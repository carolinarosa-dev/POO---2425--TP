
#include "../../include/Caravanas/CaravanaMilitar.h"
CaravanaMilitar::CaravanaMilitar(Tipo tipo, int linha, int coluna)
        : Caravana(MILITAR, getPosicaoCaravana().first, getPosicaoCaravana().second) {
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