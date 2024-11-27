cmake_minimum_required(VERSION 3.27)
project(POO_2024_25_TP)

set(CMAKE_CXX_STANDARD 20)

add_executable(POO_2024_25_TP main.cpp
        Simulador.cpp
        Buffer.h
        Buffer.cpp
        Deserto.h
        Deserto.cpp
        Item.h
        Item.cpp
        Caravana.h
        Caravana.cpp
        CaravanaComercio.h
        CaravanaComercio.cpp
        CaravanaMilitar.h
        CaravanaMilitar.cpp
        CaravanaSecreta.h
        CaravanaSecreta.cpp
        Combate.h
        Combate.cpp
        Simulador.h
        Comandos.cpp
        Cidade.h
        Cidade.cpp
        Jogador.h
)
