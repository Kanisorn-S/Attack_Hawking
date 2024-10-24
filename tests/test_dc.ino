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
    Serial.print("Testing DC Motor...");
}

void loop() {
    // Serial.println("Spin motor 1");
    // digitalWrite(motor1Pin1, LOW);
    // digitalWrite(motor1Pin2, HIGH);
    // delay(3000);

    // Serial.println("Stopping motor 1");
    // digitalWrite(motor1Pin1, LOW);
    // digitalWrite(motor1Pin2, LOW);
    // delay(1000);

    // Serial.println("Spin motor 2");
    // digitalWrite(motor2Pin1, LOW);
    // digitalWrite(motor2Pin2, HIGH);
    // delay(3000);

    // Serial.println("Stopping motor 2");
    // digitalWrite(motor2Pin1, LOW);
    // digitalWrite(motor2Pin2, LOW);
    // delay(1000);

    Serial.println("Spin both motors");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(5000);

    Serial.println("Stopping both motors");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    delay(3000);
}