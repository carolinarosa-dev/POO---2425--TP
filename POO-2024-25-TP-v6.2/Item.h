//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_ITEM_H
#define POO_2024_25_TP_ITEM_H

#include <string>
#include <memory>
#include "Caravana.h"



class Item {
protected:
    int linha, coluna;
    int duracao; // Duração em instantes que o item permanece no deserto

public:
    Item(int linha, int coluna, int duracao);
    virtual ~Item();
    virtual void aplicarEfeito(std::shared_ptr<Caravana> caravana,shared_ptr<Jogador> jogador) = 0;
    int getLinha() const;
    int getColuna() const;
    int getDuracao() const;
    void diminuirDuracao();
};



#endif //POO_2024_25_TP_ITEM_H
