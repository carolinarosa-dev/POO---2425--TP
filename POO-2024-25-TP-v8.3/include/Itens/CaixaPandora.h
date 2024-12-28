//
// Created by Carolina Rosa on 02/12/2024.
//

#ifndef POO_2024_25_TP_CAIXAPANDORA_H
#define POO_2024_25_TP_CAIXAPANDORA_H


#include "../include/Itens/item.h"

class CaixaPandora : public Item {
public:
    void aplicarEfeito(std::shared_ptr<Caravana> caravana) override;
};


#endif //POO_2024_25_TP_CAIXAPANDORA_H
