#include <SSLClient.h>
#include "certificates.h" // This file must be regenerated
#include <ArduinoMqttClient.h>
#include <M5Core2.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <Adafruit_MCP4728.h>
#include <Adafruit_PCF8574.h>

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

EthernetClient ethClient;
SSLClient ethClientSSL(ethClient, TAs, (size_t)TAs_NUM, G36);
MqttClient mqttClient(ethClientSSL);

String payload;
bool retained = false;
int qos = 0;
bool duplicateMqttMessage = false;

Adafruit_ADS1115 ads1115;
int16_t adc0, adc1, adc2, adc3;

Adafruit_MCP4728 mcp;

Adafruit_PCF8574 pcfr;
int pcfr0Prev = 0;
int pcfr1Prev = 0;

Adafruit_PCF8574 pcfw1;
Adafruit_PCF8574 pcfw2;

bool reconnect = false;

void publishDI1() {
  pcfr0Prev = int(pcfr.digitalRead(0));
  payload = String(pcfr0Prev);

  mqttClient.beginMessage(di1_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishDI2() {
  pcfr1Prev = int(pcfr.digitalRead(1));
  payload = String(pcfr1Prev);

  mqttClient.beginMessage(di2_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);  
}

void reconnectMqtt() {
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

  Ethernet.init(26);
  Ethernet.begin(mac);

  //ADS1115 ADC
  ads1115.begin(0x48);
  ads1115.setGain(GAIN_ONE);
  adc0 = ads1115.readADC_SingleEnded(0);
  adc1 = ads1115.readADC_SingleEnded(1);

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
