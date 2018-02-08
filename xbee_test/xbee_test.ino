/*
Name:    experiment.ino
Created: 11/8/2017 2:30:56 PM
*/

#include <SoftwareSerial.h>

// XBee's DOUT (TX) is connected to pin 2 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 3 (Arduino's Software TX)
SoftwareSerial XBee(2, 3); // RX, TX

// the setup function runs once when you press reset or power the board
void setup() {
  //  Start serial port
  Serial.begin(9600);
  XBee.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
  if (Serial.available()) {
    XBee.print(Serial.readString());
  }
  //  Handle updates through XBee
  handleXBee();
}

void handleXBee() {
  if (XBee.available()) {
    auto str = XBee.readString();

    Serial.println(str);
  }
}

