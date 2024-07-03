/*
OFFICIAL RCI DEVICE PROGRAM
This is the Arduino Program for my Project called "RCI Device." RCI stands for Remote Controlled Input.
The main functionality of this device revolves around receiving input data from a variety of sensors
and publishing that information to an MQTT Broker. A second RCI Device will subscribe to those input
topics and adjust its output ports accordingly. This process will continue to work back and forth between
the two RCI Devices for as long as they have power. These devices are designed to be separated by long distances
and connected to the Internet through Ethernet ports. An example of a use case is having one RCI Device in a basement to measure
temperature and another RCI Device upstairs connected to the house thermostat. The RCI Device in the basement publishes
temperature data to the MQTT Broker, and the RCI Device upstairs subscribes to the temperature data topic. When the temperature
in the basement gets too low, the RCI Device upstairs will output to the thermostat to increase the temperature in the house.
The RCI Device has a maximum capacity of 8 ports for each type of input and output (Digital and Analog) for a total of 32 possible
channels. The Arduino Program runs on an M5Stack Core2 module with an ESP32 microchip.
*/

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

//### Feeds ###

String di1_feed = String("/0001/01/di1");

String di2_feed = String("/0001/01/di2");

String di3_feed = String("/0001/01/di3");

String di4_feed = String("/0001/01/di4");

String di5_feed = String("/0001/01/di5");

String di6_feed = String("/0001/01/di6");

String di7_feed = String("/0001/01/di7");

String di8_feed = String("/0001/01/di8");

String ai1_feed = String("/0001/01/ai1");

String ai2_feed = String("/0001/01/ai2");

String ai3_feed = String("/0001/01/ai3");

String ai4_feed = String("/0001/01/ai4");

String ai5_feed = String("/0001/01/ai5");

String ai6_feed = String("/0001/01/ai6");

String ai7_feed = String("/0001/01/ai7");

String ai8_feed = String("/0001/01/ai8");

String do1_feed = String("/0001/02/di1");

String do2_feed = String("/0001/02/di2");

String do3_feed = String("/0001/02/di3");

String do4_feed = String("/0001/02/di4");

String do5_feed = String("/0001/02/di5");

String do6_feed = String("/0001/02/di6");

String do7_feed = String("/0001/02/di7");

String do8_feed = String("/0001/02/di8");

String ao1_feed = String("/0001/02/ai1");

String ao2_feed = String("/0001/02/ai2");

String ao3_feed = String("/0001/02/ai3");

String ao4_feed = String("/0001/02/ai4");

String ao5_feed = String("/0001/02/ai5");

String ao6_feed = String("/0001/02/ai6");

String ao7_feed = String("/0001/02/ai7");

String ao8_feed = String("/0001/02/ai8");

/*
String di1_feed = String("");

String di2_feed = String("");

String do1_feed = String("");

String do2_feed = String("");

String ai1_feed = String("");

String ai2_feed = String("");

String ao1_feed = String("");

String ao2_feed = String("");
*/

String ds0, ds1, ds2, ds3, ds4, ds5, ds6, ds7;
String * di_feeds[8];
String as0, as1, as2, as3, as4, as5, as6, as7;
String * ai_feeds[8];

//#INITIAL VARIABLES
String di1_value = String("0");
String di2_value = String("0");
String di3_value = String("0");
String di4_value = String("0");
String di5_value = String("0");
String di6_value = String("0");
String di7_value = String("0");
String di8_value = String("0");

String do1_value = String("0");
String do2_value = String("0");
String do3_value = String("0");
String do4_value = String("0");
String do5_value = String("0");
String do6_value = String("0");
String do7_value = String("0");
String do8_value = String("0");

String ai1_value = String("0");
String ai2_value = String("0");
String ai3_value = String("0");
String ai4_value = String("0");
String ai5_value = String("0");
String ai6_value = String("0");
String ai7_value = String("0");
String ai8_value = String("0");

String ao1_value = String("0");
String ao2_value = String("0");
String ao3_value = String("0");
String ao4_value = String("0");
String ao5_value = String("0");
String ao6_value = String("0");
String ao7_value = String("0");
String ao8_value = String("0");

unsigned int cycleCounter = 0;

const long interval = 3600000;
const long interval2 = 2000;
const long interval3 = 1800000;
const long interval4 = 5000;
const long interval5 = 5000;
const long interval6 = 5000;
const long interval7 = 1800000;
const long interval8 = 5000;
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;
unsigned long previousMillis5 = 0;
unsigned long previousMillis6 = 0;
unsigned long previousMillis7 = 0;
unsigned long previousMillis8 = 0;
unsigned long currentMillis = 0;
unsigned long currentMillis2 = 0;
unsigned long currentMillis3 = 0;
unsigned long currentMillis4 = 0;
unsigned long currentMillis5 = 0;
unsigned long currentMillis6 = 0;
unsigned long currentMillis7 = 0;
unsigned long currentMillis8 = 0;

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
bool firstConfigAo1Press = true;
int configAo1Counter = 0;
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

Adafruit_ADS1115 ads1115, ads1115second;
int16_t adc0, adc1, adc2, adc3, adc0second, adc1second, adc2second, adc3second;

Adafruit_MCP4728 mcp;

Adafruit_PCF8574 pcfr;

Adafruit_PCF8574 pcfw1;
Adafruit_PCF8574 pcfw2;

int16_t adc0Prev = 0;
int16_t adc1Prev = 0;
int16_t adc2Prev = 0;
int16_t adc3Prev = 0;
int16_t adc0secondPrev = 0;
int16_t adc1secondPrev = 0;
int16_t adc2secondPrev = 0;
int16_t adc3secondPrev = 0;

int pcfr0Prev = 0;
int pcfr1Prev = 0;
int pcfr2Prev = 0;
int pcfr3Prev = 0;
int pcfr4Prev = 0;
int pcfr5Prev = 0;
int pcfr6Prev = 0;
int pcfr7Prev = 0;

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
    if (di1_value.toInt() == 0) {
      M5.Lcd.drawString("1: OFF", 0, 40, 1);
    }
    if (di1_value.toInt() == 1) {
      M5.Lcd.drawString("1: ON", 0, 40, 1);
    }
    
    if (di2_value.toInt() == 0) {
      M5.Lcd.drawString("2: OFF", 0, 80, 1);
    }
    if (di2_value.toInt() == 1) {
      M5.Lcd.drawString("2: ON", 0, 80, 1);
    }
    
    if (di3_value.toInt() == 0) {
      M5.Lcd.drawString("3: OFF", 0, 120, 1);
    }
    if (di3_value.toInt() == 1) {
      M5.Lcd.drawString("3: ON", 0, 120, 1);
    }
    
    if (di4_value.toInt() == 0) {
      M5.Lcd.drawString("4: OFF", 0, 160, 1);
    }
    if (di4_value.toInt() == 1) {
      M5.Lcd.drawString("4: ON", 0, 160, 1);
    }
    
    if (di5_value.toInt() == 0) {
      M5.Lcd.drawString("5: OFF", 170, 40, 1);
    }
    if (di5_value.toInt() == 1) {
      M5.Lcd.drawString("5: ON", 170, 40, 1);
    }
    
    if (di6_value.toInt() == 0) {
      M5.Lcd.drawString("6: OFF", 170, 80, 1);
    }
    if (di6_value.toInt() == 1) {
      M5.Lcd.drawString("6: ON", 170, 80, 1);
    }

    if (di7_value.toInt() == 0) {
      M5.Lcd.drawString("7: OFF", 170, 120, 1);
    }
    if (di7_value.toInt() == 1) {
      M5.Lcd.drawString("7: ON", 170, 120, 1);
    }
    
    if (di8_value.toInt() == 0) {
      M5.Lcd.drawString("8: OFF", 170, 160, 1);
    }
    if (di8_value.toInt() == 1) {
      M5.Lcd.drawString("8: ON", 170, 160, 1);
    }
    
    M5.Lcd.drawString("CFG", 240, 210, 1);
  }
  if (cycleCounter == 1) {
    M5.Lcd.drawString("Digital Outputs", 30, 0, 1);
    if (do1_value.toInt() == 0) {
      M5.Lcd.drawString("1: OFF", 0, 40, 1);
    }
    if (do1_value.toInt() == 1) {
      M5.Lcd.drawString("1: ON", 0, 40, 1);
    }
    
    if (do2_value.toInt() == 0) {
      M5.Lcd.drawString("2: OFF", 0, 80, 1);
    }
    if (do2_value.toInt() == 1) {
      M5.Lcd.drawString("2: ON", 0, 80, 1);
    }
    
    if (do3_value.toInt() == 0) {
      M5.Lcd.drawString("3: OFF", 0, 120, 1);
    }
    if (do3_value.toInt() == 1) {
      M5.Lcd.drawString("3: ON", 0, 120, 1);
    }
    
    if (do4_value.toInt() == 0) {
      M5.Lcd.drawString("4: OFF", 0, 160, 1);
    }
    if (do4_value.toInt() == 1) {
      M5.Lcd.drawString("4: ON", 0, 160, 1);
    }
    
    if (do5_value.toInt() == 0) {
      M5.Lcd.drawString("5: OFF", 170, 40, 1);
    }
    if (do5_value.toInt() == 1) {
      M5.Lcd.drawString("5: ON", 170, 40, 1);
    }
    
    if (do6_value.toInt() == 0) {
      M5.Lcd.drawString("6: OFF", 170, 80, 1);
    }
    if (do6_value.toInt() == 1) {
      M5.Lcd.drawString("6: ON", 170, 80, 1);
    }
   
    if (do7_value.toInt() == 0) {
      M5.Lcd.drawString("7: OFF", 170, 120, 1);
    }
    if (do7_value.toInt() == 1) {
      M5.Lcd.drawString("7: ON", 170, 120, 1);
    }
   
    if (do8_value.toInt() == 0) {
      M5.Lcd.drawString("8: OFF", 170, 160, 1);
    }
    if (do8_value.toInt() == 1) {
      M5.Lcd.drawString("8: ON", 170, 160, 1);
    }
    
    M5.Lcd.drawString("CFG", 240, 210, 1);   
  }
  if (cycleCounter == 2) {
    M5.Lcd.drawString("Analog Inputs", 40, 0, 1);
    M5.Lcd.drawString("1: " + String(ai1_value.toFloat() / 1600.00, 2), 0, 40, 1);
    M5.Lcd.drawString("2: " + String(ai2_value.toFloat() / 1600.00, 2), 0, 80, 1);
    M5.Lcd.drawString("3: " + String(ai3_value.toFloat() / 1600.00, 2), 0, 120, 1);
    M5.Lcd.drawString("4: " + String(ai4_value.toFloat() / 1600.00, 2), 0, 160, 1);
    M5.Lcd.drawString("5: " + String(ai5_value.toFloat() / 1600.00, 2), 170, 40, 1);
    M5.Lcd.drawString("6: " + String(ai6_value.toFloat() / 1600.00, 2), 170, 80, 1);
    M5.Lcd.drawString("7: " + String(ai7_value.toFloat() / 1600.00, 2), 170, 120, 1);
    M5.Lcd.drawString("8: " + String(ai8_value.toFloat() / 1600.00, 2), 170, 160, 1);
    M5.Lcd.drawString("CFG", 240, 210, 1);
  }
  if (cycleCounter == 3) {
    M5.Lcd.drawString("Analog Outputs", 40, 0, 1);
    M5.Lcd.drawString("1: " + String(ao1_value.toFloat() / 3276.75, 2), 0, 40, 1);
    M5.Lcd.drawString("2: " + String(ao2_value.toFloat() / 3276.75, 2), 0, 80, 1);
    M5.Lcd.drawString("3: " + String(ao3_value.toFloat() / 3276.75, 2), 0, 120, 1);
    M5.Lcd.drawString("4: " + String(ao4_value.toFloat() / 3276.75, 2), 0, 160, 1);
    M5.Lcd.drawString("5: " + String(ao5_value.toFloat() / 3276.75, 2), 170, 40, 1);
    M5.Lcd.drawString("6: " + String(ao6_value.toFloat() / 3276.75, 2), 170, 80, 1);
    M5.Lcd.drawString("7: " + String(ao7_value.toFloat() / 3276.75, 2), 170, 120, 1);
    M5.Lcd.drawString("8: " + String(ao8_value.toFloat() / 3276.75, 2), 170, 160, 1);
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

      if (firstConfigAo1Press) {
        firstConfigAo1Press = false;
      } else {
        configAo1Counter++;
        if (configAo1Counter > 5) {
          configAo1Counter = 0;
        }
      }

      if (configAo1Counter == 0) {
        configAo1Value = 0;
      }

      if (configAo1Counter == 1) {
        configAo1Value = 13107;
      }

      if (configAo1Counter == 2) {
        configAo1Value = 13107 * 2;
      }

      if (configAo1Counter == 3) {
        configAo1Value = 13107 * 3;
      }

      if (configAo1Counter == 4) {
        configAo1Value = 13107 * 4;
      }

      if (configAo1Counter == 5) {
        configAo1Value = 13107 * 5;
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((configAo1Value) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);

      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(0));
      Wire.write(byte(int(configAo1Value) >> 8));
      Wire.write(byte(int(configAo1Value)));
      Wire.endTransmission();
      

      replaceText(10, 80, 300, 30, 1, String(configAo1Value));
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

      if (firstConfigAo1Press) {
        firstConfigAo1Press = false;
      } else {
        configAo1Counter--;
        if (configAo1Counter < 0) {
          configAo1Counter = 5;
        }
      }

      if (configAo1Counter == 0) {
        configAo1Value = 0;
      }

      if (configAo1Counter == 1) {
        configAo1Value = 13107;
      }

      if (configAo1Counter == 2) {
        configAo1Value = 13107 * 2;
      }

      if (configAo1Counter == 3) {
        configAo1Value = 13107 * 3;
      }

      if (configAo1Counter == 4) {
        configAo1Value = 13107 * 4;
      }

      if (configAo1Counter == 5) {
        configAo1Value = 13107 * 5;
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((configAo1Value) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);

      Wire.beginTransmission(0x1f);
      Wire.write(byte(0));
      Wire.write(byte(int(configAo1Value) >> 8));
      Wire.write(byte(int(configAo1Value)));
      Wire.endTransmission();

      replaceText(10, 80, 300, 30, 1, String(configAo1Value));
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
      firstConfigAo1Press = true;
      configAo1Counter = 0;
      configAo1Value = 0;
      configAo2Value = 0;

      //mcp.setChannelValue(MCP4728_CHANNEL_A, (ai1_value.toInt() * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                  MCP4728_GAIN_2X);
      //mcp.setChannelValue(MCP4728_CHANNEL_B, (ai2_value.toInt() * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                  MCP4728_GAIN_2X);

      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(0));
      Wire.write(byte(ao1_value.toInt() >> 8));
      Wire.write(byte(ao1_value.toInt()));
      Wire.endTransmission();

      Wire.beginTransmission(0x1f);
      Wire.write(byte(1));
      Wire.write(byte(ao2_value.toInt() >> 8));
      Wire.write(byte(ao2_value.toInt()));
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
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DO1!");
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
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DO2!");
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

void publishDI3() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI3!");
  previousMillis2 = millis();
  clear = true;

  pcfr2Prev = int(pcfr.digitalRead(2));
  payload = String(pcfr2Prev);
  di3_value = payload;

  mqttClient.beginMessage(di3_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishDI4() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI4!");
  previousMillis2 = millis();
  clear = true;

  pcfr3Prev = int(pcfr.digitalRead(3));
  payload = String(pcfr3Prev);
  di4_value = payload;

  mqttClient.beginMessage(di4_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);  
}

void publishDI5() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI5!");
  previousMillis2 = millis();
  clear = true;

  pcfr4Prev = int(pcfr.digitalRead(4));
  payload = String(pcfr4Prev);
  di5_value = payload;

  mqttClient.beginMessage(di5_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishDI6() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI6!");
  previousMillis2 = millis();
  clear = true;

  pcfr5Prev = int(pcfr.digitalRead(5));
  payload = String(pcfr5Prev);
  di6_value = payload;

  mqttClient.beginMessage(di6_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);  
}

void publishDI7() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI7!");
  previousMillis2 = millis();
  clear = true;

  pcfr6Prev = int(pcfr.digitalRead(6));
  payload = String(pcfr6Prev);
  di7_value = payload;

  mqttClient.beginMessage(di7_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishDI8() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI8!");
  previousMillis2 = millis();
  clear = true;

  pcfr7Prev = int(pcfr.digitalRead(7));
  payload = String(pcfr7Prev);
  di8_value = payload;

  mqttClient.beginMessage(di8_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);  
}

void publishAI1() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO1!", 10, 200, 1);
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
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO2!", 10, 200, 1);
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

void publishAI3() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI3");
  previousMillis2 = millis();
  clear = true;

  adc2 = ads1115.readADC_SingleEnded(2);
  adc2Prev = adc2;
  payload = String(adc2);
  ai3_value = payload;

  mqttClient.beginMessage(ai3_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAI4() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI4!");
  previousMillis2 = millis();
  clear = true;

  adc3 = ads1115.readADC_SingleEnded(3);
  adc3Prev = adc3;
  payload = String(adc3);
  ai4_value = payload;

  mqttClient.beginMessage(ai4_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAI5() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI5");
  previousMillis2 = millis();
  clear = true;

  adc0second = ads1115second.readADC_SingleEnded(0);
  adc0secondPrev = adc0second;
  payload = String(adc0second);
  ai5_value = payload;

  mqttClient.beginMessage(ai5_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAI6() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI6!");
  previousMillis2 = millis();
  clear = true;

  adc1second = ads1115second.readADC_SingleEnded(1);
  adc1secondPrev = adc1second;
  payload = String(adc1second);
  ai6_value = payload;

  mqttClient.beginMessage(ai6_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAI7() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI7");
  previousMillis2 = millis();
  clear = true;

  adc2second = ads1115second.readADC_SingleEnded(2);
  adc2secondPrev = adc2second;
  payload = String(adc2second);
  ai7_value = payload;

  mqttClient.beginMessage(ai7_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAI8() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI8!");
  previousMillis2 = millis();
  clear = true;

  adc3second = ads1115second.readADC_SingleEnded(3);
  adc3secondPrev = adc3second;
  payload = String(adc3second);
  ai8_value = payload;

  mqttClient.beginMessage(ai8_feed, payload.length(), retained, qos, duplicateMqttMessage);
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

  publishDI3();

  publishDI4();

  publishDI5();

  publishDI6();

  publishDI7();

  publishDI8();

  publishAI1();

  publishAI2();
  
  publishAI3();

  publishAI4();
  
  publishAI5();

  publishAI6();
  
  publishAI7();

  publishAI8();

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

  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("di1")) {
    pcfw1.digitalWrite(0, !bool(message.toInt()));
    do1_value = message;
    //M5.Lcd.fillRect(90, 0, 300, 50, BLACK);
    //M5.Lcd.drawString(di1_value, 90, 0, 2);
    //replaceText(90, 0, 300, 50, 2 di1_value);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("di2")) {
    pcfw1.digitalWrite(1, !bool(message.toInt()));
    do2_value = message;
    //M5.Lcd.fillRect(90, 40, 300, 50, BLACK);
    //M5.Lcd.drawString(di2_value, 90, 40, 2);
    //replaceText(90, 40, 300, 50, 2 di2_value);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("di3")) {
    pcfw1.digitalWrite(2, !bool(message.toInt()));
    do3_value = message;
    //M5.Lcd.fillRect(90, 0, 300, 50, BLACK);
    //M5.Lcd.drawString(di1_value, 90, 0, 2);
    //replaceText(90, 0, 300, 50, 2 di1_value);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("di4")) {
    pcfw1.digitalWrite(3, !bool(message.toInt()));
    do4_value = message;
    //M5.Lcd.fillRect(90, 40, 300, 50, BLACK);
    //M5.Lcd.drawString(di2_value, 90, 40, 2);
    //replaceText(90, 40, 300, 50, 2 di2_value);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("di5")) {
    pcfw1.digitalWrite(4, !bool(message.toInt()));
    do5_value = message;
    //M5.Lcd.fillRect(90, 0, 300, 50, BLACK);
    //M5.Lcd.drawString(di1_value, 90, 0, 2);
    //replaceText(90, 0, 300, 50, 2 di1_value);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("di6")) {
    pcfw1.digitalWrite(5, !bool(message.toInt()));
    do6_value = message;
    //M5.Lcd.fillRect(90, 40, 300, 50, BLACK);
    //M5.Lcd.drawString(di2_value, 90, 40, 2);
    //replaceText(90, 40, 300, 50, 2 di2_value);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("di7")) {
    pcfw1.digitalWrite(6, !bool(message.toInt()));
    do7_value = message;
    //M5.Lcd.fillRect(90, 0, 300, 50, BLACK);
    //M5.Lcd.drawString(di1_value, 90, 0, 2);
    //replaceText(90, 0, 300, 50, 2 di1_value);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("di8")) {
    pcfw1.digitalWrite(7, !bool(message.toInt()));
    do8_value = message;
    //M5.Lcd.fillRect(90, 40, 300, 50, BLACK);
    //M5.Lcd.drawString(di2_value, 90, 40, 2);
    //replaceText(90, 40, 300, 50, 2 di2_value);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ai1")) {
    if ((message.toInt()) < 0) {
      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
      

      //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao1_value = "0";

      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(0));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
      

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao1_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ai2")) {
    if ((message.toInt()) < 0) {
      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(1));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
      
      
      //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao2_value = "0";

      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(1));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
      

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao2_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ai3")) {
    if ((message.toInt()) < 0) {
      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(2));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
      

      //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao3_value = "0";

      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(2));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
      

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao3_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ai4")) {
    if ((message.toInt()) < 0) {
      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(3));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
      
      
      //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao4_value = "0";

      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      Wire.beginTransmission(0x1f);
      Wire.write(byte(3));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
      

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao4_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ai5")) {
    if ((message.toInt()) < 0) {
      
      Wire.beginTransmission(0x1c);
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
      

      //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao5_value = "0";

      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      Wire.beginTransmission(0x1c);
      Wire.write(byte(0));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
      

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao5_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ai6")) {
    if ((message.toInt()) < 0) {
      
      Wire.beginTransmission(0x1c);
      Wire.write(byte(1));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
      
      
      //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao6_value = "0";

      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      Wire.beginTransmission(0x1c);
      Wire.write(byte(1));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
      

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao6_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ai7")) {
    if ((message.toInt()) < 0) {
      
      Wire.beginTransmission(0x1c);
      Wire.write(byte(2));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
      

      //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao7_value = "0";

      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      Wire.beginTransmission(0x1c);
      Wire.write(byte(2));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
      

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao7_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ai8")) {
    if ((message.toInt()) < 0) {
      
      Wire.beginTransmission(0x1c);
      Wire.write(byte(3));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
      
      
      //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao8_value = "0";

      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      Wire.beginTransmission(0x1c);
      Wire.write(byte(3));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
      

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao8_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
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

void analyzeSDCardContents() {
  bool state = false;
  int rawCh = 0;
  char ch = 'n';
  String topic = String("");
  while (!state) {
    rawCh = myFile.read();
    if (rawCh == 59) {
      state = true;
    }
    else {
      ch = char(rawCh);
      topic += ch;
    }
  }
  if (topic.indexOf('-') != -1) {
    serialNumber = topic;
  }
  if (topic.indexOf(':') != -1) {
    stringMac = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("GID")) {
    groupID = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("UID")) {
    unitID = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ION")) {
    IONum = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("UPT")) {
    updateTime = topic;
  }
  if (topic.substring(topic.length() - 2, topic.length()).equalsIgnoreCase("CN")) {
    consumerName = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI1")) {
    di1_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI2")) {
    di2_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI3")) {
    di3_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI4")) {
    di4_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI5")) {
    di5_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI6")) {
    di6_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI7")) {
    di7_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI8")) {
    di8_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI1")) {
    ai1_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI2")) {
    ai2_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI3")) {
    ai3_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI4")) {
    ai4_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI5")) {
    ai5_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI6")) {
    ai6_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI7")) {
    ai7_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI8")) {
    ai8_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO1")) {
    do1_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO2")) {
    do2_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO3")) {
    do3_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO4")) {
    do4_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO5")) {
    do5_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO6")) {
    do6_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO7")) {
    do7_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO8")) {
    do8_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO1")) {
    ao1_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO2")) {
    ao2_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO3")) {
    ao3_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO4")) {
    ao4_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO5")) {
    ao5_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO6")) {
    ao6_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO7")) {
    ao7_feed = topic;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO8")) {
    ao8_feed = topic;
  }
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

void toggleResetClock() {
  digitalWrite(25, HIGH); // sets the digital pin 25 on
  delay(50);
  digitalWrite(25, LOW);  // sets the digital pin 25 off
  delay(50);
}

/* After M5Core2 is started or reset, the program in the setup() function will be executed, and this part will only be executed once. */
void setup() {
  pinMode(25, OUTPUT);
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

  if (SD.exists("/config.txt") == 1) {
    //INITIAL CONFIGURATION CONNECTION
    myFile = SD.open("/config.txt");
    if (myFile.available() < 1) {
      myFile.close();
      configConnect();
      while (!hasConfigInfo) {
        currentMillis7 = millis();
        if (currentMillis7 - previousMillis7 >= interval7) {
          configClient.stop();
          delay(5000);
        }

        while (!configClient.connected()) {
          if (!reconnect) {
            M5.Lcd.clear();
            M5.Lcd.setCursor(0, 0);
          }
          configConnect();
        }

        currentMillis8 = millis();
        if (currentMillis8 - previousMillis8 >= interval8) {
          previousMillis8 = currentMillis8;
          //client.loop();
          configClient.poll();
        }
        
        if (ioKnown) {
          int subscribeQos = 0;
          for (int i = 1; i <= IONum.toInt(); i++) {
            String di_feed = groupID + "_" + unitID + "_DI" + i;
            *di_feeds[i - 1] = di_feed;
            String ai_feed = groupID + "_" + unitID + "_AI" + i;
            *ai_feeds[i - 1] = ai_feed;
            String doTopic = serialNumber + "_DO" + i;
            String aoTopic = serialNumber + "_AO" + i;
            configClient.subscribe(doTopic, subscribeQos);
            configClient.subscribe(aoTopic, subscribeQos);
          }
          ioKnown = false;
        }
      }
      //configClient.disconnect();
      configClient.stop();
      myFile = SD.open("/config.txt", FILE_WRITE);
      myFile.print(groupID + "_GID;" + unitID + "_UID;" + IONum + "_ION;" + updateTime + "_UPT;" + consumerName + "_CN;" +
      *di_feeds[0] + ";" + *di_feeds[1] + ";" + *di_feeds[2] + ";" + *di_feeds[3] + ";" + *di_feeds[4] + ";" + *di_feeds[5] + ";" + *di_feeds[6] + ";" + *di_feeds[7] + ";" +
      *ai_feeds[0] + ";" + *ai_feeds[1] + ";" + *ai_feeds[2] + ";" + *ai_feeds[3] + ";" + *ai_feeds[4] + ";" + *ai_feeds[5] + ";" + *ai_feeds[6] + ";" + *ai_feeds[7] + ";" +
      do1_feed + ";" + do2_feed + ";" + do3_feed + ";" + do4_feed + ";" + do5_feed + ";" + do6_feed + ";" + do7_feed + ";" + do8_feed + ";" +
      ao1_feed + ";" + ao2_feed + ";" + ao3_feed + ";" + ao4_feed + ";" + ao5_feed + ";" + ao6_feed + ";" + ao7_feed + ";" + ao8_feed + ";");
      myFile.close();
      //ESP.restart();
    } else {
      myFile.close();
    }

    //GET MQTT TOPICS FROM SD CARD
    myFile = SD.open("/config.txt");
    while (myFile.available()) {
      analyzeSDCardContents();
    }
    myFile.close();
  }

  //ADS1115 ADC
  ads1115.begin(0x48);
  ads1115.setGain(GAIN_ONE);
  adc0 = ads1115.readADC_SingleEnded(0);
  adc1 = ads1115.readADC_SingleEnded(1);
  adc2 = ads1115.readADC_SingleEnded(2);
  adc3 = ads1115.readADC_SingleEnded(3);
  //M5.Lcd.print("ADC OK\n");

  
  ads1115second.begin(0x49);
  ads1115second.setGain(GAIN_ONE);
  adc0second = ads1115second.readADC_SingleEnded(0);
  adc1second = ads1115second.readADC_SingleEnded(1);
  adc2second = ads1115second.readADC_SingleEnded(2);
  adc3second = ads1115second.readADC_SingleEnded(3);

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

  
  Wire.beginTransmission(0x1c);
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
  //M5.Lcd.print("DAC OK\n");

  
  Wire.beginTransmission(0x1c);
  Wire.write(byte(7));
  Wire.write(byte(0));
  Wire.write(byte(0));
  Wire.endTransmission();

  /*
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
  */
  
  pcfr.begin(0x38, &Wire);
  pcfr.pinMode(0, INPUT_PULLUP);
  pcfr.pinMode(1, INPUT_PULLUP);
  pcfr.pinMode(2, INPUT_PULLUP);
  pcfr.pinMode(3, INPUT_PULLUP);
  pcfr.pinMode(4, INPUT_PULLUP);
  pcfr.pinMode(5, INPUT_PULLUP);
  pcfr.pinMode(6, INPUT_PULLUP);
  pcfr.pinMode(7, INPUT_PULLUP);
  pcfr.digitalWrite(0, true);
  pcfr.digitalWrite(1, true);
  pcfr.digitalWrite(2, true);
  pcfr.digitalWrite(3, true);
  pcfr.digitalWrite(4, true);
  pcfr.digitalWrite(5, true);
  pcfr.digitalWrite(6, true);
  pcfr.digitalWrite(7, true);

  //pcfr0Prev = int(pcfr.digitalRead(0));
  //pcfr1Prev = int(pcfr.digitalRead(1));

  //M5.Lcd.drawString(String(pcfr0Prev), 0, 60, 1);
  //M5.Lcd.drawString(String(pcfr1Prev), 0, 90, 1);

  pcfw1.begin(0x39, &Wire);
  pcfw1.pinMode(0, OUTPUT);
  pcfw1.pinMode(1, OUTPUT);
  pcfw1.pinMode(2, OUTPUT);
  pcfw1.pinMode(3, OUTPUT);
  pcfw1.pinMode(4, OUTPUT);
  pcfw1.pinMode(5, OUTPUT);
  pcfw1.pinMode(6, OUTPUT);
  pcfw1.pinMode(7, OUTPUT);
  pcfw1.digitalWrite(0, true);
  pcfw1.digitalWrite(1, true);
  pcfw1.digitalWrite(2, true);
  pcfw1.digitalWrite(3, true);
  pcfw1.digitalWrite(4, true);
  pcfw1.digitalWrite(5, true);
  pcfw1.digitalWrite(6, true);
  pcfw1.digitalWrite(7, true);

  pcfw2.begin(0x3a, &Wire);
  pcfw2.pinMode(0, OUTPUT);
  //pcfw2.pinMode(1, OUTPUT);
  //pcfw2.pinMode(2, OUTPUT);
  //pcfw2.pinMode(3, OUTPUT);
  //pcfw2.pinMode(4, OUTPUT);
  //pcfw2.pinMode(5, OUTPUT);
  //pcfw2.pinMode(6, OUTPUT);
  //pcfw2.pinMode(7, OUTPUT);
  pcfw2.digitalWrite(0, true);
  //pcfw2.digitalWrite(1, true);
  //pcfw2.digitalWrite(2, true);
  //pcfw2.digitalWrite(3, true);
  //pcfw2.digitalWrite(4, true);
  //pcfw2.digitalWrite(5, true);
  //pcfw2.digitalWrite(6, true);
  //pcfw2.digitalWrite(7, true);
  //M5.Lcd.print("PCF OK\n");

  adc0Prev = ads1115.readADC_SingleEnded(0);
  ai1_value = String(adc0Prev);
  if (adc0Prev < 0) {
    ai1_value = "0";
  }

  adc1Prev = ads1115.readADC_SingleEnded(1);
  ai2_value = String(adc1Prev);
  if (adc1Prev < 0) {
    ai2_value = "0";
  }
  
  adc2Prev = ads1115.readADC_SingleEnded(2);
  ai3_value = String(adc2Prev);
  if (adc2Prev < 0) {
    ai3_value = "0";
  }
  
  adc3Prev = ads1115.readADC_SingleEnded(3);
  ai4_value = String(adc3Prev);
  if (adc3Prev < 0) {
    ai4_value = "0";
  }
  
  adc0secondPrev = ads1115second.readADC_SingleEnded(0);
  ai5_value = String(adc0secondPrev);
  if (adc0secondPrev < 0) {
    ai5_value = "0";
  }
  
  adc1secondPrev = ads1115second.readADC_SingleEnded(1);
  ai6_value = String(adc1secondPrev);
  if (adc1secondPrev < 0) {
    ai6_value = "0";
  }
  
  adc2secondPrev = ads1115second.readADC_SingleEnded(2);
  ai7_value = String(adc2secondPrev);
  if (adc2secondPrev < 0) {
    ai7_value = "0";
  }
  
  adc3secondPrev = ads1115second.readADC_SingleEnded(3);
  ai8_value = String(adc3secondPrev);
  if (adc3secondPrev < 0) {
    ai8_value = "0";
  }

  pcfr0Prev = int(pcfr.digitalRead(0));
  di1_value = String(pcfr0Prev);

  pcfr1Prev = int(pcfr.digitalRead(1));
  di2_value = String(pcfr1Prev);

  pcfr2Prev = int(pcfr.digitalRead(2));
  di3_value = String(pcfr2Prev);
 
  pcfr3Prev = int(pcfr.digitalRead(3));
  di4_value = String(pcfr3Prev);
 
  pcfr4Prev = int(pcfr.digitalRead(4));
  di5_value = String(pcfr4Prev);

  pcfr5Prev = int(pcfr.digitalRead(5));
  di6_value = String(pcfr5Prev);

  pcfr6Prev = int(pcfr.digitalRead(6));
  di7_value = String(pcfr6Prev);

  pcfr7Prev = int(pcfr.digitalRead(7));
  di8_value = String(pcfr7Prev);

  /*
  reconnectMqtt();
  publishDI1();
  publishDI2();
  publishDI3();
  publishDI4();
  publishDI5();
  publishDI6();
  publishDI7();
  publishDI8();
  publishAI1();
  publishAI2();
  publishAI3();
  publishAI4();
  publishAI5();
  publishAI6();
  publishAI7();
  publishAI8();
  publishAll();
  */
  
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

      if ((adc2Prev + 100) < ads1115.readADC_SingleEnded(2) || (adc2Prev - 100) > ads1115.readADC_SingleEnded(2)) {
        publishAI3();
      }

      if ((adc3Prev + 100) < ads1115.readADC_SingleEnded(3) || (adc3Prev - 100) > ads1115.readADC_SingleEnded(3)) {
        publishAI4();
      }

      if ((adc0secondPrev + 100) < ads1115second.readADC_SingleEnded(0) || (adc0secondPrev - 100) > ads1115second.readADC_SingleEnded(0)) {
        publishAI5();
      }

      if ((adc1secondPrev + 100) < ads1115second.readADC_SingleEnded(1) || (adc1secondPrev - 100) > ads1115second.readADC_SingleEnded(1)) {
        publishAI6();
      }

      if ((adc2secondPrev + 100) < ads1115second.readADC_SingleEnded(2) || (adc2secondPrev - 100) > ads1115second.readADC_SingleEnded(2)) {
        publishAI7();
      }

      if ((adc3secondPrev + 100) < ads1115second.readADC_SingleEnded(3) || (adc3secondPrev - 100) > ads1115second.readADC_SingleEnded(3)) {
        publishAI8();
      }

      if (pcfr0Prev != int(pcfr.digitalRead(0))) {
        publishDI1();
      }

      if (pcfr1Prev != int(pcfr.digitalRead(1))) {
        publishDI2();
      }

      if (pcfr2Prev != int(pcfr.digitalRead(2))) {
        publishDI3();
      }

      if (pcfr3Prev != int(pcfr.digitalRead(3))) {
        publishDI4();
      }

      if (pcfr4Prev != int(pcfr.digitalRead(4))) {
        publishDI5();
      }

      if (pcfr5Prev != int(pcfr.digitalRead(5))) {
        publishDI6();
      }

      if (pcfr6Prev != int(pcfr.digitalRead(6))) {
        publishDI7();
      }

      if (pcfr7Prev != int(pcfr.digitalRead(7))) {
        publishDI8();
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

  toggleResetClock();

  /*
  if (normalMode) {
    //TEST PCF8574 DIGITAL IO FUNCTIONALITY
    int pcfr0Test = int(pcfr.digitalRead(0));
    int pcfr1Test = int(pcfr.digitalRead(1));
    int pcfr2Test = int(pcfr.digitalRead(2));
    int pcfr3Test = int(pcfr.digitalRead(3));
    int pcfr4Test = int(pcfr.digitalRead(4));
    int pcfr5Test = int(pcfr.digitalRead(5));
    int pcfr6Test = int(pcfr.digitalRead(6));
    int pcfr7Test = int(pcfr.digitalRead(7));

    pcfw1.digitalWrite(0, !bool(pcfr0Test));
    pcfw1.digitalWrite(1, !bool(pcfr1Test));
    pcfw1.digitalWrite(2, !bool(pcfr2Test));
    pcfw1.digitalWrite(3, !bool(pcfr3Test));
    pcfw1.digitalWrite(4, !bool(pcfr4Test));
    pcfw1.digitalWrite(5, !bool(pcfr5Test));
    pcfw1.digitalWrite(6, !bool(pcfr6Test));
    pcfw1.digitalWrite(7, !bool(pcfr7Test));

    pcfw2.digitalWrite(0, !bool(pcfr7Test));
    //pcfw2.digitalWrite(1, !bool(pcfr7Test));


    //TEST ADS1115 ADC AND AD5665R DAC SCALABILITY
    int testadc0 = ads1115.readADC_SingleEnded(0);

    M5.Lcd.drawString(String(testadc0), 0, 210, 1);
    //M5.Lcd.drawString(String(int(testadc0 * 2.048)), 0, 210, 1);
    //M5.Lcd.drawString(String(int(testadc1 * 2.048)), 0, 210, 1);

    testadc0 = int(testadc0 * 2.048);
    if (testadc0 < 0) {
      testadc0 = 0;
    }
    if (testadc0 > 65535) {
      testadc0 = 65535;
    }

    int testadc1 = ads1115.readADC_SingleEnded(1);
    testadc1 = int(testadc1 * 2.048);
    if (testadc1 < 0) {
      testadc1 = 0;
    }
    if (testadc1 > 65535) {
      testadc1 = 65535;
    }

    int testadc2 = ads1115.readADC_SingleEnded(2);
    testadc2 = int(testadc2 * 2.048);
    if (testadc2 < 0) {
      testadc2 = 0;
    }
    if (testadc2 > 65535) {
      testadc2 = 65535;
    }

    int testadc3 = ads1115.readADC_SingleEnded(3);
    testadc3 = int(testadc3 * 2.048);
    if (testadc3 < 0) {
      testadc3 = 0;
    }
    if (testadc3 > 65535) {
      testadc3 = 65535;
    }

    int testadc4 = ads1115second.readADC_SingleEnded(0);
    testadc4 = int(testadc4 * 2.048);
    if (testadc4 < 0) {
      testadc4 = 0;
    }
    if (testadc4 > 65535) {
      testadc4 = 65535;
    }

    int testadc5 = ads1115second.readADC_SingleEnded(1);
    testadc5 = int(testadc5 * 2.048);
    if (testadc5 < 0) {
      testadc5 = 0;
    }
    if (testadc5 > 65535) {
      testadc5 = 65535;
    }

    int testadc6 = ads1115second.readADC_SingleEnded(2);
    testadc6 = int(testadc6 * 2.048);
    if (testadc6 < 0) {
      testadc6 = 0;
    }
    if (testadc6 > 65535) {
      testadc6 = 65535;
    }

    int testadc7 = ads1115second.readADC_SingleEnded(3);
    testadc7 = int(testadc7 * 2.048);
    if (testadc7 < 0) {
      testadc7 = 0;
    }
    if (testadc7 > 65535) {
      testadc7 = 65535;
    }


    Wire.beginTransmission(0x1f);
    Wire.write(byte(0));
    Wire.write(byte(testadc0 >> 8));
    Wire.write(byte(testadc0));
    Wire.endTransmission();
  
    Wire.beginTransmission(0x1f);
    Wire.write(byte(1));
    Wire.write(byte(testadc1 >> 8));
    Wire.write(byte(testadc1));
    Wire.endTransmission();

    Wire.beginTransmission(0x1f);
    Wire.write(byte(2));
    Wire.write(byte(testadc2 >> 8));
    Wire.write(byte(testadc2));
    Wire.endTransmission();
  
    Wire.beginTransmission(0x1f);
    Wire.write(byte(3));
    Wire.write(byte(testadc3 >> 8));
    Wire.write(byte(testadc3));
    Wire.endTransmission();

    Wire.beginTransmission(0x1c);
    Wire.write(byte(0));
    Wire.write(byte(testadc4 >> 8));
    Wire.write(byte(testadc4));
    Wire.endTransmission();
  
    Wire.beginTransmission(0x1c);
    Wire.write(byte(1));
    Wire.write(byte(testadc5 >> 8));
    Wire.write(byte(testadc5));
    Wire.endTransmission();

    Wire.beginTransmission(0x1c);
    Wire.write(byte(2));
    Wire.write(byte(testadc6 >> 8));
    Wire.write(byte(testadc6));
    Wire.endTransmission();
  
    Wire.beginTransmission(0x1c);
    Wire.write(byte(3));
    Wire.write(byte(testadc7 >> 8));
    Wire.write(byte(testadc7));
    Wire.endTransmission();
  }
  */
  
}
