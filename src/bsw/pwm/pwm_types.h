#ifndef PWM_TYPES_H
#define PWM_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32_t Pwm_TimerType;
typedef uint32_t Pwm_ChannelType;

typedef struct {
    uint32_t trigger_output_ticks;
    uint32_t output_compare_mode;
    uint32_t output_compare_polarity;
    Pwm_ChannelType channel_id;
} Pwm_ChannelConfigType;

typedef struct {
    uint32_t base_address;
    uint32_t prescaler;
    uint32_t counter_mode;
    uint32_t period_ticks;
    uint32_t period_buffer_enabled;
    uint32_t repetition_counter;
    Pwm_ChannelConfigType const* channel_config_ptr;
    uint8_t number_of_channels;
} Pwm_TimerConfigType;

typedef struct {
    Pwm_TimerType timer_handle_id;
    Pwm_ChannelType channel_handle_id;
} Pwm_HandleConfigType;

typedef struct {
    Pwm_TimerConfigType const* timer_config_ptr;
    Pwm_TimerType number_of_timers;
} Pwm_ConfigType;

#endif /* PWM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: pwm_types.h
 *********************************************************************************************************************/
