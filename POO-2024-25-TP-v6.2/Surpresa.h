//
// Created by Carolina Rosa on 02/12/2024.
//

#ifndef POO_2024_25_TP_SURPRESA_H
#define POO_2024_25_TP_SURPRESA_H


#include "Item.h"

class Surpresa : public Item {
public:
    Surpresa(int linha, int coluna, int duracao);
    void aplicarEfeito(shared_ptr<Caravana> caravana,shared_ptr<Jogador> jogador) override;
};


#endif //POO_2024_25_TP_SURPRESA_H
