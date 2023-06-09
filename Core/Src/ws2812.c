/**
  ******************************************************************************
  * @file           : ws2812.c
  * @brief          : WS2812 Leds Lib Sources
  * @author 		: Kron0s
  ******************************************************************************
**/

#include "ws2812.h"

/**
  * @brief TIM2 Finish Callback
  * @retval None
  */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	HAL_TIM_PWM_Stop_DMA(&htim2, TIM_CHANNEL_1);
	datasentflag=1;
}

/**
  * @brief Set Led Function
  * @retval None
  */
void Set_LED (int LEDnum, int Red, int Green, int Blue)
{
	LED_Data[LEDnum].count = LEDnum;
	LED_Data[LEDnum].green = Green;
	LED_Data[LEDnum].red = Red;
	LED_Data[LEDnum].blue = Blue;
}

/**
  * @brief Set Brightness Test
  * @retval None
  */
void Set_Brightness (int brightness)  // 0-45
{
#if USE_BRIGHTNESS

	if (brightness > 45) brightness = 45;
	for (int i=0; i<MAX_LED; i++)
	{
		LED_Mod[i].count = LED_Data[i].count;
		for (int j=1; j<4; j++)
		{
			float angle = 90-brightness;  // in degrees
			angle = angle*PI / 180;  // in rad
			LED_Mod[i].green = (LED_Data[i].green)/(tan(angle));
			LED_Mod[i].red = (LED_Data[i].red)/(tan(angle));
			LED_Mod[i].blue = (LED_Data[i].blue)/(tan(angle));
		}
	}

#endif

}

/**
  * @brief Send The 24 bits To The Led Driver
  * @retval None
  */
void WS2812_Send (void)
{
	uint32_t indx=0;
	uint32_t color;


	for (int i= 0; i<MAX_LED; i++)
	{
#if USE_BRIGHTNESS
		color = ((LED_Mod[i].green<<16) | (LED_Mod[i].red<<8) | (LED_Mod[i].blue));
#else
		color = ((LED_Data[i].green<<16) | (LED_Data[i].red<<8) | (LED_Data[i].blue));
#endif

		for (int i=23; i>=0; i--)
		{
			if (color&(1<<i))
			{
				pwmData[indx] = 60;  // 2/3 of 90
			}

			else pwmData[indx] = 30;  // 1/3 of 90

			indx++;
		}

	}

	for (int i=0; i<50; i++)
	{
		pwmData[indx] = 0;
		indx++;
	}

	HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_1, (uint32_t *)pwmData, indx);
	while (!datasentflag){};
	datasentflag = 0;
}

/**
  * @brief Rainbow Effect
  * @retval None
  */
void Effect_Rainbow(void) {
	for (int i = 0; i < MAX_LED; i++) {
			  // Calculate the color based on the rainbow index

			  int red,green,blue;

			  uint8_t hue = rainbow_index + i * RAINBOW_STEP;
			  red = sin(hue * 3.14159 / 128 + 0) * 127 + 128;
			  green = sin(hue * 3.14159 / 128 + 2) * 127 + 128;
			  blue = sin(hue * 3.14159 / 128 + 4) * 127 + 128;
			  Set_LED(i, red, green, blue);
		  }

		  // Send the updated LED buffer to the strip
		  WS2812_Send();

		  // Increment the rainbow index for the next frame
		  rainbow_index++;
}
