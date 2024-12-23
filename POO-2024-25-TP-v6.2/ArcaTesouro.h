//
// Created by Carolina Rosa on 02/12/2024.
//

#ifndef POO_2024_25_TP_ARCATESOURO_H
#define POO_2024_25_TP_ARCATESOURO_H

#include "Item.h"
#include "Jogador.h"

class ArcaTesouro : public Item {
public:
    ArcaTesouro(Jogador& jogador);
    void aplicarEfeito(std::shared_ptr<Caravana> caravana) override;

private:
    Jogador& jogador;
};


#endif //POO_2024_25_TP_ARCATESOURO_H
