#include "M5StackRadio.h"

void pollForChannelChanges() {
  switch (IONum.toInt()) {
    case 8:
      if (digitalInputSuccess) {
        if (newDI8Available()) {
          updateDI8();

          if (isDigitalInputScreen()) {
            displayDI8();
          }
        }
      }

      if (analogInTwoSuccess) {
        if (newAI8Available()) {
          updateAI8();

          if (isAnalogInputScreen()) {
            displayAI8();
          }
        }
      }

    case 7:
      if (digitalInputSuccess) {
        if (newDI7Available()) {
          updateDI7();

          if (isDigitalInputScreen()) {
            displayDI7();
          }
        }
      }

      if (analogInTwoSuccess) {
        if (newAI7Available()) {
          updateAI7();

          if (isAnalogInputScreen()) {
            displayAI7();
          }
        }
      }

    case 6:
      if (digitalInputSuccess) {
        if (newDI6Available()) {
          updateDI6();

          if (isDigitalInputScreen()) {
            displayDI6();
          }
        }
      }

      if (analogInTwoSuccess) {
        if (newAI6Available()) {
          updateAI6();

          if (isAnalogInputScreen()) {
            displayAI6();
          }
        }
      }

    case 5:
      if (digitalInputSuccess) {
        if (newDI5Available()) {
          updateDI5();

          if (isDigitalInputScreen()) {
            displayDI5();
          }
        }
      }

      if (analogInTwoSuccess) {
        if (newAI5Available()) {
          updateAI5();

          if (isAnalogInputScreen()) {
            displayAI5();
          }
        }
      }

    case 4:
      if (digitalInputSuccess) {
        if (newDI4Available()) {
          updateDI4();

          if (isDigitalInputScreen()) {
            displayDI4();
          }
        }
      }

      if (analogInOneSuccess) {
        if (newAI4Available()) {
          updateAI4();

          if (isAnalogInputScreen()) {
            displayAI4();
          }
        }
      }
  
    case 3:
      if (digitalInputSuccess) {
        if (newDI3Available()) {
          updateDI3();

          if (isDigitalInputScreen()) {
            displayDI3();
          }
        }
      }

      if (analogInOneSuccess) {
        if (newAI3Available()) {
          updateAI3();

          if (isAnalogInputScreen()) {
            displayAI3();
          }
        }
      }

    case 2:
      if (digitalInputSuccess) {
        if (newDI2Available()) {
          updateDI2();

          if (isDigitalInputScreen()) {
            displayDI2();
          }
        }
      }

      if (analogInOneSuccess) {
        if (newAI2Available()) {
          updateAI2();

          if (isAnalogInputScreen()) {
            displayAI2();
          }
        }
      }

    case 1:
      if (digitalInputSuccess) {
        if (newDI1Available()) {
          updateDI1();

          if (isDigitalInputScreen()) {
            displayDI1();
          }
        }
      }

      if (analogInOneSuccess) {
        if (newAI1Available()) {
          updateAI1();

          if (isAnalogInputScreen()) {
            displayAI1();
          }
        }
      }
    
    default:
      break;
  }
}

void cycleComponentValues(bool continuousUpdate) {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  if (!cyclingPaused) {
    M5.Lcd.drawString("CFG", 240, 210, 1);
  } else {
    M5.Lcd.drawString("RES", 240, 210, 1);
  }

  //DISPLAY CELLULAR SIGNAL STATUS
  /*
  Serial.println("CONNECTED REMOTES: ");
  for (int i = 0; i < 5; i++) {
    Serial.println(connectedRemoteUnitIDs[i]);
  }
  */

  if (!heartbeatCheckAlreadySetFailDefaults[signalCounter]) {
    signalStatusString = String("OK");
    M5.Lcd.setTextColor(GREEN);
  } else {
    signalStatusString = String("FAIL");
    M5.Lcd.setTextColor(RED);
  }
  if (isHost) {
    String tempHeartbeatCheckFeed = *heartbeat_check_feeds[signalCounter];
    int targetUnitID = tempHeartbeatCheckFeed.substring(tempHeartbeatCheckFeed.indexOf("_") + 1, tempHeartbeatCheckFeed.indexOf("_", tempHeartbeatCheckFeed.indexOf("_") + 1)).toInt() - 1;
    String stringTargetUnitID = String(targetUnitID);
    M5.Lcd.drawString("R" + stringTargetUnitID + String(" ") + signalStatusString, 105, 210, 1);
  } else {
    M5.Lcd.drawString("H" + String(" ") + signalStatusString, 115, 210, 1);
  }
  M5.Lcd.setTextColor(WHITE);

  //displayCellularSignalQuality();

  if (cycleCounter == 0) {
    M5.Lcd.drawString("Digital Inputs", 40, 0, 1);

    switch (IONum.toInt()) {
      case 8:
        displayDI8();

      case 7:
        displayDI7();
      
      case 6:
        displayDI6();
      
      case 5:
        displayDI5();
      
      case 4:
        displayDI4();
      
      case 3:
        displayDI3();
      
      case 2:
        displayDI2();
      
      case 1:
        displayDI1();

      default:
        break;
    }
  }
  if (cycleCounter == 1) {
    M5.Lcd.drawString("Digital Outputs", 30, 0, 1);

    switch (IONum.toInt()) {
      case 8:
        displayDO8();

      case 7:
        displayDO7();
      
      case 6:
        displayDO6();
      
      case 5:
        displayDO5();
      
      case 4:
        displayDO4();
      
      case 3:
        displayDO3();
      
      case 2:
        displayDO2();
      
      case 1:
        displayDO1();

      default:
        break;
    }
  }
  if (cycleCounter == 2) {
    M5.Lcd.drawString("Analog In (mA)", 30, 0, 1);

    switch (IONum.toInt()) {
      case 8:
        displayAI8();

      case 7:
        displayAI7();
      
      case 6:
        displayAI6();
      
      case 5:
        displayAI5();
      
      case 4:
        displayAI4();
      
      case 3:
        displayAI3();
      
      case 2:
        displayAI2();
      
      case 1:
        displayAI1();

      default:
        break;
    }
  }
  if (cycleCounter == 3) {
    M5.Lcd.drawString("Analog Out (mA)", 25, 0, 1);
    
    switch (IONum.toInt()) {
      case 8:
        displayAO8();

      case 7:
        displayAO7();
      
      case 6:
        displayAO6();
      
      case 5:
        displayAO5();
      
      case 4:
        displayAO4();
      
      case 3:
        displayAO3();
      
      case 2:
        displayAO2();
      
      case 1:
        displayAO1();

      default:
        break;
    }
  }

  if (!cyclingPaused && !continuousUpdate) {
    cycleCounter++;
    signalCounter++;
    if (cycleCounter >= 4) {
      cycleCounter = 0;
    }
    if (signalCounter >= subCount) {
      signalCounter = 0;
    }
  }
}

bool isDigitalInputScreen() {
  return (!cyclingPaused && cycleCounter == 1) || (cyclingPaused && cycleCounter == 0);
}

bool isDigitalOutputScreen() {
  return (!cyclingPaused && cycleCounter == 2) || (cyclingPaused && cycleCounter == 1);
}

bool isAnalogInputScreen() {
  return (!cyclingPaused && cycleCounter == 3) || (cyclingPaused && cycleCounter == 2);
}

bool isAnalogOutputScreen() {
  return (!cyclingPaused && cycleCounter == 0) || (cyclingPaused && cycleCounter == 3);
}

void cycleConfigItems(int startIndex) {
  M5.Lcd.fillRect(0, 35, 350, 150, BLACK);
  String screenItem1 = String("");
  String screenItem2 = String("");
  String screenItem3 = String("");
  String screenItem4 = String("");
  String screenItem5 = String("");

  screenItem1 = *configItems[startIndex];
  screenItem2 = *configItems[startIndex + 1];
  screenItem3 = *configItems[startIndex + 2];
  screenItem4 = *configItems[startIndex + 3];
  screenItem5 = *configItems[startIndex + 4];

  M5.Lcd.drawString(screenItem1, 0, 40, 1);
  M5.Lcd.drawString(screenItem2, 0, 70, 1);
  M5.Lcd.drawString(screenItem3, 0, 100, 1);
  M5.Lcd.drawString(screenItem4, 0, 130, 1);
  M5.Lcd.drawString(screenItem5, 0, 160, 1);
  M5.Lcd.drawString("ESC", 245, 210, 1);
  if (bluetoothActive) {
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.drawString("BLE ON", 130, 210, 1);
    M5.Lcd.setTextColor(WHITE);
  }
  M5.Lcd.drawString(versionNumber, 1, 210, 1);
}