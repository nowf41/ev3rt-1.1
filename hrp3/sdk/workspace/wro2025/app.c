#include "ev3api.h"
#include "app.h"
#include "ports.h"

/// ロボットを指定した角度だけ回転させる。
/// @param degree 時計回りに何度回転するか。
/// @param speed 速度(0~100)
/// @return
void turn(int8_t degree, int8_t speed) {
    int degree_to_run_motor = TIRE_DISTANCE * degree / TIRE_RADIUS;

    ev3_motor_rotate(LEFT_MOTOR, degree_to_run_motor, speed, false);
    ev3_motor_rotate(RIGHT_MOTOR, -degree_to_run_motor, speed, true);
}

/// 左右のモーターを同期させて動かす。
/// @param dist 何mm前進するか。
/// @param speed 左右のモーターを動かす速度。(0~100)
/// @param facing trueで前進、falseで後退。
/// @return
void straight(int8_t dist, int8_t speed, bool_t facing) {
    int degree_to_run_motor = dist * 360 / (TIRE_RADIUS * PI);
    ev3_motor_rotate(LEFT_MOTOR, degree_to_run_motor, speed, false);
    ev3_motor_rotate(RIGHT_MOTOR, degree_to_run_motor, speed, true);
}

void main_task(intptr_t unused) {
    turn(90, 100);
}