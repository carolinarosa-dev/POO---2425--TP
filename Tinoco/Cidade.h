//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_CIDADE_H
#define POO_2024_25_TP_CIDADE_H


#include <iostream>
#include <vector>
#include <string>
#include "Caravana.h"



class Cidade {

    public:
    Cidade(char nome, int linha, int coluna);
    void adicionarCaravana(Caravana* caravana);
    void removerCaravana(Caravana* caravana);

    /*  void comprarMercadoria(Caravana* caravana, const std::string& mercadoria);
     void venderMercadoria(Caravana* caravana, const std::string& mercadoria);

     void recrutarTripulantes(Caravana* caravana, int quantidade);
    */
    void listarCaravanas();
    void mostrarPosicao();
    char getNome() const;
    int getTripulantes(int tripulantes);

    Caravana& getCaravana(int tipo);


private:
    //Caravana* caravanas;
    char nome;                          // Nome da cidade (uma letra)
    int linha, coluna;// Posição no mapa (linha, coluna)

    vector<Caravana> caravanas;   // Lista de caravanas na cidade
    int tripulantes;                    // Número de tripulantes disponíveis
    //vector<string> mercadorias; // Mercadorias disponíveis para compra e venda

};


#endif //POO_2024_25_TP_CIDADE_H
