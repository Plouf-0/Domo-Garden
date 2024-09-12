# Domo-Garden
#### A projet to add domotique in my garden


## 1. Project overview

#### Objective
Design and develop a Zigbee-based sensor network. The network will collect data from various environmental sensors (Thermal, Humidity, PH, ...), communicate wirelessly via Zigbee, and transmit data to a central hub that sends the information to a Home Assistant server via Wi-Fi. The system will also control an electrovalve based on predefined conditions.

#### Key Components:

- ESP32 + Zigbee module for Hub with Wi-Fi connectivity
- EFR32MG22-based sensor nodes
- Temperature, humidity sensors, and other IoT peripherals
- Electrovalve for irrigation control

## 2. Technical Specifications

#### Functional Requirements

    Data Collection: Periodic collection of temperature, humidity, and other sensor data.

    Communication: Use Zigbee for sensor node communication and Wi-Fi for sending data to the server.

    Control: Triggering of an electrovalve based on time or sensor data.

    Hub Features: The hub will aggregate data from up to 30 Zigbee devices and relay it via Wi-Fi to a server.

    Data Transfer Rate: Sensor data will be transmitted periodically, adjustable from 1 minute to 1 hour.

#### Hardware Specifications

    Microcontroller: 
        ESP32
        EFR32MG22E224F512IM40

    Power Supply: Battery-powered nodes, possible use of solar panels. Minimum 1-month battery life without recharging.

    Radio Frequency: Zigbee protocol.
    
    Communication Range: Up to 100 meters from hub, with a mesh network to cover distances up to 20 meters between each module.

    Sensors:
        Temperature sensors.
        Humidity sensors.
        Soil moisture sensors.
        Light sensors.
        PH sensors.
        More to come.

#### Software Specifications

    Programming Languages: C/C++ (for embedded systems), Python (for server-side automation).

    Development Environment: Simplicity Studio (for EFR32MG22).
    
    Protocols:
        Zigbee (3.0)
        Wi-Fi for hub (ESP32 or similar)
        MQTT (for data transmission to Home Assistant server).

    Operating System: FreeRTOS (for efficient power management).

#### Performance Metrics

    Battery Life: Minimum 30 days.

    Latency: Data transmission delay < 2 seconds between sensor reading and hub reception.

    Network Coverage: 100-meter total coverage using mesh networking.

## 3. Project Plan

#### Phases of Development

    Phase 1: Requirements Gathering & Research
        Gather requirements for sensors, control mechanisms, and networking.
        Research hardware options, compatibility with Zigbee and Home Assistant.

    Phase 2: Software Development
        Develop firmware for the EFR32MG22E224F512IM40 to read sensors, communicate via Zigbee, and send commands to the electrovalve with the EFR32xG22E Explorer Kit.
        Develop software for the Zigbee hub to manage data collection and Wi-Fi transmission to Home Assistant with the ESP32 and the Zigbee CC2530 Development Board.

    Phase 2^2: Hardware Design
        Design the PCB for sensor nodes (powered by EFR32MG22E224F512IM40).
        Create a schematic for power management (battery, solar charging).
        Select components for the electrovalve control system.
        Design and print the casing.

    Phase 3: Integration with Home Assistant
        Set up the Home Assistant server with Zigbee2MQTT or ZHA.
        Implement data visualization for sensor data.
        Test commands sent from Home Assistant to control the electrovalve.

    Phase 4: Prototyping
        Assemble and test initial sensor nodes and hub.
        Perform range and battery life tests.
        Ensure proper communication between the Zigbee nodes and the hub.

    Phase 6: Field Testing
        Deploy the system in a real environment (garden, yard).
        Monitor sensor performance, network stability, and control system reliability.

    Phase 6: Finalization & Documentation
        Finalize the design based on testing results.
        Prepare full documentation, including schematics, software, and user guide.

## 4. Risk Assessment

    Power Supply Issues: If solar panels are used, energy harvesting efficiency must be tested under various weather conditions.
    Connectivity Range: Trees and obstacles could interfere with Zigbee signals. Extensive field testing will be necessary to determine optimal node placement.
    Data Security: Implement encryption for data transmitted via Zigbee to prevent unauthorized access.
    Component Availability: Verify the supply chain for key components (e.g., EFR32MG22) to avoid potential delays due to shortages.

## 5. Additional Considerations

    OTA (Over-The-Air) Firmware Updates: Consider adding functionality for future remote firmware updates.
    Scalability: Keep flexibility in mind for expanding the network or adding more nodes later.