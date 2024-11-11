//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_COMBATE_H
#define POO_2024_25_TP_COMBATE_H


#include "Caravana.h"

class Combate {
public:
    static void iniciarCombate(Caravana& c1, Caravana& c2);

private:
    static void resolverCombate(Caravana& vencedora, Caravana& perdedora);
};




#endif //POO_2024_25_TP_COMBATE_H
