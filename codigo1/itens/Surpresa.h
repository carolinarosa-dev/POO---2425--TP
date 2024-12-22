//
// Created by Carolina Rosa on 02/12/2024.
//

#ifndef POO_2024_25_TP_SURPRESA_H
#define POO_2024_25_TP_SURPRESA_H


#include "Item.h"

class Surpresa : public Item {
public:
    void aplicarEfeito(std::shared_ptr<Caravana> caravana) override;
};


#endif //POO_2024_25_TP_SURPRESA_H
//
// Created by Carolina Rosa on 02/12/2024.
//

#include "Surpresa.h"

void Surpresa::aplicarEfeito(std::shared_ptr<Caravana> caravana) {
    // Implementar lógica surpresa
    caravana->adicionarTripulantes(5); // Exemplo de efeito surpresa
}
