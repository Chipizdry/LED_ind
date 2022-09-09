/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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


#define LED_ENABLE HAL_GPIO_WritePin(LED_ENABLE_GPIO_Port, LED_ENABLE_Pin,GPIO_PIN_SET)
#define LED_DISABLE HAL_GPIO_WritePin(LED_ENABLE_GPIO_Port, LED_ENABLE_Pin,GPIO_PIN_RESET)

#define LED_PWM_ON  HAL_GPIO_WritePin(GPIOA, LED_PWM_Pin, GPIO_PIN_SET)
#define LED_PWM_OFF HAL_GPIO_WritePin(GPIOA, LED_PWM_Pin, GPIO_PIN_RESET)

#define LED_10_MIN_ON  HAL_GPIO_WritePin(LED_10_min_GPIO_Port, LED_10_min_Pin,GPIO_PIN_SET)
#define LED_10_MIN_OFF  HAL_GPIO_WritePin(LED_10_min_GPIO_Port, LED_10_min_Pin,GPIO_PIN_RESET)

#define LED_20_MIN_ON  HAL_GPIO_WritePin(LED_20_min_GPIO_Port, LED_20_min_Pin,GPIO_PIN_SET)
#define LED_20_MIN_OFF  HAL_GPIO_WritePin(LED_20_min_GPIO_Port, LED_20_min_Pin,GPIO_PIN_RESET)

#define LED_30_MIN_ON  HAL_GPIO_WritePin(LED_30_min_GPIO_Port, LED_30_min_Pin,GPIO_PIN_SET)
#define LED_30_MIN_OFF  HAL_GPIO_WritePin(LED_30_min_GPIO_Port, LED_30_min_Pin,GPIO_PIN_RESET)

#define LED_40_MIN_ON  HAL_GPIO_WritePin(LED_40_min_GPIO_Port, LED_40_min_Pin,GPIO_PIN_SET)
#define LED_40_MIN_OFF  HAL_GPIO_WritePin(LED_40_min_GPIO_Port, LED_40_min_Pin,GPIO_PIN_RESET)

#define LED_50_MIN_ON  HAL_GPIO_WritePin(LED_50_min_GPIO_Port, LED_50_min_Pin,GPIO_PIN_SET)
#define LED_50_MIN_OFF  HAL_GPIO_WritePin(LED_50_min_GPIO_Port, LED_50_min_Pin,GPIO_PIN_RESET)

#define LED_60_MIN_ON  HAL_GPIO_WritePin(LED_60_min_GPIO_Port, LED_60_min_Pin,GPIO_PIN_SET)
#define LED_60_MIN_OFF  HAL_GPIO_WritePin(LED_60_min_GPIO_Port, LED_60_min_Pin,GPIO_PIN_RESET)

#define LED_1_HOUR_ON   HAL_GPIO_WritePin(LED_1_hour_GPIO_Port, LED_1_hour_Pin,GPIO_PIN_SET)
#define LED_1_HOUR_OFF  HAL_GPIO_WritePin(LED_1_hour_GPIO_Port, LED_1_hour_Pin,GPIO_PIN_RESET)

#define LED_2_HOUR_ON   HAL_GPIO_WritePin(LED_2_hour_GPIO_Port, LED_2_hour_Pin,GPIO_PIN_SET)
#define LED_2_HOUR_OFF  HAL_GPIO_WritePin(LED_2_hour_GPIO_Port, LED_2_hour_Pin,GPIO_PIN_RESET)

#define LED_3_HOUR_ON   HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,GPIO_PIN_SET)
#define LED_3_HOUR_OFF  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,GPIO_PIN_RESET)

#define ALL_OFF LED_10_MIN_OFF LED_20_MIN_OFF LED_30_MIN_OFF LED_40_MIN_OFF LED_50_MIN_OFF	LED_60_MIN_OFF LED_1_HOUR_OFF LED_2_HOUR_OFF LED_3_HOUR_OFF;

#define ALL_ON LED_10_MIN_ON LED_20_MIN_ON LED_30_MIN_ON LED_40_MIN_ON LED_50_MIN_ON	LED_60_MIN_ON LED_1_HOUR_ON LED_2_HOUR_ON LED_3_HOUR_ON;

#define KOEFF 9350000

#define BLNK 18000




/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;

/* USER CODE BEGIN PV */

uint32_t dl=0;
uint64_t count=0;
uint8_t scene=0;
uint8_t hour=0;
uint16_t blink=0;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC_Init(void);
/* USER CODE BEGIN PFP */
void Delay(uint32_t);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
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
  MX_ADC_Init();
  /* USER CODE BEGIN 2 */

  LED_ENABLE;

	LED_10_MIN_ON;

	HAL_Delay(200);

	LED_20_MIN_ON;

	HAL_Delay(200);

	LED_30_MIN_ON;

	HAL_Delay(200);

	LED_40_MIN_ON;

	HAL_Delay(200);

	LED_50_MIN_ON;

	HAL_Delay(200);

	LED_60_MIN_ON;

	HAL_Delay(200);

	LED_1_HOUR_ON;

	HAL_Delay(200);

	LED_2_HOUR_ON;

	HAL_Delay(200);

	LED_3_HOUR_ON;

	HAL_Delay(800);

	LED_10_MIN_OFF;
	LED_20_MIN_OFF;
	LED_30_MIN_OFF;
	LED_40_MIN_OFF;
	LED_50_MIN_OFF;
	LED_60_MIN_OFF;
    LED_1_HOUR_OFF;
    LED_2_HOUR_OFF;
    LED_3_HOUR_OFF;
    /*
    HAL_Delay(500);
    ALL_ON;
    HAL_Delay(500);
    ALL_OFF;
*/

    HAL_Delay(500);
  dl=50;
  LED_ENABLE;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {



	 LED_PWM_ON;

	                      LED_10_MIN_OFF;
					      LED_20_MIN_OFF;
				          LED_30_MIN_OFF;
				          LED_40_MIN_OFF;
					      LED_50_MIN_OFF;
				          LED_60_MIN_OFF;
					      LED_1_HOUR_OFF;
					      LED_2_HOUR_OFF;
				          LED_3_HOUR_OFF;

	                      count++;

	                      scene=count/KOEFF;
	                      if(hour==4){scene=0;count=0;hour=0;}
	//  Delay(dl);
	  LED_PWM_OFF;

                blink++;

                if(blink>BLNK){blink=0;}

				if((scene==0)||(scene==6)||(scene==12)||(scene==18)){ LED_10_MIN_ON;  if((blink>(BLNK/2))&&(blink<BLNK)){ LED_10_MIN_OFF; }}

				if((scene==1)||(scene==7)||(scene==13)||(scene==19)){ LED_20_MIN_ON;  if((blink>(BLNK/2))&&(blink<BLNK)){ LED_20_MIN_OFF; }}

				if((scene==2)||(scene==8)||(scene==14)||(scene==20)){ LED_30_MIN_ON;  if((blink>(BLNK/2))&&(blink<BLNK)){ LED_30_MIN_OFF; }}

				if((scene==3)||(scene==9)||(scene==15)||(scene==21)){ LED_40_MIN_ON;  if((blink>(BLNK/2))&&(blink<BLNK)){ LED_40_MIN_OFF; }}

				if((scene==4)||(scene==10)||(scene==16)||(scene==22)){LED_50_MIN_ON;  if((blink>(BLNK/2))&&(blink<BLNK)){ LED_50_MIN_OFF; }}

				if((scene==5)||(scene==11)||(scene==17)||(scene==23)){LED_60_MIN_ON;  if((blink>(BLNK/2))&&(blink<BLNK)){ LED_60_MIN_OFF; }}


				if((scene>=6)&&(scene<=11)){hour=1;LED_1_HOUR_ON;}

				if((scene>=12)&&(scene<=17)){ hour=2;LED_1_HOUR_ON; LED_2_HOUR_ON;}

				if((scene>=18)&&(scene<=23)){ hour=3;LED_1_HOUR_ON;LED_2_HOUR_ON;LED_3_HOUR_ON;}

				if(scene==24){

					    LED_10_MIN_ON;
						LED_20_MIN_ON;
						LED_30_MIN_ON;
						LED_40_MIN_ON;
						LED_50_MIN_ON;
						LED_60_MIN_ON;
					    LED_1_HOUR_ON;
					    LED_2_HOUR_ON;
					    LED_3_HOUR_ON;

					   HAL_Delay(600);

					    LED_10_MIN_OFF;
					    LED_20_MIN_OFF;
					    LED_30_MIN_OFF;
					    LED_40_MIN_OFF;
					    LED_50_MIN_OFF;
					    LED_60_MIN_OFF;
					    LED_1_HOUR_OFF;
					    LED_2_HOUR_OFF;
					    LED_3_HOUR_OFF;

					   HAL_Delay(600);

					    LED_10_MIN_ON;
					    LED_20_MIN_ON;
						LED_30_MIN_ON;
						LED_40_MIN_ON;
					    LED_50_MIN_ON;
					    LED_60_MIN_ON;
					    LED_1_HOUR_ON;
					    LED_2_HOUR_ON;
					    LED_3_HOUR_ON;

					    HAL_Delay(600);

					    LED_10_MIN_OFF;
					   	LED_20_MIN_OFF;
					   	LED_30_MIN_OFF;
					   	LED_40_MIN_OFF;
					   	LED_50_MIN_OFF;
					   	LED_60_MIN_OFF;
					   	LED_1_HOUR_OFF;
					   	LED_2_HOUR_OFF;
					   	LED_3_HOUR_OFF;

					   	HAL_Delay(600);

					   	LED_10_MIN_ON;
					   	LED_20_MIN_ON;
					   	LED_30_MIN_ON;
					   	LED_40_MIN_ON;
					   	LED_50_MIN_ON;
					   	LED_60_MIN_ON;
					   	LED_1_HOUR_ON;
					   	LED_2_HOUR_ON;
					   	LED_3_HOUR_ON;
					    HAL_Delay(1000);
				    	hour=4;}

				 Delay(dl);
				// HAL_Delay(5);

  }



    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_4;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC_Init(void)
{

  /* USER CODE BEGIN ADC_Init 0 */

  /* USER CODE END ADC_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC_Init 1 */

  /* USER CODE END ADC_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc.Instance = ADC1;
  hadc.Init.OversamplingMode = DISABLE;
  hadc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ContinuousConvMode = DISABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerFrequencyMode = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC_Init 2 */

  /* USER CODE END ADC_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED_60_min_Pin|LED_3_hour_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_ENABLE_Pin|LED_PWM_Pin|LED_20_min_Pin|LED_30_min_Pin
                          |LED_40_min_Pin|LED_2_hour_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_50_min_Pin|LED_10_min_Pin|LED_1_hour_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_60_min_Pin LED_3_hour_Pin */
  GPIO_InitStruct.Pin = LED_60_min_Pin|LED_3_hour_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_ENABLE_Pin */
  GPIO_InitStruct.Pin = LED_ENABLE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED_ENABLE_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_PWM_Pin */
  GPIO_InitStruct.Pin = LED_PWM_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(LED_PWM_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_20_min_Pin LED_30_min_Pin LED_40_min_Pin LED_2_hour_Pin */
  GPIO_InitStruct.Pin = LED_20_min_Pin|LED_30_min_Pin|LED_40_min_Pin|LED_2_hour_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_50_min_Pin LED_10_min_Pin LED_1_hour_Pin */
  GPIO_InitStruct.Pin = LED_50_min_Pin|LED_10_min_Pin|LED_1_hour_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /**/
  HAL_I2CEx_EnableFastModePlus(I2C_FASTMODEPLUS_PB6);

  /**/
  HAL_I2CEx_EnableFastModePlus(I2C_FASTMODEPLUS_PB7);

}

/* USER CODE BEGIN 4 */

void Delay(uint32_t d){

for(uint32_t n=0;n<d;){
	n++;}
}




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
