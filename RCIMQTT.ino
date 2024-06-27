#include <M5Core2.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads1115;
int16_t adc0, adc1, adc2, adc3;

/* After M5Core2 is started or reset, the program in the setup() function will be executed, and this part will only be executed once. */
void setup() {
  delay(5000);

  M5.begin(); //Init M5Core2. Initialize M5Core2
                    /* Power chip connected to gpio21, gpio22, I2C device
                      Set battery charging voltage and current
                      If used battery, please call this function in your project */
  Wire.begin();

  ads1115.begin(0x48);
  ads1115.setGain(GAIN_ONE);
  adc0 = ads1115.readADC_SingleEnded(0);
  adc1 = ads1115.readADC_SingleEnded(1);

  M5.Lcd.drawString(String(adc0), 0, 180, 1);
  M5.Lcd.drawString(String(adc1), 0, 210, 1);
}

/* After the program in the setup() function is executed, the program in the loop() function will be executed
The loop() function is an endless loop, in which the program will continue to run repeatedly */
void loop() {
  M5.update();
}
