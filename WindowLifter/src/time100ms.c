#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "time100ms.h"


void EnableTimer1ms (void){

 LPIT0->TMR[0].TVAL = 40000; /* Chan 0 Timeout period: clocks */ //1 segundo es 40000000 POR LO QUE 1 ms es 40000
 LPIT0->TMR[0].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled 0x00000001 */

}

void DisableTimer1ms (void){

LPIT0->TMR[0].TCTRL = 0x00000000; /* T_EN=1: Timer channel is Disabled 0x00000000 */

}
