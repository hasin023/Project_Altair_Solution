#include <Wire.h>

void setup() {
  //Starting connection as the same address as Master
  Wire.begin(12);             
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  delay(100);
}


void receiveEvent(int howMany) {
  while (1 < Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  //recieveing the x value
  int x = Wire.read();
  Serial.println(x);
}
