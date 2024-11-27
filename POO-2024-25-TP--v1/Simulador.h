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

#include "Buffer.h"
#include "Deserto.h"
#include "Caravana.h"
#include "Comandos.h"

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

    void adicionaCaravanaJogador();

private:
    int moedasJogador;                     // Moedas do jogador
    int instantes;                  // Número de instantes decorridos
    int combatesVencidos;           // Número de combates vencidos
    //Deserto **deserto;               // Mapa do deserto - aloca o mapa e o local da referencia na memoria
    vector<shared_ptr<Cidade>> cidades; //DONO
    Buffer buffer;                  // Buffer para output

};









#endif //POO_2024_25_TP_SIMULADOR_H

