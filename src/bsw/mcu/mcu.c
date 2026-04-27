/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "mcu.h"
#include "mcu_cfg.h"
#include "stm32f4xx_hal.h"
#include "utilities.h"

/**********************************************************************************************************************
 *  PRIVATE FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void mcu_enable_periph_clock(Mcu_PeripheralType periph);

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
void Mcu_Init(Mcu_ConfigType const* ConfigPtr)
{
    RCC_OscInitTypeDef osc;
    RCC_ClkInitTypeDef clk;

    Mcu_OscillatorConfigType const* _Mcu_OscConfig;
    Mcu_PowerConfigType const* _Mcu_PowerConfig;
    Mcu_PeripheralClockConfigType const* _Mcu_PeriphClockTable;
    Mcu_ClockConfigType const* _Mcu_ClockConfig;

    _Mcu_OscConfig = ConfigPtr->oscillator_config_ptr;
    _Mcu_PowerConfig = ConfigPtr->power_config_ptr;
    _Mcu_PeriphClockTable = ConfigPtr->periph_clock_config_table;
    _Mcu_ClockConfig = ConfigPtr->clock_config_ptr;

    /* STM32 HAL */
    HAL_Init();

    /* Power */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(_Mcu_PowerConfig->voltage_scale);

    /* Oscillator */
    osc.OscillatorType = _Mcu_OscConfig->oscillator_type;

    osc.HSIState = _Mcu_OscConfig->hsi_state;
    osc.HSICalibrationValue = _Mcu_OscConfig->hsi_calibration;

    osc.PLL.PLLState = _Mcu_OscConfig->pll_state;
    osc.PLL.PLLSource = _Mcu_OscConfig->pll_source;

    osc.PLL.PLLM = _Mcu_OscConfig->pll_m;
    osc.PLL.PLLN = _Mcu_OscConfig->pll_n;
    osc.PLL.PLLP = _Mcu_OscConfig->pll_p;
    osc.PLL.PLLQ = _Mcu_OscConfig->pll_q;
    osc.PLL.PLLR = _Mcu_OscConfig->pll_r;

    if (HAL_RCC_OscConfig(&osc) != HAL_OK) {
        Error_Handler();
    }

    /* Bus clock */
    clk.ClockType = _Mcu_ClockConfig->clock_domain_mask;
    clk.SYSCLKSource = _Mcu_ClockConfig->sysclk_source;
    clk.AHBCLKDivider = _Mcu_ClockConfig->ahb_div;
    clk.APB1CLKDivider = _Mcu_ClockConfig->apb1_div;
    clk.APB2CLKDivider = _Mcu_ClockConfig->apb2_div;

    if (HAL_RCC_ClockConfig(&clk,
                            _Mcu_ClockConfig->flash_latency) != HAL_OK) {
        Error_Handler();
    }

    /* Peripheral clock */
    for (uint32_t i = 0; i < ConfigPtr->periph_clock_count; i++) {
        mcu_enable_periph_clock(_Mcu_PeriphClockTable[i].periph);
    }
}

/**********************************************************************************************************************
 *  PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
static void mcu_enable_periph_clock(Mcu_PeripheralType periph)
{
    switch (periph) {
        case MCU_PERIPH_TIM1:
            __HAL_RCC_TIM1_CLK_ENABLE();
            break;
        case MCU_PERIPH_GPIOA:
            __HAL_RCC_GPIOA_CLK_ENABLE();
            break;
        case MCU_PERIPH_GPIOB:
            __HAL_RCC_GPIOB_CLK_ENABLE();
            break;
        default:
            break;
    }
}