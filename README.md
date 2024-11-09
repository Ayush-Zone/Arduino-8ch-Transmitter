# 8 Channel PWM Transmitter

This project implements an 8-channel PWM transmitter using an Arduino and nRF24L01 radio module. It is designed to send PWM signals for controlling various devices like drones or RC cars, through analog joystick inputs and auxiliary switches.

## Features

- 8 PWM Channels (Throttle, Yaw, Pitch, Roll, and 4 Auxiliary channels)
- Uses an **nRF24L01** wireless module for communication
- Joystick controls for throttle, yaw, pitch, and roll
- 4 auxiliary switches for additional control
- Feedback LED for connection status
- Low power consumption with automatic acknowledgment and CRC checks

## Hardware Requirements

- **Arduino Board** (such as Arduino Uno, Nano, or Mega)
- **nRF24L01 module**
- Joystick module (analog inputs for throttle, yaw, pitch, roll)
- 4 switches for auxiliary control
- External 3.3V power supply for nRF24L01 (if needed)
- LED for connection status (optional)

## Software Requirements

- **Arduino IDE**
- Libraries:
  - `SPI.h`
  - `nRF24L01.h`
  - `RF24.h`


### Pin Connections

- **nRF24L01 Module**:
  - CE Pin → Arduino Pin 9
  - CSN Pin → Arduino Pin 10
  - SCK Pin → Arduino Pin 13
  - MOSI Pin → Arduino Pin 11
  - MISO Pin → Arduino Pin 12
  - GND → GND
  - VCC → 3.3V (Do not use 5V, as the nRF24L01 operates on 3.3V)
- **Joystick**:
  - X-axis → A0 (Yaw)
  - Y-axis → A1 (Throttle)
  - Z-axis → A3 (Roll)
  - Additional axis (if any) → A6 (Pitch)
- **Auxiliary Switches**:
  - AUX1 → A4
  - AUX2 → A5
  - AUX3 → Pin 7
  - AUX4 → Pin 8
- **LED**: Connected to Pin A2 for connection status

## Code Explanation

The code initializes the nRF24L01 module and sets up communication parameters for the wireless transmission. It continuously reads the joystick analog inputs for throttle, yaw, pitch, and roll, as well as the states of 4 auxiliary switches. These values are sent wirelessly via the nRF24L01 module.

### Key Functions

- **ResetData()**: Resets the signal values to default values before sending.
- **mapJoystickValues()**: Maps joystick input values to PWM values, with options for reversing the input.
- **loop()**: Reads analog inputs, updates the signal structure, and sends the data over the radio.

### Joystick Controls

- **Throttle**: Analog input from pin A1 (forward/backward movement).
- **Yaw**: Analog input from pin A0 (left/right rotation).
- **Roll**: Analog input from pin A3 (roll control).
- **Pitch**: Analog input from pin A6 (up/down movement).

### Auxiliary Switches

- **Aux1**: Digital input from pin A4 (could be used for a button or toggle switch).
- **Aux2**: Digital input from pin A5.
- **Aux3**: Digital input from pin 7.
- **Aux4**: Digital input from pin 8.

### Connection Status LED

- **LED Pin (A2)**: Turns on when the nRF24L01 module is successfully connected and communication is active.

## How to Use

1. **Setup Hardware**: Connect the Arduino and nRF24L01 module according to the circuit diagram above.
2. **Upload the Code**: Upload the provided code to your Arduino via the Arduino IDE.
3. **Test**: Open the serial monitor to view the real-time PWM values being transmitted. If the LED lights up, it indicates that the nRF24L01 is connected and working.
4. **Adjust Controls**: Move the joystick to see the PWM values for throttle, yaw, pitch, and roll update on the serial monitor.

## Troubleshooting

- **LED not lighting up**: Double-check the wiring for the nRF24L01 module. Make sure it's powered correctly (3.3V, not 5V).
- **No connection**: If the nRF24L01 module isn't connecting, ensure the `pipeOut` address matches the receiver's pipe and that the module is connected properly to the Arduino.

## License

This project is open-source and available under the [MIT License](LICENSE).

## Author

Ayush Sharma  
[GitHub: Ayush-Zone](https://github.com/Ayush-Zone)
