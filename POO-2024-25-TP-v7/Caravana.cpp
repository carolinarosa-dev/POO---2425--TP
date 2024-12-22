
#include "Caravana.h"

int Caravana::id = 1;

Caravana::Caravana(int linha, int coluna): posCaravana(linha, coluna) {

}

Caravana::Caravana(int id, Caravana::Tipo tipo, int linha, int coluna) {

}

void Caravana::setId(int newId) {

}

Caravana::Tipo Caravana::getTipo() const {
    return Caravana::BARBARA;
}

int Caravana::getId() const{
    return id;
}

// Exibe detalhes da caravana
std::string Caravana::exibirDetalhes() const {
    std::ostringstream oss;
    oss << "Caravana ID: " << id
        << "Tipo: " << getDesignacaoTipo()
        << "Mercadorias: \n"
        << "Tripulantes: " << tripulantes
        << "Carga: " << carga
        << "Agua: " << agua;
    for (const auto& mercadoria : mercadorias) {
        oss << mercadoria << " ";
    }
    oss << std::endl;
    return oss.str();
}
//tripulantes
int Caravana::getTripulantes() const {
    return tripulantes;
}

void Caravana::adicionarTripulantes(int quantidade) {
    tripulantes += quantidade;
}

void Caravana::perderTripulantes(int quantidade) {
    tripulantes = std::max(0, tripulantes - quantidade);
}

void Caravana::removerTripulantes(int quantidade) {
    tripulantes -= quantidade;
}

std::pair<int, int> Caravana::getPosicao() const {
    return {linha, coluna};
}

std::pair<int, int> Caravana::getPosicaoAnterior() const {
    return {linhaAnterior, colunaAnterior};
}

void Caravana::setPosicao(int novaLinha, int novaColuna) {
    linhaAnterior = linha;
    colunaAnterior = coluna;
    linha = novaLinha;
    coluna = novaColuna;
}

void Caravana::setAutoGestao(bool estado) {
    autoGestao = estado;
}
int Caravana::getCapacidadeCarga() const {
    return capacidadeCarga;
}

void Caravana::adicionarAgua(int quantidade) {
    agua = std::min(capacidadeAgua, agua + quantidade);
}

int Caravana::getAgua() const {
    return agua;
}

void Caravana::consumirAgua() {
    if (tripulantes > 0) {
        agua -= consumoAgua;
        if (agua < 0) {
            agua = 0;
        }
    }
}


void Caravana::reabastecerAgua() {
    agua = capacidadeAgua;
}

int Caravana::getCarga() const {
    return carga;
}

void Caravana::adicionarCarga(int quantidade) {
    carga += quantidade;
}

void Caravana::removerCarga(int quantidade) {
    carga -= quantidade;
    if (carga < 0) {
        carga = 0;
    }
}

void Caravana::aplicarEfeitoItem(int tipoItem) {
// Implementar lógica básica de aplicação de efeito de item
}

bool Caravana::estaEmCidade() const {
    return emCidade;
}

void Caravana::setEmCidade(bool estado) {
    emCidade = estado;
}

bool Caravana::estaDestruida() const {
    return tripulantes <= 0;
}

Caravana::~Caravana() {

}
