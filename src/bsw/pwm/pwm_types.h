#ifndef PWM_TYPES_H
#define PWM_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
    PWM_CH0,
    PWM_CH1,
    PWM_CH2,
    PWM_MAX_CH,
} Pwm_ChannelType;

typedef enum {
    PWM_HWRES0,
    PWM_HWRES1,
    PWM_HWRES2,
    PWM_HWRES3,
    PWM_MAX_HWRES,
} Pwm_HwResourceType;

typedef struct {
    uint32_t base_address;
    uint32_t prescaler;
    uint32_t counter_mode;
    uint32_t period_ticks;
    uint32_t repetition_counter;
    uint32_t enable_period_tick_buffer;
    Pwm_HwResourceType logical_id;
} Pwm_HwResourceConfigType;

typedef struct {
    uint32_t pulse_ticks;
    uint32_t output_compare_mode;
    uint32_t output_compare_polarity;
    uint32_t hw_id;
    Pwm_ChannelType logical_id;
    Pwm_HwResourceType hw_res_id;
} Pwm_ChannelConfigType;

typedef struct {
    Pwm_HwResourceConfigType const* hw_res_config_table;
    Pwm_ChannelConfigType const* channel_config_table;
    uint8_t numbers_of_channels;
    uint8_t number_of_hw_res;
} Pwm_ConfigType;

#endif /* PWM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: pwm_types.h
 *********************************************************************************************************************/
