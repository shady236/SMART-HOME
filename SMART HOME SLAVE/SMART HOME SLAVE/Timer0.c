
#include "Timer0.h"

#if   TIMER0_MODE == TIMER_NORMAL_MODE
	uint32 Timer0_numOfOverFlows = 0;
	uint8  Timer0_overFlowMode_intialValue = 0;
#elif TIMER0_MODE == TIMER_CTC_MODE
	uint32 Timer0_numOfCompareMatches = 0;
	uint8  Timer0_CTCMode_initialValue = 0;
#endif


void (*volatile Timer0Function)(void);


void Timer0_init()
{
	#if   TIMER0_MODE == TIMER_NORMAL_MODE
		CLR_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);
	#elif TIMER0_MODE == TIMER_CTC_MODE
		SET_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);
	#elif TIMER0_MODE == TIMER_PHASE_CORRECT_PWM_MODE
		CLR_BIT(TCCR0, 3);
		SET_BIT(TCCR0, 6);
	#elif TIMER0_MODE == TIMER_FAST_PWM_MODE
		SET_BIT(TCCR0, 3);
		SET_BIT(TCCR0, 6);
	#endif
	
	#if   TIMER0_WAVE_GENERATION_MODE == TIMER_WAVE_GENERATION_DISABLE
		CLR_BIT(TCCR0, 4);
		CLR_BIT(TCCR0, 5);
	#elif TIMER0_WAVE_GENERATION_MODE == TIMER_WAVE_GENERATION_TOGGLE_ON_COMPARE_MATCH
		SET_BIT(TCCR0, 4);
		CLR_BIT(TCCR0, 5);
		SET_BIT(DDRB, 3);
	#elif TIMER0_WAVE_GENERATION_MODE == TIMER_WAVE_GENERATION_CLEAR_ON_COMPARE_MATCH
		CLR_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
		SET_BIT(DDRB, 3);
	#elif TIMER0_WAVE_GENERATION_MODE == TIMER_WAVE_GENERATION_SET_ON_COMPARE_MATCH
		SET_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
		SET_BIT(DDRB, 3);
	#endif
	
	#if   TIMER0_OVERFLOW_INTERRUPT_MODE == TIMER_OVERFLOW_INTERRUPT_ENABLE
		SET_BIT(SREG, 7);
		SET_BIT(TIMSK, 0);
	#elif TIMER0_OVERFLOW_INTERRUPT_MODE == TIMER_OVERFLOW_INTERRUPT_DISABLE
		CLR_BIT(TIMSK, 0);
	#endif
	
	
	#if   TIMER0_COMPARE_MATCH_INTERRUPT_MODE == TIMER_COMPARE_MATCH_INTERRUPT_ENABLE
		SET_BIT(SREG, 7);
		SET_BIT(TIMSK, 1);
	#elif TIMER0_COMPARE_MATCH_INTERRUPT_MODE == TIMER_COMPARE_MATCH_INTERRUPT_DISABLE
		CLR_BIT(TIMSK, 1);
	#endif
}

void Timer0_start()
{
	#if   TIMER0_PRESCALER == TIMER_NO_PRESCALER
		SET_BIT(TCCR0, 0);
		CLR_BIT(TCCR0, 1);
		CLR_BIT(TCCR0, 2);
	#elif TIMER0_PRESCALER == TIMER_PRESCALER_8
		CLR_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		CLR_BIT(TCCR0, 2);
	#elif TIMER0_PRESCALER == TIMER_PRESCALER_64
		SET_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		CLR_BIT(TCCR0, 2);
	#elif TIMER0_PRESCALER == TIMER_PRESCALER_256
		CLR_BIT(TCCR0, 0);
		CLR_BIT(TCCR0, 1);
		SET_BIT(TCCR0, 2);
	#elif TIMER0_PRESCALER == TIMER_PRESCALER_1024
		SET_BIT(TCCR0, 0);
		CLR_BIT(TCCR0, 1);
		SET_BIT(TCCR0, 2);
	#endif
}

void Timer0_stop()
{
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);
}

void Timer0_delay_ms(uint32 requiredDelay_ms, void (*p2Timer0Function)(void))
{
	Timer0Function = p2Timer0Function;
	
	#if   TIMER0_MODE == TIMER_NORMAL_MODE
		#if   TIMER0_PRESCALER > F_OSC_MHZ
			uint8 tickTimeMicroSec = TIMER0_PRESCALER / F_OSC_MHZ;
			uint32 requiredTickes = requiredDelay_ms*1000 / tickTimeMicroSec;
		#elif TIMER0_PRESCALER < F_OSC_MHZ
			uint16 tickTimeNanoSec = TIMER0_PRESCALER*1000 / F_OSC_MHZ;
			uint32 requiredTickes = requiredDelay_ms*1000000 / tickTimeNanoSec;
		#endif
	
		Timer0_numOfOverFlows = requiredTickes/TIMER0_MAX_TICKS;
		Timer0_overFlowMode_intialValue = TIMER0_MAX_TICKS - requiredTickes%TIMER0_MAX_TICKS;
	
		TCNT0 = Timer0_overFlowMode_intialValue;
		
		if(requiredTickes%TIMER0_MAX_TICKS != 0)
		{
			Timer0_numOfOverFlows++;
		}
		
		
	#elif TIMER0_MODE == TIMER_CTC_MODE
		#if   TIMER0_PRESCALER > F_OSC_MHZ
			uint8 tickTimeMicroSec = TIMER0_PRESCALER / F_OSC_MHZ;
			uint32 requiredTickes = requiredDelay_ms*1000 / tickTimeMicroSec;
		#elif TIMER0_PRESCALER < F_OSC_MHZ
			uint16 tickTimeNanoSec = TIMER0_PRESCALER*1000 / F_OSC_MHZ;
			uint32 requiredTickes = requiredDelay_ms*1000000 / tickTimeNanoSec;
		#endif
		
		Timer0_numOfCompareMatches = requiredTickes/TIMER0_MAX_TICKS;
		Timer0_CTCMode_initialValue = requiredTickes%TIMER0_MAX_TICKS;
		
		OCR0 = Timer0_CTCMode_initialValue;
		if(requiredTickes%TIMER0_MAX_TICKS != 0)
		{
			Timer0_numOfCompareMatches++;
		}
		
	#endif
}


#if  TIMER0_OVERFLOW_INTERRUPT_MODE == TIMER_OVERFLOW_INTERRUPT_ENABLE
ISR(TIMER0_OVF_vect)
{
	static uint32 counter = 0;
	counter++;
	
	if(counter == Timer0_numOfOverFlows)
	{
		Timer0Function();
		counter = 0;
		TCNT0 = Timer0_overFlowMode_intialValue;
	}
}
#endif


#if TIMER0_COMPARE_MATCH_INTERRUPT_MODE == TIMER_COMPARE_MATCH_INTERRUPT_ENABLE
ISR(TIMER0_COMP_vect)
{
	static uint32 counter = 0;
	counter++;
	
	if(counter == Timer0_numOfCompareMatches)
	{
		Timer0Function();
		counter = 0;
		OCR0 = Timer0_CTCMode_initialValue;
	}
	else if(counter == 1)
	{
		OCR0 = TIMER0_MAX_TICKS-1;
	}
}
#endif