#include "M5StackRadio.h"

void replaceText(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int textSize, String text) {
  M5.Lcd.fillRect(x, y, width, height, BLACK);
  M5.Lcd.drawString(text, x, y, textSize);
}

void displayCellularSignalQuality() {
  int bars = calculateCellularSignalQualityBars(signalStrengthString.toInt());

  M5.Lcd.fillRect(10, 200, 90, 40, BLACK);
  for (int i = 0; i < bars; i++) {
    M5.Lcd.fillRect(20 + (i * 12), 220 - (i * 2), 10, 10 + (i * 2), GREEN);
  }
}


void displayDI1() {
  M5.Lcd.fillRect(0, 40, 160, 35, BLACK);
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

void displayDI2() {
  M5.Lcd.fillRect(0, 80, 160, 35, BLACK);
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

void displayDI3() {
  M5.Lcd.fillRect(0, 120, 160, 35, BLACK);
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

void displayDI4() {
  M5.Lcd.fillRect(0, 160, 160, 35, BLACK);
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

void displayDI5() {
  M5.Lcd.fillRect(170, 40, 160, 35, BLACK);
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

void displayDI6() {
  M5.Lcd.fillRect(170, 80, 160, 35, BLACK);
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

void displayDI7() {
  M5.Lcd.fillRect(170, 120, 160, 35, BLACK);
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

void displayDI8() {
  M5.Lcd.fillRect(170, 160, 160, 35, BLACK);
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


void displayDO1() {
  M5.Lcd.fillRect(0, 40, 160, 35, BLACK);
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

void displayDO2() {
  M5.Lcd.fillRect(0, 80, 160, 35, BLACK);
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

void displayDO3() {
  M5.Lcd.fillRect(0, 120, 160, 35, BLACK);
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

void displayDO4() {
  M5.Lcd.fillRect(0, 160, 160, 35, BLACK);
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

void displayDO5() {
  M5.Lcd.fillRect(170, 40, 160, 35, BLACK);
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

void displayDO6() {
  M5.Lcd.fillRect(170, 80, 160, 35, BLACK);
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

void displayDO7() {
  M5.Lcd.fillRect(170, 120, 160, 35, BLACK);
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

void displayDO8() {
  M5.Lcd.fillRect(170, 160, 160, 35, BLACK);
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


void displayAI1() {
  M5.Lcd.fillRect(0, 40, 160, 35, BLACK);
  if (noHandshakeAnalogInputFeeds[0]) {
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.drawString("1:" + String(ai1_value.toFloat() / 1600.00, 2) + "D", 0, 40, 1);
  } else {
    M5.Lcd.drawString("1:" + String(ai1_value.toFloat() / 1600.00, 2), 0, 40, 1);
  }
  M5.Lcd.setTextColor(WHITE);
}

void displayAI2() {
  M5.Lcd.fillRect(0, 80, 160, 35, BLACK);
  if (noHandshakeAnalogInputFeeds[1]) {
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.drawString("2:" + String(ai2_value.toFloat() / 1600.00, 2) + "D", 0, 80, 1);
  } else {
    M5.Lcd.drawString("2:" + String(ai2_value.toFloat() / 1600.00, 2), 0, 80, 1);
  }
  M5.Lcd.setTextColor(WHITE);
}

void displayAI3() {
  M5.Lcd.fillRect(0, 120, 160, 35, BLACK);
  if (noHandshakeAnalogInputFeeds[2]) {
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.drawString("3:" + String(ai3_value.toFloat() / 1600.00, 2) + "D", 0, 120, 1);
  } else {
    M5.Lcd.drawString("3:" + String(ai3_value.toFloat() / 1600.00, 2), 0, 120, 1);
  }
  M5.Lcd.setTextColor(WHITE);
}

void displayAI4() {
  M5.Lcd.fillRect(0, 160, 160, 35, BLACK);
  if (noHandshakeAnalogInputFeeds[3]) {
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.drawString("4:" + String(ai4_value.toFloat() / 1600.00, 2) + "D", 0, 160, 1);
  } else {
    M5.Lcd.drawString("4:" + String(ai4_value.toFloat() / 1600.00, 2), 0, 160, 1);
  }
  M5.Lcd.setTextColor(WHITE);
}

void displayAI5() {
  M5.Lcd.fillRect(170, 40, 160, 35, BLACK);
  if (noHandshakeAnalogInputFeeds[4]) {
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.drawString("5:" + String(ai5_value.toFloat() / 1600.00, 2) + "D", 170, 40, 1);
  } else {
    M5.Lcd.drawString("5:" + String(ai5_value.toFloat() / 1600.00, 2), 170, 40, 1);
  }
  M5.Lcd.setTextColor(WHITE);
}

void displayAI6() {
  M5.Lcd.fillRect(170, 80, 160, 35, BLACK);
  if (noHandshakeAnalogInputFeeds[5]) {
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.drawString("6:" + String(ai6_value.toFloat() / 1600.00, 2) + "D", 170, 80, 1);
  } else {
    M5.Lcd.drawString("6:" + String(ai6_value.toFloat() / 1600.00, 2), 170, 80, 1);
  }
  M5.Lcd.setTextColor(WHITE);
}

void displayAI7() {
  M5.Lcd.fillRect(170, 120, 160, 35, BLACK);
  if (noHandshakeAnalogInputFeeds[6]) {
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.drawString("7:" + String(ai7_value.toFloat() / 1600.00, 2) + "D", 170, 120, 1);
  } else {
    M5.Lcd.drawString("7:" + String(ai7_value.toFloat() / 1600.00, 2), 170, 120, 1);
  }
  M5.Lcd.setTextColor(WHITE);
}

void displayAI8() {
  M5.Lcd.fillRect(170, 160, 160, 35, BLACK);
  if (noHandshakeAnalogInputFeeds[7]) {
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.drawString("8:" + String(ai8_value.toFloat() / 1600.00, 2) + "D", 170, 160, 1);
  } else {
    M5.Lcd.drawString("8:" + String(ai8_value.toFloat() / 1600.00, 2), 170, 160, 1);
  }
  M5.Lcd.setTextColor(WHITE);
}


void displayAO1() {
  M5.Lcd.fillRect(0, 40, 160, 35, BLACK);
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

void displayAO2() {
  M5.Lcd.fillRect(0, 80, 160, 35, BLACK);
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

void displayAO3() {
  M5.Lcd.fillRect(0, 120, 160, 35, BLACK);
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

void displayAO4() {
  M5.Lcd.fillRect(0, 160, 160, 35, BLACK);
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

void displayAO5() {
  M5.Lcd.fillRect(170, 40, 160, 35, BLACK);
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

void displayAO6() {
  M5.Lcd.fillRect(170, 80, 160, 35, BLACK);
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

void displayAO7() {
  M5.Lcd.fillRect(170, 120, 160, 35, BLACK);
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

void displayAO8() {
  M5.Lcd.fillRect(170, 160, 160, 35, BLACK);
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