/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main_app.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern ADC_HandleTypeDef hadc1;

extern I2C_HandleTypeDef hi2c2;

extern UART_HandleTypeDef hlpuart1;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;

extern SPI_HandleTypeDef hspi2;

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim8;


extern volatile uint8_t tick;
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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define RCC_OSC32_IN_Pin GPIO_PIN_14
#define RCC_OSC32_IN_GPIO_Port GPIOC
#define RCC_OSC32_OUT_Pin GPIO_PIN_15
#define RCC_OSC32_OUT_GPIO_Port GPIOC
#define RCC_OSC_IN_Pin GPIO_PIN_0
#define RCC_OSC_IN_GPIO_Port GPIOF
#define RCC_OSC_OUT_Pin GPIO_PIN_1
#define RCC_OSC_OUT_GPIO_Port GPIOF
#define Eana3_Pin GPIO_PIN_0
#define Eana3_GPIO_Port GPIOC
#define Eana4_Pin GPIO_PIN_1
#define Eana4_GPIO_Port GPIOC
#define Mot3_Sens1_Pin GPIO_PIN_2
#define Mot3_Sens1_GPIO_Port GPIOC
#define Mot3_Sens2_Pin GPIO_PIN_3
#define Mot3_Sens2_GPIO_Port GPIOC
#define Eana1_Pin GPIO_PIN_0
#define Eana1_GPIO_Port GPIOA
#define Servo3_PWM_Pin GPIO_PIN_1
#define Servo3_PWM_GPIO_Port GPIOA
#define LPUART1_TX_Pin GPIO_PIN_2
#define LPUART1_TX_GPIO_Port GPIOA
#define LPUART1_RX_Pin GPIO_PIN_3
#define LPUART1_RX_GPIO_Port GPIOA
#define Mot2_PWM_Pin GPIO_PIN_4
#define Mot2_PWM_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define Mot1_PWM_Pin GPIO_PIN_6
#define Mot1_PWM_GPIO_Port GPIOA
#define Mot1_Sens1_Pin GPIO_PIN_7
#define Mot1_Sens1_GPIO_Port GPIOA
#define Mot3_PWM_Pin GPIO_PIN_0
#define Mot3_PWM_GPIO_Port GPIOB
#define Led1_Pin GPIO_PIN_1
#define Led1_GPIO_Port GPIOB
#define Led2_Pin GPIO_PIN_2
#define Led2_GPIO_Port GPIOB
#define Servo4_PWM_Pin GPIO_PIN_10
#define Servo4_PWM_GPIO_Port GPIOB
#define Servo1_PWM_Pin GPIO_PIN_11
#define Servo1_PWM_GPIO_Port GPIOB
#define SPI_CS1_Pin GPIO_PIN_12
#define SPI_CS1_GPIO_Port GPIOB
#define SPI_SCK_Pin GPIO_PIN_13
#define SPI_SCK_GPIO_Port GPIOB
#define Eana2_Pin GPIO_PIN_14
#define Eana2_GPIO_Port GPIOB
#define SPI_MOSI_Pin GPIO_PIN_15
#define SPI_MOSI_GPIO_Port GPIOB
#define Codeur2_A_Pin GPIO_PIN_6
#define Codeur2_A_GPIO_Port GPIOC
#define Codeur2_B_Pin GPIO_PIN_7
#define Codeur2_B_GPIO_Port GPIOC
#define Etor2_Pin GPIO_PIN_8
#define Etor2_GPIO_Port GPIOC
#define Etor1_Pin GPIO_PIN_9
#define Etor1_GPIO_Port GPIOC
#define SPI_MISO_Pin GPIO_PIN_10
#define SPI_MISO_GPIO_Port GPIOA
#define Codeur1_A_Pin GPIO_PIN_11
#define Codeur1_A_GPIO_Port GPIOA
#define Codeur1_B_Pin GPIO_PIN_12
#define Codeur1_B_GPIO_Port GPIOA
#define T_SWDIO_Pin GPIO_PIN_13
#define T_SWDIO_GPIO_Port GPIOA
#define T_SWCLK_Pin GPIO_PIN_14
#define T_SWCLK_GPIO_Port GPIOA
#define Servo2_PWM_Pin GPIO_PIN_15
#define Servo2_PWM_GPIO_Port GPIOA
#define RS232_1_TX_Pin GPIO_PIN_10
#define RS232_1_TX_GPIO_Port GPIOC
#define RS232_1_RX_Pin GPIO_PIN_11
#define RS232_1_RX_GPIO_Port GPIOC
#define RS232_2_TX_Pin GPIO_PIN_12
#define RS232_2_TX_GPIO_Port GPIOC
#define RS232_2_RX_Pin GPIO_PIN_2
#define RS232_2_RX_GPIO_Port GPIOD
#define T_SWO_Pin GPIO_PIN_3
#define T_SWO_GPIO_Port GPIOB
#define Mot2_Sens1_Pin GPIO_PIN_4
#define Mot2_Sens1_GPIO_Port GPIOB
#define Mot2_Sens2_Pin GPIO_PIN_5
#define Mot2_Sens2_GPIO_Port GPIOB
#define Mot1_Sens2_Pin GPIO_PIN_6
#define Mot1_Sens2_GPIO_Port GPIOB
#define Cde_Mosfet_Pin GPIO_PIN_7
#define Cde_Mosfet_GPIO_Port GPIOB
#define Etor3_Pin GPIO_PIN_9
#define Etor3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
