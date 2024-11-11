//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Cidade.h"

    // Construtor
    Cidade::Cidade(char nome, int linha, int coluna) : nome(nome), linha(linha), coluna(coluna), tripulantes(10) {
        // Inicializa algumas mercadorias como exemplo
        mercadorias.push_back("Água");
        mercadorias.push_back("Comida");
        mercadorias.push_back("Armas");
    }

    // Adiciona uma caravana à cidade
    void Cidade::adicionarCaravana(Caravana* caravana) {
        caravanas.push_back(caravana);
        std::cout << "Caravana adicionada à cidade " << nome << ".\n";
    }

    // Remove uma caravana da cidade
    void Cidade::removerCaravana(Caravana* caravana) {
        for (auto it = caravanas.begin(); it != caravanas.end(); ++it) {
            if (*it == caravana) {
                caravanas.erase(it);
                std::cout << "Caravana removida da cidade " << nome << ".\n";
                return;
            }
        }
        std::cout << "Caravana não encontrada na cidade " << nome << ".\n";
    }

    // Recruta tripulantes para uma caravana
    void Cidade::recrutarTripulantes(Caravana* caravana, int quantidade) {
        if (quantidade > tripulantes) {
            std::cout << "Não há tripulantes suficientes na cidade " << nome << ".\n";
            return;
        }
        tripulantes -= quantidade;
        caravana->adicionarTripulantes(quantidade);
        std::cout << quantidade << " tripulantes recrutados para a caravana.\n";
    }

    // Permite que uma caravana compre mercadorias da cidade
    void Cidade::comprarMercadoria(Caravana* caravana, const std::string& mercadoria) {
        if (std::find(mercadorias.begin(), mercadorias.end(), mercadoria) == mercadorias.end()) {
            std::cout << "Mercadoria " << mercadoria << " não disponível na cidade " << nome << ".\n";
            return;
        }
        caravana->comprarMercadoria(mercadoria);
        std::cout << "Mercadoria " << mercadoria << " comprada pela caravana.\n";
    }

    // Permite que uma caravana venda mercadorias à cidade
    void Cidade::venderMercadoria(Caravana* caravana, const std::string& mercadoria) {
        caravana->venderMercadoria(mercadoria);
        std::cout << "Mercadoria " << mercadoria << " vendida à cidade " << nome << ".\n";
    }

    // Exibe as caravanas na cidade
    void Cidade::listarCaravanas() {
        std::cout << "Caravanas na cidade " << nome << ":\n";
        if (caravanas.empty()) {
            std::cout << "Nenhuma caravana na cidade.\n";
        } else {
            for (auto& caravana : caravanas) {
                caravana->exibirDetalhes();
            }
        }
    }

    // Função de utilidade para ver a posição da cidade no mapa
    void Cidade::mostrarPosicao() {
        std::cout << "Cidade " << nome << " localizada em (" << linha << ", " << coluna << ").\n";
    }

    // Getter para o nome da cidade
    char Cidade::getNome() const {
        return nome;
    }

    // Getter para o número de tripulantes disponíveis
    int Cidade::getTripulantes(int tripulantes) {
        return tripulantes;
    }

