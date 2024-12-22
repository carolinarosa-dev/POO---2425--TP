

#ifndef POO_2024_25_TP_COMANDOS_H
#define POO_2024_25_TP_COMANDOS_H

#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>


//#include "Buffer.h"
//#include "Jogador.h"
//#include "Simulador.h"

class Utils;
//class Jogador;

class Comandos {

public:
    Comandos();
    ~Comandos();
    // Comandos da Fase 1
    void cmd_config(const std::string &nomeFicheiro) const;

    std::string cmd_sair() const;

// Comandos da Fase 2
    std::string cmd_exec(std::istringstream &iss) const;

    std::string cmd_prox(std::istringstream &iss) const;

    void cmd_comprac(std::istringstream &iss, int precoCaravana);// implementar a "logica" no simulador

    std::string cmd_precos() const;

    std::string cmd_cidade(std::istringstream &iss) const;

    std::string cmd_caravana(std::istringstream &iss) const;

    std::string cmd_compra(std::istringstream &iss) const;

    std::string cmd_vende(std::istringstream &iss) const;

    std::string cmd_move(std::istringstream &iss) const;

    std::string cmd_auto(std::istringstream &iss) const;

    std::string cmd_stop(std::istringstream &iss) const;

    std::string cmd_barbaro(std::istringstream &iss) const;

    std::string cmd_areia(std::istringstream &iss) const;

    std::string cmd_moedas(std::istringstream &iss) const;

    std::string cmd_tripul(std::istringstream &iss) const;

    std::string cmd_saves(std::istringstream &iss) const;

    std::string cmd_loads(std::istringstream &iss) const;

    std::string cmd_lists() const;

    std::string cmd_dels(std::istringstream &iss) const;

    std::string cmd_terminar() const;

private:
      Utils *utils;
//    Buffer* bufferAtual;
//    std::map<std::string, Buffer*> buffersSalvos;
//    Jogador jogador;
//    Simulador simulador;
    int linhas, colunas;
};

#endif //POO_2024_25_TP_COMANDOS_H