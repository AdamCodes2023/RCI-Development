#include <SSLClient.h>
#include "certificates.h" // This file must be regenerated
#include <ArduinoMqttClient.h>
#include <M5Core2.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <Adafruit_MCP4728.h>
#include <Adafruit_PCF8574.h>
#include <Preferences.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

const char broker[]    = "06e8c7b775f1454b8b94fcd788277596.s2.eu.hivemq.cloud";
int        port        = 8883;
const char willTopic[] = "arduino/will";

String di1_feed = String("/feeds/di1");

String di2_feed = String("/feeds/di2");

String di3_feed = String("");

String di4_feed = String("");

String di5_feed = String("");

String di6_feed = String("");

String di7_feed = String("");

String di8_feed = String("");

String do1_feed = String("/feeds/do1");

String do2_feed = String("/feeds/do2");

String do3_feed = String("");

String do4_feed = String("");

String do5_feed = String("");

String do6_feed = String("");

String do7_feed = String("");

String do8_feed = String("");

String ai1_feed = String("/feeds/ai1");

String ai2_feed = String("/feeds/ai2");

String ai3_feed = String("");

String ai4_feed = String("");

String ai5_feed = String("");

String ai6_feed = String("");

String ai7_feed = String("");

String ai8_feed = String("");

String ao1_feed = String("/feeds/ao1");

String ao2_feed = String("/feeds/ao2");

String ao3_feed = String("");

String ao4_feed = String("");

String ao5_feed = String("");

String ao6_feed = String("");

String ao7_feed = String("");

String ao8_feed = String("");

String ds0, ds1, ds2, ds3, ds4, ds5, ds6, ds7;
String * di_feeds[8];
String as0, as1, as2, as3, as4, as5, as6, as7;
String * ai_feeds[8];

//#INITIAL VARIABLES
String di1_value = String("-1");
String di2_value = String("-2");
String di3_value = String("-3");
String di4_value = String("-4");
String di5_value = String("-5");
String di6_value = String("-6");
String di7_value = String("-7");
String di8_value = String("-8");

String do1_value = String("-1");
String do2_value = String("-2");
String do3_value = String("-3");
String do4_value = String("-4");
String do5_value = String("-5");
String do6_value = String("-6");
String do7_value = String("-7");
String do8_value = String("-8");

String ai1_value = String("-1");
String ai2_value = String("-2");
String ai3_value = String("-3");
String ai4_value = String("-4");
String ai5_value = String("-5");
String ai6_value = String("-6");
String ai7_value = String("-7");
String ai8_value = String("-8");

String ao1_value = String("-1");
String ao2_value = String("-2");
String ao3_value = String("-3");
String ao4_value = String("-4");
String ao5_value = String("-5");
String ao6_value = String("-6");
String ao7_value = String("-7");
String ao8_value = String("-8");

unsigned int cycleCounter = 0;

const long interval = 3600000;
const long interval2 = 2000;
const long interval3 = 1800000;
const long interval4 = 5000;
const long interval5 = 5000;
const long interval6 = 5000;
const long interval7 = 1800000;
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;
unsigned long previousMillis5 = 0;
unsigned long previousMillis6 = 0;
unsigned long previousMillis7 = 0;
unsigned long currentMillis = 0;
unsigned long currentMillis2 = 0;
unsigned long currentMillis3 = 0;
unsigned long currentMillis4 = 0;
unsigned long currentMillis5 = 0;
unsigned long currentMillis6 = 0;
unsigned long currentMillis7 = 0;

Button leftRed(0, 240, 106, 40, "left-red");
Button centerRed(106, 240, 106, 40, "center-red");
Button rightRed(212, 240, 106, 40, "right-red");

bool normalMode = true;
bool configMenu1 = false;
bool configMenu2 = false;
bool centerPressedOnce = false;
bool leftPressedOnce = false;
bool rightPressedOnce = false;
bool rightPressedTwice = false;
bool rightPressedThree = false;
int configMenu1Iterator = 0;
long configAo1Value = 0;
long configAo2Value = 0;

EthernetClient ethClient;
EthernetClient configEthClient;
SSLClient ethClientSSL(ethClient, TAs, (size_t)TAs_NUM, G36);
SSLClient configEthClientSSL(configEthClient, TAs, (size_t)TAs_NUM, G36);
MqttClient mqttClient(ethClientSSL);
MqttClient configClient(configEthClientSSL);

String payload;
bool retained = false;
int qos = 0;
bool duplicateMqttMessage = false;

Adafruit_ADS1115 ads1115;
int16_t adc0, adc1, adc2, adc3;

Adafruit_MCP4728 mcp;

Adafruit_PCF8574 pcfr;

Adafruit_PCF8574 pcfw1;
Adafruit_PCF8574 pcfw2;

int16_t adc0Prev = 0;
int16_t adc1Prev = 0;

int pcfr0Prev = 0;
int pcfr1Prev = 0;

bool clear = false;

int reconnectCount = 0;
bool reconnect = false;

const int chipSelect = 4;
File myFile;

Preferences preferences;
const char* pnamespace = "InternalInfo";
const char* serialKey = "SerialNumber";
const char* macKey = "MacAddress";
String serialNumber = String("");
String stringMac = String("");

bool hasConfigInfo = false;
String groupID = String("");
String unitID = String("");
String IONum = String("");
String updateTime = String("");
String consumerName = String("");
bool ioKnown = false;

void replaceText(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int textSize, String text) {
  M5.Lcd.fillRect(x, y, width, height, BLACK);
  M5.Lcd.drawString(text, x, y, textSize);
}

void cycleComponentValues() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  if (cycleCounter == 0) {
    M5.Lcd.drawString("Digital Inputs", 40, 0, 1);
    M5.Lcd.drawString("1: " + di1_value, 0, 40, 1);
    M5.Lcd.drawString("2: " + di2_value, 0, 80, 1);
    M5.Lcd.drawString("3: " + di3_value, 0, 120, 1);
    M5.Lcd.drawString("4: " + di4_value, 0, 160, 1);
    M5.Lcd.drawString("5: " + di5_value, 170, 40, 1);
    M5.Lcd.drawString("6: " + di6_value, 170, 80, 1);
    M5.Lcd.drawString("7: " + di7_value, 170, 120, 1);
    M5.Lcd.drawString("8: " + di8_value, 170, 160, 1);
    M5.Lcd.drawString("CFG", 240, 210, 1);
  }
  if (cycleCounter == 1) {
    M5.Lcd.drawString("Digital Outputs", 30, 0, 1);
    M5.Lcd.drawString("1: " + do1_value, 0, 40, 1);
    M5.Lcd.drawString("2: " + do2_value, 0, 80, 1);
    M5.Lcd.drawString("3: " + do3_value, 0, 120, 1);
    M5.Lcd.drawString("4: " + do4_value, 0, 160, 1);
    M5.Lcd.drawString("5: " + do5_value, 170, 40, 1);
    M5.Lcd.drawString("6: " + do6_value, 170, 80, 1);
    M5.Lcd.drawString("7: " + do7_value, 170, 120, 1);
    M5.Lcd.drawString("8: " + do8_value, 170, 160, 1); 
    M5.Lcd.drawString("CFG", 240, 210, 1);   
  }
  if (cycleCounter == 2) {
    M5.Lcd.drawString("Analog Inputs", 40, 0, 1);
    M5.Lcd.drawString("1: " + String((ai1_value.toFloat() * 2) / 3276.75, 2), 0, 40, 1);
    M5.Lcd.drawString("2: " + String((ai2_value.toFloat() * 2) / 3276.75, 2), 0, 80, 1);
    M5.Lcd.drawString("3: " + String((ai3_value.toFloat() * 2) / 3276.75, 2), 0, 120, 1);
    M5.Lcd.drawString("4: " + String((ai4_value.toFloat() * 2) / 3276.75, 2), 0, 160, 1);
    M5.Lcd.drawString("5: " + String((ai5_value.toFloat() * 2) / 3276.75, 2), 170, 40, 1);
    M5.Lcd.drawString("6: " + String((ai6_value.toFloat() * 2) / 3276.75, 2), 170, 80, 1);
    M5.Lcd.drawString("7: " + String((ai7_value.toFloat() * 2) / 3276.75, 2), 170, 120, 1);
    M5.Lcd.drawString("8: " + String((ai8_value.toFloat() * 2) / 3276.75, 2), 170, 160, 1);
    M5.Lcd.drawString("CFG", 240, 210, 1);
  }
  if (cycleCounter == 3) {
    M5.Lcd.drawString("Analog Outputs", 40, 0, 1);
    M5.Lcd.drawString("1: " + String((ao1_value.toFloat() * 2) / 3276.75, 2), 0, 40, 1);
    M5.Lcd.drawString("2: " + String((ao2_value.toFloat() * 2) / 3276.75, 2), 0, 80, 1);
    M5.Lcd.drawString("3: " + String((ao3_value.toFloat() * 2) / 3276.75, 2), 0, 120, 1);
    M5.Lcd.drawString("4: " + String((ao4_value.toFloat() * 2) / 3276.75, 2), 0, 160, 1);
    M5.Lcd.drawString("5: " + String((ao5_value.toFloat() * 2) / 3276.75, 2), 170, 40, 1);
    M5.Lcd.drawString("6: " + String((ao6_value.toFloat() * 2) / 3276.75, 2), 170, 80, 1);
    M5.Lcd.drawString("7: " + String((ao7_value.toFloat() * 2) / 3276.75, 2), 170, 120, 1);
    M5.Lcd.drawString("8: " + String((ao8_value.toFloat() * 2) / 3276.75, 2), 170, 160, 1);
    M5.Lcd.drawString("CFG", 240, 210, 1);
  }
  cycleCounter++;
  if (cycleCounter >= 4) {
    cycleCounter = 0;
  }
}

void onLeftPress() {
  if (configMenu1 || configMenu2) {
    if (leftRed.isPressed()) {
      leftPressedOnce = true;
    }
  }
}

void onLeftRelease() {
  if (configMenu1) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
      configMenu1Iterator--;
      if (configMenu1Iterator < 0) {
        configMenu1Iterator = 4;
      }
      if (configMenu1Iterator == 0) {
        M5.Lcd.fillRect(50, 50, 100, 30, BLACK);
        M5.Lcd.fillRect(80, 0, 60, 30, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 1) {
        M5.Lcd.fillRect(50, 100, 100, 30, BLACK);
        M5.Lcd.fillRect(50, 50, 100, 30, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 2) {
        M5.Lcd.fillRect(50, 150, 100, 30, BLACK);
        M5.Lcd.fillRect(50, 100, 100, 30, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 3) {
        M5.Lcd.fillRect(50, 200, 100, 30, BLACK);
        M5.Lcd.fillRect(50, 150, 100, 30, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 4) {
        M5.Lcd.fillRect(80, 0, 60, 30, BLACK);
        M5.Lcd.fillRect(50, 200, 100, 30, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
    }
  }
  if (configMenu2 && configMenu1Iterator == 1) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
    }
  }
  if (configMenu2 && configMenu1Iterator == 2) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
    }  
  }
  if (configMenu2 && configMenu1Iterator == 3) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
    }
  }
  if (configMenu2 && configMenu1Iterator == 4) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((configAo1Value) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);

      Wire.beginTransmission(0x1f);
      Wire.write(byte(0));
      Wire.write(byte(int(configAo1Value * 2) >> 8));
      Wire.write(byte(int(configAo1Value * 2)));
      Wire.endTransmission();

      replaceText(10, 80, 300, 30, 1, String(configAo1Value * 2));
      configAo1Value += int((32768/5));
      if (configAo1Value > 32768) {
        configAo1Value = 0;
      }
    }  
  }
}

void onCenterPress() {
  if (configMenu1 || configMenu2) {
    if (centerRed.isPressed()) {
      centerPressedOnce = true;
    }
  }
}

void onCenterRelease() {
  if (configMenu1) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
      configMenu1Iterator++;
      if (configMenu1Iterator > 4) {
        configMenu1Iterator = 0;
      }
      if (configMenu1Iterator == 0) {
        M5.Lcd.fillRect(80, 0, 60, 30, BLACK);
        M5.Lcd.fillRect(50, 50, 100, 30, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 1) {
        M5.Lcd.fillRect(50, 50, 100, 30, BLACK);
        M5.Lcd.fillRect(50, 100, 100, 30, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 2) {
        M5.Lcd.fillRect(50, 100, 100, 30, BLACK);
        M5.Lcd.fillRect(50, 150, 100, 30, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 3) {
        M5.Lcd.fillRect(50, 150, 100, 30, BLACK);
        M5.Lcd.fillRect(50, 200, 100, 30, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 4) {
        M5.Lcd.fillRect(50, 200, 100, 30, BLACK);
        M5.Lcd.fillRect(80, 0, 60, 30, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
    }
  }
  if (configMenu2 && configMenu1Iterator == 1) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
    }
  }
  if (configMenu2 && configMenu1Iterator == 2) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
    }  
  }
  if (configMenu2 && configMenu1Iterator == 3) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
    }
  }
  if (configMenu2 && configMenu1Iterator == 4) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((configAo1Value) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);

      Wire.beginTransmission(0x1f);
      Wire.write(byte(0));
      Wire.write(byte(int(configAo1Value * 2) >> 8));
      Wire.write(byte(int(configAo1Value * 2)));
      Wire.endTransmission();

      replaceText(10, 80, 300, 30, 1, String(configAo1Value * 2));
      configAo1Value -= int((32768/5));
      if (configAo1Value < 0) {
        configAo1Value = 32767;
      }
    }
  }
}

void onRightPress() {
  if (rightRed.isPressed() && normalMode) {
    rightPressedOnce = true;
    normalMode = false;
  }

  if (rightRed.isPressed() && configMenu1) {
    rightPressedTwice = true;
    configMenu1 = false;
  }

  if (rightRed.isPressed() && configMenu2) {
    rightPressedThree = true;
    configMenu2 = false;
  }
}

void onRightRelease() {
  if (rightRed.isReleased() && rightPressedOnce) {
    configMenu1 = true;
    rightPressedOnce = false;
    M5.Lcd.drawString("CONFIG MODE", 10, 200, 1);
    delay(1000);
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);
    mqttClient.stop();

    M5.Lcd.fillRect(80, 0, 60, 30, GREEN);
    M5.Lcd.drawString("EXIT", 80, 0, 1);
    M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
    M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
    M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
    M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
  }

  if (rightRed.isReleased() && rightPressedTwice) {
    rightPressedTwice = false;

    if (configMenu1Iterator == 0) {
      normalMode = true;
      M5.Lcd.drawString("NORMAL MODE", 10, 200, 1);
      configAo1Value = 0;
      configAo2Value = 0;
      //mcp.setChannelValue(MCP4728_CHANNEL_A, (ai1_value.toInt() * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                  MCP4728_GAIN_2X);
      //mcp.setChannelValue(MCP4728_CHANNEL_B, (ai2_value.toInt() * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                  MCP4728_GAIN_2X);

      Wire.beginTransmission(0x1f);
      Wire.write(byte(0));
      Wire.write(byte(int(ai1_value.toInt() * 2) >> 8));
      Wire.write(byte(int(ai1_value.toInt() * 2)));
      Wire.endTransmission();

      Wire.beginTransmission(0x1f);
      Wire.write(byte(1));
      Wire.write(byte(int(ai2_value.toInt() * 2) >> 8));
      Wire.write(byte(int(ai2_value.toInt() * 2)));
      Wire.endTransmission();

      delay(1000);
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
    }

    if (configMenu1Iterator == 1) {
      configMenu2 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      delay(300);
      M5.Lcd.drawString("DI1 READ VALUE: ", 10, 50, 1);
      M5.Lcd.drawString("DI2 READ VALUE: ", 10, 120, 1);
    }
    if (configMenu1Iterator == 2) {
      configMenu2 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      delay(300);
      M5.Lcd.drawString("DO1 SEND VALUE: ", 10, 50, 1);
      M5.Lcd.drawString("DO2 SEND VALUE: ", 10, 120, 1);
    }

    if (configMenu1Iterator == 3) {
      configMenu2 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      delay(300);
      M5.Lcd.drawString("AI1 READ VALUE: ", 10, 50, 1);
      M5.Lcd.drawString("AI2 READ VALUE: ", 10, 120, 1);
    }
    
    if (configMenu1Iterator == 4) {
      configMenu2 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      delay(300);
      M5.Lcd.drawString("AO1 SEND VALUE: ", 10, 50, 1);
      M5.Lcd.drawString("AO2 SEND VALUE: ", 10, 120, 1);
    }
  }
  if (rightRed.isReleased() && rightPressedThree) {
    rightPressedThree = false;
    configMenu1 = true;
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);
    delay(300);

    configMenu1Iterator = 0;
    M5.Lcd.fillRect(80, 0, 60, 30, GREEN);
    M5.Lcd.drawString("EXIT", 80, 0, 1);
    M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
    M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
    M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
    M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
  }
}

void publishDI1() {
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI1!");
  previousMillis2 = millis();
  clear = true;
  
  pcfr0Prev = int(pcfr.digitalRead(0));
  payload = String(pcfr0Prev);
  di1_value = payload;

  mqttClient.beginMessage(di1_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishDI2() {
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI2!");
  previousMillis2 = millis();
  clear = true;
  
  pcfr1Prev = int(pcfr.digitalRead(1));
  payload = String(pcfr1Prev);
  di2_value = payload;

  mqttClient.beginMessage(di2_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);  
}

void publishAI1() {
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI1");
  previousMillis2 = millis();
  clear = true;
  
  adc0 = ads1115.readADC_SingleEnded(0);
  adc0Prev = adc0;
  payload = String(adc0);
  ai1_value = payload;

  mqttClient.beginMessage(ai1_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAI2() {
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI2!");
  previousMillis2 = millis();
  clear = true;
  
  adc1 = ads1115.readADC_SingleEnded(1);
  adc1Prev = adc1;
  payload = String(adc1);
  ai2_value = payload;

  mqttClient.beginMessage(ai2_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAll() {
  replaceText(10, 200, 300, 50, 1, "PUBLISHING ALL!");
  previousMillis2 = millis();
  clear = true;

  // save the last time a message was sent
  previousMillis = currentMillis;
  
  publishDI1();

  publishDI2();

  publishAI1();

  publishAI2();

  reconnectCount++;
}

void onConfigMqttMessage(int messageSize) {
  reconnectCount = 0;

  String message;
  message = "";
  // we received a message, print out the topic and contents

  String topic;
  topic = "";
  topic = configClient.messageTopic();

  // use the Stream interface to print the contents
  while (configClient.available()) {
    message += ((char)configClient.read());
  }


  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("GID")) {
    groupID = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("UID")) {
    unitID = message;
  }
  if (topic.substring(topic.length() - 2, topic.length()).equalsIgnoreCase("IO")) {
    IONum = message;
    ioKnown = true;
  }
  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase("UPDATE")) {
    updateTime = message;
  }
  if (topic.substring(topic.length() - 4, topic.length()).equalsIgnoreCase("NAME")) {
    consumerName = message;
    hasConfigInfo = true;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO1")) {
    do1_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO2")) {
    do2_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO3")) {
    do3_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO4")) {
    do4_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO5")) {
    do5_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO6")) {
    do6_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO7")) {
    do7_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO8")) {
    do8_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO1")) {
    ao1_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO2")) {
    ao2_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO3")) {
    ao3_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO4")) {
    ao4_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO5")) {
    ao5_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO6")) {
    ao6_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO7")) {
    ao7_feed = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO8")) {
    ao8_feed = message;
  }
}

void onMqttMessage(int messageSize) {
  reconnectCount = 0;

  String message;
  message = "";
  // we received a message, print out the topic and contents

  String topic;
  topic = "";
  topic = mqttClient.messageTopic();

  // use the Stream interface to print the contents
  while (mqttClient.available()) {
    message += ((char)mqttClient.read());
  }

  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO1")) {
    pcfw1.digitalWrite(0, !bool(message.toInt()));
    do1_value = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO2")) {
    pcfw1.digitalWrite(1, !bool(message.toInt()));
    do2_value = message;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO1")) {
    if ((message.toInt()) < 0) {
      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();

      //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);

      ao1_value = "0";
    }
    else {
      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(0));
      Wire.write(byte(int(message.toInt() * 2) >> 8));
      Wire.write(byte(int(message.toInt() * 2)));
      Wire.endTransmission();

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);

      ao1_value = message;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO2")) {
    if ((message.toInt()) < 0) {
      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(1));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
      
      //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);

      ao2_value = "0";
    }
    else {
      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(1));
      Wire.write(byte(int(message.toInt() * 2) >> 8));
      Wire.write(byte(int(message.toInt() * 2)));
      Wire.endTransmission();

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);

      ao2_value = message;
    }
  }
}

void configConnect() {
  String willPayload = "oh no!";
  bool willRetain = true;
  int willQos = 0;

  configClient.beginWill(willTopic, willPayload.length(), willRetain, willQos);
  configClient.print(willPayload);
  configClient.endWill();
  
  configClient.setUsernamePassword("ADAMMQTT5","Pribusin2");
  
  if (!reconnect) {
    M5.Lcd.print("Attempting to connect to the MQTT broker:\n");
    M5.Lcd.print("CONFIG HIVEMQ\n");
  }

  if (!configClient.connect(broker, port)) {
    if (!reconnect) {
      M5.Lcd.print("MQTT connection failed! Error code = ");
      M5.Lcd.print(configClient.connectError());
      M5.Lcd.print("\n");
    }

    reconnect = true;
    return;
  }

  M5.Lcd.print("You're connected to the MQTT broker!\n");

  // set the message receive callback
  configClient.onMessage(onConfigMqttMessage);

  // subscribe to a topic
  // the second parameter sets the QoS of the subscription,
  // the the library supports subscribing at QoS 0, 1, or 2
  int subscribeQos = 0;

  configClient.subscribe(serialNumber + "_GID", subscribeQos);
  configClient.subscribe(serialNumber + "_UID", subscribeQos);
  configClient.subscribe(serialNumber + "_IO", subscribeQos);
  configClient.subscribe(serialNumber + "_UPDATE", subscribeQos);
  configClient.subscribe(serialNumber + "_NAME", subscribeQos);

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  reconnect = false;

  previousMillis7 = millis();
}

void reconnectMqtt() {
  reconnectCount = 0;
  
  String willPayload = "oh no!";
  bool willRetain = true;
  int willQos = 0;

  mqttClient.beginWill(willTopic, willPayload.length(), willRetain, willQos);
  mqttClient.print(willPayload);
  mqttClient.endWill();
  
  mqttClient.setUsernamePassword("ADAMMQTT3","Tennis19");
  
  if (!reconnect) {
    M5.Lcd.print("Attempting to connect to the MQTT broker:\n");
    M5.Lcd.print("HIVEMQ\n");
  }

  if (!mqttClient.connect(broker, port)) {
    if (!reconnect) {
      M5.Lcd.print("MQTT connection failed! Error code = ");
      M5.Lcd.print(mqttClient.connectError());
      M5.Lcd.print("\n");
    }

    reconnect = true;
    return;
  }

  M5.Lcd.print("You're connected to the MQTT broker!\n");

  delay(1000);

  // set the message receive callback
  mqttClient.onMessage(onMqttMessage);

  // subscribe to a topic
  // the second parameter sets the QoS of the subscription,
  // the the library supports subscribing at QoS 0, 1, or 2
  int subscribeQos = 0;

  if (!do1_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do1_feed, subscribeQos);
  }
  if (!do2_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do2_feed, subscribeQos);
  }
  if (!do3_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do3_feed, subscribeQos);
  }
  if (!do4_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do4_feed, subscribeQos);
  }
  if (!do5_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do5_feed, subscribeQos);
  }
  if (!do6_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do6_feed, subscribeQos);
  }
  if (!do7_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do7_feed, subscribeQos);
  }
  if (!do8_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do8_feed, subscribeQos);
  }
  if (!ao1_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao1_feed, subscribeQos);
  }
  if (!ao2_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao2_feed, subscribeQos);
  }
  if (!ao3_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao3_feed, subscribeQos);
  }
  if (!ao4_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao4_feed, subscribeQos);
  }
  if (!ao5_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao5_feed, subscribeQos);
  }
  if (!ao6_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao6_feed, subscribeQos);
  }
  if (!ao7_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao7_feed, subscribeQos);
  }
  if (!ao8_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao8_feed, subscribeQos);
  }

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  reconnect = false;

  cycleCounter = 0;
  cycleComponentValues();

  previousMillis3 = millis();
  previousMillis4 = millis();
}

void hexCharacterStringToBytes(byte *byteArray, const char *hexString) {
  bool oddLength = strlen(hexString) & 1;

  byte currentByte = 0;
  byte byteIndex = 0;

  for (byte charIndex = 0; charIndex < strlen(hexString); charIndex++) {
    bool oddCharIndex = charIndex & 1;

    if (oddLength) {
      // If the length is odd
      if (oddCharIndex) {
        // odd characters go in high nibble
        currentByte = nibble(hexString[charIndex]) << 4;
      } else {
        // Even characters go into low nibble
        currentByte |= nibble(hexString[charIndex]);
        byteArray[byteIndex++] = currentByte;
        currentByte = 0;
      }
    } else {
      // If the length is even
      if (!oddCharIndex) {
        // Odd characters go into the high nibble
        currentByte = nibble(hexString[charIndex]) << 4;
      }
      else {
        // Odd characters go into low nibble
        currentByte |= nibble(hexString[charIndex]);
        byteArray[byteIndex++] = currentByte;
        currentByte = 0;
      }
    }
  }
}

byte nibble(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';

  if (c >= 'a' && c <= 'f')
    return c - 'a' + 10;

  if (c >= 'A' && c <= 'F')
    return c - 'A' + 10;

  return 0;  // Not a valid hexadecimal character
}

/* After M5Core2 is started or reset, the program in the setup() function will be executed, and this part will only be executed once. */
void setup() {
  delay(5000);

  M5.begin(); //Init M5Core2. Initialize M5Core2
                    /* Power chip connected to gpio21, gpio22, I2C device
                      Set battery charging voltage and current
                      If used battery, please call this function in your project */
  M5.Lcd.setTextSize(3);
  
  Wire.begin();

  di_feeds[0] = & ds0;// <-- The '&' symbol sends just the String's pointer
  di_feeds[1] = & ds1;//     through the '=' symbol to the array.
  di_feeds[2] = & ds2;//
  di_feeds[3] = & ds3;// <-- We still must load the real Strings into the
  di_feeds[4] = & ds4;//     array, one by one.
  di_feeds[5] = & ds5;//
  di_feeds[6] = & ds6;//
  di_feeds[7] = & ds7;

  ai_feeds[0] = & as0;// <-- The '&' symbol sends just the String's pointer
  ai_feeds[1] = & as1;//     through the '=' symbol to the array.
  ai_feeds[2] = & as2;//
  ai_feeds[3] = & as3;// <-- We still must load the real Strings into the
  ai_feeds[4] = & as4;//     array, one by one.
  ai_feeds[5] = & as5;//
  ai_feeds[6] = & as6;//
  ai_feeds[7] = & as7;

  //WRITE SERIAL NUMBER AND MAC ADDRESS TO INTERNAL MEMORY
  if (SD.exists("/internal.txt") == 1) {
    myFile = SD.open("/internal.txt");
    while (myFile.available()) {
      analyzeSDCardContents();
    }
    myFile.close();
    SD.remove("/internal.txt");
    preferences.begin(pnamespace);
    preferences.putString(serialKey, serialNumber);
    preferences.putString(macKey, stringMac);
    preferences.end();
  }

  //RETREIVE IMPORTANT INTERNAL INFO
  preferences.begin(pnamespace);
  serialNumber = preferences.getString(serialKey);
  stringMac = preferences.getString(macKey);
  preferences.end();

  if (stringMac.indexOf(":") != -1) {
    hexCharacterStringToBytes(mac, stringMac.substring(0, stringMac.length() - 1).c_str());
  }

  Ethernet.init(26);
  Ethernet.begin(mac);

  /*
  //TEST SD CARD OPERATIONS
  myFile = SD.open("/test.txt", FILE_WRITE);
  myFile.println("testing 1, 2, 3.");
  myFile.close();
  myFile = SD.open("/test.txt");
  M5.Lcd.print(myFile.read());
  myFile.close();
  */

  //ADS1115 ADC
  ads1115.begin(0x48);
  ads1115.setGain(GAIN_ONE);
  adc0 = ads1115.readADC_SingleEnded(0);
  adc1 = ads1115.readADC_SingleEnded(1);
  adc0Prev = ads1115.readADC_SingleEnded(0);
  adc1Prev = ads1115.readADC_SingleEnded(1);

  //M5.Lcd.drawString(String(adc0), 0, 120, 1);
  //M5.Lcd.drawString(String(adc1), 0, 150, 1);

  /*
  //MCP4728 DAC
  mcp.begin(0x60);
  mcp.setChannelValue(MCP4728_CHANNEL_A, 0, MCP4728_VREF_INTERNAL,
                      MCP4728_GAIN_2X);
  mcp.setChannelValue(MCP4728_CHANNEL_B, 0, MCP4728_VREF_INTERNAL,
                      MCP4728_GAIN_2X);
  mcp.setChannelValue(MCP4728_CHANNEL_C, 0, MCP4728_VREF_INTERNAL,
                      MCP4728_GAIN_2X);
  mcp.setChannelValue(MCP4728_CHANNEL_D, 0, MCP4728_VREF_INTERNAL,
                      MCP4728_GAIN_2X);
  */

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

  pcfr.begin(0x38, &Wire);
  pcfr.pinMode(0, INPUT_PULLUP);
  pcfr.pinMode(1, INPUT_PULLUP);
  pcfr.digitalWrite(0, true);
  pcfr.digitalWrite(1, true);

  pcfr0Prev = int(pcfr.digitalRead(0));
  pcfr1Prev = int(pcfr.digitalRead(1));

  //M5.Lcd.drawString(String(pcfr0Prev), 0, 60, 1);
  //M5.Lcd.drawString(String(pcfr1Prev), 0, 90, 1);

  pcfw1.begin(0x39, &Wire);
  pcfw1.pinMode(0, OUTPUT);
  pcfw1.pinMode(1, OUTPUT);
  pcfw1.digitalWrite(0, true);
  pcfw1.digitalWrite(1, true);

  pcfw2.begin(0x3a, &Wire);
  pcfw2.pinMode(0, OUTPUT);
  pcfw2.pinMode(1, OUTPUT);
  pcfw2.digitalWrite(0, true);
  pcfw2.digitalWrite(1, true);

  reconnectMqtt();
  publishDI1();
  publishDI2();
  publishAI1();
  publishAI2();
  publishAll();
  
  /*
  //SCAN I2C BUS
  byte error, address;
  int nDevices;

  while (true) {
    nDevices = 0;
    for(address = 1; address < 127; address++ )
    {
      // The i2c_scanner uses the return value of
      // the Write.endTransmisstion to see if
      // a device did acknowledge to the address.
      Wire.beginTransmission(address);
      error = Wire.endTransmission();

      if (error == 0)
      {
        M5.Lcd.print("I2C device found at address 0x");
        if (address<16)
          M5.Lcd.print("0");
        M5.Lcd.print(address,HEX);
        M5.Lcd.print("  !\n");

        nDevices++;
      }
      else if (error==4)
      {
        M5.Lcd.print("Unknown error at address 0x");
        if (address<16)
          M5.Lcd.print("0");
        M5.Lcd.print(address,HEX);
        M5.Lcd.print("\n");
      }
    }
    if (nDevices == 0)
      M5.Lcd.print("No I2C devices found\n");
    else
      M5.Lcd.print("done\n");

    delay(2000);           // wait 2 seconds for next scan
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);
  }
  */
}

/* After the program in the setup() function is executed, the program in the loop() function will be executed
The loop() function is an endless loop, in which the program will continue to run repeatedly */
void loop() {
  M5.update();

  if (normalMode) {
    currentMillis3 = millis();
    if (reconnectCount >= 4 || currentMillis3 - previousMillis3 >= interval3) {
      mqttClient.stop();
      delay(5000);
    }

    while (!mqttClient.connected()) {
      if (!reconnect) {
        M5.Lcd.clear();
        M5.Lcd.setCursor(0, 0);
      }
      reconnectMqtt();
    }

    currentMillis5 = millis();
    if (currentMillis5 - previousMillis5 >= interval5) {
      previousMillis5 = currentMillis5;
      //client.loop();
      mqttClient.poll();
    }

    currentMillis6 = millis();
    if (currentMillis6 - previousMillis6 >= interval6) {
      previousMillis6 = currentMillis6;

      if ((adc0Prev + 100) < ads1115.readADC_SingleEnded(0) || (adc0Prev - 100) > ads1115.readADC_SingleEnded(0)) {
        publishAI1();
      }

      if ((adc1Prev + 100) < ads1115.readADC_SingleEnded(1) || (adc1Prev - 100) > ads1115.readADC_SingleEnded(1)) {
        publishAI2();
      }

      if (pcfr0Prev != int(pcfr.digitalRead(0))) {
        publishDI1();
      }

      if (pcfr1Prev != int(pcfr.digitalRead(1))) {
        publishDI2();
      }
    }

    currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      publishAll();
    }

    if (clear) {
      currentMillis2 = millis();
    }

    if (currentMillis2 - previousMillis2 >= interval2) {
      M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
      previousMillis2 = currentMillis2;
      clear = false;
    }

    currentMillis4 = millis();
    if (currentMillis4 - previousMillis4 >= interval4) {
      cycleComponentValues();
      previousMillis4 = currentMillis4;
    }
  }

  onRightPress();
  onRightRelease();
  onLeftPress();
  onLeftRelease();
  onCenterPress();
  onCenterRelease();

  /*
  //TEST PCF8574 DIGITAL IO FUNCTIONALITY
  int pcfr0Test = int(pcfr.digitalRead(0));
  int pcfr1Test = int(pcfr.digitalRead(1));

  pcfw1.digitalWrite(0, !bool(pcfr0Test));
  pcfw1.digitalWrite(1, !bool(pcfr1Test));

  pcfw2.digitalWrite(0, !bool(pcfr0Test));
  //pcfw2.digitalWrite(1, !bool(pcfr1Test));
  */
  
  /*
  //TEST ADS1115 ADC AND AD5665R DAC SCALABILITY
  int testadc0 = ads1115.readADC_SingleEnded(0);
  int testadc1 = ads1115.readADC_SingleEnded(1);

  M5.Lcd.drawString(String(testadc0 * 2), 0, 180, 1);
  M5.Lcd.drawString(String(testadc1 * 2), 0, 210, 1);

  Wire.beginTransmission(0x1f);
  Wire.write(byte(0));
  Wire.write(byte(int(testadc0 * 2) >> 8));
  Wire.write(byte(int(testadc0 * 2)));
  Wire.endTransmission();

  Wire.beginTransmission(0x1f);
  Wire.write(byte(1));
  Wire.write(byte(int(testadc1 * 2) >> 8));
  Wire.write(byte(int(testadc1 * 2)));
  Wire.endTransmission();
  */
  
}
