cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(06_spi_master C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(06_spi_master
    main.c
    06_spi_master.pio
)

pico_generate_pio_header(06_spi_master ${CMAKE_CURRENT_LIST_DIR}/06_spi_master.pio)

target_link_libraries(06_spi_master pico_stdlib hardware_pio)

pico_add_extra_outputs(06_spi_master)