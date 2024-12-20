//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_CARAVANASECRETA_H
#define POO_2024_25_TP_CARAVANASECRETA_H

#include "Caravana.h"

class CaravanaSecreta : public Caravana {
public:

    CaravanaSecreta(int id, int linha, int coluna);
   // CaravanaSecreta(int linha, int coluna);
    ~CaravanaSecreta() override;

    void mover(char direcao) ;
    void aplicarEfeitoItem(int tipoItem) ;
    void esconder();
    string exibirDetalhes() const;
};

#endif //POO_2024_25_TP_CARAVANASECRETA_H