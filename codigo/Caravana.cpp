//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Caravana.h"
/*
Caravana::Caravana():id(0){

}
Caravana::Caravana(int id, Tipo tipo, int linha, int coluna)
        : id(id),tipo(tipo),linha(linha), coluna(coluna), tripulantes(0), carga(0), agua(0), capacidadeCarga(0), capacidadeAgua(0), consumoAgua(0) {}
*/

int Caravana::proximoId = 1;

Caravana::Caravana(int id,Tipo tipo, int linha, int coluna)
        : id(id), tipo(tipo), linha(linha), coluna(coluna), tripulantes(0), carga(0), agua(0), capacidadeCarga(0), capacidadeAgua(0), consumoAgua(0) {
    if (proximoId > 9) { //Seria melhor contar somente as caravas carregadas do mapa. Aquelas estacionadas não deveriam ser contados (opinião)
        //throw std::runtime_error("Numero maximo de caravanas atingido.");
    }
    proximoId++;
}


//acho aue nao é para uasr
Caravana::Tipo Caravana::getTipo() const {
    return tipo;
}


void Caravana::setId(int newId){
    id = newId;
}

Caravana::~Caravana() {

}
