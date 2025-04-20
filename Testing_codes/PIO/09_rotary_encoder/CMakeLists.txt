cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(09_rotary_encoder C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(09_rotary_encoder
    main.c
    09_rotary_encoder.pio
)

pico_generate_pio_header(09_rotary_encoder ${CMAKE_CURRENT_LIST_DIR}/09_rotary_encoder.pio)

target_link_libraries(09_rotary_encoder pico_stdlib hardware_pio)

pico_add_extra_outputs(09_rotary_encoder)