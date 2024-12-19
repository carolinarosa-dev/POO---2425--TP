
#include <iostream>
#include <string>
#include <sstream>
#include "Comandos.h"
using namespace std;


int main() {

    Comandos comandos; // Exemplo com um buffer de 10x10 para testar os comandos saves,loads,dels,lists


    //Comandos comandos;
    string linhaComando;

    cout << "Bem-vindo ao Simulador de Viagens no Deserto!" << endl;
    cout << "Digite 'sair' para encerrar o programa." << endl;

    while (true) {
        cout << "> ";
        getline(cin, linhaComando);

        if (linhaComando == "sair") {
            comandos.sair();
            break;
        }

        comandos.executarComando(linhaComando);
    }


    return 0;  // Fim do programa
}


/*
#include <iostream>
#include <string>
#include <sstream>
#include "Comandos.h"

#include <stdexcept>

int main() noexcept {
    try {
        // Inicializa o objeto Comandos com um buffer de 10x10 para testes
        Comandos comandos(10, 10);

        string linhaComando;

        cout << "Bem-vindo ao Simulador de Viagens no Deserto!" << endl;
        cout << "Digite 'sair' para encerrar o programa." << endl;

        while (true) {
            cout << "> ";
            if (!getline(cin, linhaComando)) {
                cerr << "Erro ao ler comando. Entrada invalida ou fim inesperado do programa." << endl;
                break;
            }
            if (linhaComando == "sair") {
                try {
                    comandos.sair();
                } catch (const std::exception &e) {
                    cerr << "Erro ao executar saída: " << e.what() << endl;
                } catch (...) {
                    cerr << "Erro desconhecido ao encerrar o programa." << endl;
                }
                break;
            }
            try {
                comandos.executarComando(linhaComando);
            } catch (const std::runtime_error &e) {
                cerr << "Erro ao executar comando: " << e.what() << endl;
            } catch (...) {
                cerr << "Erro desconhecido durante a execucao do comando." << endl;
            }
        }

        cout << "Programa encerrado com sucesso!" << endl;
        return EXIT_SUCCESS;

    } catch (const std::runtime_error &e) {
        cerr << "Erro crítico: " << e.what() << endl;
        return EXIT_FAILURE;
    } catch (...) {
        cerr << "Erro desconhecido ocorrido. Encerrando o programa." << endl;
        return EXIT_FAILURE;
    }
}*/