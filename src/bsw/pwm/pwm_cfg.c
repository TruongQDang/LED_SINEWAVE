/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "pwm_cfg.h"
#include "pwm_types.h"
#include "stm32f4xx_hal.h"

/**********************************************************************************************************************
 *  PRIVATE MACROS
 *********************************************************************************************************************/
#define TIM1_HANDLE (0)

/**********************************************************************************************************************
 *  PRIVATE DATA
 *********************************************************************************************************************/
static Pwm_ChannelConfigType const Pwm_Timer1_ChannelConfig[PWM_TIMER1_CHANNEL_CONFIG_COUNT] = {
    {
        .trigger_output_ticks = 0,
        .output_compare_mode = TIM_OCMODE_PWM1,
        .output_compare_polarity = TIM_OCPOLARITY_HIGH,
        .channel_id = TIM_CHANNEL_1,
    },
    {
        .trigger_output_ticks = 0,
        .output_compare_mode = TIM_OCMODE_PWM1,
        .output_compare_polarity = TIM_OCPOLARITY_HIGH,
        .channel_id = TIM_CHANNEL_2,
    },
    {
        .trigger_output_ticks = 0,
        .output_compare_mode = TIM_OCMODE_PWM1,
        .output_compare_polarity = TIM_OCPOLARITY_HIGH,
        .channel_id = TIM_CHANNEL_3,
    },
};

/* Timer1 2000Hz PWM frequency */
static Pwm_TimerConfigType const Pwm_TimerConfig[PWM_TIMER_CONFIG_COUNT] =
    {
        {
            .base_address = (uint32_t)TIM1,
            .prescaler = 0,
            .counter_mode = TIM_COUNTERMODE_CENTERALIGNED3,
            .period_ticks = 22500,
            .period_buffer_enabled = TIM_AUTORELOAD_PRELOAD_ENABLE,
            .channel_config_ptr = Pwm_Timer1_ChannelConfig,
            .number_of_channels = PWM_TIMER1_CHANNEL_CONFIG_COUNT,
            .repetition_counter = 4,
        }};

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
Pwm_ConfigType const Pwm_Config = {
    Pwm_TimerConfig,
    PWM_TIMER_CONFIG_COUNT,
};

Pwm_HandleConfigType const Pwm_PhaseAHandle = {
    .timer_handle_id = TIM1_HANDLE,
    .channel_handle_id = TIM_CHANNEL_1,
};

Pwm_HandleConfigType const Pwm_PhaseBHandle = {
    .timer_handle_id = TIM1_HANDLE,
    .channel_handle_id = TIM_CHANNEL_2,
};

Pwm_HandleConfigType const Pwm_PhaseCHandle = {
    .timer_handle_id = TIM1_HANDLE,
    .channel_handle_id = TIM_CHANNEL_3,
};

/**********************************************************************************************************************
 *  END OF FILE: pwm_cfg.c
 *********************************************************************************************************************/
