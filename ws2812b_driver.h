/*
 * ws2812b_driver.h
 *
 *	The MIT License.
 *	Created on: 08.02.2022
 *		Author: Kamil Kośnik
 *		Repo: https://github.com/FRSH-0109/WS2812B_LED_Strip_Driver
 *		
 */

#ifndef WS2812B_H_
#define WS2812B_H_

#include "stdbool.h"
#include "string.h"
#include "stdint.h"

#include "math.h"

#define LED_AMOUNT 30
#define RESET_BYTES_AMOUNT 72
#define PWM_VALUE_ONE 52
#define PWM_VALUE_ZERO 27

typedef struct ws2812bLedStruct {
	uint16_t length;
	uint16_t resetBytes;
	uint16_t bytesToSend;
	uint16_t pwmData[RESET_BYTES_AMOUNT + 24*LED_AMOUNT];
	uint32_t ledArray[LED_AMOUNT];
	volatile bool dataSentFlag;
}ws2812bLedStruct;

void ws2812bLedStructInit(ws2812bLedStruct *ledsStrip);
void ws2812bGetBytesArray(ws2812bLedStruct *ledsStrip);
void ws2812bSetRGB(ws2812bLedStruct *ledsStrip, uint16_t index, uint8_t Red, uint8_t Green, uint8_t Blue);
void ws2812bClearAll(ws2812bLedStruct *ledsStrip);
void ws2812bWave(ws2812bLedStruct *ledStrip, uint16_t width, uint8_t Red, uint8_t Green, uint8_t Blue);

#endif
