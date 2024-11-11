//
// Created by Carolina Rosa on 09/11/2024.
//

#include "Simulador.h"

//falta construtor


/*Simulador::~Simulador() {
    delete deserto;
    for (auto caravana : caravanas) {
        delete caravana;
    }
}*/

/*void Simulador::iniciar() {
    std::cout << "Simulação iniciada com " << moedas << " moedas.\n";
}*/

void Simulador::executarComando(const std::string& comando) {
    std::cout << "Executando comando: " << comando << "\n";
}

void Simulador::exec(const std::string& nomeFicheiro) {
    std::ifstream ficheiro(nomeFicheiro);
    if (!ficheiro.is_open()) {
        std::cout << "Erro ao abrir o ficheiro: " << nomeFicheiro << "\n";
        return;
    }

    std::string comando;
    while (getline(ficheiro, comando)) {
        executarComando(comando);
    }

    ficheiro.close();
}

void Simulador::prox(int n) {
    for (int i = 0; i < n; ++i) {
        ++instantes;
        imprimirEstado();
    }
}

void Simulador::comprac(const std::string& cidade, char tipo) {
    std::cout << "Comprando caravana tipo " << tipo << " na cidade " << cidade << ".\n";
}

void Simulador::precos() const {
    std::cout << "Lista de preços das mercadorias:\n";
}

void Simulador::cidade(const std::string& nome) {
    std::cout << "Conteúdo da cidade " << nome << ":\n";
}

void Simulador::caravana(int id) {
    std::cout << "Descrição da caravana " << id << ":\n";
}

void Simulador::compra(int id, int toneladas) {
    std::cout << "Comprando " << toneladas << " toneladas para caravana " << id << ".\n";
}

void Simulador::vende(int id) {
    std::cout << "Vendendo mercadoria da caravana " << id << ".\n";
}

void Simulador::move(int id, int direcao) {
    std::cout << "Movendo caravana " << id << " na direção " << direcao << ".\n";
}

void Simulador::autoGestao(int id) {
    std::cout << "Caravana " << id << " agora em auto-gestão.\n";
}

void Simulador::stop(int id) {
    std::cout << "Caravana " << id << " parou a auto-gestão.\n";
}

void Simulador::barbaro(int linha, int coluna) {
    std::cout << "Criando caravana bárbara em (" << linha << ", " << coluna << ").\n";
}

void Simulador::areia(int linha, int coluna, int raio) {
    std::cout << "Criando tempestade de areia em (" << linha << ", " << coluna << ") com raio " << raio << ".\n";
}

void Simulador::moedas(int n) {
    moedasJogador += n;
    std::cout << "Moedas ajustadas para " << moedasJogador << ".\n";
}

void Simulador::tripulacao(int id, int tripulantes) {
    std::cout << "Comprando " << tripulantes << " tripulantes para caravana " << id << ".\n";
}

void Simulador::saves(const std::string& nome) {
    std::cout << "Salvando estado do buffer com o nome " << nome << ".\n";
}

void Simulador::loads(const std::string& nome) {
    std::cout << "Carregando estado do buffer com o nome " << nome << ".\n";
}

void Simulador::lists() const {
    std::cout << "Listando cópias do buffer salvas.\n";
}

void Simulador::dels(const std::string& nome) {
    std::cout << "Apagando cópia do buffer com o nome " << nome << ".\n";
}

void Simulador::terminar() {
    std::cout << "Simulação terminada após " << instantes << " instantes. Combates vencidos: " << combatesVencidos
              << ". Moedas restantes: " << moedasJogador << ".\n";
}

void Simulador::imprimirEstado() const {
    std::cout << "Estado atual do simulador.\n";
}



