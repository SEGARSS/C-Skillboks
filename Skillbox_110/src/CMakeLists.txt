cmake_minimum_required(VERSION 3.17)

add_executable(Skillbox_110
    Skillbox_110.cpp
    medical_tools.cpp
    ${PRJ_INCLUDE_DIR}/medical_tools.h
)

target_include_directories(Skillbox_110 PUBLIC ${PRJ_INCLUDE_DIR})