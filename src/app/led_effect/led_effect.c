#include "lut_cfg.h"
#include "pwm.h"
#include "pwm_cfg.h"
#include <stdint.h>

volatile uint32_t Ind_A = 0;
volatile uint32_t Ind_B = PHASE;
volatile uint32_t Ind_C = 2 * PHASE;

void LedEffect(void)
{
    Pwm_SetDutyCycle(&Pwm_PhaseAHandle, LedLut[Ind_A]);
    Pwm_SetDutyCycle(&Pwm_PhaseBHandle, LedLut[Ind_B]);
    Pwm_SetDutyCycle(&Pwm_PhaseCHandle, LedLut[Ind_C]);

    Ind_A = (Ind_A + 1) & (LED_LUT_COUNT - 1);
    Ind_B = (Ind_B + 1) & (LED_LUT_COUNT - 1);
    Ind_C = (Ind_C + 1) & (LED_LUT_COUNT - 1);
}