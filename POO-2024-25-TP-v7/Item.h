//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_ITEM_H
#define POO_2024_25_TP_ITEM_H

#include <string>
#include <memory>
#include "Caravana.h"

/*
public:
    Tipo getTipo() const;
    int getDuracao() const;
    void decrementarDuracao();
*/

class Item {
public:
    enum Tipo { CAIXA_PANDORA, ARCA_TESOURO, JAULA, MINA, SURPRESA };
    Item(Tipo tipo, int linha, int coluna, int duracao);
    virtual ~Item() = default;
    virtual void aplicarEfeito(std::shared_ptr<Caravana> caravana) = 0;

private:
    Tipo tipo;
    int linha, coluna;
    int duracao;
};



#endif //POO_2024_25_TP_ITEM_H
