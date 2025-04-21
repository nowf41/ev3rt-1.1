#include "ev3api.h"
#include "app.h"
#include "ports.h"

void turn(int degree) {
    int8_t first = ev3_gyro_sensor_get_angle(GYRO);
    if (degree == first) return;
    if (degree > first) {
        ev3_motor_set_power(LEFT_MOTOR, 10);
        ev3_motor_set_power(RIGHT_MOTOR, -10);
        while (ev3_gyro_sensor_get_angle(GYRO) < degree) {
            tslp_tsk(10);
        }
        ev3_motor_stop(LEFT_MOTOR, true);
        ev3_motor_stop(RIGHT_MOTOR, true);
    }
    if (degree < first) {
        ev3_motor_set_power(LEFT_MOTOR, -10);
        ev3_motor_set_power(RIGHT_MOTOR, 10);
        while (ev3_gyro_sensor_get_angle(GYRO) > degree) {
            tslp_tsk(10);
        }
        ev3_motor_stop(LEFT_MOTOR, true);
        ev3_motor_stop(RIGHT_MOTOR, true);
    }
    return;
}

// SYNCED
void straight_deg(int degree) {
    ev3_motor_rotate(LEFT_MOTOR, degree, 50, false);
    ev3_motor_rotate(RIGHT_MOTOR, degree, 50, true);
    tslp_tsk(1000);
    return;
}

// calls straight_deg() internally
void straight_mm(int mm) {
    return straight_deg((int)( ( ( (float)mm ) / (TIRE_RADIUS * PI)) * 360));
}

void straight_ms(int ms) {
    ev3_motor_set_power(LEFT_MOTOR, 30);
    ev3_motor_set_power(RIGHT_MOTOR, 30);
    tslp_tsk(ms);
    ev3_motor_stop(LEFT_MOTOR, true);
    ev3_motor_stop(RIGHT_MOTOR, true);
}

void straight_until_left_black(int brake) {
    int left = 100;
    ev3_motor_set_power(LEFT_MOTOR, 30);
    ev3_motor_set_power(RIGHT_MOTOR, 30);
    while (true) {
        left = ev3_color_sensor_get_reflect(LEFT_COLOR);
        if (left <= BLACK_BORDER) {
            break;
        }
        tslp_tsk(100);
    }
    ev3_motor_stop(LEFT_MOTOR, true);
    ev3_motor_stop(RIGHT_MOTOR, true);
}

void trace_until_left_black(int brake) {
    int left = 100, right = 100;
    while (true) {
        left = ev3_color_sensor_get_reflect(LEFT_COLOR);
        right = ev3_color_sensor_get_reflect(RIGHT_COLOR);
        if (left <= BLACK_BORDER) {
            break;
        }
        int diff = (left - right) * P_GAIN;
        ev3_motor_set_power(LEFT_MOTOR, 50 - diff);
        ev3_motor_set_power(RIGHT_MOTOR, 50 + diff);
    }
    ev3_motor_stop(LEFT_MOTOR, brake == 1);
    ev3_motor_stop(RIGHT_MOTOR, brake == 1);
    return;
}