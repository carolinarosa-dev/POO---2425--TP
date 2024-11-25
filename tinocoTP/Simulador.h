//
// Created by Carolina Rosa on 09/11/2024.
//


#ifndef POO_2024_25_TP_SIMULADOR_H
#define POO_2024_25_TP_SIMULADOR_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

#include "Buffer.h"
#include "Caravana.h"

//#include "Deserto.h"

using namespace std;


class Simulador {
    int moedasJogador;                     // Moedas do jogador
    int instantes;                  // Número de instantes decorridos
    int duracaoIntem;
    int maxItem;
    double precoVendaMercadorias;
    double precoCompraMercadorias;
    double precoCaravana;
    int instantesBarbaros;
    int duracaoBarbaros;
    int combatesVencidos;           // Número de combates vencidos
    //Deserto **deserto;               // Mapa do deserto - aloca o mapa e o local da referencia na memoria

    std::vector<Caravana*> caravanas; // Caravanas do jogador
    Buffer buffer;                  // Buffer para output
    //std::vector<Cidade*> cidades;

public:
    Simulador();
    Simulador(int moedasJogador, int instantes, int duracaoIntem, int maxIntem,
              double precoVendaMercadorias, double precoCompraMercadorias,
              double precoCaravanas,int instantesBarbaros, int duracaoBarbaros,
              const Buffer& buffer);
    ~Simulador();
    // Funções principais
    void iniciar();               // Inicia a simulação
    void executarComando(const std::string& comando); // Executa um comando
    void caravana(int id);
    // Funções auxiliares
    void imprimirEstado() const;

    void processaMapa();
    //Cidade& getCidade(char cidade)const;

    //Caravana& adicionaCaravana(Caravana caravana);
    void adicionaCaravana(Caravana* caravana);
    void imprimirCaravanas() const {
        for (const auto& caravana : caravanas) {
            caravana->exibirDetalhes();
        }
    }


};


#endif //POO_2024_25_TP_SIMULADOR_H

