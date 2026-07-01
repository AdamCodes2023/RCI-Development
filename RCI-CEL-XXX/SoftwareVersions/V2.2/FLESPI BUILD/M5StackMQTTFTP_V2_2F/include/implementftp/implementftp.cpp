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
      monitorCommFailState();
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

  checkTimeRoutine();

  logFTPEvent(String("CONFIGURATION_UPDATE_MANUAL"));

  char* ftp_server = new char[ftpBroker.length() + 1];
  fillCharArray(ftp_server, ftpBroker);

  uint16_t ftp_port = stringFtpPort.toInt();

  char* ftp_user = new char[ftpUsername.length() + 1];
  fillCharArray(ftp_user, ftpUsername);

  char* ftp_pass = new char[ftpPassword.length() + 1];
  fillCharArray(ftp_pass, ftpPassword);

  char* dirName = new char[ftpWorkingDirectory.length() + 1];
  fillCharArray(dirName, ftpWorkingDirectory);

  ftp = new FTPClient_Generic (ftp_server, ftp_port, ftp_user, ftp_pass, 10000);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Download the text file or read it
  String response = "";
  ftp->InitFile(COMMAND_XFER_TYPE_ASCII);
  ftp->DownloadString(configFileName.c_str(), response);

  ftp->CloseFile();
  ftp->CloseConnection();

  delete[] ftp_server;
  //delete ftp_port;
  delete[] ftp_user;
  delete[] ftp_pass;
  delete[] dirName;
  delete ftp;

  if (response.length() > 1) {
    receivedConfigFTP = true;
    numberOfRemoteUnits = 0;
    for (int i = 0; i < 20; i++) {
      connectedRemoteUnitIDs[i] = -1;
    }
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

  preferences.begin(pnamespace);
  preferences.putBool(publishConfigPrefKey, receivedConfigFTP);
  preferences.end();

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

  logFTPEvent(String("CONFIGURATION_UPDATE_BACKGROUND"));

  char* ftp_server = new char[ftpBroker.length() + 1];
  fillCharArray(ftp_server, ftpBroker);

  uint16_t ftp_port = stringFtpPort.toInt();

  char* ftp_user = new char[ftpUsername.length() + 1];
  fillCharArray(ftp_user, ftpUsername);

  char* ftp_pass = new char[ftpPassword.length() + 1];
  fillCharArray(ftp_pass, ftpPassword);

  char* dirName = new char[ftpWorkingDirectory.length() + 1];
  fillCharArray(dirName, ftpWorkingDirectory);

  ftp = new FTPClient_Generic (ftp_server, ftp_port, ftp_user, ftp_pass, 10000);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Download the text file or read it
  String response = "";
  ftp->InitFile(COMMAND_XFER_TYPE_ASCII);
  ftp->DownloadString(configFileName.c_str(), response);

  ftp->CloseFile();
  ftp->CloseConnection();

  delete[] ftp_server;
  //delete ftp_port;
  delete[] ftp_user;
  delete[] ftp_pass;
  delete[] dirName;
  delete ftp;

  if (response.length() > 1) {
    receivedConfigFTP = true;
    numberOfRemoteUnits = 0;
    for (int i = 0; i < 20; i++) {
      connectedRemoteUnitIDs[i] = -1;
    }
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
  preferences.putBool(publishConfigPrefKey, receivedConfigFTP);
  preferences.end();

  returnToNormalOperation();

  rebootEspWithReason("CONFIGURATION UPDATE");
}

void credConnect() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("RECEIVING", 65, 120, 1);
  M5.Lcd.drawString("CRED INFO", 65, 170, 1);

  delay(500);

  logFTPEvent(String("CREDENTIALS_AND_FIRMWARE_UPDATE_BACKGROUND"));

  char* ftp_server = new char[ftpBroker.length() + 1];
  fillCharArray(ftp_server, ftpBroker);

  uint16_t ftp_port = stringFtpPort.toInt();

  char* ftp_user = new char[ftpUsername.length() + 1];
  fillCharArray(ftp_user, ftpUsername);

  char* ftp_pass = new char[ftpPassword.length() + 1];
  fillCharArray(ftp_pass, ftpPassword);

  char* dirName = new char[ftpWorkingDirectory.length() + 1];
  fillCharArray(dirName, ftpWorkingDirectory);

  ftp = new FTPClient_Generic (ftp_server, ftp_port, ftp_user, ftp_pass, 10000);

  //Dynammically allocate buffer
  unsigned char * downloaded_file = (unsigned char *) malloc(UPDATE_BINARY_FILE_SIZE);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Download the text file or read it
  String response = "";
  
  ftp->InitFile(COMMAND_XFER_TYPE_ASCII);
  ftp->DownloadString("creds.txt", response);
  
  ftp->CloseFile();
  ftp->CloseConnection();

  delay(500);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Download the text file or read it
  ftp->InitFile(COMMAND_XFER_TYPE_BINARY);
  ftp->DownloadFile("update.bin", downloaded_file, UPDATE_BINARY_FILE_SIZE, false);

  ftp->CloseFile();
  ftp->CloseConnection();

  delete[] ftp_server;
  //delete ftp_port;
  delete[] ftp_user;
  delete[] ftp_pass;
  delete[] dirName;
  delete ftp;

  if (response.length() > 1) {
    receivedCredsFTP = true;
  }

  myFile = SD.open("/update.bin", FILE_WRITE);
  myFile.write(downloaded_file, UPDATE_BINARY_FILE_SIZE);
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
  preferences.putBool(publishCredsPrefKey, receivedCredsFTP);
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

  logFTPEvent(String("INTERNAL_UPDATE_BACKGROUND"));

  char* ftp_server = new char[ftpBroker.length() + 1];
  fillCharArray(ftp_server, ftpBroker);

  uint16_t ftp_port = stringFtpPort.toInt();

  char* ftp_user = new char[ftpUsername.length() + 1];
  fillCharArray(ftp_user, ftpUsername);

  char* ftp_pass = new char[ftpPassword.length() + 1];
  fillCharArray(ftp_pass, ftpPassword);

  char* dirName = new char[ftpWorkingDirectory.length() + 1];
  fillCharArray(dirName, ftpWorkingDirectory);

  ftp = new FTPClient_Generic (ftp_server, ftp_port, ftp_user, ftp_pass, 10000);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Download the text file or read it
  String response = "";
  ftp->InitFile(COMMAND_XFER_TYPE_ASCII);
  ftp->DownloadString("internal.txt", response);

  ftp->CloseFile();
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
  preferences.putBool(publishInternalPrefKey, receivedInternalFTP);
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

  rebootEspWithReason("INTERNAL UPDATE");
}

void apiConnect() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("RECEIVING", 65, 120, 1);
  M5.Lcd.drawString("API INFO", 70, 170, 1);

  delay(500);

  logFTPEvent(String("API_UPDATE_BACKGROUND"));

  char* ftp_server = new char[ftpBroker.length() + 1];
  fillCharArray(ftp_server, ftpBroker);

  uint16_t ftp_port = stringFtpPort.toInt();

  char* ftp_user = new char[ftpUsername.length() + 1];
  fillCharArray(ftp_user, ftpUsername);

  char* ftp_pass = new char[ftpPassword.length() + 1];
  fillCharArray(ftp_pass, ftpPassword);

  char* dirName = new char[ftpWorkingDirectory.length() + 1];
  fillCharArray(dirName, ftpWorkingDirectory);

  ftp = new FTPClient_Generic (ftp_server, ftp_port, ftp_user, ftp_pass, 10000);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Download the text file or read it
  String response = "";
  ftp->InitFile(COMMAND_XFER_TYPE_ASCII);
  ftp->DownloadString("api.txt", response);

  ftp->CloseFile();
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
  preferences.putBool(publishApiPrefKey, receivedApiFTP);
  preferences.end();

  normalMode = true;

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  if (!forceUpdate) {
    rebootEspWithReason("API UPDATE");
  }
}

void logConnect() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("UPLOADING", 65, 120, 1);
  M5.Lcd.drawString("LOG DATA", 70, 170, 1);

  delay(500);

  logFTPEvent(String("LOG_UPLOAD_BACKGROUND"));

  File logUploadFile = SD.open(String("/" + uploadLogFileName), FILE_READ);

  char* ftp_server = new char[ftpBroker.length() + 1];
  fillCharArray(ftp_server, ftpBroker);

  uint16_t ftp_port = stringFtpPort.toInt();

  char* ftp_user = new char[ftpUsername.length() + 1];
  fillCharArray(ftp_user, ftpUsername);

  char* ftp_pass = new char[ftpPassword.length() + 1];
  fillCharArray(ftp_pass, ftpPassword);

  char* dirName = new char[ftpWorkingDirectory.length() + 1];
  fillCharArray(dirName, ftpWorkingDirectory);

  ftpLogWorkingDirectory = String(ftpWorkingDirectory + "\\" + FTP_LOG_DIRECTORY_SUFFIX);
  char* logDirName = new char[ftpLogWorkingDirectory.length() + 1];
  fillCharArray(logDirName, ftpLogWorkingDirectory);

  ftp = new FTPClient_Generic (ftp_server, ftp_port, ftp_user, ftp_pass, 10000);

  ftp->OpenConnection();

  //Change directory
  ftp->ChangeWorkDir(dirName);

  //Initialize the text file
  ftp->InitFile(COMMAND_XFER_TYPE_BINARY);

  //Create log directory
  String directoryContents[256];
  ftp->ContentListWithListCommand("", directoryContents);
  if (directoryContents->indexOf(FTP_LOG_DIRECTORY_SUFFIX) == -1) {
    ftp->MakeDir(FTP_LOG_DIRECTORY_SUFFIX);
  }

  ftp->CloseFile();
  ftp->CloseConnection();

  delay(50);

  ftp->OpenConnection();

  //Change to log directory
  ftp->ChangeWorkDir(logDirName);

  //Download the text file or read it
  ftp->InitFile(COMMAND_XFER_TYPE_BINARY);
  ftp->NewFile(uploadLogFileName.c_str());

  // Establish a small 512-byte bucket buffer in RAM
  uint8_t internalBuffer[512];
  
  // Read from SD and pipe directly to the FTP server socket chunk-by-chunk
  while (logUploadFile.available()) {
    int bytesRead = logUploadFile.read(internalBuffer, sizeof(internalBuffer));
    ftp->WriteData(internalBuffer, bytesRead);
  }

  //Still connected after upload (successful)
  bool ftpConnectionSuccessful = ftp->isConnected();

  //Close everything
  logUploadFile.close();
  ftp->CloseFile();
  ftp->CloseConnection();

  delete[] ftp_server;
  //delete ftp_port;
  delete[] ftp_user;
  delete[] ftp_pass;
  delete[] dirName;
  delete[] logDirName;
  //delete[] directoryContents;
  delete ftp;

  if (ftpConnectionSuccessful) {
    sentLogFTP = true;
  }

  normalMode = true;

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
}

void logDelete() {
  if (SD.exists(deleteLogFileName.c_str())) {
    SD.remove(deleteLogFileName.c_str());
  }
  initializeLogFile();
  logDeleteEvent(deleteLogFileName);
  deletedLogFTP = true;
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
  logUploadStep1 = false;
  logUploadStep2 = false;
  logUploadStep3 = false;
  logDeleteStep1 = false;
  logDeleteStep2 = false;
  logDeleteStep3 = false;
  confUpdateStep1PubOnce = false;
  confUpdateStep2PubOnce = false;
  internalUpdateStep1PubOnce = false;
  internalUpdateStep2PubOnce = false;
  credUpdateStep1PubOnce = false;
  credUpdateStep2PubOnce = false;
  apiUpdateStep1PubOnce = false;
  apiUpdateStep2PubOnce = false;
  logUploadStep1PubOnce = false;
  logUploadStep2PubOnce = false;
  logDeleteStep1PubOnce = false;
  logDeleteStep2PubOnce = false;
}