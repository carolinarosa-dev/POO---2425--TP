//
// Created by Carolina Rosa on 02/12/2024.
//

#include "Montanha.h"

Montanha::Montanha(int linha, int coluna) : Deserto(linha, coluna) {}

void Montanha::configurarMontanhas(const std::vector<std::pair<int, int>>& posicoes) {
    for (const auto& pos : posicoes) {
        int linha = pos.first;
        int coluna = pos.second;
        setMontanha(linha, coluna);
    }
}

void Montanha::adicionaMontanha(int linha, int coluna) { //?? nao pode ter nada

}

int Montanha::getLinha() const {
    return linha;
}

int Montanha::getColuna() const {
    return coluna;
}


