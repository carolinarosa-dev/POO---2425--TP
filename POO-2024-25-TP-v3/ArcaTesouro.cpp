//
// Created by Carolina Rosa on 02/12/2024.
//


#include "ArcaTesouro.h"

ArcaTesouro::ArcaTesouro(Jogador& jogador) : jogador(jogador) {}

void ArcaTesouro::aplicarEfeito(std::shared_ptr<Caravana> caravana) {
    int moedas = jogador.getMoedas();
    jogador.adicionarMoedas(moedas * 0.1);
}