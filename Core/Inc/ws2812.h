/**
  ******************************************************************************
  * @file           : ws2812.h
  * @brief          : WS2812 Leds Lib Header
  * @author 		: Kron0s
  ******************************************************************************
**/

#ifndef SRC_WS2812_H_
#define SRC_WS2812_H_

#include "stm32f1xx_hal.h"
#include "init.h"

#define MAX_LED 5 // Max Led Count
#define USE_BRIGHTNESS 0 // If we use brightness (a bit broken)
#define RAINBOW_STEP 16 // The step size for the rainbow effect
#define PI 3.14159265


// Leds data structure
typedef struct {
	uint8_t count;
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} RGB_color_t;


// LED buffer
RGB_color_t LED_Data[MAX_LED];
RGB_color_t LED_Mod[MAX_LED];

static uint16_t pwmData[(24*MAX_LED)+50];
static int datasentflag = 0;
static uint8_t rainbow_index = 0;

// Essential Prototypes
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void Set_LED (int LEDnum, int Red, int Green, int Blue);
void Set_Brightness (int brightness);
void WS2812_Send (void);

// Effects Prototypes
void Effect_Rainbow(void);
// add +++

#endif /* SRC_WS2812_H_ */
