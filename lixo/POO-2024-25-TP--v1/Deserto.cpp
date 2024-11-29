//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Deserto.h"

// Construtor que inicializa o deserto com dimensões
Deserto::Deserto(int linhas, int colunas)
        : numLinhas(linhas), numColunas(colunas), mapa(linhas, std::vector<TipoPosicao>(colunas, VAZIO)) {}

// Configura o mapa com cidades e montanhas
void Deserto::configurarMapa(const std::vector<std::vector<TipoPosicao>>& configuracao) {
    if (configuracao.size() != numLinhas || configuracao[0].size() != numColunas) {
        throw std::invalid_argument("Dimensões do mapa não coincidem com a configuração.");
    }
    mapa = configuracao;
}

// Exibe o estado atual do deserto
string Deserto::exibirMapa() {
    ostringstream oss;
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            if (mapa[i][j] == MONTANHA)
                oss<< "M ";
            else if (mapa[i][j] == CIDADE)
                oss << "C ";
            else
                oss << ". ";
        }
        oss << endl;
    }
    return oss.str();
}

// Verifica se uma posição é válida para uma caravana (não montanha)
bool Deserto::posicaoValida(int linha, int coluna) {
    return linha >= 0 && linha < numLinhas && coluna >= 0 && coluna < numColunas && mapa[linha][coluna] != MONTANHA;
}



void Deserto::moverCaravana(Caravana* caravana, int direcao) {
    if (!caravana) {
        std::cout << "Caravana inválida.\n";
        return;
    }

    // Obter a posição atual da caravana
    auto [linhaAtual, colunaAtual] = caravana->getPosicao();

    int novaLinha = linhaAtual;
    int novaColuna = colunaAtual;

    // Movimento esférico
    switch (direcao) {
        case 0: novaLinha = (linhaAtual - 1 + numLinhas) % numLinhas; break; // Cima
        case 1: novaLinha = (linhaAtual + 1) % numLinhas; break; // Baixo
        case 2: novaColuna = (colunaAtual - 1 + numColunas) % numColunas; break; // Esquerda
        case 3: novaColuna = (colunaAtual + 1) % numColunas; break; // Direita
        case 4: // Diagonal Cima-Esquerda
            novaLinha = (linhaAtual - 1 + numLinhas) % numLinhas;
            novaColuna = (colunaAtual - 1 + numColunas) % numColunas;
            break;
        case 5: // Diagonal Cima-Direita
            novaLinha = (linhaAtual - 1 + numLinhas) % numLinhas;
            novaColuna = (colunaAtual + 1) % numColunas;
            break;
        case 6: // Diagonal Baixo-Esquerda
            novaLinha = (linhaAtual + 1) % numLinhas;
            novaColuna = (colunaAtual - 1 + numColunas) % numColunas;
            break;
        case 7: // Diagonal Baixo-Direita
            novaLinha = (linhaAtual + 1) % numLinhas;
            novaColuna = (colunaAtual + 1) % numColunas;
            break;
        default:
            std::cout << "Direção inválida.\n";
            return;
    }

    // Verificar se a nova posição é válida
    if (posicaoValida(novaLinha, novaColuna)) {
        // Atualizar a posição da caravana
        caravana->setPosicao(novaLinha, novaColuna);
        std::cout << "Caravana movida para (" << novaLinha << ", " << novaColuna << ").\n";
    } else {
        std::cout << "Movimento inválido! A posição está ocupada ou fora dos limites.\n";
    }
}
// Adiciona uma caravana ao deserto (em uma posição válida)
void Deserto::adicionarCaravana(Caravana* caravana, int linha, int coluna) {
    if (posicaoValida(linha, coluna)) {
        // Assumir que a caravana tem método para se registrar no deserto
        // caravana->registrarNoDeserto();
        //caravanas.push_back(caravana);
        std::cout << "Caravana adicionada ao deserto em (" << linha << ", " << coluna << ").\n";
    } else {
        std::cout << "Posição inválida para adicionar a caravana.\n";
    }
}

/*
shared_ptr<Cidade> Deserto::arrayCidade(char nome) {
    for (const auto& cidade : cidades) {
        if (cidade->getNome() == nome) {
            return cidade;  // Retorna a cidade encontrada
        }
    }
    return nullptr;  // Retorna nullptr se a cidade não for encontrada
}*/