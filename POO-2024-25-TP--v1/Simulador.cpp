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

//adiciona as caravanas ao jogador quando ele compra
void Simulador::adicionaCaravanaJogador() {
   /* // Cria a caravana com o número fornecido
    int idCaravana = tipoCaravanaNum;  // Usando o número da caravana diretamente

    Caravana::Tipo tipoCaravana = Caravana::COMERCIO; // Podemos atribuir um tipo fixo, ou modificar conforme a lógica

    // Exemplo de criação da caravana (pode ser ajustado conforme a lógica de tipos)
    Caravana* novaCaravana = new Caravana(idCaravana, tipoCaravana, 0, 0); // Aqui você pode passar as coordenadas da caravana

    // Adiciona a caravana à cidade
    cidade->adicionarCaravana(shared_ptr<Caravana>(novaCaravana));

    // Feedback para o usuário
    cout << "Caravana de número " << tipoCaravanaNum << " comprada na cidade " << cidadeNome << "." << endl;
    */
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


