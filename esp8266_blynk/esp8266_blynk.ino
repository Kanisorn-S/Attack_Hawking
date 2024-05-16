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
const int back_left = 15;
const int back_right = 14;
const int gun = 3;
const int bullet = 8;
const int servo_max_cw = 98; // full throtle clockwise 
const int servo_min_cw = 350; // min throtle counter-clockwise 
const int servo_max_ccw = 630; // full throtle counter-clockwise 
const int servo_min_ccw = 380; // min throtle counter-clockwise 
const int mini_min = 100;
const int mini_bullet_max = 400;
const int mini_max = 230;
const int mini_spin = 300;
const int mini_spin_back = 400;
int timer = 0;
int servoState = mini_max;
const int left_forward = servo_max_ccw; 
const int left_backward = servo_max_cw;
const int right_forward = servo_max_cw;
const int right_backward = servo_max_ccw;
bool isFirst = true;
bool opened = false;

Adafruit_PWMServoDriver board = Adafruit_PWMServoDriver(0x40);

int input;
int firing;

BLYNK_WRITE(V2) {
  firing = param.asInt();
}

BLYNK_WRITE(V1) {
  input = param.asInt();
}

void forward(float duration = 0);
void backward(float duration = 0);
void left(float duration = 0);
void right(float duration = 0);
void cw(float duration = 0);
void ccw(float duration = 0);

int motor1Pin1 = 12;
int motor1Pin2 = 14;
int motor2Pin1 = 15;
int motor2Pin2 = 13;

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
    Serial.print("Current firing state is ");
    Serial.println(firing);

    // if (firing == 1) {
    //   fire(5000);
    // }
    if (input == 1) {
      stop();
    } else if (input == 4) {
      forward();
    } else if (input == 0) {
      backward();
    } else if (input == 7) {
      left();
    } else if (input == 8) {
      right();
    } else if (input == 6) {
      cw();
    } else if (input == 5) {
      ccw();
    } else if (input == 3) {
      aimUp();
    } else if (input == 2) {
      aimDown();
    } else if (input == 9) {
      fire(5000);
    } else if (input == 11) {
      Serial.print("Current open: ");
      Serial.println(opened);
      stop_fire();
      reload();
    }
}

void stop() {
    Serial.println("Stationary");
    board.setPWM(front_left, 0, 0);
    board.setPWM(front_right, 0, 0);
    board.setPWM(back_left, 0, 0);
    board.setPWM(back_right, 0, 0);
    isFirst = true;
}

void forward(float duration) {
    Serial.println("Moving forward");
    float start_time = millis();
    board.setPWM(front_left, 0, left_forward);
    board.setPWM(front_right, 0, right_forward);
    board.setPWM(back_left, 0, left_forward);
    board.setPWM(back_right, 0, right_forward);
    isFirst = true;
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
    isFirst = true;
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
    isFirst = true;
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
    isFirst = true;
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
    isFirst = true;
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
    isFirst = true;
    if (duration == 0) {
      return;
    }
    while (millis() - start_time < duration) {
      Serial.println(millis());
      Serial.println("Turning counter-clockwise");
    }
    stop();
}

void aimDown() {
    Serial.println("Aiming up");
    if (servoState < mini_max) {
      servoState++;
      board.setPWM(gun, 0, servoState);
    }
    isFirst = true;
}

void aimUp() {
    Serial.println("Aiming down");
    if (servoState > mini_min) {
      servoState--;
      board.setPWM(gun, 0, servoState);
    }
    isFirst = true;
}

void reset(float duration) {
    Serial.println("Reseting servo to starting position...");
    servoState--;
    board.setPWM(gun, 0, servoState);
    isFirst = true;
}

void fire(float duration) {
    if (isFirst) {
      Serial.println("Firing");
      // board.setPWM(bullet, 0, mini_bullet_max);
      // delay(2000);
      // board.setPWM(bullet, 0, mini_min);
      // board.setPWM(bullet, 0, mini_spin);
      // delay(300);
      // board.setPWM(bullet, 0, mini_spin_back);
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      delay(2000);
      if (!opened) {
        board.setPWM(bullet, 0, mini_spin);
        delay(50);
        board.setPWM(bullet, 0, mini_spin_back);
        delay(50);
        board.setPWM(bullet, 0, 0);
        // opened = true;
      }

      // delay(duration);
      // digitalWrite(motor1Pin1, LOW);
      // digitalWrite(motor1Pin2, LOW);
      // digitalWrite(motor2Pin1, LOW);
      // digitalWrite(motor2Pin2, LOW);
    } else {
      Serial.println("Locked");
      return;
    }
    

}

void stop_fire() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void reload() {
  if (!opened) {
    return;
  }
  board.setPWM(bullet, 0, mini_spin);
  delay(350);
  board.setPWM(bullet, 0, 0);
  opened = false;
}