#include "M5StackMQTTFTP.h"
#include "sounds/sounds.h"

void onLeftPress() {
  if (leftRed.isPressed()) {
    triggerSound = true;
  }

  if (leftRed.isPressed() && normalMode && !cyclingPaused) {
    leftCyclingPausePressed = true;
  }

  if (leftRed.isPressed() && cyclingPaused) {
    leftCyclingScrollPressed = true;
  }

  if (configMenu1 || configMenu2 || configMenu3 || cfgServerMode) {
    if (leftRed.isPressed()) {
      leftPressedOnce = true;
    }
  }

  if (leftRed.isPressed() && warningMenu1) {
    leftPressedTwice = true;
  }

  if (leftRed.isPressed() && warningMenu2) {
    leftPressedThree = true;
  }
}

void onLeftRelease() {
  if (leftRed.isReleased() && triggerSound) {
    M5.Spk.PlaySound(beep, sizeof(beep));
    triggerSound = false;
    timeOutPreviousMillis = timeOutCurrentMillis;
  }

  if (leftRed.isReleased() && leftCyclingPausePressed) {
    cycleCounter--;
    if (cycleCounter < 0) {
      cycleCounter = 3;
    }
    cyclingPaused = true;
    leftCyclingPausePressed = false;
    cycleComponentValues();
    cyclingPausePreviousMillis = cyclingPauseCurrentMillis;
    cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
  }

  if (leftRed.isReleased() && leftCyclingScrollPressed) {
    cycleCounter--;
    if (cycleCounter < 0) {
      cycleCounter = 3;
    }
    leftCyclingScrollPressed = false;
    cycleComponentValues();
    cyclingPausePreviousMillis = cyclingPauseCurrentMillis;
    cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
  }

  if (warningMenu1) {
    if (leftRed.isReleased() && leftPressedTwice) {
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
      M5.Lcd.drawString(dateString, 20, 200, 1);
      //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
    }
  }

  if (warningMenu2) {
    if (leftRed.isReleased() && leftPressedThree) {
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
      M5.Lcd.drawString(dateString, 20, 200, 1);
      //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
    }
  }

  if (cfgServerMode) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
      viewConfigItemsIterator--;
      if (viewConfigItemsIterator < 0) {
        viewConfigItemsIterator = 20;
      }
      cycleConfigItems(viewConfigItemsIterator);
    }
  }

  if (configMenu1 || configMenu2) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
      configMenu1Iterator--;
      if (configMenu1) {
        if (configMenu1Iterator < 0) {
          configMenu1Iterator = 3; //CHANGE TO ADJUST NUMBER OF MENUS
        }
      }
      else if (configMenu2) {
        if (configMenu1Iterator < 0) {
          configMenu1Iterator = 4; //CHANGE TO ADJUST NUMBER OF MENUS
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
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
    }
  }
  if (configMenu3 && configMenu1Iterator == 2) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
    }  
  }
  if (configMenu3 && configMenu1Iterator == 3) {
    if (leftRed.isReleased() && leftPressedOnce) {
      leftPressedOnce = false;
    }
  }
}

void onCenterPress() {
  if (centerRed.isPressed()) {
    triggerSound = true;
  }

  if (centerRed.isPressed() && normalMode && !cyclingPaused) {
    centerCyclingPausePressed = true;
  }

  if (centerRed.isPressed() && cyclingPaused) {
    centerCyclingScrollPressed = true;
  }

  if (configMenu1 || configMenu2 || configMenu3 || cfgServerMode) {
    if (centerRed.isPressed()) {
      centerPressedOnce = true;
    }
  }
}

void onCenterRelease() {
  if (centerRed.isReleased() && triggerSound) {
    M5.Spk.PlaySound(beep, sizeof(beep));
    triggerSound = false;
    timeOutPreviousMillis = timeOutCurrentMillis;
  }

  if (centerRed.isReleased() && centerCyclingPausePressed) {
    cycleCounter--;
    if (cycleCounter < 0) {
      cycleCounter = 3;
    }
    cyclingPaused = true;
    centerCyclingPausePressed = false;
    cycleComponentValues();
    cyclingPausePreviousMillis = cyclingPauseCurrentMillis;
    cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
  }

  if (centerRed.isReleased() && centerCyclingScrollPressed) {
    cycleCounter++;
    if (cycleCounter >= 4) {
      cycleCounter = 0;
    }
    centerCyclingScrollPressed = false;
    cycleComponentValues();
    cyclingPausePreviousMillis = cyclingPauseCurrentMillis;
    cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
  }

  if (cfgServerMode) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
      viewConfigItemsIterator++;
      if (viewConfigItemsIterator > 20) {
        viewConfigItemsIterator = 0;
      }
      cycleConfigItems(viewConfigItemsIterator);
    }
  }
  
  if (configMenu1 || configMenu2) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
      configMenu1Iterator++;
      if (configMenu1) {
        if (configMenu1Iterator > 3) { //CHANGE TO ADJUST NUMBER OF MENUS
          configMenu1Iterator = 0;
        }
      }
      else if (configMenu2) {
        if (configMenu1Iterator > 4) { //CHANGE TO ADJUST NUMBER OF MENUS
          configMenu1Iterator = 0;
        }
      }
      if (configMenu1Iterator == 0) {
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
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
    }
  }
  if (configMenu3 && configMenu1Iterator == 2) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
    }  
  }
  if (configMenu3 && configMenu1Iterator == 3) {
    if (centerRed.isReleased() && centerPressedOnce) {
      centerPressedOnce = false;
    }
  }
}

void onRightPress() {
  if (rightRed.isPressed()) {
    triggerSound = true;
  }

  if (rightRed.isPressed() && cyclingPaused) {
    rightCyclingUnpausePressed = true;
  }

  if (rightRed.isPressed() && (normalMode || cfgServerMode) && !cyclingPaused) {
    rightPressedOnce = true;
    //normalMode = false;
  }

  if (rightRed.isPressed() && configMenu1) {
    rightPressedTwice = true;
    //configMenu1 = false;
  }

  if (rightRed.isPressed() && (configMenu2 || warningMenu1)) {
    rightPressedThree = true;
    //configMenu2 = false;
  }

  if (rightRed.isPressed() && (configMenu3 || warningMenu2)) {
    rightPressedFour = true;
    //configMenu3 = false;
  }
}

void onRightRelease() {
  if (rightRed.isReleased() && triggerSound) {
    M5.Spk.PlaySound(beep, sizeof(beep));
    triggerSound = false;
    timeOutPreviousMillis = timeOutCurrentMillis;
  }

  if (rightRed.isReleased() && rightCyclingUnpausePressed) {
    cyclingPaused = false;
    rightCyclingUnpausePressed = false;

    cycleComponentValues();
    cycleComponentsPreviousMillis = cycleComponentsCurrentMillis;
  }

  if (warningMenu1) {
    if (rightRed.isReleased() && rightPressedThree) {
      rightPressedThree = false;
      warningMenu1 = false;
      warningMenu2 = true;
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);

      M5.Lcd.drawString("ARE YOU SURE?", 40, 20, 1);
      M5.Lcd.drawString("SYSTEM WILL HAVE", 5, 80, 1);
      M5.Lcd.drawString("NEW SETTINGS!", 40, 140, 1);
      M5.Lcd.drawString("BACK", 10, 210, 1);
      M5.Lcd.drawString("CONTINUE", 175, 210, 1);
    }
  }

  if (warningMenu2) {
    if (rightRed.isReleased() && rightPressedFour) {
      rightPressedFour = false;
      warningMenu2 = false;
      M5.Lcd.drawString("CONFIG MODE", 10, 200, 1);
      delay(1000);
      //M5.Lcd.clear();
      //M5.Lcd.setCursor(0, 0);
      cfgServerMode = true;
      hasConfigInfo = false;

      configConnect();
    }
  }

  if (cfgServerMode) {
    if (rightRed.isReleased() && rightPressedOnce) {
      cfgServerMode = false;
      //normalMode = true;
      hasConfigInfo = true;
      rightPressedOnce = false;

      if (startUpMode && forceUpdate) {
        forceUpdate = false;

        myFile = SD.open(sdConfigFileName, FILE_WRITE);
        myFile.print(groupID + "_GID;" + unitID + "_UID;" + IONum + "_ION;" + updateTime + "_UPT;" + consumerName + "_CN;" +
        *di_feeds[0] + ";" + *di_feeds[1] + ";" + *di_feeds[2] + ";" + *di_feeds[3] + ";" + *di_feeds[4] + ";" + *di_feeds[5] + ";" + *di_feeds[6] + ";" + *di_feeds[7] + ";" +
        *ai_feeds[0] + ";" + *ai_feeds[1] + ";" + *ai_feeds[2] + ";" + *ai_feeds[3] + ";" + *ai_feeds[4] + ";" + *ai_feeds[5] + ";" + *ai_feeds[6] + ";" + *ai_feeds[7] + ";" +
        do1_feed + "_DO1;" + do2_feed + "_DO2;" + do3_feed + "_DO3;" + do4_feed + "_DO4;" + do5_feed + "_DO5;" + do6_feed + "_DO6;" + do7_feed + "_DO7;" + do8_feed + "_DO8;" +
        ao1_feed + "_AO1;" + ao2_feed + "_AO2;" + ao3_feed + "_AO3;" + ao4_feed + "_AO4;" + ao5_feed + "_AO5;" + ao6_feed + "_AO6;" + ao7_feed + "_AO7;" + ao8_feed + "_AO8;" +
        df1ReadValue + "_DF1;" + df2ReadValue + "_DF2;" + df3ReadValue + "_DF3;" + df4ReadValue + "_DF4;" + df5ReadValue + "_DF5;" + df6ReadValue + "_DF6;" + df7ReadValue + "_DF7;" + df8ReadValue + "_DF8;" +
        af1ReadValue + "_AF1;" + af2ReadValue + "_AF2;" + af3ReadValue + "_AF3;" + af4ReadValue + "_AF4;" + af5ReadValue + "_AF5;" + af6ReadValue + "_AF6;" + af7ReadValue + "_AF7;" + af8ReadValue + "_AF8;" +
        heartbeatSubscriptionsString + "_HB;");
        myFile.close();
        //ESP.restart();

        apiConnect();
        credConnect();
      }

      if (initialSDCheck) {
        //M5.Lcd.fillRect(10, 190, 300, 50, BLACK);
        //M5.Lcd.drawString("NORMAL MODE", 10, 200, 1);
        initialSDCheck = false;
        returnToNormalOperation();
        //delay(1000);
      } else {
        configMenu1 = true;
        M5.Lcd.fillRect(0, 190, 300, 50, BLACK);
        M5.Lcd.drawString("SETTINGS MODE", 10, 200, 1);
        delay(1000);
        M5.Lcd.clear();
        M5.Lcd.setCursor(0, 0);

        M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
        M5.Lcd.drawString("EXIT", 80, 0, 1);
        M5.Lcd.drawString("DEVICE INFO", 50, 50, 1);
        M5.Lcd.drawString("OUTPUT TEST", 50, 100, 1);
        M5.Lcd.drawString("DEVICE CONFIG", 50, 150, 1);
        M5.Lcd.drawString(dateString, 20, 200, 1);
        //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
      }
    }
  }

  if (rightRed.isReleased() && rightPressedOnce) {
    normalMode = false;
    configMenu1 = true;
    rightPressedOnce = false;
    M5.Lcd.fillRect(0, 190, 300, 50, BLACK);
    M5.Lcd.drawString("SETTINGS MODE", 10, 200, 1);
    delay(1000);
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);

    M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
    M5.Lcd.drawString(rciTitle, 50, 70, 1);
    M5.Lcd.drawString("CLOSING", 90, 120, 1);
    M5.Lcd.drawString("CONNECTION", 60, 170, 1);

    mqttClient.stop();

    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);
    delay(100);

    M5.Lcd.fillRect(50, 0, 20, 20, GREEN);
    M5.Lcd.drawString("EXIT", 80, 0, 1);
    M5.Lcd.drawString("DEVICE INFO", 50, 50, 1);
    M5.Lcd.drawString("OUTPUT TEST", 50, 100, 1);
    M5.Lcd.drawString("DEVICE CONFIG", 50, 150, 1);
    M5.Lcd.drawString(dateString, 20, 200, 1);
    //M5.Lcd.drawString("WATCHDOG TEST", 50, 200, 1);
  }

  if (rightRed.isReleased() && rightPressedTwice) {
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
      M5.Lcd.drawString("THIS WILL ERASE", 10, 80, 1);
      M5.Lcd.drawString("CURRENT SETTINGS!", 5, 140, 1);
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

  if (rightRed.isReleased() && rightPressedThree) {
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
      M5.Lcd.drawString(dateString, 20, 200, 1);
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

  if (rightRed.isReleased() && rightPressedFour) {
    firstConfigAo1Press = true;
    configAo1Counter = 0;
    configAo1Value = 0;
    configAo2Value = 0;

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