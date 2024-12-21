
#include "CaravanaComercio.h"

CaravanaComercio::CaravanaComercio()
    : Caravana(0,Tipo::COMERCIO, 0, 0) {
        tripulantes = 20;
        carga = 0;
        agua = 200;
        capacidadeCarga = 40;
        capacidadeAgua = 200;
        consumoAgua = 2;
}

CaravanaComercio::CaravanaComercio(int id, int linha, int coluna)
    : Caravana(id,Tipo::COMERCIO, linha, coluna) {
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

void CaravanaComercio::aplicarEfeitoItem(int tipoItem) {
    // Implementar lógica específica de aplicação de efeito de item
    std::cout << "Aplicando efeito do item " << tipoItem << " na Caravana de Comercio" << std::endl;
    //Caravana::aplicarEfeitoItem(tipoItem);
}
