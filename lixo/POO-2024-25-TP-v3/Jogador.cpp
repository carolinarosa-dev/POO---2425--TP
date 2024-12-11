//
// Created by Carolina Rosa on 10/11/2024.
//


#include"Caravana.h"

#include "Jogador.h"
#include "CaravanaComercio.h"
#include "CaravanaMilitar.h"
#include "CaravanaSecreta.h"
#include <iostream>

Jogador::Jogador(int moedasIniciais) : moedas(moedasIniciais) {}


shared_ptr<Caravana> Jogador::comprarCaravana(int id, int tipo, int linha, int coluna, int precoCaravana) {
    if (moedas >= precoCaravana) {
        shared_ptr<Caravana> novaCaravana;
        switch (tipo) {
            case Caravana::COMERCIO:
                novaCaravana = make_shared<CaravanaComercio>(id, linha, coluna);
                break;
            case Caravana::MILITAR:
                novaCaravana = make_shared<CaravanaMilitar>(id, linha, coluna);
                break;
            case Caravana::SECRETA:
                novaCaravana = make_shared<CaravanaSecreta>(id, linha, coluna);
                break;
            default:
                throw invalid_argument("Tipo de caravana inválido!");
        }
        caravanas.push_back(novaCaravana);
        moedas -= precoCaravana;
        return novaCaravana;
    } else {
        throw runtime_error("Moedas insuficientes para comprar uma caravana!");
    }
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

