//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_COMANDOS_H
#define POO_2024_25_TP_COMANDOS_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include<fstream>
#include <map>
#include "Buffer.h"
#include "Deserto.h"
#include "Caravana.h"
#include"Cidade.h"
#include <unordered_map>  // Para unordered_map

using namespace std;

class Comandos {
private:

    Buffer* bufferAtual;
    map<string, Buffer*> buffersSalvos;
    vector<string> mapa;
  //  vector<Caravana*> caravanas; // Lista de caravanas
   // vector<Cidade> cidades; // Lista de cidades
    int linhas=10, colunas=20;
    int moedas, instantesEntreNovosItens, duracaoItem, maxItens;
    int precoVendaMercadoria=0, precoCompraMercadoria=0, precoCaravana;
    int instantesEntreNovosBarbaros, duracaoBarbaros;
    int fase; // 1 para Fase 1, 2 para Fase 2


public:
    Comandos(int linhas, int colunas);
    ~Comandos();
    Comandos(); // Construtor
    void limparDados();
    void lerConfiguracao(const string &nomeFicheiro);
    void executarComando(const string &comando); // Método para execução de comandos
    void mostrarConfig() const;
    //void processarComandos();
    int calcularPontuacao() const;

// Métodos para adicionar cidades e caravanas
/*void adicionarCidade(Cidade cidade);
void adicionarCaravana(Caravana* caravana);*/


    // Comandos da Fase 1
    void config(istringstream &iss);
    void sair();

    // Comandos da Fase 2
    void exec(istringstream &iss);
    void prox(istringstream &iss);
    void terminar();
    void saves(istringstream& iss);
    void loads(istringstream& iss);
    void lists();
    void dels(istringstream& iss);
    void adicionaMoedas(istringstream& iss);
    void listarPrecos();
    void mostrarDetalhesCaravana(istringstream& iss);
    void listarCaravanasCidade(std::istringstream &iss);
    void tripul(istringstream& iss);
    void comprac(std::istringstream& iss);

};



#endif //POO_2024_25_TP_COMANDOS_H
