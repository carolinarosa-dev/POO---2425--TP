
#include "../include/Caravanas/CaravanaMilitar.h"
CaravanaMilitar::CaravanaMilitar(int id, int linha, int coluna, Tipo tipo)
        : Caravana(id, linha, coluna) {
    this->tipo = tipo;
    tripulantes = 40;
    carga = 0;
    agua = 400;
    capacidadeCarga = 5;
    capacidadeAgua = 400;
    consumoAgua = 3;
}


std::string CaravanaMilitar::getDesignacaoTipo() const {
    return "caravana militar ";
}

CaravanaMilitar::~CaravanaMilitar() {

}