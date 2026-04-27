cmake_minimum_required(VERSION 3.16)
project(foc_led C CXX ASM)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------------
# Validate build type
# ------------------------------------------
set(VALID_BUILD_TYPES Debug Release)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${VALID_BUILD_TYPES})

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
elseif(NOT CMAKE_BUILD_TYPE IN_LIST VALID_BUILD_TYPES)
    message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
endif()

# ------------------------------------------
# Validate memory layout
# ------------------------------------------
set(VALID_MEMORY_LAYOUT FLASH RAM)
set(MEMORY_LAYOUT "" CACHE STRING "Memory layout selection")
set_property(CACHE MEMORY_LAYOUT PROPERTY STRINGS ${VALID_MEMORY_LAYOUT})

if(NOT MEMORY_LAYOUT)
    set(MEMORY_LAYOUT FLASH CACHE STRING "Memory layout selection" FORCE)
elseif(NOT MEMORY_LAYOUT IN_LIST VALID_MEMORY_LAYOUT)
    message(FATAL_ERROR "Invalid memory layout: ${MEMORY_LAYOUT}")
endif()

# ------------------------------------------
# Architecture
# ------------------------------------------
set(ARCH_FLAGS_CM4
    -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard
)

# ------------------------------------------
# Executable & Library name
# ------------------------------------------
set(EXE_NAME_CM4 ${PROJECT_NAME}_cm4)
set(BSW_NAME_CM4 ${PROJECT_NAME}_bsw_cm4)

# ------------------------------------------
# Source files
# ------------------------------------------
add_subdirectory(src/app)
add_subdirectory(src/bsw)

# ------------------------------------------
# Utilities
# ------------------------------------------
# Size inspection
add_custom_target(size ALL
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXE_NAME_CM4}>
)