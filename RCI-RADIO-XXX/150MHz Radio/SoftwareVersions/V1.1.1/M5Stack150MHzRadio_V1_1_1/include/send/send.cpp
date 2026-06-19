#include "M5StackRadio.h"

void publishDI1() {
  if (noHandshakeDigitalInputFeeds[0]) {
    return;
  }

  pcfr0Prev = int(pcfr.digitalRead(0));
  payload = String(pcfr0Prev);
  di1_value = payload;

  sentRadioString += ("DI1=" + payload + ";");
}

void publishDI2() {
  if (noHandshakeDigitalInputFeeds[1]) {
    return;
  }

  pcfr1Prev = int(pcfr.digitalRead(1));
  payload = String(pcfr1Prev);
  di2_value = payload;

  sentRadioString += ("DI2=" + payload + ";");
}

void publishDI3() {
  if (noHandshakeDigitalInputFeeds[2]) {
    return;
  }

  pcfr2Prev = int(pcfr.digitalRead(2));
  payload = String(pcfr2Prev);
  di3_value = payload;

  sentRadioString += ("DI3=" + payload + ";");
}

void publishDI4() {
  if (noHandshakeDigitalInputFeeds[3]) {
    return;
  }

  pcfr3Prev = int(pcfr.digitalRead(3));
  payload = String(pcfr3Prev);
  di4_value = payload;

  sentRadioString += ("DI4=" + payload + ";");
}

void publishDI5() {
  if (noHandshakeDigitalInputFeeds[4]) {
    return;
  }

  pcfr4Prev = int(pcfr.digitalRead(4));
  payload = String(pcfr4Prev);
  di5_value = payload;

  sentRadioString += ("DI5=" + payload + ";");
}

void publishDI6() {
  if (noHandshakeDigitalInputFeeds[5]) {
    return;
  }

  pcfr5Prev = int(pcfr.digitalRead(5));
  payload = String(pcfr5Prev);
  di6_value = payload;

  sentRadioString += ("DI6=" + payload + ";");
}

void publishDI7() {
  if (noHandshakeDigitalInputFeeds[6]) {
    return;
  }

  pcfr6Prev = int(pcfr.digitalRead(6));
  payload = String(pcfr6Prev);
  di7_value = payload;

  sentRadioString += ("DI7=" + payload + ";");
}

void publishDI8() {
  if (noHandshakeDigitalInputFeeds[7]) {
    return;
  }

  pcfr7Prev = int(pcfr.digitalRead(7));
  payload = String(pcfr7Prev);
  di8_value = payload;

  sentRadioString += ("DI8=" + payload + ";");
}

void publishAI1() {
  if (noHandshakeAnalogInputFeeds[0]) {
    return;
  }

  adc0 = ads1115.readADC_SingleEnded(0);
  adc0Prev = adc0;
  payload = String(adc0);
  ai1_value = payload;
  if (ai1_value.toInt() < 0) {
    ai1_value = "0";
  }

  sentRadioString += ("AI1=" + payload + ";");
}

void publishAI2() {
  if (noHandshakeAnalogInputFeeds[1]) {
    return;
  }

  adc1 = ads1115.readADC_SingleEnded(1);
  adc1Prev = adc1;
  payload = String(adc1);
  ai2_value = payload;
  if (ai2_value.toInt() < 0) {
    ai2_value = "0";
  }

  sentRadioString += ("AI2=" + payload + ";");
}

void publishAI3() {
  if (noHandshakeAnalogInputFeeds[2]) {
    return;
  }

  adc2 = ads1115.readADC_SingleEnded(2);
  adc2Prev = adc2;
  payload = String(adc2);
  ai3_value = payload;
  if (ai3_value.toInt() < 0) {
    ai3_value = "0";
  }

  sentRadioString += ("AI3=" + payload + ";");
}

void publishAI4() {
  if (noHandshakeAnalogInputFeeds[3]) {
    return;
  }

  adc3 = ads1115.readADC_SingleEnded(3);
  adc3Prev = adc3;
  payload = String(adc3);
  ai4_value = payload;
  if (ai4_value.toInt() < 0) {
    ai4_value = "0";
  }

  sentRadioString += ("AI4=" + payload + ";");
}

void publishAI5() {
  if (noHandshakeAnalogInputFeeds[4]) {
    return;
  }

  adc0second = ads1115second.readADC_SingleEnded(0);
  adc0secondPrev = adc0second;
  payload = String(adc0second);
  ai5_value = payload;
  if (ai5_value.toInt() < 0) {
    ai5_value = "0";
  }

  sentRadioString += ("AI5=" + payload + ";");
}

void publishAI6() {
  if (noHandshakeAnalogInputFeeds[5]) {
    return;
  }

  adc1second = ads1115second.readADC_SingleEnded(1);
  adc1secondPrev = adc1second;
  payload = String(adc1second);
  ai6_value = payload;
  if (ai6_value.toInt() < 0) {
    ai6_value = "0";
  }

  sentRadioString += ("AI6=" + payload + ";");
}

void publishAI7() {
  if (noHandshakeAnalogInputFeeds[6]) {
    return;
  }

  adc2second = ads1115second.readADC_SingleEnded(2);
  adc2secondPrev = adc2second;
  payload = String(adc2second);
  ai7_value = payload;
  if (ai7_value.toInt() < 0) {
    ai7_value = "0";
  }

  sentRadioString += ("AI7=" + payload + ";");
}

void publishAI8() {
  if (noHandshakeAnalogInputFeeds[7]) {
    return;
  }

  adc3second = ads1115second.readADC_SingleEnded(3);
  adc3secondPrev = adc3second;
  payload = String(adc3second);
  ai8_value = payload;
  if (ai8_value.toInt() < 0) {
    ai8_value = "0";
  }

  sentRadioString += ("AI8=" + payload + ";");
}

void publishAll() {
  //replaceText(90, 210, 130, 50, 1, "PUB ALL!");
  //clearTextPreviousMillis = millis();
  //clear = true;

  // send message, the Print interface can be used to set the message contents
  // in this case we know the size ahead of time, so the message payload can be streamed
  if (IONum.toInt() >= 1) {
    if (digitalInputSuccess) {
      publishDI1();
    }

    if (analogInOneSuccess) {
      publishAI1();
    }
  }  

  if (IONum.toInt() >= 2) {
    if (digitalInputSuccess) {
      publishDI2();
    }

    if (analogInOneSuccess) {
      publishAI2();
    }
  }  

  if (IONum.toInt() >= 3) {
    if (digitalInputSuccess) {
      publishDI3();
    }

    if (analogInOneSuccess) {
      publishAI3();
    }
  }  

  if (IONum.toInt() >= 4) {
    if (digitalInputSuccess) {
      publishDI4();
    }

    if (analogInOneSuccess) {
      publishAI4();
    }
  }  

  if (IONum.toInt() >= 5) {
    if (digitalInputSuccess) {
      publishDI5();
    }

    if (analogInTwoSuccess) {
      publishAI5();
    }
  }  

  if (IONum.toInt() >= 6) {
    if (digitalInputSuccess) {
      publishDI6();
    }

    if (analogInTwoSuccess) {
      publishAI6();
    }
  }  

  if (IONum.toInt() >= 7) {
    if (digitalInputSuccess) {
      publishDI7();
    }

    if (analogInTwoSuccess) {
      publishAI7();
    }
  }  

  if (IONum.toInt() >= 8) {
    if (digitalInputSuccess) {
      publishDI8();
    }

    if (analogInTwoSuccess) {
      publishAI8();
    }
  }

  radioSerialRS232.write(sentRadioString.c_str());
  sentRadioString = groupID + "_" + unitID + "#";
}

void publishDataQuery(int targetUnitID) {
  String stringTargetUnitID = String(targetUnitID);
  if (targetUnitID >= 0 && targetUnitID <= 9) {
    stringTargetUnitID = String("0") + String(targetUnitID);
  }

  //replaceText(90, 210, 130, 50, 1, "QRY U" + stringTargetUnitID + "!");
  //clearTextPreviousMillis = millis();
  //clear = true;

  sentRadioString += (groupID + "_" + stringTargetUnitID + "?");
  radioSerialRS232.write(sentRadioString.c_str());
  sentRadioString = groupID + "_" + unitID + "#";
}

void publishSignalSend() {
  //replaceText(90, 210, 130, 50, 1, "S SIG!");
  //clearTextPreviousMillis = millis();
  //clear = true;

  sentRadioString += (groupID + "_" + unitID + "!");
  radioSerialRS232.write(sentRadioString.c_str());
  sentRadioString = groupID + "_" + unitID + "#";
}

void publishSignalQuery(int targetUnitID) {
  String stringTargetUnitID = String(targetUnitID);
  if (targetUnitID >= 0 && targetUnitID <= 9) {
    stringTargetUnitID = String("0") + String(targetUnitID);
  }

  //replaceText(90, 210, 130, 50, 1, "G SIG " + stringTargetUnitID + "!");
  //clearTextPreviousMillis = millis();
  //clear = true;

  sentRadioString += (groupID + "_" + stringTargetUnitID + "!");
  radioSerialRS232.write(sentRadioString.c_str());
  sentRadioString = groupID + "_" + unitID + "#";
}