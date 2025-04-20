cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(10_ir_transmit C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(10_ir_transmit
    main.c
    10_ir_transmit.pio
)

pico_generate_pio_header(10_ir_transmit ${CMAKE_CURRENT_LIST_DIR}/10_ir_transmit.pio)

target_link_libraries(10_ir_transmit pico_stdlib hardware_pio)

pico_add_extra_outputs(10_ir_transmit)