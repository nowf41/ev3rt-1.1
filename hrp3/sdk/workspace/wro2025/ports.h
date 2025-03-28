#ifndef PORTS_H
#define PORTS_H

// === PORTS ===
#define LEFT_MOTOR EV3_PORT_A
#define RIGHT_MOTOR EV3_PORT_B
#define CRANE EV3_PORT_C
#define FINGER EV3_PORT_D

#define LEFT_MOTOR_TYPE LARGE_MOTOR
#define RIGHT_MOTOR_TYPE LARGE_MOTOR
#define CRANE_TYPE LARGE_MOTOR
#define FINGER_TYPE MEDIUM_MOTOR

#define LEFT_COLOR EV3_PORT_1
#define RIGHT_COLOR EV3_PORT_2
#define GATE_COLOR EV3_PORT_3
#define GYRO EV3_PORT_4

#define LEFT_COLOR_TYPE COLOR_SENSOR
#define RIGHT_COLOR_TYPE COLOR_SENSOR
#define GATE_COLOR_TYPE COLOR_SENSOR
#define GYRO_TYPE GYRO_SENSOR

// ===MACHINE INFORMATION===
#define TIRE_RADIUS 22. // 直径。milli meter (float)
#define TIRE_DISTANCE 100. // milli meter (float)

// === CONTROL CONSTANTS ===
#define P_GAIN 1.0 // float

// === GENERAL ===
#define PI 3.14 // float

#endif /* PORTS_H */
