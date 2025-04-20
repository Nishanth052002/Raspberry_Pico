cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(08_pwm_generator C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(08_pwm_generator
    main.c
    08_pwm_generator.pio
)

pico_generate_pio_header(08_pwm_generator ${CMAKE_CURRENT_LIST_DIR}/08_pwm_generator.pio)

target_link_libraries(08_pwm_generator pico_stdlib hardware_pio)

pico_add_extra_outputs(08_pwm_generator)