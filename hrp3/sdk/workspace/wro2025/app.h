#include "target_test.h"

#define MAIN_PRIORITY 5

#define HIGH_PRIORITY 9
#define MID_PRIORITY 10
#define LOW_PRIORITY 11

#ifndef STACK_SIZE
#define	STACK_SIZE 4096
#endif

#ifndef LOOP_REF
#define LOOP_REF ULONG_C(1000000)
#endif

#ifndef TOPPERS_MACRO_ONLY
extern void	main_task(intptr_t exinf);
void init_ports();
void turn(int degree);
void straight_deg(int degree);
void straight_mm(int mm);
#endif