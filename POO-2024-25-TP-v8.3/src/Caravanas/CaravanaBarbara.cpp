
#include "../../include/Caravanas/CaravanaBarbara.h"


CaravanaBarbara::CaravanaBarbara(Tipo tipo, int linha, int coluna)
        : Caravana(BARBARA, getPosicaoCaravana().first, getPosicaoCaravana().second) {
    //id = getId();
    tripulantes = 40;
}


void CaravanaBarbara::moverAleatoriamente() {
    int direcao = rand() % 4;
    switch (direcao) {
        case 0: setPosicao(getPosicaoCaravana().first - 1, getPosicaoCaravana().second); break; // esquerda
        case 1: setPosicao(getPosicaoCaravana().first + 1, getPosicaoCaravana().second); break; // direita
        case 2: setPosicao(getPosicaoCaravana().first, getPosicaoCaravana().second - 1); break; // cima
        case 3: setPosicao(getPosicaoCaravana().first, getPosicaoCaravana().second + 1); break; // baixo
    }
}

void CaravanaBarbara::moverParaCaravana(int caravanaLinha, int caravanaColuna) {
    if (getPosicaoCaravana().first < caravanaLinha) setPosicao(getPosicaoCaravana().first + 1, getPosicaoCaravana().second);
    else if (getPosicaoCaravana().first > caravanaLinha) setPosicao(getPosicaoCaravana().first - 1, getPosicaoCaravana().second);
    else if (getPosicaoAnteriorCaravana().second < caravanaColuna) setPosicao(getPosicaoCaravana().first, getPosicaoCaravana().second + 1);
    else if (getPosicaoAnteriorCaravana().second > caravanaColuna) setPosicao(getPosicaoCaravana().first, getPosicaoCaravana().second - 1);
}

bool CaravanaBarbara::verificarProximidade(int caravanaLinha, int caravanaColuna) {
    int distancia = abs(getPosicaoCaravana().first- caravanaLinha) + abs(getPosicaoCaravana().second - caravanaColuna);
    return distancia <= 8;
}

void CaravanaBarbara::apanharItens(const std::string& item) {
    if (item == "arca do tesouro") {
        // Implementar lógica para arca do tesouro
    } else if (item == "ganhar_tripulantes") {
        tripulantes += 5;
    } else if (item == "perder_tripulantes") {
        tripulantes -= 5;
    }
}

void CaravanaBarbara::enfrentarTempestade() {
    tripulantes -= static_cast<int>(tripulantes * 0.1);
    if (rand() % 100 < 25) {
        tripulantes = 0;
    }
}

std::string CaravanaBarbara::turno(int caravanaLinha, int caravanaColuna) {
    if (tripulantes <= 0) return "Caravana destruida";
    if (turnosAteDesaparecer <= 0) return "Caravana desapareceu";
    if (caravanaLinha != -1 && caravanaColuna != -1 && verificarProximidade(caravanaLinha, caravanaColuna)) {
        moverParaCaravana(caravanaLinha, caravanaColuna);
    } else {
        moverAleatoriamente();
    }
    turnosAteDesaparecer--;
    return "Caravana em movimento";
}

std::string CaravanaBarbara::getDesignacaoTipo() const {
    return "caravana barbara ";
}
CaravanaBarbara::~CaravanaBarbara() {
    // Destructor implementation
}


