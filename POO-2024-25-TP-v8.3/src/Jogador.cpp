#include "../include/Jogador.h"

void Jogador::comprarCaravana(std::unique_ptr<Caravana> caravanaCidade, int preco) {
//    if (moedas >= precoCaravana) {
//        caravana->setId(caravanas.size()+1);
//        caravanas.push_back(caravana);
//        cout << "moedas antes " << moedas << endl;
//        moedas -= precoCaravana;
//        cout << "moedas depois" << moedas << endl;
//    } else {
//        throw runtime_error("Moedas insuficientes para comprar uma caravana!");
//    }
    caravanasJogador.push_back(std::move(caravanaCidade));
}



void Jogador::adicionarCaravana(std::unique_ptr<Caravana> caravana){
    caravanasJogador.push_back(std::move(caravana));
}

void Jogador::adicionarMoedas(int quantidade) {
    moedas += quantidade;
}

int Jogador::getMoedas() const {
    return moedas;
}

std::string Jogador::exibirDetalheCaravana(int id) const {
    for(auto&c: caravanasJogador){
        if (c->getId() == id){
            return c->exibirDetalhes();;
        }
    }
    return "Caravana não encontrada";
}

std::vector<std::unique_ptr<Caravana>>& Jogador::getCaravanas() {
    return caravanasJogador;
}


