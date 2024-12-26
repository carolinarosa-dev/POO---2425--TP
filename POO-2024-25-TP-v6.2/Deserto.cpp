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
        throw invalid_argument("Dimensoes do mapa nao coincidem com a configuracao.");
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
            else if (mapa[i][j] == ITEM)
                oss << "@ ";
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



// Adiciona uma caravana ao deserto (em uma posição válida)
void Deserto::adicionarCaravana(shared_ptr<Caravana> caravana, int linha, int coluna) {
    if (posicaoValida(linha, coluna)) {
        caravanas.push_back(caravana);
        caravana->setPosicao(linha, coluna);
    } else {
        throw invalid_argument("Posicao invalida para adicionar a caravana.");
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
        throw invalid_argument("Posicao invalida para adicionar a cidade.");
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
        throw invalid_argument("Posicao invalida para configurar montanha.");
    }
}

void Deserto::adicionarItem(std::shared_ptr<Item> item) {
    if (posicaoValida(item->getLinha(), item->getColuna())) {
        itens.push_back(item);
        mapa[item->getLinha()][item->getColuna()] = ITEM;
    } else {
        throw std::invalid_argument("Posicao invalida para adicionar item.");
    }
}

void Deserto::verificarItens(std::shared_ptr<Jogador> jogador) {
    for (auto& caravana : caravanas) {
        auto [linha, coluna] = caravana->getPosicao();
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                int novaLinha = (linha + i + numLinhas) % numLinhas;
                int novaColuna = (coluna + j + numColunas) % numColunas;
                if (mapa[novaLinha][novaColuna] == ITEM) {
                    for (auto it = itens.begin(); it != itens.end(); ++it) {
                        if ((*it)->getLinha() == novaLinha && (*it)->getColuna() == novaColuna) {
                            (*it)->aplicarEfeito(caravana, jogador);
                            itens.erase(it);
                            mapa[novaLinha][novaColuna] = VAZIO;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void Deserto::atualizarItens() {
    for (auto it = itens.begin(); it != itens.end();) {
        (*it)->diminuirDuracao();
        if ((*it)->getDuracao() <= 0) {
            mapa[(*it)->getLinha()][(*it)->getColuna()] = VAZIO;
            it = itens.erase(it);
        } else {
            ++it;
        }
    }
}
