cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(05_i2c_master C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(05_i2c_master
    main.c
    05_i2c_master.pio
)

pico_generate_pio_header(05_i2c_master ${CMAKE_CURRENT_LIST_DIR}/05_i2c_master.pio)

target_link_libraries(05_i2c_master pico_stdlib hardware_pio)

pico_add_extra_outputs(05_i2c_master)