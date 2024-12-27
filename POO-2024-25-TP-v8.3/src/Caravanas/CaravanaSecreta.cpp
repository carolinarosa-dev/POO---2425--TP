
#include "../../include/Caravanas/CaravanaSecreta.h"

CaravanaSecreta::CaravanaSecreta(int id, int linha, int coluna, Tipo tipo)
        : Caravana(id, linha, coluna) {
    this->tipo = tipo;
    tripulantes = 10;
    capacidadeAgua = 100;
    consumoAgua = 1;
}

std::string CaravanaSecreta::getDesignacaoTipo() const {
    return "caravana secreta";
}
CaravanaSecreta::~CaravanaSecreta() {}