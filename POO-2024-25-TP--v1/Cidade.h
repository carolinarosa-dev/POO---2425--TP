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
#include "Caravana.h"
#include "Comandos.h"

class Caravana;

using namespace std;

class Cidade {
public:
    Cidade(char nome, int linha, int coluna);
    void listarCaravanas() const;
    void mostrarPosicao();
    char getNome() const;
    int getTripulantes() const;
    int getLinha() const;
    int getColuna() const;
    void listarMercadorias() const;

    //void adicionarCaravana(Caravana* caravana);
    void adicionarCaravana(const shared_ptr<Caravana>& caravana);



private:
    char nome;
    int linha, coluna;
    int tripulantes;
    std::vector<string> mercadorias;
    //vector<Caravana*> caravanasNaCidade;  // Caravanas nesta cidade
    vector<shared_ptr<Caravana>> caravanasNaCidade;  // Usando shared_ptr para gestão automática de memória
    };



#endif //POO_2024_25_TP_CIDADE_H
