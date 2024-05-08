#define BLYNK_TEMPLATE_ID "TMPL695uDcRDn"
#define BLYNK_TEMPLATE_NAME "Attack Hawking"
#define BLYNK_AUTH_TOKEN "Y2K5GmGI1MxgwPn_oQJZFnHRGZO4B1JG"

#define BLYNK_PRINT Serial

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <BlynkSimpleEsp8266.h>
// #include <ESP32WiFi.h>
#include <Adafruit_PWMServoDriver.h>

const char* ssid = "Kong";
const char* pwd = "12345567";
const int front_left = 0;
const int front_right = 1;
const int back_left = 2;
const int back_right = 3;
const int gun = 15;
const int servo_max_cw = 98; // full throtle clockwise 
const int servo_min_cw = 350; // min throtle counter-clockwise 
const int servo_max_ccw = 630; // full throtle counter-clockwise 
const int servo_min_ccw = 380; // min throtle counter-clockwise 
const int mini_min = 150;
const int mini_max = 500;
int servoState = mini_min;
const int left_forward = servo_max_ccw; 
const int left_backward = servo_max_cw;
const int right_forward = servo_max_cw;
const int right_backward = servo_max_ccw;

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

int motor1Pin1 = 14;
int motor1Pin2 = 12;
int motor2Pin1 = 13;
int motor2Pin2 = 15;

void setup() {
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    Serial.begin(115200);
    Serial.println();
    Serial.println("----------------------------------------------");
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
      fire(5000);
    }
}

void stop() {
    Serial.println("Stationary");
    board.setPWM(front_left, 0, 0);
    board.setPWM(front_right, 0, 0);
    board.setPWM(back_left, 0, 0);
    board.setPWM(back_right, 0, 0);
}

void forward(float duration) {
    Serial.println("Moving forward");
    float start_time = millis();
    board.setPWM(front_left, 0, left_forward);
    board.setPWM(front_right, 0, right_forward);
    board.setPWM(back_left, 0, left_forward);
    board.setPWM(back_right, 0, right_forward);
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
    board.setPWM(front_left, 0, left_backward);
    board.setPWM(front_right, 0, right_backward);
    board.setPWM(back_left, 0, left_backward);
    board.setPWM(back_right, 0, right_backward);
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
    board.setPWM(front_left, 0, left_backward);
    board.setPWM(front_right, 0, right_forward);
    board.setPWM(back_left, 0, left_forward);
    board.setPWM(back_right, 0, right_backward);
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
    board.setPWM(front_left, 0, left_forward);
    board.setPWM(front_right, 0, right_backward);
    board.setPWM(back_left, 0, left_backward);
    board.setPWM(back_right, 0, right_forward);
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
    board.setPWM(front_left, 0, left_forward);
    board.setPWM(front_right, 0, right_backward);
    board.setPWM(back_left, 0, left_forward);
    board.setPWM(back_right, 0, right_backward);
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
    board.setPWM(front_left, 0, left_backward);
    board.setPWM(front_right, 0, right_forward);
    board.setPWM(back_left, 0, left_backward);
    board.setPWM(back_right, 0, right_forward);
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Turning counter-clockwise");
    }
    stop();
}

void aimUp() {
    Serial.println("Aiming up");
    if (servoState < mini_max) {
      servoState++;
      board.setPWM(gun, 0, servoState);
    }
}

void aimDown() {
    Serial.println("Aiming down");
    if (servoState > mini_min) {
      servoState--;
      board.setPWM(gun, 0, servoState);
    }
}

void fire(float duration) {
    Serial.println("Firing");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(duration);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);

}