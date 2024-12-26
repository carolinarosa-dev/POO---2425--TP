//
// Created by Carolina Rosa on 02/12/2024.
//

#include "Surpresa.h"


Surpresa::Surpresa(int linha, int coluna, int duracao)
        : Item(linha, coluna, duracao) {}

void Surpresa::aplicarEfeito(std::shared_ptr<Caravana> caravana,shared_ptr<Jogador> jogador) {

//  Adicionar ou remover tripulantes aleatoriamente
    int efeito = rand() % 2;
    if (efeito == 0) {
        caravana->adicionarTripulantes(10);
    } else {
        caravana->perderTripulantes(10);
    }
}

