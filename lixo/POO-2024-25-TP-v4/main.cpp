
#include <iostream>
#include <string>
#include <sstream>
#include "Comandos.h"
using namespace std;


int main() {

   Comandos comandos(10, 10); // Exemplo com um buffer de 10x10 para testar os comandos saves,loads,dels,lists


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








