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

  //ADS1115 ADC
  ads1115.begin(0x48);
  ads1115.setGain(GAIN_ONE);
  adc0 = ads1115.readADC_SingleEnded(0);
  adc1 = ads1115.readADC_SingleEnded(1);

  M5.Lcd.drawString(String(adc0), 0, 180, 1);
  M5.Lcd.drawString(String(adc1), 0, 210, 1);

  //AD5665R DAC
  //TURN ON INTERNAL REFRENCE VOLTAGE
  Wire.beginTransmission(0x1f);
  Wire.write(byte(56));
  Wire.write(byte(0));
  Wire.write(byte(1));
  Wire.endTransmission();

  //SET ALL CHANNELS TO 0
  Wire.beginTransmission(0x1f);
  Wire.write(byte(7));
  Wire.write(byte(0));
  Wire.write(byte(0));
  Wire.endTransmission();

  
  //TEST WRITE TO AD5665R DAC
  Wire.beginTransmission(0x1f);
  Wire.write(byte(0));
  Wire.write(byte(int(65535) >> 8));
  Wire.write(byte(int(65535)));
  Wire.endTransmission();

  Wire.beginTransmission(0x1f);
  Wire.write(byte(1));
  Wire.write(byte(int(65535) >> 8));
  Wire.write(byte(int(65535)));
  Wire.endTransmission();
  
}

/* After the program in the setup() function is executed, the program in the loop() function will be executed
The loop() function is an endless loop, in which the program will continue to run repeatedly */
void loop() {
  M5.update();
}
