//
// Created by Carolina Rosa on 02/12/2024.
//


#include "ArcaTesouro.h"

ArcaTesouro::ArcaTesouro(int linha, int coluna, int duracao)
        : Item(linha, coluna, duracao) {}



void ArcaTesouro::aplicarEfeito(std::shared_ptr<Caravana> caravana, std::shared_ptr<Jogador> jogador) {
jogador->adicionarMoedas(static_cast<int>(jogador->getMoedas() * 0.1));
}