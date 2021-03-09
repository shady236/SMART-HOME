
#ifndef TIMER0_H_
#define TIMER0_H_


#include "ATmega32_Registers.h"
#include "BIT_Math.h"
#include "Timer0Config.h"
#include <avr/interrupt.h>

#define TIMER_NORMAL_MODE								0
#define TIMER_CTC_MODE									1
#define TIMER_FAST_PWM_MODE								2
#define TIMER_PHASE_CORRECT_PWM_MODE					3

#define TIMER_WAVE_GENERATION_DISABLE					0
#define TIMER_WAVE_GENERATION_TOGGLE_ON_COMPARE_MATCH	1
#define TIMER_WAVE_GENERATION_CLEAR_ON_COMPARE_MATCH	2
#define TIMER_WAVE_GENERATION_SET_ON_COMPARE_MATCH		3

#define TIMER_NO_PRESCALER								1
#define TIMER_PRESCALER_8								8
#define TIMER_PRESCALER_64								64
#define TIMER_PRESCALER_256								256
#define TIMER_PRESCALER_1024							1024

#define TIMER_OVERFLOW_INTERRUPT_DISABLE				0
#define TIMER_OVERFLOW_INTERRUPT_ENABLE					1

#define TIMER_COMPARE_MATCH_INTERRUPT_DISABLE			0
#define TIMER_COMPARE_MATCH_INTERRUPT_ENABLE			1



void Timer0_init();
void Timer0_start();
void Timer0_stop();
void Timer0_delay_ms(uint32 requiredDelay_ms, void (*p2Timer0Function)(void));


#endif /* TIMER_H_ */