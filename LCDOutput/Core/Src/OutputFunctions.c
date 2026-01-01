/*
 * OutputFunctions.c
 *
 *  Created on: Dec 24, 2025
 *      Author: Noah Silat
 */

//Functions responsible for initializing the LCD as well as outputting to it with adequate formatting (i.e. correct positioning
// and output.)

#include "OutputFunctions.h"



void sendCommand(char command){

// our I2C module functions in 4 bit addressing mode, so we need to break the 8 bit command into 4 bit upper and lower:
//derived from datasheets and open source contributions
char upper;
char lower;

upper = command&0xF0;
lower = ((command&0x0F)<<4); //getting the rest of the command in first 4 bits

uint8_t DataToSend[4]; //we will send both upper and lower twice, with the only difference being P2 high and low to indicate data start/stop

DataToSend[0] = (upper|0x0C); // P3 = 1 -> backlight on ; P2 = 1 data start
DataToSend[1] = (upper|0x08); // P3 = 1 -> backlight on ; P2 = 0 data stop
DataToSend[2] = (lower|0x0C);
DataToSend[3] = (lower|0x08);

HAL_I2C_Master_Transmit(&hi2c1, (DEVICE_ADDR<<1), (DataToSend), 4, 200);
}

void initializeLCD(void){ //send commands following a specific order according to the datasheet to initialize our LCD to display characters/numbers
//derived from datasheets and open source contributions

//4 Bit Initialization
	HAL_Delay(10);
	sendCommand(0x30); // restart display 3 time
	HAL_Delay(10);
	sendCommand(0x30);
	HAL_Delay(10);
	sendCommand(0x30);
	HAL_Delay(10);
	sendCommand(0x20);


//Display Initialization
	HAL_Delay(5);
	sendCommand(0x28); // 4 bit mode, 2 line display, 5x8 characters
	HAL_Delay(5);
	sendCommand(0x08); // Display on/off -> all zeroes, so off
	HAL_Delay(5);
	sendCommand(0x01); // clear display
	HAL_Delay(5);
	sendCommand(0x06); // set entry mode, s = 0 (no shift)
	HAL_Delay(5);
	sendCommand(0x0F); // Display on/off, D = 1, display on, C and B = 0 (cursor and blink = 0)

}

void outputChar(char character){
	//the exact same method as sendCommand, except P0 = 1 for data transfer
	//our I2C module functions in 4 bit addressing mode, so we need to break the 8 bit command into 4 bit upper and lower:
	//derived from datasheets and open source contributions
	char upper;
	char lower;

	upper = character&0xF0;
	lower = ((character&0x0F)<<4); //getting the rest of the command in first 4 bits

	uint8_t DataToSend[4]; //we will send both upper and lower twice, with the only difference being P2 high and low to indicate data start/stop

	DataToSend[0] = (upper|0x0D); // P3 = 1 -> backlight on ; P2 = 1 data start
	DataToSend[1] = (upper|0x09); // P3 = 1 -> backlight on ; P2 = 0 data stop
	DataToSend[2] = (lower|0x0D);
	DataToSend[3] = (lower|0x09);

	HAL_I2C_Master_Transmit(&hi2c1, (DEVICE_ADDR<<1), (DataToSend), 4, 200);

}






