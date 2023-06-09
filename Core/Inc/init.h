/*
 * init.h
 *
 *  Created on: 2 mai 2023
 *      Author: leoau
 */

#ifndef SRC_INIT_H_
#define SRC_INIT_H_

#include "main.h"
#include "stm32f1xx_hal.h"

void SystemClock_Config(void); //
static void MX_SPI1_Init(void); //
static void MX_GPIO_Init(void); //
static void MX_USART2_UART_Init(void); //
static void MX_DMA_Init(void); //
static void MX_TIM2_Init(void);
void Init_All(void);

SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_tx;

TIM_HandleTypeDef htim2;
DMA_HandleTypeDef hdma_tim2_ch1;

UART_HandleTypeDef huart2;

#endif /* SRC_INIT_H_ */
