//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_DESERTO_H
#define POO_2024_25_TP_DESERTO_H

#include <vector>
#include <string>
#include <map>
#include "Item.h"
#include "Deserto.h"
#include "Caravana.h"
#include "Simulador.h"
#include "Comandos.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

enum TipoPosicao {
    VAZIO,   // Espaço vazio (Deserto)
    CIDADE,  // Cidade
    MONTANHA // Montanha
};

class Caravana;  // Declaração antecipada da classe Caravana

class Deserto {
private:
    int numLinhas, numColunas;  // Dimensões do deserto
    std::vector<std::vector<TipoPosicao>> mapa;  // Mapa do deserto
    std::vector<Caravana *> caravanas;  // Caravanas no deserto (não nas cidades)

public:
    // Construtor que inicializa o deserto com dimensões
    Deserto(int linhas, int colunas);
    void configurarMapa(const std::vector<std::vector<TipoPosicao>>& configuracao);
    void exibirMapa();
    bool posicaoValida(int linha, int coluna);
    void moverCaravana(Caravana* caravana, int direcao);
    void adicionarCaravana(Caravana* caravana, int linha, int coluna);



};




#endif //POO_2024_25_TP_DESERTO_H
