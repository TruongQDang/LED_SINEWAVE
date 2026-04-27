#include "port_cfg.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>

/**********************************************************************************************************************
 *  PRIVATE MACROS
 *********************************************************************************************************************/
#define PORT_PIN_CONFIG_COUNT (3)

/**********************************************************************************************************************
 *  PRIVATE CONSTANTS
 *********************************************************************************************************************/
static const Port_PinConfigType Port_PinConfig[PORT_PIN_CONFIG_COUNT] = {
    {.port = (uint32_t)GPIOA,
     .pin = GPIO_PIN_0,
     .mode = GPIO_MODE_AF_PP,
     .pull = GPIO_NOPULL,
     .speed = GPIO_SPEED_FREQ_LOW,
     .output_level = GPIO_PIN_RESET},
    {.port = (uint32_t)GPIOA,
     .pin = GPIO_PIN_1,
     .mode = GPIO_MODE_AF_PP,
     .pull = GPIO_NOPULL,
     .speed = GPIO_SPEED_FREQ_LOW,
     .output_level = GPIO_PIN_RESET},
    {.port = (uint32_t)GPIOB,
     .pin = GPIO_PIN_10,
     .mode = GPIO_MODE_AF_PP,
     .pull = GPIO_NOPULL,
     .speed = GPIO_SPEED_FREQ_LOW,
     .output_level = GPIO_PIN_RESET}};

/**********************************************************************************************************************
 *  GLOBAL CONSTANTS
 *********************************************************************************************************************/
Port_ConfigType const Port_Config = {
    .pin_config_ptr = Port_PinConfig,
    .pin_config_count = PORT_PIN_CONFIG_COUNT};

/**********************************************************************************************************************
 *  END OF FILE: port_cfg.c
 *********************************************************************************************************************/
