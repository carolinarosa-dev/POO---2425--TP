//
// Created by Carolina Rosa on 10/11/2024.
//


#include "Deserto.h"

// Construtor que inicializa o deserto com dimensões
Deserto::Deserto(int linhas, int colunas)
        : numLinhas(linhas), numColunas(colunas), mapa(linhas, vector<TipoPosicao>(colunas, VAZIO)), contadorInstantes(0) {}

// Configura o mapa com cidades e montanhas
void Deserto::configurarMapa(const vector<vector<TipoPosicao>>& configuracao) {
    if (configuracao.size() != numLinhas || configuracao[0].size() != numColunas) {
        throw invalid_argument("Dimensões do mapa não coincidem com a configuração.");
    }
    mapa = configuracao;
}

// Exibe o estado atual do deserto
string Deserto::exibirMapa() const {
    ostringstream oss;
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            if (mapa[i][j] == MONTANHA)
                oss << "M ";
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
bool Deserto::posicaoValida(int linha, int coluna) const {
    return linha >= 0 && linha < numLinhas && coluna >= 0 && coluna < numColunas && mapa[linha][coluna] != MONTANHA;
}

void Deserto::moverCaravana(shared_ptr<Caravana> caravana, int direcao) {
    if (!caravana) {
        throw invalid_argument("Caravana inválida.");
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
            throw invalid_argument("Direção inválida.");
    }

    // Verificar se a nova posição é válida
    if (posicaoValida(novaLinha, novaColuna)) {
        // Atualizar a posição da caravana
        caravana->setPosicao(novaLinha, novaColuna);
    } else {
        throw runtime_error("Movimento inválido! A posição está ocupada ou fora dos limites.");
    }
}

// Adiciona uma caravana ao deserto (em uma posição válida)
void Deserto::adicionarCaravana(shared_ptr<Caravana> caravana, int linha, int coluna) {
    if (posicaoValida(linha, coluna)) {
        caravanas.push_back(caravana);
        caravana->setPosicao(linha, coluna);
    } else {
        throw invalid_argument("Posição inválida para adicionar a caravana.");
    }
}

// Adiciona uma cidade ao deserto
void Deserto::adicionarCidade(shared_ptr<Cidade> cidade) {
    int linha = cidade->getLinha();
    int coluna = cidade->getColuna();
    if (posicaoValida(linha, coluna)) {
        cidades.push_back(cidade);
        mapa[linha][coluna] = CIDADE;
    } else {
        throw invalid_argument("Posição inválida para adicionar a cidade.");
    }
}

// Provoca uma tempestade de areia em uma região do deserto
void Deserto::provocarTempestade(int linhaCentro, int colunaCentro, int raio) {
    for (int i = -raio; i <= raio; ++i) {
        for (int j = -raio; j <= raio; ++j) {
            int linha = (linhaCentro + i + numLinhas) % numLinhas;
            int coluna = (colunaCentro + j + numColunas) % numColunas;
            // Afeta a caravana na posição (linha, coluna) se houver uma
            for (auto& caravana : caravanas) {
                auto [caravanaLinha, caravanaColuna] = caravana->getPosicao();
                if (caravanaLinha == linha && caravanaColuna == coluna) {
                    caravana->perderTripulantes(5); // Exemplo de efeito da tempestade
                }
            }
        }
    }
}

// Define uma posição como montanha
void Deserto::setMontanha(int linha, int coluna) {
    if (posicaoValida(linha, coluna)) {
        mapa[linha][coluna] = MONTANHA;
    } else {
        throw invalid_argument("Posição inválida para configurar montanha.");
    }
}
