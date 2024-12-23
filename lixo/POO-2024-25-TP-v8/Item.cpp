//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Item.h"

//Para a classe base Item, não precisa de um arquivo Item.cpp porque a classe é abstrata e não contém implementações de métodos que precisam ser definidos fora da classe. As classes derivadas (CaixaDePandora, ArcaDoTesouro, Jaula, Mina, Surpresa) já têm seus próprios arquivos .cpp onde os métodos específicos são implementados.

/*


Item::Item(Tipo tipo, int linha, int coluna, int duracao)
        : tipo(tipo), linha(linha), coluna(coluna), duracao(duracao) {}

Item::Tipo Item::getTipo() const {
    return tipo;
}

int Item::getDuracao() const {
    return duracao;
}

void Item::decrementarDuracao() {
    if (duracao > 0) {
        duracao--;
    }
}
*/
