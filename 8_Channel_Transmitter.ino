// 8 Channel PPM Receiver
// Ayush Sharma
// https://github.com/Ayush-Zone

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const uint64_t pipeOut = 0xE9E8F0F0E1LL;
RF24 radio(9, 10);

int ledPin = A2;  // Pin for connection status LED

struct Signal {
  byte throttle;
  byte yaw;
  byte pitch;
  byte roll;
  byte aux1;
  byte aux2;
  byte aux3;
  byte aux4;
};
Signal data;
void ResetData() {
  data.throttle = 0;
  data.yaw = 127;
  data.pitch = 127;
  data.roll = 127;
  data.aux1 = 0;
  data.aux2 = 0;
  data.aux3 = 0;
  data.aux4 = 0;
}
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.stopListening();
  radio.openWritingPipe(pipeOut);
  radio.setAutoAck(false);
  radio.setCRCLength(RF24_CRC_8);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(108);
  ResetData();

  pinMode(ledPin, OUTPUT);
  delay(1000);

  // Check if NRF24L01 module is connected
  if (radio.isChipConnected()) {
    digitalWrite(ledPin, HIGH);  // Turn on LED to indicate successful connection
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED if connection failed
  }
}

int mapJoystickValues(int val, int lower, int middle, int upper, bool reverse) {
  val = constrain(val, lower, upper);
  if (val < middle)
    val = map(val, lower, middle, 0, 128);
  else
    val = map(val, middle, upper, 128, 255);
  return (reverse ? 255 - val : val);
}
void loop() {

  // Read Joysticks analog inputs
  data.throttle = mapJoystickValues(analogRead(A1), 0, 522, 1023, false);
  data.yaw = mapJoystickValues(analogRead(A0), 0, 522, 1023, false);
  data.roll = mapJoystickValues(analogRead(A3), 0, 517, 1023, false);
  data.pitch = mapJoystickValues(analogRead(A6), 0, 507, 1023, true);

  // Read auxiliary switch states
  data.aux1 = digitalRead(A4);
  data.aux2 = digitalRead(A5);
  data.aux3 = digitalRead(7);
  data.aux4 = digitalRead(8);

  radio.write(&data, sizeof(Signal));

  Serial.print(data.throttle);
  Serial.print(" ");
  Serial.print(data.yaw);
  Serial.print(" ");
  Serial.print(data.roll);
  Serial.print(" ");
  Serial.print(data.pitch);
  Serial.print(" ");

  Serial.print(data.aux1);
  Serial.print(" ");
  Serial.print(data.aux2);
  Serial.println(" ");
}
