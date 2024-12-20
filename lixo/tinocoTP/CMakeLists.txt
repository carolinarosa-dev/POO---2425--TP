cmake_minimum_required(VERSION 3.29)
project(tinoco)

set(CMAKE_CXX_STANDARD 20)

add_executable(tinoco main.cpp
        Buffer.h Buffer.cpp
        Caravana.h Caravana.cpp
        CaravanaComercio.h CaravanaComercio.cpp
        CaravanaMilitar.h CaravanaMilitar.cpp
        CaravanaSecreta.h CaravanaSecreta.cpp
        Cidade.h Cidade.cpp
        Comandos.h Comandos.cpp
        #Interface.h Interface.cpp
        Simulador.h Simulador.cpp



)
