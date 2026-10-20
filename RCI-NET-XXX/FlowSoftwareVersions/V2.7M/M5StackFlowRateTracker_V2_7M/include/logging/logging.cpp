#include "M5StackMQTTFTP.h"

File logFile;

void openLogFile() {
    updateLocalTime();
    if (sdStorageSuccess) {
        logFile = SD.open(logFileName.c_str(), FILE_APPEND, true);
    } else {
        logFile = LittleFS.open(logFileName.c_str(), FILE_APPEND, true);
    }
}

void openDataLogFile() {
    updateLocalTime();
    if (sdStorageSuccess) {
        logFile = SD.open(dataLogFileName.c_str(), FILE_APPEND, true);
    } else {
        logFile = LittleFS.open(dataLogFileName.c_str(), FILE_APPEND, true);
    }
}

void closeLogFile() {
    logFile.close();
}

void initializeLogFile() {
    /*
    preferences.begin(pnamespace);
    preferences.putULong64(totalFlowKey, totalFlow);
    preferences.end();
    */

    if ((!SD.exists(logFileName.c_str()) && sdStorageSuccess) || (!LittleFS.exists(logFileName.c_str()) && littlefsStorageSuccess && !sdStorageSuccess)) {
        openLogFile();
        logFile.println("Timestamp, Event, Extra Information");
        closeLogFile();
        logEnabledEvent();
    }

    if ((!SD.exists(dataLogFileName.c_str()) && sdStorageSuccess) || (!LittleFS.exists(dataLogFileName.c_str()) && littlefsStorageSuccess && !sdStorageSuccess)) {
        openDataLogFile();
        logFile.println("Timestamp, Input/Output, Value");
        closeLogFile();
        //logAllIOEvent();
        logFlowRateEvent();
    }
}

void logPowerOnEvent(String reason) {
    if (loggingEnabled) {
        openLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", POWER_ON | " + reason + ", " +
                    "FW=" + versionNumber + ", LOG_EN=" + loggingEnabled + ", SD_EN=" + sdEnabled + ", AI_CHAN=" + (flowRateMinutesAITerminal + 1) +
                    ", GID=" + groupID + ", " + "UID=" + unitID + ", " + "IONUM=" + IONum + ", " + "UPTIME_MS=" + updateTime + ", " + "UNAME=" + consumerName + ", " +
                    "DO1=" + do1_feed + ", " + "DO2=" + do2_feed + ", " + "DO3=" + do3_feed + ", " + "DO4=" + do4_feed + ", " + "DO5=" + do5_feed + ", " + "DO6=" + do6_feed + ", " + "DO7=" + do7_feed + ", " + "DO8=" + do8_feed + ", " +
                    "AO1=" + ao1_feed + ", " + "AO2=" + ao2_feed + ", " + "AO3=" + ao3_feed + ", " + "AO4=" + ao4_feed + ", " + "AO5=" + ao5_feed + ", " + "AO6=" + ao6_feed + ", " + "AO7=" + ao7_feed + ", " + "AO8=" + ao8_feed + ", " +
                    "DF1=" + df1ReadValue + ", " + "DF2=" + df2ReadValue + ", " + "DF3=" + df3ReadValue + ", " + "DF4=" + df4ReadValue + ", " + "DF5=" + df5ReadValue + ", " + "DF6=" + df6ReadValue + ", " + "DF7=" + df7ReadValue + ", " + "DF8=" + df8ReadValue + ", " +
                    "AF1=" + af1ReadValue + ", " + "AF2=" + af2ReadValue + ", " + "AF3=" + af3ReadValue + ", " + "AF4=" + af4ReadValue + ", " + "AF5=" + af5ReadValue + ", " + "AF6=" + af6ReadValue + ", " + "AF7=" + af7ReadValue + ", " + "AF8=" + af8ReadValue + ", " +
                    "HB=" + heartbeatSubscriptionsString;
        logFile.println(event);
        closeLogFile();
    }
}

void logForcedResetEvent(String reason) {
    if (loggingEnabled) {
        openLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", FORCED_RESET, " +
                    reason;
        logFile.println(event);
        closeLogFile();
    }
}

void logConnectEvent() {
    if (loggingEnabled) {
        openLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", MQTT_CONNECTED, " +
                    mqttBrokerProvider + "_OK";
        logFile.println(event);
        closeLogFile();
    }
}

void logDisconnectEvent(bool noInternet) {
    if (loggingEnabled) {
        openLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", MQTT_DISCONNECTED, ";
        if (noInternet) {
            event += "NO_INTERNET_CONNECTION";
        } else {
            event += "ETHERNET_INITIALIZATION_ISSUE";
        }
        logFile.println(event);
        closeLogFile();
    }
}

void logMQTTConnectionErrorEvent(int mqttClientErrorCode) {
    if (loggingEnabled) {
        openLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", MQTT_CONNECTION_ERROR, " +
                    "ERROR_CODE=" + String(mqttClientErrorCode);
        logFile.println(event);
        closeLogFile();
    }
}

void logFTPEvent(String extraInformation) {
    if (loggingEnabled) {
        openLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", FTP_CONNECTED, " +
                    extraInformation;
        logFile.println(event);
        closeLogFile();
    }
}

void logEnterFailEvent(String unitIDLost) {
    if (loggingEnabled) {
        openLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", COMMFAIL_ACTIVE, " + "LOST_UNIT_" + unitIDLost +
                    ", DF1=" + do1_value + ", " + "DF2=" + do2_value + ", " + "DF3=" + do3_value + ", " + "DF4=" + do4_value + ", " + "DF5=" + do5_value + ", " + "DF6=" + do6_value + ", " + "DF7=" + do7_value + ", " + "DF8=" + do8_value + ", " +
                    "AF1=" + String(ao1_value.toFloat() / 3276.75, 2) + ", " + "AF2=" + String(ao2_value.toFloat() / 3276.75, 2) + ", " + "AF3=" + String(ao3_value.toFloat() / 3276.75, 2) + ", " + "AF4=" + String(ao4_value.toFloat() / 3276.75, 2) + ", " +
                    "AF5=" + String(ao5_value.toFloat() / 3276.75, 2) + ", " + "AF6=" + String(ao6_value.toFloat() / 3276.75, 2) + ", " + "AF7=" + String(ao7_value.toFloat() / 3276.75, 2) + ", " + "AF8=" + String(ao8_value.toFloat() / 3276.75, 2);
        logFile.println(event);
        closeLogFile();
    }
}

void logExitFailEvent(String unitIDFound) {
    if (loggingEnabled) {
        openLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", COMMFAIL_EXIT, " +
                    "FOUND_UNIT_" + unitIDFound;
        logFile.println(event);
        closeLogFile();
    }
}

void logSignalQualityEvent() {
    if (loggingEnabled) {
        openLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", SIGNAL_CHECK, RSSI=" +
                    signalStrengthString + ", SQ=" + signalQualityString;
        logFile.println(event);
        closeLogFile();
    }
}

void logFlowResetEvent(unsigned long long flowResetValue) {
    if (loggingEnabled) {
        openLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", FLOW_RESET, " +
                    String(flowResetValue) + " KGAL";
        logFile.println(event);
        closeLogFile();
    }
}

void logDeleteEvent(String deletedLog) {
    if (loggingEnabled) {
        openLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", REQUESTED_LOG_DELETE, " +
                    deletedLog;
        logFile.println(event);
        closeLogFile();
    }
}

void logEnabledEvent() {
    openLogFile();
    String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", DATA_LOGGING_STATUS, ";
    if (loggingEnabled) {
        event += "ENABLED";
    } else {
        event += "DISABLED";
    }
    logFile.println(event);
    closeLogFile();
}

void logSDEnabledEvent() {
    openLogFile();
    String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", SD_ENABLED_STATUS, ";
    if (sdEnabled) {
        event += "ENABLED";
    } else {
        event += "DISABLED";
    }
    logFile.println(event);
    closeLogFile();
}

void logDataUploadTimestamp() {
    if (loggingEnabled) {
        openDataLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", FTP_CONNECTED, " +
                    String("LOG_UPLOAD_TIMESTAMP");
        logFile.println(event);
        closeLogFile();
    }
}

void logSingleIOEvent(String ioTerminal, String ioValue) {
    if (loggingEnabled) {
        openDataLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", " +
                    ioTerminal + ", " + ioValue;
        logFile.println(event);
        closeLogFile();
    }
}

void logAllIOEvent() {
    switch (IONum.toInt()) {
        case 8:
            logSingleIOEvent("DI8", di8_value);
            logSingleIOEvent("AI8", String(ai8_value.toFloat() / 1600.00, 2));
            logSingleIOEvent("DO8", do8_value);
            logSingleIOEvent("AO8", String(ao8_value.toFloat() / 3276.75, 2));

        case 7:
            logSingleIOEvent("DI7", di7_value);
            logSingleIOEvent("AI7", String(ai7_value.toFloat() / 1600.00, 2));
            logSingleIOEvent("DO7", do7_value);
            logSingleIOEvent("AO7", String(ao7_value.toFloat() / 3276.75, 2));
        
        case 6:
            logSingleIOEvent("DI6", di6_value);
            logSingleIOEvent("AI6", String(ai6_value.toFloat() / 1600.00, 2));
            logSingleIOEvent("DO6", do6_value);
            logSingleIOEvent("AO6", String(ao6_value.toFloat() / 3276.75, 2));
        
        case 5:
            logSingleIOEvent("DI5", di5_value);
            logSingleIOEvent("AI5", String(ai5_value.toFloat() / 1600.00, 2));
            logSingleIOEvent("DO5", do5_value);
            logSingleIOEvent("AO5", String(ao5_value.toFloat() / 3276.75, 2));
        
        case 4:
            logSingleIOEvent("DI4", di4_value);
            logSingleIOEvent("AI4", String(ai4_value.toFloat() / 1600.00, 2));
            logSingleIOEvent("DO4", do4_value);
            logSingleIOEvent("AO4", String(ao4_value.toFloat() / 3276.75, 2));
        
        case 3:
            logSingleIOEvent("DI3", di3_value);
            logSingleIOEvent("AI3", String(ai3_value.toFloat() / 1600.00, 2));
            logSingleIOEvent("DO3", do3_value);
            logSingleIOEvent("AO3", String(ao3_value.toFloat() / 3276.75, 2));
        
        case 2:
            logSingleIOEvent("DI2", di2_value);
            logSingleIOEvent("AI2", String(ai2_value.toFloat() / 1600.00, 2));
            logSingleIOEvent("DO2", do2_value);
            logSingleIOEvent("AO2", String(ao2_value.toFloat() / 3276.75, 2));
        
        case 1:
            logSingleIOEvent("DI1", di1_value);
            logSingleIOEvent("AI1", String(ai1_value.toFloat() / 1600.00, 2));
            logSingleIOEvent("DO1", do1_value);
            logSingleIOEvent("AO1", String(ao1_value.toFloat() / 3276.75, 2));

        default:
            break;
    }
}

void logFlowRateEvent() {
    logSingleIOEvent(String("AI") + String(flowRateMinutesAITerminal + 1) + String(" READ (mA)"), String((flowRateRawAI) / (1601.0), 2U));
    logSingleIOEvent("FLOW RATE (GAL/MIN)", String(flowRateMinutes, 0U));
    logSingleIOEvent("TOTAL FLOW (GALS)", String(totalFlow));
}

double getTotalLoggingMemory() {
    myFile = LittleFS.open(logFileName.c_str());
    double systemLogSize = myFile.size() / 1048576.0;
    myFile.close();

    myFile = LittleFS.open(dataLogFileName.c_str());
    double dataLogSize = myFile.size() / 1048576.0;
    myFile.close();

    return systemLogSize + dataLogSize;
}