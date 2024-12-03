//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_ITEM_H
#define POO_2024_25_TP_ITEM_H

#include <string>
#include <memory>
#include "Caravana.h"

/*
class Item {
public:
    enum Tipo { CAIXA_PANDORA, ARCA_TESOURO, JAULA, MINA, SURPRESA };

    Item(Tipo tipo, int linha, int coluna, int duracao);
    Tipo getTipo() const;
    int getLinha() const;
    int getColuna() const;
    int getDuracao() const;
    void decrementarDuracao();

private:
    Tipo tipo;
    int linha, coluna;
    int duracao;
};
*/


class Item {
public:
    virtual ~Item() = default;
    virtual void aplicarEfeito(std::shared_ptr<Caravana> caravana) = 0;
};



#endif //POO_2024_25_TP_ITEM_H
