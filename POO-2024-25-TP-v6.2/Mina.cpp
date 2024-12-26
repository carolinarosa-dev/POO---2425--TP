//
// Created by Carolina Rosa on 02/12/2024.
//

#include "Mina.h"


Mina::Mina(int linha, int coluna, int duracao)
        : Item(linha, coluna, duracao) {}


void Mina::aplicarEfeito(shared_ptr<Caravana> caravana,shared_ptr<Jogador> jogador) {
    caravana->perderTripulantes(caravana->getTripulantes());
}