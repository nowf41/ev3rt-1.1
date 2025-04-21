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

// app.c
extern void	main_task(intptr_t exinf);
extern void doInit(intptr_t exinf);
void init_ports();
void require_port(int flag_dig);

// moves.c
void turn(int degree);
void straight_deg(int degree);
void straight_mm(int mm);
void straight_ms(int ms);
void straight_until_left_black();
void trace_until_left_black();

// arm.c
void raise_full();
void raise_deg(int abs_deg);
void drop_full();

#endif