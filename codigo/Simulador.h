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
#include <memory>
#include <algorithm>
#include <iterator>

#include "Buffer.h"
#include "Comandos.h"

//#include "Caravana.h"
class Caravana;
class Deserto;
class Cidade;
class CaravanaBarbara;
class Jogador;



using namespace std;




class Simulador {

public:

    void provocarTempestade(int linhaCentro, int colunaCentro, int raio);
    void verificarCombate();
    std::shared_ptr<Jogador> getJogador();
   // Jogador& getJogador();
    // Funções principais
    void executarComando(const std::string& comando); // Executa um comando

    std::shared_ptr<Caravana> getCaravana(int id);
    // Funções auxiliares
    void imprimirEstado() const;


private:
    int instantes;                  // Número de instantes decorridos
    int linhas;
    int colunas;
    Deserto *deserto;               // Mapa do deserto - aloca o mapa e o local da referencia na memoria
    vector<shared_ptr<Cidade>> cidades;//DONO
    vector<shared_ptr<CaravanaBarbara>> caravanasBarbaras;
    Buffer *buffer;                  // Buffer para output
    //Jogador jogador;
    std::shared_ptr<Jogador> jogador;
    vector<std::shared_ptr<Caravana>> caravanas; // Declaração da variável caravanas
    //Comandos comandos;


};


#endif //POO_2024_25_TP_SIMULADOR_H
