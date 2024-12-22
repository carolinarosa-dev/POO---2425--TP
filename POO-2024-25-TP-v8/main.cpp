
#include "Interface.h"
#include "Comandos.h"

int main() {
    Comandos comandos;
    Utils utils;
    Interface interface(comandos, utils);
    interface.executar(); // Inicia a interação com o usuário
    return 0;
}