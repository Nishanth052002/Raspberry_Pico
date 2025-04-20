cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(04_ws2812_driver C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(04_ws2812_driver
    main.c
    04_ws2812_driver.pio
)

pico_generate_pio_header(04_ws2812_driver ${CMAKE_CURRENT_LIST_DIR}/04_ws2812_driver.pio)

target_link_libraries(04_ws2812_driver pico_stdlib hardware_pio)

pico_add_extra_outputs(04_ws2812_driver)