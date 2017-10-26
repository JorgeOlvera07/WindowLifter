#include "MAL/gpio.h"

#define WINDOW_LED1 PTC7 
#define WINDOW_LED2 PTB17 
#define WINDOW_LED3 PTB14 
#define WINDOW_LED4 PTB15 
#define WINDOW_LED5 PTB16 
#define WINDOW_LED6 PTC3 
#define WINDOW_LED7 PTE16 
#define WINDOW_LED8 PTE15 
#define WINDOW_LED9 PTE14 
#define WINDOW_LED10 PTE13 

#define B 0
#define C 1
#define D 2
#define E 3



#define UP_Indicator PTD0 // Blue Led indicator UP
#define DOWN_Indicator PTD16 // Green Led indicator DOWN

void config_Led_Port(unsigned char port,unsigned char num);
