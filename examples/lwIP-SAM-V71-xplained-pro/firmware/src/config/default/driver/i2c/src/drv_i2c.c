/*******************************************************************************
  I2C Driver Implementation.

  Company:
    Microchip Technology Inc.

  File Name:
    drv_i2c.c

  Summary:
    Source code for the I2C driver dynamic implementation.

  Description:
    This file contains the source code for the dynamic implementation of the
    I2C driver.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "configuration.h"
#include "driver/i2c/drv_i2c.h"
#include "system/debug/sys_debug.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

/* This is the driver instance object array. */
static DRV_I2C_OBJ gDrvI2CObj[DRV_I2C_INSTANCES_NUMBER] ;

// *****************************************************************************
// *****************************************************************************
// Section: File scope functions
// *****************************************************************************
// *****************************************************************************

static inline uint32_t lDRV_I2C_MAKE_HANDLE(uint16_t token, uint8_t drvIndex, uint8_t index)
{
    return (((uint32_t)token << 16) | ((uint32_t)drvIndex << 8) | index);
}

static inline uint16_t lDRV_I2C_UPDATE_TOKEN(uint16_t token)
{
    token++;
    if (token >= DRV_I2C_TOKEN_MAX)
    {
        token = 1;
    }

    return token;
}

static DRV_I2C_CLIENT_OBJ* lDRV_I2C_DriverHandleValidate(DRV_HANDLE handle)
{
    /* This function returns the pointer to the client object that is
       associated with this handle if the handle is valid. Returns NULL
       otherwise. */

    uint32_t drvInstance = 0;
    DRV_I2C_CLIENT_OBJ* clientObj = NULL;

    if((handle != DRV_HANDLE_INVALID) && (handle != 0U))
    {
        /* Extract the drvInstance value from the handle */
        drvInstance = ((handle & DRV_I2C_INSTANCE_MASK) >> 8);

        if (drvInstance >= DRV_I2C_INSTANCES_NUMBER)
        {
            return (NULL);
        }

        if ((handle & DRV_I2C_INDEX_MASK) >= gDrvI2CObj[drvInstance].nClientsMax)
        {
            return (NULL);
        }

        /* Extract the client index and obtain the client object */
        clientObj = &((DRV_I2C_CLIENT_OBJ *)gDrvI2CObj[drvInstance].clientObjPool)[handle & DRV_I2C_INDEX_MASK];

        if ((clientObj->clientHandle != handle) || (clientObj->inUse == false))
        {
            return (NULL);
        }
    }

    return(clientObj);
}


static bool lDRV_I2C_ResourceLock(DRV_I2C_OBJ * dObj)
{
    bool interruptStatus;
    const DRV_I2C_INTERRUPT_SOURCES* intInfo = dObj->interruptSources;
    const DRV_I2C_MULTI_INT_SRC* multiVector = &dObj->interruptSources->intSources.multi;

    /* We will allow buffers to be added in the interrupt
       context of this I2C driver. But we must make
       sure that if we are in interrupt, then we should
       not modify mutexes. */
    if(dObj->interruptNestingCount == 0U)
    {
        /* Grab a mutex. This is okay because we are not in an interrupt context */
        if(OSAL_MUTEX_Lock(&(dObj->mutexTransferObjects), OSAL_WAIT_FOREVER) == OSAL_RESULT_FAIL)
        {
            return false;
        }
    }

    if (intInfo->isSingleIntSrc == true)
    {
        /* Disable I2C interrupt */
         dObj->i2cInterruptStatus = SYS_INT_SourceDisable((INT_SOURCE)intInfo->intSources.i2cInterrupt);
    }
    else
    {
         interruptStatus = SYS_INT_Disable();

        /* Disable I2C interrupt sources */
         if(multiVector->i2cInt0 != -1)
         {
            dObj->i2cInt0Status = SYS_INT_SourceDisable((INT_SOURCE)multiVector->i2cInt0);
         }
         if(multiVector->i2cInt1 != -1)
         {
            dObj->i2cInt1Status = SYS_INT_SourceDisable((INT_SOURCE)multiVector->i2cInt1);
         }
         if(multiVector->i2cInt2 != -1)
         {
            dObj->i2cInt2Status = SYS_INT_SourceDisable((INT_SOURCE)multiVector->i2cInt2);
         }
         if(multiVector->i2cInt3 != -1)
         {
            dObj->i2cInt3Status = SYS_INT_SourceDisable((INT_SOURCE)multiVector->i2cInt3);
         }

         SYS_INT_Restore(interruptStatus);

    }

    return true;
}

static void lDRV_I2C_ResourceUnlock(DRV_I2C_OBJ * dObj)
{
    bool interruptStatus;
    const DRV_I2C_INTERRUPT_SOURCES* intInfo = dObj->interruptSources;
    const DRV_I2C_MULTI_INT_SRC* multiVector = &dObj->interruptSources->intSources.multi;

    /* Restore the interrupts back */
    if (intInfo->isSingleIntSrc == true)
    {
        /* Enable I2C interrupt */
         SYS_INT_SourceRestore((INT_SOURCE)intInfo->intSources.i2cInterrupt, dObj->i2cInterruptStatus);
    }
    else
    {
        interruptStatus = SYS_INT_Disable();

        /* Enable I2C interrupt sources */
        if(multiVector->i2cInt0 != -1)
        {
            SYS_INT_SourceRestore((INT_SOURCE)multiVector->i2cInt0,dObj->i2cInt0Status );
        }
        if(multiVector->i2cInt1 != -1)
        {
            SYS_INT_SourceRestore((INT_SOURCE)multiVector->i2cInt1,dObj->i2cInt1Status );
        }
        if(multiVector->i2cInt2 != -1)
        {
            SYS_INT_SourceRestore((INT_SOURCE)multiVector->i2cInt2,dObj->i2cInt2Status );
        }
        if(multiVector->i2cInt3 != -1)
        {
            SYS_INT_SourceRestore((INT_SOURCE)multiVector->i2cInt3,dObj->i2cInt3Status );
        }

        SYS_INT_Restore(interruptStatus);
    }

    if(dObj->interruptNestingCount == 0U)
    {
        /* Release mutex */
        (void) OSAL_MUTEX_Unlock(&(dObj->mutexTransferObjects));
    }
}

static DRV_I2C_TRANSFER_OBJ* lDRV_I2C_FreeTransferObjGet(DRV_I2C_CLIENT_OBJ* clientObj)
{
    uint32_t index;
    DRV_I2C_OBJ* dObj = (DRV_I2C_OBJ* )&gDrvI2CObj[clientObj->drvIndex];
    DRV_I2C_TRANSFER_OBJ* pTransferObj = dObj->transferObjPool;

    for (index = 0; index < dObj->transferObjPoolSize; index++)
    {
        if (pTransferObj[index].inUse == false)
        {
            pTransferObj[index].inUse = true;
            pTransferObj[index].next = NULL;

            /* Generate a unique buffer handle consisting of an incrementing
             * token counter, driver index and the buffer index.
             */
            pTransferObj[index].transferHandle = (DRV_I2C_TRANSFER_HANDLE)lDRV_I2C_MAKE_HANDLE(
                dObj->i2cTokenCount, (uint8_t)clientObj->drvIndex, (uint8_t)index);

            /* Update the token for next time */
            dObj->i2cTokenCount = lDRV_I2C_UPDATE_TOKEN(dObj->i2cTokenCount);

            return &pTransferObj[index];
        }
    }
    return NULL;
}

static bool lDRV_I2C_TransferObjAddToList(
    DRV_I2C_OBJ* dObj,
    DRV_I2C_TRANSFER_OBJ* transferObj
)
{
    DRV_I2C_TRANSFER_OBJ** pTransferObjList;
    bool isFirstTransferInList = false;

    pTransferObjList = (DRV_I2C_TRANSFER_OBJ**)&(dObj->transferObjList);

    // Is the buffer object list empty?
    if (*pTransferObjList == NULL)
    {
        *pTransferObjList = transferObj;
        isFirstTransferInList = true;
    }
    else
    {
        // List is not empty. Iterate to the end of the buffer object list.
        while (*pTransferObjList != NULL)
        {
            if ((*pTransferObjList)->next == NULL)
            {
                // End of the list reached, add the buffer here.
                (*pTransferObjList)->next = transferObj;
                break;
            }
            else
            {
                pTransferObjList = (DRV_I2C_TRANSFER_OBJ**)&((*pTransferObjList)->next);
            }
        }
    }

    return isFirstTransferInList;
}

static DRV_I2C_TRANSFER_OBJ* lDRV_I2C_TransferObjListGet( DRV_I2C_OBJ* dObj )
{
    DRV_I2C_TRANSFER_OBJ* pTransferObj = NULL;

    // Return the element at the head of the linked list
    pTransferObj = (DRV_I2C_TRANSFER_OBJ*)dObj->transferObjList;

    return pTransferObj;
}

static void lDRV_I2C_RemoveTransferObjFromList( DRV_I2C_OBJ* dObj )
{
    DRV_I2C_TRANSFER_OBJ** pTransferObjList;

    pTransferObjList = (DRV_I2C_TRANSFER_OBJ**)&(dObj->transferObjList);

    // Remove the element at the head of the linked list
    if (*pTransferObjList != NULL)
    {
        /* Save the buffer object to be removed. Set the next buffer object as
         * the new head of the linked list. Reset the removed buffer object. */

        DRV_I2C_TRANSFER_OBJ* temp = *pTransferObjList;
        *pTransferObjList = (*pTransferObjList)->next;
        temp->currentState = DRV_I2C_TRANSFER_OBJ_IS_FREE;
        temp->next = NULL;
        temp->inUse = false;
    }
}

static void lDRV_I2C_RemoveClientTransfersFromList(
    DRV_I2C_OBJ* dObj,
    DRV_I2C_CLIENT_OBJ* clientObj
)
{
    DRV_I2C_TRANSFER_OBJ** pTransferObjList;
    DRV_I2C_TRANSFER_OBJ* delTransferObj = NULL;

    pTransferObjList = (DRV_I2C_TRANSFER_OBJ**)&(dObj->transferObjList);

    while (*pTransferObjList != NULL)
    {
        // Do not remove the buffer object that is already in process
        if (((*pTransferObjList)->clientHandle == clientObj->clientHandle) &&
            ((*pTransferObjList)->currentState == DRV_I2C_TRANSFER_OBJ_IS_IN_QUEUE))
        {
            // Save the node to be deleted off the list
            delTransferObj = *pTransferObjList;

            // Update the current node to point to the deleted node's next
            *pTransferObjList = (DRV_I2C_TRANSFER_OBJ*)(*pTransferObjList)->next;

            // Reset the deleted node
            delTransferObj->currentState = DRV_I2C_TRANSFER_OBJ_IS_FREE;
            delTransferObj->event = DRV_I2C_TRANSFER_EVENT_COMPLETE;
            delTransferObj->next = NULL;
            delTransferObj->inUse = false;
        }
        else
        {
            // Move to the next node
            pTransferObjList = (DRV_I2C_TRANSFER_OBJ**)&((*pTransferObjList)->next);
        }
    }
}

static void lDRV_I2C_ClientCallback(DRV_I2C_OBJ* dObj, DRV_I2C_CLIENT_OBJ* clientObj, DRV_I2C_TRANSFER_OBJ* transferObj)
{
    DRV_I2C_TRANSFER_EVENT event;
    DRV_I2C_TRANSFER_HANDLE transferHandle;

    transferObj->errors = dObj->i2cPlib->errorGet();

    if(transferObj->errors == DRV_I2C_ERROR_NONE)
    {
        transferObj->event = DRV_I2C_TRANSFER_EVENT_COMPLETE;
    }
    else
    {
        transferObj->event = DRV_I2C_TRANSFER_EVENT_ERROR;
    }

    /* Save the transfer handle and event locally before freeing the transfer object*/
    event = transferObj->event;
    transferHandle = transferObj->transferHandle;

    /* Free the completed buffer.
     * This is done before giving callback to allow application to use the freed
     * buffer and queue in a new request from within the callback */

    lDRV_I2C_RemoveTransferObjFromList(dObj);

    if(clientObj->eventHandler != NULL)
    {
        dObj->interruptNestingCount ++;

        clientObj->eventHandler(event, transferHandle, clientObj->context);

        dObj->interruptNestingCount -- ;
    }
}

static void lDRV_I2C_NextTransferInitiate(DRV_I2C_OBJ* dObj, DRV_I2C_CLIENT_OBJ* clientObj)
{
    DRV_I2C_TRANSFER_OBJ* transferObj = NULL;
    bool transferStatus = true;

    do
    {
        transferStatus = true;

        /* Get the transfer object at the head of the list */
        transferObj = lDRV_I2C_TransferObjListGet(dObj);

        /* Process the next transfer buffer */
        if((transferObj != NULL) && (transferObj->currentState == DRV_I2C_TRANSFER_OBJ_IS_IN_QUEUE))
        {
            // Get the client object that owns this buffer
            clientObj = &((DRV_I2C_CLIENT_OBJ *)gDrvI2CObj[((transferObj->clientHandle & DRV_I2C_INSTANCE_MASK) >> 8)].clientObjPool)
                        [transferObj->clientHandle & DRV_I2C_INDEX_MASK];

            /* Check if the transfer setup for this client is different than the current transfer setup */
            if (dObj->currentTransferSetup.clockSpeed != clientObj->transferSetup.clockSpeed)
            {
                /* Set the new transfer setup */
                (void) dObj->i2cPlib->transferSetup(&clientObj->transferSetup, 0);

                dObj->currentTransferSetup.clockSpeed = clientObj->transferSetup.clockSpeed;
            }

            switch(transferObj->flag)
            {
                case DRV_I2C_TRANSFER_OBJ_FLAG_RD:
                    transferObj->currentState = DRV_I2C_TRANSFER_OBJ_IS_PROCESSING;
                    transferStatus = dObj->i2cPlib->read_t(transferObj->slaveAddress, transferObj->readBuffer, transferObj->readSize);
                    break;

                case DRV_I2C_TRANSFER_OBJ_FLAG_WR:
                    transferObj->currentState = DRV_I2C_TRANSFER_OBJ_IS_PROCESSING;
                    transferStatus = dObj->i2cPlib->write_t(transferObj->slaveAddress, transferObj->writeBuffer, transferObj->writeSize);
                    break;
                    case DRV_I2C_TRANSFER_OBJ_FLAG_WR_RD:
                    transferObj->currentState = DRV_I2C_TRANSFER_OBJ_IS_PROCESSING;
                    transferStatus = dObj->i2cPlib->writeRead(transferObj->slaveAddress, transferObj->writeBuffer, transferObj->writeSize, transferObj->readBuffer, transferObj->readSize);
                    break;
                default:
                    /* Execution should never enter the default case */
                    break;
            }
            if (transferStatus == false)
            {
                lDRV_I2C_ClientCallback(dObj, clientObj, transferObj);
            }
        }
    }while(transferStatus == false);
}

static void lDRV_I2C_PLibCallbackHandler( uintptr_t contextHandle )
{
    DRV_I2C_OBJ* dObj = (DRV_I2C_OBJ *)contextHandle;
    DRV_I2C_CLIENT_OBJ* clientObj = NULL;
    DRV_I2C_TRANSFER_OBJ* transferObj = NULL;

    if((dObj->inUse == false) || (dObj->status != SYS_STATUS_READY))
    {
        /* This instance of the driver is not initialized. Don't
         * do anything */
        return;
    }

    // Get the transfer object at the head of the list
    transferObj = lDRV_I2C_TransferObjListGet(dObj);

    // Get the client object that owns this buffer
    clientObj = &((DRV_I2C_CLIENT_OBJ *)gDrvI2CObj[((transferObj->clientHandle & DRV_I2C_INSTANCE_MASK) >> 8)].clientObjPool)
                [transferObj->clientHandle & DRV_I2C_INDEX_MASK];

    /* Check if the client that submitted the request is active? */
    if (clientObj->clientHandle == transferObj->clientHandle)
    {
        lDRV_I2C_ClientCallback(dObj, clientObj, transferObj);
    }
    else
    {
        /* The client has probably closed the driver. Free the completed buffer */
        lDRV_I2C_RemoveTransferObjFromList(dObj);
    }

    lDRV_I2C_NextTransferInitiate(dObj, clientObj);
}

// *****************************************************************************
// *****************************************************************************
// Section: I2C Driver Common Interface Implementation
// *****************************************************************************
// *****************************************************************************
SYS_MODULE_OBJ DRV_I2C_Initialize(
    const SYS_MODULE_INDEX drvIndex,
    const SYS_MODULE_INIT* const init
)
{
    DRV_I2C_OBJ* dObj     = NULL;
/* MISRA C-2012 Rule 11.3, 11.8 deviated below. Deviation record ID -  H3_MISRAC_2012_R_11_3_DR_1 & H3_MISRAC_2012_R_11_8_DR_1*/

    DRV_I2C_INIT* i2cInit = (DRV_I2C_INIT*)init;

/* MISRAC 2012 deviation block end */

    /* Validate the request */
    if(drvIndex >= DRV_I2C_INSTANCES_NUMBER)
    {
        return SYS_MODULE_OBJ_INVALID;
    }

    /* Is the driver instance already initialized? */
    if(gDrvI2CObj[drvIndex].inUse == true)
    {
        return SYS_MODULE_OBJ_INVALID;
    }

    /* Allocate the driver object */
    dObj = &gDrvI2CObj[drvIndex];

    /* Create mutex */
    if(OSAL_MUTEX_Create(&(dObj->mutexClientObjects)) != OSAL_RESULT_SUCCESS)
    {
        return SYS_MODULE_OBJ_INVALID;
    }
    if(OSAL_MUTEX_Create(&(dObj->mutexTransferObjects)) != OSAL_RESULT_SUCCESS)
    {
        return SYS_MODULE_OBJ_INVALID;
    }

    dObj->inUse = true;

    /* Update the driver parameters */
    dObj->i2cPlib                           = i2cInit->i2cPlib;
    dObj->interruptSources                  = i2cInit->interruptSources;
    dObj->clientObjPool                     = i2cInit->clientObjPool;
    dObj->nClientsMax                       = i2cInit->numClients;
    dObj->transferObjPool                   = (DRV_I2C_TRANSFER_OBJ*)i2cInit->transferObjPool;
    dObj->transferObjPoolSize               = i2cInit->transferObjPoolSize;
    dObj->transferObjList                   = (DRV_I2C_TRANSFER_OBJ*)NULL;
    dObj->nClients                          = 0;
    dObj->isExclusive                       = false;
    dObj->interruptNestingCount             = 0;
    dObj->i2cTokenCount                     = 1;
    dObj->initI2CClockSpeed                 = i2cInit->clockSpeed;
    dObj->currentTransferSetup.clockSpeed   = i2cInit->clockSpeed;

    /* Register a callback with the underlying PLIB.
     * dObj as a context parameter will be used to distinguish the events
     * from different instances. */
    dObj->i2cPlib->callbackRegister(lDRV_I2C_PLibCallbackHandler, (uintptr_t)dObj);

    /* Update the status */
    dObj->status = SYS_STATUS_READY;

    /* Return the object structure */
    return ( (SYS_MODULE_OBJ)drvIndex );
}

SYS_STATUS DRV_I2C_Status( const SYS_MODULE_OBJ object)
{
    /* Validate the request */
    if( (object == (uint32_t)SYS_MODULE_OBJ_INVALID) || (object >= DRV_I2C_INSTANCES_NUMBER) )
    {
        return SYS_STATUS_UNINITIALIZED;
    }

    return (gDrvI2CObj[object].status);
}

DRV_HANDLE DRV_I2C_Open(
    const SYS_MODULE_INDEX drvIndex,
    const DRV_IO_INTENT ioIntent
)
{
    DRV_I2C_CLIENT_OBJ* clientObj;
    DRV_I2C_OBJ* dObj = NULL;
    uint32_t iClient,tempioIntent = 0;

    /* Validate the request */
    if (drvIndex >= DRV_I2C_INSTANCES_NUMBER)
    {
        return DRV_HANDLE_INVALID;
    }

    dObj = &gDrvI2CObj[drvIndex];

    /* Guard against multiple threads trying to open the driver */
    if(OSAL_MUTEX_Lock(&(dObj->mutexClientObjects), OSAL_WAIT_FOREVER) == OSAL_RESULT_FAIL)
    {
        return DRV_HANDLE_INVALID;
    }

    if((dObj->status != SYS_STATUS_READY) || (dObj->inUse == false))
    {
        (void) OSAL_MUTEX_Unlock(&(dObj->mutexClientObjects));
        return DRV_HANDLE_INVALID;
    }

    if(dObj->isExclusive == true)
    {
        /* Driver is already opened with exclusive access. Hence, cannot be opened again*/
        (void) OSAL_MUTEX_Unlock(&(dObj->mutexClientObjects));
        return DRV_HANDLE_INVALID;
    }

    if((dObj->nClients > 0U) && (((uint32_t)ioIntent & (uint32_t)DRV_IO_INTENT_EXCLUSIVE) != 0U))
    {
        /* Exclusive access is requested while the driver is already opened by other client */
        (void) OSAL_MUTEX_Unlock(&(dObj->mutexClientObjects));
        return DRV_HANDLE_INVALID;
    }

    for(iClient = 0; iClient != dObj->nClientsMax; iClient++)
    {
        clientObj = &((DRV_I2C_CLIENT_OBJ *)dObj->clientObjPool)[iClient];

        if(clientObj->inUse == false)
        {
            /* This means we have a free client object to use */
            clientObj->inUse = true;

            if(((uint32_t)ioIntent & (uint32_t)DRV_IO_INTENT_EXCLUSIVE) != 0U)
            {
                /* Set the driver exclusive flag */
                dObj->isExclusive = true;
            }

            dObj->nClients ++;

            /* Generate the client handle */
            clientObj->clientHandle = (DRV_HANDLE)lDRV_I2C_MAKE_HANDLE(dObj->i2cTokenCount, (uint8_t)drvIndex, (uint8_t)iClient);

            /* Increment the instance specific token counter */
            dObj->i2cTokenCount = lDRV_I2C_UPDATE_TOKEN(dObj->i2cTokenCount);

            /* We have found a client object, now release the mutex */
            (void) OSAL_MUTEX_Unlock(&(dObj->mutexClientObjects));

            clientObj->drvIndex                 = drvIndex;
            tempioIntent = (uint32_t)ioIntent | (uint32_t)DRV_IO_INTENT_NONBLOCKING;
            clientObj->ioIntent                 = (DRV_IO_INTENT)(tempioIntent);
            clientObj->transferSetup.clockSpeed = dObj->initI2CClockSpeed;
            clientObj->eventHandler             = NULL;
            clientObj->context                  = 0U;

            return ((DRV_HANDLE) clientObj->clientHandle );
        }
    }

    /* Could not find a client object. Release the mutex and return with an invalid handle. */
    (void) OSAL_MUTEX_Unlock(&(dObj->mutexClientObjects));

    return DRV_HANDLE_INVALID;
}

void DRV_I2C_Close( const DRV_HANDLE handle )
{
    /* This function closes the client, The client object is deallocated and
     * returned to the pool. */

    DRV_I2C_OBJ* dObj;
    DRV_I2C_CLIENT_OBJ* clientObj;

    /* Validate the handle */
    clientObj = lDRV_I2C_DriverHandleValidate(handle);
    if(clientObj == NULL)
    {
        /* Driver handle is not valid */
        return;
    }

    dObj = &gDrvI2CObj[clientObj->drvIndex];

    /* Guard against multiple threads trying to open/close the driver */
    if(OSAL_MUTEX_Lock(&(dObj->mutexClientObjects), OSAL_WAIT_FOREVER) == OSAL_RESULT_FAIL)
    {
        return;
    }

    /* We will be removing the transfers queued by the client. Guard the linked list
     * against interrupts and/or other threads trying to modify the linked list.
     */
    if (lDRV_I2C_ResourceLock(dObj) == false)
    {
        return;
    }

    /* Remove all buffers that this client owns from the driver queue */

    lDRV_I2C_RemoveClientTransfersFromList(dObj, clientObj);

    lDRV_I2C_ResourceUnlock(dObj);

    /* Reduce the number of clients */
    dObj->nClients --;

    /* Reset the exclusive flag */
    dObj->isExclusive = false;

    /* Invalidate the client handle */
    clientObj->clientHandle = DRV_HANDLE_INVALID;

    /* Free the client object */
    clientObj->inUse = false;

    (void) OSAL_MUTEX_Unlock(&(dObj->mutexClientObjects));

    return;
}


void DRV_I2C_TransferEventHandlerSet(
    const DRV_HANDLE handle,
    const DRV_I2C_TRANSFER_EVENT_HANDLER eventHandler,
    const uintptr_t context
)
{
    DRV_I2C_CLIENT_OBJ* clientObj = NULL;
    DRV_I2C_OBJ* dObj = NULL;

    /* Validate the handle */
    clientObj = lDRV_I2C_DriverHandleValidate(handle);

    if (clientObj == NULL)
    {
        return;
    }

    dObj = &gDrvI2CObj[clientObj->drvIndex];

    if(lDRV_I2C_ResourceLock(dObj) == false)
    {
        return;
    }

    clientObj->eventHandler = eventHandler;
    clientObj->context = context;

    lDRV_I2C_ResourceUnlock(dObj);
}

bool DRV_I2C_TransferSetup( const DRV_HANDLE handle, DRV_I2C_TRANSFER_SETUP* setup )
{
    DRV_I2C_CLIENT_OBJ* clientObj = NULL;

    if(setup == NULL)
    {
        return false;
    }

    /* Validate the driver handle */
    clientObj = lDRV_I2C_DriverHandleValidate(handle);

    if(clientObj == NULL)
    {
        return false;
    }

    /* Save the client specific transfer setup */
    clientObj->transferSetup = *setup;

    return true;
}

DRV_I2C_ERROR DRV_I2C_ErrorGet( const DRV_I2C_TRANSFER_HANDLE transferHandle )
{
    DRV_I2C_OBJ* dObj = NULL;
    uint32_t drvInstance = 0;
    uint8_t transferIndex;
    DRV_I2C_ERROR errors = DRV_I2C_ERROR_NONE;

    /* Extract driver instance value from the transfer handle */
    drvInstance = ((transferHandle & DRV_I2C_INSTANCE_MASK) >> 8);

    if(drvInstance >= DRV_I2C_INSTANCES_NUMBER)
    {
        return errors;
    }

    dObj = (DRV_I2C_OBJ*)&gDrvI2CObj[drvInstance];

    if(lDRV_I2C_ResourceLock(dObj) == false)
    {
        return errors;
    }

    /* Extract transfer buffer index value from the transfer handle */
    transferIndex = (uint8_t)(transferHandle & DRV_I2C_INDEX_MASK);

    /* Validate the transferIndex and corresponding request */
    if(transferIndex < dObj->transferObjPoolSize)
    {
        if(transferHandle == dObj->transferObjPool[transferIndex].transferHandle)
        {
            errors = dObj->transferObjPool[transferIndex].errors;
            dObj->transferObjPool[transferIndex].errors = DRV_I2C_ERROR_NONE;
        }
    }

    lDRV_I2C_ResourceUnlock(dObj);

    return errors;
}

static void lDRV_I2C_WriteReadTransferAdd (
    const DRV_HANDLE handle,
    const uint16_t address,
    void* const writeBuffer,
    const size_t writeSize,
    void* const readBuffer,
    const size_t readSize,
    DRV_I2C_TRANSFER_HANDLE* const transferHandle,
    DRV_I2C_TRANSFER_OBJ_FLAGS transferFlags
)
{
    DRV_I2C_CLIENT_OBJ* clientObj = NULL;
    DRV_I2C_OBJ* dObj = NULL;
    DRV_I2C_TRANSFER_OBJ* transferObj = NULL;
    bool transferError = false;

    /* Validate the transfer handle */
    if (transferHandle == NULL)
    {
        return;
    }

    *transferHandle = DRV_I2C_TRANSFER_HANDLE_INVALID;

    /* Validate the driver handle */
    clientObj = lDRV_I2C_DriverHandleValidate(handle);
    if(clientObj == NULL)
    {
        return;
    }

    if (transferFlags == DRV_I2C_TRANSFER_OBJ_FLAG_RD)
    {
        if((readSize == 0U) || (readBuffer == NULL))
        {
            return;
        }
    }
    else if ((transferFlags == DRV_I2C_TRANSFER_OBJ_FLAG_WR) || (transferFlags == DRV_I2C_TRANSFER_OBJ_FLAG_WR_FRCD))
    {
        if((writeSize == 0U) || (writeBuffer == NULL))
        {
            return;
        }
    }
    else
    {
        if((writeSize == 0U) || (writeBuffer == NULL) || (readSize == 0U) || (readBuffer == NULL))
        {
            return;
        }
    }

    /* Get the driver object from the client handle */
    dObj = &gDrvI2CObj[clientObj->drvIndex];


    if(lDRV_I2C_ResourceLock(dObj) == false)
    {
        return;
    }

    /* Get a free transfer object */
    transferObj = lDRV_I2C_FreeTransferObjGet(clientObj);

    if(transferObj == NULL)
    {
        lDRV_I2C_ResourceUnlock(dObj);
        return;
    }

    /* Configure the transfer object */
    transferObj->slaveAddress = address;
    transferObj->readBuffer   = ( uint8_t *)readBuffer;
    transferObj->readSize     = readSize;
    transferObj->writeBuffer  = ( uint8_t *)writeBuffer;
    transferObj->writeSize    = writeSize;
    transferObj->clientHandle = handle;
    transferObj->errors       = DRV_I2C_ERROR_NONE;
    transferObj->currentState = DRV_I2C_TRANSFER_OBJ_IS_IN_QUEUE;
    transferObj->event        = DRV_I2C_TRANSFER_EVENT_PENDING;
    transferObj->flag         = transferFlags;

    *transferHandle = transferObj->transferHandle;

    /* Add the buffer object to the transfer buffer list */
    if (lDRV_I2C_TransferObjAddToList(dObj, transferObj) == true)
    {
        /* This is the first request in the queue, hence initiate a PLIB transfer */

        /* Check if the transfer setup for this client is different than the current transfer setup */
        if (dObj->currentTransferSetup.clockSpeed != clientObj->transferSetup.clockSpeed)
        {
            /* Set the new transfer setup */
            (void) dObj->i2cPlib->transferSetup(&clientObj->transferSetup, 0);

            dObj->currentTransferSetup.clockSpeed = clientObj->transferSetup.clockSpeed;
        }

        transferObj->currentState = DRV_I2C_TRANSFER_OBJ_IS_PROCESSING;

        if (transferFlags == DRV_I2C_TRANSFER_OBJ_FLAG_RD)
        {
            if (dObj->i2cPlib->read_t(
                transferObj->slaveAddress,
                transferObj->readBuffer,
                transferObj->readSize
            ) == false)
            {
                transferError = true;
            }
        }
        else if (transferFlags == DRV_I2C_TRANSFER_OBJ_FLAG_WR)
        {
            if (dObj->i2cPlib->write_t(
                transferObj->slaveAddress,
                transferObj->writeBuffer,
                transferObj->writeSize
            ) == false)
            {
                transferError = true;
            }
        }
        else
        {
            if (dObj->i2cPlib->writeRead(
                transferObj->slaveAddress,
                transferObj->writeBuffer,
                transferObj->writeSize,
                transferObj->readBuffer,
                transferObj->readSize
            ) == false)
            {
                transferError = true;
            }
        }

        if (transferError == true)
        {
            *transferHandle = DRV_I2C_TRANSFER_HANDLE_INVALID;
            transferObj->errors = dObj->i2cPlib->errorGet();

            if(transferObj->errors == DRV_I2C_ERROR_NONE)
            {
                transferObj->event = DRV_I2C_TRANSFER_EVENT_COMPLETE;
            }
            else
            {
                transferObj->event = DRV_I2C_TRANSFER_EVENT_ERROR;
            }

            lDRV_I2C_RemoveTransferObjFromList(dObj);
        }
    }

    lDRV_I2C_ResourceUnlock(dObj);
}

void DRV_I2C_ReadTransferAdd(
    const DRV_HANDLE handle,
    const uint16_t address,
    void* const buffer,
    const size_t size,
    DRV_I2C_TRANSFER_HANDLE* const transferHandle
)
{
    lDRV_I2C_WriteReadTransferAdd(handle, address, NULL, 0,
        buffer, size, transferHandle, DRV_I2C_TRANSFER_OBJ_FLAG_RD);
}

void DRV_I2C_WriteTransferAdd(
    const DRV_HANDLE handle,
    const uint16_t address,
    void* const buffer,
    const size_t size,
    DRV_I2C_TRANSFER_HANDLE* const transferHandle
)
{
    lDRV_I2C_WriteReadTransferAdd(handle, address, buffer, size,
        NULL, 0, transferHandle, DRV_I2C_TRANSFER_OBJ_FLAG_WR);
}

void DRV_I2C_WriteReadTransferAdd (
    const DRV_HANDLE handle,
    const uint16_t address,
    void* const writeBuffer,
    const size_t writeSize,
    void* const readBuffer,
    const size_t readSize,
    DRV_I2C_TRANSFER_HANDLE* const transferHandle
)
{
    lDRV_I2C_WriteReadTransferAdd(handle, address, writeBuffer, writeSize,
        readBuffer, readSize, transferHandle, DRV_I2C_TRANSFER_OBJ_FLAG_WR_RD);
}

void DRV_I2C_QueuePurge(const DRV_HANDLE handle)
{
    DRV_I2C_TRANSFER_OBJ* transferObj = NULL;
    DRV_I2C_CLIENT_OBJ* clientObj = NULL;
    DRV_I2C_OBJ* dObj = NULL;
    bool topOfQueueUpdated = false;

    clientObj = lDRV_I2C_DriverHandleValidate(handle);

    if(clientObj == NULL)
    {
        return;
    }

    /* Get the driver object from the client handle */
    dObj = &gDrvI2CObj[clientObj->drvIndex];

    if(lDRV_I2C_ResourceLock(dObj) == false)
    {
        return;
    }

    // Get the transfer object at the head of the list
    transferObj = lDRV_I2C_TransferObjListGet(dObj);

    /* Make sure the ongoing request belongs to the client that called this API and is currently with the PLIB */
    if ( (dObj->i2cPlib->transferAbort != NULL) && (transferObj != NULL) && (transferObj->clientHandle == clientObj->clientHandle) && (transferObj->currentState == DRV_I2C_TRANSFER_OBJ_IS_PROCESSING) )
    {
        /* Abort the ongoing transfer with the PLIB */
        dObj->i2cPlib->transferAbort();

        /* Remove the transfer object at the top of the list */
        lDRV_I2C_RemoveTransferObjFromList(dObj);

        topOfQueueUpdated = true;
    }

    /* Remove all the transfers belonging to this client from the linked list */
    lDRV_I2C_RemoveClientTransfersFromList(dObj, clientObj);

    if (topOfQueueUpdated == true)
    {
        /* Since top of the queue is updated, force start the next transfer in the queue if any */
        lDRV_I2C_NextTransferInitiate(dObj, clientObj);
    }

    lDRV_I2C_ResourceUnlock(dObj);
}

DRV_I2C_TRANSFER_EVENT DRV_I2C_TransferStatusGet(
    const DRV_I2C_TRANSFER_HANDLE transferHandle
)
{
    DRV_I2C_OBJ* dObj = NULL;
    uint32_t drvInstance = 0;
    uint8_t transferIndex;
    DRV_I2C_TRANSFER_EVENT  event = DRV_I2C_TRANSFER_EVENT_HANDLE_INVALID;

    /* Extract driver instance value from the transfer handle */
    drvInstance = ((transferHandle & DRV_I2C_INSTANCE_MASK) >> 8);

    if(drvInstance >= DRV_I2C_INSTANCES_NUMBER)
    {
        return event;
    }

    dObj = (DRV_I2C_OBJ*)&gDrvI2CObj[drvInstance];

    if(lDRV_I2C_ResourceLock(dObj) == false)
    {
        return event;
    }

    /* Extract transfer buffer index value from the transfer handle */
    transferIndex = (uint8_t)(transferHandle & DRV_I2C_INDEX_MASK);

    /* Validate the transferIndex and corresponding request */
    if(transferIndex < dObj->transferObjPoolSize)
    {
        if(transferHandle == dObj->transferObjPool[transferIndex].transferHandle)
        {
            event = dObj->transferObjPool[transferIndex].event;
        }
        else
        {
            event = DRV_I2C_TRANSFER_EVENT_HANDLE_EXPIRED;
        }
    }

    lDRV_I2C_ResourceUnlock(dObj);

    return event;
}
