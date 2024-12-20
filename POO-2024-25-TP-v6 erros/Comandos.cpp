//
// Created by Carolina Rosa on 10/11/2024.
//
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <filesystem>

#include "Comandos.h"
#include "Cidade.h"
#include "Caravana.h"
#include "CaravanaComercio.h"
#include "CaravanaMilitar.h"
#include "CaravanaSecreta.h"
#include "CaravanaBarbara.h"
#include "Montanha.h"

Comandos::Comandos(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    bufferAtual = new Buffer(linhas, colunas);
    mapa = new char*[linhas];
    for(int i = 0; i<linhas; i++){
        mapa[i] = new char[colunas];
    }
    simulador = std::make_shared<Simulador>(linhas, colunas, bufferAtual);

}

Comandos::Comandos() : linhas(0), colunas(0), moedas(0),
                       instantesEntreNovosItens(0), duracaoItem(0),
                       maxItens(0), precoCaravana(0),
                       instantesEntreNovosBarbaros(0), duracaoBarbaros(0) {
    simulador = nullptr;
}


Comandos::~Comandos() {
    delete bufferAtual;
    for (auto& pair : buffersSalvos) {
        delete pair.second;
    }
}
