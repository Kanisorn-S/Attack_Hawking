#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

const int mini_spin = 60;
const int bullet = 4;
int timer = 0;

Adafruit_PWMServoDriver board = Adafruit_PWMServoDriver(0x40);

void setup() {
    Serial.begin(115200);
    Serial.println("Testing bullet dispenser");

    board.begin();
    board.setPWMFreq(60);
}

void loop() {
    Serial.println("Entering Loop");
    if (timer < 10) {
        board.setPWM(bullet, 0, mini_spin);
        timer++;
    } else {
        board.setPWM(0, 0, 0);
        Serial.println("Stopped");
        sleep(10000000000);
    }
}