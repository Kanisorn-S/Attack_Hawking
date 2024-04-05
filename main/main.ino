#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
// #include <ESP32.h>
#include <WiFiUdp.h>

#define ssid "Kong"
#define pwd "12345567"
#define UDP_PORT 4210

WiFiUDP UDP;
char receivedData[255];
char packet[255];
int32_t rssi;
char* reply = "packet Received";
int FORWARD = 0;
int SIDE = 0;

void connectToWifi() {
    WiFi.begin(ssid, pwd);
    Serial.println("\nConnecting");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("Connected to Wifi network");

}

void setup() {

    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    connectToWifi();
    UDP.begin(UDP_PORT);
}

void loop() {

    if (WiFi.status() != WL_CONNECTED){
        Serial.print("Disconnected from Wifi");
        connectToWifi();
    }
    Serial.println("Awaiting Input");
    int packetSize = UDP.parsePacket();
    if (packetSize) {
        Serial.println("Received input from keyboard");
        UDP.read(receivedData, sizeof(receivedData));
        receivedData[packetSize] = '\0';

        if (strcmp(receivedData, "0") == 0) { forward(); }
        if (strcmp(receivedData, "1") == 0) { backward(); }
        if (strcmp(receivedData, "2") == 0) { left(); }
        if (strcmp(receivedData, "3") == 0) { right(); }
        if (strcmp(receivedData, "4") == 0) { cw(); }
        if (strcmp(receivedData, "5") == 0) { ccw(); }
        if (strcmp(receivedData, "6") == 0) { fire(); }
    }

    UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
    // UDP.write(reply);
    UDP.endPacket();
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

void fire() {
    Serial.println("Firing");
}