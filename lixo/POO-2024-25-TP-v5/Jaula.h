//
// Created by Carolina Rosa on 02/12/2024.
//

#ifndef POO_2024_25_TP_JAULA_H
#define POO_2024_25_TP_JAULA_H

#include "Item.h"

class Jaula : public Item {
public:
    void aplicarEfeito(std::shared_ptr<Caravana> caravana) override;
};


#endif //POO_2024_25_TP_JAULA_H
