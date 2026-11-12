#include "M5StackRadio.h"

#define RADIO_AT_COMMAND_WAIT_DEADBAND 50

String groupIDByte = String("01");

void radioModemEnterCommandMode() {
  String atCommand = String(RADIO_MODEM_COMMAND_MODE_SEQUENCE);
  delay(500);
  radioSerialRS232.write(atCommand.c_str());
  delay(500);
}

void radioModemEnterDataMode() {
  String atCommand = String(RADIO_MODEM_DATA_MODE_SEQUENCE) + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemFactoryReset() {
  String atCommand = String(RADIO_MODEM_FACTORY_RESET_SEQUENCE) + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSaveParameters() {
  String atCommand = String(RADIO_MODEM_SAVE_SEQUENCE) + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemDisableEcho() {
  String atCommand = RADIO_MODEM_DISABLE_ECHO_ATCOMMAND + String(" ") + String(RADIO_MODEM_DISABLE_ECHO_VALUE) + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetBaudRate() {
  String atCommand = RADIO_MODEM_SET_BAUD_RATE_ATCOMMAND + String(" ") + RS232_SERIAL_BAUD + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetOTARate() {
  String atCommand = RADIO_MODEM_SET_OTA_RATE_ATCOMMAND + String(" ") + RADIO_MODEM_SET_OTA_RATE_VALUE + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetOTAPacketSize() {
  String atCommand = RADIO_MODEM_SET_OTA_PACKET_SIZE_ATCOMMAND + String(" ") + RADIO_MODEM_SET_OTA_PACKET_SIZE_VALUE + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetIOConfig() {
  String atCommand = RADIO_MODEM_SET_IO_CONFIG_ATCOMMAND + String(" ") + RADIO_MODEM_SET_IO_CONFIG_VALUE + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetHWFlowControl() {
  String atCommand = RADIO_MODEM_SET_HW_FLOW_CONTROL_ATCOMMAND + String(" ") + RADIO_MODEM_SET_HW_FLOW_CONTROL_VALUE + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetCarrierDetect() {
  String atCommand = RADIO_MODEM_SET_CARRIER_DETECT_ATCOMMAND + String(" ") + RADIO_MODEM_SET_CARRIER_DETECT_VALUE + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetGroupID() {
  int intGroupID = groupID.toInt();
  while (intGroupID > 255) {
    intGroupID -= 255;
  }
  if (intGroupID <= 0) {
    intGroupID = 255;
  }
  groupIDByte = String(intGroupID, HEX);
  groupIDByte.toUpperCase();
  //String atCommand = RADIO_MODEM_CHANGE_GROUP_ID_ATCOMMAND + String(" ") + intGroupID + CARRIAGE_RETURN_CHARACTER;
  //radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetUnitID() {
  String atCommand = RADIO_MODEM_CHANGE_UNIT_ID_ATCOMMAND + String(" ") + groupIDByte + unitID + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetDestinationIDs() {
  String atCommand = String("");
  if (isHost) {
    atCommand = RADIO_MODEM_CHANGE_DESTINATION_IDS_ATCOMMAND + String(" ") + groupIDByte + RADIO_MODEM_DESTINATION_ID_BROADCAST + CARRIAGE_RETURN_CHARACTER;
  } else {
    atCommand = RADIO_MODEM_CHANGE_DESTINATION_IDS_ATCOMMAND + String(" ") + groupIDByte + RADIO_MODEM_DESTINATION_ID_HOST + CARRIAGE_RETURN_CHARACTER;
  }
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetListenerIDs() {
  String atCommand = RADIO_MODEM_CHANGE_LISTENER_IDS_ATCOMMAND + String(" ") + RADIO_MODEM_UNIT_ID_MASK + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetRFPower() {
  String atCommand = RADIO_MODEM_SET_RF_POWER_ATCOMMAND + String(" ") + RADIO_MODEM_SET_RF_POWER_50PERCENT_VALUE + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetRFPower(String radioModemSetRFPowerValue) {
  String atCommand = RADIO_MODEM_SET_RF_POWER_ATCOMMAND + String(" ") + String(int(ceil(radioModemSetRFPowerValue.toDouble()/MAXIMUM_RADIO_POWER_WATTS*100))) + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetChannel() {
  String atCommand = RADIO_MODEM_SET_CHANNEL_ATCOMMAND + String(" ") + RADIO_MODEM_SET_CHANNEL_1_VALUE + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetChannel(String radioModemSetChannelValue) {
  String atCommand = RADIO_MODEM_SET_CHANNEL_ATCOMMAND + String(" ") + radioModemSetChannelValue + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetModemType(bool freqHoppingSSEnabled) {
  String atCommand = String("");

  if (freqHoppingSSEnabled) {
    atCommand = RADIO_MODEM_SET_MODEM_TYPE_ATCOMMAND + String(" ") + RADIO_MODEM_SET_MODEM_TYPE_FREQ_HOPPING_SS + CARRIAGE_RETURN_CHARACTER;
  } else {
    atCommand = RADIO_MODEM_SET_MODEM_TYPE_ATCOMMAND + String(" ") + RADIO_MODEM_SET_MODEM_TYPE_LORALITE + CARRIAGE_RETURN_CHARACTER;
  }
  
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemEnterTransmitTest() {
  String atCommand = RADIO_MODEM_TRANSMIT_TEST_ATCOMMAND + String(" ") + RADIO_MODEM_TRANSMIT_TEST_VALUE + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemExitTransmitTest() {
  String atCommand = String(CARRIAGE_RETURN_CHARACTER);
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemGetRSSI() {
  String atCommand = String(RADIO_MODEM_GET_RSSI_ATCOMMAND) + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
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

void initializeRadioModem() {
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemEnterCommandMode();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  //radioModemFactoryReset();
  //delay(2000);
  radioModemDisableEcho();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSetBaudRate();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  //radioModemSetOTARate();
  //delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSetOTAPacketSize();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSetIOConfig();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSetHWFlowControl();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSetCarrierDetect();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSetGroupID();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSetUnitID();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSetDestinationIDs();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSetListenerIDs();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSetRFPower(radioModemSelectedRFPower);
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSetChannel(radioModemSelectedChannel);
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSetModemType(false);
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemSaveParameters();
  delay(2000);
  radioModemEnterDataMode();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
}

void getRadioSignal() {
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemEnterCommandMode();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemGetRSSI();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND * 2);
  radioModemEnterDataMode();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
}

void enterContinuousRadioTest() {
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemEnterCommandMode();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemEnterTransmitTest();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND * 2);
}

void exitContinuousRadioTest() {
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
  radioModemExitTransmitTest();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND * 2);
  radioModemEnterDataMode();
  delay(RADIO_AT_COMMAND_WAIT_DEADBAND);
}