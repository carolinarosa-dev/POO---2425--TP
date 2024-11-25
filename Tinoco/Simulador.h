//
// Created by Carolina Rosa on 09/11/2024.
//


#ifndef POO_2024_25_TP_SIMULADOR_H
#define POO_2024_25_TP_SIMULADOR_H

#include <string>
#include <map>
#include <vector>
#include "Buffer.h"
#include "Deserto.h"
#include "Caravana.h"
#include "Comandos.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;


    class Simulador {


    public:
        Simulador(int moedasJogador, int instantes, int duracaoIntem, int maxIntem,
                  double precoVendaMercadorias, double precoCompraMercadorias,
                  double precoCaravanas,int instantesBarbaros, int duracaoBarbaros, Buffer buffer);
        ~Simulador();
        // Funções principais
        void iniciar();               // Inicia a simulação
        void executarComando(const std::string& comando); // Executa um comando
        void caravana(int id);
        // Funções auxiliares
        void imprimirEstado() const;

        void processaMapa();
        Cidade& getCidade(char cidade)const;
        Caravana& adicionaCaravana(Caravana caravana);

    private:
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
        std::vector<Cidade*> cidades;
    };


#endif //POO_2024_25_TP_SIMULADOR_H

