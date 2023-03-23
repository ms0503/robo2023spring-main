/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.cc
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
// clang-format -style="{ ContinuationIndentWidth: 2, IndentWidth: 2, TabWidth: 2 }"
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "can.h"
#include "gpio.h"
#include "usart.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Arm.hh"
#include "Controller.hh"
#include "LED.hh"
#include "Motor.hh"
#include "Thrower.hh"
#include "params.hh"
#include "stm32f4xx_hal.h"
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
LMLL::Can can(hcan1);
LM::Controller ctrl;
LM::Motor motorFR(hcan1, can, ADDR_MOTOR.FR);
LM::Motor motorFL(hcan1, can, ADDR_MOTOR.FL);
LM::Motor motorRL(hcan1, can, ADDR_MOTOR.RL);
LM::Motor motorRR(hcan1, can, ADDR_MOTOR.RR);
Arm arm({ PIN_ARM_HAND, PIN_ARM_MOVER_LEFT, PIN_ARM_MOVER_RIGHT });
LED led1(PIN_LED_1);
LED led2(PIN_LED_2);
LED led3(PIN_LED_3);
LED led4(PIN_LED_4);
Thrower thrower({ PIN_THROWER_LOADER_LEFT, PIN_THROWER_LOADER_RIGHT, PIN_THROWER_LOCKER });
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config();
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main() {
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
    MX_CAN1_Init();
    MX_USART3_UART_Init();
    /* USER CODE BEGIN 2 */
    LL_USART_EnableIT_RXNE(USART3);
    motorFR.init(ADDR_MAIN, MOTOR_SPEED_MAX);
    motorFL.init(ADDR_MAIN, MOTOR_SPEED_MAX);
    motorRL.init(ADDR_MAIN, MOTOR_SPEED_MAX);
    motorRR.init(ADDR_MAIN, MOTOR_SPEED_MAX);
    ctrl.init(CTRL_DEAD_ZONES);
    arm.back();
    arm.open();
    thrower.lock();
    thrower.dispatch();
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while(true) {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
        /*
        led3.turnOff();
        led1.turnOn();
        LL_mDelay(250);
        led4.turnOff();
        led2.turnOn();
        LL_mDelay(250);
        led1.turnOff();
        led3.turnOn();
        LL_mDelay(250);
        led2.turnOff();
        led4.turnOn();
        LL_mDelay(250);
         */
    }
    /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config() {
    LL_FLASH_SetLatency(LL_FLASH_LATENCY_5);
    while(LL_FLASH_GetLatency() != LL_FLASH_LATENCY_5) {
    }
    LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
    while(LL_PWR_IsActiveFlag_VOS() == 0) {
    }
    LL_RCC_HSI_SetCalibTrimming(16);
    LL_RCC_HSI_Enable();

    /* Wait till HSI is ready */
    while(LL_RCC_HSI_IsReady() != 1) {
    }
    LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI, LL_RCC_PLLM_DIV_8, 168, LL_RCC_PLLP_DIV_2);
    LL_RCC_PLL_Enable();

    /* Wait till PLL is ready */
    while(LL_RCC_PLL_IsReady() != 1) {
    }
    LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
    LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_4);
    LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_2);
    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

    /* Wait till System clock is ready */
    while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL) {
    }
    LL_SetSystemCoreClock(168000000);

    /* Update the time base */
    if(HAL_InitTick(TICK_INT_PRIORITY) != HAL_OK) {
        Error_Handler();
    }
}

/* USER CODE BEGIN 4 */
inline void blink(LMLL::SBDBT::AnalogState sticks) {
    if(sticks.LX <= -64) led1.turnOn();
    else led1.turnOff();
    if(63 <= sticks.LX) led2.turnOn();
    else led2.turnOff();
    if(sticks.LY <= -64) led3.turnOn();
    else led3.turnOff();
    if(63 <= sticks.LY) led4.turnOn();
    else led4.turnOff();
}
extern "C" {
    void onSBDBTReceived(std::uint8_t data[LMLL::SBDBT_RECEIVE_SIZE]) {
        const LMLL::SBDBT::ButtonAssignment bs = ctrl.receiveProcessing(data);
        if(LM::Controller::isPush(bs.L1)) arm.move();
        else if(LM::Controller::isReleaseEdge(bs.L1)) arm.back();
        if(LM::Controller::isPush(bs.L2)) arm.close();
        else if(LM::Controller::isReleaseEdge(bs.L2)) arm.open();
        if(LM::Controller::isPush(bs.R1)) thrower.unlock();
        else if(LM::Controller::isReleaseEdge(bs.R1)) thrower.lock();
        if(LM::Controller::isPush(bs.R2)) thrower.reload();
        else if(LM::Controller::isReleaseEdge(bs.R2)) thrower.dispatch();
        motorFR.update(ctrl.stickToMotor(static_cast<std::uint8_t>(LM::EnumMotor::FR)));
        motorFL.update(ctrl.stickToMotor(static_cast<std::uint8_t>(LM::EnumMotor::FL)));
        motorRL.update(ctrl.stickToMotor(static_cast<std::uint8_t>(LM::EnumMotor::RL)));
        motorRR.update(ctrl.stickToMotor(static_cast<std::uint8_t>(LM::EnumMotor::RR)));
        const LMLL::SBDBT::AnalogState sticks = ctrl.getStick();
        blink(sticks);
        led1.turnOff();
        led2.turnOff();
        led3.turnOff();
        led4.turnOff();
    }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler() {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while(true) {
    }
    /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line) {
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
