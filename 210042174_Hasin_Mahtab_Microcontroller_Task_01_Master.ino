#include <Wire.h>

void setup() {
  //Initialize I2C
  Wire.begin();
}

byte x = 27;

void loop() {

  //Define the address where we want to connect to slave
  Wire.beginTransmission(12);
  //Send a string
  Wire.write("Master is Sending ");
  //sending the value of x
  Wire.write(x);
  //Ending the single transmission for next loop
  Wire.endTransmission();

  //Increment by 3
  x = x+3;
  delay(1000);
}
