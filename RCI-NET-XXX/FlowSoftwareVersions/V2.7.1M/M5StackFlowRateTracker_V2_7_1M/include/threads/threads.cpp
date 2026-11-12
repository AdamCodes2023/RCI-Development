#include "M5StackMQTTFTP.h"

class FlowRateThread : public Thread {
    private:
        Adafruit_ADS1115 flowRateAIDevice; // ADS1115 device for flow rate measurement
        TimeStep* ts = nullptr; // Pointer to TimeStep object
        Integrator* integrator = nullptr; // Pointer to Integrator object

        const unsigned short flowRateUpdateInterval = sampleTime; // Update flow rate every 2000 milliseconds
        unsigned long long flowRateUpdateCurrentMillis = 0;
        unsigned long long flowRateUpdatePreviousMillis = 0;

        const unsigned short flowRateRecordInterval = 30000; // Record flow rate every 30 seconds
        unsigned long long flowRateRecordCurrentMillis = 0;
        unsigned long long flowRateRecordPreviousMillis = 0;

        void updateFlowRate() {
            // Calculate the flow rate based on the counter and sample time
            if (analogInOneSuccess) {
                flowRateRawAI = flowRateAIDevice.readADC_SingleEnded(flowRateMinutesAITerminal);
                flowRateMinutes = (flowRateRawAI - 6392.0);
            } else {
                flowRateRawAI = 0;
                flowRateMinutes = 0.0; // If the analog input is not successful, set the flow rate to 0.0
            }

            if (flowRateRawAI < 0) {
                flowRateRawAI = 0; // Ensure raw AI is not below the minimum (0 mA)
            }

            if (flowRateMinutes < 0.0) {
                flowRateMinutes = 0.0; // Ensure flow rate is not negative
            }
            if (flowRateMinutes > 25620.0) {
                flowRateRawAI = 32012;
                flowRateMinutes = 25620.0; // Ensure flow rate does not exceed maximum (20mA)
            }
            flowRateMinutes = (flowRateMinutes / 25620.0) * (3000.0); // Convert ADC reading to flow rate in gallons/min
            flowRateSeconds = flowRateMinutes / 60.0; // Convert flow rate to gallons/sec

            // Use the integrator to calculate the total flow
            totalFlow = integrator->step(flowRateSeconds);

            if (totalFlow < lastRecordedTotalFlow || totalFlow > (lastRecordedTotalFlow + 500)) {
                // If the total flow is less than the last recorded total flow or greater than the last recorded total flow + 500, reset the integrator
                newFlowSetpoint = lastRecordedTotalFlow / 1000; // Set the new flow setpoint to the last recorded total flow
                resetFlowIntegrator();
            } else {
                lastRecordedTotalFlow = totalFlow; // Update the last recorded total flow
            }

            /*
            // Print the flow rate and total flow for debugging
            Serial.print("Flow Rate: ");
            Serial.print(flowRateSeconds);
            Serial.print(" gallons/sec, Total Flow: ");
            Serial.print(totalFlow);
            Serial.println(" gallons");
            */
        }

        void recordFlowRate() {
            // Record the flow rate to LittleFS Storage.
            Serial.println("Recording flow rate to LittleFS Storage...");
            logFlowRateEvent();
        }

    protected:
        void OnInitialization() override {
            // Anything we need to do here prior to the Thread's Loop starting.
            if (analogInOneSuccess) {
                flowRateAIDevice.begin(0x48);
                flowRateAIDevice.setGain(GAIN_ONE);
            }

            ts = new TimeStep(dt); // Initialize TimeStep object
            integrator = new Integrator(*ts, totalFlow); // Initialize Integrator object
        }

        void OnLoop() override {
            if (updateFlowIntegrator) {
                updateFlowIntegrator = false;
                totalFlow = newFlowSetpoint * 1000;
                lastRecordedTotalFlow = totalFlow;
                integrator = new Integrator(*ts, totalFlow); // Reinitialize Integrator object
            }

            if (threadedFlowReset) {
                threadedFlowReset = false;
                flowRateMinutes = 0.0;
                totalFlow = 0;
                lastRecordedTotalFlow = 0;
                //integrator->reset();
                integrator = new Integrator(*ts, 0.0); // Reinitialize Integrator object
            }

            flowRateUpdateCurrentMillis = millis();
            if (flowRateUpdateCurrentMillis - flowRateUpdatePreviousMillis >= flowRateUpdateInterval && flowRateUpdateCurrentMillis - flowRateUpdatePreviousMillis <= flowRateUpdateInterval * 30) {
                flowRateUpdatePreviousMillis += flowRateUpdateInterval;
                updateFlowRate(); // Totalize collected Flow Rate data.
            }

            flowRateRecordCurrentMillis = millis();
            if (flowRateRecordCurrentMillis - flowRateRecordPreviousMillis >= flowRateRecordInterval && flowRateRecordCurrentMillis - flowRateRecordPreviousMillis <= flowRateRecordInterval * 10) {
                flowRateRecordPreviousMillis += flowRateRecordInterval;
                recordFlowRate(); // Record the flow rate to LittleFS Storage.
            }

            delay(5); // Let's let this Thread wait for 5 milliseconds before it loops around again.
        }
};