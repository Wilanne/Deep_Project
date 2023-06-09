/*
 * ILI9341_STM32_DRIVER.h
 *
 *  Created on: 5 mai 2023
 *      Author: leoau
 */

#ifndef INC_ILI9341_STM32_DRIVER_H_
#define INC_ILI9341_STM32_DRIVER_H_

#include "stm32f1xx_hal.h"

extern SPI_HandleTypeDef hspi1;

#define ILI9341_SCREEN_HEIGHT 	240
#define ILI9341_SCREEN_WIDTH 	320

// PIN Configuration
#define HSPI_INSTANCE			&hspi1
#define LCD_CS_PORT				GPIOB
#define LCD_CS_PIN				GPIO_PIN_10
#define LCD_DC_PORT				GPIOB
#define LCD_DC_PIN				GPIO_PIN_0
#define	LCD_RST_PORT			GPIOB
#define	LCD_RST_PIN				GPIO_PIN_1

// Color Definitions (HEX && 2Bits)
#define BURST_MAX_SIZE 			500
#define BL      				0x0000 // Black
#define N	        			0x000F // Navy
#define DG  					0x03E0 // DarkGreen
#define DC   					0x03EF // DarkCyan
#define M      					0x7800 // Maroon
#define PU      				0x780F // Purple
#define O      					0x7BE0 // Olive
#define LG  					0xC618 // LightGreen
#define DGY    					0x7BEF // DarkGrey
#define B        				0x001F // Blue
#define GR       				0x07E0 // Green
#define C        				0x07FF // Cyan
#define R        				0xF800 // Red
#define MAG   					0xF81F // Magenta
#define YE     					0xFFE0 // Yellow
#define W       				0xFFFF // White
#define OR      				0xFD20 // Orange
#define GY 						0xAFE5 // GreenYellow
#define P        				0xF81F // Pink

// Screen Orientation
#define SCREEN_VERTICAL_1		0
#define SCREEN_HORIZONTAL_1		1
#define SCREEN_VERTICAL_2		2
#define SCREEN_HORIZONTAL_2		3

// Main Manipulation Function's Prototypes
void ILI9341_WriteCommand(uint8_t cmd);
void ILI9341_WriteData(uint8_t data);
void ILI9341_WriteBuffer(uint8_t *buffer, uint16_t len);
void ILI9341_Reset(void);
void ILI9341_Enable(void);
void ILI9341_Init(void);
void ILI9341_SetRotation(uint8_t rotation);
void ILI9341_SetAddress(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

// Main Graphical Function's Prototypes
void ILI9341_DrawColor(uint16_t color);
void ILI9341_DrawColorBurst(uint16_t color, uint32_t size);
void ILI9341_FillScreen(uint16_t color);
void ILI9341_DrawPixel(uint16_t x,uint16_t y,uint16_t color);
void ILI9341_DrawRectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color);
void ILI9341_DrawHLine(uint16_t x, uint16_t y, uint16_t width, uint16_t color);
void ILI9341_DrawVLine(uint16_t x, uint16_t y, uint16_t height, uint16_t color);

#endif /* INC_ILI9341_STM32_DRIVER_H_ */
