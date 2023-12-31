# nRF24L01+ GUINO Dashboard

A brief description of your project.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#Requirements)
- [Project Files](#Project_Files)
- [Installation](#installation)
- [Credits](#Credits)

## Introduction
![GUINO Dashboard Screenshot](GUINO_Dashboard.png)
![GUINO Dashboard Screenshot2](GUINO-Dashboard2.png)
The nRF24 GUINO project addresses this critical need by providing a robust and flexible solution for monitoring and controlling rescue robots. This project is driven by the following key objectives:

1. **Wireless Communication**: Leveraging the nRF24L01 radio communication modules, known for their reliability and low-power consumption, to establish seamless wireless communication channels between robots and operators or control centers.

2. **Graphical User Interface**: Implementing the GUINO library to create an intuitive and user-friendly graphical user interface (GUI) for monitoring robot data and controlling robot functions. GUINO offers real-time data visualization, enabling operators to make informed decisions quickly.

3. **Future Compatibility**: Addressing hardware and software compatibility concerns by planning for future integration with technologies such as the Raspberry Pi and ROS (Robot Operating System), enhancing the project's adaptability and longevity.

This README.md file serves as your gateway to understanding and working with the nRF24 GUINO project. I'll provide installation instructions, guidance on project usage, details on how to contribute to the project, and the project's licensing information. We encourage you to explore and contribute to this project, as it has the potential to shape the future of rescue robot monitoring and control.


# Features

This project offers two main functionalities:

1. **nRF24 Radio Communication with Packet Acknowledgement**: The project leverages the nRF24L01 2.4GHz RF transceiver module for wireless communication. It includes a robust communication protocol with packet acknowledgement, ensuring reliable data transmission between devices. This functionality is crucial for establishing communication between your Arduino-based devices, such as robots, controllers, or sensors.

2. **Display Information in GUINO Dashboard**: The project provides a graphical user interface (GUI) dashboard called GUINO for monitoring and controlling your Arduino-based systems. GUINO allows you to display real-time information, including sensor data, system status, and interactive controls. It offers a user-friendly interface for managing and interacting with your connected

# Requirements

To utilise this project, you'll need the following components:

1. **Arduino Microcontroller**: You'll require an Arduino microcontroller board, such as Arduino Uno R3 or Arduino Nano, to run the provided Arduino sketch files. These microcontrollers serve as the central processing units (CPUs) for your connected devices.

2. **nRF24L01+ Radio Module**: The project relies on the nRF24L01+ 2.4GHz RF transceiver module for wireless communication. Ensure you have one or more nRF24L01+ modules, depending on your project's communication requirements.
    Wiring Schematic for the module (Some nRF24 modules will have different pinout configurations see the specific data for your pinout.)
    ![Wiring Schematic for the module](nrf24PinOut.png)
    
    source:Dejan, How to Mechatronics [https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/]



These components form the core hardware prerequisites for setting up and running the project effectively. Make sure you have the necessary Arduino microcontroller and nRF24L01+ radio modules to get started.

# Project_Files

**Controller and Dashboard Display**: RF24Comms_Master_Controller_Oneway_.ino contains the code necessary to communicate radio data recieved to GUINO.exe executable via serial communication. Guino_libarary.ino is a library for GUINO which contains all the functions and defitions. This file is necessary for RF24Comms_Master_Controller_Oneway_.ino to function.

**Bot Transceiver**: Bot_Transceiver.ino sketch contains the code for the bot which transmit a payload to the controller unit.

**GUINO PACKAGE**: This file contains the GUINO executable program which is able to communicate with the arduino running the Controller and Dashboard Display program.


# Installation

This project consists of Arduino sketch files that can be easily cloned or downloaded and opened using the Arduino IDE. You can follow these steps to get started:

1. **Clone or Download**: Begin by cloning this repository to your local machine using Git, or simply download the project as a ZIP file and extract it to your preferred directory.

   ```shell
   git clone https://github.com/strong-sira/nRF24-GUINO-Dashboard.git

## Credits
GUINO Dashboard:
- Programming and idea by: Mads Hobye
- Easytransfer library by: Bill Porter
- GUI library by: Reza Ali
