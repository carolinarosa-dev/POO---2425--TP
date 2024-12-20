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
#include <stdexcept>
#include<iterator>

#include "Simulador.h"
#include "Caravana.h"
class Cidade;
class Simulador;
class Montanha;
using namespace std;

class Comandos {

private:

    Buffer* bufferAtual;
    map<string, Buffer*> buffersSalvos;
    char** mapa; //DESTRUIR
    vector<shared_ptr<Cidade>> cidades;
    shared_ptr<Montanha>montanha;
    shared_ptr<Simulador> simulador;
    std::map<std::string, int> atributosConfiguraveis;

    int linhas=10, colunas=20;
    int moedas, instantesEntreNovosItens, duracaoItem, maxItens;
    int precoCaravana, precoCompraMercadoria, precoVendaMercadoria;
    int instantesEntreNovosBarbaros, duracaoBarbaros;
    int fase; // 1 para Fase 1, 2 para Fase 2

public:

    Comandos(int linhas, int colunas);
    ~Comandos();
    Comandos(); // Construtor
    




};

#endif //POO_2024_25_TP_COMANDOS_H
