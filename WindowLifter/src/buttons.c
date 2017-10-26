#include "HAL/buttons.h"

void config_Buttons_PortC(unsigned char num){


config_Pin_Int_PortC(num);
config_Pin_Mux_PortC(num,0x00000110);  //0x00000110 0xC0110


}

unsigned char get_Button_Value(unsigned char num){

	if (io_GetValue_Pin_PortC(num)) {return 1;}
	else {return 0;}

}
