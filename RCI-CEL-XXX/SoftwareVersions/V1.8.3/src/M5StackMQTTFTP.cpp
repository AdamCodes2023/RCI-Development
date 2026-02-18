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
#include "M5StackMQTTFTP.h"

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

//#include <SSLClient.h>                            		//-- moved to arduinoGlue.h
//#include <ArduinoMqttClient.h>                    		//-- moved to arduinoGlue.h
//#include <M5Core2.h>                              		//-- moved to arduinoGlue.h
//#include <SPI.h>                                  		//-- moved to arduinoGlue.h
//#include <Ethernet.h>                             		//-- moved to arduinoGlue.h
//#include <EthernetUdp.h>                          		//-- moved to arduinoGlue.h
//#include <Wire.h>                                 		//-- moved to arduinoGlue.h
//#include <Adafruit_ADS1X15.h>                     		//-- moved to arduinoGlue.h
//#include <Adafruit_MCP4728.h>                     		//-- moved to arduinoGlue.h
//#include <Adafruit_PCF8574.h>                     		//-- moved to arduinoGlue.h
//#include <Preferences.h>                          		//-- moved to arduinoGlue.h
//#include <FTPClient_Generic.h>                    		//-- moved to arduinoGlue.h
//#include <TimeLib.h>                              		//-- moved to arduinoGlue.h
//#include <Update.h>                               		//-- moved to arduinoGlue.h
//#include <ArduinoJson.h>                          		//-- moved to arduinoGlue.h
#include "Arduino.h"
#include "buttons/buttons.h"
#include "cellular/cellular.h"
#include "certificates/certificates.h"  // This file must be regenerated.
#include "config/config.h"
#include "cycling/cycling.h"
#include "fwupdate/fwupdate.h"
#include "implementftp/implementftp.h"
#include "implementmqtt/implementmqtt.h"
#include "modes/modes.h"
#include "receive/receive.h"
#include "screen/screen.h"
#include "send/send.h"
#include "utility/utility.h"

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
	//-- moved to arduinoGlue.h // #define USING_VSFTP_SERVER      false

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

String software_version_feed = String("");

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

String globalZeroText = String("0");
bool noHandshakeDigitalInputFeeds[8] = {};
bool noHandshakeAnalogInputFeeds[8] = {};

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
bool publishSoftwareVersionFlag = false;

long long connectedPublishCount = 0;

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
long long heartbeatPublishCount = 0;
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

String versionNumber = String("V 1.8.3");
String statusString = String("");
String signalQualityString = String("NR");
String signalStrengthString = String("NR");
bool onSignalClientDisconnect = true;
bool receivingSignalQuality = false;
bool signalQualityCheckSuccessful = false;
bool firstSignalQualityCheck = true;
short requestAPIAccessCount = 0;
short requestCellModemRefreshCount = 0;
short requestCellularSignalQualityCount = 0;

short cycleCounter = 0;
bool cyclingPaused = false;

const long long publishAllInterval = 3600000;
const long long clearTextInterval = 2000;
const long long reconnectInterval = 1800000;
const long long cycleComponentsInterval = 5000;
long long checkForSubscribeInterval = 10000;
long long checkForPublishInterval = 10000;
const long long startUpInterval = 5000;
const long long timeOutInterval = 180000;
const long long commFailInterval = 300000;
const long long getTimeInterval = 86400000;
const long long apiAccessInterval = 3600000;
const long long apiAccessRequestInterval = 30000;
const long long requestSignalQualityConfigModeInterval = 30000;
const long long requestSignalQualityNormalModeInterval = 3600000;
const long long heartbeatPublishInterval = 60000;
const long long heartbeatCheckInterval = 180000;
const long long cyclingPauseInterval = 300000;
const long long updateSignalDeviceInfoInterval = 30000;
const long long receiveSignalQualityInterval = 20000;
const long long clearUpdateFlagsInterval = 60000;
unsigned long long publishAllPreviousMillis = 0;
unsigned long long clearTextPreviousMillis = 0;
unsigned long long reconnectPreviousMillis = 0;
unsigned long long cycleComponentsPreviousMillis = 0;
unsigned long long checkForSubscribePreviousMillis = 0;
unsigned long long checkForPublishPreviousMillis = 0;
unsigned long long startUpPreviousMillis = 0;
unsigned long long timeOutPreviousMillis = 0;
unsigned long long commFailPreviousMillis = 0;
unsigned long long getTimePreviousMillis = 0;
unsigned long long apiAccessPreviousMillis = 0;
unsigned long long apiAccessRequestPreviousMillis = 0;
unsigned long long requestSignalQualityPreviousMillis = 0;
unsigned long long heartbeatPublishPreviousMillis = 0;
unsigned long long heartbeatCheckPreviousMillis[20] = {};
unsigned long long cyclingPausePreviousMillis = 0;
unsigned long long updateSignalDeviceInfoPreviousMillis = 0;
unsigned long long receiveSignalQualityPreviousMillis = 0;
unsigned long long clearUpdateFlagsPreviousMillis = 0;
unsigned long long publishAllCurrentMillis = 0;
unsigned long long clearTextCurrentMillis = 0;
unsigned long long reconnectCurrentMillis = 0;
unsigned long long cycleComponentsCurrentMillis = 0;
unsigned long long checkForSubscribeCurrentMillis = 0;
unsigned long long checkForPublishCurrentMillis = 0;
unsigned long long startUpCurrentMillis = 0;
unsigned long long timeOutCurrentMillis = 0;
unsigned long long commFailCurrentMillis = 0;
unsigned long long getTimeCurrentMillis = 0;
unsigned long long apiAccessCurrentMillis = 0;
unsigned long long apiAccessRequestCurrentMillis = 0;
unsigned long long requestSignalQualityCurrentMillis = 0;
unsigned long long heartbeatPublishCurrentMillis = 0;
unsigned long long heartbeatCheckCurrentMillis[20] = {};
unsigned long long cyclingPauseCurrentMillis = 0;
unsigned long long updateSignalDeviceInfoCurrentMillis = 0;
unsigned long long receiveSignalQualityCurrentMillis = 0;
unsigned long long clearUpdateFlagsCurrentMillis = 0;
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
bool centerCyclingPausePressed = false;
bool centerCyclingScrollPressed = false;
bool centerPressedOnce = false;
bool leftCyclingPausePressed = false;
bool leftCyclingScrollPressed = false;
bool leftPressedOnce = false;
bool leftPressedTwice = false;
bool leftPressedThree = false;
bool rightCyclingUnpausePressed = false;
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

byte packetBufferTime[NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets

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

    if (!noStartUpConfig) {
      signalQualityRoutine();
    }

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
    //initEthernet();
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

  for (int i = 1; i <= IONum.toInt(); i++) {
    String di_feed = groupID + "_" + unitID + "_DI" + i;
    if (noHandshakeDigitalInputFeeds[i - 1]) {
      di_feed = globalZeroText + "_DI" + i;
    }
    *di_feeds[i - 1] = di_feed;
    String di_feedACK = di_feed + "_ACK";
    *di_feedsACK[i - 1] = di_feedACK;

    String ai_feed = groupID + "_" + unitID + "_AI" + i;
    if (noHandshakeAnalogInputFeeds[i - 1]) {
      ai_feed = globalZeroText + "_AI" + i;
    }
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
The loop() function is an infinite loop in which the program runs repeatedly */
void loop() {
  M5.update();

  signalQualityRoutine();

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
    reconnectCurrentMillis = millis();

    cyclingPauseCurrentMillis = millis();
    if ((cyclingPauseCurrentMillis - cyclingPausePreviousMillis >= cyclingPauseInterval) && cyclingPaused) {
      cyclingPaused = false;

      cycleComponentValues();
      cyclingPausePreviousMillis = cyclingPauseCurrentMillis;
      cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
    }

    /*
    if (reconnectCount >= 4 || reconnectCurrentMillis - reconnectPreviousMillis >= reconnectInterval) {
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

    checkForSubscribeCurrentMillis = millis();
    if (checkForSubscribeCurrentMillis - checkForSubscribePreviousMillis >= checkForSubscribeInterval) {
      checkForSubscribePreviousMillis = checkForSubscribeCurrentMillis;
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

    checkForPublishCurrentMillis = millis();
    if (checkForPublishCurrentMillis - checkForPublishPreviousMillis >= checkForPublishInterval) {
      checkForPublishPreviousMillis = checkForPublishCurrentMillis;
    
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

    publishAllCurrentMillis = millis();

    if (publishAllCurrentMillis - publishAllPreviousMillis >= publishAllInterval) {
      publishAll();
    }

    if (clear) {
      clearTextCurrentMillis = millis();
    }

    if (clearTextCurrentMillis - clearTextPreviousMillis >= clearTextInterval) {
      M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
      clearTextPreviousMillis = clearTextCurrentMillis;
      clear = false;
    }

    cycleComponentsCurrentMillis = millis();
    if (cycleComponentsCurrentMillis - cycleComponentsPreviousMillis >= cycleComponentsInterval) {
      cycleComponentValues();
      cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
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

    if (publishSoftwareVersionFlag) {
      publishSoftwareVersion();
      publishSoftwareVersionFlag = false;
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

  clearUpdateFlagsCurrentMillis = millis();
  if (confUpdateStep1 || internalUpdateStep1 || credUpdateStep1 || apiUpdateStep1) {
    if (clearUpdateFlagsCurrentMillis - clearUpdateFlagsPreviousMillis >= clearUpdateFlagsInterval) {
      clearUpdateFlags();
      clearUpdateFlagsPreviousMillis = clearUpdateFlagsCurrentMillis;
    }
  } else {
    clearUpdateFlagsPreviousMillis = clearUpdateFlagsCurrentMillis;
  }

  if (cfgServerMode) {
    ;
  }
  
  if (copyMode) {
    inputToOutputCopyRoutine();
  }
  
  if (!normalMode && timeOutCurrentMillis - timeOutPreviousMillis >= timeOutInterval) {
    returnToNormalOperation();
  }
}