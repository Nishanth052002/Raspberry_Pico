cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(13_parallel_bus_rx C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(13_parallel_bus_rx
    main.c
    13_parallel_bus_rx.pio
)

pico_generate_pio_header(13_parallel_bus_rx ${CMAKE_CURRENT_LIST_DIR}/13_parallel_bus_rx.pio)

target_link_libraries(13_parallel_bus_rx pico_stdlib hardware_pio)

pico_add_extra_outputs(13_parallel_bus_rx)