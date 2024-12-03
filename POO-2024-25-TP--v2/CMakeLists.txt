cmake_minimum_required(VERSION 3.27)
project(POO_2024_25_TP)

set(CMAKE_CXX_STANDARD 20)

add_executable(POO_2024_25_TP main.cpp
        Buffer.h            Buffer.cpp
        Caravana.h          Caravana.cpp
        CaravanaBarbara.h   CaravanaBarbara.cpp
        CaravanaComercio.h  CaravanaComercio.cpp
        CaravanaMilitar.h   CaravanaMilitar.cpp
        CaravanaSecreta.h   CaravanaSecreta.cpp
        Cidade.h            Cidade.cpp
        Comandos.h          Comandos.cpp
        Deserto.h           Deserto.cpp
        Item.h              Item.cpp
        Jogador.h           Jogador.cpp
        Simulador.h         Simulador.cpp

        Montanha.h
        Montanha.cpp
        CaixaPandora.h
        CaixaPandora.cpp
        ArcaTesouro.h
        ArcaTesouro.cpp
        Jaula.h
        Jaula.cpp
        Mina.h
        Mina.cpp
        Surpresa.h
        Surpresa.cpp
)
