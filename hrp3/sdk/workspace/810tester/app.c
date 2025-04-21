#include "ev3api.h"
#include "app.h"

int now = 0;

void main_screen() {
    int v;
    ev3_font_get_size(EV3_FONT_MEDIUM, null, &v);
    char s[30];
    sprintf(s, "batt: %dmV; %dmA", ev3_battery_voltage_mV(), ev3_battery_current_mA())
    ev3_lcd_draw_string(s, 0, 0);
}

void main_task(intptr_t unused) {
    ev3_lcd_set_font(EV3_FONT_MEDIUM);
}

