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


using namespace std;


class Simulador {


public:




    ~Simulador();

    // Funções principais
    void iniciar();               // Inicia a simulação
    void executarComando(const std::string& comando); // Executa um comando


    void caravana(int id);

    // Funções auxiliares
    void imprimirEstado() const;

    // Simulador.h




private:
    int moedasJogador;                     // Moedas do jogador
    int instantes;                  // Número de instantes decorridos
    int combatesVencidos;           // Número de combates vencidos
    //Deserto **deserto;               // Mapa do deserto - aloca o mapa e o local da referencia na memoria
    //   std::vector<Caravana*> caravanas; // Caravanas do jogador
    Buffer buffer;                  // Buffer para output


};









#endif //POO_2024_25_TP_SIMULADOR_H

