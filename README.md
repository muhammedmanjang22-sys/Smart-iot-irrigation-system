# Smart-iot-irrigation-system
An IoT-based smart irrigation system using Arduino MKR WiFi 1010 for automated Irrigation and remote monitoring

## Project Overview

The Smart IoT-Based Irrigation System is an automated agricultural solution designed to improve irrigation efficiency through real-time soil moisture monitoring and intelligent water management.

The system uses an Arduino MKR WiFi 1010 microcontroller, a capacitive soil moisture sensor, a DHT11 sensor, a relay module, and a water pump. Through IoT connectivity, users can monitor environmental conditions and irrigation status remotely.

This project demonstrates the application of embedded systems, automation, sensor integration, and Internet of Things (IoT) technology in agriculture.

## Project Objectives

The main objective of this project is to develop an IoT-based smart irrigation system capable of automatically watering plants based on soil moisture conditions.

### Specific Objectives

- Monitor soil moisture levels in real time.
- Measure temperature and humidity using the DHT11 sensor.
- Automate irrigation using a relay-controlled water pump.
- Enable remote monitoring through IoT connectivity.
- Improve water-use efficiency in agriculture.

## Hardware Components

| Component | Function |
|------------|------------|
| Arduino MKR WiFi 1010 | Main Controller |
| Capacitive Soil Moisture Sensor | Measures soil moisture |
| DHT11 Sensor | Measures temperature and humidity |
| 5V Relay Module | Controls pump operation |
| Water Pump | Supplies water to plants |
| Breadboard | Circuit assembly |
| 3.7V Battery | Power supply |
| Jumper Wires | Electrical connections |

## System Features

- Automatic irrigation control
- Real-time soil moisture monitoring
- Temperature and humidity monitoring
- Remote monitoring through Arduino IoT Cloud
- Wireless communication using WiFi
- Water conservation through intelligent irrigation

## System Architecture

The system consists of three main layers:

### 1. Sensing Layer
- Capacitive Soil Moisture Sensor
- DHT11 Temperature and Humidity Sensor

### 2. Processing Layer
- Arduino MKR WiFi 1010

### 3. Actuation Layer
- Relay Module
- Water Pump

Sensor data is collected from the environment and processed by the Arduino MKR WiFi 1010. Based on soil moisture conditions, the controller activates or deactivates the water pump through a relay module.

### System Block Diagram

(Block diagram will be added here)

## Working Principle

The Smart IoT-Based Irrigation System operates according to the following sequence:

1. The capacitive soil moisture sensor measures the moisture content of the soil.
2. The DHT11 sensor measures environmental temperature and humidity.
3. Sensor data is transmitted to the Arduino MKR WiFi 1010.
4. The controller compares the soil moisture value with a predefined threshold.
5. If the soil is dry, the relay module activates the water pump.
6. Water is supplied to the plant until the desired moisture level is achieved.
7. Sensor readings and system status are transmitted to Arduino IoT Cloud for remote monitoring.

### System Flowchart

(Flowchart will be added here after project documentation is completed.)
