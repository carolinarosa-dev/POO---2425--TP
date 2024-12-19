//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_DESERTO_H
#define POO_2024_25_TP_DESERTO_H



#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <sstream>
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

    void adicionarCaravana(shared_ptr<Caravana> caravana, int linha, int coluna);
    void adicionarCidade(shared_ptr<Cidade> cidade);
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
    int contadorInstantes;
};



#endif //POO_2024_25_TP_DESERTO_H
