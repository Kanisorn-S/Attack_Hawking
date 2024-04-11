#define BLYNK_TEMPLATE_ID "TMPL69_HKO5iy"
#define BLYNK_TEMPLATE_NAME "Mahn automatic"
#define BLYNK_AUTH_TOKEN "cFMczdEq_b1rYcfLezwHhQu2RzY9lJOG"

#define BLYNK_PRINT Serial

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define ssid "Passorn138_2.4G"
#define pwd "kong2546"

int input;

BLYNK_WRITE(V0) {
  input = param.asInt();
}


void setup() {

    Serial.begin(115200);
    // WiFi.mode(WIFI_STA);
    // WiFi.begin(ssid, pwd);
    // Serial.println("\nConnecting");
    // while (WiFi.status() != WL_CONNECTED) {
    //     Serial.print(".");
    //     delay(1000);
    // }
    // Serial.print("\nConnected to Wifi with IP: ");
    // Serial.println(WiFi.localIP());

    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pwd);
}

void loop() {

    Blynk.run();
    Blynk.syncVirtual(V0);

    // if (WiFi.status() != WL_CONNECTED){
    //     Serial.print("Disconnected from Wifi");
    // }
    Serial.print("Current input status is ");
    Serial.println(input);
    sleep(2000);
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