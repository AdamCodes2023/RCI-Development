#include "M5StackRadio.h"

class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    BLEServerCallbacks::onConnect(pServer);
    Serial.println("BLE CONNECTION DETECTED!");
    stopBluetooth();
  };

  void onDisconnect(BLEServer* pServer) {
    BLEServerCallbacks::onDisconnect(pServer);
    Serial.println("BLE CONNECTION LOST!");
    simulationMode = false;
    // Cancel OTA update on disconnect
    if (otaInProgress) {
      Serial.println("[OTA] Update cancelled.");
      Update.end(false); // Abort the update process
      otaInProgress = false;
    }
    pSendConfigCharacteristic->setValue(initialBluetoothRciInfo.c_str());
    resetBluetooth();
  }
};

class MyConfigCharacteristicCallbacks: public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    String rxValue = String(pCharacteristic->getValue().c_str());
    Serial.println(rxValue);

    if (rxValue.length() > 1) {
      if (rxValue.equalsIgnoreCase("DONE") && cfgServerMode) {
        viewConfigItemsIterator = 0;
        cycleConfigItems(viewConfigItemsIterator);
        forceUpdate = true;
      } else {
        analyzeBLEWriteContents(rxValue);
      }
    }
    else {
      Serial.println("INVALID MESSAGE!");
    }

    pDisplayConfigCharacteristic->setValue(createDisplayConfigString().c_str());
  }
};

class MySimulationCharacteristicCallbacks: public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    String rxValue = String(pCharacteristic->getValue().c_str());
    Serial.println(rxValue);

    if (rxValue.length() > 1) {
      if (rxValue.substring(rxValue.length() - 2).equalsIgnoreCase("sm")) {
        if (rxValue.substring(0, rxValue.indexOf('_')).equalsIgnoreCase("0")) {
          simulationMode = false;
        } else if (rxValue.substring(0, rxValue.indexOf('_')).equalsIgnoreCase("1")) {
          simulationMode = true;
        } else {
          Serial.println("INVALID SIMULATION MODE VALUE!");
        }
      } else if (rxValue.substring(rxValue.length() - 2).equalsIgnoreCase("ma")) {
        if (rxValue.substring(0, rxValue.indexOf('_')).equalsIgnoreCase("4")) {
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
        } else if (rxValue.substring(0, rxValue.indexOf('_')).equalsIgnoreCase("12")) {
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
        } else if (rxValue.substring(0, rxValue.indexOf('_')).equalsIgnoreCase("20")) {
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
        } else {
          Serial.println("INVALID AO mA VALUE!");
        }
      } else if (rxValue.substring(rxValue.length() - 2).equalsIgnoreCase("sd")) {
        if (rxValue.substring(0, rxValue.indexOf('_')).toInt() == 1) {
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
        } else if (rxValue.substring(0, rxValue.indexOf('_')).toInt() == 0) {
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
        } else {
          Serial.println("INVALID DO STATE VALUE!");
        }
      } else {
        Serial.println("INVALID COMMAND SUFFIX!");
      }
    } else {
      Serial.println("INVALID MESSAGE!");
    }
  }
};

class MyUpdateCharacteristicCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    String data = pCharacteristic->getValue().c_str();
    Serial.print("DT: ");
    Serial.println(data);

    if (data.equalsIgnoreCase("0_um")) {
      if (Update.begin(2000000)) {
        otaInProgress = true;
        Serial.println("START UPDATE!");
      }
    } else if (data.equalsIgnoreCase("1_um")) {
      otaInProgress = false;
      fwUpdateFlag = true;
    } else if (otaInProgress) {
      /*
      String byteVals = String("");
      long index = data.indexOf("x");
      long previousIndex = 0;
      long byteCount = 0;
      while (index != -1) {
        byteVals += data.substring(index + 1, index + 3);
        previousIndex = index;
        index = data.indexOf("x", previousIndex + 1);
        byteCount++;
      }
      Serial.println(byteVals);
      */

      long byteCount = data.length() / 2;
      Serial.print("BC: ");
      Serial.println(byteCount);
      byte updateBuffer[byteCount];
      hexCharacterStringToBytes(updateBuffer, data.c_str());

      otaReceived += Update.write(updateBuffer, byteCount);
      Serial.print("WR: ");
      Serial.println(otaReceived);

      fwWriteFlag = true;
    }
  }
};

void resetBluetooth() {
  BLEDevice::startAdvertising();
  bluetoothActive = true;
  bluetoothPreviousMillis = millis();
}

void stopBluetooth() {
  bluetoothActive = false;
  BLEDevice::stopAdvertising();
}

String createDisplayConfigString() {
  return String(rciTitle + "_RCI;" + versionNumber + ";" + serialNumber + "_SN;" + groupID + "_GID;" + unitID + "_UID;" + IONum + "_ION;" + updateTime + "_UPT;" + consumerName + "_CN;" +
  heartbeatSubscriptionsString + "_HB;" + radioModemSelectedRFPower + "_RFP;" + radioModemSelectedChannel + "_RCH;" + radioModemSelectedPHP + "_RPH;" + radioModemSelectedSHP + "_RSH;" + radioModemSelectedNetworkID + "_RNW;" +
  do1_feed + "_DO1;" + do2_feed + "_DO2;" + do3_feed + "_DO3;" + do4_feed + "_DO4;" + do5_feed + "_DO5;" + do6_feed + "_DO6;" + do7_feed + "_DO7;" + do8_feed + "_DO8;" +
  ao1_feed + "_AO1;" + ao2_feed + "_AO2;" + ao3_feed + "_AO3;" + ao4_feed + "_AO4;" + ao5_feed + "_AO5;" + ao6_feed + "_AO6;" + ao7_feed + "_AO7;" + ao8_feed + "_AO8;" +
  df1ReadValue + "_DF1;" + df2ReadValue + "_DF2;" + df3ReadValue + "_DF3;" + df4ReadValue + "_DF4;" + df5ReadValue + "_DF5;" + df6ReadValue + "_DF6;" + df7ReadValue + "_DF7;" + df8ReadValue + "_DF8;" +
  af1ReadValue + "_AF1;" + af2ReadValue + "_AF2;" + af3ReadValue + "_AF3;" + af4ReadValue + "_AF4;" + af5ReadValue + "_AF5;" + af6ReadValue + "_AF6;" + af7ReadValue + "_AF7;" + af8ReadValue + "_AF8");
}