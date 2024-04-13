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
#include <Adafruit_PWMServoDriver.h>

const char* ssid = "Passorn138_2.4G";
const char* pwd = "kong2546";
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

Adafruit_PWMServoDriver board = Adafruit_PWMServoDriver(0x40);

int input;

BLYNK_WRITE(V1) {
  input = param.asInt();
}

void forward(float duration = 0);
void backward(float duration = 0);
void left(float duration = 0);
void right(float duration = 0);
void cw(float duration = 0);
void ccw(float duration = 0);
void aimUp(float duration = 0);
void aimDown(float duration = 0);

void setup() {
    Serial.begin(115200);
    board.begin();
    board.setPWMFreq(60);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pwd);
}

void loop() {

    Blynk.run();
    Blynk.syncVirtual(V1);

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
    board.setPWM(front_left, 0, 0);
    board.setPWM(front_right, 0, 0);
}

void forward(float duration) {
    Serial.println("Moving forward");
    float start_time = millis();
    board.setPWM(front_left, 0, servo_max_ccw);
    board.setPWM(front_right, 0, servo_max_cw);
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
    board.setPWM(front_left, 0, servo_max_cw);
    board.setPWM(front_right, 0, servo_max_ccw);
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
    board.setPWM(back_left, 0, mini_ccw);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Moving to the left");
    }
    board.setPWM(back_left, 0, 0);
}

void right(float duration) {
    Serial.println("Moving to the right");
    float start_time = millis();
    board.setPWM(back_right, 0, mini_cw);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Moving to the right");
    }
    board.setPWM(back_right, 0, 0);
}

void cw(float duration) {
    Serial.println("Turning clockwise");
    float start_time = millis();
    board.setPWM(front_left, 0, servo_max_ccw);
    board.setPWM(front_right, 0, servo_max_ccw);
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
    board.setPWM(front_left, 0, servo_max_cw);
    board.setPWM(front_right, 0, servo_max_cw);
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
    board.setPWM(gun, 0, mini_ccw);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Aiming up");
    }
    board.setPWM(gun, 0, 0);
}

void aimDown(float duration) {
    Serial.println("Aiming down");
    float start_time = millis();
    board.setPWM(gun, 0, mini_cw);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Aiming down");
    }
    board.setPWM(gun, 0, 0);
}

void fire() {
    Serial.println("Firing");
}