//
// Created by Carolina Rosa on 02/12/2024.
//

#ifndef POO_2024_25_TP_MINA_H
#define POO_2024_25_TP_MINA_H


#include "Item.h"

class Mina : public Item {
public:
    Mina(int linha, int coluna, int duracao);
    void aplicarEfeito(std::shared_ptr<Caravana> caravana,shared_ptr<Jogador> jogador) override;
};



#endif //POO_2024_25_TP_MINA_H
