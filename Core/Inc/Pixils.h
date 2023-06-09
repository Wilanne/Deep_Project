/*
 * Pixils.h
 *
 *  Created on: 11 mai 2023
 *      Author: leoau
 */

#ifndef INC_PIXILS_H_
#define INC_PIXILS_H_

#include "ILI9341_STM32_DRIVER.h"

typedef struct {
    uint16_t pixels[8][8];
} characterPixels8_8;

extern characterPixels8_8 Wizard[4];

#endif /* INC_PIXILS_H_ */
