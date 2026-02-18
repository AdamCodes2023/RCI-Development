#ifndef ARDUINOGLUE_H
#define ARDUINOGLUE_H


//============ Includes ====================
#include <SSLClient.h>
#include <ArduinoMqttClient.h>
#include <M5Core2.h>
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <Adafruit_MCP4728.h>
#include <Adafruit_PCF8574.h>
#include <Preferences.h>
#include <FTPClient_Generic.h>
#include <TimeLib.h>
#include <Update.h>
#include <ArduinoJson.h>

//============ Defines & Macros====================
#define VIEWABLE_DEVICE_INFO_INDEX_RANGE       4
#define RSSI_DEVICE_INFO_INDEX                 22
#define SIGNAL_QUALITY_DEVICE_INFO_INDEX       23
#define USING_VSFTP_SERVER                     false

//============ Extern Variables ============
extern String          AUTH_PATH_NAME;                    		//-- from M5StackMQTTFTP
extern char            HOST_NAME[];                       		//-- from M5StackMQTTFTP
extern String          HTTP_GET_METHOD;                   		//-- from M5StackMQTTFTP
extern String          HTTP_METHOD;                       		//-- from M5StackMQTTFTP
extern int             HTTP_PORT;                         		//-- from M5StackMQTTFTP
extern String          HTTP_POST_METHOD;                  		//-- from M5StackMQTTFTP
extern String          INFO_PATH_NAME;                    		//-- from M5StackMQTTFTP
extern String          IONum;                             		//-- from M5StackMQTTFTP
extern const int       NTP_PACKET_SIZE;                   		//-- from M5StackMQTTFTP
extern String          PATH_NAME;                         		//-- from M5StackMQTTFTP
extern String          REFRESH_PATH_NAME;                 		//-- from M5StackMQTTFTP
extern EthernetUDP     Udp;                               		//-- from M5StackMQTTFTP
extern String          acs0;                              		//-- from M5StackMQTTFTP
extern String          acs1;                              		//-- from M5StackMQTTFTP
extern String          acs2;                              		//-- from M5StackMQTTFTP
extern String          acs3;                              		//-- from M5StackMQTTFTP
extern String          acs4;                              		//-- from M5StackMQTTFTP
extern String          acs5;                              		//-- from M5StackMQTTFTP
extern String          acs6;                              		//-- from M5StackMQTTFTP
extern String          acs7;                              		//-- from M5StackMQTTFTP
extern int16_t         adc0;                              		//-- from M5StackMQTTFTP
extern int16_t         adc0Prev;                          		//-- from M5StackMQTTFTP
extern int16_t         adc0second;                        		//-- from M5StackMQTTFTP
extern int16_t         adc0secondPrev;                    		//-- from M5StackMQTTFTP
extern int16_t         adc1;                              		//-- from M5StackMQTTFTP
extern int16_t         adc1Prev;                          		//-- from M5StackMQTTFTP
extern int16_t         adc1second;                        		//-- from M5StackMQTTFTP
extern int16_t         adc1secondPrev;                    		//-- from M5StackMQTTFTP
extern int16_t         adc2;                              		//-- from M5StackMQTTFTP
extern int16_t         adc2Prev;                          		//-- from M5StackMQTTFTP
extern int16_t         adc2second;                        		//-- from M5StackMQTTFTP
extern int16_t         adc2secondPrev;                    		//-- from M5StackMQTTFTP
extern int16_t         adc3;                              		//-- from M5StackMQTTFTP
extern int16_t         adc3Prev;                          		//-- from M5StackMQTTFTP
extern int16_t         adc3second;                        		//-- from M5StackMQTTFTP
extern int16_t         adc3secondPrev;                    		//-- from M5StackMQTTFTP
extern byte            address;                           		//-- from M5StackMQTTFTP
extern Adafruit_ADS1115 ads1115;                           		//-- from M5StackMQTTFTP
extern Adafruit_ADS1115 ads1115second;                     		//-- from M5StackMQTTFTP
extern String          af1ReadValue;                      		//-- from M5StackMQTTFTP
extern String          af2ReadValue;                      		//-- from M5StackMQTTFTP
extern String          af3ReadValue;                      		//-- from M5StackMQTTFTP
extern String          af4ReadValue;                      		//-- from M5StackMQTTFTP
extern String          af5ReadValue;                      		//-- from M5StackMQTTFTP
extern String          af6ReadValue;                      		//-- from M5StackMQTTFTP
extern String          af7ReadValue;                      		//-- from M5StackMQTTFTP
extern String          af8ReadValue;                      		//-- from M5StackMQTTFTP
extern int             ai1LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            ai1Recv;                           		//-- from M5StackMQTTFTP
extern bool            ai1Sent;                           		//-- from M5StackMQTTFTP
extern String          ai1_feed;                          		//-- from M5StackMQTTFTP
extern String          ai1_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ai1_value;                         		//-- from M5StackMQTTFTP
extern int             ai2LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            ai2Recv;                           		//-- from M5StackMQTTFTP
extern bool            ai2Sent;                           		//-- from M5StackMQTTFTP
extern String          ai2_feed;                          		//-- from M5StackMQTTFTP
extern String          ai2_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ai2_value;                         		//-- from M5StackMQTTFTP
extern int             ai3LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            ai3Recv;                           		//-- from M5StackMQTTFTP
extern bool            ai3Sent;                           		//-- from M5StackMQTTFTP
extern String          ai3_feed;                          		//-- from M5StackMQTTFTP
extern String          ai3_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ai3_value;                         		//-- from M5StackMQTTFTP
extern int             ai4LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            ai4Recv;                           		//-- from M5StackMQTTFTP
extern bool            ai4Sent;                           		//-- from M5StackMQTTFTP
extern String          ai4_feed;                          		//-- from M5StackMQTTFTP
extern String          ai4_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ai4_value;                         		//-- from M5StackMQTTFTP
extern int             ai5LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            ai5Recv;                           		//-- from M5StackMQTTFTP
extern bool            ai5Sent;                           		//-- from M5StackMQTTFTP
extern String          ai5_feed;                          		//-- from M5StackMQTTFTP
extern String          ai5_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ai5_value;                         		//-- from M5StackMQTTFTP
extern int             ai6LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            ai6Recv;                           		//-- from M5StackMQTTFTP
extern bool            ai6Sent;                           		//-- from M5StackMQTTFTP
extern String          ai6_feed;                          		//-- from M5StackMQTTFTP
extern String          ai6_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ai6_value;                         		//-- from M5StackMQTTFTP
extern int             ai7LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            ai7Recv;                           		//-- from M5StackMQTTFTP
extern bool            ai7Sent;                           		//-- from M5StackMQTTFTP
extern String          ai7_feed;                          		//-- from M5StackMQTTFTP
extern String          ai7_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ai7_value;                         		//-- from M5StackMQTTFTP
extern int             ai8LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            ai8Recv;                           		//-- from M5StackMQTTFTP
extern bool            ai8Sent;                           		//-- from M5StackMQTTFTP
extern String          ai8_feed;                          		//-- from M5StackMQTTFTP
extern String          ai8_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ai8_value;                         		//-- from M5StackMQTTFTP
extern String *        ai_feedsACK[8];                    		//-- from M5StackMQTTFTP
extern String *        ai_feeds[8];                       		//-- from M5StackMQTTFTP
extern bool            analogInOneSuccess;                		//-- from M5StackMQTTFTP
extern bool            analogInTwoSuccess;                		//-- from M5StackMQTTFTP
extern bool            analogOutOneSuccess;               		//-- from M5StackMQTTFTP
extern bool            analogOutTwoSuccess;               		//-- from M5StackMQTTFTP
extern String          analyzedFailValue;                 		//-- from M5StackMQTTFTP
extern bool            ao1CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            ao1Recv;                           		//-- from M5StackMQTTFTP
extern double          ao1_fail_default;                  		//-- from M5StackMQTTFTP
extern String          ao1_feed;                          		//-- from M5StackMQTTFTP
extern String          ao1_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ao1_value;                         		//-- from M5StackMQTTFTP
extern bool            ao2CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            ao2Recv;                           		//-- from M5StackMQTTFTP
extern double          ao2_fail_default;                  		//-- from M5StackMQTTFTP
extern String          ao2_feed;                          		//-- from M5StackMQTTFTP
extern String          ao2_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ao2_value;                         		//-- from M5StackMQTTFTP
extern bool            ao3CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            ao3Recv;                           		//-- from M5StackMQTTFTP
extern double          ao3_fail_default;                  		//-- from M5StackMQTTFTP
extern String          ao3_feed;                          		//-- from M5StackMQTTFTP
extern String          ao3_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ao3_value;                         		//-- from M5StackMQTTFTP
extern bool            ao4CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            ao4Recv;                           		//-- from M5StackMQTTFTP
extern double          ao4_fail_default;                  		//-- from M5StackMQTTFTP
extern String          ao4_feed;                          		//-- from M5StackMQTTFTP
extern String          ao4_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ao4_value;                         		//-- from M5StackMQTTFTP
extern bool            ao5CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            ao5Recv;                           		//-- from M5StackMQTTFTP
extern double          ao5_fail_default;                  		//-- from M5StackMQTTFTP
extern String          ao5_feed;                          		//-- from M5StackMQTTFTP
extern String          ao5_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ao5_value;                         		//-- from M5StackMQTTFTP
extern bool            ao6CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            ao6Recv;                           		//-- from M5StackMQTTFTP
extern double          ao6_fail_default;                  		//-- from M5StackMQTTFTP
extern String          ao6_feed;                          		//-- from M5StackMQTTFTP
extern String          ao6_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ao6_value;                         		//-- from M5StackMQTTFTP
extern bool            ao7CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            ao7Recv;                           		//-- from M5StackMQTTFTP
extern double          ao7_fail_default;                  		//-- from M5StackMQTTFTP
extern String          ao7_feed;                          		//-- from M5StackMQTTFTP
extern String          ao7_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ao7_value;                         		//-- from M5StackMQTTFTP
extern bool            ao8CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            ao8Recv;                           		//-- from M5StackMQTTFTP
extern double          ao8_fail_default;                  		//-- from M5StackMQTTFTP
extern String          ao8_feed;                          		//-- from M5StackMQTTFTP
extern String          ao8_feedACK;                       		//-- from M5StackMQTTFTP
extern String          ao8_value;                         		//-- from M5StackMQTTFTP
extern bool            apiAccessGranted;                  		//-- from M5StackMQTTFTP
extern bool            apiAccessRequestSent;              		//-- from M5StackMQTTFTP
extern String          apiString;                         		//-- from M5StackMQTTFTP
extern bool            apiUpdateStep1;                    		//-- from M5StackMQTTFTP
extern bool            apiUpdateStep1PubOnce;             		//-- from M5StackMQTTFTP
extern bool            apiUpdateStep2;                    		//-- from M5StackMQTTFTP
extern bool            apiUpdateStep2PubOnce;             		//-- from M5StackMQTTFTP
extern String          api_update_feed;                   		//-- from M5StackMQTTFTP
extern String          as0;                               		//-- from M5StackMQTTFTP
extern String          as0ACK;                            		//-- from M5StackMQTTFTP
extern String          as1;                               		//-- from M5StackMQTTFTP
extern String          as1ACK;                            		//-- from M5StackMQTTFTP
extern String          as2;                               		//-- from M5StackMQTTFTP
extern String          as2ACK;                            		//-- from M5StackMQTTFTP
extern String          as3;                               		//-- from M5StackMQTTFTP
extern String          as3ACK;                            		//-- from M5StackMQTTFTP
extern String          as4;                               		//-- from M5StackMQTTFTP
extern String          as4ACK;                            		//-- from M5StackMQTTFTP
extern String          as5;                               		//-- from M5StackMQTTFTP
extern String          as5ACK;                            		//-- from M5StackMQTTFTP
extern String          as6;                               		//-- from M5StackMQTTFTP
extern String          as6ACK;                            		//-- from M5StackMQTTFTP
extern String          as7;                               		//-- from M5StackMQTTFTP
extern String          as7ACK;                            		//-- from M5StackMQTTFTP
extern String          broker;                            		//-- from M5StackMQTTFTP
extern uint8_t         cardType;                          		//-- from M5StackMQTTFTP
extern bool            cellModemRefreshSuccessful;        		//-- from M5StackMQTTFTP
extern bool            centerCyclingPausePressed;         		//-- from M5StackMQTTFTP
extern bool            centerCyclingScrollPressed;        		//-- from M5StackMQTTFTP
extern bool            centerPressedOnce;                 		//-- from M5StackMQTTFTP
extern bool            cfgServerMode;                     		//-- from M5StackMQTTFTP
extern const int       chipSelect;                        		//-- from M5StackMQTTFTP
extern bool            clear;                             		//-- from M5StackMQTTFTP
extern String          cns;                               		//-- from M5StackMQTTFTP
extern const long long     commFailInterval;                  		//-- from M5StackMQTTFTP
extern bool            commFailToggledOnce;               		//-- from M5StackMQTTFTP
extern bool            confUpdateStep1;                   		//-- from M5StackMQTTFTP
extern bool            confUpdateStep1PubOnce;            		//-- from M5StackMQTTFTP
extern bool            confUpdateStep2;                   		//-- from M5StackMQTTFTP
extern bool            confUpdateStep2PubOnce;            		//-- from M5StackMQTTFTP
extern int             configAo1Counter;                  		//-- from M5StackMQTTFTP
extern long            configAo1Value;                    		//-- from M5StackMQTTFTP
extern long            configAo2Value;                    		//-- from M5StackMQTTFTP
extern String          configFileName;                    		//-- from M5StackMQTTFTP
extern String *        configItems[25];                   		//-- from M5StackMQTTFTP
extern bool            configMenu1;                       		//-- from M5StackMQTTFTP
extern int             configMenu1Iterator;               		//-- from M5StackMQTTFTP
extern bool            configMenu2;                       		//-- from M5StackMQTTFTP
extern bool            configMenu3;                       		//-- from M5StackMQTTFTP
extern String          config_update_feed;                		//-- from M5StackMQTTFTP
extern String          connected_feed_publish;            		//-- from M5StackMQTTFTP
extern String          connected_feed_publishACK;         		//-- from M5StackMQTTFTP
extern String          connected_feed_subscribe;          		//-- from M5StackMQTTFTP
extern String          connected_feed_subscribeACK;       		//-- from M5StackMQTTFTP
extern String          consumerName;                      		//-- from M5StackMQTTFTP
extern bool            copyMode;                          		//-- from M5StackMQTTFTP
extern bool            credUpdateStep1;                   		//-- from M5StackMQTTFTP
extern bool            credUpdateStep1PubOnce;            		//-- from M5StackMQTTFTP
extern bool            credUpdateStep2;                   		//-- from M5StackMQTTFTP
extern bool            credUpdateStep2PubOnce;            		//-- from M5StackMQTTFTP
extern String          credential_update_feed;            		//-- from M5StackMQTTFTP
extern short           cycleCounter;                      		//-- from M5StackMQTTFTP
extern const long long     cyclingPauseInterval;              		//-- from M5StackMQTTFTP
extern bool            cyclingPaused;                     		//-- from M5StackMQTTFTP
extern String          dateString;                        		//-- from M5StackMQTTFTP
extern String          dcs0;                              		//-- from M5StackMQTTFTP
extern String          dcs1;                              		//-- from M5StackMQTTFTP
extern String          dcs2;                              		//-- from M5StackMQTTFTP
extern String          dcs3;                              		//-- from M5StackMQTTFTP
extern String          dcs4;                              		//-- from M5StackMQTTFTP
extern String          dcs5;                              		//-- from M5StackMQTTFTP
extern String          dcs6;                              		//-- from M5StackMQTTFTP
extern String          dcs7;                              		//-- from M5StackMQTTFTP
extern String          df1ReadValue;                      		//-- from M5StackMQTTFTP
extern String          df2ReadValue;                      		//-- from M5StackMQTTFTP
extern String          df3ReadValue;                      		//-- from M5StackMQTTFTP
extern String          df4ReadValue;                      		//-- from M5StackMQTTFTP
extern String          df5ReadValue;                      		//-- from M5StackMQTTFTP
extern String          df6ReadValue;                      		//-- from M5StackMQTTFTP
extern String          df7ReadValue;                      		//-- from M5StackMQTTFTP
extern String          df8ReadValue;                      		//-- from M5StackMQTTFTP
extern int             di1LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            di1Recv;                           		//-- from M5StackMQTTFTP
extern bool            di1Sent;                           		//-- from M5StackMQTTFTP
extern String          di1_feed;                          		//-- from M5StackMQTTFTP
extern String          di1_feedACK;                       		//-- from M5StackMQTTFTP
extern String          di1_value;                         		//-- from M5StackMQTTFTP
extern int             di2LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            di2Recv;                           		//-- from M5StackMQTTFTP
extern bool            di2Sent;                           		//-- from M5StackMQTTFTP
extern String          di2_feed;                          		//-- from M5StackMQTTFTP
extern String          di2_feedACK;                       		//-- from M5StackMQTTFTP
extern String          di2_value;                         		//-- from M5StackMQTTFTP
extern int             di3LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            di3Recv;                           		//-- from M5StackMQTTFTP
extern bool            di3Sent;                           		//-- from M5StackMQTTFTP
extern String          di3_feed;                          		//-- from M5StackMQTTFTP
extern String          di3_feedACK;                       		//-- from M5StackMQTTFTP
extern String          di3_value;                         		//-- from M5StackMQTTFTP
extern int             di4LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            di4Recv;                           		//-- from M5StackMQTTFTP
extern bool            di4Sent;                           		//-- from M5StackMQTTFTP
extern String          di4_feed;                          		//-- from M5StackMQTTFTP
extern String          di4_feedACK;                       		//-- from M5StackMQTTFTP
extern String          di4_value;                         		//-- from M5StackMQTTFTP
extern int             di5LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            di5Recv;                           		//-- from M5StackMQTTFTP
extern bool            di5Sent;                           		//-- from M5StackMQTTFTP
extern String          di5_feed;                          		//-- from M5StackMQTTFTP
extern String          di5_feedACK;                       		//-- from M5StackMQTTFTP
extern String          di5_value;                         		//-- from M5StackMQTTFTP
extern int             di6LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            di6Recv;                           		//-- from M5StackMQTTFTP
extern bool            di6Sent;                           		//-- from M5StackMQTTFTP
extern String          di6_feed;                          		//-- from M5StackMQTTFTP
extern String          di6_feedACK;                       		//-- from M5StackMQTTFTP
extern String          di6_value;                         		//-- from M5StackMQTTFTP
extern int             di7LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            di7Recv;                           		//-- from M5StackMQTTFTP
extern bool            di7Sent;                           		//-- from M5StackMQTTFTP
extern String          di7_feed;                          		//-- from M5StackMQTTFTP
extern String          di7_feedACK;                       		//-- from M5StackMQTTFTP
extern String          di7_value;                         		//-- from M5StackMQTTFTP
extern int             di8LoopCount;                      		//-- from M5StackMQTTFTP
extern bool            di8Recv;                           		//-- from M5StackMQTTFTP
extern bool            di8Sent;                           		//-- from M5StackMQTTFTP
extern String          di8_feed;                          		//-- from M5StackMQTTFTP
extern String          di8_feedACK;                       		//-- from M5StackMQTTFTP
extern String          di8_value;                         		//-- from M5StackMQTTFTP
extern String *        di_feedsACK[8];                    		//-- from M5StackMQTTFTP
extern String *        di_feeds[8];                       		//-- from M5StackMQTTFTP
extern bool            digitalDebugSuccess;               		//-- from M5StackMQTTFTP
extern bool            digitalInputSuccess;               		//-- from M5StackMQTTFTP
extern bool            digitalOutputSuccess;              		//-- from M5StackMQTTFTP
extern bool            do1CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            do1Recv;                           		//-- from M5StackMQTTFTP
extern int             do1_fail_default;                  		//-- from M5StackMQTTFTP
extern String          do1_feed;                          		//-- from M5StackMQTTFTP
extern String          do1_feedACK;                       		//-- from M5StackMQTTFTP
extern String          do1_value;                         		//-- from M5StackMQTTFTP
extern bool            do2CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            do2Recv;                           		//-- from M5StackMQTTFTP
extern int             do2_fail_default;                  		//-- from M5StackMQTTFTP
extern String          do2_feed;                          		//-- from M5StackMQTTFTP
extern String          do2_feedACK;                       		//-- from M5StackMQTTFTP
extern String          do2_value;                         		//-- from M5StackMQTTFTP
extern bool            do3CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            do3Recv;                           		//-- from M5StackMQTTFTP
extern int             do3_fail_default;                  		//-- from M5StackMQTTFTP
extern String          do3_feed;                          		//-- from M5StackMQTTFTP
extern String          do3_feedACK;                       		//-- from M5StackMQTTFTP
extern String          do3_value;                         		//-- from M5StackMQTTFTP
extern bool            do4CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            do4Recv;                           		//-- from M5StackMQTTFTP
extern int             do4_fail_default;                  		//-- from M5StackMQTTFTP
extern String          do4_feed;                          		//-- from M5StackMQTTFTP
extern String          do4_feedACK;                       		//-- from M5StackMQTTFTP
extern String          do4_value;                         		//-- from M5StackMQTTFTP
extern bool            do5CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            do5Recv;                           		//-- from M5StackMQTTFTP
extern int             do5_fail_default;                  		//-- from M5StackMQTTFTP
extern String          do5_feed;                          		//-- from M5StackMQTTFTP
extern String          do5_feedACK;                       		//-- from M5StackMQTTFTP
extern String          do5_value;                         		//-- from M5StackMQTTFTP
extern bool            do6CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            do6Recv;                           		//-- from M5StackMQTTFTP
extern int             do6_fail_default;                  		//-- from M5StackMQTTFTP
extern String          do6_feed;                          		//-- from M5StackMQTTFTP
extern String          do6_feedACK;                       		//-- from M5StackMQTTFTP
extern String          do6_value;                         		//-- from M5StackMQTTFTP
extern bool            do7CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            do7Recv;                           		//-- from M5StackMQTTFTP
extern int             do7_fail_default;                  		//-- from M5StackMQTTFTP
extern String          do7_feed;                          		//-- from M5StackMQTTFTP
extern String          do7_feedACK;                       		//-- from M5StackMQTTFTP
extern String          do7_value;                         		//-- from M5StackMQTTFTP
extern bool            do8CommFailTriggered;              		//-- from M5StackMQTTFTP
extern bool            do8Recv;                           		//-- from M5StackMQTTFTP
extern int             do8_fail_default;                  		//-- from M5StackMQTTFTP
extern String          do8_feed;                          		//-- from M5StackMQTTFTP
extern String          do8_feedACK;                       		//-- from M5StackMQTTFTP
extern String          do8_value;                         		//-- from M5StackMQTTFTP
extern String          ds0;                               		//-- from M5StackMQTTFTP
extern String          ds0ACK;                            		//-- from M5StackMQTTFTP
extern String          ds1;                               		//-- from M5StackMQTTFTP
extern String          ds1ACK;                            		//-- from M5StackMQTTFTP
extern String          ds2;                               		//-- from M5StackMQTTFTP
extern String          ds2ACK;                            		//-- from M5StackMQTTFTP
extern String          ds3;                               		//-- from M5StackMQTTFTP
extern String          ds3ACK;                            		//-- from M5StackMQTTFTP
extern String          ds4;                               		//-- from M5StackMQTTFTP
extern String          ds4ACK;                            		//-- from M5StackMQTTFTP
extern String          ds5;                               		//-- from M5StackMQTTFTP
extern String          ds5ACK;                            		//-- from M5StackMQTTFTP
extern String          ds6;                               		//-- from M5StackMQTTFTP
extern String          ds6ACK;                            		//-- from M5StackMQTTFTP
extern String          ds7;                               		//-- from M5StackMQTTFTP
extern String          ds7ACK;                            		//-- from M5StackMQTTFTP
extern bool            duplicateMqttMessage;              		//-- from M5StackMQTTFTP
extern byte            error;                             		//-- from M5StackMQTTFTP
extern String          errorCode;                         		//-- from M5StackMQTTFTP
extern SSLClient       ethClientSSL;                      		//-- from M5StackMQTTFTP
extern EthernetClient  ethSignalClient;                   		//-- from M5StackMQTTFTP
extern bool            firstConfigAo1Press;               		//-- from M5StackMQTTFTP
extern bool            firstSignalQualityCheck;           		//-- from M5StackMQTTFTP
extern bool            firstTimeGet;                      		//-- from M5StackMQTTFTP
extern bool            forceUpdate;                       		//-- from M5StackMQTTFTP
extern FTPClient_Generic* ftp;                               		//-- from M5StackMQTTFTP
extern String          ftpBroker;                         		//-- from M5StackMQTTFTP
extern const char*     ftpBrokerKey;                      		//-- from M5StackMQTTFTP
extern String          ftpPassword;                       		//-- from M5StackMQTTFTP
extern const char*     ftpPasswordKey;                    		//-- from M5StackMQTTFTP
extern const char*     ftpPortKey;                        		//-- from M5StackMQTTFTP
extern String          ftpUsername;                       		//-- from M5StackMQTTFTP
extern const char*     ftpUsernameKey;                    		//-- from M5StackMQTTFTP
extern String          ftpWorkingDirectory;               		//-- from M5StackMQTTFTP
extern const char*     ftpWorkingDirectoryKey;            		//-- from M5StackMQTTFTP
extern String          gids;                              		//-- from M5StackMQTTFTP
extern String          globalZeroText;                    		//-- from M5StackMQTTFTP
extern String          groupID;                           		//-- from M5StackMQTTFTP
extern bool            hasConfigInfo;                     		//-- from M5StackMQTTFTP
extern String          hc0;                               		//-- from M5StackMQTTFTP
extern String          hc1;                               		//-- from M5StackMQTTFTP
extern String          hc10;                              		//-- from M5StackMQTTFTP
extern String          hc11;                              		//-- from M5StackMQTTFTP
extern String          hc12;                              		//-- from M5StackMQTTFTP
extern String          hc13;                              		//-- from M5StackMQTTFTP
extern String          hc14;                              		//-- from M5StackMQTTFTP
extern String          hc15;                              		//-- from M5StackMQTTFTP
extern String          hc16;                              		//-- from M5StackMQTTFTP
extern String          hc17;                              		//-- from M5StackMQTTFTP
extern String          hc18;                              		//-- from M5StackMQTTFTP
extern String          hc19;                              		//-- from M5StackMQTTFTP
extern String          hc2;                               		//-- from M5StackMQTTFTP
extern String          hc3;                               		//-- from M5StackMQTTFTP
extern String          hc4;                               		//-- from M5StackMQTTFTP
extern String          hc5;                               		//-- from M5StackMQTTFTP
extern String          hc6;                               		//-- from M5StackMQTTFTP
extern String          hc7;                               		//-- from M5StackMQTTFTP
extern String          hc8;                               		//-- from M5StackMQTTFTP
extern String          hc9;                               		//-- from M5StackMQTTFTP
extern bool            heartbeatCheckAlreadySetFailDefaults[20];		//-- from M5StackMQTTFTP
extern String          heartbeatCheckUnitID;              		//-- from M5StackMQTTFTP
extern bool            heartbeatCommFail;                 		//-- from M5StackMQTTFTP
extern String          heartbeatSubscriptionsString;      		//-- from M5StackMQTTFTP
extern String *        heartbeat_check_feeds[20];         		//-- from M5StackMQTTFTP
extern String          heartbeat_feed;                    		//-- from M5StackMQTTFTP
extern bool            initialSDCheck;                    		//-- from M5StackMQTTFTP
extern bool            internalUpdateStep1;               		//-- from M5StackMQTTFTP
extern bool            internalUpdateStep1PubOnce;        		//-- from M5StackMQTTFTP
extern bool            internalUpdateStep2;               		//-- from M5StackMQTTFTP
extern bool            internalUpdateStep2PubOnce;        		//-- from M5StackMQTTFTP
extern String          internal_update_feed;              		//-- from M5StackMQTTFTP
extern const long long     publishAllInterval;                          		//-- from M5StackMQTTFTP
extern const long long     clearTextInterval;                         		//-- from M5StackMQTTFTP
extern const long long     reconnectInterval;                         		//-- from M5StackMQTTFTP
extern const long long     cycleComponentsInterval;                         		//-- from M5StackMQTTFTP
extern long long           checkForSubscribeInterval;                         		//-- from M5StackMQTTFTP
extern long long           checkForPublishInterval;                         		//-- from M5StackMQTTFTP
extern bool            ioKnown;                           		//-- from M5StackMQTTFTP
extern String          ions;                              		//-- from M5StackMQTTFTP
extern bool            leftCyclingPausePressed;           		//-- from M5StackMQTTFTP
extern bool            leftCyclingScrollPressed;          		//-- from M5StackMQTTFTP
extern bool            leftPressedOnce;                   		//-- from M5StackMQTTFTP
extern bool            leftPressedThree;                  		//-- from M5StackMQTTFTP
extern bool            leftPressedTwice;                  		//-- from M5StackMQTTFTP
extern Button          leftRed;                           		//-- from M5StackMQTTFTP
extern const char*     macKey;                            		//-- from M5StackMQTTFTP
extern String          macs;                              		//-- from M5StackMQTTFTP
extern int             maxHeartbeatChecks;                		//-- from M5StackMQTTFTP
extern String          mqttBroker;                        		//-- from M5StackMQTTFTP
extern const char*     mqttBrokerKey;                     		//-- from M5StackMQTTFTP
extern String          mqttPassword;                      		//-- from M5StackMQTTFTP
extern const char*     mqttPasswordKey;                   		//-- from M5StackMQTTFTP
extern const char*     mqttPortKey;                       		//-- from M5StackMQTTFTP
extern String          mqttUsername;                      		//-- from M5StackMQTTFTP
extern const char*     mqttUsernameKey;                   		//-- from M5StackMQTTFTP
extern File            myFile;                            		//-- from M5StackMQTTFTP
extern int             nDevices;                          		//-- from M5StackMQTTFTP
extern char            newDirName[];                      		//-- from M5StackMQTTFTP
extern bool            noHandshakeAnalogInputFeeds[8];    		//-- from M5StackMQTTFTP
extern bool            noHandshakeDigitalInputFeeds[8];   		//-- from M5StackMQTTFTP
extern bool            noStartUpConfig;                   		//-- from M5StackMQTTFTP
extern bool            normalMode;                        		//-- from M5StackMQTTFTP
extern String          ntpDay;                            		//-- from M5StackMQTTFTP
extern String          ntpMonth;                          		//-- from M5StackMQTTFTP
extern String          ntpYear;                           		//-- from M5StackMQTTFTP
extern bool            onSignalClientDisconnect;          		//-- from M5StackMQTTFTP
extern String          optAPIKey;                         		//-- from M5StackMQTTFTP
extern String          optAPIToken;                       		//-- from M5StackMQTTFTP
extern String          optAccountID;                      		//-- from M5StackMQTTFTP
extern const char*     optAccountIDKey;                   		//-- from M5StackMQTTFTP
extern String          optApplicationID;                  		//-- from M5StackMQTTFTP
extern const char*     optApplicationIDKey;               		//-- from M5StackMQTTFTP
extern String          optRadioSN;                        		//-- from M5StackMQTTFTP
extern const char*     optRadioSNKey;                     		//-- from M5StackMQTTFTP
extern String          optSecretID;                       		//-- from M5StackMQTTFTP
extern const char*     optSecretIDKey;                    		//-- from M5StackMQTTFTP
extern String          optSummitID;                       		//-- from M5StackMQTTFTP
extern String          payload;                           		//-- from M5StackMQTTFTP
extern Adafruit_PCF8574 pcfr;                              		//-- from M5StackMQTTFTP
extern int             pcfr0Prev;                         		//-- from M5StackMQTTFTP
extern int             pcfr0Test;                         		//-- from M5StackMQTTFTP
extern int             pcfr1Prev;                         		//-- from M5StackMQTTFTP
extern int             pcfr1Test;                         		//-- from M5StackMQTTFTP
extern int             pcfr2Prev;                         		//-- from M5StackMQTTFTP
extern int             pcfr2Test;                         		//-- from M5StackMQTTFTP
extern int             pcfr3Prev;                         		//-- from M5StackMQTTFTP
extern int             pcfr3Test;                         		//-- from M5StackMQTTFTP
extern int             pcfr4Prev;                         		//-- from M5StackMQTTFTP
extern int             pcfr4Test;                         		//-- from M5StackMQTTFTP
extern int             pcfr5Prev;                         		//-- from M5StackMQTTFTP
extern int             pcfr5Test;                         		//-- from M5StackMQTTFTP
extern int             pcfr6Prev;                         		//-- from M5StackMQTTFTP
extern int             pcfr6Test;                         		//-- from M5StackMQTTFTP
extern int             pcfr7Prev;                         		//-- from M5StackMQTTFTP
extern int             pcfr7Test;                         		//-- from M5StackMQTTFTP
extern Adafruit_PCF8574 pcfw1;                             		//-- from M5StackMQTTFTP
extern Adafruit_PCF8574 pcfw2;                             		//-- from M5StackMQTTFTP
extern const char*     pnamespace;                        		//-- from M5StackMQTTFTP
extern int             port;                              		//-- from M5StackMQTTFTP
extern bool            preCheckSD;                        		//-- from M5StackMQTTFTP
extern Preferences     preferences;                       		//-- from M5StackMQTTFTP
extern int             pubConnectedLoopCount;             		//-- from M5StackMQTTFTP
extern bool            pubConnectedRecv;                  		//-- from M5StackMQTTFTP
extern bool            pubConnectedSent;                  		//-- from M5StackMQTTFTP
extern bool            publishAllc;                       		//-- from M5StackMQTTFTP
extern int             qos;                               		//-- from M5StackMQTTFTP
extern String          rciTitle;                          		//-- from M5StackMQTTFTP
extern bool            receivingSignalQuality;            		//-- from M5StackMQTTFTP
extern bool            reconnect;                         		//-- from M5StackMQTTFTP
extern int             reconnectCount;                    		//-- from M5StackMQTTFTP
extern bool            reconnectFirstMessageStatus;       		//-- from M5StackMQTTFTP
extern String          refreshString;                     		//-- from M5StackMQTTFTP
extern bool            retained;                          		//-- from M5StackMQTTFTP
extern bool            rightCyclingUnpausePressed;        		//-- from M5StackMQTTFTP
extern bool            rightPressedFour;                  		//-- from M5StackMQTTFTP
extern bool            rightPressedOnce;                  		//-- from M5StackMQTTFTP
extern bool            rightPressedThree;                 		//-- from M5StackMQTTFTP
extern bool            rightPressedTwice;                 		//-- from M5StackMQTTFTP
extern Button          rightRed;                          		//-- from M5StackMQTTFTP
extern String          sdConfigFileName;                  		//-- from M5StackMQTTFTP
extern const char*     serialKey;                         		//-- from M5StackMQTTFTP
extern String          serialNumber;                      		//-- from M5StackMQTTFTP
extern String          serns;                             		//-- from M5StackMQTTFTP
extern SSLClient       signalClient;                      		//-- from M5StackMQTTFTP
extern bool            signalQualityCheckSuccessful;      		//-- from M5StackMQTTFTP
extern String          signalQualityString;               		//-- from M5StackMQTTFTP
extern String          signalStrengthString;              		//-- from M5StackMQTTFTP
extern String          sqs;                               		//-- from M5StackMQTTFTP
extern String          ssis;                              		//-- from M5StackMQTTFTP
extern const long long     startUpInterval;                   		//-- from M5StackMQTTFTP
extern bool            startUpMode;                       		//-- from M5StackMQTTFTP
extern String          statusString;                      		//-- from M5StackMQTTFTP
extern String          stringFtpPort;                     		//-- from M5StackMQTTFTP
extern String          stringMac;                         		//-- from M5StackMQTTFTP
extern String          stringMqttPort;                    		//-- from M5StackMQTTFTP
extern bool            subConnectedRecv;                  		//-- from M5StackMQTTFTP
extern int             subCount;                          		//-- from M5StackMQTTFTP
extern time_t          t;                                 		//-- from M5StackMQTTFTP
extern int             testadc0;                          		//-- from M5StackMQTTFTP
extern int             testadc1;                          		//-- from M5StackMQTTFTP
extern int             testadc2;                          		//-- from M5StackMQTTFTP
extern int             testadc3;                          		//-- from M5StackMQTTFTP
extern int             testadc4;                          		//-- from M5StackMQTTFTP
extern int             testadc5;                          		//-- from M5StackMQTTFTP
extern int             testadc6;                          		//-- from M5StackMQTTFTP
extern int             testadc7;                          		//-- from M5StackMQTTFTP
extern const long long     timeOutInterval;                   		//-- from M5StackMQTTFTP
extern const char      timeServer2[];                     		//-- from M5StackMQTTFTP
extern const char      timeServer3[];                     		//-- from M5StackMQTTFTP
extern const char      timeServer4[];                     		//-- from M5StackMQTTFTP
extern const char      timeServer5[];                     		//-- from M5StackMQTTFTP
extern const char      timeServer[];                      		//-- from M5StackMQTTFTP
extern bool            udpHasTimePacket;                  		//-- from M5StackMQTTFTP
extern String          uids;                              		//-- from M5StackMQTTFTP
extern String          unitID;                            		//-- from M5StackMQTTFTP
extern String          updateTime;                        		//-- from M5StackMQTTFTP
extern String          upds;                              		//-- from M5StackMQTTFTP
extern String          versionNumber;                     		//-- from M5StackMQTTFTP
extern int             viewConfigItemsIterator;           		//-- from M5StackMQTTFTP
extern bool            warningMenu1;                      		//-- from M5StackMQTTFTP
extern bool            warningMenu2;                      		//-- from M5StackMQTTFTP
extern const char      willTopic[];                       		//-- from M5StackMQTTFTP
extern unsigned long long heartbeatCheckCurrentMillis[20];
extern unsigned long long heartbeatCheckPreviousMillis[20];
extern bool triggerSound;
extern unsigned long long timeOutCurrentMillis;
extern unsigned long long timeOutPreviousMillis;
extern unsigned long long cyclingPauseCurrentMillis;
extern unsigned long long cyclingPausePreviousMillis;
extern unsigned long long cycleComponentsCurrentMillis;
extern unsigned long long cycleComponentsPreviousMillis;
extern Button centerRed;
extern MqttClient mqttClient;
extern unsigned long long commFailCurrentMillis;
extern unsigned long long commFailPreviousMillis;
extern byte mac[];
extern unsigned long long clearTextCurrentMillis;
extern unsigned long long clearTextPreviousMillis;
extern unsigned long long getTimeCurrentMillis;
extern unsigned long long getTimePreviousMillis;
extern byte packetBufferTime[];
extern unsigned long long publishAllCurrentMillis;
extern unsigned long long publishAllPreviousMillis;
extern long long connectedPublishCount;
extern long long heartbeatPublishCount;
extern unsigned long long heartbeatPublishCurrentMillis;
extern unsigned long long heartbeatPublishPreviousMillis;
extern const long long getTimeInterval;
extern unsigned long long reconnectCurrentMillis;
extern unsigned long long reconnectPreviousMillis;
extern unsigned int localUDPPort;
extern String software_version_feed;
extern bool publishSoftwareVersionFlag;
extern const long long updateSignalDeviceInfoInterval;
extern unsigned long long updateSignalDeviceInfoCurrentMillis;
extern unsigned long long updateSignalDeviceInfoPreviousMillis;
extern const long long receiveSignalQualityInterval;
extern unsigned long long receiveSignalQualityCurrentMillis;
extern unsigned long long receiveSignalQualityPreviousMillis;
extern const long long clearUpdateFlagsInterval;
extern unsigned long long clearUpdateFlagsCurrentMillis;
extern unsigned long long clearUpdateFlagsPreviousMillis;
extern short requestAPIAccessCount;
extern short requestCellModemRefreshCount;
extern short requestCellularSignalQualityCount;
extern const long long apiAccessInterval;
extern unsigned long long apiAccessCurrentMillis;
extern unsigned long long apiAccessPreviousMillis;
extern const long long apiAccessRequestInterval;
extern unsigned long long apiAccessRequestCurrentMillis;
extern unsigned long long apiAccessRequestPreviousMillis;
extern const long long requestSignalQualityConfigModeInterval;
extern const long long requestSignalQualityNormalModeInterval;
extern unsigned long long requestSignalQualityCurrentMillis;
extern unsigned long long requestSignalQualityPreviousMillis;

//============ Function Prototypes =========
//-- from M5StackMQTTFTP.ino -----------
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
void publishHeartbeat();                                    
void publishConnected();                                    
void publishConnectedReceipt();                             
void publishConf(bool final);                               
void publishCreds(bool final);                              
void publishInternal(bool final);                           
void publishApi(bool final);                                
void publishDI1();                                          
void publishDO1Receipt();                                   
void publishDI2();                                          
void publishDO2Receipt();                                   
void publishDI3();                                          
void publishDO3Receipt();                                   
void publishDI4();                                          
void publishDO4Receipt();                                   
void publishDI5();                                          
void publishDO5Receipt();                                   
void publishDI6();                                          
void publishDO6Receipt();                                   
void publishDI7();                                          
void publishDO7Receipt();                                   
void publishDI8();                                          
void publishDO8Receipt();                                   
void publishAI1();                                          
void publishAO1Receipt();                                   
void publishAI2();                                          
void publishAO2Receipt();                                   
void publishAI3();                                          
void publishAO3Receipt();                                   
void publishAI4();                                          
void publishAO4Receipt();                                   
void publishAI5();                                          
void publishAO5Receipt();                                   
void publishAI6();                                          
void publishAO6Receipt();                                   
void publishAI7();                                          
void publishAO7Receipt();                                   
void publishAI8();                                          
void publishAO8Receipt();                                   
void publishAll();                                          
void callback(char* topic, byte* payload, unsigned int length);
void cycleConfigItems(int startIndex);                      
void onMqttMessage(int messageSize);                        
void fillCharArray(char* charArray, String string);         
void configConnect();                                       
void confConnect();                                         
void performUpdate(Stream &updateSource, size_t updateSize);
void updateFromFS(fs::FS &fs);                              
void credConnect();                                         
void internalConnect();                                     
void apiConnect();                                          
void sendNTPpacket(const char * address);                   
void reconnectMqtt();                                       
void analyzeFTPFileContents(String topic);                  
void analyzeSDCardContents();                               
void createHeartbeatSubscriptionArrays(String subscriptions);
void checkHeartbeatSubscriptionArrays(String subscription); 
void setGroupMemberLossOfCommunicationDefaults(String subscription);
void hexCharacterStringToBytes(byte *byteArray, const char *hexString);
byte nibble(char c);                                        
void returnToNormalOperation();                             
void requestAPIAccess();                                    
void backgroundReceiveAPIKey();                             
void requestCellModemRefresh();                             
void backgroundReceiveCellModemRefresh();                   
void requestCellularSignalQuality();                        
void backgroundReceiveCellularSignalQuality(bool displayBars);
int calculateCellularSignalQualityBars(int signalStrengthValue);
void displayCellularSignalQuality();                        
void rebootEspWithReason(String reason);     
void publishSoftwareVersion();      
void signalQualityRoutine();      
void clearUpdateFlags();   

#endif // ARDUINOGLUE_H
