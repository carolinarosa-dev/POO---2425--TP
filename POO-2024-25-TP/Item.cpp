//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Item.h"



Item::Item(Tipo tipo, int linha, int coluna, int duracao)
        : tipo(tipo), linha(linha), coluna(coluna), duracao(duracao) {}

Item::Tipo Item::getTipo() const {
    return tipo;
}

int Item::getLinha() const {
    return linha;
}

int Item::getColuna() const {
    return coluna;
}

int Item::getDuracao() const {
    return duracao;
}

void Item::decrementarDuracao() {
    if (duracao > 0) {
        duracao--;
    }
}
