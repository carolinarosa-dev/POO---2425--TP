
#include "CaravanaMilitar.h"

CaravanaMilitar::CaravanaMilitar(int id, int linha, int coluna)
    : Caravana(id, MILITAR, linha, coluna) {
        tripulantes = 40;
        carga = 0;
        agua = 400;
        capacidadeCarga = 5;
        capacidadeAgua = 400;
        consumoAgua = 3;
}


void CaravanaMilitar::aplicarEfeitoItem(int tipoItem) {
    // Implementar lógica de aplicação de efeito de item específica para Caravana Militar
    std::cout << "Aplicando efeito do item " << tipoItem << " na Caravana Militar" << std::endl;
    //Caravana::aplicarEfeitoItem(tipoItem);
}

std::string CaravanaMilitar::getDesignacaoTipo() const {
        return "caravana militar ";
}

CaravanaMilitar::~CaravanaMilitar() {

}
