#include "M5StackMQTTFTP.h"

bool newDI1Available() {
    return pcfr0Prev != int(pcfr.digitalRead(0));
}

bool newDI2Available() {
    return pcfr1Prev != int(pcfr.digitalRead(1));
}

bool newDI3Available() {
    return pcfr2Prev != int(pcfr.digitalRead(2));
}

bool newDI4Available() {
    return pcfr3Prev != int(pcfr.digitalRead(3));
}

bool newDI5Available() {
    return pcfr4Prev != int(pcfr.digitalRead(4));
}

bool newDI6Available() {
    return pcfr5Prev != int(pcfr.digitalRead(5));
}

bool newDI7Available() {
    return pcfr6Prev != int(pcfr.digitalRead(6));
}

bool newDI8Available() {
    return pcfr7Prev != int(pcfr.digitalRead(7));
}


bool newDO1Available(String doUpdateValue) {
    return !do1_value.equalsIgnoreCase(doUpdateValue);
}

bool newDO2Available(String doUpdateValue) {
    return !do2_value.equalsIgnoreCase(doUpdateValue);
}

bool newDO3Available(String doUpdateValue) {
    return !do3_value.equalsIgnoreCase(doUpdateValue);
}

bool newDO4Available(String doUpdateValue) {
    return !do4_value.equalsIgnoreCase(doUpdateValue);
}

bool newDO5Available(String doUpdateValue) {
    return !do5_value.equalsIgnoreCase(doUpdateValue);
}

bool newDO6Available(String doUpdateValue) {
    return !do6_value.equalsIgnoreCase(doUpdateValue);
}

bool newDO7Available(String doUpdateValue) {
    return !do7_value.equalsIgnoreCase(doUpdateValue);
}

bool newDO8Available(String doUpdateValue) {
    return !do8_value.equalsIgnoreCase(doUpdateValue);
}


bool newAI1Available() {
    return (adc0Prev + 100) < ads1115.readADC_SingleEnded(0) || (adc0Prev - 100) > ads1115.readADC_SingleEnded(0);
}

bool newAI2Available() {
    return (adc1Prev + 100) < ads1115.readADC_SingleEnded(1) || (adc1Prev - 100) > ads1115.readADC_SingleEnded(1);
}

bool newAI3Available() {
    return (adc2Prev + 100) < ads1115.readADC_SingleEnded(2) || (adc2Prev - 100) > ads1115.readADC_SingleEnded(2);
}

bool newAI4Available() {
    return (adc3Prev + 100) < ads1115.readADC_SingleEnded(3) || (adc3Prev - 100) > ads1115.readADC_SingleEnded(3);
}

bool newAI5Available() {
    return (adc0secondPrev + 100) < ads1115second.readADC_SingleEnded(0) || (adc0secondPrev - 100) > ads1115second.readADC_SingleEnded(0);
}

bool newAI6Available() {
    return (adc1secondPrev + 100) < ads1115second.readADC_SingleEnded(1) || (adc1secondPrev - 100) > ads1115second.readADC_SingleEnded(1);
}

bool newAI7Available() {
    return (adc2secondPrev + 100) < ads1115second.readADC_SingleEnded(2) || (adc2secondPrev - 100) > ads1115second.readADC_SingleEnded(2);
}

bool newAI8Available() {
    return (adc3secondPrev + 100) < ads1115second.readADC_SingleEnded(3) || (adc3secondPrev - 100) > ads1115second.readADC_SingleEnded(3);
}


bool newAO1Available(String aoUpdateValue) {
    return !ao1_value.equalsIgnoreCase(aoUpdateValue);
}

bool newAO2Available(String aoUpdateValue) {
    return !ao2_value.equalsIgnoreCase(aoUpdateValue);
}

bool newAO3Available(String aoUpdateValue) {
    return !ao3_value.equalsIgnoreCase(aoUpdateValue);
}

bool newAO4Available(String aoUpdateValue) {
    return !ao4_value.equalsIgnoreCase(aoUpdateValue);
}

bool newAO5Available(String aoUpdateValue) {
    return !ao5_value.equalsIgnoreCase(aoUpdateValue);
}

bool newAO6Available(String aoUpdateValue) {
    return !ao6_value.equalsIgnoreCase(aoUpdateValue);
}

bool newAO7Available(String aoUpdateValue) {
    return !ao7_value.equalsIgnoreCase(aoUpdateValue);
}

bool newAO8Available(String aoUpdateValue) {
    return !ao8_value.equalsIgnoreCase(aoUpdateValue);
}


void updateDI1() {
    pcfr0Prev = int(pcfr.digitalRead(0));
    di1_value = String(pcfr0Prev);
}

void updateDI2() {
    pcfr1Prev = int(pcfr.digitalRead(1));
    di2_value = String(pcfr1Prev);
}

void updateDI3() {
    pcfr2Prev = int(pcfr.digitalRead(2));
    di3_value = String(pcfr2Prev);
}

void updateDI4() {
    pcfr3Prev = int(pcfr.digitalRead(3));
    di4_value = String(pcfr3Prev);
}

void updateDI5() {
    pcfr4Prev = int(pcfr.digitalRead(4));
    di5_value = String(pcfr4Prev);
}

void updateDI6() {
    pcfr5Prev = int(pcfr.digitalRead(5));
    di6_value = String(pcfr5Prev);
}

void updateDI7() {
    pcfr6Prev = int(pcfr.digitalRead(6));
    di7_value = String(pcfr6Prev);
}

void updateDI8() {
    pcfr7Prev = int(pcfr.digitalRead(7));
    di8_value = String(pcfr7Prev);
}


void updateDO1(String doUpdateValue) {
    do1_value = doUpdateValue;
}

void updateDO2(String doUpdateValue) {
    do2_value = doUpdateValue;
}

void updateDO3(String doUpdateValue) {
    do3_value = doUpdateValue;
}

void updateDO4(String doUpdateValue) {
    do4_value = doUpdateValue;
}

void updateDO5(String doUpdateValue) {
    do5_value = doUpdateValue;
}

void updateDO6(String doUpdateValue) {
    do6_value = doUpdateValue;
}

void updateDO7(String doUpdateValue) {
    do7_value = doUpdateValue;
}

void updateDO8(String doUpdateValue) {
    do8_value = doUpdateValue;
}


void updateAI1() {
    adc0 = ads1115.readADC_SingleEnded(0);
    adc0Prev = adc0;
    ai1_value = String(adc0);
    if (ai1_value.toInt() < 0) {
        ai1_value = "0";
    }
}

void updateAI2() {
    adc1 = ads1115.readADC_SingleEnded(1);
    adc1Prev = adc1;
    ai2_value = String(adc1);
    if (ai2_value.toInt() < 0) {
        ai2_value = "0";
    }
}

void updateAI3() {
    adc2 = ads1115.readADC_SingleEnded(2);
    adc2Prev = adc2;
    ai3_value = String(adc2);
    if (ai3_value.toInt() < 0) {
        ai3_value = "0";
    }
}

void updateAI4() {
    adc3 = ads1115.readADC_SingleEnded(3);
    adc3Prev = adc3;
    ai4_value = String(adc3);
    if (ai4_value.toInt() < 0) {
        ai4_value = "0";
    }
}

void updateAI5() {
    adc0second = ads1115second.readADC_SingleEnded(0);
    adc0secondPrev = adc0second;
    ai5_value = String(adc0second);
    if (ai5_value.toInt() < 0) {
        ai5_value = "0";
    }
}

void updateAI6() {
    adc1second = ads1115second.readADC_SingleEnded(1);
    adc1secondPrev = adc1second;
    ai6_value = String(adc1second);
    if (ai6_value.toInt() < 0) {
        ai6_value = "0";
    }
}

void updateAI7() {
    adc2second = ads1115second.readADC_SingleEnded(2);
    adc2secondPrev = adc2second;
    ai7_value = String(adc2second);
    if (ai7_value.toInt() < 0) {
        ai7_value = "0";
    }
}

void updateAI8() {
    adc3second = ads1115second.readADC_SingleEnded(3);
    adc3secondPrev = adc3second;
    ai8_value = String(adc3second);
    if (ai8_value.toInt() < 0) {
        ai8_value = "0";
    }
}


void updateAO1(String aoUpdateValue) {
    ao1_value = aoUpdateValue;
}

void updateAO2(String aoUpdateValue) {
    ao2_value = aoUpdateValue;
}

void updateAO3(String aoUpdateValue) {
    ao3_value = aoUpdateValue;
}

void updateAO4(String aoUpdateValue) {
    ao4_value = aoUpdateValue;
}

void updateAO5(String aoUpdateValue) {
    ao5_value = aoUpdateValue;
}

void updateAO6(String aoUpdateValue) {
    ao6_value = aoUpdateValue;
}

void updateAO7(String aoUpdateValue) {
    ao7_value = aoUpdateValue;
}

void updateAO8(String aoUpdateValue) {
    ao8_value = aoUpdateValue;
}