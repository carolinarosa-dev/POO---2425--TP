
#include <iostream>
#include <string>
#include <sstream>
#include "Comandos.h"



int main() {
    // Instanciar a classe Comandos
    Comandos comandos;

    string linhaComando;

    cout << "Bem-vindo ao programa!" << endl;

    // Loop para ler e executar comandos até que o usuário saia
    while (true) {
        cout << "> ";  // Prompt para o usuário digitar o comando
        getline(cin, linhaComando);  // Ler o comando do usuário

        // Executar o comando
        comandos.executarComando(linhaComando);

        // Verificar se o comando foi 'sair', caso contrário continuar
        if (linhaComando == "sair") {
            break;  // Sai do loop e finaliza o programa
        }
    }

    return 0;  // Fim do programa
}










