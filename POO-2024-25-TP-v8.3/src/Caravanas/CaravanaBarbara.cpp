
#include "../include/Caravanas/CaravanaBarbara.h"


CaravanaBarbara::CaravanaBarbara(Tipo tipo, int linha, int coluna)
        : Caravana(BARBARA, getPosicao().first, getPosicao().second) {
    //id = getId();
    tripulantes = 40;
}
CaravanaBarbara::CaravanaBarbara(int linha, int coluna)
        : Caravana(616, linha, coluna) {
    //id = getId();
    tripulantes = 40;
}

void CaravanaBarbara::moverAleatoriamente() {
    int direcao = rand() % 4;
    switch (direcao) {
        case 0: setPosicao(getPosicao().first - 1, getPosicao().second); break; // esquerda
        case 1: setPosicao(getPosicao().first + 1, getPosicao().second); break; // direita
        case 2: setPosicao(getPosicao().first, getPosicao().second - 1); break; // cima
        case 3: setPosicao(getPosicao().first, getPosicao().second + 1); break; // baixo
    }
}

void CaravanaBarbara::moverParaCaravana(int caravanaLinha, int caravanaColuna) {
    if (getPosicao().first < caravanaLinha) setPosicao(getPosicao().first + 1, getPosicao().second);
    else if (getPosicao().first > caravanaLinha) setPosicao(getPosicao().first - 1, getPosicao().second);
    else if (getPosicaoAnteriorCaravana().second < caravanaColuna) setPosicao(getPosicao().first, getPosicao().second + 1);
    else if (getPosicaoAnteriorCaravana().second > caravanaColuna) setPosicao(getPosicao().first, getPosicao().second - 1);
}

bool CaravanaBarbara::verificarProximidade(int caravanaLinha, int caravanaColuna) {
    int distancia = abs(getPosicao().first- caravanaLinha) + abs(getPosicao().second - caravanaColuna);
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


