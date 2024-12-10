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
#include "Caravana.h"
#include "Comandos.h"
#include "Jogador.h"
//#include "CaravanaBarbara.h"


class Deserto;
class Cidade;
class CaravanaBarbara;

using namespace std;

class Simulador {

public:

    Simulador(int linhas, int colunas, int moedasIniciais);
    void adicionaCaravanaJogador(char cidadeLetra, int tipoCaravanaNum, char tipoCaravanaChar);
    void listarCaravanas(char cidadeLetra) const;
    void adicionarCidade(shared_ptr<Cidade> cidade);
    void provocarTempestade(int linhaCentro, int colunaCentro, int raio);
    void moverCaravana(int idCaravana, int direcao);
    void verificarCombate();
    bool terminarSimulacao() const;
    Simulador(int linhas, int colunas, Buffer buffer);
    //Jogador& getJogador();
    void criarCaravanaBarbara(int linha, int coluna);


    void mostrarDescricaoCaravana(int idCaravana) const;

    ~Simulador();

    // Funções principais
    void iniciar();               // Inicia a simulação
    void executarComando(const std::string& comando); // Executa um comando

    void caravana(int id);

    // Funções auxiliares
    void imprimirEstado() const;

private:
    int moedasJogador;                     // Moedas do jogador
    int instantes;                  // Número de instantes decorridos
    int combatesVencidos;           // Número de combates vencidos
    Deserto *deserto;               // Mapa do deserto - aloca o mapa e o local da referencia na memoria
    vector<shared_ptr<Cidade>> cidades; //DONO
    vector<shared_ptr<CaravanaBarbara>> caravanasBarbaras;
    Buffer buffer;                  // Buffer para output
    Jogador jogador;
};


#endif //POO_2024_25_TP_SIMULADOR_H

