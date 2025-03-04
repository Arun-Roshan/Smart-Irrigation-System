#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SENSOR_PIN A0    // Soil moisture sensor
#define BUZZER_PIN D6    // Buzzer (GPIO12)

const int moistureThreshold = 30;  // Dry soil threshold

// OLED display setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // OLED initialization
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED initialization failed!");
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Smart Irrigation");
  display.display();
  delay(2000);
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);
  float moisturePercent = (1 - (sensorValue / 1024.0)) * 100;  // Convert to percentage

  Serial.print("Soil Moisture Level: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Moisture: ");
  display.print(moisturePercent);
  display.println("%");

  // Draw moisture level bar
  int barWidth = map(moisturePercent, 0, 100, 0, 100); // Scale moisture to bar width
  display.drawRect(10, 30, 100, 10, WHITE); // Outline
  display.fillRect(10, 30, barWidth, 10, WHITE); // Fill based on moisture level

  if (moisturePercent < moistureThreshold) {
    Serial.println("Soil is too dry! Activating Buzzer...");

    // Activate Buzzer
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);
    digitalWrite(BUZZER_PIN, LOW);

    display.setCursor(0, 50);
    display.println("Dry Soil! Buzzer ON");
  } else {
    Serial.println("Soil moisture is sufficient.");
    display.setCursor(0, 50);
    display.println("Soil Moisture OK");
  }

  display.display();
  Serial.println("-----------------------------");
  delay(2000);  // Read every 2 seconds
}
