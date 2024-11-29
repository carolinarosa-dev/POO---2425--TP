//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_JOGADOR_H
#define POO_2024_25_TP_JOGADOR_H

#include"Caravana.h"


class Jogador {
    private:
        int moedas;
        std::vector<Caravana> caravanas;

    public:
        Jogador(int moedasIniciais);
        void comprarCaravana(char tipo);
        void adicionarMoedas(int quantidade);
        int getMoedas();
        bool temCaravanas();
    };

#endif //POO_2024_25_TP_JOGADOR_H
