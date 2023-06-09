/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
**/

/*
 * Current Version 0.1b
 * Code Revision History :
 * 		0.0	: Nothing is working, even light up a LED is not working
 * 		0.1a	: The LED strip is working using TIMER TIM 2, TIM1 is broken
 * 		0.1b	: Adding Screen Lib + Font
 */

#include "main.h"
#include "init.h"
#include "ws2812.h"
#include "ILI9341_GFX.h"
#include "ILI9341_STM32_DRIVER.h"

// Da main function boy
int main(void)
{
	Init_All();

	ILI9341_Init();
	ILI9341_FillScreen(W);

	while(1) {

	}
}

// keske c ksa
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
