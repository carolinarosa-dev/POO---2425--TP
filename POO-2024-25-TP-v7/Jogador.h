
#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>
#include <sstream>

#include <vector>
#include <memory>

#include "Caravana.h"

class Jogador {
private:
    int moedas;
    int combatesVencidos;           // Número de combates vencidos

public:
    Jogador();
    Jogador(int moedasIniciais);

    int getMoedas() const;
    void adicionarMoedas(int quantidade);

    bool temCaravanas() const;
    std::string listarCaravanas() const;

    void comprarCaravana(std::shared_ptr<Caravana>, int precoCaravana);

    const std::vector<std::shared_ptr<Caravana>>& getCaravanas() const;
    void adicionarCaravana(std::shared_ptr<Caravana> caravana);
};

#endif //POO_2024_25_TP_JOGADOR