# Smart Irrigation System with OLED Display & Buzzer 🌱

This is a simple smart irrigation system using an ESP8266 (NodeMCU), an OLED display, a soil moisture sensor, and a buzzer. The system continuously monitors soil moisture levels and alerts the user when the soil is too dry by activating a buzzer and displaying a warning on the OLED screen.

**Features**

✅ Real-time soil moisture monitoring.

✅ OLED display with moisture percentage & graphical bar.

✅ Buzzer alert for dry soil.

✅ Compact and low-power solution.

**Hardware Components**

-> ESP8266 (NodeMCU)

-> Soil Moisture Sensor

-> 0.96" OLED Display (SSD1306, I2C)

-> Buzzer

-> Jumper Wires

**Libraries Used**

You need to install the following libraries in the Arduino IDE:

-> Adafruit SSD1306 - (Install from Library Manager)

-> Adafruit GFX - (Required for OLED display)

-> Wire.h - (Default Arduino library for I2C communication)

**Wiring Connections (ESP8266 - NodeMCU)**

<img width="448" alt="image" src="https://github.com/user-attachments/assets/43673ca9-e01d-49f7-a5cf-8578a318285a" />

**Project Images & Demonstration**

![WhatsApp Image 2025-03-04 at 21 12 14_d91137b1](https://github.com/user-attachments/assets/1a9c8641-c3ba-4955-a5e0-48c252f5b2a1)

![WhatsApp Image 2025-03-04 at 21 12 14_97c499d8](https://github.com/user-attachments/assets/447f14e0-477a-4264-a715-ce9eda0bcc12)

![WhatsApp Image 2025-03-04 at 21 12 14_0df575bb](https://github.com/user-attachments/assets/b2b8e4c2-3388-47ca-a0eb-d3c2384c4c3a)

**How It Works**

-> The soil moisture sensor reads the moisture level of the soil.

-> The OLED display shows the percentage of soil moisture along with a visual bar indicator.

-> If the soil moisture drops below 30%, the buzzer is activated to alert the user.

-> The system updates every 2 seconds.

**Future Enhancements**

🔹 Add WiFi & IoT connectivity for remote monitoring.

🔹 Send notifications to a mobile app when moisture is low.

🔹 Implement automatic irrigation control by adding a relay & water pump.
