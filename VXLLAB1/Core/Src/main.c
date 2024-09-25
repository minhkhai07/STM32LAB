/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void display7SEG(int num) {
  uint8_t segmentPattern[10] = {
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111 };
  if (num < 0 || num > 9) {
    num = 0;
  }

  	uint8_t pattern = segmentPattern[num];
  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (pattern & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET); //A
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (pattern & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET); //B
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, (pattern & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET); //C
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (pattern & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET); // D
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (pattern & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET); // E
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (pattern & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET); // F
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (pattern & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET); //G
  }

void display7seg(int num){
	    uint8_t segments[10] = {
	        0b00111111, // 0
	        0b00000110, // 1
	        0b01011011, // 2
	        0b01001111, // 3
	        0b01100110, // 4
	        0b01101101, // 5
	        0b01111101, // 6
	        0b00000111, // 7
	        0b01111111, // 8
	        0b01101111  // 9
	    };
	    if (num < 0 || num > 9) {
	        num = 0;
	      }

	    uint8_t segment_value = segments[num];

	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, (segment_value & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);  // A
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, (segment_value & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);  // B
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, (segment_value & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);  // C
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, (segment_value & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);  // D
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, (segment_value & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);  // E
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (segment_value & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);  // F
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (segment_value & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);  // G
	}
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  	int red = 1;
    int green = 0;
    int yellow = 2;
    int color_1 = 0;
    int color_2 = 1;
    int coun1 = 0;
    int coun2 = 0;
    int four_1 = 4;
    int two_1 = 2;
    int one_1 = 1;
    int four_2 = 4;
    int two_2 = 2;
    int one_2 = 1;
  while (1)
  {
    /* USER CODE END WHILE */
	  	  	  	  if(color_1 == green && coun1 == 3){
	  	  	  		  color_1 = 2;
	  	  	  		  two_1 = 2;
	  	  	  		  coun1 = 0;
	  	  	  	  }
	  	  	  	  if(color_1 == red && coun1 == 5){
	  	  	  		  color_1 = 0;
	  	  	  		  four_1 = 4;
	  	  	  		  coun1 = 0;
	  	  	  	  }
	  	  	  	  if(color_1 == yellow && coun1 == 2){
	  	  	  		  color_1 = 1;
	  	  	  		  one_1 = 1;
	  	  	  		  coun1 = 0;
	  	  	  	  }
	  	  	  	  if(color_2 == green && coun2 == 3){
	  	  	  		  color_2 = 2;
	  	  	  		  two_2 = 2;
	  	  	  		  coun2 = 0;
	  	  	  	  }
	  	  	  	  if(color_2 == red && coun2 == 5){
	  	  	  		  color_2 = 0;
	  	  	  		  four_2 = 4;
	  	  	  		  coun2 = 0;
	  	  	  	  }
	  	  	  	  if(color_2 == yellow && coun2 == 2){
	  	  	  		  color_2 = 1;
	  	  	  		  one_2 = 1;
	  	  	  		  coun2 = 0;
	  	  	  	  }
	  	  	  if(color_1 == green){
	  	  	  	  	  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
	  	  	  	  	  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
	  	  	  		  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);  //  led green on
	  	  	  		  	  display7seg(two_1--);
	  	  	  	  	  	  }
	  	  	  		  	  else if(color_1 == yellow){
	  	  	  		  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET); // led yellow on
	  	  	  		  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
	  	  	  		  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
	  	  	  		  	  display7seg(one_1--);
	  	  	  		  	  }
	  	  	  		  	  else if(color_1 == red){
	  	  	  		  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
	  	  	  			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET); //led red on
	  	  	  			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
	  	  	  		  	  display7seg(four_1--);
	  	  	  		  	  }

	  	  	  	if(color_2 == red){
	  	  	  		  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
	  	  	  		  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);  //led red on
	  	  	  		  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);
	  	  	  		  	  display7SEG(four_2--);
	  	  	  			  }
	  	  	  		  	  else if(color_2 == yellow){
	  	  	  			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);  // led yellow on
	  	  	  			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
	  	  	  			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET); // led yellow on
	  	  	  			  display7SEG(one_2--);
	  	  	  		  	  }
	  	  	  		  	  else if(color_2 == green){
	  	  	  			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
	  	  	  			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
	  	  	  			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);  // led green on
	  	  	  			  display7SEG(two_2--);
	  	  	  		  	  }
	  	  	  		  	  coun1++;
	  	  	  		  	  coun2++;
	  	  	  		  	  HAL_Delay(1000);

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA6 PA7 PA8 PA9
                           PA10 PA11 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10
                           PB11 PB12 PB13 PB3
                           PB4 PB5 PB6 PB7
                           PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
