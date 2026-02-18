#include "M5StackMQTTFTP.h"

void requestAPIAccess() {
  if (optSecretID.equalsIgnoreCase("")) {
    return;
  }
  
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