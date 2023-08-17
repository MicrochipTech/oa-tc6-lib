![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)

# OPEN Alliance TC6 Protocol Driver for LAN8650/1 Release Notes

## OPEN Alliance TC6 Protocol Driver for LAN8650/1 Release v3.1.3
### Bugfixes

 - Renamed "protected" parameter into "secure", so C++ compilers do not throw keyword error.

## OPEN Alliance TC6 Protocol Driver for LAN8650/1 Release v3.1.2
### New Features
- SAM V71 example provides interactive menu and benchmark result like the E54 noIP variant

### Bugfixes
- Updating all example projects to latest Harmony 3 components
- Lowering all release mode settings to -O1 to avoid comercial compiler license warning
- Providing TC6 version number in tc6.h
- Printing PLCA-Node-ID at firmware start
- Board instance can be chosen from Project Build dropdown list
- Bugfixes for synchronous TC6 variant used in PIC18 firmware

## OPEN Alliance TC6 Protocol Driver for LAN8650/1 Release v3.1.1
### New Features

 - Add MAC-PHY chip revision checking
 - Replaced PIC18 example by synchronous API OA-TC6 example (easier to use and maintain)

### Bugfixes

 - Initialize MAC-PHY according to AN1760 LAN8650/1 Configuration Application Note
 - Enable collision detection on CSMA/CD mode

## OPEN Alliance TC6 Protocol Driver for LAN8650/1 Release v3.1.0

### Bugfixes

 - Changed initialization phase according to Configuration Application Note (AN1760)
 - Checking Chip Revision at startup

### Dependencies (applies only to Demo applications)

* [MPLAB® X IDE v610](https://www.microchip.com/mplab/mplab-x-ide) or later
* [MPLAB® XC32 C/C++ Compiler v4.30](https://www.microchip.com/mplab/compilers)
 
## OPEN Alliance TC6 Protocol Driver for LAN8650/1 Release v3.0.1

### Bugfixes

 - Fixes issue with mass production LAN8650/1

## OPEN Alliance TC6 Protocol Driver for LAN8650/1 Release v3.0.0

This is the first release distributed on GitHub. Previous releases were distributed via the Microchip support channel.

### New Features

**Generic TC6 Protocol Driver for LAN8650/1**


- **New device support** -
  This release introduces support for

    | Device    | Description             |
    | ------    | ------                  |
    | LAN865x   | 10BASE-T1S Ethernet MAC-PHY |

- **Demo application support** -
  The following table provides a list of of new applications

| Name                                                                      | Status                                                                                            |
| ---                                                                       | ---                                                                                               |
|[lwIP TCP/IP example running on dsPIC33CK Curiosity Development Board](examples/lwIP-dsPIC33CK_Curiosity/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[lwIP TCP/IP example running on SAM D21 Curiosity Nano Evaluation Kit](examples/lwIP-SAM-D21-Curiosity-Nano/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[lwIP TCP/IP example running on SAM E54 Curiosity Ultra Development Board](examples/lwIP-SAM-E54-Curiosity/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[lwIP TCP/IP example running on SAM E54 Xplained Pro evaluation kit](examples/lwIP-SAM-E54-xplained-pro/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[lwIP TCP/IP example running on SAM V71 Xplained Ultra evaluation kit](examples/lwIP-SAM-V71-xplained-pro/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[RAW Ethernet example running on PIC18F57Q43 Curiosity Nano Evaluation Kit](examples/noIP-PIC18-Curiosity-Nano/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[RAW Ethernet example running on SAM E54 Curiosity Ultra Development Board](examples/noIP-PIC18-Curiosity-Nano/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[RAW Ethernet example running on SAM E70 Xplained Ultra Evaluation Kit](examples/noIP-SAM-E70-Xplained/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |

### Dependencies (applies only to Demo applications)

* [MPLAB® X IDE v6.05](https://www.microchip.com/mplab/mplab-x-ide) or later
* [MPLAB® XC32 C/C++ Compiler v4.21](https://www.microchip.com/mplab/compilers) or later
**(OR)** [MPLAB® XC32 Functional Safety Compiler v4.09](https://www.microchip.com/mplab/compilers) or later
