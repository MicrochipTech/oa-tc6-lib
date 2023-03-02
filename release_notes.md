![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)

# OPEN Alliance TC6 Protocol Driver for LAN8650/1 Release Notes


## OPEN Alliance TC6 Protocol Driver for LAN8650/1 Release v3.0.0

This is the first release distributed on GitHub. Previous releases were distributed via the Microchip support channel.

## New Features

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
* [net v3.9.1](https://github.com/Microchip-MPLAB-Harmony/net/tree/v3.9.1) or later
