

#ifndef POO_2024_25_TP_COMANDOS_H
#define POO_2024_25_TP_COMANDOS_H

#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>
#include <vector>
#include "memory"

#include <functional>

#include "Simulador.h"

class Cidade;
class Caravana;

class Comandos {

public:
    Comandos();

    // Comandos da Fase 1
//    void cmd_config(const std::string &nomeFicheiro, int linhas, int colunas, Simulador simulador) const;
    void cmd_config(const std::string &nomeFicheiro);

    std::string cmd_sair();

// Comandos da Fase 2
    std::string cmd_exec(std::istringstream &iss);

    std::string cmd_prox(std::istringstream &iss);

    void cmd_comprac(std::istringstream &iss);// implementar a "logica" no simulador

    std::string cmd_precos();

    std::string cmd_cidade(std::istringstream &iss);

    void cmd_caravana(std::istringstream &iss);

    std::string cmd_compra(std::istringstream &iss);

    std::string cmd_vende(std::istringstream &iss);

    std::string cmd_move(std::istringstream &iss);

    std::string cmd_auto(std::istringstream &iss);

    std::string cmd_stop(std::istringstream &iss);

    std::string cmd_barbaro(std::istringstream &iss);

    std::string cmd_areia(std::istringstream &iss);

    std::string cmd_moedas(std::istringstream &iss);

    std::string cmd_tripul(std::istringstream &iss);

    std::string cmd_saves(std::istringstream &iss);

    std::string cmd_loads(std::istringstream &iss);

    std::string cmd_lists();

    std::string cmd_dels(std::istringstream &iss);

    std::string cmd_terminar();

    //Mapa
    void processaMapa();

    void lerFicheiro(std::ifstream& ficheiro);
    bool validarArgumentos(const std::string &comando, std::string& mensagem);
    bool executarComando(const std::string &comando, std::string &mensagem);

    void limparMapa();  //ver
    void limpaDados();
    void atualizaMapa();
    int calcularPontuacao();

//    configuraveis
    std::map<std::string, int> getAtributosConfiguraveis() const;
    void imprimirAtributosConfiguraveis() const;


    ~Comandos();
private:
    Simulador* simulador;
//    mapa
    std::vector<std::string> mapaFicheiro;
//    configuraveis
    std::map<std::string, int> atributosConfiguraveis;

    int moedas, instantesEntreNovosItens, duracaoItem, maxItens;
    int precoCaravana, precoCompraMercadoria, precoVendaMercadoria;
    int instantesEntreNovosBarbaros, duracaoBarbaros;

};

#endif //POO_2024_25_TP_COMANDOS_H