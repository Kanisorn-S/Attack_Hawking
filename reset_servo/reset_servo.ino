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
    float start_time = millis();
    float duration = 5000;
    int servo_state = 250;
    while (millis() - start_time < duration) {
        Serial.print("Current servo state: ");
        Serial.println(servo_state);
        board.setPWM(0, 0, servo_state);
        board.setPWM(1, 0, servo_state);
        board.setPWM(2, 0, servo_state);
        servo_state--;
    }
    delay(10000000);
}