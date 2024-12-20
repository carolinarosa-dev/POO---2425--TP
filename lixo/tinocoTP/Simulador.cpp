//
// Created by Carolina Rosa on 09/11/2024.
//

#include "Simulador.h"
Simulador::Simulador() : buffer(10, 10) {  // Inicializa 'buffer' com 10x10
    moedasJogador = 1000;
    instantes = 10;
    duracaoIntem = 5;
    maxItem = 50;
    precoVendaMercadorias = 10.0;
    precoCompraMercadorias = 5.0;
    precoCaravana = 100;
    instantesBarbaros = 5;
    duracaoBarbaros = 3;
}
Simulador::~Simulador() {
    // Libere qualquer recurso alocado, se necessário
    // Exemplo: liberar memória alocada dinamicamente
}

Simulador::Simulador(int moedasJogador, int instantes, int duracaoIntem, int maxItem, double precoVendaMercadorias,
                     double precoCompraMercadorias, double precoCaravanas, int instantesBarbaros, int duracaoBarbaros,
                     const Buffer& buffer):buffer(buffer){
    this->moedasJogador = moedasJogador;
    this->instantes = instantes;
    this->duracaoIntem = duracaoIntem;
    this->maxItem = maxItem;
    this->precoCompraMercadorias = precoCompraMercadorias;
    this->precoVendaMercadorias = precoVendaMercadorias;
    this->precoCaravana = precoCaravanas;
    this->instantesBarbaros = instantesBarbaros;
    this->duracaoBarbaros = duracaoBarbaros;
    //this->buffer = buffer;

    //processaMapa();

}
void Simulador::iniciar() {
    std::cout << "Simulação iniciada com " << moedasJogador << " moedas.\n";

}

void Simulador::executarComando(const std::string &comando) {
    std::cout << "Executando comando: " << comando << "\n";
}


void Simulador::imprimirEstado() const {
    std::cout << "Estado atual do simulador.\n";
}
/*
void Simulador::processaMapa() {
    for (int i = 0; i < buffer.getLinhas(); ++i) {
        for (int j = 0; j < buffer.getColunas(); ++j) {
            if(isalpha(buffer.getPosicao(i,j))){
                cidades.push_back(new Cidade(buffer.getPosicao(i,j), i, j));
            }
            if(isdigit(buffer.getPosicao(i,j))){
                caravanas.push_back(new Caravana(int(buffer.getPosicao(i,j)), i,j));

            }

        }

    }
}
 */
/*
Cidade& Simulador::getCidade(char cidade) const {
    for (auto& c : cidades){
        if(c->getNome() == cidade){
            return *c;
        }
    }
    cout << "Cidade nao encontrada\n";
}*/

//Caravana& Simulador::adicionaCaravana(Caravana caravana) {
void Simulador::adicionaCaravana(Caravana* caravana) {
    caravanas.push_back(caravana);
}


