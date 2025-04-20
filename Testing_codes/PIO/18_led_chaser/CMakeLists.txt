cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(18_led_chaser C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(18_led_chaser
    main.c
    18_led_chaser.pio
)

pico_generate_pio_header(18_led_chaser ${CMAKE_CURRENT_LIST_DIR}/18_led_chaser.pio)

target_link_libraries(18_led_chaser pico_stdlib hardware_pio)

pico_add_extra_outputs(18_led_chaser)