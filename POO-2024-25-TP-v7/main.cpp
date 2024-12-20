#include "Interface.h"
#include "Simulador.h"
#include "Comandos.h"


int main() {
    Simulador simulador;
    Comandos comandos;
    Interface interface(simulador, comandos);

    interface.executar(); // Inicia a interação com o usuário
    return 0;
}