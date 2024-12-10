//
// Created by Carolina Rosa on 02/12/2024.
//

#ifndef POO_2024_25_TP_MONTANHA_H
#define POO_2024_25_TP_MONTANHA_H

#include "Deserto.h"

class Montanha : public Deserto {
public:
    Montanha(int linhas, int colunas);
    void configurarMontanhas(const vector<pair<int, int>>& posicoes);
};



#endif //POO_2024_25_TP_MONTANHA_H
