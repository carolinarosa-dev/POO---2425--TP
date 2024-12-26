//
// Created by Carolina Rosa on 02/12/2024.
//

#include "Jaula.h"

    Jaula::Jaula(int linha, int coluna, int duracao)
        : Item(linha, coluna, duracao) {}

    void Jaula::aplicarEfeito(std::shared_ptr<Caravana> caravana,shared_ptr<Jogador> jogador)  {
        caravana->adicionarTripulantes(5); // Exemplo de quantidade de prisioneiros
    }



