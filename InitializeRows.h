#ifndef INITIALIZE_ROWS_H
#define INITIALIZE_ROWS_H



void initializeRows(void){
	for(uint8_t i = 4;i<8;i++){  //Initialized Rows to Low
		gpio_clear_pin(PORTC_ID,i);
	}
}

void setRowsHigh(){
	for(uint8_t i = 4;i<8;i++){
		gpio_set_pin(PORTC_ID,i);
	}
}
#endif
