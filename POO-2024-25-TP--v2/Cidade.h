//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_CIDADE_H
#define POO_2024_25_TP_CIDADE_H

#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iostream>


#include "Comandos.h"
#include "Simulador.h"

class Jogador;
class Caravana;

using namespace std;

class Cidade {
public:
    Cidade(char nome, int linha, int coluna);

    string listarCaravanas() const;
    void mostrarPosicao();
    char getNome() const;
    int getTripulantes() const;
    int getLinha() const;
    int getColuna() const;
    void listarMercadorias() const;

    void adicionarCaravana(weak_ptr<Caravana>& caravana);//conhece do dono jogador

private:
    char nome;
    int linha, coluna;
    int tripulantes;
    std::vector<string> mercadorias;
    vector<weak_ptr<Caravana>> caravanasNaCidade;
    //fazer verificaçoes dos ponteiros

    };

#endif //POO_2024_25_TP_CIDADE_H
