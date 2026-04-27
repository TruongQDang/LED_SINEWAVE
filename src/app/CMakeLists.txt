# ------------------------------------------
# Linker script, map file
# ------------------------------------------
set(MAP_FILE "${CMAKE_BINARY_DIR}/${EXE_NAME_CM4}.map")
set(LINKER_SCRIPT_FLASH_CM4 "${CMAKE_SOURCE_DIR}/platform/linker_script/STM32F446RETX_FLASH.ld")
set(LINKER_SCRIPT_RAM_CM4 "${CMAKE_SOURCE_DIR}/platform/linker_script/STM32F446RETX_RAM.ld")
if("${MEMORY_LAYOUT}" STREQUAL "FLASH")
    set(LINKER_SCRIPT_CM4 "${LINKER_SCRIPT_FLASH_CM4}")
else()
    set(LINKER_SCRIPT_CM4 "${LINKER_SCRIPT_RAM_CM4}")
endif()

# ------------------------------------------
# Source, include, library
# ------------------------------------------
add_executable(${EXE_NAME_CM4}
    main/main.c
    main/main_task.c
    main/main_intr.c
    led_effect/led_effect.c
    led_effect/lut_cfg.c
    ${CMAKE_SOURCE_DIR}/platform/startup/startup_stm32f446retx.s
    ${CMAKE_SOURCE_DIR}/platform/startup/system_stm32f4xx.c
)

target_compile_definitions(${EXE_NAME_CM4} PRIVATE
)

target_include_directories(${EXE_NAME_CM4} PRIVATE
    led_effect
    main
)

target_link_libraries(${EXE_NAME_CM4} PRIVATE
    ${BSW_NAME_CM4}
)

target_compile_options(${EXE_NAME_CM4} PRIVATE
    ${ARCH_FLAGS_CM4}
)

target_link_options(${EXE_NAME_CM4} PRIVATE
    -Wl,-Map=${MAP_FILE},--cref
    "-T${LINKER_SCRIPT_CM4}"
    ${ARCH_FLAGS_CM4}
)