// TODO: Wait for start signal from RFID before starting "wobbler()" program
// TODO: Make second program

#include <ESP32Servo.h>

Servo servo_one;
int servo_one_pin = 13;

int lr_one_pin = 14;

void setup() {
    servo_one.attach(servo_one_pin);
    servo_one.write(0);

    pinMode(lr_one_pin, INPUT);

    Serial.begin(9600);
}

bool is_wobbler_active = false;

void loop() {
    bool lr_value = digitalRead(lr_one_pin);

    Serial.println(lr_value);

    if (lr_value == 0) {
        is_wobbler_active = !is_wobbler_active;
        delay(1500);
    }

    if (is_wobbler_active) {
        servo_one.write(0);
        delay(1000);
        servo_one.write(60);
        delay(1000);
    }
}

void wobbler(Servo target_servo, int min_degrees, int max_degrees)
{
    for (int i = 0; i < 100; i++)
    {
        sweep_servo(target_servo, i, min_degrees, max_degrees);
    }

    target_servo.write(90);
}

void sweep_servo(Servo target_servo, int time_delay, int min_degrees, int max_degrees) {
    for (int i = max_degrees; i > min_degrees; i -= 10) {
        target_servo.write(i);
        delay(time_delay);
    }

    for (int i = min_degrees; i < max_degrees; i += 10) {
        target_servo.write(i);
        delay(time_delay);
    }
}
