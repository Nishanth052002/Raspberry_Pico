cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(07_square_wave C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(07_square_wave
    main.c
    07_square_wave.pio
)

pico_generate_pio_header(07_square_wave ${CMAKE_CURRENT_LIST_DIR}/07_square_wave.pio)

target_link_libraries(07_square_wave pico_stdlib hardware_pio)

pico_add_extra_outputs(07_square_wave)