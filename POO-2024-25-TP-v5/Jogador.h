//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef JOGADOR_H
#define JOGADOR_H
#include <memory>
#include <vector>


#include"Simulador.h"

class Caravana;

using namespace std;

class Jogador {
private:
    int moedas;
    vector<shared_ptr<Caravana>> caravanas; // DONO

public:
    Jogador(int moedasIniciais);
    void comprarCaravana(std::shared_ptr<Caravana>, int precoCaravana);
    void adicionarMoedas(int quantidade);
    int getMoedas() const;
    bool temCaravanas() const;
    void listarCaravanas() const;
    const vector<shared_ptr<Caravana>>& getCaravanas() const;
    void adicionarCaravana(std::shared_ptr<Caravana> caravana);
};

#endif //POO_2024_25_TP_JOGADOR_H