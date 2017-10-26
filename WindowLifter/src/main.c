#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "HAL/buttons.h"
#include "HAL/windowleds.h"
#include "APP/initproyect.h"
#include "clocks_and_modes.h"
#include "time100ms.h"
#include "cw.h"




int lpit0_ch0_flag_counter1ms = 0; /* LPIT0 chan 0 timeout counter */
unsigned char percentwindow=0;
unsigned char flagwindowUp=0;
unsigned char flagwindowDown=0;
unsigned char flagOneTouchUp=0;
unsigned char flagOneTouchDown=0;



void WDOG_disable (void){
 WDOG->CNT=0xD928C520; /*Unlock watchdog*/
 WDOG->TOVAL=0x0000FFFF; /*Maximum timeout value*/
 WDOG->CS = 0x00002100; /*Disable watchdog*/
}

int main(void) {
 WDOG_disable();
 SOSC_init_8MHz(); /* Initialize system oscillator for 8 MHz xtal */
 SPLL_init_160MHz(); /* Initialize SPLL to 160 MHz with 8 MHz SOSC */
 NormalRUNmode_80MHz(); /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
 NVIC_init_IRQs(); /* Enable desired interrupts and priorities */
 LPIT0_init(); /* Initialize PIT0*/
 EnablePCC ();
 WindowInit ();
 IndicatorsInit();
 ButtonsInit ();



 for (;;) {

	 if ( (get_Button_Value(UP_Button) ^ get_Button_Value(DOWN_Button)) ) {

		 EnableTimer1ms ();

		 while( (get_Button_Value(UP_Button) ^ get_Button_Value(DOWN_Button))|| (flagwindowDown==255)||(flagwindowUp==255) ){


		 if( ((lpit0_ch0_flag_counter1ms>=_1000ms)&&get_Button_Value(UP_Button)) || (flagwindowUp==255)){  /* valid button press up */
			 PTD-> PCOR |= 1<<PTD0; /* Clear Output on port D0 (on) */
			 PTD-> PSOR |= 1<<PTD16; /* Set Output on port D16 (off) */


				 if ( ((lpit0_ch0_flag_counter1ms<_3000ms)&&get_Button_Value(UP_Button))|| (flagwindowUp==255) ){ /* one touch  up*/
					 flagOneTouchUp=1;

					 while(get_Button_Value(UP_Button)){   if((lpit0_ch0_flag_counter1ms>_3000ms)){flagwindowUp=0;DisableTimer1ms ();lpit0_ch0_flag_counter1ms=0; flagOneTouchUp=0;} } /* semiautomatic up */

					 if (flagOneTouchUp){  /* one touch  up*/

					 flagwindowUp=0;
					 DisableTimer1ms ();
					 lpit0_ch0_flag_counter1ms=0;


					 EnableTimer1ms ();

					 while(percentwindow<10){

						 if(lpit0_ch0_flag_counter1ms>=_1000ms) {DisableTimer1ms (); lpit0_ch0_flag_counter1ms=0; percentwindow++; ControlWindowUp (&percentwindow); EnableTimer1ms ();}
						 else if(get_Button_Value(DOWN_Button)){
							 DisableTimer1ms ();
							 lpit0_ch0_flag_counter1ms=0;
							 EnableTimer1ms ();

							 while(get_Button_Value(DOWN_Button)){if((lpit0_ch0_flag_counter1ms>=_1000ms)&&get_Button_Value(DOWN_Button)){flagwindowDown=255;PTD-> PCOR |= 1<<PTD16; PTD-> PSOR |= 1<<PTD0;break;} }
						 }

						 if(flagwindowDown==255){break;}


					 }

					 } /* one touch  up*/

				 } /* one touch  up*/


		         }  /* valid button press up */

		 if( ((lpit0_ch0_flag_counter1ms>=_1000ms)&&get_Button_Value(DOWN_Button)) || (flagwindowDown==255)){/* valid button press down */
		 		PTD-> PCOR |= 1<<PTD16; /* Clear Output on port D16 (on) */
		 		PTD-> PSOR |= 1<<PTD0; /* Set Output on port D0 (off) */


					 if ( ((lpit0_ch0_flag_counter1ms<_3000ms)&&get_Button_Value(DOWN_Button))|| (flagwindowDown==255) ) { /* one touch  down*/

						 flagOneTouchDown=1;

						 while(get_Button_Value(DOWN_Button)){   if((lpit0_ch0_flag_counter1ms>_3000ms)){flagwindowDown=0;DisableTimer1ms ();lpit0_ch0_flag_counter1ms=0; flagOneTouchDown=0;} } /* semiautomatic up */

						 if (flagOneTouchDown){  /* one touch  down*/


						    flagwindowDown=0;
					 		DisableTimer1ms ();
					 		lpit0_ch0_flag_counter1ms=0;



					 		EnableTimer1ms ();

					 		while(percentwindow>=1){

					 			if(lpit0_ch0_flag_counter1ms>=_1000ms) {DisableTimer1ms (); lpit0_ch0_flag_counter1ms=0; ControlWindowDown (&percentwindow);  percentwindow--; EnableTimer1ms ();}
								 else if(get_Button_Value(UP_Button)){
									 DisableTimer1ms ();
									 lpit0_ch0_flag_counter1ms=0;
									 EnableTimer1ms ();

									 while(get_Button_Value(UP_Button)){if((lpit0_ch0_flag_counter1ms>=_1000ms)&&get_Button_Value(UP_Button)){flagwindowUp=255;PTD-> PCOR |= 1<<PTD0; PTD-> PSOR |= 1<<PTD16;break;} }
								 }

								 if(flagwindowUp==255){break;}
					 		}

						 }/* one touch  down*/

					 }/* one touch  down*/

		 		 } /* valid button pres down */
		 }

	 }
	 else { /* If BTN0 was not pushed */
	 PTD-> PSOR |= 1<<PTD0; /* Set Output on port D0 (off) */
	 PTD-> PSOR |= 1<<PTD16; /* Set Output on port D16 (off) */
	 DisableTimer1ms ();
	 lpit0_ch0_flag_counter1ms=0;






	 }

 }
}

void LPIT0_Ch0_IRQHandler (void) {
	lpit0_ch0_flag_counter1ms++; /* Increment LPIT0 timeout counter */

 LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
}


void PORTE_IRQHandler (void) {
	PTD-> PCOR |= 1<<PTD0; PTD-> PSOR |= 1<<PTD16;
	PORTE->ISFR=PORT_ISFR_ISF_MASK;

}



