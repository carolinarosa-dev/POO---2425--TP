
#include "CaravanaSecreta.h"

CaravanaSecreta::CaravanaSecreta(int id,int linha, int coluna)
        : Caravana(id,Tipo::SECRETA, posCaravana(linha, coluna)) {
    tripulantes = 10;
    capacidadeAgua = 100;
    consumoAgua = 1;
}

std::string CaravanaSecreta::getDesignacaoTipo() const {
    return "caravana secreta";
}
CaravanaSecreta::~CaravanaSecreta() {}
