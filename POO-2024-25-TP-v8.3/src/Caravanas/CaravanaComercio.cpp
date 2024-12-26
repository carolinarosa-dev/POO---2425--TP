
#include "../../include/Caravanas/CaravanaComercio.h"

CaravanaComercio::CaravanaComercio()
        : Caravana(Tipo::COMERCIO, 0, 0) {
    tripulantes = 20;
    carga = 0;
    agua = 200;
    capacidadeCarga = 40;
    capacidadeAgua = 200;
    consumoAgua = 2;
}

CaravanaComercio::CaravanaComercio(Tipo tipo, int linha, int coluna)
        : Caravana(Tipo::COMERCIO, getPosicaoCaravana().first, getPosicaoCaravana().second) {
    tripulantes = 20;
    carga = 0;
    agua = 200;
    capacidadeCarga = 40;
    capacidadeAgua = 200;
    consumoAgua = 2;
}

std::string CaravanaComercio::getDesignacaoTipo() const {
    return "caravana comercio ";
}

CaravanaComercio::~CaravanaComercio() {

}
