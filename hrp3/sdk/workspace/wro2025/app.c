#include "ev3api.h"
#include "app.h"
#define left_sensor EV3_PORT_1
#define right_sensor EV3_PORT_4
#define left_motor EV3_PORT_A
#define right_motor EV3_PORT_D
#define color_sensor COLOR_SENSOR
#define large_motor LARGE_MOTOR
#define kp 1

int min(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void main_task(intptr_t unused) {
    // initialize
    ev3_sensor_config(left_sensor, color_sensor);
    ev3_sensor_config(right_sensor, color_sensor);
    ev3_motor_config(left_motor, large_motor);
    ev3_motor_config(right_motor, large_motor);

    int diff = 0;
    // trace the line until the center button to be pressed
    while (!ev3_button_is_pressed(ENTER_BUTTON)) {
        diff = ev3_color_sensor_get_reflect(left_sensor) - ev3_color_sensor_get_reflect(right_sensor);
        
        ev3_motor_set_power(left_motor, max(-70, min(0, -30-diff*kp)));
        ev3_motor_set_power(right_motor, max(-70, min(0, -30+diff*kp)));
    }

    ev3_motor_stop(left_motor, true);
    ev3_motor_stop(right_motor, true);
}