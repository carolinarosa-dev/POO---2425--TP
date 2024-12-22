//
// Created by Carolina Rosa on 02/12/2024.
//

#ifndef POO_2024_25_TP_MONTANHA_H
#define POO_2024_25_TP_MONTANHA_H

#include "Deserto.h"

class Montanha : public Deserto {
    int linha, coluna;
    //vector<shared_ptr<Montanha>montanhas>;

public:
    Montanha(int linha, int coluna);
    void configurarMontanhas(const vector<pair<int, int>>& posicoes);
    void adicionaMontanha(int linha, int coluna);
    int getLinha()const;
    int getColuna()const;
};



#endif //POO_2024_25_TP_MONTANHA_H
