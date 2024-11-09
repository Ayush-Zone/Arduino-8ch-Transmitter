
# 8-Channel PPM Transmitter

This repository contains code for an 8-channel PPM transmitter, built using the nRF24L01 wireless module and Arduino. The transmitter reads analog joystick positions and digital switch inputs, then transmits the values wirelessly as PPM signals to a receiver. Ideal for RC (radio control) projects, the setup supports 8 channels, including throttle, yaw, pitch, roll, and four auxiliary channels.

## Features

- **8-Channel PPM Transmission**: Includes throttle, yaw, pitch, roll, and 4 auxiliary channels.
- **Wireless Communication**: Uses nRF24L01 for 2.4 GHz communication.
- **Configurable Joystick Inputs**: Maps analog joystick inputs with adjustable ranges.
- **Connection Status Indicator**: LED indicates successful nRF24L01 connection.
  
## Hardware Required

- Arduino (Uno, Nano, or similar)
- nRF24L01 Wireless Module
- Joystick module or potentiometers
- SPDT switches (for auxiliary channels)
- Status LED (optional)
- Jumper wires and breadboard for connections

## Pin Configuration

| Arduino Pin | Component      |
|-------------|----------------|
| A0          | Yaw Joystick   |
| A1          | Throttle Joystick |
| A3          | Roll Joystick  |
| A6          | Pitch Joystick |
| A4          | Aux1 Switch    |
| A5          | Aux2 Switch    |
| 7           | Aux3 Switch    |
| 8           | Aux4 Switch    |
| A2          | Connection Status LED |
| 9, 10       | nRF24L01 CE, CSN |

> **Note**: Ensure nRF24L01 has adequate power (use a capacitor if necessary for stability).

## Code Overview

The program initializes the nRF24L01 module to start transmission and maps joystick values to the 8-channel signal structure. Auxiliary channels are read as digital inputs. The data is then sent wirelessly at a 250 kbps data rate and displayed in the Serial Monitor.

### Key Functions

- `ResetData()`: Resets channel data to default "safe" values if no input is detected.
- `mapJoystickValues()`: Maps joystick analog values to an appropriate PPM range (0-255).
- `setup()`: Initializes the nRF24L01 and checks connection, lighting the LED if successful.
- `loop()`: Continuously reads joystick and switch data, updates `data` struct, and transmits.

## Usage

1. **Hardware Setup**: Connect joysticks, switches, and nRF24L01 module as per the pin configuration above.
2. **Upload Code**: Use the Arduino IDE to upload the code to your board.
3. **Monitoring**: Open Serial Monitor to view transmitted data values for debugging and verification.

## Serial Output

The Serial Monitor displays the following data in order:

- `Throttle`, `Yaw`, `Roll`, `Pitch`
- `Aux1`, `Aux2`, `Aux3`, `Aux4`

Example Output:
```plaintext
127 127 127 127 1 0 1 1
```

## License

This project is open-source and available under the [MIT License](https://opensource.org/licenses/MIT).
