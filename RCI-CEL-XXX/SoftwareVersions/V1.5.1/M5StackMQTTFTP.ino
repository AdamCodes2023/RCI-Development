/*
OFFICIAL RCI DEVICE PROGRAM
This is the Arduino Program for my Project called "RCI Device."
RCI stands for Remote Controlled Input.
The main functionality of this device revolves around receiving input data from a variety of sensors and publishing that information to an MQTT Broker.
A second RCI Device will subscribe to those input topics and adjust its output ports accordingly.
This process will continue to work back and forth between the two RCI Devices for as long as they have power.
These devices are designed to be separated by long distances and connected to the Internet through Ethernet ports.
An example of a use case is having one RCI Device in a basement to measure temperature and another RCI Device upstairs connected to the house thermostat.
The RCI Device in the basement publishes temperature data to the MQTT Broker, and the RCI Device upstairs subscribes to the temperature data topic.
When the temperature in the basement gets too low, the RCI Device upstairs will output to the thermostat to increase the temperature in the house.
The RCI Device has a maximum capacity of 8 ports for each type of input and output (Digital and Analog) for a total of 32 possible channels.
The Arduino Program runs on an M5Stack Core2 module with an ESP32 microchip.
*/

/*
 Basic MQTT example (with SSL!)
 This sketch demonstrates the basic capabilities of the library.
 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic"
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary
 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.

 You will need to populate "certificates.h" with your trust anchors
 (see https://github.com/OPEnSLab-OSU/SSLClient/blob/master/TrustAnchors.md)
 and my_cert/my_key with your certificate/private key pair
 (see https://github.com/OPEnSLab-OSU/SSLClient#mtls).
*/

#include <SSLClient.h>
#include <ArduinoMqttClient.h>
#include <M5Core2.h>
#include <SPI.h>
//#include <Ethernet_Generic.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <Adafruit_MCP4728.h>
#include <Adafruit_PCF8574.h>
//#include <SD.h>
#include <Preferences.h>
#include "Arduino.h"
#include "certificates/certificates.h"  // This file must be regenerated.
#include "defines/defines.h"
#include "sounds/sounds.h"
#include <FTPClient_Generic.h>
#include <TimeLib.h>
#include <Update.h>
#include <ArduinoJson.h>

//byte mac[] = {0x8C, 0x1F, 0x64, 0x81, 0x30, 0x02};
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
//int previousIndex = 0;
//int sectionIndex = -1;

/*
const char broker[]    = "06e8c7b775f1454b8b94fcd788277596.s2.eu.hivemq.cloud";
int        port        = 8883;
*/
String broker = String("");
int  port = -1;
const char willTopic[] = "pribusin/will";

// To use `true` with the following PASV mode asnswer from server, such as `VSFTP`
// 227 Entering Passive Mode (192,168,2,112,157,218)
// Using `false` with old style PASV answer, such as `FTP_Server_Teensy41` library
// 227 Entering Passive Mode (4043483328, port 55600)
#define USING_VSFTP_SERVER      false

#if USING_VSFTP_SERVER

  // Change according to your FTP server
  /*
  char ftp_server[] = "ftp.DriveHQ.com";

  char ftp_user[]   = "AdamPribusin";
  char ftp_pass[]   = "Rp22001227!?";

  char dirName[]    = "/RCIConfig";
  */

  /*
  String ftp_server = String("");
  int ftp_port = -1;

  String ftp_user   = String("");
  String ftp_pass   = String("");

  String dirName    = String("");
  */
  char newDirName[] = "/NewDir";

#else

  // Change according to your FTP server
  /*
  char ftp_server[] = "ftp.DriveHQ.com";

  char ftp_user[]   = "AdamPribusin";
  char ftp_pass[]   = "Rp22001227!?";

  char dirName[]    = "/RCIConfig";
  */

  /*
  String ftp_server = String("");
  int ftp_port = -1;

  String ftp_user   = String("");
  String ftp_pass   = String("");

  String dirName    = String("");
  */
  char newDirName[] = "/NewDir";

#endif

// FTPClient_Generic(char* _serverAdress, uint16_t _port, char* _userName, char* _passWord, uint16_t _timeout = 10000);
FTPClient_Generic* ftp;

String configFileName = "";
String sdConfigFileName = "";

//### Feeds ###
/*
String di1_feed = String("/feeds/di1-2");

String di2_feed = String("/feeds/di2-2");

String do1_feed = String("/feeds/do1-2");

String do2_feed = String("/feeds/do2-2");

String ai1_feed = String("/feeds/ai1-2");

String ai2_feed = String("/feeds/ai2-2");

String ao1_feed = String("/feeds/ao1-2");

String ao2_feed = String("/feeds/ao2-2");
*/

String connected_feed_publish = String("");
String connected_feed_publishACK = String("");

String connected_feed_subscribe = String("");
String connected_feed_subscribeACK = String("");

String config_update_feed = String("");
//String config_update_feedACK = String("");

String internal_update_feed = String("");
//String internal_update_feedACK = String("");

String credential_update_feed = String("");
//String credential_update_feedACK = String("");

String api_update_feed = String("");
//String api_update_feedACK = String("");

String di1_feed = String("");
String di1_feedACK = String("");

String di2_feed = String("");
String di2_feedACK = String("");

String di3_feed = String("");
String di3_feedACK = String("");

String di4_feed = String("");
String di4_feedACK = String("");

String di5_feed = String("");
String di5_feedACK = String("");

String di6_feed = String("");
String di6_feedACK = String("");

String di7_feed = String("");
String di7_feedACK = String("");

String di8_feed = String("");
String di8_feedACK = String("");

String do1_feed = String("");
String do1_feedACK = String("");

String do2_feed = String("");
String do2_feedACK = String("");

String do3_feed = String("");
String do3_feedACK = String("");

String do4_feed = String("");
String do4_feedACK = String("");

String do5_feed = String("");
String do5_feedACK = String("");

String do6_feed = String("");
String do6_feedACK = String("");

String do7_feed = String("");
String do7_feedACK = String("");

String do8_feed = String("");
String do8_feedACK = String("");

String ai1_feed = String("");
String ai1_feedACK = String("");

String ai2_feed = String("");
String ai2_feedACK = String("");

String ai3_feed = String("");
String ai3_feedACK = String("");

String ai4_feed = String("");
String ai4_feedACK = String("");

String ai5_feed = String("");
String ai5_feedACK = String("");

String ai6_feed = String("");
String ai6_feedACK = String("");

String ai7_feed = String("");
String ai7_feedACK = String("");

String ai8_feed = String("");
String ai8_feedACK = String("");

String ao1_feed = String("");
String ao1_feedACK = String("");

String ao2_feed = String("");
String ao2_feedACK = String("");

String ao3_feed = String("");
String ao3_feedACK = String("");

String ao4_feed = String("");
String ao4_feedACK = String("");

String ao5_feed = String("");
String ao5_feedACK = String("");

String ao6_feed = String("");
String ao6_feedACK = String("");

String ao7_feed = String("");
String ao7_feedACK = String("");

String ao8_feed = String("");
String ao8_feedACK = String("");

String heartbeat_feed = String("");

String ds0, ds1, ds2, ds3, ds4, ds5, ds6, ds7;
String * di_feeds[8];
String as0, as1, as2, as3, as4, as5, as6, as7;
String * ai_feeds[8];

String ds0ACK, ds1ACK, ds2ACK, ds3ACK, ds4ACK, ds5ACK, ds6ACK, ds7ACK;
String * di_feedsACK[8];
String as0ACK, as1ACK, as2ACK, as3ACK, as4ACK, as5ACK, as6ACK, as7ACK;
String * ai_feedsACK[8];

String serns, macs, gids, uids, ions, dcs0, dcs1, dcs2, dcs3, dcs4, dcs5, dcs6, dcs7, acs0, acs1, acs2, acs3, acs4, acs5, acs6, acs7, upds, ssis, sqs, cns = String("");
String * configItems[25];

String hc0, hc1, hc2, hc3, hc4, hc5, hc6, hc7, hc8, hc9, hc10, hc11, hc12, hc13, hc14, hc15, hc16, hc17, hc18, hc19;
String * heartbeat_check_feeds[20];

bool publishAllc = false;
bool confUpdateStep1 = false;
bool confUpdateStep2 = false;
bool internalUpdateStep1 = false;
bool internalUpdateStep2 = false;
bool credUpdateStep1 = false;
bool credUpdateStep2 = false;
bool apiUpdateStep1 = false;
bool apiUpdateStep2 = false;
bool confUpdateStep1PubOnce = false;
bool confUpdateStep2PubOnce = false;
bool internalUpdateStep1PubOnce = false;
bool internalUpdateStep2PubOnce = false;
bool credUpdateStep1PubOnce = false;
bool credUpdateStep2PubOnce = false;
bool apiUpdateStep1PubOnce = false;
bool apiUpdateStep2PubOnce = false;

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

int subCount = 0;
int maxHeartbeatChecks = 20;
String analyzedFailValue = String("");
String heartbeatSubscriptionsString = String("");
String heartbeatCheckUnitID = String("");
bool heartbeatCommFail = false;
bool heartbeatCheckAlreadySetFailDefaults[20] = {};

String df1ReadValue = String("");
String df2ReadValue = String("");
String df3ReadValue = String("");
String df4ReadValue = String("");
String df5ReadValue = String("");
String df6ReadValue = String("");
String df7ReadValue = String("");
String df8ReadValue = String("");

String af1ReadValue = String("");
String af2ReadValue = String("");
String af3ReadValue = String("");
String af4ReadValue = String("");
String af5ReadValue = String("");
String af6ReadValue = String("");
String af7ReadValue = String("");
String af8ReadValue = String("");

int do1_fail_default = 0;
int do2_fail_default = 0;
int do3_fail_default = 0;
int do4_fail_default = 0;
int do5_fail_default = 0;
int do6_fail_default = 0;
int do7_fail_default = 0;
int do8_fail_default = 0;

double ao1_fail_default = 0.00;
double ao2_fail_default = 0.00;
double ao3_fail_default = 0.00;
double ao4_fail_default = 0.00;
double ao5_fail_default = 0.00;
double ao6_fail_default = 0.00;
double ao7_fail_default = 0.00;
double ao8_fail_default = 0.00;

bool do1CommFailTriggered = false;
bool do2CommFailTriggered = false;
bool do3CommFailTriggered = false;
bool do4CommFailTriggered = false;
bool do5CommFailTriggered = false;
bool do6CommFailTriggered = false;
bool do7CommFailTriggered = false;
bool do8CommFailTriggered = false;

bool ao1CommFailTriggered = false;
bool ao2CommFailTriggered = false;
bool ao3CommFailTriggered = false;
bool ao4CommFailTriggered = false;
bool ao5CommFailTriggered = false;
bool ao6CommFailTriggered = false;
bool ao7CommFailTriggered = false;
bool ao8CommFailTriggered = false;

String versionNumber = String("V 1.5.1");
String statusString = String("");
String signalQualityString = String("NR");
String signalStrengthString = String("NR");
bool onSignalClientDisconnect = true;
bool receivingSignalQuality = false;
bool signalQualityCheckSuccessful = false;
bool firstSignalQualityCheck = true;

unsigned int cycleCounter = 0;

const long interval = 3600000; //Publish All Time
const long interval2 = 2000; //Replace Text Time
const long interval3 = 1800000; //Reconnect Time
const long interval4 = 5000; //Cycle Component Values Time
long interval5 = 10000; //Check For Subscription Updates Time
long interval6 = 10000; //Check For Publish Updates Time
const long startUpInterval = 5000;
const long timeOutInterval = 180000;
const long commFailInterval = 300000;
const long long getTimeInterval = 86400000;
const long long apiAccessInterval = 3600000;
const long long apiAccessRequestInterval = 30000;
const long long requestSignalQualityInterval = 3600000;
const long long heartbeatPublishInterval = 60000;
const long long heartbeatCheckInterval = 180000;
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;
unsigned long previousMillis5 = 0;
unsigned long previousMillis6 = 0;
unsigned long previousMillis7 = 0;
unsigned long previousMillis8 = 0;
unsigned long startUpPreviousMillis = 0;
unsigned long timeOutPreviousMillis = 0;
unsigned long commFailPreviousMillis = 0;
unsigned long long getTimePreviousMillis = 0;
unsigned long long apiAccessPreviousMillis = 0;
unsigned long long apiAccessRequestPreviousMillis = 0;
unsigned long long requestSignalQualityPreviousMillis = 0;
unsigned long long heartbeatPublishPreviousMillis = 0;
unsigned long long heartbeatCheckPreviousMillis[20] = {};
unsigned long currentMillis = 0;
unsigned long currentMillis2 = 0;
unsigned long currentMillis3 = 0;
unsigned long currentMillis4 = 0;
unsigned long currentMillis5 = 0;
unsigned long currentMillis6 = 0;
unsigned long currentMillis7 = 0;
unsigned long currentMillis8 = 0;
unsigned long startUpCurrentMillis = 0;
unsigned long timeOutCurrentMillis = 0;
unsigned long commFailCurrentMillis = 0;
unsigned long long getTimeCurrentMillis = 0;
unsigned long long apiAccessCurrentMillis = 0;
unsigned long long apiAccessRequestCurrentMillis = 0;
unsigned long long requestSignalQualityCurrentMillis = 0;
unsigned long long heartbeatPublishCurrentMillis = 0;
unsigned long long heartbeatCheckCurrentMillis[20] = {};
bool commFailToggledOnce = true;
bool clear = false;
bool firstTimeGet = true;

int reconnectCount = 0;
bool reconnect = false;
bool reconnectFirstMessageStatus = false;

Button leftRed(0, 240, 106, 40, "left-red");
Button centerRed(106, 240, 106, 40, "center-red");
Button rightRed(212, 240, 106, 40, "right-red");

bool triggerSound = false;
bool normalMode = true;
bool cfgServerMode = false;
bool startUpMode = false;
bool forceUpdate = false;
bool noStartUpConfig = true;
bool initialSDCheck = false;
bool copyMode = false;
bool configMenu1 = false;
bool configMenu2 = false;
bool configMenu3 = false;
bool warningMenu1 = false;
bool warningMenu2 = false;
bool centerPressedOnce = false;
bool leftPressedOnce = false;
bool leftPressedTwice = false;
bool leftPressedThree = false;
bool rightPressedOnce = false;
bool rightPressedTwice = false;
bool rightPressedThree = false;
bool rightPressedFour = false;
int viewConfigItemsIterator = 0;
int configMenu1Iterator = 0;
bool firstConfigAo1Press = true;
int configAo1Counter = 0;
long configAo1Value = 0;
long configAo2Value = 0;

// HANDSHAKE VARIABLES
bool pubConnectedSent = false;
//bool pubConfSent = false;
//bool pubCredSent = false;
//bool pubInternalSent = false;
//bool pubApiSent = false;
bool di1Sent = false;
bool di2Sent = false;
bool di3Sent = false;
bool di4Sent = false;
bool di5Sent = false;
bool di6Sent = false;
bool di7Sent = false;
bool di8Sent = false;
bool ai1Sent = false;
bool ai2Sent = false;
bool ai3Sent = false;
bool ai4Sent = false;
bool ai5Sent = false;
bool ai6Sent = false;
bool ai7Sent = false;
bool ai8Sent = false;

bool pubConnectedRecv = false;
//bool pubConfRecv = false;
//bool pubCredRecv = false;
//bool pubInternalRecv = false;
//bool pubApiRecv = false;
bool di1Recv = false;
bool di2Recv = false;
bool di3Recv = false;
bool di4Recv = false;
bool di5Recv = false;
bool di6Recv = false;
bool di7Recv = false;
bool di8Recv = false;
bool ai1Recv = false;
bool ai2Recv = false;
bool ai3Recv = false;
bool ai4Recv = false;
bool ai5Recv = false;
bool ai6Recv = false;
bool ai7Recv = false;
bool ai8Recv = false;

bool subConnectedRecv = false;
//bool subConfRecv = false;
//bool subCredRecv = false;
//bool subInternalRecv = false;
//bool subApiRecv = false;
bool do1Recv = false;
bool do2Recv = false;
bool do3Recv = false;
bool do4Recv = false;
bool do5Recv = false;
bool do6Recv = false;
bool do7Recv = false;
bool do8Recv = false;
bool ao1Recv = false;
bool ao2Recv = false;
bool ao3Recv = false;
bool ao4Recv = false;
bool ao5Recv = false;
bool ao6Recv = false;
bool ao7Recv = false;
bool ao8Recv = false;

int pubConnectedLoopCount = 0;
//int pubConfLoopCount = 0;
//int pubCredLoopCount = 0;
//int pubInternalLoopCount = 0;
//int pubApiLoopCount = 0;
int di1LoopCount = 0;
int di2LoopCount = 0;
int di3LoopCount = 0;
int di4LoopCount = 0;
int di5LoopCount = 0;
int di6LoopCount = 0;
int di7LoopCount = 0;
int di8LoopCount = 0;
int ai1LoopCount = 0;
int ai2LoopCount = 0;
int ai3LoopCount = 0;
int ai4LoopCount = 0;
int ai5LoopCount = 0;
int ai6LoopCount = 0;
int ai7LoopCount = 0;
int ai8LoopCount = 0;

EthernetClient ethSignalClient;
SSLClient signalClient(ethSignalClient, TAs_API, (size_t)TAs_NUM_API, G36);

EthernetClient ethClient;
SSLClient ethClientSSL(ethClient, TAs, (size_t)TAs_NUM, G36);
//SSLClient ethClientSSL(ethClient, nullptr, 0, G36);
//SSLClient ethClientSSL(nullptr);
MqttClient mqttClient(ethClientSSL);
//MqttClient mqttClient(nullptr);

/*
//GLIMPSE API INFORMATION
int    HTTP_PORT   = 8888;
String HTTP_METHOD = "GET"; // or POST
char   HOST_NAME[] = "192.168.1.90";
String PATH_NAME   = "/api/v1";
*/

//SUMMIT API INFORMATION
int    HTTP_PORT        = 443;  // HTTP = PORT 80 | HTTPS = PORT 443
String HTTP_GET_METHOD  = "GET";
String HTTP_POST_METHOD = "POST";
char   HOST_NAME[] = "api.optconnect.com";
String AUTH_PATH_NAME   = "/summit/beta/accounts/login/app_secret";
String INFO_PATH_NAME   = "/summit/beta/devices/serial/"; //ADD DEVICE SERIAL NUMBER TO END OF PATH
String REFRESH_PATH_NAME = "/summit/beta/devices/refresh/"; //ADD DEVICE SUMMIT ID TO END OF PATH

//OPT CONNECT ACCOUNT INFORMATION
String optAccountID = "";
String optApplicationID = "";
String optSecretID = "";
String optRadioSN = "";

String apiString = "";
String optAPIKey = "";
String optAPIToken = "";
bool apiAccessGranted = false;
bool apiAccessRequestSent = false;

String refreshString = "";
String optSummitID = String("NR");
bool cellModemRefreshSuccessful = false;

unsigned int localUDPPort = 8888;       // local port to listen for UDP packets

const char timeServer[] = "pool.ntp.org"; // pool.ntp.org NTP server
const char timeServer2[] = "time.google.com"; // time.google.com NTP server
const char timeServer3[] = "time.cloudflare.com"; // time.cloudflare.com NTP server
const char timeServer4[] = "time.aws.com"; // time.aws.com NTP server
const char timeServer5[] = "time.nist.gov"; // time.nist.gov NTP server

const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message

byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets

bool udpHasTimePacket = false;

// A UDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

time_t t = 0;
String ntpMonth = String("NA");
String ntpDay = String("NA");
String ntpYear = String("NA");
String dateString = String("");

String payload;
bool retained = false;
int qos = 0;
bool duplicateMqttMessage = false;

Adafruit_ADS1115 ads1115, ads1115second;
int16_t adc0, adc1, adc2, adc3, adc0second, adc1second, adc2second, adc3second;

bool analogInOneSuccess = true;
bool analogInTwoSuccess = true;
bool analogOutOneSuccess = true;
bool analogOutTwoSuccess = true;
bool digitalInputSuccess = true;
bool digitalOutputSuccess = true;
bool digitalDebugSuccess = true;

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

int testadc0 = 0;
int testadc1 = 0;
int testadc2 = 0;
int testadc3 = 0;
int testadc4 = 0;
int testadc5 = 0;
int testadc6 = 0;
int testadc7 = 0;

int pcfr0Test = 0;
int pcfr1Test = 0;
int pcfr2Test = 0;
int pcfr3Test = 0;
int pcfr4Test = 0;
int pcfr5Test = 0;
int pcfr6Test = 0;
int pcfr7Test = 0;

//Adafruit_MCP4728 mcp;

Adafruit_PCF8574 pcfr;
Adafruit_PCF8574 pcfw1;
Adafruit_PCF8574 pcfw2;

const int chipSelect = 4;
File myFile;

Preferences preferences;
const char* pnamespace = "InternalInfo";
const char* serialKey = "SerialNumber";
const char* macKey = "MacAddress";
const char* mqttBrokerKey = "MqttBroker";
const char* mqttUsernameKey = "MqttUsername";
const char* mqttPasswordKey = "MqttPassword";
const char* mqttPortKey = "MqttPort";
const char* ftpBrokerKey = "FtpBroker";
const char* ftpPortKey = "FtpPort";
const char* ftpUsernameKey = "FtpUsername";
const char* ftpPasswordKey = "FtpPassword";
const char* ftpWorkingDirectoryKey = "FtpWorkingDir";
const char* optAccountIDKey = "OptAccID";
const char* optApplicationIDKey = "OptAppID";
const char* optSecretIDKey = "OptSecretID";
const char* optRadioSNKey = "OptRadioSN";
String serialNumber = String("");
String stringMac = String("");
String mqttBroker = String("");
String mqttUsername = String("");
String mqttPassword = String("");
String stringMqttPort = String("");
String ftpBroker = String("");
String stringFtpPort = String("");
String ftpUsername = String("");
String ftpPassword = String("");
String ftpWorkingDirectory = String("");

bool hasConfigInfo = false;
String groupID = String("");
String unitID = String("");
String IONum = String("0");
String updateTime = String("");
String consumerName = String("");
bool ioKnown = false;

bool preCheckSD = false;
String rciTitle = String("");
String errorCode = String("NO ERRORS");
uint8_t cardType;

int pingI2cAddress(byte address)
{
  Wire.beginTransmission(address);
  return Wire.endTransmission();
}

void replaceText(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int textSize, String text) {
  M5.Lcd.fillRect(x, y, width, height, BLACK);
  M5.Lcd.drawString(text, x, y, textSize);
}

void cycleComponentValues() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  if (cellModemRefreshSuccessful && signalQualityCheckSuccessful) {
    displayCellularSignalQuality();
  }

  if (cycleCounter == 0) {
    M5.Lcd.drawString("Digital Inputs", 40, 0, 1);

    if (IONum.toInt() >= 1) {
      if (di1_value.toInt() == 0) {
        M5.Lcd.drawString("1: OFF", 0, 40, 1);
      }
      if (di1_value.toInt() == 1) {
        M5.Lcd.drawString("1: ON", 0, 40, 1);
      }
    }

    if (IONum.toInt() >= 2) {
      if (di2_value.toInt() == 0) {
        M5.Lcd.drawString("2: OFF", 0, 80, 1);
      }
      if (di2_value.toInt() == 1) {
        M5.Lcd.drawString("2: ON", 0, 80, 1);
      }
    }

    if (IONum.toInt() >= 3) {
      if (di3_value.toInt() == 0) {
        M5.Lcd.drawString("3: OFF", 0, 120, 1);
      }
      if (di3_value.toInt() == 1) {
        M5.Lcd.drawString("3: ON", 0, 120, 1);
      }
    }

    if (IONum.toInt() >= 4) {
      if (di4_value.toInt() == 0) {
        M5.Lcd.drawString("4: OFF", 0, 160, 1);
      }
      if (di4_value.toInt() == 1) {
        M5.Lcd.drawString("4: ON", 0, 160, 1);
      }
    }

    if (IONum.toInt() >= 5) {
      if (di5_value.toInt() == 0) {
        M5.Lcd.drawString("5: OFF", 170, 40, 1);
      }
      if (di5_value.toInt() == 1) {
        M5.Lcd.drawString("5: ON", 170, 40, 1);
      }
    }

    if (IONum.toInt() >= 6) {
      if (di6_value.toInt() == 0) {
        M5.Lcd.drawString("6: OFF", 170, 80, 1);
      }
      if (di6_value.toInt() == 1) {
        M5.Lcd.drawString("6: ON", 170, 80, 1);
      }
    }

    if (IONum.toInt() >= 7) {
      if (di7_value.toInt() == 0) {
        M5.Lcd.drawString("7: OFF", 170, 120, 1);
      }
      if (di7_value.toInt() == 1) {
        M5.Lcd.drawString("7: ON", 170, 120, 1);
      }
    }

    if (IONum.toInt() >= 8) {
      if (di8_value.toInt() == 0) {
        M5.Lcd.drawString("8: OFF", 170, 160, 1);
      }
      if (di8_value.toInt() == 1) {
        M5.Lcd.drawString("8: ON", 170, 160, 1);
      }
    }

    M5.Lcd.drawString("CFG", 240, 210, 1);


    if (apiAccessGranted && (!cellModemRefreshSuccessful || !signalQualityCheckSuccessful)) {
      if (firstSignalQualityCheck) {
        receivingSignalQuality = true;
        requestCellularSignalQuality();
      } else {
        receivingSignalQuality = false;
        requestCellModemRefresh();
      }
    }
  }
  if (cycleCounter == 1) {
    M5.Lcd.drawString("Digital Outputs", 30, 0, 1);

    if (IONum.toInt() >= 1) {
      if (do1CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("1: FAIL", 0, 40, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        if (do1_value.toInt() == 0) {
          M5.Lcd.drawString("1: OFF", 0, 40, 1);
        }
        if (do1_value.toInt() == 1) {
          M5.Lcd.drawString("1: ON", 0, 40, 1);
        }
      }
    }

    if (IONum.toInt() >= 2) {
      if (do2CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("2: FAIL", 0, 80, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        if (do2_value.toInt() == 0) {
          M5.Lcd.drawString("2: OFF", 0, 80, 1);
        }
        if (do2_value.toInt() == 1) {
          M5.Lcd.drawString("2: ON", 0, 80, 1);
        }
      }
    }

    if (IONum.toInt() >= 3) {
      if (do3CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("3: FAIL", 0, 120, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        if (do3_value.toInt() == 0) {
          M5.Lcd.drawString("3: OFF", 0, 120, 1);
        }
        if (do3_value.toInt() == 1) {
          M5.Lcd.drawString("3: ON", 0, 120, 1);
        }
      }
    }

    if (IONum.toInt() >= 4) {
      if (do4CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("4: FAIL", 0, 160, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        if (do4_value.toInt() == 0) {
          M5.Lcd.drawString("4: OFF", 0, 160, 1);
        }
        if (do4_value.toInt() == 1) {
          M5.Lcd.drawString("4: ON", 0, 160, 1);
        }
      }
    }

    if (IONum.toInt() >= 5) {
      if (do5CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("5: FAIL", 170, 40, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        if (do5_value.toInt() == 0) {
          M5.Lcd.drawString("5: OFF", 170, 40, 1);
        }
        if (do5_value.toInt() == 1) {
          M5.Lcd.drawString("5: ON", 170, 40, 1);
        }
      }
    }

    if (IONum.toInt() >= 6) {
      if (do6CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("6: FAIL", 170, 80, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        if (do6_value.toInt() == 0) {
          M5.Lcd.drawString("6: OFF", 170, 80, 1);
        }
        if (do6_value.toInt() == 1) {
          M5.Lcd.drawString("6: ON", 170, 80, 1);
        }
      }
    }

    if (IONum.toInt() >= 7) {
      if (do7CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("7: FAIL", 170, 120, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        if (do7_value.toInt() == 0) {
          M5.Lcd.drawString("7: OFF", 170, 120, 1);
        }
        if (do7_value.toInt() == 1) {
          M5.Lcd.drawString("7: ON", 170, 120, 1);
        }
      }
    }

    if (IONum.toInt() >= 8) {
      if (do8CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("8: FAIL", 170, 160, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        if (do8_value.toInt() == 0) {
          M5.Lcd.drawString("8: OFF", 170, 160, 1);
        }
        if (do8_value.toInt() == 1) {
          M5.Lcd.drawString("8: ON", 170, 160, 1);
        }
      }
    }

    M5.Lcd.drawString("CFG", 240, 210, 1);   
  }
  if (cycleCounter == 2) {
    M5.Lcd.drawString("Analog In (mA)", 30, 0, 1);

    if (IONum.toInt() >= 1) {
      M5.Lcd.drawString("1: " + String(ai1_value.toFloat() / 1600.00, 2), 0, 40, 1);
    }

    if (IONum.toInt() >= 2) {
      M5.Lcd.drawString("2: " + String(ai2_value.toFloat() / 1600.00, 2), 0, 80, 1);
    }

    if (IONum.toInt() >= 3) {
      M5.Lcd.drawString("3: " + String(ai3_value.toFloat() / 1600.00, 2), 0, 120, 1);
    }

    if (IONum.toInt() >= 4) {
      M5.Lcd.drawString("4: " + String(ai4_value.toFloat() / 1600.00, 2), 0, 160, 1);
    }

    if (IONum.toInt() >= 5) {
      M5.Lcd.drawString("5: " + String(ai5_value.toFloat() / 1600.00, 2), 170, 40, 1);
    }

    if (IONum.toInt() >= 6) {
      M5.Lcd.drawString("6: " + String(ai6_value.toFloat() / 1600.00, 2), 170, 80, 1);
    }

    if (IONum.toInt() >= 7) {
      M5.Lcd.drawString("7: " + String(ai7_value.toFloat() / 1600.00, 2), 170, 120, 1);
    }

    if (IONum.toInt() >= 8) {
      M5.Lcd.drawString("8: " + String(ai8_value.toFloat() / 1600.00, 2), 170, 160, 1);
    }

    M5.Lcd.drawString("CFG", 240, 210, 1);
  }
  if (cycleCounter == 3) {
    M5.Lcd.drawString("Analog Out (mA)", 25, 0, 1);
    
    if (IONum.toInt() >= 1) {
      if (ao1CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("1: FAIL", 0, 40, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        M5.Lcd.drawString("1: " + String(ao1_value.toFloat() / 3276.75, 2), 0, 40, 1);
      }
    }
    
    if (IONum.toInt() >= 2) {
      if (ao2CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("2: FAIL", 0, 80, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        M5.Lcd.drawString("2: " + String(ao2_value.toFloat() / 3276.75, 2), 0, 80, 1);
      }
    }
    
    if (IONum.toInt() >= 3) {
      if (ao3CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("3: FAIL", 0, 120, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        M5.Lcd.drawString("3: " + String(ao3_value.toFloat() / 3276.75, 2), 0, 120, 1);
      }
    }
    
    if (IONum.toInt() >= 4) {
      if (ao4CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("4: FAIL", 0, 160, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        M5.Lcd.drawString("4: " + String(ao4_value.toFloat() / 3276.75, 2), 0, 160, 1);
      }
    }
    
    if (IONum.toInt() >= 5) {
      if (ao5CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("5: FAIL", 170, 40, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        M5.Lcd.drawString("5: " + String(ao5_value.toFloat() / 3276.75, 2), 170, 40, 1);
      }
    }
    
    if (IONum.toInt() >= 6) {
      if (ao6CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("6: FAIL", 170, 80, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        M5.Lcd.drawString("6: " + String(ao6_value.toFloat() / 3276.75, 2), 170, 80, 1);
      }
    }
    
    if (IONum.toInt() >= 7) {
      if (ao7CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("7: FAIL", 170, 120, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        M5.Lcd.drawString("7: " + String(ao7_value.toFloat() / 3276.75, 2), 170, 120, 1);
      }
    }
    
    if (IONum.toInt() >= 8) {
      if (ao8CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString("8: FAIL", 170, 160, 1);
        M5.Lcd.setTextColor(WHITE);
      } else {
        M5.Lcd.drawString("8: " + String(ao8_value.toFloat() / 3276.75, 2), 170, 160, 1);
      }
    }

    M5.Lcd.drawString("CFG", 240, 210, 1);
  }
  cycleCounter++;
  if (cycleCounter >= 4) {
    cycleCounter = 0;
  }
}

void onLeftPress() {
  if (leftRed.isPressed()) {
    triggerSound = true;
  }

  if (configMenu1 || configMenu2 || configMenu3 || cfgServerMode) {
    if (leftRed.isPressed()) {
      leftPressedOnce = true;
    }
  }

  if (leftRed.isPressed() && warningMenu1) {
    leftPressedTwice = true;
  }

  if (leftRed.isPressed() && warningMenu2) {
    leftPressedThree = true;
  }
}

void onLeftRelease() {
  if (leftRed.isReleased() && triggerSound) {
    M5.Spk.PlaySound(beep, sizeof(beep));
    triggerSound = false;
    timeOutPreviousMillis = timeOutCurrentMillis;
  }

  if (warningMenu1) {
    if (leftRed.isReleased() && leftPressedTwice) {
      leftPressedTwice = false;
      warningMenu1 = false;
      configMenu1 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
      M5.Lcd.drawString("EXIT", 80, 0, 1);
      M5.Lcd.drawString("DEVICE INFO", 50, 50, 1);
      M5.Lcd.drawString("OUTPUT TEST", 50, 100, 1);
      M5.Lcd.drawString("DEVICE CONFIG", 50, 150, 1);
      M5.Lcd.drawString(dateString, 20, 200, 1);
      //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
    }
  }

  if (warningMenu2) {
    if (leftRed.isReleased() && leftPressedThree) {
      leftPressedThree = false;
      warningMenu2 = false;
      configMenu1 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
      M5.Lcd.drawString("EXIT", 80, 0, 1);
      M5.Lcd.drawString("DEVICE INFO", 50, 50, 1);
      M5.Lcd.drawString("OUTPUT TEST", 50, 100, 1);
      M5.Lcd.drawString("DEVICE CONFIG", 50, 150, 1);
      M5.Lcd.drawString(dateString, 20, 200, 1);
      //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
    }
  }

  if (cfgServerMode) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
      viewConfigItemsIterator--;
      if (viewConfigItemsIterator < 0) {
        viewConfigItemsIterator = 20;
      }
      cycleConfigItems(viewConfigItemsIterator);
    }
  }

  if (configMenu1 || configMenu2) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
      configMenu1Iterator--;
      if (configMenu1) {
        if (configMenu1Iterator < 0) {
          configMenu1Iterator = 3; //CHANGE TO ADJUST NUMBER OF MENUS
        }
      }
      else if (configMenu2) {
        if (configMenu1Iterator < 0) {
          configMenu1Iterator = 4; //CHANGE TO ADJUST NUMBER OF MENUS
        }
      }
      if (configMenu1Iterator == 0) {
        M5.Lcd.fillRect(20, 50, 20, 20, BLACK);
        M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 1) {
        M5.Lcd.fillRect(20, 100, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 50, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 2) {
        M5.Lcd.fillRect(20, 150, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 100, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 3) {
        if (configMenu1) {
          M5.Lcd.fillRect(50, 0, 20, 20, BLACK);
          M5.Lcd.fillRect(20, 150, 20, 20, GREEN);
        }
        else if (configMenu2) {
          M5.Lcd.fillRect(20, 200, 20, 20, BLACK);
          M5.Lcd.fillRect(20, 150, 20, 20, GREEN);
        }
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 4) {
        M5.Lcd.fillRect(50, 0, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 200, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
    }
  }
  if (configMenu3 && configMenu1Iterator == 1) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
    }
  }
  if (configMenu3 && configMenu1Iterator == 2) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
    }  
  }
  if (configMenu3 && configMenu1Iterator == 3) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
    }
  }
}

void onCenterPress() {
  if (centerRed.isPressed()) {
    triggerSound = true;
  }

  if (configMenu1 || configMenu2 || configMenu3 || cfgServerMode) {
    if (centerRed.isPressed()) {
      centerPressedOnce = true;
    }
  }
}

void onCenterRelease() {
  if (centerRed.isReleased() && triggerSound) {
    M5.Spk.PlaySound(beep, sizeof(beep));
    triggerSound = false;
    timeOutPreviousMillis = timeOutCurrentMillis;
  }

  if (cfgServerMode) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
      viewConfigItemsIterator++;
      if (viewConfigItemsIterator > 20) {
        viewConfigItemsIterator = 0;
      }
      cycleConfigItems(viewConfigItemsIterator);
    }
  }
  
  if (configMenu1 || configMenu2) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
      configMenu1Iterator++;
      if (configMenu1) {
        if (configMenu1Iterator > 3) { //CHANGE TO ADJUST NUMBER OF MENUS
          configMenu1Iterator = 0;
        }
      }
      else if (configMenu2) {
        if (configMenu1Iterator > 4) { //CHANGE TO ADJUST NUMBER OF MENUS
          configMenu1Iterator = 0;
        }
      }
      if (configMenu1Iterator == 0) {
        if (configMenu1) {
          M5.Lcd.fillRect(20, 150, 20, 20, BLACK);
          M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
        }
        else if (configMenu2) {
          M5.Lcd.fillRect(20, 200, 20, 20, BLACK);
          M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
        }
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 1) {
        M5.Lcd.fillRect(50, 0, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 50, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 2) {
        M5.Lcd.fillRect(20, 50, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 100, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 3) {
        M5.Lcd.fillRect(20, 100, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 150, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 4) {
        M5.Lcd.fillRect(20, 150, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 200, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
    }
  }
  if (configMenu3 && configMenu1Iterator == 1) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
    }
  }
  if (configMenu3 && configMenu1Iterator == 2) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
    }  
  }
  if (configMenu3 && configMenu1Iterator == 3) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
    }
  }
}

void onRightPress() {
  if (rightRed.isPressed()) {
    triggerSound = true;
  }

  if (rightRed.isPressed() && (normalMode || cfgServerMode)) {
    rightPressedOnce = true;
    //normalMode = false;
  }

  if (rightRed.isPressed() && configMenu1) {
    rightPressedTwice = true;
    //configMenu1 = false;
  }

  if (rightRed.isPressed() && (configMenu2 || warningMenu1)) {
    rightPressedThree = true;
    //configMenu2 = false;
  }

  if (rightRed.isPressed() && (configMenu3 || warningMenu2)) {
    rightPressedFour = true;
    //configMenu3 = false;
  }
}

void onRightRelease() {
  if (rightRed.isReleased() && triggerSound) {
    M5.Spk.PlaySound(beep, sizeof(beep));
    triggerSound = false;
    timeOutPreviousMillis = timeOutCurrentMillis;
  }

  if (warningMenu1) {
    if (rightRed.isReleased() && rightPressedThree) {
      rightPressedThree = false;
      warningMenu1 = false;
      warningMenu2 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.drawString("ARE YOU SURE?", 40, 20, 1);
      M5.Lcd.drawString("SYSTEM WILL HAVE", 5, 80, 1);
      M5.Lcd.drawString("NEW SETTINGS!", 40, 140, 1);
      M5.Lcd.drawString("BACK", 10, 210, 1);
      M5.Lcd.drawString("CONTINUE", 175, 210, 1);
    }
  }

  if (warningMenu2) {
    if (rightRed.isReleased() && rightPressedFour) {
      rightPressedFour = false;
      warningMenu2 = false;
      M5.Lcd.drawString("CONFIG MODE", 10, 200, 1);
      delay(1000);
      //M5.Lcd.clear();
      //M5.Lcd.setCursor(0, 0);
      cfgServerMode = true;
      hasConfigInfo = false;

      configConnect();
    }
  }

  if (cfgServerMode) {
    if (rightRed.isReleased() && rightPressedOnce) {
      cfgServerMode = false;
      //normalMode = true;
      hasConfigInfo = true;
      rightPressedOnce = false;

      myFile = SD.open(sdConfigFileName, FILE_WRITE);
      myFile.print(groupID + "_GID;" + unitID + "_UID;" + IONum + "_ION;" + updateTime + "_UPT;" + consumerName + "_CN;" +
      *di_feeds[0] + ";" + *di_feeds[1] + ";" + *di_feeds[2] + ";" + *di_feeds[3] + ";" + *di_feeds[4] + ";" + *di_feeds[5] + ";" + *di_feeds[6] + ";" + *di_feeds[7] + ";" +
      *ai_feeds[0] + ";" + *ai_feeds[1] + ";" + *ai_feeds[2] + ";" + *ai_feeds[3] + ";" + *ai_feeds[4] + ";" + *ai_feeds[5] + ";" + *ai_feeds[6] + ";" + *ai_feeds[7] + ";" +
      do1_feed + "_DO1;" + do2_feed + "_DO2;" + do3_feed + "_DO3;" + do4_feed + "_DO4;" + do5_feed + "_DO5;" + do6_feed + "_DO6;" + do7_feed + "_DO7;" + do8_feed + "_DO8;" +
      ao1_feed + "_AO1;" + ao2_feed + "_AO2;" + ao3_feed + "_AO3;" + ao4_feed + "_AO4;" + ao5_feed + "_AO5;" + ao6_feed + "_AO6;" + ao7_feed + "_AO7;" + ao8_feed + "_AO8;" +
      df1ReadValue + "_DF1;" + df2ReadValue + "_DF2;" + df3ReadValue + "_DF3;" + df4ReadValue + "_DF4;" + df5ReadValue + "_DF5;" + df6ReadValue + "_DF6;" + df7ReadValue + "_DF7;" + df8ReadValue + "_DF8;" +
      af1ReadValue + "_AF1;" + af2ReadValue + "_AF2;" + af3ReadValue + "_AF3;" + af4ReadValue + "_AF4;" + af5ReadValue + "_AF5;" + af6ReadValue + "_AF6;" + af7ReadValue + "_AF7;" + af8ReadValue + "_AF8;" +
      heartbeatSubscriptionsString + "_HB;");
      myFile.close();
      //ESP.restart();

      di1_feed = *di_feeds[0];
      di2_feed = *di_feeds[1];
      di3_feed = *di_feeds[2];
      di4_feed = *di_feeds[3];
      di5_feed = *di_feeds[4];
      di6_feed = *di_feeds[5];
      di7_feed = *di_feeds[6];
      di8_feed = *di_feeds[7];

      ai1_feed = *ai_feeds[0];
      ai2_feed = *ai_feeds[1];
      ai3_feed = *ai_feeds[2];
      ai4_feed = *ai_feeds[3];
      ai5_feed = *ai_feeds[4];
      ai6_feed = *ai_feeds[5];
      ai7_feed = *ai_feeds[6];
      ai8_feed = *ai_feeds[7];

      di1_feedACK = *di_feedsACK[0];
      di2_feedACK = *di_feedsACK[1];
      di3_feedACK = *di_feedsACK[2];
      di4_feedACK = *di_feedsACK[3];
      di5_feedACK = *di_feedsACK[4];
      di6_feedACK = *di_feedsACK[5];
      di7_feedACK = *di_feedsACK[6];
      di8_feedACK = *di_feedsACK[7];

      ai1_feedACK = *ai_feedsACK[0];
      ai2_feedACK = *ai_feedsACK[1];
      ai3_feedACK = *ai_feedsACK[2];
      ai4_feedACK = *ai_feedsACK[3];
      ai5_feedACK = *ai_feedsACK[4];
      ai6_feedACK = *ai_feedsACK[5];
      ai7_feedACK = *ai_feedsACK[6];
      ai8_feedACK = *ai_feedsACK[7];

      if (startUpMode && forceUpdate) {
        forceUpdate = false;
        apiConnect();
        credConnect();
      }

      if (initialSDCheck) {
        //M5.Lcd.fillRect(10, 190, 300, 50, BLACK);
        //M5.Lcd.drawString("NORMAL MODE", 10, 200, 1);
        initialSDCheck = false;
        returnToNormalOperation();
        //delay(1000);
      } else {
        configMenu1 = true;
        M5.Lcd.fillRect(10, 190, 300, 50, BLACK);
        M5.Lcd.drawString("SETTINGS MODE", 10, 200, 1);
        delay(1000);
        M5.Lcd.clear();
        M5.Lcd.setCursor(0, 0);

        M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DEVICE INFO", 50, 50, 1);
        M5.Lcd.drawString("OUTPUT TEST", 50, 100, 1);
        M5.Lcd.drawString("DEVICE CONFIG", 50, 150, 1);
        M5.Lcd.drawString(dateString, 20, 200, 1);
        //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
      }
    }
  }

  if (rightRed.isReleased() && rightPressedOnce) {
    normalMode = false;
    configMenu1 = true;
    rightPressedOnce = false;
    M5.Lcd.drawString("SETTINGS MODE", 10, 200, 1);
    delay(1000);
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);

    M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
    M5.Lcd.drawString(rciTitle, 50, 70, 1);
    M5.Lcd.drawString("CLOSING", 90, 120, 1);
    M5.Lcd.drawString("CONNECTION", 60, 170, 1);

    mqttClient.stop();

    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);
    delay(100);

    M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
    M5.Lcd.drawString("EXIT", 80, 0, 1);
    M5.Lcd.drawString("DEVICE INFO", 50, 50, 1);
    M5.Lcd.drawString("OUTPUT TEST", 50, 100, 1);
    M5.Lcd.drawString("DEVICE CONFIG", 50, 150, 1);
    M5.Lcd.drawString(dateString, 20, 200, 1);
    //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
  }

  if (rightRed.isReleased() && rightPressedTwice) {
    rightPressedTwice = false;

    if (configMenu1Iterator == 0) {
      returnToNormalOperation();
    }

    if (configMenu1Iterator == 2) {
      configMenu1 = false;
      configMenu2 = true;
      configMenu1Iterator = 0;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
      M5.Lcd.drawString("EXIT", 80, 0, 1);
      M5.Lcd.drawString("OUTPUT = 20mA", 50, 50, 1);
      M5.Lcd.drawString("OUTPUT = 12mA", 50, 100, 1);
      M5.Lcd.drawString("OUTPUT = 4mA", 50, 150, 1);
      M5.Lcd.drawString("OUTPUT = INPUT", 50, 200, 1);
    }

    if (configMenu1Iterator == 3) {
      configMenu1Iterator = 0;
      configMenu1 = false;
      warningMenu1 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.drawString("WARNING!", 80, 20, 1);
      M5.Lcd.drawString("THIS WILL ERASE", 10, 80, 1);
      M5.Lcd.drawString("CURRENT SETTINGS!", 5, 140, 1);
      M5.Lcd.drawString("BACK", 10, 210, 1);
      M5.Lcd.drawString("CONTINUE", 175, 210, 1);
    }

    if (configMenu1Iterator == 1) {
      configMenu1Iterator = 0;
      configMenu1 = false;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      M5.Lcd.drawString("CONFIG INFO", 40, 0, 1);
      cycleConfigItems(viewConfigItemsIterator);
      cfgServerMode = true;
      hasConfigInfo = false;
      ioKnown = true;
    }

    if (configMenu1Iterator == 4) {
      delay(5000);
    }
  }

  if (rightRed.isReleased() && rightPressedThree) {
    rightPressedThree = false;

    if (configMenu1Iterator == 0) {
      configMenu1 = true;
      configMenu2 = false;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
      M5.Lcd.drawString("EXIT", 80, 0, 1);
      M5.Lcd.drawString("DEVICE INFO", 50, 50, 1);
      M5.Lcd.drawString("OUTPUT TEST", 50, 100, 1);
      M5.Lcd.drawString("DEVICE CONFIG", 50, 150, 1);
      M5.Lcd.drawString(dateString, 20, 200, 1);
      //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
    }

    if (configMenu1Iterator == 1) {
      configMenu2 = false;
      configMenu3 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      delay(300);
      M5.Lcd.drawString("ALL RELAYS = ON", 10, 50, 1);
      M5.Lcd.drawString("ALL OUTPUTS = 20mA", 0, 120, 1);
      M5.Lcd.drawString("ESC", 240, 210, 1);

      if (digitalOutputSuccess) {
        pcfw1.digitalWrite(0, false);
        pcfw1.digitalWrite(1, false);
        pcfw1.digitalWrite(2, false);
        pcfw1.digitalWrite(3, false);
        pcfw1.digitalWrite(4, false);
        pcfw1.digitalWrite(5, false);
        pcfw1.digitalWrite(6, false);
        pcfw1.digitalWrite(7, false);
      }

      if (digitalDebugSuccess) {
        pcfw2.digitalWrite(0, false);
      }

      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(0));
        Wire.write(byte(65535 >> 8));
        Wire.write(byte(65535));
        Wire.endTransmission();
  
        Wire.beginTransmission(0x1f);
        Wire.write(byte(1));
        Wire.write(byte(65535 >> 8));
        Wire.write(byte(65535));
        Wire.endTransmission();

        Wire.beginTransmission(0x1f);
        Wire.write(byte(2));
        Wire.write(byte(65535 >> 8));
        Wire.write(byte(65535));
        Wire.endTransmission();
  
        Wire.beginTransmission(0x1f);
        Wire.write(byte(3));
        Wire.write(byte(65535 >> 8));
        Wire.write(byte(65535));
        Wire.endTransmission();
      }

      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(0));
        Wire.write(byte(65535 >> 8));
        Wire.write(byte(65535));
        Wire.endTransmission();
  
        Wire.beginTransmission(0x1c);
        Wire.write(byte(1));
        Wire.write(byte(65535 >> 8));
        Wire.write(byte(65535));
        Wire.endTransmission();

        Wire.beginTransmission(0x1c);
        Wire.write(byte(2));
        Wire.write(byte(65535 >> 8));
        Wire.write(byte(65535));
        Wire.endTransmission();
  
        Wire.beginTransmission(0x1c);
        Wire.write(byte(3));
        Wire.write(byte(65535 >> 8));
        Wire.write(byte(65535));
        Wire.endTransmission();
      }
    }

    if (configMenu1Iterator == 3) {
      configMenu2 = false;
      configMenu3 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      delay(300);
      M5.Lcd.drawString("ALL RELAYS = OFF", 10, 50, 1);
      M5.Lcd.drawString("ALL OUTPUTS = 4mA", 5, 120, 1);
      M5.Lcd.drawString("ESC", 240, 210, 1);

      if (digitalOutputSuccess) {
        pcfw1.digitalWrite(0, true);
        pcfw1.digitalWrite(1, true);
        pcfw1.digitalWrite(2, true);
        pcfw1.digitalWrite(3, true);
        pcfw1.digitalWrite(4, true);
        pcfw1.digitalWrite(5, true);
        pcfw1.digitalWrite(6, true);
        pcfw1.digitalWrite(7, true);
      }

      if (digitalDebugSuccess) {
        pcfw2.digitalWrite(0, true);
      }

      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(0));
        Wire.write(byte((int) ((1.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((1.0/5.0) * 65535)));
        Wire.endTransmission();
  
        Wire.beginTransmission(0x1f);
        Wire.write(byte(1));
        Wire.write(byte((int) ((1.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((1.0/5.0) * 65535)));
        Wire.endTransmission();

        Wire.beginTransmission(0x1f);
        Wire.write(byte(2));
        Wire.write(byte((int) ((1.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((1.0/5.0) * 65535)));
        Wire.endTransmission();
  
        Wire.beginTransmission(0x1f);
        Wire.write(byte(3));
        Wire.write(byte((int) ((1.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((1.0/5.0) * 65535)));
        Wire.endTransmission();
      }

      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(0));
        Wire.write(byte((int) ((1.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((1.0/5.0) * 65535)));
        Wire.endTransmission();
  
        Wire.beginTransmission(0x1c);
        Wire.write(byte(1));
        Wire.write(byte((int) ((1.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((1.0/5.0) * 65535)));
        Wire.endTransmission();

        Wire.beginTransmission(0x1c);
        Wire.write(byte(2));
        Wire.write(byte((int) ((1.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((1.0/5.0) * 65535)));
        Wire.endTransmission();
  
        Wire.beginTransmission(0x1c);
        Wire.write(byte(3));
        Wire.write(byte((int) ((1.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((1.0/5.0) * 65535)));
        Wire.endTransmission();
      }
    }

    if (configMenu1Iterator == 4) {
      configMenu2 = false;
      configMenu3 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      delay(300);
      M5.Lcd.drawString("COPY ALL INPUT", 10, 50, 1);
      M5.Lcd.drawString("VALUES TO OUTPUT", 10, 120, 1);
      M5.Lcd.drawString("ESC", 240, 210, 1);

      if (digitalDebugSuccess) {
        pcfw2.digitalWrite(0, false);
      }

      copyMode = true;
    }
    
    if (configMenu1Iterator == 2) {
      configMenu2 = false;
      configMenu3 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      delay(300);
      M5.Lcd.drawString("ALL RELAYS = OFF", 10, 50, 1);
      M5.Lcd.drawString("ALL OUTPUTS = 12mA", 0, 120, 1);
      M5.Lcd.drawString("ESC", 240, 210, 1);

      if (digitalOutputSuccess) {
        pcfw1.digitalWrite(0, true);
        pcfw1.digitalWrite(1, true);
        pcfw1.digitalWrite(2, true);
        pcfw1.digitalWrite(3, true);
        pcfw1.digitalWrite(4, true);
        pcfw1.digitalWrite(5, true);
        pcfw1.digitalWrite(6, true);
        pcfw1.digitalWrite(7, true);
      }

      if (digitalDebugSuccess) {
        pcfw2.digitalWrite(0, true);
      }

      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(0));
        Wire.write(byte((int) ((3.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((3.0/5.0) * 65535)));
        Wire.endTransmission();
  
        Wire.beginTransmission(0x1f);
        Wire.write(byte(1));
        Wire.write(byte((int) ((3.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((3.0/5.0) * 65535)));
        Wire.endTransmission();

        Wire.beginTransmission(0x1f);
        Wire.write(byte(2));
        Wire.write(byte((int) ((3.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((3.0/5.0) * 65535)));
        Wire.endTransmission();
  
        Wire.beginTransmission(0x1f);
        Wire.write(byte(3));
        Wire.write(byte((int) ((3.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((3.0/5.0) * 65535)));
        Wire.endTransmission();
      }

      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(0));
        Wire.write(byte((int) ((3.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((3.0/5.0) * 65535)));
        Wire.endTransmission();
  
        Wire.beginTransmission(0x1c);
        Wire.write(byte(1));
        Wire.write(byte((int) ((3.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((3.0/5.0) * 65535)));
        Wire.endTransmission();

        Wire.beginTransmission(0x1c);
        Wire.write(byte(2));
        Wire.write(byte((int) ((3.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((3.0/5.0) * 65535)));
        Wire.endTransmission();
  
        Wire.beginTransmission(0x1c);
        Wire.write(byte(3));
        Wire.write(byte((int) ((3.0/5.0) * 65535) >> 8));
        Wire.write(byte((int) ((3.0/5.0) * 65535)));
        Wire.endTransmission();
      }
    }
  }

  if (rightRed.isReleased() && rightPressedFour) {
    firstConfigAo1Press = true;
    configAo1Counter = 0;
    configAo1Value = 0;
    configAo2Value = 0;

    copyMode = false;
    rightPressedFour = false;
    configMenu2 = true;
    configMenu3 = false;
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);
    delay(300);

    configMenu1Iterator = 0;
    M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
    M5.Lcd.drawString("EXIT", 80, 0, 1);
    M5.Lcd.drawString("OUTPUT = 20mA", 50, 50, 1);
    M5.Lcd.drawString("OUTPUT = 12mA", 50, 100, 1);
    M5.Lcd.drawString("OUTPUT = 4mA", 50, 150, 1);
    M5.Lcd.drawString("OUTPUT = INPUT", 50, 200, 1);
  }
}

void inputToOutputCopyRoutine() {
  //TEST DIGITAL IO FUNCTIONALITY
  if (digitalInputSuccess) {
    pcfr0Test = int(pcfr.digitalRead(0));
    pcfr1Test = int(pcfr.digitalRead(1));
    pcfr2Test = int(pcfr.digitalRead(2));
    pcfr3Test = int(pcfr.digitalRead(3));
    pcfr4Test = int(pcfr.digitalRead(4));
    pcfr5Test = int(pcfr.digitalRead(5));
    pcfr6Test = int(pcfr.digitalRead(6));
    pcfr7Test = int(pcfr.digitalRead(7));
  }

  if (digitalOutputSuccess) {
    pcfw1.digitalWrite(0, !bool(pcfr0Test));
    pcfw1.digitalWrite(1, !bool(pcfr1Test));
    pcfw1.digitalWrite(2, !bool(pcfr2Test));
    pcfw1.digitalWrite(3, !bool(pcfr3Test));
    pcfw1.digitalWrite(4, !bool(pcfr4Test));
    pcfw1.digitalWrite(5, !bool(pcfr5Test));
    pcfw1.digitalWrite(6, !bool(pcfr6Test));
    pcfw1.digitalWrite(7, !bool(pcfr7Test));
  }

  //if (digitalDebugSuccess) {
    //pcfw2.digitalWrite(0, !bool(pcfr7Test));
    //pcfw2.digitalWrite(1, !bool(pcfr7Test));
  //}


  //TEST AD5665R DAC SCALABILITY
  if (analogInOneSuccess) {
    testadc0 = ads1115.readADC_SingleEnded(0);

    //M5.Lcd.drawString(String(testadc0), 0, 210, 1);
    //M5.Lcd.drawString(String(int(testadc0 * 2.048)), 0, 210, 1);
    //M5.Lcd.drawString(String(int(testadc1 * 2.048)), 0, 210, 1);

    testadc0 = int(testadc0 * 2.048);
    if (testadc0 < 0) {
      testadc0 = 0;
    }
    if (testadc0 > 65535) {
      testadc0 = 65535;
    }

    testadc1 = ads1115.readADC_SingleEnded(1);
    testadc1 = int(testadc1 * 2.048);
    if (testadc1 < 0) {
      testadc1 = 0;
    }
    if (testadc1 > 65535) {
      testadc1 = 65535;
    }

    testadc2 = ads1115.readADC_SingleEnded(2);
    testadc2 = int(testadc2 * 2.048);
    if (testadc2 < 0) {
      testadc2 = 0;
    }
    if (testadc2 > 65535) {
      testadc2 = 65535;
    }

    testadc3 = ads1115.readADC_SingleEnded(3);
    testadc3 = int(testadc3 * 2.048);
    if (testadc3 < 0) {
      testadc3 = 0;
    }
    if (testadc3 > 65535) {
      testadc3 = 65535;
    }
  }

  if (analogInTwoSuccess) {
    testadc4 = ads1115second.readADC_SingleEnded(0);
    testadc4 = int(testadc4 * 2.048);
    if (testadc4 < 0) {
      testadc4 = 0;
    }
    if (testadc4 > 65535) {
      testadc4 = 65535;
    }

    testadc5 = ads1115second.readADC_SingleEnded(1);
    testadc5 = int(testadc5 * 2.048);
    if (testadc5 < 0) {
      testadc5 = 0;
    }
    if (testadc5 > 65535) {
      testadc5 = 65535;
    }

    testadc6 = ads1115second.readADC_SingleEnded(2);
    testadc6 = int(testadc6 * 2.048);
    if (testadc6 < 0) {
      testadc6 = 0;
    }
    if (testadc6 > 65535) {
      testadc6 = 65535;
    }

    testadc7 = ads1115second.readADC_SingleEnded(3);
    testadc7 = int(testadc7 * 2.048);
    if (testadc7 < 0) {
      testadc7 = 0;
    }
    if (testadc7 > 65535) {
      testadc7 = 65535;
    }
  }


  if (analogOutOneSuccess) {
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
  }

  if (analogOutTwoSuccess) {
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
}

void publishHeartbeat() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  payload = "HB_" + unitID;

  mqttClient.beginMessage(heartbeat_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishConnected() {
  if (!pubConnectedSent) {
    pubConnectedSent = true;
    pubConnectedRecv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  
  payload = "HI";

  mqttClient.beginMessage(connected_feed_publish, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishConnectedReceipt() {
  payload = "1";

  mqttClient.beginMessage(connected_feed_subscribeACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishConf(bool final) {
  /*
  if (!pubConfSent) {
    pubConfSent = true;
  }
  */
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  if (final) {
    payload = "4";
  } else {
    payload = "2";
  }

  mqttClient.beginMessage(config_update_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishCreds(bool final) {
  /*
  if (!pubCredSent) {
    pubCredSent = true;
  }
  */
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  if (final) {
    payload = "4";
  } else {
    payload = "2";
  }

  mqttClient.beginMessage(credential_update_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishInternal(bool final) {
  /*
  if (!pubInternalSent) {
    pubInternalSent = true;
  }
  */
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  if (final) {
    payload = "4";
  } else {
    payload = "2";
  }

  mqttClient.beginMessage(internal_update_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishApi(bool final) {
  /*
  if (!pubApiSent) {
    pubApiSent = true;
  }
  */
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  if (final) {
    payload = "4";
  } else {
    payload = "2";
  }

  mqttClient.beginMessage(api_update_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishDI1() {
  if (!di1Sent) {
    di1Sent = true;
    di1Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
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

void publishDO1Receipt() {
  payload = "1";

  mqttClient.beginMessage(do1_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI2() {
  if (!di2Sent) {
    di2Sent = true;
    di2Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO2!", 10, 200, 1);
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

void publishDO2Receipt() {
  payload = "1";

  mqttClient.beginMessage(do2_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI3() {
  if (!di3Sent) {
    di3Sent = true;
    di3Recv = false;
  }
  
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

void publishDO3Receipt() {
  payload = "1";

  mqttClient.beginMessage(do3_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI4() {
  if (!di4Sent) {
    di4Sent = true;
    di4Recv = false;
  }
  
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

void publishDO4Receipt() {
  payload = "1";

  mqttClient.beginMessage(do4_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI5() {
  if (!di5Sent) {
    di5Sent = true;
    di5Recv = false;
  }
  
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

void publishDO5Receipt() {
  payload = "1";

  mqttClient.beginMessage(do5_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI6() {
  if (!di6Sent) {
    di6Sent = true;
    di6Recv = false;
  }
  
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

void publishDO6Receipt() {
  payload = "1";

  mqttClient.beginMessage(do6_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI7() {
  if (!di7Sent) {
    di7Sent = true;
    di7Recv = false;
  }
  
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

void publishDO7Receipt() {
  payload = "1";

  mqttClient.beginMessage(do7_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI8() {
  if (!di8Sent) {
    di8Sent = true;
    di8Recv = false;
  }
  
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

void publishDO8Receipt() {
  payload = "1";

  mqttClient.beginMessage(do8_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI1() {
  if (!ai1Sent) {
    ai1Sent = true;
    ai1Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI1!");
  previousMillis2 = millis();
  clear = true;

  adc0 = ads1115.readADC_SingleEnded(0);
  adc0Prev = adc0;
  payload = String(adc0);
  ai1_value = payload;
  if (ai1_value.toInt() < 0) {
    ai1_value = "0";
  }

  mqttClient.beginMessage(ai1_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO1Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao1_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI2() {
  if (!ai2Sent) {
    ai2Sent = true;
    ai2Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI2!");
  previousMillis2 = millis();
  clear = true;

  adc1 = ads1115.readADC_SingleEnded(1);
  adc1Prev = adc1;
  payload = String(adc1);
  ai2_value = payload;
  if (ai2_value.toInt() < 0) {
    ai2_value = "0";
  }

  mqttClient.beginMessage(ai2_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO2Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao2_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI3() {
  if (!ai3Sent) {
    ai3Sent = true;
    ai3Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI3!");
  previousMillis2 = millis();
  clear = true;

  adc2 = ads1115.readADC_SingleEnded(2);
  adc2Prev = adc2;
  payload = String(adc2);
  ai3_value = payload;
  if (ai3_value.toInt() < 0) {
    ai3_value = "0";
  }

  mqttClient.beginMessage(ai3_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO3Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao3_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI4() {
  if (!ai4Sent) {
    ai4Sent = true;
    ai4Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI4!");
  previousMillis2 = millis();
  clear = true;

  adc3 = ads1115.readADC_SingleEnded(3);
  adc3Prev = adc3;
  payload = String(adc3);
  ai4_value = payload;
  if (ai4_value.toInt() < 0) {
    ai4_value = "0";
  }

  mqttClient.beginMessage(ai4_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO4Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao4_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI5() {
  if (!ai5Sent) {
    ai5Sent = true;
    ai5Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI5!");
  previousMillis2 = millis();
  clear = true;

  adc0second = ads1115second.readADC_SingleEnded(0);
  adc0secondPrev = adc0second;
  payload = String(adc0second);
  ai5_value = payload;
  if (ai5_value.toInt() < 0) {
    ai5_value = "0";
  }

  mqttClient.beginMessage(ai5_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO5Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao5_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI6() {
  if (!ai6Sent) {
    ai6Sent = true;
    ai6Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI6!");
  previousMillis2 = millis();
  clear = true;

  adc1second = ads1115second.readADC_SingleEnded(1);
  adc1secondPrev = adc1second;
  payload = String(adc1second);
  ai6_value = payload;
  if (ai6_value.toInt() < 0) {
    ai6_value = "0";
  }

  mqttClient.beginMessage(ai6_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO6Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao6_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI7() {
  if (!ai7Sent) {
    ai7Sent = true;
    ai7Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI7!");
  previousMillis2 = millis();
  clear = true;

  adc2second = ads1115second.readADC_SingleEnded(2);
  adc2secondPrev = adc2second;
  payload = String(adc2second);
  ai7_value = payload;
  if (ai7_value.toInt() < 0) {
    ai7_value = "0";
  }

  mqttClient.beginMessage(ai7_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO7Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao7_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI8() {
  if (!ai8Sent) {
    ai8Sent = true;
    ai8Recv = false;
  }

  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI8!");
  previousMillis2 = millis();
  clear = true;

  adc3second = ads1115second.readADC_SingleEnded(3);
  adc3secondPrev = adc3second;
  payload = String(adc3second);
  ai8_value = payload;
  if (ai8_value.toInt() < 0) {
    ai8_value = "0";
  }

  mqttClient.beginMessage(ai8_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO8Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao8_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAll() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING ALL!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING ALL!");
  previousMillis2 = millis();
  clear = true;

  // save the last time a message was sent
  previousMillis = currentMillis;

  // send message, the Print interface can be used to set the message contents
  // in this case we know the size ahead of time, so the message payload can be streamed

  if (IONum.toInt() >= 1) {
    if (digitalInputSuccess) {
      publishDI1();
    }

    if (analogInOneSuccess) {
      publishAI1();
    }
  }  

  if (IONum.toInt() >= 2) {
    if (digitalInputSuccess) {
      publishDI2();
    }

    if (analogInOneSuccess) {
      publishAI2();
    }
  }  

  if (IONum.toInt() >= 3) {
    if (digitalInputSuccess) {
      publishDI3();
    }

    if (analogInOneSuccess) {
      publishAI3();
    }
  }  

  if (IONum.toInt() >= 4) {
    if (digitalInputSuccess) {
      publishDI4();
    }

    if (analogInOneSuccess) {
      publishAI4();
    }
  }  

  if (IONum.toInt() >= 5) {
    if (digitalInputSuccess) {
      publishDI5();
    }

    if (analogInTwoSuccess) {
      publishAI5();
    }
  }  

  if (IONum.toInt() >= 6) {
    if (digitalInputSuccess) {
      publishDI6();
    }

    if (analogInTwoSuccess) {
      publishAI6();
    }
  }  

  if (IONum.toInt() >= 7) {
    if (digitalInputSuccess) {
      publishDI7();
    }

    if (analogInTwoSuccess) {
      publishAI7();
    }
  }  

  if (IONum.toInt() >= 8) {
    if (digitalInputSuccess) {
      publishDI8();
    }

    if (analogInTwoSuccess) {
      publishAI8();
    }
  }  

  reconnectCount++;
}

void callback(char* topic, byte* payload, unsigned int length) {
  ;
}

void cycleConfigItems(int startIndex) {
  M5.Lcd.fillRect(0, 35, 350, 150, BLACK);
  String screenItem1 = String("");
  String screenItem2 = String("");
  String screenItem3 = String("");
  String screenItem4 = String("");
  String screenItem5 = String("");

  screenItem1 = *configItems[startIndex];
  screenItem2 = *configItems[startIndex + 1];
  screenItem3 = *configItems[startIndex + 2];
  screenItem4 = *configItems[startIndex + 3];
  screenItem5 = *configItems[startIndex + 4];

  M5.Lcd.drawString(screenItem1, 0, 40, 1);
  M5.Lcd.drawString(screenItem2, 0, 70, 1);
  M5.Lcd.drawString(screenItem3, 0, 100, 1);
  M5.Lcd.drawString(screenItem4, 0, 130, 1);
  M5.Lcd.drawString(screenItem5, 0, 160, 1);
  M5.Lcd.drawString("ESC", 240, 210, 1);
  M5.Lcd.drawString(versionNumber, 5, 210, 1);
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

  if (topic.substring(topic.length() - 2, topic.length()).equalsIgnoreCase("HB")) {
    checkHeartbeatSubscriptionArrays(topic.substring(topic.indexOf("_") + 1, topic.indexOf("_", topic.indexOf("_") + 1)));
  }

  if (topic.substring(topic.length() - 1, topic.length()).equalsIgnoreCase("p")) {
    subConnectedRecv = true;

    publishAllc = true;
  }
  if (topic.substring(topic.length() - 5, topic.length()).equalsIgnoreCase("p_ACK")) {
    pubConnectedRecv = true;
    pubConnectedSent = false;
    pubConnectedLoopCount = 0;
  }

  if (topic.substring(topic.length() - 12, topic.length()).equalsIgnoreCase("configUpdate")) {
    //subConfRecv = true;

    if (message.toInt() == 1) {
      confUpdateStep1 = true;
      confUpdateStep1PubOnce = true;
    }
    if (message.toInt() == 3 && confUpdateStep1) {
      confUpdateStep2 = true;
      confUpdateStep2PubOnce = true;
    }
  }
  /*
  if () {
    //pubConfRecv = true;
  }
  */

  if (topic.substring(topic.length() - 14, topic.length()).equalsIgnoreCase("internalUpdate")) {
    //subInternalRecv = true;

    if (message.toInt() == 1) {
      internalUpdateStep1 = true;
      internalUpdateStep1PubOnce = true;
    }
    if (message.toInt() == 3 && internalUpdateStep1) {
      internalUpdateStep2 = true;
      internalUpdateStep2PubOnce = true;
    }
  }
  /*
  if () {
    //pubInternalRecv = true
  }
  */

  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase("credUpdate")) {
    //subCredRecv = true;

    if (message.toInt() == 1) {
      credUpdateStep1 = true;
      credUpdateStep1PubOnce = true;
    }
    if (message.toInt() == 3 && credUpdateStep1) {
      credUpdateStep2 = true;
      credUpdateStep2PubOnce = true;
    }
  }
  /*
  if () {
    //pubCredRecv = true;
  }
  */

  if (topic.substring(topic.length() - 9, topic.length()).equalsIgnoreCase("apiUpdate")) {
    //subApiRecv = true;

    if (message.toInt() == 1) {
      apiUpdateStep1 = true;
      apiUpdateStep1PubOnce = true;
    }
    if (message.toInt() == 3 && apiUpdateStep1) {
      apiUpdateStep2 = true;
      apiUpdateStep2PubOnce = true;
    }
  }
  /*
  if () {
    //pubApiRecv = true
  }
  */

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do1_feed.substring(do1_feed.length() - 6, do1_feed.length()))) {
    do1Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(0, !bool(message.toInt()));
    }
    do1_value = message;
    //M5.Lcd.fillRect(90, 0, 300, 50, BLACK);
    //M5.Lcd.drawString(di1_value, 90, 0, 2);
    //replaceText(90, 0, 300, 50, 2 di1_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di1_feedACK.substring(di1_feedACK.length() - 10, di1_feedACK.length()))) {
    di1Recv = true;
    di1Sent = false;
    di1LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do2_feed.substring(do2_feed.length() - 6, do2_feed.length()))) {
    do2Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(1, !bool(message.toInt()));
    }
    do2_value = message;
    //M5.Lcd.fillRect(90, 40, 300, 50, BLACK);
    //M5.Lcd.drawString(di2_value, 90, 40, 2);
    //replaceText(90, 40, 300, 50, 2 di2_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di2_feedACK.substring(di2_feedACK.length() - 10, di2_feedACK.length()))) {
    di2Recv = true;
    di2Sent = false;
    di2LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do3_feed.substring(do3_feed.length() - 6, do3_feed.length()))) {
    do3Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(2, !bool(message.toInt()));
    }
    do3_value = message;
    //M5.Lcd.fillRect(90, 0, 300, 50, BLACK);
    //M5.Lcd.drawString(di1_value, 90, 0, 2);
    //replaceText(90, 0, 300, 50, 2 di1_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di3_feedACK.substring(di3_feedACK.length() - 10, di3_feedACK.length()))) {
    di3Recv = true;
    di3Sent = false;
    di3LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do4_feed.substring(do4_feed.length() - 6, do4_feed.length()))) {
    do4Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(3, !bool(message.toInt()));
    }
    do4_value = message;
    //M5.Lcd.fillRect(90, 40, 300, 50, BLACK);
    //M5.Lcd.drawString(di2_value, 90, 40, 2);
    //replaceText(90, 40, 300, 50, 2 di2_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di4_feedACK.substring(di4_feedACK.length() - 10, di4_feedACK.length()))) {
    di4Recv = true;
    di4Sent = false;
    di4LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do5_feed.substring(do5_feed.length() - 6, do5_feed.length()))) {
    do5Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(4, !bool(message.toInt()));
    }
    do5_value = message;
    //M5.Lcd.fillRect(90, 0, 300, 50, BLACK);
    //M5.Lcd.drawString(di1_value, 90, 0, 2);
    //replaceText(90, 0, 300, 50, 2 di1_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di5_feedACK.substring(di5_feedACK.length() - 10, di5_feedACK.length()))) {
    di5Recv = true;
    di5Sent = false;
    di5LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do6_feed.substring(do6_feed.length() - 6, do6_feed.length()))) {
    do6Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(5, !bool(message.toInt()));
    }
    do6_value = message;
    //M5.Lcd.fillRect(90, 40, 300, 50, BLACK);
    //M5.Lcd.drawString(di2_value, 90, 40, 2);
    //replaceText(90, 40, 300, 50, 2 di2_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di6_feedACK.substring(di6_feedACK.length() - 10, di6_feedACK.length()))) {
    di6Recv = true;
    di6Sent = false;
    di6LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do7_feed.substring(do7_feed.length() - 6, do7_feed.length()))) {
    do7Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(6, !bool(message.toInt()));
    }
    do7_value = message;
    //M5.Lcd.fillRect(90, 0, 300, 50, BLACK);
    //M5.Lcd.drawString(di1_value, 90, 0, 2);
    //replaceText(90, 0, 300, 50, 2 di1_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di7_feedACK.substring(di7_feedACK.length() - 10, di7_feedACK.length()))) {
    di7Recv = true;
    di7Sent = false;
    di7LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do8_feed.substring(do8_feed.length() - 6, do8_feed.length()))) {
    do8Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(7, !bool(message.toInt()));
    }
    do8_value = message;
    //M5.Lcd.fillRect(90, 40, 300, 50, BLACK);
    //M5.Lcd.drawString(di2_value, 90, 40, 2);
    //replaceText(90, 40, 300, 50, 2 di2_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di8_feedACK.substring(di8_feedACK.length() - 10, di8_feedACK.length()))) {
    di8Recv = true;
    di8Sent = false;
    di8LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao1_feed.substring(ao1_feed.length() - 6, ao1_feed.length()))) {
    ao1Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }

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
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(0));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao1_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai1_feedACK.substring(ai1_feedACK.length() - 10, ai1_feedACK.length()))) {
    ai1Recv = true;
    ai1Sent = false;
    ai1LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao2_feed.substring(ao2_feed.length() - 6, ao2_feed.length()))) {
    ao2Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(1));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }
      
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
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(1));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao2_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai2_feedACK.substring(ai2_feedACK.length() - 10, ai2_feedACK.length()))) {
    ai2Recv = true;
    ai2Sent = false;
    ai2LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao3_feed.substring(ao3_feed.length() - 6, ao3_feed.length()))) {
    ao3Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(2));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }

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
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(2));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao3_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai3_feedACK.substring(ai3_feedACK.length() - 10, ai3_feedACK.length()))) {
    ai3Recv = true;
    ai3Sent = false;
    ai3LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao4_feed.substring(ao4_feed.length() - 6, ao4_feed.length()))) {
    ao4Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(3));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }
      
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
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(3));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao4_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai4_feedACK.substring(ai4_feedACK.length() - 10, ai4_feedACK.length()))) {
    ai4Recv = true;
    ai4Sent = false;
    ai4LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao5_feed.substring(ao5_feed.length() - 6, ao5_feed.length()))) {
    ao5Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }

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
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(0));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao5_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai5_feedACK.substring(ai5_feedACK.length() - 10, ai5_feedACK.length()))) {
    ai5Recv = true;
    ai5Sent = false;
    ai5LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao6_feed.substring(ao6_feed.length() - 6, ao6_feed.length()))) {
    ao6Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(1));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }
      
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
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(1));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao6_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai6_feedACK.substring(ai6_feedACK.length() - 10, ai6_feedACK.length()))) {
    ai6Recv = true;
    ai6Sent = false;
    ai6LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao7_feed.substring(ao7_feed.length() - 6, ao7_feed.length()))) {
    ao7Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(2));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }

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
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(2));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao7_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai7_feedACK.substring(ai7_feedACK.length() - 10, ai7_feedACK.length()))) {
    ai7Recv = true;
    ai7Sent = false;
    ai7LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao8_feed.substring(ao8_feed.length() - 6, ao8_feed.length()))) {
    ao8Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(3));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }
      
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
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(3));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao8_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai8_feedACK.substring(ai8_feedACK.length() - 10, ai8_feedACK.length()))) {
    ai8Recv = true;
    ai8Sent = false;
    ai8LoopCount = 0;
  }
}

void fillCharArray(char* charArray, String string) {
  for (int i = 0; i < string.length(); i++) {
    charArray[i] = string[i];
  }
  charArray[string.length()] = '\0';
}

void configConnect() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("RECEIVING", 65, 120, 1);
  M5.Lcd.drawString("CONFIG INFO", 60, 170, 1);

  delay(500);

  if (startUpMode) {
    commFailCurrentMillis = millis();
    commFailPreviousMillis = commFailCurrentMillis;
    while (Ethernet.begin(mac) == 0) {
      commFailCurrentMillis = millis();
      if (commFailCurrentMillis - commFailPreviousMillis >= commFailInterval && commFailToggledOnce) {
        commFailToggledOnce = false;
        if (digitalDebugSuccess) {
          pcfw2.digitalWrite(0, true);
        }
      }
    }
    commFailToggledOnce = true;
    if (digitalDebugSuccess) {
      pcfw2.digitalWrite(0, false);
    }
    initEthernet();
    Udp.begin(localUDPPort);
    Ethernet.maintain();
    noStartUpConfig = false;
    forceUpdate = true;
  }

  char* ftp_server = new char[ftpBroker.length() + 1];
  fillCharArray(ftp_server, ftpBroker);

  uint16_t ftp_port = stringFtpPort.toInt();

  char* ftp_user = new char[ftpUsername.length() + 1];
  fillCharArray(ftp_user, ftpUsername);

  char* ftp_pass = new char[ftpPassword.length() + 1];
  fillCharArray(ftp_pass, ftpPassword);

  char* dirName = new char[ftpWorkingDirectory.length() + 1];
  fillCharArray(dirName, ftpWorkingDirectory);

  ftp = new FTPClient_Generic (ftp_server, ftp_port, ftp_user, ftp_pass, 60000);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Download the text file or read it
  String response = "";
  ftp->InitFile(COMMAND_XFER_TYPE_ASCII);
  ftp->DownloadString(configFileName.c_str(), response);

  ftp->CloseConnection();

  delete[] ftp_server;
  //delete ftp_port;
  delete[] ftp_user;
  delete[] ftp_pass;
  delete[] dirName;
  delete ftp;


  String FTPKeyword = "";
  for (int i = 0; i < response.length(); i++) {
    String character = response.substring(i, i + 1);
    if (character.equalsIgnoreCase(";")) {
      analyzeFTPFileContents(FTPKeyword);
      FTPKeyword = "";
    }
    else {
      FTPKeyword += character;
    }
  }  

  if (startUpMode) {
    for (int i = 1; i <= IONum.toInt(); i++) {
      String di_feed = groupID + "_" + unitID + "_DI" + i;
      *di_feeds[i - 1] = di_feed;
      String di_feedACK = di_feed + "_ACK";
      *di_feedsACK[i - 1] = di_feedACK;

      String ai_feed = groupID + "_" + unitID + "_AI" + i;
      *ai_feeds[i - 1] = ai_feed;
      String ai_feedACK = ai_feed + "_ACK";
      *ai_feedsACK[i - 1] = ai_feedACK;
    }
  }

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("CONFIG INFO", 40, 0, 1);
  cycleConfigItems(viewConfigItemsIterator);
}

void confConnect() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("RECEIVING", 65, 120, 1);
  M5.Lcd.drawString("CONFIG INFO", 60, 170, 1);

  delay(500);

  char* ftp_server = new char[ftpBroker.length() + 1];
  fillCharArray(ftp_server, ftpBroker);

  uint16_t ftp_port = stringFtpPort.toInt();

  char* ftp_user = new char[ftpUsername.length() + 1];
  fillCharArray(ftp_user, ftpUsername);

  char* ftp_pass = new char[ftpPassword.length() + 1];
  fillCharArray(ftp_pass, ftpPassword);

  char* dirName = new char[ftpWorkingDirectory.length() + 1];
  fillCharArray(dirName, ftpWorkingDirectory);

  ftp = new FTPClient_Generic (ftp_server, ftp_port, ftp_user, ftp_pass, 60000);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Download the text file or read it
  String response = "";
  ftp->InitFile(COMMAND_XFER_TYPE_ASCII);
  ftp->DownloadString(configFileName.c_str(), response);

  ftp->CloseConnection();

  delete[] ftp_server;
  //delete ftp_port;
  delete[] ftp_user;
  delete[] ftp_pass;
  delete[] dirName;
  delete ftp;


  String FTPKeyword = "";
  for (int i = 0; i < response.length(); i++) {
    String character = response.substring(i, i + 1);
    if (character.equalsIgnoreCase(";")) {
      analyzeFTPFileContents(FTPKeyword);
      FTPKeyword = "";
    }
    else {
      FTPKeyword += character;
    }
  }

  for (int i = 1; i <= IONum.toInt(); i++) {
    String di_feed = groupID + "_" + unitID + "_DI" + i;
    *di_feeds[i - 1] = di_feed;
    String di_feedACK = di_feed + "_ACK";
    *di_feedsACK[i - 1] = di_feedACK;

    String ai_feed = groupID + "_" + unitID + "_AI" + i;
    *ai_feeds[i - 1] = ai_feed;
    String ai_feedACK = ai_feed + "_ACK";
    *ai_feedsACK[i - 1] = ai_feedACK;
  }
  ioKnown = false;  

  myFile = SD.open(sdConfigFileName, FILE_WRITE);
  myFile.print(groupID + "_GID;" + unitID + "_UID;" + IONum + "_ION;" + updateTime + "_UPT;" + consumerName + "_CN;" +
  *di_feeds[0] + ";" + *di_feeds[1] + ";" + *di_feeds[2] + ";" + *di_feeds[3] + ";" + *di_feeds[4] + ";" + *di_feeds[5] + ";" + *di_feeds[6] + ";" + *di_feeds[7] + ";" +
  *ai_feeds[0] + ";" + *ai_feeds[1] + ";" + *ai_feeds[2] + ";" + *ai_feeds[3] + ";" + *ai_feeds[4] + ";" + *ai_feeds[5] + ";" + *ai_feeds[6] + ";" + *ai_feeds[7] + ";" +
  do1_feed + "_DO1;" + do2_feed + "_DO2;" + do3_feed + "_DO3;" + do4_feed + "_DO4;" + do5_feed + "_DO5;" + do6_feed + "_DO6;" + do7_feed + "_DO7;" + do8_feed + "_DO8;" +
  ao1_feed + "_AO1;" + ao2_feed + "_AO2;" + ao3_feed + "_AO3;" + ao4_feed + "_AO4;" + ao5_feed + "_AO5;" + ao6_feed + "_AO6;" + ao7_feed + "_AO7;" + ao8_feed + "_AO8;" +
  df1ReadValue + "_DF1;" + df2ReadValue + "_DF2;" + df3ReadValue + "_DF3;" + df4ReadValue + "_DF4;" + df5ReadValue + "_DF5;" + df6ReadValue + "_DF6;" + df7ReadValue + "_DF7;" + df8ReadValue + "_DF8;" +
  af1ReadValue + "_AF1;" + af2ReadValue + "_AF2;" + af3ReadValue + "_AF3;" + af4ReadValue + "_AF4;" + af5ReadValue + "_AF5;" + af6ReadValue + "_AF6;" + af7ReadValue + "_AF7;" + af8ReadValue + "_AF8;" +
  heartbeatSubscriptionsString + "_HB;");
  myFile.close();
  //ESP.restart();

  di1_feed = *di_feeds[0];
  di2_feed = *di_feeds[1];
  di3_feed = *di_feeds[2];
  di4_feed = *di_feeds[3];
  di5_feed = *di_feeds[4];
  di6_feed = *di_feeds[5];
  di7_feed = *di_feeds[6];
  di8_feed = *di_feeds[7];

  ai1_feed = *ai_feeds[0];
  ai2_feed = *ai_feeds[1];
  ai3_feed = *ai_feeds[2];
  ai4_feed = *ai_feeds[3];
  ai5_feed = *ai_feeds[4];
  ai6_feed = *ai_feeds[5];
  ai7_feed = *ai_feeds[6];
  ai8_feed = *ai_feeds[7];

  di1_feedACK = *di_feedsACK[0];
  di2_feedACK = *di_feedsACK[1];
  di3_feedACK = *di_feedsACK[2];
  di4_feedACK = *di_feedsACK[3];
  di5_feedACK = *di_feedsACK[4];
  di6_feedACK = *di_feedsACK[5];
  di7_feedACK = *di_feedsACK[6];
  di8_feedACK = *di_feedsACK[7];

  ai1_feedACK = *ai_feedsACK[0];
  ai2_feedACK = *ai_feedsACK[1];
  ai3_feedACK = *ai_feedsACK[2];
  ai4_feedACK = *ai_feedsACK[3];
  ai5_feedACK = *ai_feedsACK[4];
  ai6_feedACK = *ai_feedsACK[5];
  ai7_feedACK = *ai_feedsACK[6];
  ai8_feedACK = *ai_feedsACK[7];

  normalMode = true;

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
}

// perform the actual update from a given stream
void performUpdate(Stream &updateSource, size_t updateSize) {
  if (Update.begin(updateSize)) {
    size_t written = Update.writeStream(updateSource);
    if (written == updateSize) {
      Serial.println("Written : " + String(written) + " successfully");
    } else {
      Serial.println("Written only : " + String(written) + "/" + String(updateSize) + ". Retry?");
    }
    if (Update.end()) {
      Serial.println("OTA done!");
      if (Update.isFinished()) {
        Serial.println("Update successfully completed. Rebooting.");
      } else {
        Serial.println("Update not finished? Something went wrong!");
      }
    } else {
      Serial.println("Error Occurred. Error #: " + String(Update.getError()));
    }

  } else {
    Serial.println("Not enough space to begin OTA");
  }
}

// check given FS for valid update.bin and perform update if available
void updateFromFS(fs::FS &fs) {
  File updateBin = fs.open("/update.bin");
  if (updateBin) {
    if (updateBin.isDirectory()) {
      Serial.println("Error, update.bin is not a file");
      updateBin.close();
      return;
    }

    size_t updateSize = updateBin.size();

    if (updateSize > 0) {
      Serial.println("Try to start update");
      performUpdate(updateBin, updateSize);
    } else {
      Serial.println("Error, file is empty");
    }

    updateBin.close();

    // when finished remove the binary from sd card to indicate end of the process
    fs.remove("/update.bin");
  } else {
    Serial.println("Could not load update.bin from sd root");
  }
}

void credConnect() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("RECEIVING", 65, 120, 1);
  M5.Lcd.drawString("CRED INFO", 65, 170, 1);

  delay(500);

  char* ftp_server = new char[ftpBroker.length() + 1];
  fillCharArray(ftp_server, ftpBroker);

  uint16_t ftp_port = stringFtpPort.toInt();

  char* ftp_user = new char[ftpUsername.length() + 1];
  fillCharArray(ftp_user, ftpUsername);

  char* ftp_pass = new char[ftpPassword.length() + 1];
  fillCharArray(ftp_pass, ftpPassword);

  char* dirName = new char[ftpWorkingDirectory.length() + 1];
  fillCharArray(dirName, ftpWorkingDirectory);

  ftp = new FTPClient_Generic (ftp_server, ftp_port, ftp_user, ftp_pass, 300000);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Download the text file or read it
  String response = "";
  
  ftp->InitFile(COMMAND_XFER_TYPE_ASCII);
  ftp->DownloadString("creds.txt", response);
  
  ftp->CloseConnection();

  //Dynammically allocate buffer
  unsigned char * downloaded_file = (unsigned char *) malloc(1000000);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Download the text file or read it
  ftp->InitFile(COMMAND_XFER_TYPE_BINARY);
  ftp->DownloadFile("update.bin", downloaded_file, 1000000, false);

  ftp->CloseConnection();

  delete[] ftp_server;
  //delete ftp_port;
  delete[] ftp_user;
  delete[] ftp_pass;
  delete[] dirName;
  delete ftp;


  myFile = SD.open("/update.bin", FILE_WRITE);
  myFile.write(downloaded_file, 1000000);
  myFile.close();


  String FTPKeyword = "";
  for (int i = 0; i < response.length(); i++) {
    String character = response.substring(i, i + 1);
    if (character.equalsIgnoreCase(";")) {
      analyzeFTPFileContents(FTPKeyword);
      FTPKeyword = "";
    }
    else {
      FTPKeyword += character;
    }
  }

  preferences.begin(pnamespace);
  preferences.putString(mqttBrokerKey, mqttBroker);
  preferences.putString(mqttUsernameKey, mqttUsername);
  preferences.putString(mqttPasswordKey, mqttPassword);
  preferences.putString(mqttPortKey, stringMqttPort);
  preferences.putString(ftpBrokerKey, ftpBroker);
  preferences.putString(ftpPortKey, stringFtpPort);
  preferences.putString(ftpUsernameKey, ftpUsername);
  preferences.putString(ftpPasswordKey, ftpPassword);
  preferences.putString(ftpWorkingDirectoryKey, ftpWorkingDirectory);
  preferences.end();

  updateFromFS(SD);

  rebootEspWithReason("FIRMWARE UPDATE");

  normalMode = true;

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
}

void internalConnect() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("RECEIVING", 65, 120, 1);
  M5.Lcd.drawString("INTERNAL INFO", 55, 170, 1);

  delay(500);

  char* ftp_server = new char[ftpBroker.length() + 1];
  fillCharArray(ftp_server, ftpBroker);

  uint16_t ftp_port = stringFtpPort.toInt();

  char* ftp_user = new char[ftpUsername.length() + 1];
  fillCharArray(ftp_user, ftpUsername);

  char* ftp_pass = new char[ftpPassword.length() + 1];
  fillCharArray(ftp_pass, ftpPassword);

  char* dirName = new char[ftpWorkingDirectory.length() + 1];
  fillCharArray(dirName, ftpWorkingDirectory);

  ftp = new FTPClient_Generic (ftp_server, ftp_port, ftp_user, ftp_pass, 60000);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Download the text file or read it
  String response = "";
  ftp->InitFile(COMMAND_XFER_TYPE_ASCII);
  ftp->DownloadString("internal.txt", response);

  ftp->CloseConnection();

  delete[] ftp_server;
  //delete ftp_port;
  delete[] ftp_user;
  delete[] ftp_pass;
  delete[] dirName;
  delete ftp;


  String FTPKeyword = "";
  for (int i = 0; i < response.length(); i++) {
    String character = response.substring(i, i + 1);
    if (character.equalsIgnoreCase(";")) {
      analyzeFTPFileContents(FTPKeyword);
      FTPKeyword = "";
    }
    else {
      FTPKeyword += character;
    }
  }

  preferences.begin(pnamespace);
  preferences.putString(serialKey, serialNumber);
  preferences.putString(macKey, stringMac);
  preferences.end();

  if (serialNumber.length() != 0) {
    *configItems[0] = "SN: " + serialNumber;
  }
  if (stringMac.length() != 0) {
    *configItems[1] = "MAC: " + stringMac.substring(0, stringMac.length() - 1);
  }

  if (stringMac.indexOf(":") != -1) {
    hexCharacterStringToBytes(mac, stringMac.substring(0, stringMac.length() - 1).c_str());
  }

  configFileName = serialNumber + ".txt";
  sdConfigFileName = "/" + configFileName;

  normalMode = true;

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
}

void apiConnect() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("RECEIVING", 65, 120, 1);
  M5.Lcd.drawString("API INFO", 70, 170, 1);

  delay(500);

  char* ftp_server = new char[ftpBroker.length() + 1];
  fillCharArray(ftp_server, ftpBroker);

  uint16_t ftp_port = stringFtpPort.toInt();

  char* ftp_user = new char[ftpUsername.length() + 1];
  fillCharArray(ftp_user, ftpUsername);

  char* ftp_pass = new char[ftpPassword.length() + 1];
  fillCharArray(ftp_pass, ftpPassword);

  char* dirName = new char[ftpWorkingDirectory.length() + 1];
  fillCharArray(dirName, ftpWorkingDirectory);

  ftp = new FTPClient_Generic (ftp_server, ftp_port, ftp_user, ftp_pass, 60000);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Download the text file or read it
  String response = "";
  ftp->InitFile(COMMAND_XFER_TYPE_ASCII);
  ftp->DownloadString("api.txt", response);

  ftp->CloseConnection();

  delete[] ftp_server;
  //delete ftp_port;
  delete[] ftp_user;
  delete[] ftp_pass;
  delete[] dirName;
  delete ftp;


  String FTPKeyword = "";
  for (int i = 0; i < response.length(); i++) {
    String character = response.substring(i, i + 1);
    if (character.equalsIgnoreCase(";")) {
      analyzeFTPFileContents(FTPKeyword);
      FTPKeyword = "";
    }
    else {
      FTPKeyword += character;
    }
  }

  preferences.begin(pnamespace);
  preferences.putString(optAccountIDKey, optAccountID);
  preferences.putString(optApplicationIDKey, optApplicationID);
  preferences.putString(optSecretIDKey, optSecretID);
  preferences.putString(optRadioSNKey, optRadioSN);
  preferences.end();

  normalMode = true;

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
}

// send an NTP request to the time server at the given address
void sendNTPpacket(const char * address) {
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(address, 123); // NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}

void reconnectMqtt() {
  if (!reconnectFirstMessageStatus) {
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);

    M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
    M5.Lcd.drawString(rciTitle, 50, 70, 1);
    M5.Lcd.drawString("ORGANIZING", 60, 120, 1);
    M5.Lcd.drawString("COMMUNICATION DATA", 0, 170, 1);
    reconnectFirstMessageStatus = true;
  }

  publishAllc = false;
  confUpdateStep1 = false;
  confUpdateStep2 = false;
  internalUpdateStep1 = false;
  internalUpdateStep2 = false;
  credUpdateStep1 = false;
  credUpdateStep2 = false;
  apiUpdateStep1 = false;
  apiUpdateStep2 = false;
  confUpdateStep1PubOnce = false;
  confUpdateStep2PubOnce = false;
  internalUpdateStep1PubOnce = false;
  internalUpdateStep2PubOnce = false;
  credUpdateStep1PubOnce = false;
  credUpdateStep2PubOnce = false;
  apiUpdateStep1PubOnce = false;
  apiUpdateStep2PubOnce = false;

  connected_feed_publish = groupID + "_p";
  connected_feed_publishACK = connected_feed_publish + "_ACK";

  connected_feed_subscribe = connected_feed_publish;
  config_update_feed = serialNumber + "_configUpdate";
  internal_update_feed = serialNumber + "_internalUpdate";
  credential_update_feed = serialNumber + "_credUpdate";
  api_update_feed = serialNumber + "_apiUpdate";

  heartbeat_feed = groupID + "_" + unitID + "_" + "HB";
  createHeartbeatSubscriptionArrays(heartbeatSubscriptionsString);

  if (firstTimeGet || getTimeCurrentMillis - getTimePreviousMillis >= getTimeInterval) {
    ethClientSSL.clearWriteError();

    sendNTPpacket(timeServer); // send an NTP packet to a time server

    // wait to see if a reply is available
    delay(1000);
    if (Udp.parsePacket()) {
      udpHasTimePacket = true;
    }

    if (!udpHasTimePacket) {
      sendNTPpacket(timeServer2); // send an NTP packet to a time server

      // wait to see if a reply is available
      delay(1000);
      if (Udp.parsePacket()) {
        udpHasTimePacket = true;
      }
    }

    if (!udpHasTimePacket) {
      sendNTPpacket(timeServer3); // send an NTP packet to a time server

      // wait to see if a reply is available
      delay(1000);
      if (Udp.parsePacket()) {
        udpHasTimePacket = true;
      }
    }

    if (!udpHasTimePacket) {
      sendNTPpacket(timeServer4); // send an NTP packet to a time server

      // wait to see if a reply is available
      delay(1000);
      if (Udp.parsePacket()) {
        udpHasTimePacket = true;
      }
    }

    if (!udpHasTimePacket) {
      sendNTPpacket(timeServer5); // send an NTP packet to a time server

      // wait to see if a reply is available
      delay(1000);
      if (Udp.parsePacket()) {
        udpHasTimePacket = true;
      }
    }

    if (udpHasTimePacket) {
      // We've received a packet, read the data from it
      Udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer

      // the timestamp starts at byte 40 of the received packet and is four bytes,
      // or two words, long. First, extract the two words:

      unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
      unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
      // combine the four bytes (two words) into a long integer
      // this is NTP time (seconds since Jan 1 1900):
      unsigned long secsSince1900 = highWord << 16 | lowWord;
      //Serial.print("Seconds since Jan 1 1900 = ");
      //Serial.println(secsSince1900);

      // now convert NTP time into everyday time:
      //Serial.print("Unix time = ");
      // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
      const unsigned long seventyYears = 2208988800UL;
      // subtract seventy years:
      unsigned long epoch = secsSince1900 - seventyYears;
      // print Unix time:
      //Serial.println(epoch);

      t = epoch;
      ntpMonth = String(month(t));
      ntpDay = String(day(t));
      ntpYear = String(year(t));
      dateString = "DATE: " + ntpMonth + "/" + ntpDay + "/" + ntpYear;

      ethClientSSL.setVerificationTime((unsigned long) (epoch/86400UL) + 719528UL, 0);
      getTimePreviousMillis = getTimeCurrentMillis;
      firstTimeGet = false;
      udpHasTimePacket = false;
    }
  }

  reconnectCount = 0;

  String willPayload = "CONNECTION CHANGE DETECTED!";
  bool willRetain = true;
  int willQos = 0;

  mqttClient.beginWill(willTopic, willPayload.length(), willRetain, willQos);
  mqttClient.print(willPayload);
  mqttClient.endWill();
  
  mqttClient.setId(serialNumber);

  //mqttClient.setUsernamePassword("ADAMMQTT3","Tennis19");
  mqttClient.setUsernamePassword(mqttUsername, mqttPassword);
  
  if (!reconnect) {
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
    M5.Lcd.drawString(rciTitle, 50, 70, 1);
    M5.Lcd.drawString("VERIFYING", 65, 120, 1);
    M5.Lcd.drawString("CONNECTION", 60, 170, 1);
  }

  if (!mqttClient.connect(broker.c_str(), port)) {
    if (!reconnect) {
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
      M5.Lcd.drawString(rciTitle, 50, 70, 1);
      M5.Lcd.drawString("CONNECTION FAILED", 5, 120, 1);
      M5.Lcd.drawString("RETRYING", 85, 170, 1);
      //M5.Lcd.print(mqttClient.connectError());
    }

    reconnect = true;
    return;
  }

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("CONNECTION SUCCESS", 0, 120, 1);
  M5.Lcd.drawString("LOADING", 90, 170, 1);

  // set the message receive callback
  mqttClient.onMessage(onMqttMessage);

  // subscribe to a topic
  // the second parameter sets the QoS of the subscription,
  // the the library supports subscribing at QoS 0, 1, or 2
  int subscribeQos = 0;

  mqttClient.subscribe(connected_feed_subscribe, subscribeQos);
  connected_feed_subscribeACK = connected_feed_subscribe + "_ACK";
  //mqttClient.subscribe(connected_feed_subscribeACK, subscribeQos);
  mqttClient.subscribe(connected_feed_publishACK, subscribeQos);

  mqttClient.subscribe(config_update_feed, subscribeQos);
  //config_update_feedACK = config_update_feed + "_ACK";
  //mqttClient.subscribe(config_update_feedACK, subscribeQos);
  
  mqttClient.subscribe(internal_update_feed, subscribeQos);
  //internal_update_feedACK = internal_update_feed + "_ACK";
  //mqttClient.subscribe(internal_update_feedACK, subscribeQos);
  
  mqttClient.subscribe(credential_update_feed, subscribeQos);
  //credential_update_feedACK = credential_update_feed + "_ACK";
  //mqttClient.subscribe(credential_update_feedACK, subscribeQos);

  mqttClient.subscribe(api_update_feed, subscribeQos);
  //api_update_feedACK = api_update_feed + "_ACK";
  //mqttClient.subscribe(api_update_feedACK, subscribeQos);
  
  if (!do1_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do1_feed, subscribeQos);
    do1_feedACK = do1_feed + "_ACK";
    //mqttClient.subscribe(do1_feedACK, subscribeQos);
  }
  if (!do2_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do2_feed, subscribeQos);
    do2_feedACK = do2_feed + "_ACK";
    //mqttClient.subscribe(do2_feedACK, subscribeQos);
  }
  if (!do3_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do3_feed, subscribeQos);
    do3_feedACK = do3_feed + "_ACK";
    //mqttClient.subscribe(do3_feedACK, subscribeQos);
  }
  if (!do4_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do4_feed, subscribeQos);
    do4_feedACK = do4_feed + "_ACK";
    //mqttClient.subscribe(do4_feedACK, subscribeQos);
  }
  if (!do5_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do5_feed, subscribeQos);
    do5_feedACK = do5_feed + "_ACK";
    //mqttClient.subscribe(do5_feedACK, subscribeQos);
  }
  if (!do6_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do6_feed, subscribeQos);
    do6_feedACK = do6_feed + "_ACK";
    //mqttClient.subscribe(do6_feedACK, subscribeQos);
  }
  if (!do7_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do7_feed, subscribeQos);
    do7_feedACK = do7_feed + "_ACK";
    //mqttClient.subscribe(do7_feedACK, subscribeQos);
  }
  if (!do8_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do8_feed, subscribeQos);
    do8_feedACK = do8_feed + "_ACK";
    //mqttClient.subscribe(do8_feedACK, subscribeQos);
  }
  if (!ao1_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao1_feed, subscribeQos);
    ao1_feedACK = ao1_feed + "_ACK";
    //mqttClient.subscribe(ao1_feedACK, subscribeQos);
  }
  if (!ao2_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao2_feed, subscribeQos);
    ao2_feedACK = ao2_feed + "_ACK";
    //mqttClient.subscribe(ao2_feedACK, subscribeQos);
  }
  if (!ao3_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao3_feed, subscribeQos);
    ao3_feedACK = ao3_feed + "_ACK";
    //mqttClient.subscribe(ao3_feedACK, subscribeQos);
  }
  if (!ao4_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao4_feed, subscribeQos);
    ao4_feedACK = ao4_feed + "_ACK";
    //mqttClient.subscribe(ao4_feedACK, subscribeQos);
  }
  if (!ao5_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao5_feed, subscribeQos);
    ao5_feedACK = ao5_feed + "_ACK";
    //mqttClient.subscribe(ao5_feedACK, subscribeQos);
  }
  if (!ao6_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao6_feed, subscribeQos);
    ao6_feedACK = ao6_feed + "_ACK";
    //mqttClient.subscribe(ao6_feedACK, subscribeQos);
  }
  if (!ao7_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao7_feed, subscribeQos);
    ao7_feedACK = ao7_feed + "_ACK";
    //mqttClient.subscribe(ao7_feedACK, subscribeQos);
  }
  if (!ao8_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao8_feed, subscribeQos);
    ao8_feedACK = ao8_feed + "_ACK";
    //mqttClient.subscribe(ao8_feedACK, subscribeQos);
  }


  if (!di1_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(di1_feedACK, subscribeQos);
  }
  if (!di2_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(di2_feedACK, subscribeQos);
  }
  if (!di3_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(di3_feedACK, subscribeQos);
  }
  if (!di4_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(di4_feedACK, subscribeQos);
  }
  if (!di5_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(di5_feedACK, subscribeQos);
  }
  if (!di6_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(di6_feedACK, subscribeQos);
  }
  if (!di7_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(di7_feedACK, subscribeQos);
  }
  if (!di8_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(di8_feedACK, subscribeQos);
  }
  if (!ai1_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ai1_feedACK, subscribeQos);
  }
  if (!ai2_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ai2_feedACK, subscribeQos);
  }
  if (!ai3_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ai3_feedACK, subscribeQos);
  }
  if (!ai4_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ai4_feedACK, subscribeQos);
  }
  if (!ai5_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ai5_feedACK, subscribeQos);
  }
  if (!ai6_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ai6_feedACK, subscribeQos);
  }
  if (!ai7_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ai7_feedACK, subscribeQos);
  }
  if (!ai8_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ai8_feedACK, subscribeQos);
  }

  for (int i = 0; i < subCount; i++) {
    mqttClient.subscribe(*heartbeat_check_feeds[i], subscribeQos);
  }

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  reconnect = false;
  reconnectFirstMessageStatus = false;

  //M5.Lcd.drawString("DI1: " + di1_value, 10, 0, 2);

  //M5.Lcd.drawString("DI2: " + di2_value, 10, 40, 2);

  //M5.Lcd.drawString("AI1: " + ai1_value, 10, 80, 2);

  //M5.Lcd.drawString("AI2: " + ai2_value, 10, 120, 2);

  cycleCounter = 0;
  cycleComponentValues();

  previousMillis3 = millis();
  previousMillis4 = millis();

  for (int i = 0; i < subCount; i++) {
    heartbeatCheckPreviousMillis[i] = millis();
  }

  heartbeatPublishPreviousMillis = millis();
  publishHeartbeat();
  publishConnected();
}

void analyzeFTPFileContents(String topic) {
  if (topic.indexOf('-') != -1) {
    serialNumber = topic;
    //*configItems[0] = serialNumber;
  }
  if (topic.indexOf(':') != -1) {
    stringMac = topic;
    //*configItems[1] = stringMac.substring(0, stringMac.length() - 1);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("GID")) {
    groupID = topic.substring(0, topic.length() - 4);
    *configItems[2] = "GID: " + groupID;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("UID")) {
    unitID = topic.substring(0, topic.length() - 4);
    *configItems[3] = "UID: " + unitID;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ION")) {
    IONum = topic.substring(0, topic.length() - 4);
    *configItems[4] = "IO#: " + IONum;
    ioKnown = true;
    rciTitle = "RCI-" + IONum + "00-CEL";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("UPT")) {
    updateTime = topic.substring(0, topic.length() - 4);
    *configItems[21] = "UPDATE: " + updateTime;
    interval5 = updateTime.toInt();
    interval6 = updateTime.toInt();
  }
  if (topic.substring(topic.length() - 2, topic.length()).equalsIgnoreCase("CN")) {
    consumerName = topic.substring(0, topic.length() - 3);
    *configItems[24] = "NAME: " + consumerName;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI1")) {
    di1_feed = topic;
    di1_feedACK = di1_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI2")) {
    di2_feed = topic;
    di2_feedACK = di2_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI3")) {
    di3_feed = topic;
    di3_feedACK = di3_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI4")) {
    di4_feed = topic;
    di4_feedACK = di4_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI5")) {
    di5_feed = topic;
    di5_feedACK = di5_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI6")) {
    di6_feed = topic;
    di6_feedACK = di6_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI7")) {
    di7_feed = topic;
    di7_feedACK = di7_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI8")) {
    di8_feed = topic;
    di8_feedACK = di8_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI1")) {
    ai1_feed = topic;
    ai1_feedACK = ai1_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI2")) {
    ai2_feed = topic;
    ai2_feedACK = ai2_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI3")) {
    ai3_feed = topic;
    ai3_feedACK = ai3_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI4")) {
    ai4_feed = topic;
    ai4_feedACK = ai4_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI5")) {
    ai5_feed = topic;
    ai5_feedACK = ai5_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI6")) {
    ai6_feed = topic;
    ai6_feedACK = ai6_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI7")) {
    ai7_feed = topic;
    ai7_feedACK = ai7_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI8")) {
    ai8_feed = topic;
    ai8_feedACK = ai8_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO1")) {
    do1_feed = topic.substring(0, topic.length() - 4);
    *configItems[5] = "DO1: " + do1_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO2")) {
    do2_feed = topic.substring(0, topic.length() - 4);
    *configItems[6] = "DO2: " + do2_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO3")) {
    do3_feed = topic.substring(0, topic.length() - 4);
    *configItems[7] = "DO3: " + do3_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO4")) {
    do4_feed = topic.substring(0, topic.length() - 4);
    *configItems[8] = "DO4: " + do4_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO5")) {
    do5_feed = topic.substring(0, topic.length() - 4);
    *configItems[9] = "DO5: " + do5_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO6")) {
    do6_feed = topic.substring(0, topic.length() - 4);
    *configItems[10] = "DO6: " + do6_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO7")) {
    do7_feed = topic.substring(0, topic.length() - 4);
    *configItems[11] = "DO7: " + do7_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO8")) {
    do8_feed = topic.substring(0, topic.length() - 4);
    *configItems[12] = "DO8: " + do8_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO1")) {
    ao1_feed = topic.substring(0, topic.length() - 4);
    *configItems[13] = "AO1: " + ao1_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO2")) {
    ao2_feed = topic.substring(0, topic.length() - 4);
    *configItems[14] = "AO2: " + ao2_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO3")) {
    ao3_feed = topic.substring(0, topic.length() - 4);
    *configItems[15] = "AO3: " + ao3_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO4")) {
    ao4_feed = topic.substring(0, topic.length() - 4);
    *configItems[16] = "AO4: " + ao4_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO5")) {
    ao5_feed = topic.substring(0, topic.length() - 4);
    *configItems[17] = "AO5: " + ao5_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO6")) {
    ao6_feed = topic.substring(0, topic.length() - 4);
    *configItems[18] = "AO6: " + ao6_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO7")) {
    ao7_feed = topic.substring(0, topic.length() - 4);
    *configItems[19] = "AO7: " + ao7_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO8")) {
    ao8_feed = topic.substring(0, topic.length() - 4);
    *configItems[20] = "AO8: " + ao8_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MBR")) {
    mqttBroker = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MUN")) {
    mqttUsername = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MPW")) {
    mqttPassword = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MPT")) {
    stringMqttPort = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FBR")) {
    ftpBroker = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FPT")) {
    stringFtpPort = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FUN")) {
    ftpUsername = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FPW")) {
    ftpPassword = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FWD")) {
    ftpWorkingDirectory = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ACC")) {
    optAccountID = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("APP")) {
    optApplicationID = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("SEC")) {
    optSecretID = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("RSN")) {
    optRadioSN = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF1")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df1ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do1_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do1_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do1_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF2")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df2ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do2_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do2_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do2_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF3")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df3ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do3_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do3_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do3_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF4")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df4ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do4_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do4_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do4_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF5")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df5ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do5_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do5_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do5_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF6")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df6ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do6_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do6_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do6_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF7")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df7ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do7_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do7_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do7_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF8")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df8ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do8_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do8_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do8_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF1")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af1ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao1_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao1_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF2")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af2ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao2_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao2_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF3")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af3ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao3_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao3_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF4")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af4ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao4_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao4_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF5")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af5ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao5_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao5_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF6")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af6ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao6_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao6_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF7")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af7ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao7_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao7_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF8")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af8ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao8_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao8_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 2, topic.length()).equalsIgnoreCase("HB")) {
    heartbeatSubscriptionsString = topic.substring(0, topic.length() - 3);
  }
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
    //*configItems[0] = serialNumber;
  }
  if (topic.indexOf(':') != -1) {
    stringMac = topic;
    //*configItems[1] = stringMac.substring(0, stringMac.length() - 1);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("GID")) {
    groupID = topic.substring(0, topic.length() - 4);
    *configItems[2] = "GID: " + groupID;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("UID")) {
    unitID = topic.substring(0, topic.length() - 4);
    *configItems[3] = "UID: " + unitID;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ION")) {
    IONum = topic.substring(0, topic.length() - 4);
    *configItems[4] = "IO#: " + IONum;
    rciTitle = "RCI-" + IONum + "00-CEL";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("UPT")) {
    updateTime = topic.substring(0, topic.length() - 4);
    *configItems[21] = "UPDATE: " + updateTime;
    interval5 = updateTime.toInt();
    interval6 = updateTime.toInt();
  }
  if (topic.substring(topic.length() - 2, topic.length()).equalsIgnoreCase("CN")) {
    consumerName = topic.substring(0, topic.length() - 3);
    *configItems[24] = "NAME: " + consumerName;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI1")) {
    di1_feed = topic;
    di1_feedACK = di1_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI2")) {
    di2_feed = topic;
    di2_feedACK = di2_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI3")) {
    di3_feed = topic;
    di3_feedACK = di3_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI4")) {
    di4_feed = topic;
    di4_feedACK = di4_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI5")) {
    di5_feed = topic;
    di5_feedACK = di5_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI6")) {
    di6_feed = topic;
    di6_feedACK = di6_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI7")) {
    di7_feed = topic;
    di7_feedACK = di7_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI8")) {
    di8_feed = topic;
    di8_feedACK = di8_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI1")) {
    ai1_feed = topic;
    ai1_feedACK = ai1_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI2")) {
    ai2_feed = topic;
    ai2_feedACK = ai2_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI3")) {
    ai3_feed = topic;
    ai3_feedACK = ai3_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI4")) {
    ai4_feed = topic;
    ai4_feedACK = ai4_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI5")) {
    ai5_feed = topic;
    ai5_feedACK = ai5_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI6")) {
    ai6_feed = topic;
    ai6_feedACK = ai6_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI7")) {
    ai7_feed = topic;
    ai7_feedACK = ai7_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI8")) {
    ai8_feed = topic;
    ai8_feedACK = ai8_feed + "_ACK";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO1")) {
    do1_feed = topic.substring(0, topic.length() - 4);
    *configItems[5] = "DO1: " + do1_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO2")) {
    do2_feed = topic.substring(0, topic.length() - 4);
    *configItems[6] = "DO2: " + do2_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO3")) {
    do3_feed = topic.substring(0, topic.length() - 4);
    *configItems[7] = "DO3: " + do3_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO4")) {
    do4_feed = topic.substring(0, topic.length() - 4);
    *configItems[8] = "DO4: " + do4_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO5")) {
    do5_feed = topic.substring(0, topic.length() - 4);
    *configItems[9] = "DO5: " + do5_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO6")) {
    do6_feed = topic.substring(0, topic.length() - 4);
    *configItems[10] = "DO6: " + do6_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO7")) {
    do7_feed = topic.substring(0, topic.length() - 4);
    *configItems[11] = "DO7: " + do7_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO8")) {
    do8_feed = topic.substring(0, topic.length() - 4);
    *configItems[12] = "DO8: " + do8_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO1")) {
    ao1_feed = topic.substring(0, topic.length() - 4);
    *configItems[13] = "AO1: " + ao1_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO2")) {
    ao2_feed = topic.substring(0, topic.length() - 4);
    *configItems[14] = "AO2: " + ao2_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO3")) {
    ao3_feed = topic.substring(0, topic.length() - 4);
    *configItems[15] = "AO3: " + ao3_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO4")) {
    ao4_feed = topic.substring(0, topic.length() - 4);
    *configItems[16] = "AO4: " + ao4_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO5")) {
    ao5_feed = topic.substring(0, topic.length() - 4);
    *configItems[17] = "AO5: " + ao5_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO6")) {
    ao6_feed = topic.substring(0, topic.length() - 4);
    *configItems[18] = "AO6: " + ao6_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO7")) {
    ao7_feed = topic.substring(0, topic.length() - 4);
    *configItems[19] = "AO7: " + ao7_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO8")) {
    ao8_feed = topic.substring(0, topic.length() - 4);
    *configItems[20] = "AO8: " + ao8_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MBR")) {
    mqttBroker = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MUN")) {
    mqttUsername = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MPW")) {
    mqttPassword = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MPT")) {
    stringMqttPort = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FBR")) {
    ftpBroker = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FPT")) {
    stringFtpPort = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FUN")) {
    ftpUsername = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FPW")) {
    ftpPassword = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FWD")) {
    ftpWorkingDirectory = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ACC")) {
    optAccountID = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("APP")) {
    optApplicationID = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("SEC")) {
    optSecretID = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("RSN")) {
    optRadioSN = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF1")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df1ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do1_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do1_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do1_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF2")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df2ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do2_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do2_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do2_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF3")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df3ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do3_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do3_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do3_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF4")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df4ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do4_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do4_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do4_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF5")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df5ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do5_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do5_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do5_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF6")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df6ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do6_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do6_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do6_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF7")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df7ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do7_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do7_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do7_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF8")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df8ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do8_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do8_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do8_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF1")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af1ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao1_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao1_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF2")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af2ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao2_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao2_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF3")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af3ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao3_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao3_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF4")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af4ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao4_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao4_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF5")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af5ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao5_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao5_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF6")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af6ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao6_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao6_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF7")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af7ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao7_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao7_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF8")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af8ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao8_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao8_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 2, topic.length()).equalsIgnoreCase("HB")) {
    heartbeatSubscriptionsString = topic.substring(0, topic.length() - 3);
  }
}

void createHeartbeatSubscriptionArrays(String subscriptions) {
  subCount = 0;
  heartbeatCheckUnitID = String("");
  for (int i = 0; i < subscriptions.length(); i++) {
    if (subscriptions[i] == ',' && subCount < maxHeartbeatChecks) {
      *heartbeat_check_feeds[subCount] = groupID + "_" + heartbeatCheckUnitID + "_" + "HB";
      heartbeatCheckPreviousMillis[subCount] = 1;
      heartbeatCheckCurrentMillis[subCount] = 1;
      subCount++;
      heartbeatCheckUnitID = String("");
    } else {
      heartbeatCheckUnitID += subscriptions[i];
    }
  }
  if (heartbeatCheckUnitID.length() != 0 && subCount < maxHeartbeatChecks) {
    *heartbeat_check_feeds[subCount] = groupID + "_" + heartbeatCheckUnitID + "_" + "HB";
    heartbeatCheckPreviousMillis[subCount] = 1;
    heartbeatCheckCurrentMillis[subCount] = 1;
    subCount++;
    heartbeatCheckUnitID = String("");
  }
}

void checkHeartbeatSubscriptionArrays(String subscription) {
  for (int i = 0; i < subCount; i++) {
    String tempHeartbeatCheckFeed = *heartbeat_check_feeds[i];
    if (tempHeartbeatCheckFeed.substring(tempHeartbeatCheckFeed.indexOf("_") + 1, tempHeartbeatCheckFeed.indexOf("_", tempHeartbeatCheckFeed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
      heartbeatCheckPreviousMillis[i] = millis();
      heartbeatCheckAlreadySetFailDefaults[i] = false;
    }
  }

  if (IONum.toInt() >= 1) {
    if (analogOutOneSuccess) {
      if (ao1_feed.substring(ao1_feed.indexOf("_") + 1, ao1_feed.indexOf("_", ao1_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao1CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do1_feed.substring(do1_feed.indexOf("_") + 1, do1_feed.indexOf("_", do1_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do1CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 2) {
    if (analogOutOneSuccess) {
      if (ao2_feed.substring(ao2_feed.indexOf("_") + 1, ao2_feed.indexOf("_", ao2_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao2CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do2_feed.substring(do2_feed.indexOf("_") + 1, do2_feed.indexOf("_", do2_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do2CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 3) {
    if (analogOutOneSuccess) {
      if (ao3_feed.substring(ao3_feed.indexOf("_") + 1, ao3_feed.indexOf("_", ao3_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao3CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do3_feed.substring(do3_feed.indexOf("_") + 1, do3_feed.indexOf("_", do3_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do3CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 4) {
    if (analogOutOneSuccess) {
      if (ao4_feed.substring(ao4_feed.indexOf("_") + 1, ao4_feed.indexOf("_", ao4_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao4CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do4_feed.substring(do4_feed.indexOf("_") + 1, do4_feed.indexOf("_", do4_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do4CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 5) {
    if (analogOutTwoSuccess) {
      if (ao5_feed.substring(ao5_feed.indexOf("_") + 1, ao5_feed.indexOf("_", ao5_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao5CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do5_feed.substring(do5_feed.indexOf("_") + 1, do5_feed.indexOf("_", do5_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do5CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 6) {
    if (analogOutTwoSuccess) {
      if (ao6_feed.substring(ao6_feed.indexOf("_") + 1, ao6_feed.indexOf("_", ao6_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao6CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do6_feed.substring(do6_feed.indexOf("_") + 1, do6_feed.indexOf("_", do6_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do6CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 7) {
    if (analogOutTwoSuccess) {
      if (ao7_feed.substring(ao7_feed.indexOf("_") + 1, ao7_feed.indexOf("_", ao7_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao7CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do7_feed.substring(do7_feed.indexOf("_") + 1, do7_feed.indexOf("_", do7_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do7CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 8) {
    if (analogOutTwoSuccess) {
      if (ao8_feed.substring(ao8_feed.indexOf("_") + 1, ao8_feed.indexOf("_", ao8_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao8CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do8_feed.substring(do8_feed.indexOf("_") + 1, do8_feed.indexOf("_", do8_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do8CommFailTriggered = false;
      }
    }
  }
}

void setGroupMemberLossOfCommunicationDefaults(String subscription) {
  if (IONum.toInt() >= 1) {
    if (analogOutOneSuccess) {
      if (ao1_feed.substring(ao1_feed.indexOf("_") + 1, ao1_feed.indexOf("_", ao1_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao1_fail_default != 30.0) {
          Wire.beginTransmission(0x1f);
          Wire.write(byte(0));
          Wire.write(byte(int(ao1_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao1_fail_default * 3276.75)));
          Wire.endTransmission();
          ao1_value = String(int(ao1_fail_default * 3276.75));
        }
        ao1CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do1_feed.substring(do1_feed.indexOf("_") + 1, do1_feed.indexOf("_", do1_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do1_fail_default != 2) {
          pcfw1.digitalWrite(0, !bool(do1_fail_default));
          do1_value = String(do1_fail_default);
        }
        do1CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 2) {
    if (analogOutOneSuccess) {
      if (ao2_feed.substring(ao2_feed.indexOf("_") + 1, ao2_feed.indexOf("_", ao2_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao2_fail_default != 30.0) {
          Wire.beginTransmission(0x1f);
          Wire.write(byte(1));
          Wire.write(byte(int(ao2_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao2_fail_default * 3276.75)));
          Wire.endTransmission();
          ao2_value = String(int(ao2_fail_default * 3276.75));
        }
        ao2CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do2_feed.substring(do2_feed.indexOf("_") + 1, do2_feed.indexOf("_", do2_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do2_fail_default != 2) {
          pcfw1.digitalWrite(1, !bool(do2_fail_default));
          do2_value = String(do2_fail_default);
        }
        do2CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 3) {
    if (analogOutOneSuccess) {
      if (ao3_feed.substring(ao3_feed.indexOf("_") + 1, ao3_feed.indexOf("_", ao3_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao3_fail_default != 30.0) {
          Wire.beginTransmission(0x1f);
          Wire.write(byte(2));
          Wire.write(byte(int(ao3_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao3_fail_default * 3276.75)));
          Wire.endTransmission();
          ao3_value = String(int(ao3_fail_default * 3276.75));
        }
        ao3CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do3_feed.substring(do3_feed.indexOf("_") + 1, do3_feed.indexOf("_", do3_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do3_fail_default != 2) {
          pcfw1.digitalWrite(2, !bool(do3_fail_default));
          do3_value = String(do3_fail_default);
        }
        do3CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 4) {
    if (analogOutOneSuccess) {
      if (ao4_feed.substring(ao4_feed.indexOf("_") + 1, ao4_feed.indexOf("_", ao4_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao4_fail_default != 30.0) {
          Wire.beginTransmission(0x1f);
          Wire.write(byte(3));
          Wire.write(byte(int(ao4_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao4_fail_default * 3276.75)));
          Wire.endTransmission();
          ao4_value = String(int(ao4_fail_default * 3276.75));
        }
        ao4CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do4_feed.substring(do4_feed.indexOf("_") + 1, do4_feed.indexOf("_", do4_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do4_fail_default != 2) {
          pcfw1.digitalWrite(3, !bool(do4_fail_default));
          do4_value = String(do4_fail_default);
        }
        do4CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 5) {
    if (analogOutTwoSuccess) {
      if (ao5_feed.substring(ao5_feed.indexOf("_") + 1, ao5_feed.indexOf("_", ao5_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao5_fail_default != 30.0) {
          Wire.beginTransmission(0x1c);
          Wire.write(byte(0));
          Wire.write(byte(int(ao5_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao5_fail_default * 3276.75)));
          Wire.endTransmission();
          ao5_value = String(int(ao5_fail_default * 3276.75));
        }
        ao5CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do5_feed.substring(do5_feed.indexOf("_") + 1, do5_feed.indexOf("_", do5_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do5_fail_default != 2) {
          pcfw1.digitalWrite(4, !bool(do5_fail_default));
          do5_value = String(do5_fail_default);
        }
        do5CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 6) {
    if (analogOutTwoSuccess) {
      if (ao6_feed.substring(ao6_feed.indexOf("_") + 1, ao6_feed.indexOf("_", ao6_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao6_fail_default != 30.0) {
          Wire.beginTransmission(0x1c);
          Wire.write(byte(1));
          Wire.write(byte(int(ao6_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao6_fail_default * 3276.75)));
          Wire.endTransmission();
          ao6_value = String(int(ao6_fail_default * 3276.75));
        }
        ao6CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do6_feed.substring(do6_feed.indexOf("_") + 1, do6_feed.indexOf("_", do6_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do6_fail_default != 2) {
          pcfw1.digitalWrite(5, !bool(do6_fail_default));
          do6_value = String(do6_fail_default);
        }
        do6CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 7) {
    if (analogOutTwoSuccess) {
      if (ao7_feed.substring(ao7_feed.indexOf("_") + 1, ao7_feed.indexOf("_", ao7_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao7_fail_default != 30.0) {
          Wire.beginTransmission(0x1c);
          Wire.write(byte(2));
          Wire.write(byte(int(ao7_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao7_fail_default * 3276.75)));
          Wire.endTransmission();
          ao7_value = String(int(ao7_fail_default * 3276.75));
        }
        ao7CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do7_feed.substring(do7_feed.indexOf("_") + 1, do7_feed.indexOf("_", do7_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do7_fail_default != 2) {
          pcfw1.digitalWrite(6, !bool(do7_fail_default));
          do7_value = String(do7_fail_default);
        }
        do7CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 8) {
    if (analogOutTwoSuccess) {
      if (ao8_feed.substring(ao8_feed.indexOf("_") + 1, ao8_feed.indexOf("_", ao8_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao8_fail_default != 30.0) {
          Wire.beginTransmission(0x1c);
          Wire.write(byte(3));
          Wire.write(byte(int(ao8_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao8_fail_default * 3276.75)));
          Wire.endTransmission();
          ao8_value = String(int(ao8_fail_default * 3276.75));
        }
        ao8CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do8_feed.substring(do8_feed.indexOf("_") + 1, do8_feed.indexOf("_", do8_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do8_fail_default != 2) {
          pcfw1.digitalWrite(7, !bool(do8_fail_default));
          do8_value = String(do8_fail_default);
        }
        do8CommFailTriggered = true;
      }
    }
  }
}

void hexCharacterStringToBytes(byte *byteArray, const char *hexString) {
  bool oddLength = strlen(hexString) & 1;

  byte currentByte = 0;
  int byteIndex = 0;

  for (int charIndex = 0; charIndex < strlen(hexString); charIndex++) {
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

/*
void toggleResetClock() {
  digitalWrite(25, HIGH); // sets the digital pin 25 on
  delay(50);
  digitalWrite(25, LOW);  // sets the digital pin 25 off
  delay(50);
}
*/

void returnToNormalOperation() {
  cycleCounter = 0;
  triggerSound = false;
  normalMode = true;
  cfgServerMode = false;
  copyMode = false;
  configMenu1 = false;
  configMenu2 = false;
  configMenu3 = false;
  warningMenu1 = false;
  warningMenu2 = false;
  centerPressedOnce = false;
  leftPressedOnce = false;
  leftPressedTwice = false;
  leftPressedThree = false;
  rightPressedOnce = false;
  rightPressedTwice = false;
  rightPressedThree = false;
  rightPressedFour = false;
  viewConfigItemsIterator = 0;
  configMenu1Iterator = 0;
  firstConfigAo1Press = true;
  configAo1Counter = 0;
  configAo1Value = 0;
  configAo2Value = 0;
  hasConfigInfo = true;
  ioKnown = false;

  M5.Lcd.fillRect(10, 190, 300, 50, BLACK);
  M5.Lcd.drawString("NORMAL MODE", 10, 200, 1);

  //mcp.setChannelValue(MCP4728_CHANNEL_A, (ai1_value.toInt() * 2) >> 4, MCP4728_VREF_INTERNAL,
  //                  MCP4728_GAIN_2X);
  //mcp.setChannelValue(MCP4728_CHANNEL_B, (ai2_value.toInt() * 2) >> 4, MCP4728_VREF_INTERNAL,
  //                  MCP4728_GAIN_2X);

  if (digitalOutputSuccess) {
    pcfw1.digitalWrite(0, !bool(do1_value.toInt()));
    pcfw1.digitalWrite(1, !bool(do2_value.toInt()));
    pcfw1.digitalWrite(2, !bool(do3_value.toInt()));
    pcfw1.digitalWrite(3, !bool(do4_value.toInt()));
    pcfw1.digitalWrite(4, !bool(do5_value.toInt()));
    pcfw1.digitalWrite(5, !bool(do6_value.toInt()));
    pcfw1.digitalWrite(6, !bool(do7_value.toInt()));
    pcfw1.digitalWrite(7, !bool(do8_value.toInt()));
  }
      
  if (analogOutOneSuccess) {
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

    Wire.beginTransmission(0x1f);
    Wire.write(byte(2));
    Wire.write(byte(ao3_value.toInt() >> 8));
    Wire.write(byte(ao3_value.toInt()));
    Wire.endTransmission();

    Wire.beginTransmission(0x1f);
    Wire.write(byte(3));
    Wire.write(byte(ao4_value.toInt() >> 8));
    Wire.write(byte(ao4_value.toInt()));
    Wire.endTransmission();
  }

  if (analogOutTwoSuccess) {
    Wire.beginTransmission(0x1c);
    Wire.write(byte(0));
    Wire.write(byte(ao5_value.toInt() >> 8));
    Wire.write(byte(ao5_value.toInt()));
    Wire.endTransmission();

    Wire.beginTransmission(0x1c);
    Wire.write(byte(1));
    Wire.write(byte(ao6_value.toInt() >> 8));
    Wire.write(byte(ao6_value.toInt()));
    Wire.endTransmission();

    Wire.beginTransmission(0x1c);
    Wire.write(byte(2));
    Wire.write(byte(ao7_value.toInt() >> 8));
    Wire.write(byte(ao7_value.toInt()));
    Wire.endTransmission();

    Wire.beginTransmission(0x1c);
    Wire.write(byte(3));
    Wire.write(byte(ao8_value.toInt() >> 8));
    Wire.write(byte(ao8_value.toInt()));
    Wire.endTransmission();
  }
      
  if (digitalDebugSuccess) {
    pcfw2.digitalWrite(0, false);
  }

  for (int i = 1; i <= IONum.toInt(); i++) {
    String di_feed = groupID + "_" + unitID + "_DI" + i;
    *di_feeds[i - 1] = di_feed;
    String di_feedACK = di_feed + "_ACK";
    *di_feedsACK[i - 1] = di_feedACK;

    String ai_feed = groupID + "_" + unitID + "_AI" + i;
    *ai_feeds[i - 1] = ai_feed;
    String ai_feedACK = ai_feed + "_ACK";
    *ai_feedsACK[i - 1] = ai_feedACK;
  }

  myFile = SD.open(sdConfigFileName, FILE_WRITE);
  myFile.print(groupID + "_GID;" + unitID + "_UID;" + IONum + "_ION;" + updateTime + "_UPT;" + consumerName + "_CN;" +
  *di_feeds[0] + ";" + *di_feeds[1] + ";" + *di_feeds[2] + ";" + *di_feeds[3] + ";" + *di_feeds[4] + ";" + *di_feeds[5] + ";" + *di_feeds[6] + ";" + *di_feeds[7] + ";" +
  *ai_feeds[0] + ";" + *ai_feeds[1] + ";" + *ai_feeds[2] + ";" + *ai_feeds[3] + ";" + *ai_feeds[4] + ";" + *ai_feeds[5] + ";" + *ai_feeds[6] + ";" + *ai_feeds[7] + ";" +
  do1_feed + "_DO1;" + do2_feed + "_DO2;" + do3_feed + "_DO3;" + do4_feed + "_DO4;" + do5_feed + "_DO5;" + do6_feed + "_DO6;" + do7_feed + "_DO7;" + do8_feed + "_DO8;" +
  ao1_feed + "_AO1;" + ao2_feed + "_AO2;" + ao3_feed + "_AO3;" + ao4_feed + "_AO4;" + ao5_feed + "_AO5;" + ao6_feed + "_AO6;" + ao7_feed + "_AO7;" + ao8_feed + "_AO8;" +
  df1ReadValue + "_DF1;" + df2ReadValue + "_DF2;" + df3ReadValue + "_DF3;" + df4ReadValue + "_DF4;" + df5ReadValue + "_DF5;" + df6ReadValue + "_DF6;" + df7ReadValue + "_DF7;" + df8ReadValue + "_DF8;" +
  af1ReadValue + "_AF1;" + af2ReadValue + "_AF2;" + af3ReadValue + "_AF3;" + af4ReadValue + "_AF4;" + af5ReadValue + "_AF5;" + af6ReadValue + "_AF6;" + af7ReadValue + "_AF7;" + af8ReadValue + "_AF8;" +
  heartbeatSubscriptionsString + "_HB;");
  myFile.close();
  //ESP.restart();

  di1_feed = *di_feeds[0];
  di2_feed = *di_feeds[1];
  di3_feed = *di_feeds[2];
  di4_feed = *di_feeds[3];
  di5_feed = *di_feeds[4];
  di6_feed = *di_feeds[5];
  di7_feed = *di_feeds[6];
  di8_feed = *di_feeds[7];

  ai1_feed = *ai_feeds[0];
  ai2_feed = *ai_feeds[1];
  ai3_feed = *ai_feeds[2];
  ai4_feed = *ai_feeds[3];
  ai5_feed = *ai_feeds[4];
  ai6_feed = *ai_feeds[5];
  ai7_feed = *ai_feeds[6];
  ai8_feed = *ai_feeds[7];

  di1_feedACK = *di_feedsACK[0];
  di2_feedACK = *di_feedsACK[1];
  di3_feedACK = *di_feedsACK[2];
  di4_feedACK = *di_feedsACK[3];
  di5_feedACK = *di_feedsACK[4];
  di6_feedACK = *di_feedsACK[5];
  di7_feedACK = *di_feedsACK[6];
  di8_feedACK = *di_feedsACK[7];

  ai1_feedACK = *ai_feedsACK[0];
  ai2_feedACK = *ai_feedsACK[1];
  ai3_feedACK = *ai_feedsACK[2];
  ai4_feedACK = *ai_feedsACK[3];
  ai5_feedACK = *ai_feedsACK[4];
  ai6_feedACK = *ai_feedsACK[5];
  ai7_feedACK = *ai_feedsACK[6];
  ai8_feedACK = *ai_feedsACK[7];

  delay(1000);
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
}

void requestAPIAccess() {
  apiString = String("");
  onSignalClientDisconnect = true;

  // connect to SUMMIT API on port 443:
  if (signalClient.connect(HOST_NAME, HTTP_PORT)) {
    // if connected:
    Serial.println("Connected to server");

    // make a json document:
    JsonDocument doc;
    // Add values in the document
    //
    doc["accountId"] = optAccountID.toInt();
    doc["applicationId"] = optApplicationID.toInt();
    doc["secret"] = optSecretID;
     
    String requestBody;
    serializeJson(doc, requestBody);

    // make a HTTP request:
    // send HTTP header
    signalClient.print(HTTP_POST_METHOD + " " + AUTH_PATH_NAME + " HTTP/1.1\r\n");
    signalClient.print("Host: " + String(HOST_NAME) + "\r\n");
    signalClient.print("Content-Type: application/json\r\n");
    signalClient.print("Content-Length: " + String(requestBody.length()) + "\r\n");
    signalClient.print("Connection: close\r\n");
    signalClient.print("\r\n"); // end HTTP header

    // debug HTTP header
    Serial.print(HTTP_POST_METHOD + " " + AUTH_PATH_NAME + " HTTP/1.1\r\n");
    Serial.print("Host: " + String(HOST_NAME) + "\r\n");
    Serial.print("Content-Type: application/json\r\n");
    Serial.print("Content-Length: " + String(requestBody.length()) + "\r\n");
    Serial.print("Connection: close\r\n");
    Serial.print("\r\n"); // end HTTP header

    // send HTTP body
    //signalClient.print("{\r\n\"accountId\": " + optAccountID + ",\r\n\"applicationId\": " + optApplicationID + ",\r\n\"secret\": \"" + optSecretID + "\"\r\n}\r\n");
    signalClient.print(requestBody + "\r\n");

    // debug HTTP body
    //Serial.print("{\r\n\"accountId\": " + optAccountID + ",\r\n\"applicationId\": " + optApplicationID + ",\r\n\"secret\": \"" + optSecretID + "\"\r\n}\r\n");
    Serial.print(requestBody + "\r\n");
  } else {// if not connected:
    Serial.println("connection failed");
  }
}

void backgroundReceiveAPIKey() {
  if (signalClient.connected()) {
    if (signalClient.available()) {
      // read an incoming byte from the server and print it to serial monitor:
      char c = signalClient.read();

      Serial.print(c);

      apiString += c;
    }
  } else if (onSignalClientDisconnect) {
    onSignalClientDisconnect = false;

    // the server's disconnected, stop the signalClient:
    signalClient.stop();
    Serial.println();
    Serial.println("disconnected");

    if (apiString.length() > 0) {
      optAPIKey = apiString.substring(apiString.indexOf("apiKey") + 9, apiString.indexOf("\"", apiString.indexOf("apiKey") + 9));
      optAPIToken = apiString.substring(apiString.indexOf("token") + 8, apiString.indexOf("\"", apiString.indexOf("token") + 8));

      if ((apiString.indexOf("apiKey") != -1) && (apiString.indexOf("token") != -1)) {
        apiAccessGranted = true;
      }
    }

    Serial.println("API KEY: " + optAPIKey);
    Serial.println("API TOKEN: " + optAPIToken);
  }
}

void requestCellModemRefresh() {
  refreshString = String("");
  onSignalClientDisconnect = true;

  // connect to SUMMIT API on port 443:
  if (signalClient.connect(HOST_NAME, HTTP_PORT)) {
    // if connected:
    Serial.println("Connected to server");
    // make a HTTP request:
    // send HTTP header
    signalClient.print(HTTP_GET_METHOD + " " + REFRESH_PATH_NAME + optSummitID + " HTTP/1.1\r\n");
    signalClient.print("Host: " + String(HOST_NAME) + "\r\n");
    signalClient.print("Authorization: " + optAPIToken + "\r\n");
    signalClient.print("x-api-key: " + optAPIKey + "\r\n");
    signalClient.print("Connection: close\r\n");
    signalClient.print("\r\n"); // end HTTP header

    // debug HTTP header
    Serial.print(HTTP_GET_METHOD + " " + REFRESH_PATH_NAME + optSummitID + " HTTP/1.1\r\n");
    Serial.print("Host: " + String(HOST_NAME) + "\r\n");
    Serial.print("Authorization: " + optAPIToken + "\r\n");
    Serial.print("x-api-key: " + optAPIKey + "\r\n");
    Serial.print("Connection: close\r\n");
    Serial.print("\r\n"); // end HTTP header

  } else {// if not connected:
    cellModemRefreshSuccessful = false;
    Serial.println("connection failed");
  }
}

void backgroundReceiveCellModemRefresh() {
  if (signalClient.connected()) {
    if (signalClient.available()) {
      // read an incoming byte from the server and print it to serial monitor:
      char c = signalClient.read();

      Serial.print(c);

      refreshString += c;
    }
  } else if (onSignalClientDisconnect) {
    onSignalClientDisconnect = false;

    // the server's disconnected, stop the signalClient:
    signalClient.stop();
    Serial.println();
    Serial.println("disconnected");

    if (refreshString.indexOf("statusKey") != -1) {
      cellModemRefreshSuccessful = true;
    } else {
      cellModemRefreshSuccessful = false;
    }

    receivingSignalQuality = true;
    requestCellularSignalQuality();
  }
}

void requestCellularSignalQuality() {
  statusString = String("");
  onSignalClientDisconnect = true;

  // connect to SUMMIT API on port 443:
  if (signalClient.connect(HOST_NAME, HTTP_PORT)) {
    // if connected:
    Serial.println("Connected to server");
    // make a HTTP request:
    // send HTTP header
    signalClient.print(HTTP_GET_METHOD + " " + INFO_PATH_NAME + optRadioSN + " HTTP/1.1\r\n");
    signalClient.print("Host: " + String(HOST_NAME) + "\r\n");
    signalClient.print("Authorization: " + optAPIToken + "\r\n");
    signalClient.print("x-api-key: " + optAPIKey + "\r\n");
    signalClient.print("Connection: close\r\n");
    signalClient.print("\r\n"); // end HTTP header

    // debug HTTP header
    Serial.print(HTTP_GET_METHOD + " " + INFO_PATH_NAME + optRadioSN + " HTTP/1.1\r\n");
    Serial.print("Host: " + String(HOST_NAME) + "\r\n");
    Serial.print("Authorization: " + optAPIToken + "\r\n");
    Serial.print("x-api-key: " + optAPIKey + "\r\n");
    Serial.print("Connection: close\r\n");
    Serial.print("\r\n"); // end HTTP header

  } else {// if not connected:
    signalQualityCheckSuccessful = false;
    Serial.println("connection failed");
  }
}

void backgroundReceiveCellularSignalQuality(bool displayBars) {
  if (signalClient.connected()) {
    if (signalClient.available()) {
      // read an incoming byte from the server and print it to serial monitor:
      char c = signalClient.read();

      Serial.print(c);

      statusString += c;
    }
  } else if (onSignalClientDisconnect) {
    onSignalClientDisconnect = false;
    String previousSignalStrengthString = signalStrengthString;

    // the server's disconnected, stop the signalClient:
    signalClient.stop();
    Serial.println();
    Serial.println("disconnected");

    if (statusString.length() > 0) {
      signalQualityString = statusString.substring(statusString.indexOf("signalQuality") + 16, statusString.indexOf("\"", statusString.indexOf("signalQuality") + 16));
      signalStrengthString = statusString.substring(statusString.indexOf("signalStrength") + 17, statusString.indexOf("dBm", statusString.indexOf("signalStrength") + 17) - 1);
      optSummitID = statusString.substring(statusString.indexOf("summitId") + 10, statusString.indexOf(",", statusString.indexOf("summitId") + 10));
    }

    if (signalStrengthString.toInt() != 0) {
      *configItems[22] = "SSI: " + signalStrengthString + " dBm";
    } else {
      signalStrengthString = String("NR");
      *configItems[22] = "SSI: " + signalStrengthString;
    }

    if (signalQualityString.toInt() != 0) {
      *configItems[23] = "SIGNAL QUALITY: " + signalQualityString;
    } else {
      signalQualityString = String("NR");
      *configItems[23] = "SIGNAL QUALITY: " + signalQualityString;
    }

    if (optSummitID.toInt() != 0) {
      ;
    } else {
      optSummitID = String("NR");
      ;
    }

    if (!signalStrengthString.equalsIgnoreCase("NR") && !signalQualityString.equalsIgnoreCase("NR") && !optSummitID.equalsIgnoreCase("NR")) {
      signalQualityCheckSuccessful = true;
      firstSignalQualityCheck = false;
    } else {
      signalQualityCheckSuccessful = false;
    }

    if (cellModemRefreshSuccessful && signalQualityCheckSuccessful && displayBars && (calculateCellularSignalQualityBars(signalStrengthString.toInt()) != calculateCellularSignalQualityBars(previousSignalStrengthString.toInt()))) {
      displayCellularSignalQuality();
    }

    Serial.println("SSI: " + signalStrengthString + " dBm");
    Serial.println("SIGNAL QUALITY: " + signalQualityString);
    Serial.println("SUMMIT ID: " + optSummitID);
  }
}

int calculateCellularSignalQualityBars(int signalStrengthValue) {
  int bars = 0;
  if (signalStrengthValue <= -141) {
    Serial.println("SIGNAL QUALITY VERY LOW!");
  } else if (signalStrengthValue >= -140 && signalStrengthValue <= -116) {
    bars = 1;
  } else if (signalStrengthValue >= -115 && signalStrengthValue <= -101) {
    bars = 2;
  } else if (signalStrengthValue >= -100 && signalStrengthValue <= -86) {
    bars = 3;
  } else if (signalStrengthValue >= -85 && signalStrengthValue <= -71) {
    bars = 4;
  } else if (signalStrengthValue >= -70 && signalStrengthValue <= -1) {
    bars = 5;
  } else {
    Serial.println("INVALID SIGNAL QUALITY CODE!");
  }

  return bars;
}

void displayCellularSignalQuality() {
  int bars = calculateCellularSignalQualityBars(signalStrengthString.toInt());

  M5.Lcd.fillRect(8, 200, 60, 30, BLACK);
  for (int i = 0; i < bars; i++) {
    M5.Lcd.fillRect(10 + (i * 12), 210 - (i * 2), 10, 10 + (i * 2), GREEN);
  }
}

void rebootEspWithReason(String reason) {
  Serial.println(reason);
  delay(1000);
  ESP.restart();
}

/* After M5Core2 is started or reset
the program in the setUp () function will be run, and this part will only be run once.
After M5Core2 is started or reset, the program in the setup() function will be executed, and this part will only be executed once. */
void setup() {
  delay(500);

  M5.begin(); //Init M5Core2. Initialize M5Core2
                    /* Power chip connected to gpio21, gpio22, I2C device
                      Set battery charging voltage and current
                      If used battery, please call this function in your project */

  M5.Axp.SetSpkEnable(1);

  M5.Lcd.setTextSize(3);

  //pinMode(25, OUTPUT);
  //pinMode(27, OUTPUT);
  //digitalWrite(27, HIGH);

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

  di_feedsACK[0] = & ds0ACK;// <-- The '&' symbol sends just the String's pointer
  di_feedsACK[1] = & ds1ACK;//     through the '=' symbol to the array.
  di_feedsACK[2] = & ds2ACK;//
  di_feedsACK[3] = & ds3ACK;// <-- We still must load the real Strings into the
  di_feedsACK[4] = & ds4ACK;//     array, one by one.
  di_feedsACK[5] = & ds5ACK;//
  di_feedsACK[6] = & ds6ACK;//
  di_feedsACK[7] = & ds7ACK;

  ai_feedsACK[0] = & as0ACK;// <-- The '&' symbol sends just the String's pointer
  ai_feedsACK[1] = & as1ACK;//     through the '=' symbol to the array.
  ai_feedsACK[2] = & as2ACK;//
  ai_feedsACK[3] = & as3ACK;// <-- We still must load the real Strings into the
  ai_feedsACK[4] = & as4ACK;//     array, one by one.
  ai_feedsACK[5] = & as5ACK;//
  ai_feedsACK[6] = & as6ACK;//
  ai_feedsACK[7] = & as7ACK;

  configItems[0] = & serns;
  configItems[1] = & macs;
  configItems[2] = & gids;
  configItems[3] = & uids;
  configItems[4] = & ions;
  configItems[5] = & dcs0;
  configItems[6] = & dcs1;
  configItems[7] = & dcs2;
  configItems[8] = & dcs3;
  configItems[9] = & dcs4;
  configItems[10] = & dcs5;
  configItems[11] = & dcs6;
  configItems[12] = & dcs7;
  configItems[13] = & acs0;
  configItems[14] = & acs1;
  configItems[15] = & acs2;
  configItems[16] = & acs3;
  configItems[17] = & acs4;
  configItems[18] = & acs5;
  configItems[19] = & acs6;
  configItems[20] = & acs7;
  configItems[21] = & upds;
  configItems[22] = & ssis;
  configItems[23] = & sqs;
  configItems[24] = & cns;

  *configItems[0] = "SN: NONE";
  *configItems[1] = "MAC: NONE";
  *configItems[2] = "GID: NONE";
  *configItems[3] = "UID: NONE";
  *configItems[4] = "IO#: NONE";
  *configItems[5] = "DO1: NONE";
  *configItems[6] = "DO2: NONE";
  *configItems[7] = "DO3: NONE";
  *configItems[8] = "DO4: NONE";
  *configItems[9] = "DO5: NONE";
  *configItems[10] = "DO6: NONE";
  *configItems[11] = "DO7: NONE";
  *configItems[12] = "DO8: NONE";
  *configItems[13] = "AO1: NONE";
  *configItems[14] = "AO2: NONE";
  *configItems[15] = "AO3: NONE";
  *configItems[16] = "AO4: NONE";
  *configItems[17] = "AO5: NONE";
  *configItems[18] = "AO6: NONE";
  *configItems[19] = "AO7: NONE";
  *configItems[20] = "AO8: NONE";
  *configItems[21] = "UPDATE: NONE";
  *configItems[22] = "SSI: " + signalStrengthString;
  *configItems[23] = "SIGNAL QUALITY: " + signalQualityString;
  *configItems[24] = "NAME: NONE";

  heartbeat_check_feeds[0] = & hc0;// <-- The '&' symbol sends just the String's pointer
  heartbeat_check_feeds[1] = & hc1;//     through the '=' symbol to the array.
  heartbeat_check_feeds[2] = & hc2;//
  heartbeat_check_feeds[3] = & hc3;// <-- We still must load the real Strings into the
  heartbeat_check_feeds[4] = & hc4;//     array, one by one.
  heartbeat_check_feeds[5] = & hc5;//
  heartbeat_check_feeds[6] = & hc6;//
  heartbeat_check_feeds[7] = & hc7;
  heartbeat_check_feeds[8] = & hc8;
  heartbeat_check_feeds[9] = & hc9;
  heartbeat_check_feeds[10] = & hc10;
  heartbeat_check_feeds[11] = & hc11;
  heartbeat_check_feeds[12] = & hc12;
  heartbeat_check_feeds[13] = & hc13;
  heartbeat_check_feeds[14] = & hc14;
  heartbeat_check_feeds[15] = & hc15;
  heartbeat_check_feeds[16] = & hc16;
  heartbeat_check_feeds[17] = & hc17;
  heartbeat_check_feeds[18] = & hc18;
  heartbeat_check_feeds[19] = & hc19;

  Serial.begin(115200);
  while (!Serial) {
    /*
    M5.update();
    onRightPress();
    onRightRelease();
    onLeftPress();
    onLeftRelease();
    onCenterPress();
    onCenterRelease();
    */
  }

  Wire.begin();
  //Wire.setClock(100000);

  cardType = SD.cardType();

  //UPDATE FIRMWARE IF AVAILABLE
  if (SD.exists("/update.bin") == 1) {
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);

    M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
    M5.Lcd.drawString(rciTitle, 50, 70, 1);
    M5.Lcd.drawString("UPDATING", 85, 120, 1);
    M5.Lcd.drawString("FIRMWARE", 85, 170, 1);
    updateFromFS(SD);

    rebootEspWithReason("FIRMWARE UPDATE");
  }

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

  //WRITE OPT CONNECT SUMMIT API INFORMATION TO INTERNAL MEMORY
  if (SD.exists("/api.txt") == 1) {
    myFile = SD.open("/api.txt");
    while (myFile.available()) {
      analyzeSDCardContents();
    }
    myFile.close();
    SD.remove("/api.txt");
    preferences.begin(pnamespace);
    preferences.putString(optAccountIDKey, optAccountID);
    preferences.putString(optApplicationIDKey, optApplicationID);
    preferences.putString(optSecretIDKey, optSecretID);
    preferences.putString(optRadioSNKey, optRadioSN);
    preferences.end();
  }

  //WRITE SERVER CREDENTIALS TO INTERNAL MEMORY
  if (SD.exists("/creds.txt") == 1) {
    myFile = SD.open("/creds.txt");
    while (myFile.available()) {
      analyzeSDCardContents();
    }
    myFile.close();
    SD.remove("/creds.txt");
    preferences.begin(pnamespace);
    preferences.putString(mqttBrokerKey, mqttBroker);
    preferences.putString(mqttUsernameKey, mqttUsername);
    preferences.putString(mqttPasswordKey, mqttPassword);
    preferences.putString(mqttPortKey, stringMqttPort);
    preferences.putString(ftpBrokerKey, ftpBroker);
    preferences.putString(ftpPortKey, stringFtpPort);
    preferences.putString(ftpUsernameKey, ftpUsername);
    preferences.putString(ftpPasswordKey, ftpPassword);
    preferences.putString(ftpWorkingDirectoryKey, ftpWorkingDirectory);
    preferences.end();
  }

  //RETREIVE IMPORTANT INTERNAL INFO
  preferences.begin(pnamespace);
  serialNumber = preferences.getString(serialKey);
  stringMac = preferences.getString(macKey);
  mqttBroker = preferences.getString(mqttBrokerKey);
  mqttUsername = preferences.getString(mqttUsernameKey);
  mqttPassword = preferences.getString(mqttPasswordKey);
  stringMqttPort = preferences.getString(mqttPortKey);
  ftpBroker = preferences.getString(ftpBrokerKey);
  stringFtpPort = preferences.getString(ftpPortKey);
  ftpUsername = preferences.getString(ftpUsernameKey);
  ftpPassword = preferences.getString(ftpPasswordKey);
  ftpWorkingDirectory = preferences.getString(ftpWorkingDirectoryKey);
  optAccountID = preferences.getString(optAccountIDKey);
  optApplicationID = preferences.getString(optApplicationIDKey);
  optSecretID = preferences.getString(optSecretIDKey);
  optRadioSN = preferences.getString(optRadioSNKey);
  preferences.end();

  if (serialNumber.length() != 0) {
    *configItems[0] = "SN: " + serialNumber;
  }
  if (stringMac.length() != 0) {
    *configItems[1] = "MAC: " + stringMac.substring(0, stringMac.length() - 1);
  }

  if (stringMac.indexOf(":") != -1) {
    hexCharacterStringToBytes(mac, stringMac.substring(0, stringMac.length() - 1).c_str());
  }

  configFileName = serialNumber + ".txt";
  sdConfigFileName = "/" + configFileName;

  if (SD.exists(sdConfigFileName) == 1) {
    myFile = SD.open(sdConfigFileName);
    if (myFile.available() >= 1) {
      //GET MQTT TOPICS FROM SD CARD
      while (myFile.available()) {
        analyzeSDCardContents();
      }
      preCheckSD = true;
    }
    myFile.close();
  } 


  if (pingI2cAddress(0x48) == 0) {
    ads1115.begin(0x48);
    ads1115.setGain(GAIN_ONE);
    adc0 = ads1115.readADC_SingleEnded(0);
    adc1 = ads1115.readADC_SingleEnded(1);
    adc2 = ads1115.readADC_SingleEnded(2);
    adc3 = ads1115.readADC_SingleEnded(3);
    
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
  } else {
    analogInOneSuccess = false;
    errorCode = "ERROR CODE: 10";
  }

  //if (IONum.toInt() > 4) {
  if (pingI2cAddress(0x49) == 0) {
    ads1115second.begin(0x49);
    ads1115second.setGain(GAIN_ONE);
    adc0second = ads1115second.readADC_SingleEnded(0);
    adc1second = ads1115second.readADC_SingleEnded(1);
    adc2second = ads1115second.readADC_SingleEnded(2);
    adc3second = ads1115second.readADC_SingleEnded(3);

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
  } else {
    analogInTwoSuccess = false;
    if (IONum.toInt() > 4 || IONum.toInt() == 0) {
      errorCode = "ERROR CODE: 11";
    }
  }

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
  if (pingI2cAddress(0x1f) == 0) {
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
  } else {
    analogOutOneSuccess = false;
    errorCode = "ERROR CODE: 12";
  }

  
  if (pingI2cAddress(0x1c) == 0) {
    Wire.beginTransmission(0x1c);
    Wire.write(byte(56));
    Wire.write(byte(0));
    Wire.write(byte(1));
    Wire.endTransmission();
  
    Wire.beginTransmission(0x1c);
    Wire.write(byte(7));
    Wire.write(byte(0));
    Wire.write(byte(0));
    Wire.endTransmission();
  } else {
    analogOutTwoSuccess = false;
    if (IONum.toInt() > 4 || IONum.toInt() == 0) {
      errorCode = "ERROR CODE: 13";
    }
  }


  if (pingI2cAddress(0x38) == 0) {
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
  } else {
    digitalInputSuccess = false;
    errorCode = "ERROR CODE: 14";
  }

  if (pingI2cAddress(0x39) == 0) {
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
  } else {
    digitalOutputSuccess = false;
    errorCode = "ERROR CODE: 15";
  }

  if (pingI2cAddress(0x3a) == 0) {
    pcfw2.begin(0x3a, &Wire);
    pcfw2.pinMode(0, OUTPUT);
    //pcfw2.pinMode(1, OUTPUT);
    //pcfw2.pinMode(2, OUTPUT);
    //pcfw2.pinMode(3, OUTPUT);
    //pcfw2.pinMode(4, OUTPUT);
    //pcfw2.pinMode(5, OUTPUT);
    //pcfw2.pinMode(6, OUTPUT);
    //pcfw2.pinMode(7, OUTPUT);
    pcfw2.digitalWrite(0, false);
    //pcfw2.digitalWrite(1, true);
    //pcfw2.digitalWrite(2, true);
    //pcfw2.digitalWrite(3, true);
    //pcfw2.digitalWrite(4, true);
    //pcfw2.digitalWrite(5, true);
    //pcfw2.digitalWrite(6, true);
    //pcfw2.digitalWrite(7, true);
  } else {
    digitalDebugSuccess = false;
    errorCode = "ERROR CODE: 16";
  } 

  Ethernet.init(26);

  rciTitle = "RCI-" + IONum + "00-CEL";

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("START-UP CHECK", 40, 120, 1);
  if (errorCode.equalsIgnoreCase(String("NO ERRORS"))) {
    M5.Lcd.drawString(errorCode, 70, 170, 1);
  } else {
    M5.Lcd.drawString(errorCode, 35, 170, 1);
  }
  M5.Lcd.drawString(versionNumber, 5, 210, 1);
  
  startUpPreviousMillis = millis();
  startUpCurrentMillis = startUpPreviousMillis;

  startUpMode = true;

  while (startUpCurrentMillis - startUpPreviousMillis < startUpInterval || !normalMode) {
    M5.update();
    onRightPress();
    onRightRelease();
    onLeftPress();
    onLeftRelease();
    onCenterPress();
    onCenterRelease();
    startUpCurrentMillis = millis();
    timeOutCurrentMillis = millis();

    if (copyMode) {
      inputToOutputCopyRoutine();
    }

    if (!normalMode && timeOutCurrentMillis - timeOutPreviousMillis >= timeOutInterval) {
      returnToNormalOperation();
    }
  }

  startUpMode = false;

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("WAITING FOR", 50, 120, 1);
  M5.Lcd.drawString("CONNECTION", 60, 170, 1);


  broker = mqttBroker;

  port = stringMqttPort.toInt();

  commFailCurrentMillis = millis();
  commFailPreviousMillis = commFailCurrentMillis;

  while (Ethernet.begin(mac) == 0) {
    commFailCurrentMillis = millis();
    if (commFailCurrentMillis - commFailPreviousMillis >= commFailInterval && commFailToggledOnce) {
      commFailToggledOnce = false;
      if (digitalDebugSuccess) {
        pcfw2.digitalWrite(0, true);
      }
    }
    /*
    M5.update();
    onRightPress();
    onRightRelease();
    onLeftPress();
    onLeftRelease();
    onCenterPress();
    onCenterRelease();
    //delay(5000);
    */
  }
  commFailToggledOnce = true;
  if (digitalDebugSuccess) {
    pcfw2.digitalWrite(0, false);
  }

  delay(500);

  if (noStartUpConfig) {
    initEthernet();
    Udp.begin(localUDPPort);
    Ethernet.maintain();
  }

  delay(500);

  //GET TIME ON ESP32
  /*
  while (true) {
    time_t result = time(NULL);
    Serial.println(asctime(gmtime(&result)));
    delay(1000);
  }
  */

  /*
  //TEST SD CARD OPERATIONS
  myFile = SD.open("/test.txt", FILE_WRITE);
  myFile.println("testing 1, 2, 3.");
  myFile.close();
  myFile = SD.open("/test.txt");
  M5.Lcd.print(myFile.read());
  myFile.close();
  */

  //INITIAL CONFIGURATION CONNECTION
  myFile = SD.open(sdConfigFileName);
  if (myFile.available() < 1) {
    myFile.close();

    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);

    normalMode = false;
    cfgServerMode = true;
    initialSDCheck = true;
    configConnect();

    while (!hasConfigInfo) {
      M5.update();

      if (ioKnown) {
        for (int i = 1; i <= IONum.toInt(); i++) {
          String di_feed = groupID + "_" + unitID + "_DI" + i;
          *di_feeds[i - 1] = di_feed;
          String di_feedACK = di_feed + "_ACK";
          *di_feedsACK[i - 1] = di_feedACK;

          String ai_feed = groupID + "_" + unitID + "_AI" + i;
          *ai_feeds[i - 1] = ai_feed;
          String ai_feedACK = ai_feed + "_ACK";
          *ai_feedsACK[i - 1] = ai_feedACK;
        }
        ioKnown = false;
      }

      timeOutCurrentMillis = millis();
      onRightPress();
      onRightRelease();
      onLeftPress();
      onLeftRelease();
      onCenterPress();
      onCenterRelease();

      //toggleResetClock();

      Ethernet.maintain();

      if (!normalMode && timeOutCurrentMillis - timeOutPreviousMillis >= timeOutInterval) {
        returnToNormalOperation();
      }
    }
  } else {
    myFile.close();
  }

  if (!preCheckSD) {
    //GET MQTT TOPICS FROM SD CARD
    myFile = SD.open(sdConfigFileName);
    while (myFile.available()) {
      analyzeSDCardContents();
    }
    myFile.close();
  }
  else {
    preCheckSD = false;
  }

  Ethernet.maintain();
  reconnectMqtt();

  //publishConnected();

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

/* After the program in setup() runs, it runs the program in loop()
The loop() function is an infinite loop in which the program runs repeatedly
After the program in the setup() function is executed, the program in the loop() function will be executed
The loop() function is an endless loop, in which the program will continue to run repeatedly */
void loop() {
  M5.update();

  apiAccessCurrentMillis = millis();
  if (apiAccessCurrentMillis - apiAccessPreviousMillis >= apiAccessInterval) {
    apiAccessPreviousMillis = apiAccessCurrentMillis;
    apiAccessGranted = false;
    apiAccessRequestSent = false;
  }

  apiAccessRequestCurrentMillis = millis();
  if ((apiAccessRequestSent) && (apiAccessRequestCurrentMillis - apiAccessRequestPreviousMillis >= apiAccessRequestInterval)) {
    apiAccessRequestPreviousMillis = apiAccessRequestCurrentMillis;
    apiAccessRequestSent = false;
  }

  requestSignalQualityCurrentMillis = millis();
  if (requestSignalQualityCurrentMillis - requestSignalQualityPreviousMillis >= requestSignalQualityInterval) {
    requestSignalQualityPreviousMillis = requestSignalQualityCurrentMillis;
    cellModemRefreshSuccessful = false;
    signalQualityCheckSuccessful = false;
  }

  if (apiAccessGranted) {
    if (receivingSignalQuality) {
      backgroundReceiveCellularSignalQuality(normalMode);
    } else {
      backgroundReceiveCellModemRefresh();
    }
  } else {
    if (!apiAccessRequestSent) {
      requestAPIAccess();
      apiAccessRequestSent = true;
    }
    backgroundReceiveAPIKey();
  }
  

  commFailCurrentMillis = millis();
  commFailPreviousMillis = commFailCurrentMillis;

  getTimeCurrentMillis = millis();

  if (pingI2cAddress(0x48) == 0) {
    analogInOneSuccess = true;
  } else {
    analogInOneSuccess = false;
  }

  if (pingI2cAddress(0x49) == 0) {
    analogInTwoSuccess = true;
  } else {
    analogInTwoSuccess = false;
  }
  
  if (pingI2cAddress(0x1f) == 0) {
    analogOutOneSuccess = true;
  } else {
    analogOutOneSuccess = false;
  }

  if (pingI2cAddress(0x1c) == 0) {
    analogOutTwoSuccess = true;
  } else {
    analogOutTwoSuccess = false;
  }

  if (pingI2cAddress(0x38) == 0) {
    digitalInputSuccess = true;
  } else {
    digitalInputSuccess = false;
  }

  if (pingI2cAddress(0x39) == 0) {
    digitalOutputSuccess = true;
  } else {
    digitalOutputSuccess = false;
  }

  if (pingI2cAddress(0x3a) == 0) {
    digitalDebugSuccess = true;
  } else {
    digitalDebugSuccess = false;
  }


  if (normalMode) {
    currentMillis3 = millis();

    /*
    if (reconnectCount >= 4 || currentMillis3 - previousMillis3 >= interval3) {
      mqttClient.stop();
      delay(5000);
    }
    */

    while (!mqttClient.connected()) {
      commFailCurrentMillis = millis();
      if (commFailCurrentMillis - commFailPreviousMillis >= commFailInterval && commFailToggledOnce) {
        commFailToggledOnce = false;
        if (digitalDebugSuccess) {
          pcfw2.digitalWrite(0, true);
        }
      }
      if (!reconnect) {
        M5.Lcd.clear();
        M5.Lcd.setCursor(0, 0);
        M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
        M5.Lcd.drawString(rciTitle, 50, 70, 1);
        M5.Lcd.drawString("WAITING FOR", 50, 120, 1);
        M5.Lcd.drawString("CONNECTION", 60, 170, 1);
      }
      while (Ethernet.begin(mac) == 0) {
        commFailCurrentMillis = millis();
        if (commFailCurrentMillis - commFailPreviousMillis >= commFailInterval && commFailToggledOnce) {
          commFailToggledOnce = false;
          if (digitalDebugSuccess) {
            pcfw2.digitalWrite(0, true);
          }
        }
      }
      Ethernet.maintain();
      //delay(1000);
      reconnectMqtt();
    }

    if (!commFailToggledOnce) {
      commFailToggledOnce = true;
      if (digitalDebugSuccess) {
        pcfw2.digitalWrite(0, false);
      }
    }

    currentMillis5 = millis();
    if (currentMillis5 - previousMillis5 >= interval5) {
      previousMillis5 = currentMillis5;
      //mqttClient.loop();
      mqttClient.poll();

      if (subConnectedRecv) {
        subConnectedRecv = false;
        publishConnectedReceipt();
      }
      if (do1Recv) {
        do1Recv = false;
        publishDO1Receipt();
      }
      if (do2Recv) {
        do2Recv = false;
        publishDO2Receipt();
      }
      if (do3Recv) {
        do3Recv = false;
        publishDO3Receipt();
      }
      if (do4Recv) {
        do4Recv = false;
        publishDO4Receipt();
      }
      if (do5Recv) {
        do5Recv = false;
        publishDO5Receipt();
      }
      if (do6Recv) {
        do6Recv = false;
        publishDO6Receipt();
      }
      if (do7Recv) {
        do7Recv = false;
        publishDO7Receipt();
      }
      if (do8Recv) {
        do8Recv = false;
        publishDO8Receipt();
      }
      if (ao1Recv) {
        ao1Recv = false;
        publishAO1Receipt();
      }
      if (ao2Recv) {
        ao2Recv = false;
        publishAO2Receipt();
      }
      if (ao3Recv) {
        ao3Recv = false;
        publishAO3Receipt();
      }
      if (ao4Recv) {
        ao4Recv = false;
        publishAO4Receipt();
      }
      if (ao5Recv) {
        ao5Recv = false;
        publishAO5Receipt();
      }
      if (ao6Recv) {
        ao6Recv = false;
        publishAO6Receipt();
      }
      if (ao7Recv) {
        ao7Recv = false;
        publishAO7Receipt();
      }
      if (ao8Recv) {
        ao8Recv = false;
        publishAO8Receipt();
      }

      if (pubConnectedSent && !pubConnectedRecv) {
        pubConnectedLoopCount++;
        if (pubConnectedLoopCount > 2) {
          pubConnectedLoopCount = 0;
          publishConnected();
        }
      }
      /*
      if (pubConfSent && !) {
        if () {
          
        }
      }
      */
      /*
      if (pubCredSent && !) {
        if () {
          
        }
      }
      */
      /*
      if (pubInternalSent && !) {
        if () {
          
        }
      }
      */
      /*
      if (pubApiSent && !) {
        if () {
          
        }
      }
      */
      if (di1Sent && !di1Recv) {
        di1LoopCount++;
        if (di1LoopCount > 2) {
          di1LoopCount = 0;
          publishDI1();
        }
      }
      if (di2Sent && !di2Recv) {
        di2LoopCount++;
        if (di2LoopCount > 2) {
          di2LoopCount = 0;
          publishDI2();
        }
      }
      if (di3Sent && !di3Recv) {
        di3LoopCount++;
        if (di3LoopCount > 2) {
          di3LoopCount = 0;
          publishDI3();
        }
      }
      if (di4Sent && !di4Recv) {
        di4LoopCount++;
        if (di4LoopCount > 2) {
          di4LoopCount = 0;
          publishDI4();
        }
      }
      if (di5Sent && !di5Recv) {
        di5LoopCount++;
        if (di5LoopCount > 2) {
          di5LoopCount = 0;
          publishDI5();
        }
      }
      if (di6Sent && !di6Recv) {
        di6LoopCount++;
        if (di6LoopCount > 2) {
          di6LoopCount = 0;
          publishDI6();
        }
      }
      if (di7Sent && !di7Recv) {
        di7LoopCount++;
        if (di7LoopCount > 2) {
          di7LoopCount = 0;
          publishDI7();
        }
      }
      if (di8Sent && !di8Recv) {
        di8LoopCount++;
        if (di8LoopCount > 2) {
          di8LoopCount = 0;
          publishDI8();
        }
      }
      if (ai1Sent && !ai1Recv) {
        ai1LoopCount++;
        if (ai1LoopCount > 2) {
          ai1LoopCount = 0;
          publishAI1();
        }
      }
      if (ai2Sent && !ai2Recv) {
        ai2LoopCount++;
        if (ai2LoopCount > 2) {
          ai2LoopCount = 0;
          publishAI2();
        }
      }
      if (ai3Sent && !ai3Recv) {
        ai3LoopCount++;
        if (ai3LoopCount > 2) {
          ai3LoopCount = 0;
          publishAI3();
        }
      }
      if (ai4Sent && !ai4Recv) {
        ai4LoopCount++;
        if (ai4LoopCount > 2) {
          ai4LoopCount = 0;
          publishAI4();
        }
      }
      if (ai5Sent && !ai5Recv) {
        ai5LoopCount++;
        if (ai5LoopCount > 2) {
          ai5LoopCount = 0;
          publishAI5();
        }
      }
      if (ai6Sent && !ai6Recv) {
        ai6LoopCount++;
        if (ai6LoopCount > 2) {
          ai6LoopCount = 0;
          publishAI6();
        }
      }
      if (ai7Sent && !ai7Recv) {
        ai7LoopCount++;
        if (ai7LoopCount > 2) {
          ai7LoopCount = 0;
          publishAI7();
        }
      }
      if (ai8Sent && !ai8Recv) {
        ai8LoopCount++;
        if (ai8LoopCount > 2) {
          ai8LoopCount = 0;
          publishAI8();
        }
      }
    }

    heartbeatPublishCurrentMillis = millis();
    if (heartbeatPublishCurrentMillis - heartbeatPublishPreviousMillis >= heartbeatPublishInterval) {
      heartbeatPublishPreviousMillis = heartbeatPublishCurrentMillis;
      publishHeartbeat();
    }

    currentMillis6 = millis();
    if (currentMillis6 - previousMillis6 >= interval6) {
      previousMillis6 = currentMillis6;
    
      if (IONum.toInt() >= 1) {
        if (analogInOneSuccess) {
          if ((adc0Prev + 100) < ads1115.readADC_SingleEnded(0) || (adc0Prev - 100) > ads1115.readADC_SingleEnded(0)) {
            publishAI1();
          }
        }

        if (digitalInputSuccess) {
          if (pcfr0Prev != int(pcfr.digitalRead(0))) {
            publishDI1();
          }
        }
      }

      if (IONum.toInt() >= 2) {
        if (analogInOneSuccess) {
          if ((adc1Prev + 100) < ads1115.readADC_SingleEnded(1) || (adc1Prev - 100) > ads1115.readADC_SingleEnded(1)) {
            publishAI2();
          }
        }

        if (digitalInputSuccess) {
          if (pcfr1Prev != int(pcfr.digitalRead(1))) {
            publishDI2();
          }
        }
      }

      if (IONum.toInt() >= 3) {
        if (analogInOneSuccess) {
          if ((adc2Prev + 100) < ads1115.readADC_SingleEnded(2) || (adc2Prev - 100) > ads1115.readADC_SingleEnded(2)) {
            publishAI3();
          }
        }

        if (digitalInputSuccess) {
          if (pcfr2Prev != int(pcfr.digitalRead(2))) {
            publishDI3();
          }
        }
      }

      if (IONum.toInt() >= 4) {
        if (analogInOneSuccess) {
          if ((adc3Prev + 100) < ads1115.readADC_SingleEnded(3) || (adc3Prev - 100) > ads1115.readADC_SingleEnded(3)) {
            publishAI4();
          }
        }

        if (digitalInputSuccess) {
          if (pcfr3Prev != int(pcfr.digitalRead(3))) {
            publishDI4();
          }
        }
      }

      if (IONum.toInt() >= 5) {
        if (analogInTwoSuccess) {
          if ((adc0secondPrev + 100) < ads1115second.readADC_SingleEnded(0) || (adc0secondPrev - 100) > ads1115second.readADC_SingleEnded(0)) {
            publishAI5();
          }
        }

        if (digitalInputSuccess) {
          if (pcfr4Prev != int(pcfr.digitalRead(4))) {
            publishDI5();
          }
        }
      }

      if (IONum.toInt() >= 6) {
        if (analogInTwoSuccess) {
          if ((adc1secondPrev + 100) < ads1115second.readADC_SingleEnded(1) || (adc1secondPrev - 100) > ads1115second.readADC_SingleEnded(1)) {
            publishAI6();
          }
        }

        if (digitalInputSuccess) {
          if (pcfr5Prev != int(pcfr.digitalRead(5))) {
            publishDI6();
          }
        }
      }

      if (IONum.toInt() >= 7) {
        if (analogInTwoSuccess) {
          if ((adc2secondPrev + 100) < ads1115second.readADC_SingleEnded(2) || (adc2secondPrev - 100) > ads1115second.readADC_SingleEnded(2)) {
            publishAI7();
          }
        }

        if (digitalInputSuccess) {
          if (pcfr6Prev != int(pcfr.digitalRead(6))) {
            publishDI7();
          }
        }
      }

      if (IONum.toInt() >= 8) {
        if (analogInTwoSuccess) {
          if ((adc3secondPrev + 100) < ads1115second.readADC_SingleEnded(3) || (adc3secondPrev - 100) > ads1115second.readADC_SingleEnded(3)) {
            publishAI8();
          }
        }

        if (digitalInputSuccess) {
          if (pcfr7Prev != int(pcfr.digitalRead(7))) {
            publishDI8();
          }
        }
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

    if (publishAllc) {
      publishAll();
      publishAllc = false;
    }

    if (confUpdateStep1PubOnce) {
      publishConf(false);
      confUpdateStep1PubOnce = false;
    }

    if (confUpdateStep2PubOnce) {
      publishConf(true);
      confUpdateStep2PubOnce = false;
      mqttClient.stop();
      normalMode = false;
    }

    if (internalUpdateStep1PubOnce) {
      publishInternal(false);
      internalUpdateStep1PubOnce = false;
    }

    if (internalUpdateStep2PubOnce) {
      publishInternal(true);
      internalUpdateStep2PubOnce = false;
      mqttClient.stop();
      normalMode = false;
    }

    if (credUpdateStep1PubOnce) {
      publishCreds(false);
      credUpdateStep1PubOnce = false;
    }

    if (credUpdateStep2PubOnce) {
      publishCreds(true);
      credUpdateStep2PubOnce = false;
      mqttClient.stop();
      normalMode = false;
    }

    if (apiUpdateStep1PubOnce) {
      publishApi(false);
      apiUpdateStep1PubOnce = false;
    }

    if (apiUpdateStep2PubOnce) {
      publishApi(true);
      apiUpdateStep2PubOnce = false;
      mqttClient.stop();
      normalMode = false;
    }

    /*
    if (!analogInOneSuccess) {
      //replaceText(10, 200, 300, 50, 1, "NO COMM: AI1-4");
      M5.Lcd.drawString("NO COMM: AI1-4", 0, 200, 1);
    }

    else if (!analogInTwoSuccess) {
      //replaceText(10, 200, 300, 50, 1, "NO COMM: AI5-8");
      M5.Lcd.drawString("NO COMM: AI5-8", 0, 200, 1);
    }

    else if (!analogOutOneSuccess) {
      //replaceText(10, 200, 300, 50, 1, "NO COMM: AO1-4");
      M5.Lcd.drawString("NO COMM: AO1-4", 0, 200, 1);
    }

    else if (!analogOutTwoSuccess) {
      //replaceText(10, 200, 300, 50, 1, "NO COMM: AO5-8");
      M5.Lcd.drawString("NO COMM: AO5-8", 0, 200, 1);
    }

    else if (!digitalInputSuccess) {
      //replaceText(10, 200, 300, 50, 1, "NO COMM: ALL DI");
      M5.Lcd.drawString("NO COMM: ALL DI", 0, 200, 1);
    }

    else if (!digitalOutputSuccess) {
      //replaceText(10, 200, 300, 50, 1, "NO COMM: ALL DO");
      M5.Lcd.drawString("NO COMM: ALL DO", 0, 200, 1);
    }

    else if (!digitalDebugSuccess) {
      //replaceText(10, 200, 300, 50, 1, "NO COMM: FAIL LINE");
      M5.Lcd.drawString("NO COMM: FAIL LINE", 0, 200, 1);
    }
    */

    for (int i = 0; i < subCount; i++) {
      heartbeatCheckCurrentMillis[i] = millis();
      if ((heartbeatCheckCurrentMillis[i] - heartbeatCheckPreviousMillis[i] >= heartbeatCheckInterval) && (!heartbeatCheckAlreadySetFailDefaults[i])) {
        String tempHeartbeatCheckFeed = *heartbeat_check_feeds[i];
        setGroupMemberLossOfCommunicationDefaults(tempHeartbeatCheckFeed.substring(tempHeartbeatCheckFeed.indexOf("_") + 1, tempHeartbeatCheckFeed.indexOf("_", tempHeartbeatCheckFeed.indexOf("_") + 1)));
        heartbeatCheckAlreadySetFailDefaults[i] = true;
      }
    }

    for (int i = 0; i < subCount; i++) {
      if (heartbeatCheckAlreadySetFailDefaults[i]) {
        heartbeatCommFail = true;
        break;
      }
      if (i == (subCount - 1)) {
        heartbeatCommFail = false;
      }
    }

    if (digitalDebugSuccess) {
      pcfw2.digitalWrite(0, heartbeatCommFail);
    }
  }

  timeOutCurrentMillis = millis();
  onRightPress();
  onRightRelease();
  onLeftPress();
  onLeftRelease();
  onCenterPress();
  onCenterRelease();

  //toggleResetClock();

  Ethernet.maintain();

  if (confUpdateStep2 && !confUpdateStep2PubOnce) {
    confConnect();
  }

  if (internalUpdateStep2 && !internalUpdateStep2PubOnce) {
    internalConnect();
  }

  if (credUpdateStep2 && !credUpdateStep2PubOnce) {
    credConnect();
  }

  if (apiUpdateStep2 && !apiUpdateStep2PubOnce) {
    apiConnect();
  }

  if (cfgServerMode) {
    if (!hasConfigInfo) {
      if (ioKnown) {
        for (int i = 1; i <= IONum.toInt(); i++) {
          String di_feed = groupID + "_" + unitID + "_DI" + i;
          *di_feeds[i - 1] = di_feed;
          String di_feedACK = di_feed + "_ACK";
          *di_feedsACK[i - 1] = di_feedACK;

          String ai_feed = groupID + "_" + unitID + "_AI" + i;
          *ai_feeds[i - 1] = ai_feed;
          String ai_feedACK = ai_feed + "_ACK";
          *ai_feedsACK[i - 1] = ai_feedACK;
        }
        ioKnown = false;
      }
      

      //toggleResetClock();

      //Ethernet.maintain();
    }
  }
  
  if (copyMode) {
    inputToOutputCopyRoutine();
  }
  
  if (!normalMode && timeOutCurrentMillis - timeOutPreviousMillis >= timeOutInterval) {
    returnToNormalOperation();
  }
}