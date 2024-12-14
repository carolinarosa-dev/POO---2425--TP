//
// Created by Tinoco on 27/11/2024.
//
#include "CaravanaBarbara.h"


CaravanaBarbara::CaravanaBarbara(int id,int linha, int coluna)
        : Caravana(id, BARBARA, linha, coluna), turnosAteDesaparecer(60) {
    tripulantes = 40;
}

void CaravanaBarbara::moverAleatoriamente() {
    int direcao = rand() % 4;
    switch (direcao) {
        case 0: setPosicao(linha - 1, coluna); break; // esquerda
        case 1: setPosicao(linha + 1, coluna); break; // direita
        case 2: setPosicao(linha, coluna - 1); break; // cima
        case 3: setPosicao(linha, coluna + 1); break; // baixo
    }
}

void CaravanaBarbara::moverParaCaravana(int caravanaLinha, int caravanaColuna) {
    if (linha < caravanaLinha) setPosicao(linha + 1, coluna);
    else if (linha > caravanaLinha) setPosicao(linha - 1, coluna);
    else if (coluna < caravanaColuna) setPosicao(linha, coluna + 1);
    else if (coluna > caravanaColuna) setPosicao(linha, coluna - 1);
}

bool CaravanaBarbara::verificarProximidade(int caravanaLinha, int caravanaColuna) {
    int distancia = abs(linha - caravanaLinha) + abs(coluna - caravanaColuna);
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
    if (tripulantes <= 0) return "Caravana destruída";
    if (turnosAteDesaparecer <= 0) return "Caravana desapareceu";
    if (caravanaLinha != -1 && caravanaColuna != -1 && verificarProximidade(caravanaLinha, caravanaColuna)) {
        moverParaCaravana(caravanaLinha, caravanaColuna);
    } else {
        moverAleatoriamente();
    }
    turnosAteDesaparecer--;
    return "Caravana em movimento";
}

CaravanaBarbara::~CaravanaBarbara() {
    // Destructor implementation
}