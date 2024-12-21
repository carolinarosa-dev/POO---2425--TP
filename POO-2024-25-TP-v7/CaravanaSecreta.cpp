
#include "CaravanaSecreta.h"

CaravanaSecreta::CaravanaSecreta(int id,int linha, int coluna)
        : Caravana(id,Tipo::SECRETA, linha, coluna) {
    tripulantes = 10;
    capacidadeAgua = 100;
    consumoAgua = 1;
}



void CaravanaSecreta::aplicarEfeitoItem(int tipoItem) {
    // Implementar lógica de aplicação de efeito de item específica para Caravana Secreta
    std::cout << "Aplicando efeito do item " << tipoItem << " na Caravana Secreta" << std::endl;
}
void CaravanaSecreta::esconder() {
    // Implementar lógica para esconder a caravana
    std::cout << "Caravana Secreta esta a esconder-se." << std::endl;
}

std::string CaravanaSecreta::getDesignacaoTipo() const {
    return "caravana secreta";
}
CaravanaSecreta::~CaravanaSecreta() {}
