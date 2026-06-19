#include "M5StackRadio.h"

void replaceText(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int textSize, String text) {
  M5.Lcd.fillRect(x, y, width, height, BLACK);
  M5.Lcd.drawString(text, x, y, textSize);
}

void displayCellularSignalQuality() {
  int bars = calculateCellularSignalQualityBars(signalStrengthString.toInt());

  M5.Lcd.fillRect(58, 198, 64, 34, BLACK);
  for (int i = 0; i < bars; i++) {
    M5.Lcd.fillRect(60 + (i * 12), 220 - (i * 2), 10, 10 + (i * 2), GREEN);
  }
}