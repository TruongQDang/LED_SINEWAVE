/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "mcu_cfg.h"
#include "stm32f4xx_hal.h"

/**********************************************************************************************************************
 *  PRIVATE MACROS
 *********************************************************************************************************************/
#define MCU_PERIPH_CLOCK_CONFIG_COUNT (4)
#define MCU_CLOCK_DOMAIN_MASK \
    (RCC_CLOCKTYPE_SYSCLK |   \
     RCC_CLOCKTYPE_HCLK |     \
     RCC_CLOCKTYPE_PCLK1 |    \
     RCC_CLOCKTYPE_PCLK2)

/**********************************************************************************************************************
 *  PRIVATE CONSTANTS
 *********************************************************************************************************************/
static const Mcu_OscillatorConfigType Mcu_OscillatorConfig = {
    .oscillator_type = RCC_OSCILLATORTYPE_HSI,
    .hsi_state = RCC_HSI_ON,
    .hse_state = RCC_HSE_OFF,
    .pll_state = RCC_PLL_ON,
    .pll_source = RCC_PLLSOURCE_HSI,
    .pll_m = 8,
    .pll_n = 90,
    .pll_p = RCC_PLLP_DIV2,
    .pll_q = 2,
    .pll_r = 2,
    .hsi_calibration = RCC_HSICALIBRATION_DEFAULT};

/* APB2 90Mhz - Timer1 */
static const Mcu_ClockConfigType Mcu_ClockConfig = {
    .clock_domain_mask = MCU_CLOCK_DOMAIN_MASK,
    .sysclk_source = RCC_SYSCLKSOURCE_PLLCLK,
    .ahb_div = RCC_SYSCLK_DIV1,
    .apb1_div = RCC_HCLK_DIV2,
    .apb2_div = RCC_HCLK_DIV1,
    .flash_latency = FLASH_LATENCY_2};

static const Mcu_PowerConfigType Mcu_PowerConfig = {
    .voltage_scale = PWR_REGULATOR_VOLTAGE_SCALE3,
};

static const Mcu_PeripheralClockConfigType Mcu_PeriphClockTable[MCU_PERIPH_CLOCK_CONFIG_COUNT] = {
    {
        .periph = MCU_PERIPH_TIM1,
    },
    {
        .periph = MCU_PERIPH_GPIOA,
    },
    {
        .periph = MCU_PERIPH_GPIOB,
    },
};

/**********************************************************************************************************************
 *  GLOBAL CONSTANTS
 *********************************************************************************************************************/
Mcu_ConfigType const Mcu_Config = {
    .oscillator_config_ptr = &Mcu_OscillatorConfig,
    .clock_config_ptr = &Mcu_ClockConfig,
    .power_config_ptr = &Mcu_PowerConfig,
    .periph_clock_config_table = Mcu_PeriphClockTable,
    .periph_clock_count = MCU_PERIPH_CLOCK_CONFIG_COUNT};

/**********************************************************************************************************************
 *  END OF FILE: mcu_cfg.c
 *********************************************************************************************************************/
