#include <avr/io.h>

#include "utility.h"

#include "utility.c"

#define F_CPU 16000000
#include <util/delay.h>

#include "SetPins.h"

#include "InitializeRows.h"

#include "Display.h"

#define DELAY_TIME 100

uint8_t identifyColumn();
uint8_t identifyRow();
void readColumnandRowPins();

uint8_t rowPin;
uint8_t ColumnPin;

int main(void) {

	   setPinsAndPorts();  //PORTA and PORTC are set
	   initializeRows();  //Rows are set to low.
	while (1) {

		
		ColumnPin = identifyColumn();
		rowPin = identifyRow();
		initializeRows();
		display(rowPin, ColumnPin);
		_delay_ms(DELAY_TIME);
	}
}

uint8_t identifyColumn() {
	for (uint8_t i = 0; i < 4; i++) {
		if (!gpio_read_pin(PORTC_ID, i)) {  //if pressed
			_delay_ms(DELAY_TIME); //debouncing
			if (gpio_read_pin(PORTC_ID,i))  //check again
			{
				return i;
			}
			    //finding out which pin
		}
	}
	return ColumnPin;
}


uint8_t identifyRow() {
	uint8_t columnPressed = identifyColumn(); // Identify the pressed column directly
	
	if (columnPressed != 0xFF) { // Check if a column is pressed
		for (uint8_t i = 4; i < 8; i++) {
			setRowsHigh(); // All set to high
			gpio_clear_pin(PORTC_ID, i); // One at a time set to low
			if (!gpio_read_pin(PORTC_ID, i) && (i - 4 == columnPressed)) {
				return i - 4; // Return the row number
			}
		}
	}
	return rowPin; // Default value when no key is pressed
}
