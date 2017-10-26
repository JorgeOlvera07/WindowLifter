#include "MAL/gpio.h"



#define UP_Button PTC12
#define DOWN_Button PTC13

void config_Buttons_PortC(unsigned char num);
unsigned char get_Button_Value(unsigned char num);
