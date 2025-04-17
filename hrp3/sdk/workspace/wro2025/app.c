#include "ev3api.h"
#include "app.h"
#include "ports.h"

void main_task(intptr_t unused) {
    init_ports();

    turn(90);
    turn(0);
    straight_deg(720);
}

void init_ports() {
    ev3_motor_config(LEFT_MOTOR, LEFT_MOTOR_TYPE);
    ev3_motor_config(RIGHT_MOTOR, RIGHT_MOTOR_TYPE);
    ev3_motor_config(FINGER, FINGER_TYPE);
    ev3_motor_config(CRANE, CRANE_TYPE);
    ev3_sensor_config(LEFT_COLOR, LEFT_COLOR_TYPE);
    ev3_sensor_config(RIGHT_COLOR, RIGHT_COLOR_TYPE);
    ev3_sensor_config(GYRO, GYRO_TYPE);
    ev3_gyro_sensor_reset(GYRO);
    ev3_sensor_config(GATE_COLOR, GATE_COLOR_TYPE);
}

void turn(int degree) {
    int8_t first = ev3_gyro_sensor_get_angle(GYRO);
    if (degree == first) return;
    if (degree > first) {
        ev3_motor_set_power(LEFT_MOTOR, 10);
        ev3_motor_set_power(RIGHT_MOTOR, -10);
        while (ev3_gyro_sensor_get_angle(GYRO) < degree) {}
        ev3_motor_stop(LEFT_MOTOR, true);
        ev3_motor_stop(RIGHT_MOTOR, true);
    }
    if (degree < first) {
        ev3_motor_set_power(LEFT_MOTOR, -10);
        ev3_motor_set_power(RIGHT_MOTOR, 10);
        while (ev3_gyro_sensor_get_angle(GYRO) > degree) {}
        ev3_motor_stop(LEFT_MOTOR, true);
        ev3_motor_stop(RIGHT_MOTOR, true);
    }
    tslp_tsk(1000);
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
    straight_deg((int)( ( ( (float)mm ) / (TIRE_RADIUS * PI)) * 360));
}