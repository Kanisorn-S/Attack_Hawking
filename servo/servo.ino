#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver board = Adafruit_PWMServoDriver(0x40);


void setup() {
    Serial.begin(9600);
    Serial.println("4 channel Servo test");

    board.begin();
    board.setPWMFreq(60);
}

void loop() {
    float t = 5000;
    float start_time = millis();
    board.setPWM(0, 0, 1000);
    while (millis() - start_time < t) {
        ;
    }
    board.setPWM(0, 0, 0);
}