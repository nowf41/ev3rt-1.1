#include "ev3api.h"
#include "app.h"
#include "ports.h"

int min(int a, int b) { if (a > b) { return b; } else { return a; } }
int max(int a, int b) { if (a > b) { return a; } else { return b; } }
int abs(int a) { if (a >= 0) { return a; } else { return -a; } }
int mid(int a, int b, int c) {if (a>=b&&b>=c){return b;}if (a>=c&&c>=b){return c;}if (b>=a&&a>=c){return a;}if (b>=c&&c>=a){return c;}if (c>=a&&a>=b){return a;}if (c>=b&&b>=a){return b;}return 0;}

void main_task(intptr_t unused) {
    
}