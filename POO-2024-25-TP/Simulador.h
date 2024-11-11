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
#include "CaravanaComercio.h"
#include "CaravanaMilitar.h"
#include "CaravanaSecreta.h"
#include "Comandos.h"
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;


    class Simulador {


    public:
        Simulador(int moedasJogador);

        ~Simulador();

        // Funções principais
        void iniciar();               // Inicia a simulação
        void executarComando(const std::string& comando); // Executa um comando

        // Comandos da fase 2
        void exec(const std::string& nomeFicheiro);
        void prox(int n = 1);
        void comprac(const std::string& cidade, char tipo);
        void precos() const;
        void cidade(const std::string& nome);
        void caravana(int id);
        void compra(int id, int toneladas);
        void vende(int id);
        void move(int id, int direcao);
        void autoGestao(int id);
        void stop(int id);
        void barbaro(int linha, int coluna);
        void areia(int linha, int coluna, int raio);
        void moedas(int n);
        void tripulacao(int id, int tripulantes);
        void saves(const std::string& nome);
        void loads(const std::string& nome);
        void lists() const;
        void dels(const std::string& nome);
        void terminar();

        // Funções auxiliares
        void imprimirEstado() const;

    private:
        int moedasJogador;                     // Moedas do jogador
        int instantes;                  // Número de instantes decorridos
        int combatesVencidos;           // Número de combates vencidos
        //Deserto* deserto;               // Mapa do deserto
        std::vector<Caravana*> caravanas; // Caravanas do jogador
        Buffer buffer;                  // Buffer para output


    };


#endif //POO_2024_25_TP_SIMULADOR_H

