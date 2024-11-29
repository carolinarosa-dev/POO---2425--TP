//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_JOGADOR_H
#define POO_2024_25_TP_JOGADOR_H

#include <memory>
#include <vector>

#include"Simulador.h"
class Caravana;

using namespace std;

class Jogador {
    private:
        int moedas;
        std::vector<shared_ptr<Caravana>> caravanas;//DONO

    public:
        Jogador(int moedasIniciais);
        void comprarCaravana(char tipo);
        void adicionarMoedas(int quantidade);
        int getMoedas();
        bool temCaravanas();
    };

#endif //POO_2024_25_TP_JOGADOR_H
