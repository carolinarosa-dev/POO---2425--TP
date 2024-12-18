//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_CARAVANAMILITAR_H
#define POO_2024_25_TP_CARAVANAMILITAR_H

#include "Caravana.h"

class CaravanaMilitar : public Caravana {
public:

    CaravanaMilitar(int id, int linha, int coluna);
   // CaravanaMilitar(int linha, int coluna);
    ~CaravanaMilitar() override;

    void mover(char direcao) ;
    void aplicarEfeitoItem(int tipoItem) ;
    void esconder();
    //string exibirDetalhes() const;
};

#endif //POO_2024_25_TP_CARAVANAMILITAR_H