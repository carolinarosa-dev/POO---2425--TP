#include "../../include/Mapa/Cidade.h"
#include <sstream>


Cidade::Cidade(char nome, int linha, int coluna)
//        : nome(nome), getPosicaoCidade().first, getPosicaoCidade().second, tripulantes(10) {
        : nome(nome), linha(linha), coluna(coluna), tripulantes(10) {
    // Inicializa algumas mercadorias como exemplo
    mercadorias.push_back("Agua");
    mercadorias.push_back("Comida");
    mercadorias.push_back("Armas");
}

char Cidade::getNome() const {
        return nome;
}

std::pair<int, int> Cidade::getPosicaoCidade() const {
    return {linha, coluna};
}

int Cidade::getTripulantes() const {
    return tripulantes;
}


bool Cidade::possuiCaravana(Caravana::Tipo tipo){
    for (const auto& caravana : caravanasCidade) {
        if (caravana->getTipo() == tipo) {
            return true;
        }
    }
    return false;
}

std::unique_ptr<Caravana> Cidade::removerCaravanaDaCidadeParaJogador(Caravana::Tipo tipo) {
    for (auto it = caravanasCidade.begin(); it != caravanasCidade.end(); ++it) {
        if ((*it)->getTipo() == tipo) {
            auto caravanaRemovida = std::move(*it);  // Usa std::move para transferir a posse da caravana
            caravanasCidade.erase(it);  // Remove a caravana da cidade
            return caravanaRemovida;  // Retorna a caravana removida
        }
    }
    throw std::invalid_argument("Caravana do tipo especificado não encontrada na cidade.");
}


 void Cidade::adicionaCaravanasCidade(std::unique_ptr<Caravana> caravana) {
    caravanasCidade.push_back(std::move(caravana));
}
/*
std::shared_ptr<Caravana> Cidade::cidadeVendeCaravana(int id) {
//    for (auto it =  caravanasNaCidade.begin(); it != caravanasNaCidade.end(); it++) {
//        if((*it)->getId() == id) {
//            std::unique_ptr<Caravana> vendida = std::move(*it);
//            caravanasNaCidade.erase(it);
//            //std::cout << "Caravana " << id << " vendida!" << std::endl;
//            return vendida;
//        }
//    }
    //std::cout << "Caravana com ID " << id << " não encontrada!" << std::endl;
    return nullptr;
}
*/


std::string Cidade::listarCaravanas() const {
    std::ostringstream oss;
    oss << "Caravanas na cidade " << nome << ":" << std::endl;
//    for (const auto& caravana : caravanasNaCidade) {
//        // Assumindo que caravana é um shared_ptr ou unique_ptr
//        oss << "ID: " << caravana->getId() << " Tipo: " << caravana->exibirDetalhes() << std::endl;
//    }
    return oss.str();
}




