cmake_minimum_required(VERSION 3.27)
project(POO_2024_25_TP)

set(CMAKE_CXX_STANDARD 20)


# Caminho para os diretórios de include
include_directories(include)

# Procurar todos os arquivos .cpp automaticamente
file(GLOB_RECURSE SOURCES src/*.cpp)

# Executável principal (main.cpp)
add_executable(POO_2024_25_TP main.cpp ${SOURCES})