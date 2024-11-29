//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Combate.h"
#include <iostream>
#include <cstdlib> // Para a função rand()

void Combate::iniciarCombate(Caravana& c1, Caravana& c2) {
    int sorteioC1 = rand() % (c1.getTripulantes() + 1);
    int sorteioC2 = rand() % (c2.getTripulantes() + 1);

    std::cout << "Sorteio Caravana 1: " << sorteioC1 << std::endl;
    std::cout << "Sorteio Caravana 2: " << sorteioC2 << std::endl;

    if (sorteioC1 > sorteioC2) {
        resolverCombate(c1, c2);
    } else {
        resolverCombate(c2, c1);
    }
}

void Combate::resolverCombate(Caravana& vencedora, Caravana& perdedora) {
    int perdaVencedora = vencedora.getTripulantes() * 0.2;
    int perdaPerdedora = perdaVencedora * 2;

    std::cout << "Perda Caravana Vencedora: " << perdaVencedora << std::endl;
    std::cout << "Perda Caravana Perdedora: " << perdaPerdedora << std::endl;

    vencedora.perderTripulantes(perdaVencedora);
    perdedora.perderTripulantes(perdaPerdedora);

    if (perdedora.estaDestruida()) {
        vencedora.adicionarAgua(perdedora.getAgua());
        perdedora.adicionarAgua(-perdedora.getAgua()); // A caravana perdedora perde toda a sua água
        std::cout << "Caravana perdedora destruída. Água transferida para a caravana vencedora." << std::endl;
    }
}
