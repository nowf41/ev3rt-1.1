#include "ev3api.h"
#include "app.h"
#define left_sensor EV3_PORT_1
#define right_sensor EV3_PORT_4
#define left_motor EV3_PORT_A
#define right_motor EV3_PORT_D
#define color_sensor COLOR_SENSOR
#define large_motor LARGE_MOTOR
#define kp 0.5

int min(int a, int b) { if (a > b) { return b; } else { return a; } }
int max(int a, int b) { if (a > b) { return a; } else { return b; } }
int abs(int a) { if (a >= 0) { return a; } else { return -a; } }
int mid(int a, int b, int c) {if (a>=b&&b>=c){return b;}if (a>=c&&c>=b){return c;}if (b>=a&&a>=c){return a;}if (b>=c&&c>=a){return c;}if (c>=a&&a>=b){return a;}if (c>=b&&b>=a){return b;}return 0;}

void main_task(intptr_t unused) {
    // initialize
    ev3_sensor_config(left_sensor, color_sensor);
    ev3_sensor_config(right_sensor, color_sensor);
    ev3_motor_config(left_motor, large_motor);
    ev3_motor_config(right_motor, large_motor);

    int diff = 0;
    int p = 0;
    // trace the line until the center button to be pressed
    while (!ev3_button_is_pressed(ENTER_BUTTON)) {
        diff = ev3_color_sensor_get_reflect(left_sensor) - ev3_color_sensor_get_reflect(right_sensor);
        p = diff * kp;

        ev3_motor_set_power(left_motor, mid(-90, -30-p, 90));
        ev3_motor_set_power(right_motor, mid(-90, -30+p, 90));
    }

    ev3_motor_stop(left_motor, true);
    ev3_motor_stop(right_motor, true);
}