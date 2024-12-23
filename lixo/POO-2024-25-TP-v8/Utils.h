//
// Created by Tinoco on 20/12/2024.
//

#ifndef POO_2024_25_TP_UTILS_H
#define POO_2024_25_TP_UTILS_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <memory>

#include <filesystem>
#include <fstream>


#include "Jogador.h"
//#include "Simulador.h"
//#include "CaravanaComercio.h"
//#include "CaravanaMilitar.h"
//#include "CaravanaSecreta.h"

class Comandos;
class Simulador;
class Utils {

public:
    Utils();

    void limparDados();

    //Validacoes
    bool validarArgumentos(const std::string &comando, std::string& mensagem) const;
    bool posicaoValida(int linha, int coluna, char** mapa) const;
    bool verificarFicheiro(const std::string& nomeFicheiro);

    void lerFicheiro(std::ifstream& ficheiro, int& linhas, int& colunas, std::vector<std::string>& mapa);
    void processarFicheiro(std::map<std::string, int>& atributosConfiguraveis);

    bool executarComando(const std::string &comando, std::string &mensagem) const; // Método para execução de comandos

    void limparMapa();
    std::string processaMapa() const;
    void atualizaMapa();
    std::string mostrarMapa() const;

    std::string mostrarConfig() const;


    int calcularPontuacao() const;

    ~Utils();
private:
    Comandos* comandos;
    Jogador* jogador;
    Simulador* simulador;

    int linha, coluna;


    //rever!!!
    int precoComprac;

};


#endif //POO_2024_25_TP_UTILS_H
