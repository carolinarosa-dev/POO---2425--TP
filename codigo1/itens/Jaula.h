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
//
// Created by Carolina Rosa on 02/12/2024.
//

#include "Jaula.h"

void Jaula::aplicarEfeito(std::shared_ptr<Caravana> caravana) {
    int tripulantes = caravana->getTripulantes();
   // int capacidade = caravana->getCapacidadeTripulantes();
  //  int novosTripulantes = std::min(capacidade - tripulantes, 10);
  //  caravana->adicionarTripulantes(novosTripulantes);
}
