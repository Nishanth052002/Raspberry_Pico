cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(03_uart_rx C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(03_uart_rx
    main.c
    03_uart_rx.pio
)

pico_generate_pio_header(03_uart_rx ${CMAKE_CURRENT_LIST_DIR}/03_uart_rx.pio)

target_link_libraries(03_uart_rx pico_stdlib hardware_pio)

pico_add_extra_outputs(03_uart_rx)