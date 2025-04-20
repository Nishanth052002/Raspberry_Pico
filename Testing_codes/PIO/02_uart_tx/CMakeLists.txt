cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(02_uart_tx C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(02_uart_tx
    main.c
    02_uart_tx.pio
)

pico_generate_pio_header(02_uart_tx ${CMAKE_CURRENT_LIST_DIR}/02_uart_tx.pio)

target_link_libraries(02_uart_tx pico_stdlib hardware_pio)

pico_add_extra_outputs(02_uart_tx)