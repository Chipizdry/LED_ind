/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_60_min_Pin GPIO_PIN_14
#define LED_60_min_GPIO_Port GPIOC
#define LED_3_hour_Pin GPIO_PIN_15
#define LED_3_hour_GPIO_Port GPIOC
#define LED_ENABLE_Pin GPIO_PIN_0
#define LED_ENABLE_GPIO_Port GPIOA
#define LED_PWM_Pin GPIO_PIN_1
#define LED_PWM_GPIO_Port GPIOA
#define ADC_LED_INP_Pin GPIO_PIN_4
#define ADC_LED_INP_GPIO_Port GPIOA
#define LED_20_min_Pin GPIO_PIN_5
#define LED_20_min_GPIO_Port GPIOA
#define LED_30_min_Pin GPIO_PIN_7
#define LED_30_min_GPIO_Port GPIOA
#define LED_50_min_Pin GPIO_PIN_1
#define LED_50_min_GPIO_Port GPIOB
#define LED_40_min_Pin GPIO_PIN_9
#define LED_40_min_GPIO_Port GPIOA
#define LED_2_hour_Pin GPIO_PIN_10
#define LED_2_hour_GPIO_Port GPIOA
#define LED_10_min_Pin GPIO_PIN_6
#define LED_10_min_GPIO_Port GPIOB
#define LED_1_hour_Pin GPIO_PIN_7
#define LED_1_hour_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
