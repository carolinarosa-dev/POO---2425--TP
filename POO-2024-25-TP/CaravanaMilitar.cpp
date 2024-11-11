//
// Created by Carolina Rosa on 10/11/2024.
//

#include "CaravanaMilitar.h"


CaravanaMilitar::CaravanaMilitar(int id, int linha, int coluna)
        : Caravana(MILITAR, id, linha, coluna) {
    tripulantes = 40;
    carga = 0;
    agua = 400;
    capacidadeCarga = 5;
    capacidadeAgua = 400;
    consumoAgua = 3;
}

void CaravanaMilitar::mover(char direcao) {
    // Implementar lógica de movimentação específica para caravana militar
}

void CaravanaMilitar::aplicarEfeitoItem(int tipoItem) {
    // Implementar lógica específica de aplicação de efeito de item
}
