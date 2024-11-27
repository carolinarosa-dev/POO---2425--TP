//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Cidade.h"
#include "Caravana.h"

Cidade::Cidade(char nome, int linha, int coluna)
        : nome(nome), linha(linha), coluna(coluna), tripulantes(10) {
    // Inicializa algumas mercadorias como exemplo
    mercadorias.push_back("Água");
    mercadorias.push_back("Comida");
    mercadorias.push_back("Armas");
}

char Cidade::getNome() const {
    return nome;
}

int Cidade::getLinha() const {
    return linha;
}

int Cidade::getColuna() const {
    return coluna;
}



void Cidade::listarCaravanas() const {
    std::cout << "Caravanas na cidade " << nome << ":" << std::endl;

    for (const auto& caravana : caravanasNaCidade) {
        if(auto obj = caravana.lock())
        cout << "ID: " << obj->getId() << " Tipo: " << obj->exibirDetalhes()<< std::endl;
    }
}

/*
void Cidade::adicionarCaravana(Caravana* caravana) {
    caravanasNaCidade.push_back(caravana);
}*/


void Cidade::adicionarCaravana(weak_ptr<Caravana>&caravana) {
    caravanasNaCidade.push_back(caravana);
}





