#include "M5StackMQTTFTP.h"

File logFile;

void openLogFile() {
    updateLocalTime();
    logFile = SD.open(logFileName.c_str(), FILE_APPEND, true);
}

void closeLogFile() {
    logFile.close();
}

void initializeLogFile() {
    if (!SD.exists(logFileName.c_str())) {
        openLogFile();
        logFile.println("Timestamp, Event, Extra Information");
        closeLogFile();
        logEnabledEvent();
    }
}

void logPowerOnEvent() {
    if (loggingEnabled) {
        openLogFile();
        String event = String(timeinfo.tm_year) + "/" + String(timeinfo.tm_mon) + "/" + String(timeinfo.tm_mday) + "  " +
                    [&](){ char b[9]; snprintf(b, sizeof(b), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); return String(b); }() + ", POWER_ON, " +
                    "FW=" + versionNumber + ", LOG_EN=" + loggingEnabled +
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
                    MQTT_BROKER_PROVIDER + "_OK";
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
                    "AF1=" + ao1_value + ", " + "AF2=" + ao2_value + ", " + "AF3=" + ao3_value + ", " + "AF4=" + ao4_value + ", " + "AF5=" + ao5_value + ", " + "AF6=" + ao6_value + ", " + "AF7=" + ao7_value + ", " + "AF8=" + ao8_value;
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