#ifndef MCU_TYPES_H
#define MCU_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
    MCU_PERIPH_GPIOA,
    MCU_PERIPH_GPIOB,
    MCU_PERIPH_TIM1,
    MCU_PERIPH_MAX
} Mcu_PeripheralType;

typedef struct {
    uint32_t clock_domain_mask;
    uint32_t sysclk_source;
    uint32_t ahb_div;
    uint32_t apb1_div;
    uint32_t apb2_div;
    uint32_t flash_latency;
} Mcu_ClockConfigType;

typedef struct {
    uint8_t oscillator_type;
    uint8_t hsi_state;
    uint8_t hse_state;

    uint8_t pll_state;
    uint8_t pll_source;

    uint8_t pll_m;
    uint8_t pll_n;
    uint8_t pll_p;
    uint8_t pll_q;
    uint8_t pll_r;

    uint8_t hsi_calibration;
} Mcu_OscillatorConfigType;

typedef struct {
    uint32_t voltage_scale;
} Mcu_PowerConfigType;

typedef struct {
    Mcu_PeripheralType periph;
} Mcu_PeripheralClockConfigType;

typedef struct {
    Mcu_OscillatorConfigType const* oscillator_config_ptr;
    Mcu_ClockConfigType const* clock_config_ptr;
    Mcu_PowerConfigType const* power_config_ptr;
    Mcu_PeripheralClockConfigType const* periph_clock_config_table;
    uint32_t periph_clock_count;
} Mcu_ConfigType;

#endif /* MCU_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: mcu_types.h
 *********************************************************************************************************************/
