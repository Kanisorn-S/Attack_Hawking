#include <SPI.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Adafruit_PWMServoDriver.h>


#define ssid "Passorn138_2.4G"
#define pwd "kong2546"
#define UDP_PORT 4210

const int front_left = 0;
const int front_right = 1;
const int back_left = 2;
const int back_right = 3;
const int gun = 15;
const int servo_max_cw = 98; // full throtle clockwise 
const int servo_min_cw = 350; // min throtle counter-clockwise 
const int servo_max_ccw = 632; // full throtle counter-clockwise 
const int servo_min_ccw = 380; // min throtle counter-clockwise 
const int mini_cw = 60;
const int mini_ccw = 1100;
const int left_forward = servo_max_ccw; 
const int left_backward = servo_max_cw;
const int right_forward = servo_max_cw;
const int right_backward = servo_max_ccw;

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40);

void forward(float duration = 0);
void backward(float duration = 0);
void left(float duration = 0);
void right(float duration = 0);
void cw(float duration = 0);
void ccw(float duration = 0);
void aimUp(float duration = 0);
void aimDown(float duration = 0);
void fire(float duration = 0);

int motor1Pin1 = 14;
int motor1Pin2 = 12;
int motor2Pin1 = 13;
int motor2Pin2 = 15;

WiFiUDP UDP;
char receivedData[255];
char packet[255];
int32_t rssi;
char reply[] = "packet Received";

void connectToWiFi() {
    Serial.println("connecting to WiFi ...");
    WiFi.begin(ssid, pwd);

    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(2000);
    }

    Serial.println("Connected.");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP().toString().c_str());
}

void setup() {
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    connectToWiFi();
    UDP.begin(UDP_PORT);
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Wifi Disconnected...");
        connectToWiFi();
    }

    int packetSize = UDP.parsePacket();
    if (packetSize) {
        UDP.read(receivedData, sizeof(receivedData));
        receivedData[packetSize] = '\0';
        Serial.print("Input Key: ");
        Serial.println(receivedData);
        if (strcmp(receivedData, "0")) {
            stop();
        } else if (strcmp(receivedData, "1")) {
            forward();
        } else if (strcmp(receivedData, "2")) {
            backward();
        } else if (strcmp(receivedData, "3")) {
            left();
        } else if (strcmp(receivedData, "4")) {
            right();
        } else if (strcmp(receivedData, "5")) {
            cw();
        } else if (strcmp(receivedData, "6")) {
            ccw();
        } else if (strcmp(receivedData, "7")) {
            aimUp();
        } else if (strcmp(receivedData, "8")) {
            aimDown();
        } else if (strcmp(receivedData, "9")) {
            fire();
        }
        UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
        UDP.write(reply);
        UDP.endPacket();
    } 
}



void stop() {
    Serial.println("Stationary");
    pca.setPWM(front_left, 0, 0);
    pca.setPWM(front_right, 0, 0);
    pca.setPWM(back_left, 0, 0);
    pca.setPWM(back_right, 0, 0);
}

void forward(float duration) {
    Serial.println("Moving forward");
    float start_time = millis();
    pca.setPWM(front_left, 0, left_forward);
    pca.setPWM(front_right, 0, right_forward);
    pca.setPWM(back_left, 0, left_forward);
    pca.setPWM(back_right, 0, right_forward);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Moving forward");
    }
    stop();
}

void backward(float duration) {
    Serial.println("Moving backward");
    float start_time = millis();
    pca.setPWM(front_left, 0, left_backward);
    pca.setPWM(front_right, 0, right_backward);
    pca.setPWM(back_left, 0, left_backward);
    pca.setPWM(back_right, 0, right_backward);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Moving backward");
    }
    stop();
}

void left(float duration) {
    Serial.println("Moving to the left");
    float start_time = millis();
    pca.setPWM(front_left, 0, left_backward);
    pca.setPWM(front_right, 0, right_forward);
    pca.setPWM(back_left, 0, left_forward);
    pca.setPWM(back_right, 0, right_backward);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Moving to the left");
    }
    pca.setPWM(back_left, 0, 0);
}

void right(float duration) {
    Serial.println("Moving to the right");
    float start_time = millis();
    pca.setPWM(front_left, 0, left_forward);
    pca.setPWM(front_right, 0, right_backward);
    pca.setPWM(back_left, 0, left_backward);
    pca.setPWM(back_right, 0, right_forward);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Moving to the right");
    }
    pca.setPWM(back_right, 0, 0);
}

void cw(float duration) {
    Serial.println("Turning clockwise");
    float start_time = millis();
    pca.setPWM(front_left, 0, left_forward);
    pca.setPWM(front_right, 0, right_backward);
    pca.setPWM(back_left, 0, left_forward);
    pca.setPWM(back_right, 0, right_backward);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Turning clockwise");
    }
    stop();
}

void ccw(float duration) {
    Serial.println("Turning counter-clockwise");
    float start_time = millis();
    pca.setPWM(front_left, 0, left_backward);
    pca.setPWM(front_right, 0, right_forward);
    pca.setPWM(back_left, 0, left_backward);
    pca.setPWM(back_right, 0, right_forward);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Turning counter-clockwise");
    }
    stop();
}

void aimUp(float duration) {
    Serial.println("Aiming up");
    float start_time = millis();
    pca.setPWM(gun, 0, mini_ccw);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Aiming up");
    }
    pca.setPWM(gun, 0, 0);
}

void aimDown(float duration) {
    Serial.println("Aiming down");
    float start_time = millis();
    pca.setPWM(gun, 0, mini_cw);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Aiming down");
    }
    pca.setPWM(gun, 0, 0);
}

void fire(float duration) {
    Serial.println("Firing");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    delay(duration);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);

}

