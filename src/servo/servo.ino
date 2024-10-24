#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

const int servo_max_cw = 98; // full throtle clockwise 
const int servo_min_cw = 350; // min throtle counter-clockwise 
const int servo_max_ccw = 632; // full throtle counter-clockwise 
const int servo_min_ccw = 380; // min throtle counter-clockwise 

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
    float start_time = millis();
    board.setPWM(0, 0, servo_min_cw);
    while (millis() - start_time < t) {
        Serial.print(millis());
        Serial.println("Spinning");
    }
    board.setPWM(0, 0, 0);
    sleep(10000000);
}