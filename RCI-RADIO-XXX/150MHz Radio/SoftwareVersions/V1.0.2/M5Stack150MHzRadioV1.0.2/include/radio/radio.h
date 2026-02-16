#include "M5StackRadio.h"

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
  String atCommand = RADIO_MODEM_DISABLE_ECHO_ATCOMMAND + String(RADIO_MODEM_DISABLE_ECHO_VALUE) + CARRIAGE_RETURN_CHARACTER;
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
  String atCommand = RADIO_MODEM_CHANGE_GROUP_ID_ATCOMMAND + String(" ") + intGroupID + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetUnitID() {
  String atCommand = RADIO_MODEM_CHANGE_UNIT_ID_ATCOMMAND + String(" 00") + unitID + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetDestinationIDs() {
  String atCommand = String("");
  if (isHost) {
    atCommand = RADIO_MODEM_CHANGE_DESTINATION_IDS_ATCOMMAND + String(" ") + RADIO_MODEM_DESTINATION_ID_BROADCAST + CARRIAGE_RETURN_CHARACTER;
  } else {
    atCommand = RADIO_MODEM_CHANGE_DESTINATION_IDS_ATCOMMAND + String(" ") + RADIO_MODEM_DESTINATION_ID_HOST + CARRIAGE_RETURN_CHARACTER;
  }
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetListenerIDs() {
  String atCommand = RADIO_MODEM_CHANGE_LISTENER_IDS_ATCOMMAND + String(" ") + RADIO_MODEM_UNIT_ID_MASK + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetRFPower() {
  String atCommand = RADIO_MODEM_SET_RF_POWER_ATCOMMAND + String(" ") + RADIO_MODEM_SET_RF_POWER_100PERCENT_VALUE + CARRIAGE_RETURN_CHARACTER;
  radioSerialRS232.write(atCommand.c_str());
}

void radioModemSetRFPower(String radioModemSetRFPowerValue) {
  String atCommand = RADIO_MODEM_SET_RF_POWER_ATCOMMAND + String(" ") + radioModemSetRFPowerValue + CARRIAGE_RETURN_CHARACTER;
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
  delay(50);
  radioModemEnterCommandMode();
  delay(50);
  //radioModemFactoryReset();
  //delay(1000);
  radioModemDisableEcho();
  delay(50);
  radioModemSetBaudRate();
  delay(50);
  radioModemSetOTARate();
  delay(50);
  radioModemSetOTAPacketSize();
  delay(50);
  radioModemSetIOConfig();
  delay(50);
  radioModemSetHWFlowControl();
  delay(50);
  radioModemSetCarrierDetect();
  delay(50);
  radioModemSetGroupID();
  delay(50);
  radioModemSetUnitID();
  delay(50);
  radioModemSetDestinationIDs();
  delay(50);
  radioModemSetListenerIDs();
  delay(50);
  radioModemSetRFPower(radioModemSelectedRFPower);
  delay(50);
  radioModemSetChannel(radioModemSelectedChannel);
  delay(50);
  radioModemSaveParameters();
  delay(250);
  radioModemEnterDataMode();
  delay(50);
}

void getRadioSignal() {
  delay(50);
  radioModemEnterCommandMode();
  delay(50);
  radioModemGetRSSI();
  delay(50);
  radioModemEnterDataMode();
  delay(50);
}