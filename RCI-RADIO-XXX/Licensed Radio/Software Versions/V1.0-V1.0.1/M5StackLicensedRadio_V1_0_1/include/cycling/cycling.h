#include "M5StackRadio.h"

void cycleComponentValues() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  if (!cyclingPaused) {
    M5.Lcd.drawString("CFG", 240, 210, 1);
  } else {
    M5.Lcd.drawString("RES", 240, 210, 1);
  }

  /*
  //DISPLAY CELLULAR SIGNAL QUALITY
  if (!testingSignal || !isHost) {
    if (isHost) {
      if (unitRSSIs[signalCounter] >= 0) {
        signalStrengthString = String("NA");
      } else {
        signalStrengthString = String(unitRSSIs[signalCounter]);
      }
      int targetUnitID = connectedRemoteUnitIDs[signalCounter];
      String stringTargetUnitID = String(targetUnitID);
      M5.Lcd.drawString("R" + stringTargetUnitID, 1, 210, 1);
    } else {
      M5.Lcd.drawString("H", 21, 210, 1);
    }
    Serial.println(signalStrengthString);
    displayCellularSignalQuality();
  }
  */

  if (cycleCounter == 0) {
    M5.Lcd.drawString("Digital Inputs", 40, 0, 1);

    if (IONum.toInt() >= 1) {
      if (di1_value.toInt() == 0) {
        if (noHandshakeDigitalInputFeeds[0]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("1: OFF D", 0, 40, 1);
        } else {
          M5.Lcd.drawString("1: OFF", 0, 40, 1);
        }
      }
      if (di1_value.toInt() == 1) {
        if (noHandshakeDigitalInputFeeds[0]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("1: ON D", 0, 40, 1);
        } else {
          M5.Lcd.drawString("1: ON", 0, 40, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 2) {
      if (di2_value.toInt() == 0) {
        if (noHandshakeDigitalInputFeeds[1]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("2: OFF D", 0, 80, 1);
        } else {
          M5.Lcd.drawString("2: OFF", 0, 80, 1);
        }
      }
      if (di2_value.toInt() == 1) {
        if (noHandshakeDigitalInputFeeds[1]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("2: ON D", 0, 80, 1);
        } else {
          M5.Lcd.drawString("2: ON", 0, 80, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 3) {
      if (di3_value.toInt() == 0) {
        if (noHandshakeDigitalInputFeeds[2]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("3: OFF D", 0, 120, 1);
        } else {
          M5.Lcd.drawString("3: OFF", 0, 120, 1);
        }
      }
      if (di3_value.toInt() == 1) {
        if (noHandshakeDigitalInputFeeds[2]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("3: ON D", 0, 120, 1);
        } else {
          M5.Lcd.drawString("3: ON", 0, 120, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 4) {
      if (di4_value.toInt() == 0) {
        if (noHandshakeDigitalInputFeeds[3]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("4: OFF D", 0, 160, 1);
        } else {
          M5.Lcd.drawString("4: OFF", 0, 160, 1);
        }
      }
      if (di4_value.toInt() == 1) {
        if (noHandshakeDigitalInputFeeds[3]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("4: ON D", 0, 160, 1);
        } else {
          M5.Lcd.drawString("4: ON", 0, 160, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 5) {
      if (di5_value.toInt() == 0) {
        if (noHandshakeDigitalInputFeeds[4]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("5: OFF D", 170, 40, 1);
        } else {
          M5.Lcd.drawString("5: OFF", 170, 40, 1);
        }
      }
      if (di5_value.toInt() == 1) {
        if (noHandshakeDigitalInputFeeds[4]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("5: ON D", 170, 40, 1);
        } else {
          M5.Lcd.drawString("5: ON", 170, 40, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 6) {
      if (di6_value.toInt() == 0) {
        if (noHandshakeDigitalInputFeeds[5]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("6: OFF D", 170, 80, 1);
        } else {
          M5.Lcd.drawString("6: OFF", 170, 80, 1);
        }
      }
      if (di6_value.toInt() == 1) {
        if (noHandshakeDigitalInputFeeds[5]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("6: ON D", 170, 80, 1);
        } else {
          M5.Lcd.drawString("6: ON", 170, 80, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 7) {
      if (di7_value.toInt() == 0) {
        if (noHandshakeDigitalInputFeeds[6]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("7: OFF D", 170, 120, 1);
        } else {
          M5.Lcd.drawString("7: OFF", 170, 120, 1);
        }
      }
      if (di7_value.toInt() == 1) {
        if (noHandshakeDigitalInputFeeds[6]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("7: ON D", 170, 120, 1);
        } else {
          M5.Lcd.drawString("7: ON", 170, 120, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 8) {
      if (di8_value.toInt() == 0) {
        if (noHandshakeDigitalInputFeeds[7]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("8: OFF D", 170, 160, 1);
        } else {
          M5.Lcd.drawString("8: OFF", 170, 160, 1);
        }
      }
      if (di8_value.toInt() == 1) {
        if (noHandshakeDigitalInputFeeds[7]) {
          M5.Lcd.setTextColor(BLUE);
          M5.Lcd.drawString("8: ON D", 170, 160, 1);
        } else {
          M5.Lcd.drawString("8: ON", 170, 160, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }
  }
  if (cycleCounter == 1) {
    M5.Lcd.drawString("Digital Outputs", 30, 0, 1);

    if (IONum.toInt() >= 1) {
      if (do1CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (do1_fail_default == 0) {
          M5.Lcd.drawString("1: OFF F", 0, 40, 1);
        }
        if (do1_fail_default == 1) {
          M5.Lcd.drawString("1: ON F", 0, 40, 1);
        }
        if (do1_fail_default == 2) {
          if (do1_value.toInt() == 0) {
            M5.Lcd.drawString("1: OFF F", 0, 40, 1);
          }
          if (do1_value.toInt() == 1) {
            M5.Lcd.drawString("1: ON F", 0, 40, 1);
          }
        }
      } else {
        if (do1_value.toInt() == 0) {
          M5.Lcd.drawString("1: OFF", 0, 40, 1);
        }
        if (do1_value.toInt() == 1) {
          M5.Lcd.drawString("1: ON", 0, 40, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 2) {
      if (do2CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (do2_fail_default == 0) {
          M5.Lcd.drawString("2: OFF F", 0, 80, 1);
        }
        if (do2_fail_default == 1) {
          M5.Lcd.drawString("2: ON F", 0, 80, 1);
        }
        if (do2_fail_default == 2) {
          if (do2_value.toInt() == 0) {
            M5.Lcd.drawString("2: OFF F", 0, 80, 1);
          }
          if (do2_value.toInt() == 1) {
            M5.Lcd.drawString("2: ON F", 0, 80, 1);
          }
        }
      } else {
        if (do2_value.toInt() == 0) {
          M5.Lcd.drawString("2: OFF", 0, 80, 1);
        }
        if (do2_value.toInt() == 1) {
          M5.Lcd.drawString("2: ON", 0, 80, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 3) {
      if (do3CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (do3_fail_default == 0) {
          M5.Lcd.drawString("3: OFF F", 0, 120, 1);
        }
        if (do3_fail_default == 1) {
          M5.Lcd.drawString("3: ON F", 0, 120, 1);
        }
        if (do3_fail_default == 2) {
          if (do3_value.toInt() == 0) {
            M5.Lcd.drawString("3: OFF F", 0, 120, 1);
          }
          if (do3_value.toInt() == 1) {
            M5.Lcd.drawString("3: ON F", 0, 120, 1);
          }
        }
      } else {
        if (do3_value.toInt() == 0) {
          M5.Lcd.drawString("3: OFF", 0, 120, 1);
        }
        if (do3_value.toInt() == 1) {
          M5.Lcd.drawString("3: ON", 0, 120, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 4) {
      if (do4CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (do4_fail_default == 0) {
          M5.Lcd.drawString("4: OFF F", 0, 160, 1);
        }
        if (do4_fail_default == 1) {
          M5.Lcd.drawString("4: ON F", 0, 160, 1);
        }
        if (do4_fail_default == 2) {
          if (do4_value.toInt() == 0) {
            M5.Lcd.drawString("4: OFF F", 0, 160, 1);
          }
          if (do4_value.toInt() == 1) {
            M5.Lcd.drawString("4: ON F", 0, 160, 1);
          }
        }
      } else {
        if (do4_value.toInt() == 0) {
          M5.Lcd.drawString("4: OFF", 0, 160, 1);
        }
        if (do4_value.toInt() == 1) {
          M5.Lcd.drawString("4: ON", 0, 160, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 5) {
      if (do5CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (do5_fail_default == 0) {
          M5.Lcd.drawString("5: OFF F", 170, 40, 1);
        }
        if (do5_fail_default == 1) {
          M5.Lcd.drawString("5: ON F", 170, 40, 1);
        }
        if (do5_fail_default == 2) {
          if (do5_value.toInt() == 0) {
            M5.Lcd.drawString("5: OFF F", 170, 40, 1);
          }
          if (do5_value.toInt() == 1) {
            M5.Lcd.drawString("5: ON F", 170, 40, 1);
          }
        }
      } else {
        if (do5_value.toInt() == 0) {
          M5.Lcd.drawString("5: OFF", 170, 40, 1);
        }
        if (do5_value.toInt() == 1) {
          M5.Lcd.drawString("5: ON", 170, 40, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 6) {
      if (do6CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (do6_fail_default == 0) {
          M5.Lcd.drawString("6: OFF F", 170, 80, 1);
        }
        if (do6_fail_default == 1) {
          M5.Lcd.drawString("6: ON F", 170, 80, 1);
        }
        if (do6_fail_default == 2) {
          if (do6_value.toInt() == 0) {
            M5.Lcd.drawString("6: OFF F", 170, 80, 1);
          }
          if (do6_value.toInt() == 1) {
            M5.Lcd.drawString("6: ON F", 170, 80, 1);
          }
        }
      } else {
        if (do6_value.toInt() == 0) {
          M5.Lcd.drawString("6: OFF", 170, 80, 1);
        }
        if (do6_value.toInt() == 1) {
          M5.Lcd.drawString("6: ON", 170, 80, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 7) {
      if (do7CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (do7_fail_default == 0) {
          M5.Lcd.drawString("7: OFF F", 170, 120, 1);
        }
        if (do7_fail_default == 1) {
          M5.Lcd.drawString("7: ON F", 170, 120, 1);
        }
        if (do7_fail_default == 2) {
          if (do7_value.toInt() == 0) {
            M5.Lcd.drawString("7: OFF F", 170, 120, 1);
          }
          if (do7_value.toInt() == 1) {
            M5.Lcd.drawString("7: ON F", 170, 120, 1);
          }
        }
      } else {
        if (do7_value.toInt() == 0) {
          M5.Lcd.drawString("7: OFF", 170, 120, 1);
        }
        if (do7_value.toInt() == 1) {
          M5.Lcd.drawString("7: ON", 170, 120, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 8) {
      if (do8CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (do8_fail_default == 0) {
          M5.Lcd.drawString("8: OFF F", 170, 160, 1);
        }
        if (do8_fail_default == 1) {
          M5.Lcd.drawString("8: ON F", 170, 160, 1);
        }
        if (do8_fail_default == 2) {
          if (do8_value.toInt() == 0) {
            M5.Lcd.drawString("8: OFF F", 170, 160, 1);
          }
          if (do8_value.toInt() == 1) {
            M5.Lcd.drawString("8: ON F", 170, 160, 1);
          }
        }
      } else {
        if (do8_value.toInt() == 0) {
          M5.Lcd.drawString("8: OFF", 170, 160, 1);
        }
        if (do8_value.toInt() == 1) {
          M5.Lcd.drawString("8: ON", 170, 160, 1);
        }
      }
      M5.Lcd.setTextColor(WHITE);
    } 
  }
  if (cycleCounter == 2) {
    M5.Lcd.drawString("Analog In (mA)", 30, 0, 1);

    if (IONum.toInt() >= 1) {
      if (noHandshakeAnalogInputFeeds[0]) {
        M5.Lcd.setTextColor(BLUE);
        M5.Lcd.drawString("1:" + String(ai1_value.toFloat() / 1600.00, 2) + "D", 0, 40, 1);
      } else {
        M5.Lcd.drawString("1:" + String(ai1_value.toFloat() / 1600.00, 2), 0, 40, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 2) {
      if (noHandshakeAnalogInputFeeds[1]) {
        M5.Lcd.setTextColor(BLUE);
        M5.Lcd.drawString("2:" + String(ai2_value.toFloat() / 1600.00, 2) + "D", 0, 80, 1);
      } else {
        M5.Lcd.drawString("2:" + String(ai2_value.toFloat() / 1600.00, 2), 0, 80, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 3) {
      if (noHandshakeAnalogInputFeeds[2]) {
        M5.Lcd.setTextColor(BLUE);
        M5.Lcd.drawString("3:" + String(ai3_value.toFloat() / 1600.00, 2) + "D", 0, 120, 1);
      } else {
        M5.Lcd.drawString("3:" + String(ai3_value.toFloat() / 1600.00, 2), 0, 120, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 4) {
      if (noHandshakeAnalogInputFeeds[3]) {
        M5.Lcd.setTextColor(BLUE);
        M5.Lcd.drawString("4:" + String(ai4_value.toFloat() / 1600.00, 2) + "D", 0, 160, 1);
      } else {
        M5.Lcd.drawString("4:" + String(ai4_value.toFloat() / 1600.00, 2), 0, 160, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 5) {
      if (noHandshakeAnalogInputFeeds[4]) {
        M5.Lcd.setTextColor(BLUE);
        M5.Lcd.drawString("5:" + String(ai5_value.toFloat() / 1600.00, 2) + "D", 170, 40, 1);
      } else {
        M5.Lcd.drawString("5:" + String(ai5_value.toFloat() / 1600.00, 2), 170, 40, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 6) {
      if (noHandshakeAnalogInputFeeds[5]) {
        M5.Lcd.setTextColor(BLUE);
        M5.Lcd.drawString("6:" + String(ai6_value.toFloat() / 1600.00, 2) + "D", 170, 80, 1);
      } else {
        M5.Lcd.drawString("6:" + String(ai6_value.toFloat() / 1600.00, 2), 170, 80, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 7) {
      if (noHandshakeAnalogInputFeeds[6]) {
        M5.Lcd.setTextColor(BLUE);
        M5.Lcd.drawString("7:" + String(ai7_value.toFloat() / 1600.00, 2) + "D", 170, 120, 1);
      } else {
        M5.Lcd.drawString("7:" + String(ai7_value.toFloat() / 1600.00, 2), 170, 120, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }

    if (IONum.toInt() >= 8) {
      if (noHandshakeAnalogInputFeeds[7]) {
        M5.Lcd.setTextColor(BLUE);
        M5.Lcd.drawString("8:" + String(ai8_value.toFloat() / 1600.00, 2) + "D", 170, 160, 1);
      } else {
        M5.Lcd.drawString("8:" + String(ai8_value.toFloat() / 1600.00, 2), 170, 160, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }
  }
  if (cycleCounter == 3) {
    M5.Lcd.drawString("Analog Out (mA)", 25, 0, 1);
    
    if (IONum.toInt() >= 1) {
      if (ao1CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (ao1_fail_default != 30.0) {
          M5.Lcd.drawString("1:" + String(ao1_fail_default, 2) + "F", 0, 40, 1);
        } else {
          M5.Lcd.drawString("1:" + String(ao1_value.toFloat() / 3276.75, 2) + "F", 0, 40, 1);
        }
      } else {
        M5.Lcd.drawString("1:" + String(ao1_value.toFloat() / 3276.75, 2), 0, 40, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }
    
    if (IONum.toInt() >= 2) {
      if (ao2CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (ao2_fail_default != 30.0) {
          M5.Lcd.drawString("2:" + String(ao2_fail_default, 2) + "F", 0, 80, 1);
        } else {
          M5.Lcd.drawString("2:" + String(ao2_value.toFloat() / 3276.75, 2) + "F", 0, 80, 1);
        }
      } else {
        M5.Lcd.drawString("2:" + String(ao2_value.toFloat() / 3276.75, 2), 0, 80, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }
    
    if (IONum.toInt() >= 3) {
      if (ao3CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (ao3_fail_default != 30.0) {
          M5.Lcd.drawString("3:" + String(ao3_fail_default, 2) + "F", 0, 120, 1);
        } else {
          M5.Lcd.drawString("3:" + String(ao3_value.toFloat() / 3276.75, 2) + "F", 0, 120, 1);
        }
      } else {
        M5.Lcd.drawString("3:" + String(ao3_value.toFloat() / 3276.75, 2), 0, 120, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }
    
    if (IONum.toInt() >= 4) {
      if (ao4CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (ao4_fail_default != 30.0) {
          M5.Lcd.drawString("4:" + String(ao4_fail_default, 2) + "F", 0, 160, 1);
        } else {
          M5.Lcd.drawString("4:" + String(ao4_value.toFloat() / 3276.75, 2) + "F", 0, 160, 1);
        }
      } else {
        M5.Lcd.drawString("4:" + String(ao4_value.toFloat() / 3276.75, 2), 0, 160, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }
    
    if (IONum.toInt() >= 5) {
      if (ao5CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (ao5_fail_default != 30.0) {
          M5.Lcd.drawString("5:" + String(ao5_fail_default, 2) + "F", 170, 40, 1);
        } else {
          M5.Lcd.drawString("5:" + String(ao5_value.toFloat() / 3276.75, 2) + "F", 170, 40, 1);
        }
      } else {
        M5.Lcd.drawString("5:" + String(ao5_value.toFloat() / 3276.75, 2), 170, 40, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }
    
    if (IONum.toInt() >= 6) {
      if (ao6CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (ao6_fail_default != 30.0) {
          M5.Lcd.drawString("6:" + String(ao6_fail_default, 2) + "F", 170, 80, 1);
        } else {
          M5.Lcd.drawString("6:" + String(ao6_value.toFloat() / 3276.75, 2) + "F", 170, 80, 1);
        }
      } else {
        M5.Lcd.drawString("6:" + String(ao6_value.toFloat() / 3276.75, 2), 170, 80, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }
    
    if (IONum.toInt() >= 7) {
      if (ao7CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (ao7_fail_default != 30.0) {
          M5.Lcd.drawString("7:" + String(ao7_fail_default, 2) + "F", 170, 120, 1);
        } else {
          M5.Lcd.drawString("7:" + String(ao7_value.toFloat() / 3276.75, 2) + "F", 170, 120, 1);
        }
      } else {
        M5.Lcd.drawString("7:" + String(ao7_value.toFloat() / 3276.75, 2), 170, 120, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }
    
    if (IONum.toInt() >= 8) {
      if (ao8CommFailTriggered) {
        M5.Lcd.setTextColor(RED);
        if (ao8_fail_default != 30.0) {
          M5.Lcd.drawString("8:" + String(ao8_fail_default, 2) + "F", 170, 160, 1);
        } else {
          M5.Lcd.drawString("8:" + String(ao8_value.toFloat() / 3276.75, 2) + "F", 170, 160, 1);
        }
      } else {
        M5.Lcd.drawString("8:" + String(ao8_value.toFloat() / 3276.75, 2), 170, 160, 1);
      }
      M5.Lcd.setTextColor(WHITE);
    }
  }

  if (!cyclingPaused) {
    cycleCounter++;
    signalCounter++;
    if (cycleCounter >= 4) {
      cycleCounter = 0;
    }
    if (signalCounter >= numberOfRemoteUnits) {
      signalCounter = 0;
    }
  }
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
  M5.Lcd.drawString("ESC", 240, 210, 1);
  M5.Lcd.drawString(versionNumber, 5, 210, 1);
}