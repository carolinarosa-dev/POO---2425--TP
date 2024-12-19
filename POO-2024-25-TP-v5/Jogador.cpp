//
// Created by Carolina Rosa on 10/11/2024.
//



//#include"Caravana.h"

#include "Jogador.h"
#include "CaravanaComercio.h"
#include "CaravanaMilitar.h"
#include "CaravanaSecreta.h"
#include <iostream>

class Caravana;

Jogador::Jogador(int moedasIniciais) : moedas(moedasIniciais) {}

void Jogador::comprarCaravana(std::shared_ptr<Caravana> caravana, int precoCaravana) {
    if (moedas >= precoCaravana) {
        caravana->setId(caravanas.size()+1);
        caravanas.push_back(caravana);
        cout << "moedas antes " << moedas << endl;
        moedas -= precoCaravana;
        cout << "moedas depois" << moedas << endl;
    } else {
        throw runtime_error("Moedas insuficientes para comprar uma caravana!");
    }
}

void Jogador::adicionarCaravana(std::shared_ptr<Caravana> caravana){
    caravanas.push_back(caravana);
}

void Jogador::adicionarMoedas(int quantidade) {
    moedas += quantidade;
}

int Jogador::getMoedas() const {
    return moedas;
}

bool Jogador::temCaravanas() const {
    return !caravanas.empty();
}

void Jogador::listarCaravanas() const {
    for (const auto& caravana : caravanas) {
        cout << caravana->exibirDetalhes() << endl;
    }
}

const vector<shared_ptr<Caravana>>& Jogador::getCaravanas() const {
    return caravanas;
}