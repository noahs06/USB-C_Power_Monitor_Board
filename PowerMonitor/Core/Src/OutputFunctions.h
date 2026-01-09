/*
 * OutputFunctions.h
 *
 *  Created on: Dec 24, 2025
 *      Author: Noah Silat
 */

#ifndef SRC_OUTPUTFUNCTIONS_H_
#define SRC_OUTPUTFUNCTIONS_H_




#include "main.h"

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
// Functions here will be responsible for initializing the LCD as well as outputting to it with adequate formatting (i.e. correct positioning
// and output.

void sendCommand(char cmd);
void initializeLCD(void);
void outputWords(char* words);
void outputNums(uint32_t nums);
void outputChar(char character);
void setCursor(int row, int col);
int readINA(int reg);
void displayFloat (float flt, int row, int col);

#endif /* SRC_OUTPUTFUNCTIONS_H_ */
