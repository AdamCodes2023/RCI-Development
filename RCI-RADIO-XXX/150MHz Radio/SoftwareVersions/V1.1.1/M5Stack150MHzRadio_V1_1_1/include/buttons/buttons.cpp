#include "M5StackRadio.h"
#include "sounds/sounds.cpp"

void onLeftPress() {
  if (M5.BtnA.wasPressed()) {
    triggerSound = true;
  }

  if (M5.BtnA.wasPressed() && normalMode && !cyclingPaused) {
    leftCyclingPausePressed = true;
  }

  if (M5.BtnA.wasPressed() && cyclingPaused) {
    leftCyclingScrollPressed = true;
  }

  if (configMenu1 || configMenu2 || configMenu3 || cfgServerMode) {
    if (M5.BtnA.wasPressed()) {
      leftPressedOnce = true;
    }
  }

  if (M5.BtnA.wasPressed() && warningMenu1) {
    leftPressedTwice = true;
  }

  if (M5.BtnA.wasPressed() && warningMenu2) {
    leftPressedThree = true;
  }
}

void onLeftRelease() {
  if (M5.BtnA.wasReleased() && triggerSound) {
    M5.Spk.PlaySound(beep, sizeof(beep));
    triggerSound = false;
    timeOutPreviousMillis = timeOutCurrentMillis;
  }

  if (M5.BtnA.wasReleased() && leftCyclingPausePressed) {
    cycleCounter--;
    if (cycleCounter < 0) {
      cycleCounter = 3;
    }
    signalCounter--;
    if (signalCounter < 0) {
      signalCounter = numberOfRemoteUnits - 1;
    }
    cyclingPaused = true;
    leftCyclingPausePressed = false;
    cycleComponentValues(!screenRefresh);
    continuousUpdateComponentsPreviousMillis = continuousUpdateComponentsCurrentMillis;
    cyclingPausePreviousMillis = cyclingPauseCurrentMillis;
    cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
  }

  if (M5.BtnA.wasReleased() && leftCyclingScrollPressed) {
    cycleCounter--;
    if (cycleCounter < 0) {
      cycleCounter = 3;
    }
    signalCounter--;
    if (signalCounter < 0) {
      signalCounter = numberOfRemoteUnits - 1;
    }
    leftCyclingScrollPressed = false;
    cycleComponentValues(!screenRefresh);
    continuousUpdateComponentsPreviousMillis = continuousUpdateComponentsCurrentMillis;
    cyclingPausePreviousMillis = cyclingPauseCurrentMillis;
    cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
  }

  if (warningMenu1) {
    if (M5.BtnA.wasReleased() && leftPressedTwice) {
      leftPressedTwice = false;
      warningMenu1 = false;
      configMenu1 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
      M5.Lcd.drawString("EXIT", 80, 0, 1);
      M5.Lcd.drawString("DEVICE INFO", 50, 50, 1);
      M5.Lcd.drawString("OUTPUT TEST", 50, 100, 1);
      M5.Lcd.drawString("DEVICE CONFIG", 50, 150, 1);
      //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
    }
  }

  if (warningMenu2) {
    if (M5.BtnA.wasReleased() && leftPressedThree) {
      leftPressedThree = false;
      warningMenu2 = false;
      configMenu1 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
      M5.Lcd.drawString("EXIT", 80, 0, 1);
      M5.Lcd.drawString("DEVICE INFO", 50, 50, 1);
      M5.Lcd.drawString("OUTPUT TEST", 50, 100, 1);
      M5.Lcd.drawString("DEVICE CONFIG", 50, 150, 1);
      //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
    }
  }

  if (cfgServerMode) {
    if (M5.BtnA.wasReleased() && leftPressedOnce) {
      leftPressedOnce = false;
      viewConfigItemsIterator--;
      if (viewConfigItemsIterator < 0) {
        viewConfigItemsIterator = 20;
      }
      cycleConfigItems(viewConfigItemsIterator);
    }
  }

  if (configMenu1 || configMenu2) {
    if (M5.BtnA.wasReleased() && leftPressedOnce) {
      leftPressedOnce = false;
      configMenu1Iterator--;
      if (configMenu1) {
        if (configMenu1Iterator < 0) {
          configMenu1Iterator = 3; //CHANGE TO ADJUST NUMBER OF MENUS (DO NOT FORGET TO ADJUST GREEN SELECTION SQUARE)
        }
      }
      else if (configMenu2) {
        if (configMenu1Iterator < 0) {
          configMenu1Iterator = 4; //CHANGE TO ADJUST NUMBER OF MENUS (DO NOT FORGET TO ADJUST GREEN SELECTION SQUARE)
        }
      }
      if (configMenu1Iterator == 0) {
        M5.Lcd.fillRect(20, 50, 20, 20, BLACK);
        M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 1) {
        M5.Lcd.fillRect(20, 100, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 50, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 2) {
        M5.Lcd.fillRect(20, 150, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 100, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 3) {
        //ADJUST GREEN SELECTION SQUARE HERE
        if (configMenu1) {
          M5.Lcd.fillRect(50, 0, 20, 20, BLACK);
          M5.Lcd.fillRect(20, 150, 20, 20, GREEN);
        }
        else if (configMenu2) {
          M5.Lcd.fillRect(20, 200, 20, 20, BLACK);
          M5.Lcd.fillRect(20, 150, 20, 20, GREEN);
        }
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 4) {
        M5.Lcd.fillRect(50, 0, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 200, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
    }
  }
  if (configMenu3 && configMenu1Iterator == 1) {
    if (M5.BtnA.wasReleased() && leftPressedOnce) {
      leftPressedOnce = false;
    }
  }
  if (configMenu3 && configMenu1Iterator == 2) {
    if (M5.BtnA.wasReleased() && leftPressedOnce) {
      leftPressedOnce = false;
    }  
  }
  if (configMenu3 && configMenu1Iterator == 3) {
    if (M5.BtnA.wasReleased() && leftPressedOnce) {
      leftPressedOnce = false;
    }
  }
}

void onCenterPress() {
  if (M5.BtnB.wasPressed()) {
    triggerSound = true;
  }

  if (M5.BtnB.wasPressed() && normalMode && !cyclingPaused) {
    centerCyclingPausePressed = true;
  }

  if (M5.BtnB.wasPressed() && cyclingPaused) {
    centerCyclingScrollPressed = true;
  }

  if (configMenu1 || configMenu2 || configMenu3 || cfgServerMode) {
    if (M5.BtnB.wasPressed()) {
      centerPressedOnce = true;
    }
  }
}

void onCenterRelease() {
  if (M5.BtnB.wasReleased() && triggerSound) {
    M5.Spk.PlaySound(beep, sizeof(beep));
    triggerSound = false;
    timeOutPreviousMillis = timeOutCurrentMillis;
  }

  if (M5.BtnB.wasReleased() && centerCyclingPausePressed) {
    cycleCounter--;
    if (cycleCounter < 0) {
      cycleCounter = 3;
    }
    signalCounter--;
    if (signalCounter < 0) {
      signalCounter = numberOfRemoteUnits - 1;
    }
    cyclingPaused = true;
    centerCyclingPausePressed = false;
    cycleComponentValues(!screenRefresh);
    continuousUpdateComponentsPreviousMillis = continuousUpdateComponentsCurrentMillis;
    cyclingPausePreviousMillis = cyclingPauseCurrentMillis;
    cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
  }

  if (M5.BtnB.wasReleased() && centerCyclingScrollPressed) {
    cycleCounter++;
    if (cycleCounter >= 4) {
      cycleCounter = 0;
    }
    signalCounter++;
    if (signalCounter >= numberOfRemoteUnits) {
      signalCounter = 0;
    }
    centerCyclingScrollPressed = false;
    cycleComponentValues(!screenRefresh);
    continuousUpdateComponentsPreviousMillis = continuousUpdateComponentsCurrentMillis;
    cyclingPausePreviousMillis = cyclingPauseCurrentMillis;
    cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
  }

  if (cfgServerMode) {
    if (M5.BtnB.wasReleased() && centerPressedOnce) {
      centerPressedOnce = false;
      viewConfigItemsIterator++;
      if (viewConfigItemsIterator > 20) {
        viewConfigItemsIterator = 0;
      }
      cycleConfigItems(viewConfigItemsIterator);
    }
  }
  
  if (configMenu1 || configMenu2) {
    if (M5.BtnB.wasReleased() && centerPressedOnce) {
      centerPressedOnce = false;
      configMenu1Iterator++;
      if (configMenu1) {
        if (configMenu1Iterator > 3) { //CHANGE TO ADJUST NUMBER OF MENUS (DO NOT FORGET TO ADJUST GREEN SELECTION SQUARE)
          configMenu1Iterator = 0;
        }
      }
      else if (configMenu2) {
        if (configMenu1Iterator > 4) { //CHANGE TO ADJUST NUMBER OF MENUS (DO NOT FORGET TO ADJUST GREEN SELECTION SQUARE)
          configMenu1Iterator = 0;
        }
      }
      if (configMenu1Iterator == 0) {
        //ADJUST GREEN SELECTION SQUARE HERE
        if (configMenu1) {
          M5.Lcd.fillRect(20, 150, 20, 20, BLACK);
          M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
        }
        else if (configMenu2) {
          M5.Lcd.fillRect(20, 200, 20, 20, BLACK);
          M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
        }
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 1) {
        M5.Lcd.fillRect(50, 0, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 50, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 2) {
        M5.Lcd.fillRect(20, 50, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 100, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 3) {
        M5.Lcd.fillRect(20, 100, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 150, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
      if (configMenu1Iterator == 4) {
        M5.Lcd.fillRect(20, 150, 20, 20, BLACK);
        M5.Lcd.fillRect(20, 200, 20, 20, GREEN);
        //M5.Lcd.drawString("EXIT", 80, 0, 1);
        //M5.Lcd.drawString("DI CONFIG", 50, 50, 1);
        //M5.Lcd.drawString("DO CONFIG", 50, 100, 1);
        //M5.Lcd.drawString("AI CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("AO CONFIG", 50, 200, 1);
      }
    }
  }
  if (configMenu3 && configMenu1Iterator == 1) {
    if (M5.BtnB.wasReleased() && centerPressedOnce) {
      centerPressedOnce = false;
    }
  }
  if (configMenu3 && configMenu1Iterator == 2) {
    if (M5.BtnB.wasReleased() && centerPressedOnce) {
      centerPressedOnce = false;
    }  
  }
  if (configMenu3 && configMenu1Iterator == 3) {
    if (M5.BtnB.wasReleased() && centerPressedOnce) {
      centerPressedOnce = false;
    }
  }
}

void onRightPress() {
  if (M5.BtnC.wasPressed()) {
    triggerSound = true;
  }

  if (M5.BtnC.wasPressed() && cyclingPaused) {
    rightCyclingUnpausePressed = true;
  }

  if (M5.BtnC.wasPressed() && (normalMode || cfgServerMode) && !cyclingPaused) {
    rightPressedOnce = true;
    //normalMode = false;
  }

  if (M5.BtnC.wasPressed() && configMenu1) {
    rightPressedTwice = true;
    //configMenu1 = false;
  }

  if (M5.BtnC.wasPressed() && (configMenu2 || warningMenu1)) {
    rightPressedThree = true;
    //configMenu2 = false;
  }

  if (M5.BtnC.wasPressed() && (configMenu3 || warningMenu2)) {
    rightPressedFour = true;
    //configMenu3 = false;
  }
}

void onRightRelease() {
  if (M5.BtnC.wasReleased() && triggerSound) {
    M5.Spk.PlaySound(beep, sizeof(beep));
    triggerSound = false;
    timeOutPreviousMillis = timeOutCurrentMillis;
  }

  if (M5.BtnC.wasReleased() && rightCyclingUnpausePressed) {
    cyclingPaused = false;
    rightCyclingUnpausePressed = false;

    cycleComponentValues(!screenRefresh);
    continuousUpdateComponentsPreviousMillis = continuousUpdateComponentsCurrentMillis;
    cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
  }

  if (warningMenu1) {
    if (M5.BtnC.wasReleased() && rightPressedThree) {
      rightPressedThree = false;
      warningMenu1 = false;
      warningMenu2 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.drawString("ARE YOU SURE?", 40, 20, 1);
      M5.Lcd.drawString("SYSTEM MAY HAVE", 20, 80, 1);
      M5.Lcd.drawString("NEW SETTINGS!", 40, 140, 1);
      M5.Lcd.drawString("BACK", 10, 210, 1);
      M5.Lcd.drawString("CONTINUE", 175, 210, 1);
    }
  }

  if (warningMenu2) {
    if (M5.BtnC.wasReleased() && rightPressedFour) {
      rightPressedFour = false;
      warningMenu2 = false;
      M5.Lcd.fillRect(0, 190, 300, 50, BLACK);
      M5.Lcd.drawString("BLE CONFIG MODE", 10, 200, 1);
      delay(1000);
      //M5.Lcd.clear();
      //M5.Lcd.setCursor(0, 0);
      cfgServerMode = true;
      hasConfigInfo = false;

      configConnect();
    }
  }

  if (cfgServerMode) {
    if (M5.BtnC.wasReleased() && rightPressedOnce) {
      if (pServer->getConnectedCount() >= 1) {
        pServer->disconnect(pServer->getConnId());
      }
      stopBluetooth();

      cfgServerMode = false;
      //normalMode = true;
      hasConfigInfo = true;
      rightPressedOnce = false;

      signalCounter = 0;
      viewConfigItemsIterator = 0;

      if (startUpMode && forceUpdate) {
        //forceUpdate = false;

        recordRCIConfigurationData();

        //rebootEspWithReason("CONFIGURATION UPDATE");
      }

      if (initialSDCheck) {
        //M5.Lcd.fillRect(10, 190, 300, 50, BLACK);
        //M5.Lcd.drawString("NORMAL MODE", 10, 200, 1);
        initialSDCheck = false;
        returnToNormalOperation();
        //delay(1000);
      } else {
        configMenu1 = true;
        M5.Lcd.fillRect(0, 190, 200, 50, BLACK);
        M5.Lcd.drawString("SETTINGS MODE", 10, 200, 1);
        delay(1000);
        M5.Lcd.clear();
        M5.Lcd.setCursor(0, 0);

        M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DEVICE INFO", 50, 50, 1);
        M5.Lcd.drawString("OUTPUT TEST", 50, 100, 1);
        M5.Lcd.drawString("DEVICE CONFIG", 50, 150, 1);
        //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
      }
    }
  }

  if (M5.BtnC.wasReleased() && rightPressedOnce) {
    normalMode = false;
    configMenu1 = true;
    rightPressedOnce = false;
    M5.Lcd.fillRect(0, 190, 200, 50, BLACK);
    M5.Lcd.drawString("SETTINGS MODE", 10, 200, 1);
    delay(1000);
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);

    M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
    M5.Lcd.drawString(rciTitle, 50, 70, 1);
    M5.Lcd.drawString("CLOSING", 90, 120, 1);
    M5.Lcd.drawString("CONNECTION", 60, 170, 1);

    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);
    delay(100);

    M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
    M5.Lcd.drawString("EXIT", 80, 0, 1);
    M5.Lcd.drawString("DEVICE INFO", 50, 50, 1);
    M5.Lcd.drawString("OUTPUT TEST", 50, 100, 1);
    M5.Lcd.drawString("DEVICE CONFIG", 50, 150, 1);
    //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
  }

  if (M5.BtnC.wasReleased() && rightPressedTwice) {
    rightPressedTwice = false;

    if (configMenu1Iterator == 0) {
      returnToNormalOperation();
    }

    if (configMenu1Iterator == 2) {
      configMenu1 = false;
      configMenu2 = true;
      configMenu1Iterator = 0;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
      M5.Lcd.drawString("EXIT", 80, 0, 1);
      M5.Lcd.drawString("OUTPUT = 20mA", 50, 50, 1);
      M5.Lcd.drawString("OUTPUT = 12mA", 50, 100, 1);
      M5.Lcd.drawString("OUTPUT = 4mA", 50, 150, 1);
      M5.Lcd.drawString("OUTPUT = INPUT", 50, 200, 1);
    }

    if (configMenu1Iterator == 3) {
      configMenu1Iterator = 0;
      configMenu1 = false;
      warningMenu1 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.drawString("WARNING!", 80, 20, 1);
      M5.Lcd.drawString("THIS MAY ERASE", 30, 80, 1);
      M5.Lcd.drawString("CURRENT SETTINGS!", 10, 140, 1);
      M5.Lcd.drawString("BACK", 10, 210, 1);
      M5.Lcd.drawString("CONTINUE", 175, 210, 1);
    }

    if (configMenu1Iterator == 1) {
      configMenu1Iterator = 0;
      configMenu1 = false;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      M5.Lcd.drawString("CONFIG INFO", 40, 0, 1);
      cycleConfigItems(viewConfigItemsIterator);
      cfgServerMode = true;
      hasConfigInfo = false;
      ioKnown = true;
    }

    if (configMenu1Iterator == 4) {
      delay(5000);
    }
  }

  if (M5.BtnC.wasReleased() && rightPressedThree) {
    rightPressedThree = false;

    if (configMenu1Iterator == 0) {
      configMenu1 = true;
      configMenu2 = false;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
      M5.Lcd.drawString("EXIT", 80, 0, 1);
      M5.Lcd.drawString("DEVICE INFO", 50, 50, 1);
      M5.Lcd.drawString("OUTPUT TEST", 50, 100, 1);
      M5.Lcd.drawString("DEVICE CONFIG", 50, 150, 1);
      //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
    }

    if (configMenu1Iterator == 1) {
      configMenu2 = false;
      configMenu3 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      delay(300);
      M5.Lcd.drawString("ALL RELAYS = ON", 10, 50, 1);
      M5.Lcd.drawString("ALL OUTPUTS = 20mA", 0, 120, 1);
      M5.Lcd.drawString("ESC", 240, 210, 1);

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
    }

    if (configMenu1Iterator == 3) {
      configMenu2 = false;
      configMenu3 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      delay(300);
      M5.Lcd.drawString("ALL RELAYS = OFF", 10, 50, 1);
      M5.Lcd.drawString("ALL OUTPUTS = 4mA", 5, 120, 1);
      M5.Lcd.drawString("ESC", 240, 210, 1);

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
    }

    if (configMenu1Iterator == 4) {
      configMenu2 = false;
      configMenu3 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      delay(300);
      M5.Lcd.drawString("COPY ALL INPUT", 10, 50, 1);
      M5.Lcd.drawString("VALUES TO OUTPUT", 10, 120, 1);
      M5.Lcd.drawString("ESC", 240, 210, 1);

      if (digitalDebugSuccess) {
        pcfw2.digitalWrite(0, false);
      }

      copyMode = true;
    }
    
    if (configMenu1Iterator == 2) {
      configMenu2 = false;
      configMenu3 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      delay(300);
      M5.Lcd.drawString("ALL RELAYS = OFF", 10, 50, 1);
      M5.Lcd.drawString("ALL OUTPUTS = 12mA", 0, 120, 1);
      M5.Lcd.drawString("ESC", 240, 210, 1);

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
    }
  }

  if (M5.BtnC.wasReleased() && rightPressedFour) {
    copyMode = false;
    rightPressedFour = false;
    configMenu2 = true;
    configMenu3 = false;
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);
    delay(300);

    configMenu1Iterator = 0;
    M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
    M5.Lcd.drawString("EXIT", 80, 0, 1);
    M5.Lcd.drawString("OUTPUT = 20mA", 50, 50, 1);
    M5.Lcd.drawString("OUTPUT = 12mA", 50, 100, 1);
    M5.Lcd.drawString("OUTPUT = 4mA", 50, 150, 1);
    M5.Lcd.drawString("OUTPUT = INPUT", 50, 200, 1);
  }
}