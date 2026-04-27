# ------------------------------------------
# Library
# ------------------------------------------
add_library(${BSW_NAME_CM4}
    pwm/pwm.c
    pwm/pwm_cfg.c
    port/port_cfg.c
    port/port.c
    mcu/mcu_cfg.c
    mcu/mcu.c
    interrupt/interrupt.c
    interrupt/interrupt_cfg.c
    utilities/utilities.c
    stm32_hal/Src/stm32f4xx_hal_tim.c
    stm32_hal/Src/stm32f4xx_hal_tim_ex.c
    stm32_hal/Src/stm32f4xx_hal_dma.c
    stm32_hal/Src/stm32f4xx_hal_dma_ex.c
    stm32_hal/Src/stm32f4xx_hal.c
    stm32_hal/Src/stm32f4xx_hal_cortex.c
    stm32_hal/Src/stm32f4xx_hal_rcc.c
    stm32_hal/Src/stm32f4xx_hal_rcc_ex.c
    stm32_hal/Src/stm32f4xx_hal_gpio.c
)

target_compile_definitions(${BSW_NAME_CM4} PUBLIC
    STM32F446xx
    USE_HAL_DRIVER
)

target_include_directories(${BSW_NAME_CM4} PUBLIC
    pwm
    mcu
    port
    utilities
    interrupt
    ${CMAKE_SOURCE_DIR}/platform/cmsis
    stm32_hal/Inc
)

target_link_libraries(${BSW_NAME_CM4} PUBLIC
)

target_compile_options(${BSW_NAME_CM4} PUBLIC
    ${ARCH_FLAGS_CM4}
)

target_link_options(${BSW_NAME_CM4} PUBLIC
)