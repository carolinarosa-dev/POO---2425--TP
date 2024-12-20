//
// Created by Tinoco on 20/12/2024.
//

#ifndef POO_2024_25_TP_INTERFACE_H
#define POO_2024_25_TP_INTERFACE_H

#include "Comandos.h"

#include "Simulador.h"
#include "Comandos.h"

class Interface {
private:
    Simulador& simulador;
    Comandos& comandos;

public:
    Interface(Simulador& sim, Comandos& cmd) : simulador(sim), comandos(cmd) {}
    void executar(); // Gerencia a interação com o usuário
};



#endif //POO_2024_25_TP_INTERFACE_H
