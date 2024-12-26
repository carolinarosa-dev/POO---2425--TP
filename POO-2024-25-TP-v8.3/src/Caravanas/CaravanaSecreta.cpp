
#include "../../include/Caravanas/CaravanaSecreta.h"

CaravanaSecreta::CaravanaSecreta(Tipo tipo, int linha, int coluna)
        : Caravana(Tipo::SECRETA, getPosicaoCaravana().first, getPosicaoCaravana().second) {
    tripulantes = 10;
    capacidadeAgua = 100;
    consumoAgua = 1;
}

std::string CaravanaSecreta::getDesignacaoTipo() const {
    return "caravana secreta";
}
CaravanaSecreta::~CaravanaSecreta() {}