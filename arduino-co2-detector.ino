#include "MQ135.h"
#define ANALOGPIN A0            // Analog PIN on the board
#define RZERO 336.37            // RZERO Calibration Value
#define RL    20                // Resistance on MQ sensor
#define CALIBRATE_MODE false    // Calibration should be done outdoors
#define CALIBRATION_SAMPLES 100
MQ135 gasSensor = MQ135(ANALOGPIN, RZERO, RL);

float calibration() {
  Serial.println("Calibrating MQ135...");

  float rzero = 0;
  float sumRzero = 0;
  for (int i = 0; i < CALIBRATION_SAMPLES; i++) {
    rzero = gasSensor.getRZero();
    sumRzero += rzero;

    Serial.println("Sample " + String(i) + ": " + String(rzero));
    delay(1500);
  }

  float averageRzero = sumRzero / CALIBRATION_SAMPLES;
  Serial.println("OK");
  Serial.println("Average Rzero: " + String(averageRzero));
  Serial.println("Now you can use this RZERO for indoor monitoring");

  return averageRzero;
}

void setup()
{
  Serial.begin(9600);
  delay(1000);

  if (CALIBRATE_MODE) {
    Serial.println("Program running for calibration");
    float averageRzero = calibration();

    gasSensor = MQ135(ANALOGPIN, averageRzero, RL);
    delay(500);
  }
}

void loop() {
  int analog = analogRead(ANALOGPIN);
  Serial.print("CO2 (ANALOG): ");
  Serial.println(analog);

  float ppm = gasSensor.getPPM();
  Serial.print("CO2 (GET PPM): ");
  Serial.println(ppm);
  delay(1000);
}
