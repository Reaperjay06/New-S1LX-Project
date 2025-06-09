/*
  Emo-Plant Monitor
  MKR WiFi 1010 + Soil Moisture + PulseSensor
  -------------------------------------------
  • Maps soil probe reading to % moisture
  • Computes BPM over 10-beat rolling window
  • Combines the two to drive RGB LED colour
*/

#define PULSE_SENSOR_DISABLE_INTERRUPTS
#include <PulseSensorPlayground.h>


///////////////////////
// === SETTINGS ==== //
///////////////////////
const int MOISTURE_PIN = A0;
const int PULSE_PIN    = A1;

const int LED_R = 9;
const int LED_G = 10;
const int LED_B = 11;
const bool LED_COMMON_ANODE = false;   // flip if you wired common-anode

// Calibrate your own dry / wet values:
const int DRY_READING  = 850;   // analogRead() when probe is in air
const int WET_READING  = 350;   // analogRead() when probe is in water-saturated soil

// Heart-rate zones
const int HIGH_BPM = 100;

PulseSensorPlayground pulseSensor;

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 4000) { }   // wait up to 4 s for monitor
  Serial.println("Serial ready…");

  // --- LED pins ---
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  // --- Pulse sensor ---
  pulseSensor.analogInput(PULSE_PIN);
  pulseSensor.setThreshold(660);         // tweak if needed
  pulseSensor.outputBeat(true);    // prints “♥ A HeartBeat Happened” + BPM
  pulseSensor.begin();

  Serial.println(F("Emo-Plant starting…"));
}

void loop() {
  // 1. Read sensors
  int rawMoist   = analogRead(MOISTURE_PIN);
  int moisturePct = map(rawMoist, DRY_READING, WET_READING, 0, 100);
  moisturePct = constrain(moisturePct, 0, 100);

  int bpm = pulseSensor.getBeatsPerMinute();
  bool beat = pulseSensor.sawStartOfBeat();   // keeps algorithm inside library ticking

  // 2. Decide LED colour each second
  static unsigned long lastUpdate = 0;
  if (millis() - lastUpdate >= 1000) {
    lastUpdate = millis();

    // Rules table
    if (moisturePct < 30 && bpm > HIGH_BPM) {
      setLED(255, 0, 0);    // RED
      Serial.println("⚠️  Dry soil + high BPM → RED (Water + relax!)");
    } else if (moisturePct < 30) {
      setLED(0, 0, 255);    // BLUE
      Serial.println("💧 Dry soil → BLUE (Water soon)");
    } else if (bpm > HIGH_BPM) {
      setLED(128, 0, 128);  // PURPLE
      Serial.println("💓 High BPM → PURPLE (Take a break)");
    } else {
      setLED(0, 255, 0);    // GREEN
      Serial.println("✅ All good → GREEN");
    }

    // 3. Log raw numbers
    Serial.print("Soil: ");     Serial.print(moisturePct); Serial.print("%  |  ");
    Serial.print("Heart rate: ");Serial.print(bpm);        Serial.println(" BPM");
  }
}

///////////////////////
// Helper to drive LED
///////////////////////
void setLED(int r, int g, int b) {
  if (LED_COMMON_ANODE) { r = 255 - r; g = 255 - g; b = 255 - b; }
  analogWrite(LED_R, r);
  analogWrite(LED_G, g);
  analogWrite(LED_B, b);
}
