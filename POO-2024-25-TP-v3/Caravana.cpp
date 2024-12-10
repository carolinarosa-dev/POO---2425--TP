//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Caravana.h"
Caravana::Caravana(int id, Tipo tipo, int linha, int coluna)
        : id(id),tipo(tipo),linha(linha), coluna(coluna), tripulantes(0), carga(0), agua(0), capacidadeCarga(0), capacidadeAgua(0), consumoAgua(0) {}



Caravana::Tipo Caravana::getTipo() const {
    return tipo;
}

int Caravana::getId() const {
    return id;
}


pair<int, int> Caravana::getPosicao() const {

    return {linha, coluna};
}


void Caravana:: setPosicao(int novaLinha, int novaColuna) {
    linha = novaLinha;
    coluna = novaColuna;
}

int Caravana::getTripulantes() const {
    return tripulantes;
}

bool Caravana::estaEmCidade() const {
    return emCidade;
}
void Caravana::setEmCidade(bool estado) {
    emCidade = estado;
}

int Caravana::getCarga() const {
    return carga;
}

int Caravana::getAgua() const {
    return agua;
}

void Caravana::mover(char direcao) {
    // Implementar lógica de movimentação básica
}

void Caravana::adicionarTripulantes(int quantidade) {
    tripulantes += quantidade;
}



void Caravana::removerTripulantes(int quantidade) {
    tripulantes -= quantidade;
}

void Caravana::adicionarCarga(int quantidade) {
    carga += quantidade;
}

void Caravana::removerCarga(int quantidade) {
    carga -= quantidade;
}

void Caravana::reabastecerAgua() {
    agua = capacidadeAgua;
}

void Caravana::consumirAgua() {
    if (tripulantes > 0) {
        agua -= consumoAgua;
        if (agua < 0) {
            agua = 0;
        }
    }
}

void Caravana::aplicarEfeitoItem(int tipoItem) {
    // Implementar lógica básica de aplicação de efeito de item
}


// Compra mercadorias
void Caravana::comprarMercadoria(const std::string& mercadoria) {
    mercadorias.push_back(mercadoria);
}


// Vende mercadorias
void Caravana::venderMercadoria(const std::string& mercadoria) {
    auto it = std::find(mercadorias.begin(), mercadorias.end(), mercadoria);
    if (it != mercadorias.end()) {
        mercadorias.erase(it);
    }
}

bool Caravana::estaDestruida() const {
    return tripulantes <= 0;
}

void Caravana::perderTripulantes(int quantidade) {
    tripulantes = std::max(0, tripulantes - quantidade);
}

void Caravana::adicionarAgua(int quantidade) {
    agua = std::min(capacidadeAgua, agua + quantidade);
}


// Exibe detalhes da caravana
string Caravana::exibirDetalhes() const {
    ostringstream  oss;
     oss << "Caravana ID: " << id << ", Tripulantes: " << tripulantes << ", Mercadorias: ";
    for (const auto& mercadoria : mercadorias) {
        oss << mercadoria << " ";
    }
    oss << endl;
    return oss.str();
}