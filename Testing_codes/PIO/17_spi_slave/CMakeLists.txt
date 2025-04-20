cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(17_spi_slave C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(17_spi_slave
    main.c
    17_spi_slave.pio
)

pico_generate_pio_header(17_spi_slave ${CMAKE_CURRENT_LIST_DIR}/17_spi_slave.pio)

target_link_libraries(17_spi_slave pico_stdlib hardware_pio)

pico_add_extra_outputs(17_spi_slave)