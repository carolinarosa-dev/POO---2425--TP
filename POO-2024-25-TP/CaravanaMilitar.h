//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_CARAVANAMILITAR_H
#define POO_2024_25_TP_CARAVANAMILITAR_H



#include "Caravana.h"

class CaravanaMilitar : public Caravana {
public:
    CaravanaMilitar(int id, int linha, int coluna);
    void mover(char direcao) override;
    void aplicarEfeitoItem(int tipoItem) override;
};


#endif //POO_2024_25_TP_CARAVANAMILITAR_H
