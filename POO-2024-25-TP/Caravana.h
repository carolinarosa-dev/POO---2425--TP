//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_CARAVANA_H
#define POO_2024_25_TP_CARAVANA_H

#include <string>
#include <algorithm> // Para std::max
#include <vector>
#include "Cidade.h"
#include <sstream>

using namespace  std;


class Caravana {
public:
    enum Tipo { COMERCIO, MILITAR, SECRETA, BARBARA };

    Caravana(Tipo tipo, int id, int linha, int coluna);
    virtual ~Caravana() = default;

    Tipo getTipo() const;
    int getId() const;
    pair<int, int> getPosicao() const;
    void setPosicao(int novaLinha, int novaColuna);
    int getTripulantes() const;
    int getCarga() const;
    int getAgua() const;
    virtual void mover(char direcao);
    void adicionarTripulantes(int quantidade);
    void removerTripulantes(int quantidade);
    void adicionarCarga(int quantidade);
    void removerCarga(int quantidade);
    void venderMercadoria(const std::string& mercadoria);
    void comprarMercadoria(const std::string& mercadoria);
    void reabastecerAgua();
    void consumirAgua();
    virtual void aplicarEfeitoItem(int tipoItem);
    bool estaDestruida() const;
    void perderTripulantes(int quantidade);
    void adicionarAgua(int quantidade);
    void exibirDetalhes();

protected:
    Tipo tipo;
    int id;
    int linha, coluna;
    int tripulantes;
    int carga;
    int agua;
    int capacidadeCarga;
    int capacidadeAgua;
    int consumoAgua;
    std::vector<std::string> mercadorias;

};

#endif //POO_2024_25_TP_CARAVANA_H
