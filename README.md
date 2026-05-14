![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)

# OPEN Alliance TC6 Protocol Driver for LAN8650/1

This repository contains the Microchip OPEN Alliance TC6 Protocol Driver for LAN8650/1 source code and example applications.

The driver is fully OPEN Alliance TC6 V1.1 compliant.
Quickly incorporate connectivity to your designs with 10BASE-T1S
ICs, modules, software and development kits that make connecting effortless
for your customers. Our comprehensive 10BASE-T1S portfolio has the technology
to meet your range, data rate, interoperability, frequency and topology needs.
Please contact the Microchip support in case of issues and questions.

- [10BASE-T1S Support](https://www.microchip.com/support)
- [OPEN Alliance TC6 - 10BASE-T1x MAC-PHY Serial Interface specification](https://www.opensig.org/Automotive-Ethernet-Specifications)
- [10Base-T1x MAC-PHY Serial Interface Protocol Analyzer for Saleae Logic](https://github.com/MicrochipTech/oa-tc6-saleae-extension)

# Contents Summary

| Folder    | Description                                   |
| ---       | ---                                           |
| examples  | Example applications for 10BASE-T1S devices   |
| libtc6    | Source code of the OPEN Alliance TC6 Protocol Driver for LAN8650/1  |

## Code Examples

The following applications are provided to demonstrate the typical or interesting usage models of the MAC-PHY driver.

| Name                                                                      | Status                                                                                            |
| ---                                                                       | ---                                                                                               |
|[lwIP TCP/IP example running on dsPIC33AK Curiosity Development Board](examples/lwIP-dsPIC33AK_Curiosity/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[lwIP TCP/IP example running on dsPIC33AK Curiosity Nano Development Board](examples/lwIP-dsPIC33AK_Curiosity_Nano/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[lwIP TCP/IP example running on dsPIC33CK Curiosity Development Board](examples/lwIP-dsPIC33CK_Curiosity/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[lwIP TCP/IP example running on SAM D21 Curiosity Nano Evaluation Kit](examples/lwIP-SAM-D21-Curiosity-Nano/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[lwIP TCP/IP example running on SAM E54 Curiosity Ultra Development Board](examples/lwIP-SAM-E54-Curiosity/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[lwIP TCP/IP example running on SAM E54 Xplained Pro evaluation kit](examples/lwIP-SAM-E54-xplained-pro/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[lwIP TCP/IP example running on SAM V71 Xplained Ultra evaluation kit](examples/lwIP-SAM-V71-xplained-pro/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[RAW Ethernet example running on PIC18F57Q43 Curiosity Nano Evaluation Kit](examples/noIP-PIC18-Curiosity-Nano/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[RAW Ethernet example running on SAM E54 Curiosity Ultra Development Board](examples/noIP-SAM-E54-Curiosity/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |
|[RAW Ethernet example running on SAM E70 Xplained Ultra Evaluation Kit](examples/noIP-SAM-E70-Xplained/readme.md)  | ![app-production](https://img.shields.io/badge/application-production-brightgreen?style=plastic)  |


Those applications have no deep integration of the TC6 protocol driver into MPLAB® Harmony 3. If this is desired, please refer to the official LAN865x MPLAB Harmony v3 driver and example applications in the corresponding repository:
- [MPLAB® Harmony 3 - 10BASE-T1S-Examples](https://github.com/Microchip-MPLAB-Harmony/net_10base_t1s)

Note: Please refer to AN4964 provided on the Microchip LAN865x product websites:
- [LAN8650](https://www.microchip.com/en-us/product/lan8650)
- [LAN8651](https://www.microchip.com/en-us/product/lan8651)

____


[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)
