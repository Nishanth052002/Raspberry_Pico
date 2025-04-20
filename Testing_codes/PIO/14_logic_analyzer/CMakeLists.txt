cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(14_logic_analyzer C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(14_logic_analyzer
    main.c
    14_logic_analyzer.pio
)

pico_generate_pio_header(14_logic_analyzer ${CMAKE_CURRENT_LIST_DIR}/14_logic_analyzer.pio)

target_link_libraries(14_logic_analyzer pico_stdlib hardware_pio)

pico_add_extra_outputs(14_logic_analyzer)