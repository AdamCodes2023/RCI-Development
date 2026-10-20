/*
OFFICIAL RCI DEVICE PROGRAM
This is the Arduino Program for my Project called "RCI Device."
RCI stands for Remote Controlled Input.
The main functionality of this device revolves around receiving input data from a variety of sensors and publishing that information to over Radio.
A second RCI Device will receive those inputs and adjust its outputs accordingly.
This process will continue to work back and forth between the two RCI Devices for as long as they have power.
These devices are designed to be separated by long distances and connected through Radio antennas.
An example of a use case is having one RCI Device in a basement to measure temperature and another RCI Device upstairs connected to the house thermostat.
The RCI Device in the basement sends temperature data to the RCI Device upstairs.
When the temperature in the basement gets too low, the RCI Device upstairs will output to the thermostat to increase the temperature in the house.
The RCI Device has a maximum capacity of 8 ports for each type of input and output (Digital and Analog) for a total of 32 possible channels.
The Arduino Program runs on an M5Stack Core2 module with an ESP32 microchip.
*/

#include "M5StackRadio.h"

//#include <M5Core2.h>                              		//-- moved to arduinoGlue.h
//#include <SPI.h>                                  		//-- moved to arduinoGlue.h
//#include <Wire.h>                                 		//-- moved to arduinoGlue.h
//#include <Adafruit_ADS1X15.h>                     		//-- moved to arduinoGlue.h
//#include <Adafruit_MCP4728.h>                     		//-- moved to arduinoGlue.h
//#include <Adafruit_PCF8574.h>                     		//-- moved to arduinoGlue.h
//#include <SD.h>
//#include <Preferences.h>                          		//-- moved to arduinoGlue.h
#include "Arduino.h"
#include "buttons/buttons.h"
#include "config/config.h"
#include "cycling/cycling.h"
#include "fwupdate/fwupdate.h"
#include "modes/modes.h"
#include "receive/receive.h"
#include "screen/screen.h"
#include "send/send.h"
#include "signal/signal.h"
#include "utility/utility.h"
//#include <Update.h>                               		//-- moved to arduinoGlue.h

String configFileName = "";
String sdConfigFileName = "";

//### Feeds ###
String config_update_feed = String("");
String internal_update_feed = String("");
String credential_update_feed = String("");
String api_update_feed = String("");

String di1_feed = String("");
String di2_feed = String("");
String di3_feed = String("");
String di4_feed = String("");
String di5_feed = String("");
String di6_feed = String("");
String di7_feed = String("");
String di8_feed = String("");

String do1_feed = String("");
String do2_feed = String("");
String do3_feed = String("");
String do4_feed = String("");
String do5_feed = String("");
String do6_feed = String("");
String do7_feed = String("");
String do8_feed = String("");

String ai1_feed = String("");
String ai2_feed = String("");
String ai3_feed = String("");
String ai4_feed = String("");
String ai5_feed = String("");
String ai6_feed = String("");
String ai7_feed = String("");
String ai8_feed = String("");

String ao1_feed = String("");
String ao2_feed = String("");
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

String serns, macs, gids, uids, ions, dcs0, dcs1, dcs2, dcs3, dcs4, dcs5, dcs6, dcs7, acs0, acs1, acs2, acs3, acs4, acs5, acs6, acs7, upds, ssis, sqs, cns = String("");
String * configItems[25];

String hc0, hc1, hc2, hc3, hc4, hc5, hc6, hc7, hc8, hc9, hc10, hc11, hc12, hc13, hc14, hc15, hc16, hc17, hc18, hc19;
String * heartbeat_check_feeds[20];

const String globalZeroText = String("0");
bool noHandshakeDigitalInputFeeds[8] = {};
bool noHandshakeAnalogInputFeeds[8] = {};

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

HardwareSerial radioSerialRS232 = Serial2;
String sentRadioString = String("");
String receivedRadioString = String("");
bool radioStringArrived = false;
bool isHost = false;
int publishSelector = 0;
int numberOfRemoteUnits = 0;
bool publishAllFlag = false;
int connectedRemoteUnitIDs[20] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

String versionNumber = String("V 1.0");
String statusString = String("");
String signalQualityString = String("NR");
String signalStrengthString = String("NR");
bool receivingSignalQuality = false;
bool signalQualityCheckSuccessful = false;
bool firstSignalQualityCheck = true;

short cycleCounter = 0;
bool cyclingPaused = false;

//### TIMING VARIABLES ###
long long publishAllInterval = 10000;
const long clearTextInterval = 2000;
const long cycleComponentsInterval = 5000;
long checkForSubscribeInterval = 10000;
long checkForPublishInterval = 10000;
const long startUpInterval = 5000;
const long timeOutInterval = 180000;
const long commFailInterval = 300000;
const long long getTimeInterval = 86400000;
const long long apiAccessInterval = 3600000;
const long long apiAccessRequestInterval = 30000;
const long long requestSignalQualityInterval = 3600000;
const long long heartbeatPublishInterval = 60000;
const long long heartbeatCheckInterval = 180000;
const long cyclingPauseInterval = 300000;
const long long waitForDataQueryResponseInterval = 5000;

unsigned long publishAllPreviousMillis = 0;
unsigned long clearTextPreviousMillis = 0;
unsigned long cycleComponentsPreviousMillis = 0;
unsigned long checkForSubscribePreviousMillis = 0;
unsigned long checkForPublishPreviousMillis = 0;
unsigned long startUpPreviousMillis = 0;
unsigned long timeOutPreviousMillis = 0;
unsigned long commFailPreviousMillis = 0;
unsigned long long getTimePreviousMillis = 0;
unsigned long long apiAccessPreviousMillis = 0;
unsigned long long apiAccessRequestPreviousMillis = 0;
unsigned long long requestSignalQualityPreviousMillis = 0;
unsigned long long heartbeatPublishPreviousMillis = 0;
unsigned long long heartbeatCheckPreviousMillis[20] = {};
unsigned long long cyclingPausePreviousMillis = 0;
unsigned long long waitForDataQueryResponsePreviousMillis = 0;

unsigned long publishAllCurrentMillis = 0;
unsigned long clearTextCurrentMillis = 0;
unsigned long cycleComponentsCurrentMillis = 0;
unsigned long checkForSubscribeCurrentMillis = 0;
unsigned long checkForPublishCurrentMillis = 0;
unsigned long startUpCurrentMillis = 0;
unsigned long timeOutCurrentMillis = 0;
unsigned long commFailCurrentMillis = 0;
unsigned long long getTimeCurrentMillis = 0;
unsigned long long apiAccessCurrentMillis = 0;
unsigned long long apiAccessRequestCurrentMillis = 0;
unsigned long long requestSignalQualityCurrentMillis = 0;
unsigned long long heartbeatPublishCurrentMillis = 0;
unsigned long long heartbeatCheckCurrentMillis[20] = {};
unsigned long long cyclingPauseCurrentMillis = 0;
unsigned long long waitForDataQueryResponseCurrentMillis = 0;

//#MORE INITIAL VARIABLES
bool commFailToggledOnce = true;
bool clear = false;

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


// I/O VARIABLES
String payload = String("");
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

//### CONFIGURATION VARIABLES ###
const int chipSelect = 4;
File myFile;

Preferences preferences;
const char* pnamespace = "InternalInfo";
const char* serialKey = "SerialNumber";
String serialNumber = String("");

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
    preferences.end();
  }

  //RETREIVE IMPORTANT INTERNAL INFO
  preferences.begin(pnamespace);
  serialNumber = preferences.getString(serialKey);
  preferences.end();

  if (serialNumber.length() != 0) {
    *configItems[0] = "SN: " + serialNumber;
  }

  configFileName = serialNumber + ".txt";
  sdConfigFileName = "/" + configFileName;

  if (SD.exists(sdConfigFileName) == 1) {
    myFile = SD.open(sdConfigFileName);
    if (myFile.available() >= 1) {
      //GET RADIO INFO FROM SD CARD
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

  commFailCurrentMillis = millis();
  commFailPreviousMillis = commFailCurrentMillis;

  /*
  pinMode(G13, OUTPUT);
  pinMode(G14, OUTPUT);
  digitalWrite(G13, LOW);
  digitalWrite(G14, HIGH);
  */

  //radioSerialRS232.begin(baud-rate, protocol, RX pin, TX pin);.
  radioSerialRS232.begin(RS232_SERIAL_BAUD, SERIAL_8N1, RS232_RX_PIN, RS232_TX_PIN);
  radioSerialRS232.setTimeout(200);

  while (!radioSerialRS232) {
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

    String ai_feed = groupID + "_" + unitID + "_AI" + i;
    if (noHandshakeAnalogInputFeeds[i - 1]) {
      ai_feed = globalZeroText + "_AI" + i;
    }
    *ai_feeds[i - 1] = ai_feed;
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


  reconnectRadio();

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

  if (radioSerialRS232.available()) {
    receivedRadioString += char(radioSerialRS232.read());
    radioStringArrived = true;
  } else if (radioStringArrived) {
    onRadioMessage(receivedRadioString);
    receivedRadioString = String("");
    radioStringArrived = false;
  }

  requestSignalQualityCurrentMillis = millis();
  if (requestSignalQualityCurrentMillis - requestSignalQualityPreviousMillis >= requestSignalQualityInterval) {
    requestSignalQualityPreviousMillis = requestSignalQualityCurrentMillis;
    signalQualityCheckSuccessful = false;
  }

  if (receivingSignalQuality) {
    backgroundReceiveCellularSignalQuality(normalMode);
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
    cyclingPauseCurrentMillis = millis();
    if ((cyclingPauseCurrentMillis - cyclingPausePreviousMillis >= cyclingPauseInterval) && cyclingPaused) {
      cyclingPaused = false;

      cycleComponentValues();
      cyclingPausePreviousMillis = cyclingPauseCurrentMillis;
      cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
    }

    while (!radioSerialRS232) {
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
    if (!commFailToggledOnce) {
      commFailToggledOnce = true;
      if (digitalDebugSuccess) {
        pcfw2.digitalWrite(0, false);
      }
    }

    /*
    checkForSubscribeCurrentMillis = millis();
    if (checkForSubscribeCurrentMillis - checkForSubscribePreviousMillis >= checkForSubscribeInterval) {
      checkForSubscribePreviousMillis = checkForSubscribeCurrentMillis;
      //SUBSCRIPTION POLLING FOR RADIO?
    }
    */

    /*
    checkForPublishCurrentMillis = millis();
    if (checkForPublishCurrentMillis - checkForPublishPreviousMillis >= checkForPublishInterval) {
      checkForPublishPreviousMillis = checkForPublishCurrentMillis;
      //PUBLISH POLLING FOR RADIO?
    }
    */

    publishAllCurrentMillis = millis();
    //waitForDataQueryResponseCurrentMillis = millis();

    /*
    //DATA QUERY PAUSE
    if ((publishAllCurrentMillis - publishAllPreviousMillis >= publishAllInterval) && (waitForDataQueryResponseCurrentMillis - waitForDataQueryResponsePreviousMillis >= waitForDataQueryResponseInterval) && (isHost)) {
      if (publishSelector == 0) {
        // Save the last time a message was sent.
        publishAllPreviousMillis = publishAllCurrentMillis;
        publishAll();
      } else {
        // Save the last time a message was sent.
        waitForDataQueryResponsePreviousMillis = waitForDataQueryResponseCurrentMillis;
        publishDataQuery(connectedRemoteUnitIDs[publishSelector - 1]);
      }

      if (publishSelector == numberOfRemoteUnits) {
        publishSelector = 0;
      } else {
        publishSelector++;
      }
    }
    */

    //NO DATA QUERY PAUSE
    if ((publishAllCurrentMillis - publishAllPreviousMillis >= publishAllInterval) && (isHost)) {
      while (publishSelector <= numberOfRemoteUnits) {
        if (publishSelector == 0) {
          publishAll();
        } else {
          publishDataQuery(connectedRemoteUnitIDs[publishSelector - 1]);
        }

        publishSelector++;
        delay(150);
      }

      // Save the last time a message was sent.
      publishAllPreviousMillis = publishAllCurrentMillis;

      publishSelector = 0;
    }

    if (publishAllFlag) {
      publishAll();
      publishAllFlag = false;
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

  if (confUpdateStep2 && !confUpdateStep2PubOnce) {
    confConnect();
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