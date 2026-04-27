/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "port.h"
#include "port_cfg.h"
#include "stm32f4xx_hal.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
void Port_Init(Port_ConfigType const* ConfigPtr)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    Port_PinConfigType const* _Port_PinConfig;
    uint32_t pinNum;

    for (pinNum = 0; pinNum < ConfigPtr->pin_config_count; pinNum++) {
        _Port_PinConfig = &ConfigPtr->pin_config_ptr[pinNum];

        if (_Port_PinConfig->mode == GPIO_MODE_OUTPUT_PP || _Port_PinConfig->mode == GPIO_MODE_OUTPUT_OD) {
            HAL_GPIO_WritePin((GPIO_TypeDef*)_Port_PinConfig->port, _Port_PinConfig->pin, (GPIO_PinState)_Port_PinConfig->output_level);
        }

        GPIO_InitStruct.Pin = _Port_PinConfig->pin;
        GPIO_InitStruct.Mode = _Port_PinConfig->mode;
        GPIO_InitStruct.Pull = _Port_PinConfig->pull;
        GPIO_InitStruct.Speed = _Port_PinConfig->speed;

        HAL_GPIO_Init((GPIO_TypeDef*)_Port_PinConfig->port, &GPIO_InitStruct);
    }
}

/**********************************************************************************************************************
 *  END OF FILE: port.c
 *********************************************************************************************************************/
