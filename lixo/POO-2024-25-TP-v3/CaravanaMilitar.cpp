//
// Created by Carolina Rosa on 10/11/2024.
//

#include "CaravanaMilitar.h"

CaravanaMilitar::CaravanaMilitar(int id, int linha, int coluna) : Caravana(id, MILITAR, linha, coluna) {
    tripulantes = 40;
carga = 0;
agua = 400;
capacidadeCarga = 5;
capacidadeAgua = 400;
consumoAgua = 3;

}




void CaravanaMilitar::mover(char direcao) {
    // Implementar lógica de movimentação específica para Caravana Militar
    std::cout << "Movendo Caravana Militar na direção " << direcao << std::endl;
}

void CaravanaMilitar::aplicarEfeitoItem(int tipoItem) {
    // Implementar lógica de aplicação de efeito de item específica para Caravana Militar
    std::cout << "Aplicando efeito do item " << tipoItem << " na Caravana Militar" << std::endl;
}
void CaravanaMilitar::esconder() {
    // Implementar lógica para esconder a caravana
    std::cout << "Caravana Secreta está se escondendo." << std::endl;
}

string CaravanaMilitar::exibirDetalhes() const {
    ostringstream oss;
    oss << "Caravana Militar ID: " << id << ", Tripulantes: " << tripulantes << "\n";
    return oss.str();
}



