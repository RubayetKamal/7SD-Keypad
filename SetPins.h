#ifndef SET_PINS_H
#define SET_PINS_H



void setPinsAndPorts(void){
	for(uint8_t i = 0;i<8;i++){
		gpio_set_pin_mode(PORTA_ID,i,PIN_MODE_OUTPUT);  //PortA set as output
	}
	for(uint8_t i = 0;i<4;i++){  //column pins as input 
		gpio_set_pin_mode(PORTC_ID,i,PIN_MODE_INPUT);  //pulled up resistors
	}
	for(uint8_t i = 4;i<8;i++){ //row pins set as output
		gpio_set_pin_mode(PORTC_ID,i,PIN_MODE_OUTPUT);
	}

}
#endif
