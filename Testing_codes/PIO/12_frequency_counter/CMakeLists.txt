cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(12_frequency_counter C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(12_frequency_counter
    main.c
    12_frequency_counter.pio
)

pico_generate_pio_header(12_frequency_counter ${CMAKE_CURRENT_LIST_DIR}/12_frequency_counter.pio)

target_link_libraries(12_frequency_counter pico_stdlib hardware_pio)

pico_add_extra_outputs(12_frequency_counter)