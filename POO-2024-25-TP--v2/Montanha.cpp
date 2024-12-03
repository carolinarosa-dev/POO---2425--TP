//
// Created by Carolina Rosa on 02/12/2024.
//

#include "Montanha.h"

Montanha::Montanha(int linhas, int colunas) : Deserto(linhas, colunas) {}

void Montanha::configurarMontanhas(const std::vector<std::pair<int, int>>& posicoes) {
    for (const auto& pos : posicoes) {
        int linha = pos.first;
        int coluna = pos.second;
        setMontanha(linha, coluna);
    }
}