
#ifndef POO_2024_25_TP_JOGADOR_H
#define POO_2024_25_TP_JOGADOR_H

#include <iostream>
#include <string>
#include <sstream>

#include <vector>
#include <memory>

#include "Mapa/Cidade.h"

class Jogador {
public:
    void comprarCaravana(std::unique_ptr<Caravana> caravanaCidade, int preco);  // Método da classe Jogador
    void adicionarCaravana(std::unique_ptr<Caravana> caravana);
    void adicionarMoedas(int quantidade);
    int getMoedas()const;
    std::string exibirDetalheCaravana(int id) const;
    std::vector<std::unique_ptr<Caravana>>& getCaravanas();


private:
    int moedas;
    std::vector<std::unique_ptr<Caravana>> caravanasJogador;  // Vetor de caravanas do jogador

};

#endif //POO_2024_25_TP_JOGADOR_H