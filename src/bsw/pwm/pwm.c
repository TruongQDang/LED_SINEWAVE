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
static TIM_HandleTypeDef Pwm_HwRes[PWM_USED_HWRES_COUNT];
static Pwm_ChannelConfigType Pwm_Channel[PWM_USED_CH_COUNT];

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
void Pwm_Init(Pwm_ConfigType const* ConfigPtr)
{
    Pwm_ChannelType ch_id;
    Pwm_HwResourceType hw_res_id;
    Pwm_HwResourceType channel_hw_res_id;
    Pwm_ChannelConfigType const* _ChannelConfigTable;
    Pwm_HwResourceConfigType const* _HwResConfigTable;
    TIM_OC_InitTypeDef output_compare_config;

    if (ConfigPtr != NULL) {
        for (hw_res_id = 0; hw_res_id < ConfigPtr->number_of_hw_res; hw_res_id++) {
            _HwResConfigTable = ConfigPtr->hw_res_config_table;

            Pwm_HwRes[hw_res_id].Instance = (TIM_TypeDef*)_HwResConfigTable[hw_res_id].base_address;
            Pwm_HwRes[hw_res_id].Init.Prescaler = _HwResConfigTable[hw_res_id].prescaler;
            Pwm_HwRes[hw_res_id].Init.CounterMode = _HwResConfigTable[hw_res_id].counter_mode;
            Pwm_HwRes[hw_res_id].Init.Period = _HwResConfigTable[hw_res_id].period_ticks;
            Pwm_HwRes[hw_res_id].Init.AutoReloadPreload = _HwResConfigTable[hw_res_id].enable_period_tick_buffer;
            Pwm_HwRes[hw_res_id].Init.RepetitionCounter = _HwResConfigTable[hw_res_id].repetition_counter;

            if (HAL_TIM_Base_Init(&Pwm_HwRes[hw_res_id]) != HAL_OK) {
                Error_Handler();
            }

            if (HAL_TIM_PWM_Init(&Pwm_HwRes[hw_res_id]) != HAL_OK) {
                Error_Handler();
            }
        }

        for (ch_id = 0; ch_id < ConfigPtr->numbers_of_channels; ch_id++) {
            _ChannelConfigTable = ConfigPtr->channel_config_table;
            channel_hw_res_id = _ChannelConfigTable[ch_id].hw_res_id;

            output_compare_config.OCMode = _ChannelConfigTable[ch_id].output_compare_mode;
            output_compare_config.Pulse = _ChannelConfigTable[ch_id].pulse_ticks;
            output_compare_config.OCPolarity = _ChannelConfigTable[ch_id].output_compare_polarity;

            Pwm_Channel[ch_id] = _ChannelConfigTable[ch_id];

            if (HAL_TIM_PWM_ConfigChannel(&Pwm_HwRes[channel_hw_res_id], &output_compare_config, _ChannelConfigTable[ch_id].hw_id) != HAL_OK) {
                Error_Handler();
            }

            HAL_TIM_PWM_Start(&Pwm_HwRes[channel_hw_res_id], _ChannelConfigTable[ch_id].hw_id);
        }

        for (hw_res_id = 0; hw_res_id < ConfigPtr->number_of_hw_res; hw_res_id++) {
            HAL_TIM_Base_Start_IT(&Pwm_HwRes[hw_res_id]);
        }
    }
}

void Pwm_SetPulseTicks(Pwm_ChannelType ch, uint32_t pulse_ticks)
{
    Pwm_HwResourceType hw_res_id;

    hw_res_id = Pwm_Channel[ch].hw_res_id;

    __HAL_TIM_SET_COMPARE(&Pwm_HwRes[hw_res_id], ch, pulse_ticks);
}

/**********************************************************************************************************************
 *  END OF FILE: pwm.c
 *********************************************************************************************************************/