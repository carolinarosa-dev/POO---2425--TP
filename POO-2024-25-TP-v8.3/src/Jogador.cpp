#include "../include/Jogador.h"

void Jogador::comprarCaravana(std::unique_ptr<Caravana> caravanaCidade, int preco) {
    caravanasJogador.push_back(std::move(caravanaCidade));
}