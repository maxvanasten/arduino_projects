#include <ESP32Servo.h>

Servo servo;
int servo_pin = 13;

void setup() {
    Serial.begin(9600);
    servo.attach(servo_pin);
}

void loop() {

    servo.write(0);
    delay(2500);
    servo.write(180);
    delay(2500);
    

}


