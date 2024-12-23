#include "Jogador.h"

Jogador::Jogador(int moedasIniciais) : moedas(moedasIniciais) {}

void Jogador::setMoedas(int moedas) {
    this->moedas = moedas;
}

int Jogador::getMoedas() const {
    return moedas;
}
void Jogador::adicionarMoedas(int quantidade) {
    moedas += quantidade;
}

bool Jogador::temCaravanas() const {
    return !caravanasJogador.empty();
}

void Jogador::adicionaCaravanaJogador(std::unique_ptr<Caravana> caravana) {
    std::cout << "\n\nfalta testar caravanas ate 9\n\n";
    if (caravana) {
        caravanasJogador.push_back(std::move(caravana));
        //std::cout << "Caravana adicionada ao inventário do jogador!" << std::endl;
    }
}

std::string Jogador::getCaravanasJogador() const {
    std::ostringstream oss;
    for (const auto& caravana : caravanasJogador) {
        oss << caravana->exibirDetalhes() << std::endl;
        return oss.str();
    }
}



void Jogador::comprarCaravana(std::shared_ptr<Caravana>, int precoCaravana) {

}

/*const std::vector<std::shared_ptr<Caravana>> &Jogador::getCaravanas() const {
    return <#initializer#>;
}*/



