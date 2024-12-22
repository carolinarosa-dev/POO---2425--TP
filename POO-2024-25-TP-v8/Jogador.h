
#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>
#include <sstream>

#include <vector>
#include <memory>

#include "Caravana.h"

class Jogador {

public:
    Jogador(int moedasIniciais);

    int getMoedas() const;
    void adicionarMoedas(int quantidade);

    bool temCaravanas() const;
    void adicionaCaravanaJogador(std::unique_ptr<Caravana> caravanas);
    std::string getCaravanasJogador() const;

    void comprarCaravana(std::shared_ptr<Caravana>caravanaJogador, int precoCaravana);

    const std::vector<std::shared_ptr<Caravana>>& getCaravanas() const;


private:
    int moedas;
    int combatesVencidos;

    std::vector<std::unique_ptr<Caravana>> caravanasJogador;
};

#endif //POO_2024_25_TP_JOGADOR