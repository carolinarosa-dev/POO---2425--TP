//
// Created by Carolina Rosa on 02/12/2024.
//


#include "CaixaPandora.h"

void CaixaPandora::aplicarEfeito(std::shared_ptr<Caravana> caravana) {
    int tripulantes = caravana->getTripulantes();
    int perda = tripulantes * 0.2;
    caravana->perderTripulantes(perda);
}