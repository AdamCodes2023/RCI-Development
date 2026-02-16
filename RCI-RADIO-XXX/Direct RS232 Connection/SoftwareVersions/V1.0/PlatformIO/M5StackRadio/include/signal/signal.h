#include "M5StackRadio.h"

void requestCellularSignalQuality() {
  ;
}

void backgroundReceiveCellularSignalQuality(bool displayBars) {
  if (signalQualityCheckSuccessful && displayBars && (calculateCellularSignalQualityBars(signalStrengthString.toInt()) != calculateCellularSignalQualityBars(2/*previousSignalStrengthString.toInt()*/))) {
    displayCellularSignalQuality();
  }

  Serial.println("SSI: " + signalStrengthString + " dBm");
  Serial.println("SIGNAL QUALITY: " + signalQualityString);
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