#include "S32K144.h"
/* Define PORTS name*/

#define PTC0 0
#define PTC1 1
#define PTC2 2
#define PTC3 3
#define PTC4 4
#define PTC5 5
#define PTC6 6
#define PTC7 7
#define PTC8 8
#define PTC9 9
#define PTC10 10
#define PTC11 11
#define PTC12 12
#define PTC13 13
#define PTC14 14
#define PTC15 15
#define PTC16 16
#define PTC17 17


#define PTB0 0
#define PTB1 1
#define PTB2 2
#define PTB3 3
#define PTB4 4
#define PTB5 5
#define PTB6 6
#define PTB7 7
#define PTB8 8
#define PTB9 9
#define PTB10 10
#define PTB11 11
#define PTB12 12
#define PTB13 13
#define PTB14 14
#define PTB15 15
#define PTB16 16
#define PTB17 17


#define PTE0 0
#define PTE1 1
#define PTE2 2
#define PTE3 3
#define PTE4 4
#define PTE5 5
#define PTE6 6
#define PTE7 7
#define PTE8 8
#define PTE9 9
#define PTE10 10
#define PTE11 11
#define PTE12 12
#define PTE13 13
#define PTE14 14
#define PTE15 15
#define PTE16 16
#define PTE17 17


#define PTD0 0
#define PTD1 1
#define PTD2 2
#define PTD3 3
#define PTD4 4
#define PTD5 5
#define PTD6 6
#define PTD7 7
#define PTD8 8
#define PTD9 9
#define PTD10 10
#define PTD11 11
#define PTD12 12
#define PTD13 13
#define PTD14 14
#define PTD15 15
#define PTD16 16
#define PTD17 17

/* config out pins */

#define config_Pin_Out_PortB(numout) PTB->PDDR |= 1<<numout
#define config_Pin_Out_PortC(numout) PTC->PDDR |= 1<<numout
#define config_Pin_Out_PortD(numout) PTD->PDDR |= 1<<numout
#define config_Pin_Out_PortE(numout) PTE->PDDR |= 1<<numout


/* config int pins */

#define config_Pin_Int_PortB(numint) PTB->PDDR &= ~(1<<numint)
#define config_Pin_Int_PortC(numint) PTC->PDDR &= ~(1<<numint)
#define config_Pin_Int_PortD(numint) PTD->PDDR &= ~(1<<numint)
#define config_Pin_Int_PortE(numint) PTE->PDDR &= ~(1<<numint)

/* config mux pins */
#define config_Pin_Mux_PortB(nummux,muxconfig) PORTB->PCR[nummux] = muxconfig
#define config_Pin_Mux_PortC(nummux,muxconfig) PORTC->PCR[nummux] = muxconfig
#define config_Pin_Mux_PortD(nummux,muxconfig) PORTD->PCR[nummux] = muxconfig
#define config_Pin_Mux_PortE(nummux,muxconfig) PORTE->PCR[nummux] = muxconfig

/* get pin value*/
#define io_GetValue_Pin_PortB(numpin) PTB->PDIR & (1<<numpin)
#define io_GetValue_Pin_PortC(numpin) PTC->PDIR & (1<<numpin)
#define io_GetValue_Pin_PortD(numpin) PTD->PDIR & (1<<numpin)
#define io_GetValue_Pin_PortE(numpin) PTE->PDIR & (1<<numpin)

/* set pin */
#define io_Set_Pin_PortB(numset) PTB-> PSOR |= 1<<numset
#define io_Set_Pin_PortC(numset) PTC-> PSOR |= 1<<numset
#define io_Set_Pin_PortD(numset) PTD-> PSOR |= 1<<numset
#define io_Set_Pin_PortE(numset) PTE-> PSOR |= 1<<numset

/* clear pin */
#define io_Clear_Pin_PortB(numclear) PTB-> PCOR |= 1<<numclear
#define io_Clear_Pin_PortC(numclear) PTC-> PCOR |= 1<<numclear
#define io_Clear_Pin_PortD(numclear) PTD-> PCOR |= 1<<numclear
#define io_Clear_Pin_PortE(numclear) PTE-> PCOR |= 1<<numclear





