#define BLYNK_TEMPLATE_ID "TMPL695uDcRDn"
#define BLYNK_TEMPLATE_NAME "Attack Hawking"
#define BLYNK_AUTH_TOKEN "Y2K5GmGI1MxgwPn_oQJZFnHRGZO4B1JG"

#define BLYNK_PRINT Serial

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

const char* ssid = "Passorn138_2.4G";
const char* pwd = "kong2546";

int input;

BLYNK_WRITE(V1) {
  input = param.asInt();
  // Serial.print("Input value is ");
  // Serial.println(input);
}

void setup() {

    Serial.begin(115200);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pwd);
}

void loop() {

    Blynk.run();
    Blynk.syncVirtual(V1);
    // delay(1000);

    Serial.print("Current input status is ");
    Serial.println(input);
    if (input == 0) {
      stop();
    } else if (input == 1) {
      forward();
    } else if (input == 2) {
      backward();
    } else if (input == 3) {
      left();
    } else if (input == 4) {
      right();
    } else if (input == 5) {
      cw();
    } else if (input == 6) {
      ccw();
    } else if (input == 7) {
      aimUp();
    } else if (input == 8) {
      aimDown();
    } else if (input == 9) {
      fire();
    }
}

void stop() {
    Serial.println("Stationary");
}

void forward() {
    Serial.println("Moving forward");
}

void backward() {
    Serial.println("Moving backward");
}

void left() {
    Serial.println("Moving to the left");
}

void right() {
    Serial.println("Moving to the right");
}

void cw() {
    Serial.println("Turning clockwise");
}

void ccw() {
    Serial.println("Turning counter-clockwise");
}

void aimUp() {
    Serial.println("Aiming up");
}

void aimDown() {
    Serial.println("Aiming down");
}

void fire() {
    Serial.println("Firing");
}