#include "thingProperties.h"
#include "DHT.h"

// ============================================
// DHT11
// ============================================
#define DHTPIN 3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// ============================================
// PINS
// ============================================
int relayPin = 2;
int soilPin  = A1;

// ============================================
// THRESHOLD
// ============================================
int threshold = 650;

// ============================================
// SETUP
// ============================================
void setup() {

  Serial.begin(9600);
  delay(1500);

  // Cloud
  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  // Relay
  pinMode(relayPin, OUTPUT);

  // Pump OFF initially
  digitalWrite(relayPin, LOW);

  // DHT
  dht.begin();

  Serial.println("SMART IRRIGATION STARTED");
}

// ============================================
// LOOP
// ============================================
void loop() {

  ArduinoCloud.update();

  // Read sensors
  bedA = analogRead(soilPin);

  tempA = dht.readTemperature();

  if (isnan(tempA)) {
    tempA = 0;
  }

  // ========================================
  // AUTO MODE
  // ========================================
  if (autoMode == true) {

    // Dry soil
    if (bedA > threshold) {

      digitalWrite(relayPin, HIGH);

      pump = true;

      Serial.println("AUTO: Dry soil -> Pump ON");
    }

    // Wet soil
    else {

      digitalWrite(relayPin, LOW);

      pump = false;

      Serial.println("AUTO: Wet soil -> Pump OFF");
    }
  }

  // ========================================
  // MANUAL MODE
  // ========================================
  else {

    if (pump == true) {

      digitalWrite(relayPin, HIGH);

      Serial.println("MANUAL: Pump ON");
    }

    else {

      digitalWrite(relayPin, LOW);

      Serial.println("MANUAL: Pump OFF");
    }
  }

  // ========================================
  // SERIAL MONITOR
  // ========================================
  Serial.println("----------- DATA -----------");

  Serial.print("Moisture: ");
  Serial.println(bedA);

  Serial.print("Temperature: ");
  Serial.println(tempA);

  Serial.print("Pump: ");
  Serial.println(pump);

  Serial.print("Auto Mode: ");
  Serial.println(autoMode);

  Serial.println("----------------------------");
  Serial.println();

  delay(2000);
}

// ============================================
// CLOUD CALLBACKS
// ============================================

void onPumpChange() {

  // Only allow manual control
  if (autoMode == false) {

    if (pump) {

      digitalWrite(relayPin, HIGH);

      Serial.println("Cloud -> Pump ON");

    } else {

      digitalWrite(relayPin, LOW);

      Serial.println("Cloud -> Pump OFF");
    }
  }
}

void onAutoModeChange() {

  Serial.print("Auto Mode changed to: ");
  Serial.println(autoMode);
}
