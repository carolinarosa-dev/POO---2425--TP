//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Caravana.h"
/*
Caravana::Caravana():id(0){

}
Caravana::Caravana(int id, Tipo tipo, int linha, int coluna)
        : id(id),tipo(tipo),linha(linha), coluna(coluna), tripulantes(0), carga(0), agua(0), capacidadeCarga(0), capacidadeAgua(0), consumoAgua(0) {}
*/

int Caravana::proximoId = 1;

Caravana::Caravana(int id,Tipo tipo, int linha, int coluna)
        : id(id), tipo(tipo), linha(linha), coluna(coluna), tripulantes(0), carga(0), agua(0), capacidadeCarga(0), capacidadeAgua(0), consumoAgua(0) {
    if (proximoId > 9) { //Seria melhor contar somente as caravas carregadas do mapa. Aquelas estacionadas não deveriam ser contados (opinião)
        //throw std::runtime_error("Numero maximo de caravanas atingido.");
    }
    proximoId++;
}

int Caravana::getProximoId() {
    return proximoId;
}

Caravana::Tipo Caravana::getTipo() const {
    return tipo;
}

int Caravana::getId() const {
    return id;
}

void Caravana::setId(int newId){
    id = newId;
}

pair<int, int> Caravana::getPosicaoAnterior() const {

    return {linhaAnterior, colunaAnterior};
}

pair<int, int> Caravana::getPosicao() const {

    return {linha, coluna};
}

void Caravana:: setPosicao(int novaLinha, int novaColuna) {
    linhaAnterior = linha;
    colunaAnterior = coluna;
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
int Caravana::getCapacidadeCarga() const {
    return capacidadeCarga;
}

void Caravana::adicionarCarga(int quantidade) {
    carga += quantidade;
}

int Caravana::getAgua() const {
    return agua;
}

void Caravana::adicionarTripulantes(int quantidade) {
    tripulantes += quantidade;
}

void Caravana::removerTripulantes(int quantidade) {
    tripulantes -= quantidade;
}

void Caravana::removerCarga(int quantidade) {
    carga -= quantidade;
    if (carga < 0) {
        carga = 0;
    }
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

bool Caravana::estaDestruida() const {
    return tripulantes <= 0;
}

void Caravana::perderTripulantes(int quantidade) {
    tripulantes = std::max(0, tripulantes - quantidade);
}

void Caravana::setAutoGestao(bool estado) {
    autoGestao = estado;
}

void Caravana::adicionarAgua(int quantidade) {
    agua = std::min(capacidadeAgua, agua + quantidade);
}

// Exibe detalhes da caravana
string Caravana::exibirDetalhes() const {
   ostringstream oss;
    oss << "Caravana ID: " << proximoId << ", Tipo: " << getDesignacaoTipo()
        << ", Tripulantes: " << tripulantes << ", Carga: " << carga << ", Agua: " << agua
        << ", Mercadorias: ";
    for (const auto& mercadoria : mercadorias) {
        oss << mercadoria << " ";
    }
    oss << std::endl;
    return oss.str();
}

Caravana::~Caravana() {

}