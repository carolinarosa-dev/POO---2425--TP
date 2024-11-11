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

using namespace std;

class Comandos {
private:
    vector<string> mapa;
    int linhas, colunas;
    int moedas, instantesEntreNovosItens, duracaoItem, maxItens;
    int precoVendaMercadoria, precoCompraMercadoria, precoCaravana;
    int instantesEntreNovosBarbaros, duracaoBarbaros;
    int fase; // 1 para Fase 1, 2 para Fase 2

public:
    Comandos(); // Construtor
    void limparDados();
    void lerConfiguracao(const string &nomeFicheiro);
   void executarComando(const string &comando);
    void mostrarConfig() const;
    //void processarComandos();

// Comandos da Fase 1
    void config(istringstream &iss);
    void sair();

    // Comandos da Fase 2
    void exec(istringstream &iss);
    void prox(istringstream &iss);
    void terminar();


};





#endif //POO_2024_25_TP_COMANDOS_H
