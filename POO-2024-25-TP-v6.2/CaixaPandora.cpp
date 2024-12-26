//
// Created by Carolina Rosa on 02/12/2024.
//


#include "CaixaPandora.h"

CaixaPandora:: CaixaPandora(int linha, int coluna, int duracao)
        : Item(linha, coluna, duracao) {}


void CaixaPandora::aplicarEfeito(std::shared_ptr<Caravana> caravana,shared_ptr<Jogador> jogador) {
    int tripulantes = caravana->getTripulantes();
    int perda = tripulantes * 0.2;
    caravana->perderTripulantes(perda);
}