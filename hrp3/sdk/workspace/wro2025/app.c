#include "ev3api.h"
#include "app.h"
#include "ports.h"

void main_task(intptr_t unused) {
    init_ports();

    turn(-45);
    straight_mm(360);
    turn(-85);
    drop_full();
    straight_mm(300);
    straight_until_left_black(1);
    straight_mm(150);
    turn(-180);
    
}

int port_flags = 0;

// Todo handle error
void init_ports() {
    ev3_sensor_config(GYRO, GYRO_TYPE);
    ev3_gyro_sensor_reset(GYRO);
    port_flags |= 1 << GYRO_FLAG_DIG;

    ev3_motor_config(LEFT_MOTOR, LEFT_MOTOR_TYPE);
    port_flags |= 1 << LEFT_MOTOR_FLAG_DIG;
    
    ev3_motor_config(RIGHT_MOTOR, RIGHT_MOTOR_TYPE);
    port_flags |= 1 << RIGHT_MOTOR_FLAG_DIG;

    ev3_motor_config(FINGER, FINGER_TYPE);
    port_flags |= 1 << FINGER_FLAG_DIG;
    
    ev3_motor_config(CRANE, CRANE_TYPE);
    port_flags |= 1 << CRANE_FLAG_DIG;
    
    ev3_sensor_config(LEFT_COLOR, LEFT_COLOR_TYPE);
    port_flags |= 1 << LEFT_COLOR_FLAG_DIG;
    
    ev3_sensor_config(RIGHT_COLOR, RIGHT_COLOR_TYPE);
    port_flags |= 1 << RIGHT_COLOR_FLAG_DIG;
    
    ev3_sensor_config(GATE_COLOR, GATE_COLOR_TYPE);
    port_flags |= 1 << GYRO_FLAG_DIG;
}

void require_port(int flag_dig) {
    while ((port_flags & 1 << flag_dig) == 0) {
        tslp_tsk(100);
    }
    return;
}
