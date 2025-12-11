/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void Control_Loop_5ms(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MOTOR_DIR_Pin GPIO_PIN_7
#define MOTOR_DIR_GPIO_Port GPIOA
#define MOTOR_DIR2_Pin GPIO_PIN_0
#define MOTOR_DIR2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
/* Encoder configuration:
 *  - Encoder PPR = 1000 pulses / revolution (per channel A/B)
 *  - TIM2 encoder mode = TI1 and TI2, polarity Rising  -> x2 counting
 *    => CPR (counts per revolution) = PPR * 2 = 2000
 */
#define ENCODER_PPR          1000.0
#define ENCODER_MODE_FACTOR  2.0        // x2 counting (TI1 & TI2, Rising)
#define ENCODER_CPR          (ENCODER_PPR * ENCODER_MODE_FACTOR)

/* Maximum absolute PID output expected from Simulink model (Saturation block) */
#define PID_OUTPUT_MAX       10.0

extern volatile uint32_t pid_tick_ms;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
