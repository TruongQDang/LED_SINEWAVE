#include "led_effect.h"
#include "stm32f4xx_hal.h"

void SysTick_Handler(void)
{
    HAL_IncTick();
}

void TIM1_UP_TIM10_IRQHandler(void)
{
    LedEffect();
}