void setup() {
    Serial.begin(9600);
    Serial.println("Hello World!");
    pinMode(32, OUTPUT);
}

void loop() {
    Serial.println("Connected");
    digitalWrite(32, HIGH);
    delay(1000);
    digitalWrite(32, LOW);
    delay(1000);
}

