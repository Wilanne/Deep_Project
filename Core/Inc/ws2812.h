/**

@file : ws2812.h
@brief : WS2812 Leds Lib Header
@author : Kron0s
**/

#ifndef SRC_WS2812_H_
#define SRC_WS2812_H_

#include "stm32f1xx_hal.h"
#include "init.h"

#define MAX_LED 5 ///< Maximum number of LEDs
#define USE_BRIGHTNESS 0 ///< Flag to indicate if brightness is used (a bit broken)
#define RAINBOW_STEP 16 ///< The step size for the rainbow effect
#define PI 3.14159265 ///< The value of PI

/**

@brief Structure to hold LED data.
*/
typedef struct {
uint8_t count; ///< LED number
uint8_t red; ///< Red color value
uint8_t green; ///< Green color value
uint8_t blue; ///< Blue color value
} RGB_color_t;

// LED buffer
static RGB_color_t LED_Data[MAX_LED]; ///< Array to hold LED data
static RGB_color_t LED_Mod[MAX_LED]; ///< Array to hold modified LED data

static uint16_t pwmData[(24*MAX_LED)+50]; ///< Array to store PWM data
static int datasentflag = 0; ///< Flag to indicate if data has been sent
static uint8_t rainbow_index = 0; ///< Index for the rainbow effect

// Essential Prototypes
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void Set_LED (int LEDnum, int Red, int Green, int Blue);
void Set_Brightness (int brightness);
void WS2812_Send (void);

// Effects Prototypes
void Effect_Rainbow(void);

#endif /* SRC_WS2812_H_ */
