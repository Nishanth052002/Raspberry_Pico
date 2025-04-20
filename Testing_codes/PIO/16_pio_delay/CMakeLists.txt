cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(16_pio_delay C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(16_pio_delay
    main.c
    16_pio_delay.pio
)

pico_generate_pio_header(16_pio_delay ${CMAKE_CURRENT_LIST_DIR}/16_pio_delay.pio)

target_link_libraries(16_pio_delay pico_stdlib hardware_pio)

pico_add_extra_outputs(16_pio_delay)