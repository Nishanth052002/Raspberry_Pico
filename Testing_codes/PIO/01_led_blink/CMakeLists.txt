cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(01_led_blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(01_led_blink
    main.c
    01_led_blink.pio
)

pico_generate_pio_header(01_led_blink ${CMAKE_CURRENT_LIST_DIR}/01_led_blink.pio)

target_link_libraries(01_led_blink pico_stdlib hardware_pio)

pico_add_extra_outputs(01_led_blink)