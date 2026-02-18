#include "M5StackMQTTFTP.h"

void replaceText(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int textSize, String text) {
  M5.Lcd.fillRect(x, y, width, height, BLACK);
  M5.Lcd.drawString(text, x, y, textSize);
}