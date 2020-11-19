#include <Wire.h>

#define SDA_PIN 4
#define SCL_PIN 5
const int16_t I2C_MASTER = 0x42;
const int16_t I2C_SLAVE = 0x2E;
byte resValue = 0x00E;

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN, I2C_MASTER); // join i2c bus (address optional for master)
}

void loop() {
  // put your main codee here, to run repeatedly:
  Wire.beginTransmission(I2C_SLAVE); // transmit to device #8
  Wire.write(0x000);              // sends one byte
  Wire.write(resValue);
  Wire.endTransmission();
  delay(200);
  resValue++;
  if (resValue == 128) {
    resValue = 0;
    };
}
