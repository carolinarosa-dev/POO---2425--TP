#include "Cidade.h"

Cidade::Cidade(char nome, int linha, int coluna)
        : nome(nome), posCidade(linha, coluna), tripulantes(10) {
    // Inicializa algumas mercadorias como exemplo
    mercadorias.push_back("Agua");
    mercadorias.push_back("Comida");
    mercadorias.push_back("Armas");
}

char Cidade::getNome() const {
    return nome;
}

int Cidade::getTripulantes() const {
    return tripulantes;
}

bool Cidade::possuiCaravana(Caravana::Tipo tipo){
    for (const auto& caravana : caravanasNaCidade) {
        if (caravana->getTipo() == tipo) {
            return true;
        }
    }
    return false;
}
void Cidade::adicionaCaravanaCidade(std::unique_ptr<Caravana> caravana) {
    caravanasNaCidade.push_back(std::move(caravana));
}
std::shared_ptr<Caravana> Cidade::cidadeVendeCaravana(int id) {
    for (auto it =  caravanasNaCidade.begin(); it != caravanasNaCidade.end(); it++) {
        ((*it)->getId() == id) {
            std::unique_ptr<Caravana> vendida = std::move(*it);
            caravanasNaCidade.erase(it);
            //std::cout << "Caravana " << id << " vendida!" << std::endl;
            return vendida;
        }
    }
    //std::cout << "Caravana com ID " << id << " não encontrada!" << std::endl;
    return nullptr;
}


std::string Cidade::listarCaravanas() const {
    std::ostringstream oss;
    oss << "Caravanas na cidade " << nome << ":" << std::endl;
    for (const auto& caravana : caravanasNaCidade) {
        // Assumindo que caravana é um shared_ptr ou unique_ptr
        oss << "ID: " << caravana->getId() << " Tipo: " << caravana->exibirDetalhes() << std::endl;
    }
    return oss.str();
}




