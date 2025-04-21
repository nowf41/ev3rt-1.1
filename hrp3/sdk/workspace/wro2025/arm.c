#include "ev3api.h"
#include "app.h"
#include "ports.h"

// 320
void drop_full() {
    ev3_motor_rotate(CRANE, 300, 80, true);
    ev3_motor_set_power(CRANE, 30);
    tslp_tsk(1000);
    ev3_motor_stop(CRANE, false);
}

void raise_full() {
    ev3_motor_rotate(CRANE, -280, 100, true);
    ev3_motor_set_power(CRANE, -70);
    tslp_tsk(1000);
    ev3_motor_stop(CRANE, true);
}

void raise_deg(int deg_abs) {
    ev3_motor_rotate(CRANE, -deg_abs, 50, true);
}