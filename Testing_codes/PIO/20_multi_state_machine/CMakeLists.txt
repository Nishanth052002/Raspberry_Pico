cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(20_multi_state_machine C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(20_multi_state_machine
    main.c
    20_multi_state_machine.pio
)

pico_generate_pio_header(20_multi_state_machine ${CMAKE_CURRENT_LIST_DIR}/20_multi_state_machine.pio)

target_link_libraries(20_multi_state_machine pico_stdlib hardware_pio)

pico_add_extra_outputs(20_multi_state_machine)