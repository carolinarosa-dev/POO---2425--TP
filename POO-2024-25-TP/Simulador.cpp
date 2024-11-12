//
// Created by Carolina Rosa on 09/11/2024.
//

#include "Simulador.h"


void Simulador::iniciar() {
    std::cout << "Simulação iniciada com " << moedasJogador << " moedas.\n";

}

void Simulador::executarComando(const std::string &comando) {
    std::cout << "Executando comando: " << comando << "\n";
}


void Simulador::imprimirEstado() const {
    std::cout << "Estado atual do simulador.\n";
}


