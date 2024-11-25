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

/*void Simulador::atualizarEstado() {
    // Atualizar o tempo da simulação
    instanteAtual++;

    // Movimentar entidades no mapa (se aplicável)
    moverEntidades();

    // Gerar novos itens, se necessário
    if (instanteAtual % instantesEntreNovosItens == 0) {
        gerarNovosItens();
    }

    // Gerar novos bárbaros, se necessário
    if (instanteAtual % instantesEntreNovosBarbaros == 0) {
        gerarNovosBarbaros();
    }

    // Remover itens ou bárbaros que já expiraram
    removerElementosExpirados();

    // Outras lógicas específicas da simulação
    processarEventosEspeciais();
}*/


