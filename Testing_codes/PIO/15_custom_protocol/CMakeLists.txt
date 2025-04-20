cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(15_custom_protocol C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(15_custom_protocol
    main.c
    15_custom_protocol.pio
)

pico_generate_pio_header(15_custom_protocol ${CMAKE_CURRENT_LIST_DIR}/15_custom_protocol.pio)

target_link_libraries(15_custom_protocol pico_stdlib hardware_pio)

pico_add_extra_outputs(15_custom_protocol)