cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(11_vga_output C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(11_vga_output
    main.c
    11_vga_output.pio
)

pico_generate_pio_header(11_vga_output ${CMAKE_CURRENT_LIST_DIR}/11_vga_output.pio)

target_link_libraries(11_vga_output pico_stdlib hardware_pio)

pico_add_extra_outputs(11_vga_output)