//
// Created by Tinoco on 20/12/2024.
//

#include "Interface.h"

Interface::Interface(Comandos& cmd, Utils& utl): comandos(cmd), utils(utl){}

void Interface::executar() {
    std::ostringstream oss;
    std::string linhaComando, mensagem;

    std::cout << "Bem-vindo ao Simulador de Viagens no Deserto!\n";
    std::cout << "Digite 'sair' para encerrar o programa.\n";

    while (true) {
        oss << "> ";
        getline(std::cin, linhaComando);

        if (!utils.executarComando(linhaComando, mensagem));
        if (linhaComando == "sair") {
            comandos.cmd_sair();
            break;
        }
    }
}
