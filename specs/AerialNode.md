# Domo-Garden
### The node is the modular part where sensors are attached. It gets sensors information and transmit them to the hub via Zigbee.

## 1. Components

- EFR32MG22E224F512IM32
- DHT22
- Photoresistors
- Battery 1000mAh + recharging module (MCP73833)
- CP2102N-Axx-xQFN20 (USB to UART)
- TLV75533PDBV (3-5V to 3.3V)
- Crystal ECS-384-CDX-1983-TR3 

## 2. Alim

The board is powered by USB-C.
The USB-C powers the MCP73833 that recharges the 1000mAh.
The MCP73833 and the battery can power the board by using a TLV75533PDBV to sabilize the voltage to 3.3V.



