#define BLYNK_TEMPLATE_ID "TMPL695uDcRDn"
#define BLYNK_TEMPLATE_NAME "Attack Hawking"
#define BLYNK_AUTH_TOKEN "Y2K5GmGI1MxgwPn_oQJZFnHRGZO4B1JG"

#define BLYNK_PRINT Serial

#include <SPI.h>
#include <Wire.h>
#include <BlynkSimpleEsp32.h>

const char* ssid = "Kong";
const char* pwd = "12345567";
const int target1 = 32;
const int target2 = 33;
const int target3 = 25;
const int target4 = 26;
int v1;
int v2;
int v3;
int v4;

int input;


void setup() {
    pinMode(target1, INPUT);
    pinMode(target2, INPUT);
    pinMode(target3, INPUT);
    pinMode(target4, INPUT);
    Serial.begin(9600);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pwd);
}

void loop() {
    Blynk.run();
    v1 = digitalRead(target1);
    v2 = digitalRead(target3);
    v3 = digitalRead(target4);
    v4 = digitalRead(target2);
    Serial.print("Target 1 is reading: ");
    Serial.println(v1);
    Serial.print("Target 2 is reading: ");
    Serial.println(v2);
    Serial.print("Target 3 is reading: ");
    Serial.println(v3);
    Serial.print("Target 4 is reading: ");
    Serial.println(v4);
    if (v4 == 1) {
        Blynk.virtualWrite(V0, 4);
        Serial.println("Hit target for 4 Points!");
    } else if (v3 == 1) {
        Blynk.virtualWrite(V0, 3);
        Serial.println("Hit target for 4 Points!");
    } else if (v2 == 1) {
        Blynk.virtualWrite(V0, 1);
        Serial.println("Hit target for 4 Points!");
    } else if (v1 == 1) {
        Blynk.virtualWrite(V0, 2);
        Serial.println("Hit target for 4 Points!");
    }
    // } else {
    //     Blynk.virtualWrite(V0, 0);
    //     Serial.println("No target hit!");
    // }
    Serial.println("------------------------------------------------");
}