#include "M5StackMQTTFTP.h"

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
    //initEthernet();
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

  if (response.length() > 1) {
    receivedConfigFTP = true;
  }

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

  if (response.length() > 1) {
    receivedConfigFTP = true;
  }

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

  returnToNormalOperation();
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

  if (response.length() > 1) {
    receivedInternalFTP = true;
  }

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

  if (response.length() > 1) {
    receivedApiFTP = true;
  }

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

void clearUpdateFlags() {
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
}