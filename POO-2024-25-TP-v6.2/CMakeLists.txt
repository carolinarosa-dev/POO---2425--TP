cmake_minimum_required(VERSION 3.29)
project(POO_2024_25_TP_v6_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(POO_2024_25_TP_v6_1 main.cpp
        ArcaTesouro.h       ArcaTesouro.cpp
        Buffer.h            Buffer.cpp
        CaixaPandora.h      CaixaPandora.cpp
        Caravana.h          Caravana.cpp
        CaravanaBarbara.h   CaravanaBarbara.cpp
        CaravanaComercio.h  CaravanaComercio.cpp
        CaravanaMilitar.h   CaravanaMilitar.cpp
        CaravanaSecreta.h   CaravanaSecreta.cpp
        Cidade.h            Cidade.cpp
        Comandos.h          Comandos.cpp
        Deserto.h           Deserto.cpp
        Item.h              Item.cpp
        Jaula.h             Jaula.cpp
        Jogador.h           Jogador.cpp
        Mina.h              Mina.cpp
        Montanha.h          Montanha.cpp
        Simulador.h         Simulador.cpp
        Surpresa.h          Surpresa.cpp
)
