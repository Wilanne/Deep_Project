/*
 * PixelArt.h
 *
 *  Created on: May 5, 2023
 *      Author: leoau
 */

#ifndef INC_PIXELART_H_
#define INC_PIXELART_H_

#include "ws2812.h"
#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"
#include "Pixils.h"

void PixelArt_InitScreen();
void PixelArt_DrawGrid(uint16_t m_gridColor, uint16_t m_fillColor, uint8_t m_cellSize, float m_scalFactor);
void PixelArt_DrawCharacter(characterPixels8_8 character, uint8_t m_cellSize, uint8_t borderSpace, float m_scalFactor);
void PixelArt_AnimeCharacter(characterPixels8_8 character[4], uint8_t m_cellSize, uint8_t borderSpace, float m_scalFactor);

void PixelArt_ScreenTest();

#endif /* INC_PIXELART_H_ */
