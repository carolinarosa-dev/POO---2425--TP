//
// Created by Tinoco on 20/12/2024.
//

#ifndef POO_2024_25_TP_UTILS_H
#define POO_2024_25_TP_UTILS_H

#include <iostream>
#include <string>
#include <sstream>

class Utils {

public:
    void limparDados();

    bool validarArgumentos(const std::string &cmd);
    void executarComando(const std::string &comando); // Método para execução de comandos

    void limparMapa();
    std::string processaMapa() const;
    void atualizaMapa();
    std::string mostrarMapa() const;

    std::string mostrarConfig() const;


    int calcularPontuacao() const;



};


#endif //POO_2024_25_TP_UTILS_H
