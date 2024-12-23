//
// Created by Carolina Rosa on 02/12/2024.
//

#include "Mina.h"

void Mina::aplicarEfeito(std::shared_ptr<Caravana> caravana) {
    caravana->perderTripulantes(caravana->getTripulantes());
}