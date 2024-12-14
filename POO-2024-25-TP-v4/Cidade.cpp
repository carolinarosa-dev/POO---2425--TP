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



/*string Cidade::listarCaravanas() const {
    ostringstream oss;
    for (const auto& caravana : caravanasNaCidade) {
        //if(auto obj = caravana.lock())
        cout << "ID: " << caravana->getId() << " Tipo: " << caravana->exibirDetalhes()<< std::endl;
    }
    oss << "Caravanas na cidade " << nome << ":" << std::endl;
    return oss.str();
}*/

std::string Cidade::listarCaravanas() const {
    std::ostringstream oss;
    oss << "Caravanas na cidade " << nome << ":" << std::endl;
    for (const auto& caravana : caravanasNaCidade) {
        // Assumindo que caravana é um shared_ptr ou unique_ptr
        oss << "ID: " << caravana->getId() << " Tipo: " << caravana->exibirDetalhes() << std::endl;
    }
    return oss.str();
}

//coloca as caravanas na cidade
void Cidade::adicionarCaravana(shared_ptr<Caravana> caravana) {
    caravanasNaCidade.push_back(caravana);
}