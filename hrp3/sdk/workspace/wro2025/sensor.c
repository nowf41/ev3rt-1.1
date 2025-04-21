#include "ev3api.h"
#include "app.h"
#include "ports.h"

int is_black(int port) {
    int val = ev3_color_sensor_get_reflect(port);
    return val >= 40 ? 1 : 0;
}