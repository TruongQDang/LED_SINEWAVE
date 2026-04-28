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
static Pwm_HwResourceConfigType const Pwm_HwResconfig[PWM_USED_HWRES_COUNT] = {
    {.base_address = (uint32_t)TIM1,
     .prescaler = 0,
     .counter_mode = TIM_COUNTERMODE_CENTERALIGNED3,
     .period_ticks = 22500,
     .enable_period_tick_buffer = TIM_AUTORELOAD_PRELOAD_ENABLE,
     .repetition_counter = 4,
     .logical_id = PWM_HWRES0}};

static Pwm_ChannelConfigType const Pwm_ChannelConfig[PWM_USED_CH_COUNT] = {
    {.pulse_ticks = 0,
     .output_compare_mode = TIM_OCMODE_PWM1,
     .output_compare_polarity = TIM_OCPOLARITY_HIGH,
     .hw_id = TIM_CHANNEL_1,
     .logical_id = PWM_PHASEA_CH,
     .hw_res_id = PWM_HWRES0},
    {.pulse_ticks = 0,
     .output_compare_mode = TIM_OCMODE_PWM1,
     .output_compare_polarity = TIM_OCPOLARITY_HIGH,
     .hw_id = TIM_CHANNEL_2,
     .logical_id = PWM_PHASEB_CH,
     .hw_res_id = PWM_HWRES0},
    {.pulse_ticks = 0,
     .output_compare_mode = TIM_OCMODE_PWM1,
     .output_compare_polarity = TIM_OCPOLARITY_HIGH,
     .hw_id = TIM_CHANNEL_3,
     .logical_id = PWM_PHASEC_CH,
     .hw_res_id = PWM_HWRES0},
};

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
Pwm_ConfigType const Pwm_Config = {
    .channel_config_table = Pwm_ChannelConfig,
    .numbers_of_channels = PWM_USED_CH_COUNT,
    .hw_res_config_table = Pwm_HwResconfig,
    .number_of_hw_res = PWM_USED_HWRES_COUNT};

/**********************************************************************************************************************
 *  END OF FILE: pwm_cfg.c
 *********************************************************************************************************************/
