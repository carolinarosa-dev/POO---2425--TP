#include "Caravana.h"
#include "Cidade.h"
#include "Item.h"

using namespace std;

class Deserto {
public:
    enum TipoPosicao { VAZIO, MONTANHA, CIDADE };

    Deserto(int linhas, int colunas);

    void configurarMapa(const vector<vector<TipoPosicao>>& configuracao);
    string exibirMapa() const;
    bool posicaoValida(int linha, int coluna) const;

    //void adicionarCaravana(shared_ptr<Caravana> caravana, int linha, int coluna);
    //void adicionarCidade(shared_ptr<Cidade> cidade);
    void provocarTempestade(int linhaCentro, int colunaCentro, int raio);
    void adicionarItem(shared_ptr<Item> item, int linha, int coluna);
    void atualizarItens();
protected:
    void setMontanha(int linha, int coluna);

private:
    int numLinhas;
    int numColunas;
    vector<vector<TipoPosicao>> mapa;
    vector<shared_ptr<Caravana>> caravanas;
    vector<shared_ptr<Cidade>> cidades;
    vector<shared_ptr<Item>> itens;
    vector<pair<int, int>> posicoesItens;

};
#endif //POO_2024_25_TP_DESERTO_H


//
// Created by Carolina Rosa on 10/11/2024.
//


#include "Deserto.h"

// Construtor que inicializa o deserto com dimensões
Deserto::Deserto(int linhas, int colunas, int contadorInstantes)
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
