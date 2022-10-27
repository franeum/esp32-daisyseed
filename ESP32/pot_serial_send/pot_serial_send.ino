#include <HardwareSerial.h>

#define RX        16
#define TX        17
#define DEBUG     1
#define POT       4

HardwareSerial Serial_2(2);
uint8_t previous = 0;

void setup() {

  Serial_2.begin(115200, SERIAL_8N1, RX, TX);
  
#if DEBUG
  Serial.begin(115200);
#endif
  
  pinMode(POT, INPUT);
}

void loop() {
  uint8_t value = analogRead(POT) >> 5;
  if (value != previous) {

    Serial_2.println(value);
#if DEBUG
    Serial.println(value);
#endif
    
    previous = value;
  }
  delay(100);
}
