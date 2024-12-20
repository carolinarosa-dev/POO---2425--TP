#include "Jogador.h"

Jogador::Jogador(int moedasIniciais) : moedas(moedasIniciais) {}

int Jogador::getMoedas() const {
    return moedas;
}
void Jogador::adicionarMoedas(int quantidade) {
    moedas += quantidade;
}
//
//bool Jogador::temCaravanas() const {
//    return !caravanas.empty();
//}
//
//std::string Jogador::listarCaravanas() const {
//    std::ostringstream oss;
//    for (const auto& caravana : caravanas) {
//        oss << caravana->exibirDetalhes() << std::endl;
//        return oss.str();
//    }
//}