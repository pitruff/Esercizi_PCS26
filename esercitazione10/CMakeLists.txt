cmake_minimum_required(VERSION 3.20)
project(esercitazione10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

find_package(Eigen3 REQUIRED)

add_executable(gradiente_coniugato gradiente_coniugato.cpp)
add_test(NAME prova_GC COMMAND gradiente_coniugato)

enable_testing()

target_link_libraries(gradiente_coniugato Eigen3::Eigen)

