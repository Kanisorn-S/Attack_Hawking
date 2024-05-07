#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

const int servo_max_cw = 98; // full throtle clockwise 
const int servo_min_cw = 350; // min throtle counter-clockwise 
const int servo_max_ccw = 630; // full throtle counter-clockwise 
const int servo_min_ccw = 380; // min throtle counter-clockwise 
const int mini_cw = 60;
const int mini_ccw = 1100;

#define servoMin  150     
#define servoMax  500

Adafruit_PWMServoDriver board = Adafruit_PWMServoDriver(0x40);


void setup() {
    Serial.begin(9600);
    Serial.println("4 channel Servo test");

    board.begin();
    board.setPWMFreq(60);
}

void loop() {
    Serial.println("Entering Loop");
    float t = 5000;
    for (int pulse = servoMin; pulse < servoMax; pulse++){
      board.setPWM(15, 0, pulse);
    delay(5);
    }
    float start_time = millis();
    board.setPWM(0, 0, servo_max_cw);
    while (millis() - start_time < t) {
        Serial.print(millis());
        Serial.println("Spinning");
    }
    board.setPWM(0, 0, 0);
    delay(10000000);
}