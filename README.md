# RCI-Development
A simple repository to organize all the files related to my RCI MQTT Input and Output Device.

/*
OFFICIAL RCI DEVICE PROGRAM
This is the Arduino Program for my Project called "RCI Device." RCI stands for Remote Controlled Input.
The main functionality of this device revolves around receiving input data from a variety of sensors
and publishing that information to an MQTT Broker. A second RCI Device will subscribe to those input
topics and adjust its output ports accordingly. This process will continue to work back and forth between
the two RCI Devices for as long as they have power. These devices are designed to be separated by long distances
and connected to the Internet through Ethernet ports. An example of a use case is having one RCI Device in a basement to measure
temperature and another RCI Device upstairs connected to the house thermostat. The RCI Device in the basement publishes
temperature data to the MQTT Broker, and the RCI Device upstairs subscribes to the temperature data topic. When the temperature
in the basement gets too low, the RCI Device upstairs will output to the thermostat to increase the temperature in the house.
The RCI Device has a maximum capacity of 8 ports for each type of input and output (Digital and Analog) for a total of 32 possible
channels. The Arduino Program runs on an M5Stack Core2 module with an ESP32 microchip.
*/
