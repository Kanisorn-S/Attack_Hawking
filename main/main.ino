#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>


#define ssid "Kong"
#define pwd "12345567"


void setup() {

    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pwd);
    Serial.println("\nConnecting");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("Connected to Wifi network");
}

void loop() {

    // if (WiFi.status() != WL_CONNECTED){
    //     Serial.print("Disconnected from Wifi");
    //     connectToWifi();
    // }
    Serial.println("Awaiting Input");
}

// void forward() {
//     Serial.println("Moving forward");
// }

// void backward() {
//     Serial.println("Moving backward");
// }

// void left() {
//     Serial.println("Moving to the left");
// }

// void right() {
//     Serial.println("Moving to the right");
// }

// void cw() {
//     Serial.println("Turning clockwise");
// }

// void ccw() {
//     Serial.println("Turning counter-clockwise");
// }

// void fire() {
//     Serial.println("Firing");
// }