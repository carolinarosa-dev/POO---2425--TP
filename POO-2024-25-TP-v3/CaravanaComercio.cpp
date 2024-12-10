//
// Created by Carolina Rosa on 10/11/2024.
//

#include "CaravanaComercio.h"




CaravanaComercio::CaravanaComercio(int id, int linha, int coluna)
        : Caravana(id, COMERCIO,  linha, coluna) {
    tripulantes = 20;
    carga = 0;
    agua = 200;
    capacidadeCarga = 40;
    capacidadeAgua = 200;
    consumoAgua = 2;
}

void CaravanaComercio::mover(char direcao){
    cout << "Movendo Caravana de Comércio na direção " << direcao << endl;
    // Implementar lógica de movimentação específica para caravana de comércio
}

void CaravanaComercio::aplicarEfeitoItem(int tipoItem) {
    // Implementar lógica específica de aplicação de efeito de item
    cout << "Aplicando efeito do item " << tipoItem << " na Caravana de Comércio" << endl;
}
void CaravanaComercio::esconder() {
    // Implementar lógica para esconder a caravana
    std::cout << "Caravana Secreta está se escondendo." << std::endl;
}

string CaravanaComercio::exibirDetalhes() const {
    ostringstream oss;
    oss << "Caravana de Comércio ID: " << id << ", Tripulantes: " << tripulantes << "\n";
    return oss.str();
}
