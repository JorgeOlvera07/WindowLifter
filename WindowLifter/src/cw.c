
#include "cw.h"




void ControlWindowUp (unsigned char * percent){

switch ((*percent)){

case 1: PTC-> PSOR |= 1<<7; /* clear Output on port D16 (on) */   break;
case 2: io_Set_Pin_PortB(WINDOW_LED2); /* clear Output on port D16 (on) */   break;
case 3: io_Set_Pin_PortB(WINDOW_LED3); /* clear Output on port D16 (on) */   break;
case 4: io_Set_Pin_PortB(WINDOW_LED4); /* clear Output on port D16 (on) */   break;
case 5: io_Set_Pin_PortB(WINDOW_LED5); /* clear Output on port D16 (on) */   break;
case 6: io_Set_Pin_PortC(WINDOW_LED6); /* clear Output on port D16 (on) */   break;
case 7: io_Set_Pin_PortE(WINDOW_LED7); /* clear Output on port D16 (on) */  break;
case 8: io_Set_Pin_PortE(WINDOW_LED8); /* clear Output on port D16 (on) */  break;
case 9: io_Set_Pin_PortE(WINDOW_LED9); /* clear Output on port D16 (on) */  break;
case 10: io_Set_Pin_PortE(WINDOW_LED10); /* clear Output on port D16 (on) */  break;
default: if(*percent>10) {*percent=10;}
         if(*percent<1)  {*percent=1; } break;

}



}


void ControlWindowDown (unsigned char * percent){

switch ((*percent)){

case 1: io_Clear_Pin_PortC(WINDOW_LED1); /* set Output on port D16 (off) */   break;
case 2: io_Clear_Pin_PortB(WINDOW_LED2); /* set Output on port D16 (off) */   break;
case 3: io_Clear_Pin_PortB(WINDOW_LED3); /* set Output on port D16 (off) */   break;
case 4: io_Clear_Pin_PortB(WINDOW_LED4); /* set Output on port D16 (off) */   break;
case 5: io_Clear_Pin_PortB(WINDOW_LED5); /* set Output on port D16 (off) */   break;
case 6: io_Clear_Pin_PortC(WINDOW_LED6); /* set Output on port D16 (off) */   break;
case 7: io_Clear_Pin_PortE(WINDOW_LED7); /* set Output on port D16 (off) */  break;
case 8: io_Clear_Pin_PortE(WINDOW_LED8); /* set Output on port D16 (off) */  break;
case 9: io_Clear_Pin_PortE(WINDOW_LED9); /* set Output on port D16 (off) */  break;
case 10: io_Clear_Pin_PortE(WINDOW_LED10); /* set Output on port D16 (off) */  break;
default: if(*percent>10) {*percent=10;}
         if(*percent<1)  {*percent=1; } break;

}


}
