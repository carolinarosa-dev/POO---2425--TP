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

#include "Simulador.h"
#include "Caravana.h"
class Cidade;
class Simulador;
using namespace std;

class Comandos {

private:

    Buffer* bufferAtual;
    map<string, Buffer*> buffersSalvos;
    vector<string> mapa;

    vector<shared_ptr<Cidade>> cidades;
    int linhas=10, colunas=20;
    int moedas, instantesEntreNovosItens, duracaoItem, maxItens;
    int precoVendaMercadoria=0, precoCompraMercadoria=0, precoCaravana;
    int instantesEntreNovosBarbaros, duracaoBarbaros;
    int fase; // 1 para Fase 1, 2 para Fase 2
    shared_ptr<Simulador> simulador;


public:

    Comandos(int linhas, int colunas);
    ~Comandos();
    Comandos(); // Construtor
    void limparDados();
    void lerConfiguracao(const string &nomeFicheiro);
    void processaMapa();
    void executarComando(const string &comando); // Método para execução de comandos
    void mostrarConfig() const;
    //void processarComandos();
    int calcularPontuacao() const;
    void criarCaravanaBarbara(std::istringstream &iss);

//Acho que é no simulador
// Métodos para adicionar cidades e caravanas
/*void adicionarCidade(Cidade cidade);
void adicionarCaravana(Caravana* caravana);*/

    // Comandos da Fase 1
    void config(istringstream &iss);
    void sair();

    // Comandos da Fase 2
    void exec(istringstream &iss);
    void prox(istringstream &iss);
    void comprac(std::istringstream& iss, int precoCaravana);// implementar a "logica" no simulador
    void terminar();
    void saves(istringstream& iss);
    void loads(istringstream& iss);
    void lists();
    void dels(istringstream& iss);
    void adicionaMoedas(istringstream& iss);
    string listarPrecos();
    void mostrarDetalhesCaravana(istringstream& iss);
    void listarCaravanasCidade(std::istringstream &iss);
    void tripul(istringstream& iss);


};

#endif //POO_2024_25_TP_COMANDOS_H