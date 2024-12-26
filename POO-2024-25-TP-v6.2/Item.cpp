//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Item.h"

Item::Item(int linha, int coluna, int duracao)
        : linha(linha), coluna(coluna), duracao(duracao) {}

Item::~Item() {}


void Item::aplicarEfeito(std::shared_ptr<Caravana> caravana, std::shared_ptr<Jogador> jogador){}


int Item::getLinha() const {
    return linha;
}

int Item::getColuna() const {
    return coluna;
}

int Item::getDuracao() const {
    return duracao;
}

void Item::diminuirDuracao() {
    duracao--;
}
