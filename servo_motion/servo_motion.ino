#include <ESP32Servo.h>

Servo servo;
int servo_pin = 13;

void setup() {
    Serial.begin(9600);

    servo.attach(13);

    servo.write(0);

    swing_servo(servo, 0, 80, 80);
    //swing_servo_ms(servo, 500, 1800, 80);
    servo.write(0);
}
void loop() {}

float delay_standard = 1.5;
float delay_increase_per_swing = 0.001;
float delay_increase = 0.0;
float angle_delay = 0.04;

void swing_servo(Servo target, int min_angle, int max_angle, int iterations) {
    float total_ms = 0;
    for (int i = 0; i < iterations; i++) {
        Serial.print(i);
        Serial.print(": ");
        Serial.print(delay_standard);
        Serial.println();
        for (int angle = min_angle; angle <= max_angle; angle++) {
            target.write(angle);
            float d = delay_standard + (angle * angle_delay);
            total_ms += d;
            delay(d);
        }
        for (int angle = max_angle; angle >= min_angle; angle--) {
            target.write(angle);
            float d = delay_standard + (angle * angle_delay);
            total_ms += d;
            delay(d);
        }
        delay_standard+=delay_increase;
        delay_increase+=delay_increase_per_swing;
    }

    Serial.print("swing_servo() finished in ");
    Serial.print(total_ms);
    Serial.print("ms.");
    Serial.println();
}
