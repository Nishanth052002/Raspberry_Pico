cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(19_pio_dma C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(19_pio_dma
    main.c
    19_pio_dma.pio
)

pico_generate_pio_header(19_pio_dma ${CMAKE_CURRENT_LIST_DIR}/19_pio_dma.pio)

target_link_libraries(19_pio_dma pico_stdlib hardware_pio)

pico_add_extra_outputs(19_pio_dma)