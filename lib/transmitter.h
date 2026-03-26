#pragma once
#include <Arduino.h>

/**
 * @brief Initializes and configures a transmitter via AT commands.
 *
 * This template function sets up a serial interface and sends AT commands
 * to configure a radio/transmitter module (commonly LoRa or similar).
 *
 * The function performs the following steps:
 * - Starts serial communication at the specified baud rate
 * - Verifies communication with the module using "AT"
 * - Sets the network ID
 * - Sets the device address
 *
 * @tparam SerialT Type of the serial interface (e.g., HardwareSerial, SoftwareSerial).
 *
 * @param serial Reference to the serial interface used for communication.
 * @param network Network ID to assign to the transmitter.
 * @param address Address ID to assign to the transmitter.
 * @param baudRate Baud rate for serial communication (default: 115200).
 * @param waitMs Delay time (in milliseconds) between commands (default: 200 ms).
 */
template <typename SerialT>
void transmitter(
    SerialT& serial,
    long network,
    long address,
    unsigned long baudRate = 115200,
    unsigned long waitMs = 200
) {
    /** 
     * @brief Initialize serial communication with the transmitter module.
     * 
     * Begins communication at the specified baud rate so commands
     * can be sent to the module.
     */
    serial.begin(baudRate);
    delay(waitMs);

    /**
     * @brief Check communication with the module.
     * 
     * "AT" is a basic attention command used to verify that the module
     * is responding. A properly functioning module typically replies "OK".
     */
    serial.println("AT");
    delay(waitMs);

    /**
     * @brief Set the network ID of the transmitter.
     * 
     * "AT+NETWORKID=<value>" configures the network group.
     * Only devices with the same network ID can communicate with each other.
     */
    serial.print("AT+NETWORKID=");
    serial.println(network);
    delay(waitMs);

    /**
     * @brief Set the address of the transmitter.
     * 
     * "AT+ADDRESS=<value>" assigns a unique identifier to this device.
     * This is used so other devices know where to send data.
     */
    serial.print("AT+ADDRESS=");
    serial.println(address);
    delay(waitMs);
}