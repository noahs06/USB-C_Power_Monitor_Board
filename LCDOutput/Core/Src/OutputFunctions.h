/*
 * OutputFunctions.h
 *
 *  Created on: Dec 24, 2025
 *      Author: Noah Silat
 */

#ifndef SRC_OUTPUTFUNCTIONS_H_
#define SRC_OUTPUTFUNCTIONS_H_

#define DEVICE_ADDR 0x27


// Functions here will be responsible for initializing the LCD as well as outputting to it with adequate formatting (i.e. correct positioning
// and output.

void sendCommand(char cmd);
void initializeLCD(void);
void outputWords(char* words);
void outputNums(uint32_t nums);
void outputChars(char character);

#endif /* SRC_OUTPUTFUNCTIONS_H_ */
