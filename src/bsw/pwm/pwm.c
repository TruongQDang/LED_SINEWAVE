/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "pwm.h"
#include "pwm_cfg.h"
#include "pwm_types.h"
#include "stm32f4xx_hal.h"
#include "utilities.h"

/**********************************************************************************************************************
 *  PRIVATE DATA
 *********************************************************************************************************************/
static TIM_HandleTypeDef Pwm_Timer[PWM_TIMER_CONFIG_COUNT];

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
void Pwm_Init(Pwm_ConfigType const* ConfigPtr)
{
    Pwm_ChannelType ch;
    Pwm_TimerType tim;
    Pwm_TimerConfigType const* _TimerConfig;
    Pwm_ChannelConfigType const* _ChannelConfig;
    TIM_HandleTypeDef* _PwmTimer;
    TIM_OC_InitTypeDef output_compare_config;

    if (ConfigPtr != NULL) {
        for (tim = 0; tim < ConfigPtr->number_of_timers; tim++) {
            _TimerConfig = &ConfigPtr->timer_config_ptr[tim];
            _PwmTimer = &Pwm_Timer[tim];

            _PwmTimer->Instance = (TIM_TypeDef*)_TimerConfig->base_address;
            _PwmTimer->Init.Prescaler = _TimerConfig->prescaler;
            _PwmTimer->Init.CounterMode = _TimerConfig->counter_mode;
            _PwmTimer->Init.Period = _TimerConfig->period_ticks;
            _PwmTimer->Init.AutoReloadPreload = _TimerConfig->period_buffer_enabled;
            _PwmTimer->Init.RepetitionCounter = _TimerConfig->repetition_counter;

            if (HAL_TIM_Base_Init(_PwmTimer) != HAL_OK) {
                Error_Handler();
            }

            if (HAL_TIM_PWM_Init(_PwmTimer) != HAL_OK) {
                Error_Handler();
            }

            for (ch = 0; ch < _TimerConfig->number_of_channels; ch++) {
                _ChannelConfig = &_TimerConfig->channel_config_ptr[ch];

                output_compare_config.OCMode = _ChannelConfig->output_compare_mode;
                output_compare_config.Pulse = _ChannelConfig->trigger_output_ticks;
                output_compare_config.OCPolarity = _ChannelConfig->output_compare_polarity;

                if (HAL_TIM_PWM_ConfigChannel(_PwmTimer, &output_compare_config, _ChannelConfig->channel_id) != HAL_OK) {
                    Error_Handler();
                }

                HAL_TIM_PWM_Start(_PwmTimer, _ChannelConfig->channel_id);
            }

            HAL_TIM_Base_Start_IT(_PwmTimer);
        }
    }
}

void Pwm_SetDutyCycle(Pwm_HandleConfigType const* PwmHandlePtr, uint32_t trigger_output_ticks)
{
    Pwm_ChannelType ch_handle;
    Pwm_TimerType tim_handle;

    ch_handle = PwmHandlePtr->channel_handle_id;
    tim_handle = PwmHandlePtr->timer_handle_id;

    __HAL_TIM_SET_COMPARE(&Pwm_Timer[tim_handle], ch_handle, trigger_output_ticks);
}

/**********************************************************************************************************************
 *  END OF FILE: pwm.c
 *********************************************************************************************************************/