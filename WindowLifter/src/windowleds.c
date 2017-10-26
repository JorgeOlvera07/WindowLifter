#include "HAL/windowleds.h"

void config_Led_Port(unsigned char port,unsigned char num){
	
	switch(port){
	case 0: config_Pin_Out_PortB(num); config_Pin_Mux_PortB(num,0x00000100); break;
	case 1: config_Pin_Out_PortC(num); config_Pin_Mux_PortC(num,0x00000100); break;
	case 2: config_Pin_Out_PortD(num); config_Pin_Mux_PortD(num,0x00000100); break;
	case 3: config_Pin_Out_PortE(num); config_Pin_Mux_PortE(num,0x00000100); break;
	default: break;
	
	}
	
}