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

    Simulador(int linhas, int colunas, int moedasIniciais);
    void adicionaCaravanaJogador(std::shared_ptr<Caravana> caravana);//processaMapa
    void adicionaCaravanaJogador(char cidadeLetra, char tipoCaravana, int precoCaravana);//comprac
    void adicionaCaravanaBarbara(std::shared_ptr<CaravanaBarbara> caravana);
    void listarCaravanas(char cidadeLetra) const;
    void adicionarCidade(shared_ptr<Cidade> cidade);
    void provocarTempestade(int linhaCentro, int colunaCentro, int raio);
    void moverCaravana(int idCaravana, int direcao);
    bool posicaoValida(int linha, int coluna, char** mapa) const;

    void verificarCombate();
    bool terminarSimulacao() const;
    Simulador(int linhas, int colunas, Buffer *buffer);
    std::shared_ptr<Jogador> getJogador();
   // Jogador& getJogador();
    void criarCaravanaBarbara(int linha, int coluna);

    void comprarMercadoria(int idCaravana, int quantidadeMercadoria, int precoCompraMercadoria);
    void venderMercadoria(int idCaravana, int precoVendaMercadoria);

    void moverCaravana(int idCaravana, const std::string &direcao, char** mapa);
    void ativarAutoGestao(int idCaravana);
    void desativarAutoGestao(int idCaravana);



    void mostrarDescricaoCaravana(int idCaravana) const;

    ~Simulador();

    // Funções principais
    void iniciar();               // Inicia a simulação
    void executarComando(const std::string& comando); // Executa um comando

    std::shared_ptr<Caravana> getCaravana(int id);

    // Funções auxiliares
    void imprimirEstado() const;

    const vector<shared_ptr<Cidade>> &getCidades() const;

private:
    int moedasJogador;                     // Moedas do jogador
    int instantes;                  // Número de instantes decorridos
    int combatesVencidos;           // Número de combates vencidos
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

