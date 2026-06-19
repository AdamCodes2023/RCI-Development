#ifndef ARDUINOGLUE_H
#define ARDUINOGLUE_H


//============ Includes ====================
#include <M5Core2.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <Adafruit_MCP4728.h>
#include <Adafruit_PCF8574.h>
#include <Preferences.h>
#include <Update.h>

//============ Defines & Macros ====================
#define RS232_RX_PIN G13 // Rx Pin
#define RS232_TX_PIN G14 // Tx Pin
#define RS232_SERIAL_BAUD 9600 // Baud Rate for ESP32 and MAX232 Communication

#define MESSAGING_HOST_UNIT_ID "01" // RCI Host Unit ID for Data Message Formatting

#define CARRIAGE_RETURN_CHARACTER char(0x0d) // Carriage Return Character
#define RADIO_MODEM_COMMAND_MODE_SEQUENCE "+++" // Raveon 150MHz Radio Modem Command Mode Sequence
#define RADIO_MODEM_DATA_MODE_SEQUENCE "ATCN" // Raveon 150MHz Radio Modem Data Mode Sequence
#define RADIO_MODEM_FACTORY_RESET_SEQUENCE "AT&F" // Raveon 150MHz Radio Modem Factory Reset Sequence
#define RADIO_MODEM_SAVE_SEQUENCE "ATSV" // Raveon 150MHz Radio Modem Save Sequence
#define RADIO_MODEM_DISABLE_ECHO_VALUE "0" // Radio Modem Disable Echo AT Command Value (0 = OFF)
#define RADIO_MODEM_SET_BAUD_RATE_VALUE "3" // Radio Modem Set Baud Rate AT Command Value (3 = 9600 Baud Rate)
#define RADIO_MODEM_SET_OTA_RATE_VALUE "3" // Radio Modem Set OTA Baud Rate AT Command Value (3 = 4800 Baud Rate)
#define RADIO_MODEM_SET_IO_CONFIG_VALUE "0" // Radio Modem Set IO Configuration AT Command Value (0 = RS232)
#define RADIO_MODEM_SET_HW_FLOW_CONTROL_VALUE "0" // Radio Modem Set Hardware Flow Control AT Command Value (0 = DISABLED)
#define RADIO_MODEM_SET_CARRIER_DETECT_VALUE "1" // Radio Modem Set Carrier Detect AT Command Value (1 = Data CD)
#define RADIO_MODEM_DESTINATION_ID_BROADCAST "00FF" // Radio Modem Destination Addresses (00-99)
#define RADIO_MODEM_DESTINATION_ID_HOST "00" + MESSAGING_HOST_UNIT_ID // Radio Modem Destination Address HOST ONLY (0000)
#define RADIO_MODEM_UNIT_ID_MASK "FF00" // Radio Modem Listener Addresses (00-99)
#define RADIO_MODEM_SET_RF_POWER_1PERCENT_VALUE "1" // Radio Modem Set RF Power AT Command Value (1% = 100mW)
#define RADIO_MODEM_SET_RF_POWER_50PERCENT_VALUE "50" // Radio Modem Set RF Power AT Command Value (50% = 1W)
#define RADIO_MODEM_SET_RF_POWER_100PERCENT_VALUE "100" // Radio Modem Set RF Power AT Command Value (100% = 2W)
#define RADIO_MODEM_SET_CHANNEL_1_VALUE "1" // Radio Modem Select Channel AT Command Value (1 = Channel 1)
#define RADIO_MODEM_SET_CHANNEL_2_VALUE "2" // Radio Modem Select Channel AT Command Value (2 = Channel 2)
#define RADIO_MODEM_SET_CHANNEL_3_VALUE "3" // Radio Modem Select Channel AT Command Value (3 = Channel 3)
#define RADIO_MODEM_SET_CHANNEL_4_VALUE "4" // Radio Modem Select Channel AT Command Value (4 = Channel 4)
#define RADIO_MODEM_SET_CHANNEL_5_VALUE "5" // Radio Modem Select Channel AT Command Value (5 = Channel 5)
#define RADIO_MODEM_SET_CHANNEL_6_VALUE "6" // Radio Modem Select Channel AT Command Value (6 = Channel 6)
#define RADIO_MODEM_TRANSMIT_TEST_VALUE "7" // Radio Modem Enter Transmit Test AT Command Value (7 = Transmit CW)
#define RADIO_MODEM_DISABLE_ECHO_ATCOMMAND "ATE" // Radio Modem Disable Echo AT Command
#define RADIO_MODEM_SET_BAUD_RATE_ATCOMMAND "ATBD" // Radio Modem Set Baud Rate AT Command
#define RADIO_MODEM_SET_OTA_RATE_ATCOMMAND "ATR2" // Radio Modem Set OTA Baud Rate AT Command
#define RADIO_MODEM_SET_IO_CONFIG_ATCOMMAND "ATIO" // Radio Modem Set IO Configuration AT Command
#define RADIO_MODEM_SET_HW_FLOW_CONTROL_ATCOMMAND "ATCH" // Radio Modem Set Hardware Flow Control AT Command
#define RADIO_MODEM_SET_CARRIER_DETECT_ATCOMMAND "ATR1" // Radio Modem Set Carrier Detect AT Command
#define RADIO_MODEM_CHANGE_GROUP_ID_ATCOMMAND "ATGP" // Radio Modem Change Group ID AT Command
#define RADIO_MODEM_CHANGE_UNIT_ID_ATCOMMAND "ATMY" // Radio Modem Change Unit ID AT Command
#define RADIO_MODEM_CHANGE_DESTINATION_IDS_ATCOMMAND "ATDT" // Radio Modem Change Destination Addresses AT Command
#define RADIO_MODEM_CHANGE_LISTENER_IDS_ATCOMMAND "ATMK" // Radio Modem Change Listener Addresses AT Command
#define RADIO_MODEM_SET_RF_POWER_ATCOMMAND "ATPO" // Radio Modem Set RF Power AT Command
#define RADIO_MODEM_SET_CHANNEL_ATCOMMAND "ATHP" // Radio Modem Select Channel AT Command
#define RADIO_MODEM_TRANSMIT_TEST_ATCOMMAND "ATTD" // Radio Modem Enter Transmit Test AT Command
#define RADIO_MODEM_GET_RSSI_ATCOMMAND "ATRS" // Radio Modem Get RSSI AT Command

//============ Extern Variables ============
extern String          IONum;                             		//-- from M5StackRadio
extern String          acs0;                              		//-- from M5StackRadio
extern String          acs1;                              		//-- from M5StackRadio
extern String          acs2;                              		//-- from M5StackRadio
extern String          acs3;                              		//-- from M5StackRadio
extern String          acs4;                              		//-- from M5StackRadio
extern String          acs5;                              		//-- from M5StackRadio
extern String          acs6;                              		//-- from M5StackRadio
extern String          acs7;                              		//-- from M5StackRadio
extern int16_t         adc0;                              		//-- from M5StackRadio
extern int16_t         adc0Prev;                          		//-- from M5StackRadio
extern int16_t         adc0second;                        		//-- from M5StackRadio
extern int16_t         adc0secondPrev;                    		//-- from M5StackRadio
extern int16_t         adc1;                              		//-- from M5StackRadio
extern int16_t         adc1Prev;                          		//-- from M5StackRadio
extern int16_t         adc1second;                        		//-- from M5StackRadio
extern int16_t         adc1secondPrev;                    		//-- from M5StackRadio
extern int16_t         adc2;                              		//-- from M5StackRadio
extern int16_t         adc2Prev;                          		//-- from M5StackRadio
extern int16_t         adc2second;                        		//-- from M5StackRadio
extern int16_t         adc2secondPrev;                    		//-- from M5StackRadio
extern int16_t         adc3;                              		//-- from M5StackRadio
extern int16_t         adc3Prev;                          		//-- from M5StackRadio
extern int16_t         adc3second;                        		//-- from M5StackRadio
extern int16_t         adc3secondPrev;                    		//-- from M5StackRadio
extern byte            address;                           		//-- from M5StackRadio
extern Adafruit_ADS1115 ads1115;                           		//-- from M5StackRadio
extern Adafruit_ADS1115 ads1115second;                     		//-- from M5StackRadio
extern String          af1ReadValue;                      		//-- from M5StackRadio
extern String          af2ReadValue;                      		//-- from M5StackRadio
extern String          af3ReadValue;                      		//-- from M5StackRadio
extern String          af4ReadValue;                      		//-- from M5StackRadio
extern String          af5ReadValue;                      		//-- from M5StackRadio
extern String          af6ReadValue;                      		//-- from M5StackRadio
extern String          af7ReadValue;                      		//-- from M5StackRadio
extern String          af8ReadValue;                      		//-- from M5StackRadio
extern String          ai1_feed;                          		//-- from M5StackRadio
extern String          ai1_value;                         		//-- from M5StackRadio
extern String          ai2_feed;                          		//-- from M5StackRadio
extern String          ai2_value;                         		//-- from M5StackRadio
extern String          ai3_feed;                          		//-- from M5StackRadio
extern String          ai3_value;                         		//-- from M5StackRadio
extern String          ai4_feed;                          		//-- from M5StackRadio
extern String          ai4_value;                         		//-- from M5StackRadio
extern String          ai5_feed;                          		//-- from M5StackRadio
extern String          ai5_value;                         		//-- from M5StackRadio
extern String          ai6_feed;                          		//-- from M5StackRadio
extern String          ai6_value;                         		//-- from M5StackRadio
extern String          ai7_feed;                          		//-- from M5StackRadio
extern String          ai7_value;                         		//-- from M5StackRadio
extern String          ai8_feed;                          		//-- from M5StackRadio
extern String          ai8_value;                         		//-- from M5StackRadio
extern String *        ai_feeds[8];                       		//-- from M5StackRadio
extern bool            analogInOneSuccess;                		//-- from M5StackRadio
extern bool            analogInTwoSuccess;                		//-- from M5StackRadio
extern bool            analogOutOneSuccess;               		//-- from M5StackRadio
extern bool            analogOutTwoSuccess;               		//-- from M5StackRadio
extern String          analyzedFailValue;                 		//-- from M5StackRadio
extern bool            ao1CommFailTriggered;              		//-- from M5StackRadio
extern double          ao1_fail_default;                  		//-- from M5StackRadio
extern String          ao1_feed;                          		//-- from M5StackRadio
extern String          ao1_value;                         		//-- from M5StackRadio
extern bool            ao2CommFailTriggered;              		//-- from M5StackRadio
extern double          ao2_fail_default;                  		//-- from M5StackRadio
extern String          ao2_feed;                          		//-- from M5StackRadio
extern String          ao2_value;                         		//-- from M5StackRadio
extern bool            ao3CommFailTriggered;              		//-- from M5StackRadio
extern double          ao3_fail_default;                  		//-- from M5StackRadio
extern String          ao3_feed;                          		//-- from M5StackRadio
extern String          ao3_value;                         		//-- from M5StackRadio
extern bool            ao4CommFailTriggered;              		//-- from M5StackRadio
extern double          ao4_fail_default;                  		//-- from M5StackRadio
extern String          ao4_feed;                          		//-- from M5StackRadio
extern String          ao4_value;                         		//-- from M5StackRadio
extern bool            ao5CommFailTriggered;              		//-- from M5StackRadio
extern double          ao5_fail_default;                  		//-- from M5StackRadio
extern String          ao5_feed;                          		//-- from M5StackRadio
extern String          ao5_value;                         		//-- from M5StackRadio
extern bool            ao6CommFailTriggered;              		//-- from M5StackRadio
extern double          ao6_fail_default;                  		//-- from M5StackRadio
extern String          ao6_feed;                          		//-- from M5StackRadio
extern String          ao6_value;                         		//-- from M5StackRadio
extern bool            ao7CommFailTriggered;              		//-- from M5StackRadio
extern double          ao7_fail_default;                  		//-- from M5StackRadio
extern String          ao7_feed;                          		//-- from M5StackRadio
extern String          ao7_value;                         		//-- from M5StackRadio
extern bool            ao8CommFailTriggered;              		//-- from M5StackRadio
extern double          ao8_fail_default;                  		//-- from M5StackRadio
extern String          ao8_feed;                          		//-- from M5StackRadio
extern String          ao8_value;                         		//-- from M5StackRadio
extern bool            apiUpdateStep1;                    		//-- from M5StackRadio
extern bool            apiUpdateStep1PubOnce;             		//-- from M5StackRadio
extern bool            apiUpdateStep2;                    		//-- from M5StackRadio
extern bool            apiUpdateStep2PubOnce;             		//-- from M5StackRadio
extern String          api_update_feed;                   		//-- from M5StackRadio
extern String          as0;                               		//-- from M5StackRadio
extern String          as1;                               		//-- from M5StackRadio
extern String          as2;                               		//-- from M5StackRadio
extern String          as3;                               		//-- from M5StackRadio
extern String          as4;                               		//-- from M5StackRadio
extern String          as5;                               		//-- from M5StackRadio
extern String          as6;                               		//-- from M5StackRadio
extern String          as7;                               		//-- from M5StackRadio
extern uint8_t         cardType;                          		//-- from M5StackRadio
extern bool            centerCyclingPausePressed;         		//-- from M5StackRadio
extern bool            centerCyclingScrollPressed;        		//-- from M5StackRadio
extern bool            centerPressedOnce;                 		//-- from M5StackRadio
extern Button          centerRed;                               //-- from M5StackRadio
extern bool            cfgServerMode;                     		//-- from M5StackRadio
extern const int       chipSelect;                        		//-- from M5StackRadio
extern bool            clear;                             		//-- from M5StackRadio
extern String          cns;                               		//-- from M5StackRadio
extern const long      commFailInterval;                  		//-- from M5StackRadio
extern bool            commFailToggledOnce;               		//-- from M5StackRadio
extern bool            confUpdateStep1;                   		//-- from M5StackRadio
extern bool            confUpdateStep1PubOnce;            		//-- from M5StackRadio
extern bool            confUpdateStep2;                   		//-- from M5StackRadio
extern bool            confUpdateStep2PubOnce;            		//-- from M5StackRadio
extern String          configFileName;                    		//-- from M5StackRadio
extern String *        configItems[25];                   		//-- from M5StackRadio
extern bool            configMenu1;                       		//-- from M5StackRadio
extern int             configMenu1Iterator;               		//-- from M5StackRadio
extern bool            configMenu2;                       		//-- from M5StackRadio
extern bool            configMenu3;                       		//-- from M5StackRadio
extern String          config_update_feed;                		//-- from M5StackRadio
extern String          consumerName;                      		//-- from M5StackRadio
extern bool            copyMode;                          		//-- from M5StackRadio
extern bool            credUpdateStep1;                   		//-- from M5StackRadio
extern bool            credUpdateStep1PubOnce;            		//-- from M5StackRadio
extern bool            credUpdateStep2;                   		//-- from M5StackRadio
extern bool            credUpdateStep2PubOnce;            		//-- from M5StackRadio
extern String          credential_update_feed;            		//-- from M5StackRadio
extern short           cycleCounter;                      		//-- from M5StackRadio
extern const long      cyclingPauseInterval;              		//-- from M5StackRadio
extern bool            cyclingPaused;                     		//-- from M5StackRadio
extern String          dcs0;                              		//-- from M5StackRadio
extern String          dcs1;                              		//-- from M5StackRadio
extern String          dcs2;                              		//-- from M5StackRadio
extern String          dcs3;                              		//-- from M5StackRadio
extern String          dcs4;                              		//-- from M5StackRadio
extern String          dcs5;                              		//-- from M5StackRadio
extern String          dcs6;                              		//-- from M5StackRadio
extern String          dcs7;                              		//-- from M5StackRadio
extern String          df1ReadValue;                      		//-- from M5StackRadio
extern String          df2ReadValue;                      		//-- from M5StackRadio
extern String          df3ReadValue;                      		//-- from M5StackRadio
extern String          df4ReadValue;                      		//-- from M5StackRadio
extern String          df5ReadValue;                      		//-- from M5StackRadio
extern String          df6ReadValue;                      		//-- from M5StackRadio
extern String          df7ReadValue;                      		//-- from M5StackRadio
extern String          df8ReadValue;                      		//-- from M5StackRadio
extern String          di1_feed;                          		//-- from M5StackRadio
extern String          di1_value;                         		//-- from M5StackRadio
extern String          di2_feed;                          		//-- from M5StackRadio
extern String          di2_value;                         		//-- from M5StackRadio
extern String          di3_feed;                          		//-- from M5StackRadio
extern String          di3_value;                         		//-- from M5StackRadio
extern String          di4_feed;                          		//-- from M5StackRadio
extern String          di4_value;                         		//-- from M5StackRadio
extern String          di5_feed;                          		//-- from M5StackRadio
extern String          di5_value;                         		//-- from M5StackRadio
extern String          di6_feed;                          		//-- from M5StackRadio
extern String          di6_value;                         		//-- from M5StackRadio
extern String          di7_feed;                          		//-- from M5StackRadio
extern String          di7_value;                         		//-- from M5StackRadio
extern String          di8_feed;                          		//-- from M5StackRadio
extern String          di8_value;                         		//-- from M5StackRadio
extern String *        di_feeds[8];                       		//-- from M5StackRadio
extern bool            digitalDebugSuccess;               		//-- from M5StackRadio
extern bool            digitalInputSuccess;               		//-- from M5StackRadio
extern bool            digitalOutputSuccess;              		//-- from M5StackRadio
extern bool            do1CommFailTriggered;              		//-- from M5StackRadio
extern int             do1_fail_default;                  		//-- from M5StackRadio
extern String          do1_feed;                          		//-- from M5StackRadio
extern String          do1_value;                         		//-- from M5StackRadio
extern bool            do2CommFailTriggered;              		//-- from M5StackRadio
extern int             do2_fail_default;                  		//-- from M5StackRadio
extern String          do2_feed;                          		//-- from M5StackRadio
extern String          do2_value;                         		//-- from M5StackRadio
extern bool            do3CommFailTriggered;              		//-- from M5StackRadio
extern int             do3_fail_default;                  		//-- from M5StackRadio
extern String          do3_feed;                          		//-- from M5StackRadio
extern String          do3_value;                         		//-- from M5StackRadio
extern bool            do4CommFailTriggered;              		//-- from M5StackRadio
extern int             do4_fail_default;                  		//-- from M5StackRadio
extern String          do4_feed;                          		//-- from M5StackRadio
extern String          do4_value;                         		//-- from M5StackRadio
extern bool            do5CommFailTriggered;              		//-- from M5StackRadio
extern int             do5_fail_default;                  		//-- from M5StackRadio
extern String          do5_feed;                          		//-- from M5StackRadio
extern String          do5_value;                         		//-- from M5StackRadio
extern bool            do6CommFailTriggered;              		//-- from M5StackRadio
extern int             do6_fail_default;                  		//-- from M5StackRadio
extern String          do6_feed;                          		//-- from M5StackRadio
extern String          do6_value;                         		//-- from M5StackRadio
extern bool            do7CommFailTriggered;              		//-- from M5StackRadio
extern int             do7_fail_default;                  		//-- from M5StackRadio
extern String          do7_feed;                          		//-- from M5StackRadio
extern String          do7_value;                         		//-- from M5StackRadio
extern bool            do8CommFailTriggered;              		//-- from M5StackRadio
extern int             do8_fail_default;                  		//-- from M5StackRadio
extern String          do8_feed;                          		//-- from M5StackRadio
extern String          do8_value;                         		//-- from M5StackRadio
extern String          ds0;                               		//-- from M5StackRadio
extern String          ds1;                               		//-- from M5StackRadio
extern String          ds2;                               		//-- from M5StackRadio
extern String          ds3;                               		//-- from M5StackRadio
extern String          ds4;                               		//-- from M5StackRadio
extern String          ds5;                               		//-- from M5StackRadio
extern String          ds6;                               		//-- from M5StackRadio
extern String          ds7;                               		//-- from M5StackRadio
extern byte            error;                             		//-- from M5StackRadio
extern String          errorCode;                         		//-- from M5StackRadio
extern bool            firstSignalQualityCheck;           		//-- from M5StackRadio
extern bool            forceUpdate;                       		//-- from M5StackRadio
extern String          gids;                              		//-- from M5StackRadio
extern const String    globalZeroText;                    		//-- from M5StackRadio
extern String          groupID;                           		//-- from M5StackRadio
extern bool            hasConfigInfo;                     		//-- from M5StackRadio
extern String          hc0;                               		//-- from M5StackRadio
extern String          hc1;                               		//-- from M5StackRadio
extern String          hc10;                              		//-- from M5StackRadio
extern String          hc11;                              		//-- from M5StackRadio
extern String          hc12;                              		//-- from M5StackRadio
extern String          hc13;                              		//-- from M5StackRadio
extern String          hc14;                              		//-- from M5StackRadio
extern String          hc15;                              		//-- from M5StackRadio
extern String          hc16;                              		//-- from M5StackRadio
extern String          hc17;                              		//-- from M5StackRadio
extern String          hc18;                              		//-- from M5StackRadio
extern String          hc19;                              		//-- from M5StackRadio
extern String          hc2;                               		//-- from M5StackRadio
extern String          hc3;                               		//-- from M5StackRadio
extern String          hc4;                               		//-- from M5StackRadio
extern String          hc5;                               		//-- from M5StackRadio
extern String          hc6;                               		//-- from M5StackRadio
extern String          hc7;                               		//-- from M5StackRadio
extern String          hc8;                               		//-- from M5StackRadio
extern String          hc9;                               		//-- from M5StackRadio
extern bool            heartbeatCheckAlreadySetFailDefaults[20];		//-- from M5StackRadio
extern String          heartbeatCheckUnitID;              		//-- from M5StackRadio
extern bool            heartbeatCommFail;                 		//-- from M5StackRadio
extern String          heartbeatSubscriptionsString;      		//-- from M5StackRadio
extern String *        heartbeat_check_feeds[20];         		//-- from M5StackRadio
extern bool            initialSDCheck;                    		//-- from M5StackRadio
extern bool            internalUpdateStep1;               		//-- from M5StackRadio
extern bool            internalUpdateStep1PubOnce;        		//-- from M5StackRadio
extern bool            internalUpdateStep2;               		//-- from M5StackRadio
extern bool            internalUpdateStep2PubOnce;        		//-- from M5StackRadio
extern String          internal_update_feed;              		//-- from M5StackRadio
extern long long       publishAllInterval;                      //-- from M5StackRadio
extern const long      clearTextInterval;                       //-- from M5StackRadio
extern const long      cycleComponentsInterval;                 //-- from M5StackRadio
extern long            checkForSubscribeInterval;               //-- from M5StackRadio
extern long            checkForPublishInterval;                 //-- from M5StackRadio
extern bool            ioKnown;                           		//-- from M5StackRadio
extern String          ions;                              		//-- from M5StackRadio
extern bool            leftCyclingPausePressed;           		//-- from M5StackRadio
extern bool            leftCyclingScrollPressed;          		//-- from M5StackRadio
extern bool            leftPressedOnce;                   		//-- from M5StackRadio
extern bool            leftPressedThree;                  		//-- from M5StackRadio
extern bool            leftPressedTwice;                  		//-- from M5StackRadio
extern Button          leftRed;                           		//-- from M5StackRadio
extern String          macs;                              		//-- from M5StackRadio
extern int             maxHeartbeatChecks;                		//-- from M5StackRadio
extern File            myFile;                            		//-- from M5StackRadio
extern int             nDevices;                          		//-- from M5StackRadio
extern bool            noHandshakeAnalogInputFeeds[8];    		//-- from M5StackRadio
extern bool            noHandshakeDigitalInputFeeds[8];   		//-- from M5StackRadio
extern bool            normalMode;                        		//-- from M5StackRadio
extern String          payload;                           		//-- from M5StackRadio
extern Adafruit_PCF8574 pcfr;                              		//-- from M5StackRadio
extern int             pcfr0Prev;                         		//-- from M5StackRadio
extern int             pcfr0Test;                         		//-- from M5StackRadio
extern int             pcfr1Prev;                         		//-- from M5StackRadio
extern int             pcfr1Test;                         		//-- from M5StackRadio
extern int             pcfr2Prev;                         		//-- from M5StackRadio
extern int             pcfr2Test;                         		//-- from M5StackRadio
extern int             pcfr3Prev;                         		//-- from M5StackRadio
extern int             pcfr3Test;                         		//-- from M5StackRadio
extern int             pcfr4Prev;                         		//-- from M5StackRadio
extern int             pcfr4Test;                         		//-- from M5StackRadio
extern int             pcfr5Prev;                         		//-- from M5StackRadio
extern int             pcfr5Test;                         		//-- from M5StackRadio
extern int             pcfr6Prev;                         		//-- from M5StackRadio
extern int             pcfr6Test;                         		//-- from M5StackRadio
extern int             pcfr7Prev;                         		//-- from M5StackRadio
extern int             pcfr7Test;                         		//-- from M5StackRadio
extern Adafruit_PCF8574 pcfw1;                             		//-- from M5StackRadio
extern Adafruit_PCF8574 pcfw2;                             		//-- from M5StackRadio
extern const char*     pnamespace;                        		//-- from M5StackRadio
extern bool            preCheckSD;                        		//-- from M5StackRadio
extern Preferences     preferences;                       		//-- from M5StackRadio
extern HardwareSerial  radioSerialRS232;                        //-- from M5StackRadio
extern String          rciTitle;                          		//-- from M5StackRadio
extern bool            receivingSignalQuality;            		//-- from M5StackRadio
extern bool            reconnect;                         		//-- from M5StackRadio
extern bool            reconnectFirstMessageStatus;       		//-- from M5StackRadio
extern bool            rightCyclingUnpausePressed;        		//-- from M5StackRadio
extern bool            rightPressedFour;                  		//-- from M5StackRadio
extern bool            rightPressedOnce;                  		//-- from M5StackRadio
extern bool            rightPressedThree;                 		//-- from M5StackRadio
extern bool            rightPressedTwice;                 		//-- from M5StackRadio
extern Button          rightRed;                          		//-- from M5StackRadio
extern String          sdConfigFileName;                  		//-- from M5StackRadio
extern const char*     serialKey;                         		//-- from M5StackRadio
extern String          serialNumber;                      		//-- from M5StackRadio
extern String          serns;                             		//-- from M5StackRadio
extern bool            signalQualityCheckSuccessful;      		//-- from M5StackRadio
extern String          signalQualityString;               		//-- from M5StackRadio
extern String          signalStrengthString;              		//-- from M5StackRadio
extern String          sqs;                               		//-- from M5StackRadio
extern String          ssis;                              		//-- from M5StackRadio
extern const long      startUpInterval;                   		//-- from M5StackRadio
extern bool            startUpMode;                       		//-- from M5StackRadio
extern String          statusString;                      		//-- from M5StackRadio
extern int             subCount;                          		//-- from M5StackRadio
extern int             testadc0;                          		//-- from M5StackRadio
extern int             testadc1;                          		//-- from M5StackRadio
extern int             testadc2;                          		//-- from M5StackRadio
extern int             testadc3;                          		//-- from M5StackRadio
extern int             testadc4;                          		//-- from M5StackRadio
extern int             testadc5;                          		//-- from M5StackRadio
extern int             testadc6;                          		//-- from M5StackRadio
extern int             testadc7;                          		//-- from M5StackRadio
extern const long      timeOutInterval;                   		//-- from M5StackRadio
extern bool            triggerSound;                            //-- from M5StackRadio
extern String          uids;                              		//-- from M5StackRadio
extern String          unitID;                            		//-- from M5StackRadio
extern String          updateTime;                        		//-- from M5StackRadio
extern String          upds;                              		//-- from M5StackRadio
extern String          versionNumber;                     		//-- from M5StackRadio
extern int             viewConfigItemsIterator;           		//-- from M5StackRadio
extern bool            warningMenu1;                      		//-- from M5StackRadio
extern bool            warningMenu2;                      		//-- from M5StackRadio
extern unsigned long publishAllPreviousMillis;
extern unsigned long clearTextPreviousMillis;
extern unsigned long cycleComponentsPreviousMillis;
extern unsigned long checkForSubscribePreviousMillis;
extern unsigned long checkForPublishPreviousMillis;
extern unsigned long startUpPreviousMillis;
extern unsigned long timeOutPreviousMillis;
extern unsigned long commFailPreviousMillis;
extern unsigned long long getTimePreviousMillis;
extern unsigned long long apiAccessPreviousMillis;
extern unsigned long long apiAccessRequestPreviousMillis;
extern unsigned long long requestSignalQualityPreviousMillis;
extern unsigned long long heartbeatPublishPreviousMillis;
extern unsigned long long heartbeatCheckPreviousMillis[20];
extern unsigned long long cyclingPausePreviousMillis;
extern unsigned long publishAllCurrentMillis;
extern unsigned long clearTextCurrentMillis;
extern unsigned long cycleComponentsCurrentMillis;
extern unsigned long checkForSubscribeCurrentMillis;
extern unsigned long checkForPublishCurrentMillis;
extern unsigned long startUpCurrentMillis;
extern unsigned long timeOutCurrentMillis;
extern unsigned long commFailCurrentMillis;
extern unsigned long long getTimeCurrentMillis;
extern unsigned long long apiAccessCurrentMillis;
extern unsigned long long apiAccessRequestCurrentMillis;
extern unsigned long long requestSignalQualityCurrentMillis;
extern unsigned long long heartbeatPublishCurrentMillis;
extern unsigned long long heartbeatCheckCurrentMillis[20];
extern unsigned long long cyclingPauseCurrentMillis;
extern String sentRadioString;
extern String receivedRadioString;
extern bool radioStringArrived;
extern bool isHost;
extern int publishSelector;
extern int numberOfRemoteUnits;
extern bool publishAllFlag;
extern int connectedRemoteUnitIDs[20];
extern const long long waitForDataQueryResponseInterval;
extern unsigned long long waitForDataQueryResponsePreviousMillis;
extern unsigned long long waitForDataQueryResponseCurrentMillis;
extern bool radioGettingRSSI;
extern const long long waitForSignalQueryResponseInterval;
extern unsigned long long waitForSignalQueryResponsePreviousMillis;
extern unsigned long long waitForSignalQueryResponseCurrentMillis;
extern bool testingSignal;
extern const long long signalTestInterval;
extern unsigned long long signalTestPreviousMillis;
extern unsigned long long signalTestCurrentMillis;
extern int signalSelector;
extern int unitRSSIs[20];
extern short signalCounter;
extern String radioModemSelectedRFPower;
extern String radioModemSelectedChannel;

//============ Function Prototypes =========
//-- from M5StackRadio.ino -----------
int pingI2cAddress(byte address);                           
void replaceText(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int textSize, String text);
void cycleComponentValues();                                
void onLeftPress();                                         
void onLeftRelease();                                       
void onCenterPress();                                       
void onCenterRelease();                                     
void onRightPress();                                        
void onRightRelease();                                      
void inputToOutputCopyRoutine();                            
void publishDI1();                                                                         
void publishDI2();                                                                         
void publishDI3();                                                                           
void publishDI4();                                                                            
void publishDI5();                                                                        
void publishDI6();                                                                       
void publishDI7();                                                                           
void publishDI8();                                                                      
void publishAI1();                                                                          
void publishAI2();                                                                        
void publishAI3();                                                                           
void publishAI4();                                                                            
void publishAI5();                                                                       
void publishAI6();                                                                          
void publishAI7();                                                                        
void publishAI8();                                                                        
void publishAll();     
void publishDataQuery(int targetUnitID);
void publishSignalSend();
void publishSignalQuery(int targetUnitID);                                   
void cycleConfigItems(int startIndex);                      
void onRadioMessage(int messageSize);                       
void fillCharArray(char* charArray, String string);         
void configConnect();                                       
void confConnect();                                         
void performUpdate(Stream &updateSource, size_t updateSize);
void updateFromFS(fs::FS &fs);                              
void reconnectMqtt();                                       
void analyzeFTPFileContents(String topic);                  
void analyzeSDCardContents();                               
void createHeartbeatSubscriptionArrays(String subscriptions);
void checkHeartbeatSubscriptionArrays(String subscription); 
void setGroupMemberLossOfCommunicationDefaults(String subscription);
void returnToNormalOperation();                                                     
int calculateCellularSignalQualityBars(int signalStrengthValue);
void displayCellularSignalQuality();                        
void rebootEspWithReason(String reason);     
void collectRemoteUnitIDs(String remoteUnitID);               
void radioModemEnterCommandMode();
void radioModemEnterDataMode();
void radioModemFactoryReset();
void radioModemSaveParameters();
void radioModemDisableEcho();
void radioModemSetBaudRate();
void radioModemSetOTARate();
void radioModemSetIOConfig();
void radioModemSetHWFlowControl();
void radioModemSetCarrierDetect();
void radioModemSetGroupID();
void radioModemSetUnitID();
void radioModemSetDestinationIDs();
void radioModemSetListenerIDs();
void radioModemSetRFPower();
void radioModemSetRFPower(String radioModemSetRFPowerValue);
void radioModemSetChannel();
void radioModemSetChannel(String radioModemSetChannelValue);
void radioModemEnterTransmitTest();
void radioModemExitTransmitTest();
void radioModemGetRSSI();
void initializeRadioModem();
void getRadioSignal();

#endif // ARDUINOGLUE_H