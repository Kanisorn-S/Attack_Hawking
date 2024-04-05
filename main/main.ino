#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266.h>
#include <WiFiUdp.h>

#define ssid "Wifi-name"
#define pwd "password"
#define UDP_PORT 4210

WiFiUDP UDP;
char receivedData[255];
char packet[255];
int32_t rssi;
char reply[] = "packet Received"
int FORWARD = 0
int SIDE = 0

void connectToWifi() {
    WiFi.begin(ssid, pwd);
    while (WiFi.status() != WL_CONNECTED) {
        
    }

}

void setup() {

    Serial.begin(115200)

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    WiFi.begin(ssid, pwd);
    while (WiFi.status() != WL_CONNECTED) {

    }
    UDP.begin(UDP_PORT)
}

void loop() {

    if (WiFi.status() != WL_CONNECTED){
        connectToWifi();
    }

    int packetSize = UDP.parsePacket();
    if (packetSize) {
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
    UDP.write(reply);
    UDP.endPacket();
}