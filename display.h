#ifndef DISPLAY_H
#define DISPLAY_H


void display(uint8_t row, uint8_t column){
	if (row==0  && column == 0)   //1
	{
		PORTA = 0x06;
	}else if (row==0  && column == 1) //2
	{
		PORTA = 0x5B;
	}else if (row==0  && column == 2) //3
	{
		PORTA = 0x4F;
	}else if (row==0  && column == 3)  //A
	{
		PORTA = 0x77;
	}
	if (row==1  && column == 0) //4
	{
		PORTA = 0x66;
	}else if (row==1  && column == 1) //5
	{
		PORTA = 0x6D;
	}else if (row==1  && column == 2)  //6
	{
		PORTA = 0x7D;
	}else if (row==1  && column == 3) //B
	{
		PORTA = 0x7C;
	}
	if (row==2  && column == 0) //7
	{
		PORTA = 0x07;
	}else if (row==2  && column == 1) //8
	{
		PORTA = 0x7F;
	}else if (row==2  && column == 2) //9
	{
		PORTA = 0x6F;
	}else if (row==2  && column == 3)  //C
	{
		PORTA = 0x39;
	}
	if (row==3  && column == 0)  //*
	{
		PORTA = 0x1B;
	}else if (row==3  && column == 1) //0
	{
		PORTA = 0x3F;
	}else if (row==3  && column == 2) //#
	{
		PORTA = 0x76;
	}else if (row==3  && column == 3)  //D
	{
		PORTA = 0x5E;
	}
}
#endif
