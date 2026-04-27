/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "interrupt_types.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DEFINTIONS
 *********************************************************************************************************************/
void Intr_Init(Intr_ConfigType const* ConfigPtr)
{
    uint32_t i;
    Intr_IrqConfigType const* _Intr_IrqConfig;

    for (i = 0; i < ConfigPtr->irq_config_count; i++) {
        _Intr_IrqConfig = &ConfigPtr->irq_config_ptr[i];
        HAL_NVIC_SetPriority(_Intr_IrqConfig->irqn,
                             _Intr_IrqConfig->preempt_priority, _Intr_IrqConfig->sub_priority);

        HAL_NVIC_EnableIRQ(_Intr_IrqConfig->irqn);
    }
}

/**********************************************************************************************************************
 *  END OF FILE: interrupt.c
 *********************************************************************************************************************/
