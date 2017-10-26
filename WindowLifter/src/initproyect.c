#include "APP/initproyect.h"

void EnablePCC (void){

 PCC-> PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT B */
 PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT C */
 PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
 PCC-> PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT E */

}

void NVIC_init_IRQs (void) {
 S32_NVIC->ICPR[1] = 1 << (48 % 32); /* IRQ48-LPIT0 ch0: clr any pending IRQ*/
 S32_NVIC->ISER[1] = 1 << (48 % 32); /* IRQ48-LPIT0 ch0: enable IRQ */
 S32_NVIC->IP[48] =0x0A; /* IRQ48-LPIT0 ch0: priority 10 of 0-15*/


 S32_NVIC->ICPR[1] = 1 << (63 % 32); /* IRQ48-LPIT0 ch0: clr any pending IRQ*/
 S32_NVIC->ISER[1] = 1 << (63 % 32); /* IRQ48-LPIT0 ch0: enable IRQ */
 S32_NVIC->IP[63] =0x0C; /* IRQ48-LPIT0 ch0: priority 10 of 0-15*/

}



void WindowInit (void){

config_Led_Port(C,WINDOW_LED1);
config_Led_Port(B,WINDOW_LED2);
config_Led_Port(B,WINDOW_LED3);
config_Led_Port(B,WINDOW_LED4);
config_Led_Port(B,WINDOW_LED5);
config_Led_Port(C,WINDOW_LED6);
config_Led_Port(E,WINDOW_LED7);
config_Led_Port(E,WINDOW_LED8);
config_Led_Port(E,WINDOW_LED9);
config_Led_Port(E,WINDOW_LED10);


}


void IndicatorsInit (void){
 PTD->PDDR |= 1<<PTD0; /* Port D0: Data Direction= output */
 PTD->PDDR |= 1<<PTD16; /* Port D16: Data Direction= output */
 PORTD->PCR[PTD0] = 0x00000100; /* Port D0: MUX , GPIO  */
 PORTD->PCR[PTD16] = 0x00000100; /* Port D0: MUX , GPIO  */

 PTD->PSOR |= 1<<PTD0; /* clear pin */
 PTD->PSOR |= 1<<PTD16; /* clear pin */
}

void ButtonsInit (void){
config_Buttons_PortC(UP_Button);
config_Buttons_PortC(DOWN_Button);
 
PTE->PDDR &= ~(1<<1);
PORTE->PCR[1]= 0x10C0110;
}


void LPIT0_init (void) {
 PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6); /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
 PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
 LPIT0->MCR = 0x00000001; /* DBG_EN-0: Timer chans stop in Debug mode */
 /* DOZE_EN=0: Timer chans are stopped in DOZE mode */
/* SW_RST=0: SW reset does not reset timer chans, regs */
 /* M_CEN=1: enable module clk (allow writing other LPIT0 regs) */
 LPIT0->MIER = 0x00000001; /* TIE0=1: Timer Interrupt Enabled fot Chan 0 */
// LPIT0->TMR[0].TVAL = 40000;; /* Chan 0 Timeout period: clocks */ //1000ms es 40000000 por lo que 1ms es 40000;
// LPIT0->TMR[0].TCTRL = 0x00000000; /* T_EN=1: Timer channel is enabled 0x00000001 */
 /* CHAIN=0: channel chaining is disabled */
/* MODE=0: 32 periodic counter mode */
/* TSOT=0: Timer decrements immediately based on restart */
/* TSOI=0: Timer does not stop after timeout */
/* TROT=0 Timer will not reload on trigger */
/* TRG_SRC=0: External trigger source */
/* TRG_SEL=0: Timer chan 0 trigger source is selected*/
}
