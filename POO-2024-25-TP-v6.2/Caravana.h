//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef CARAVANA_H
#define CARAVANA_H

#include <string>
#include <algorithm> // Para std::max
#include <vector>
#include <sstream>

#include"Comandos.h"
#include "Jogador.h"

//class Cidade; //cidade conhece as caravanas

using namespace  std;


class Caravana {
public:
    enum Tipo {
        COMERCIO, MILITAR, SECRETA, BARBARA
    };
    int tripulantes;

    Caravana(int id,Tipo tipo,  int linha, int coluna);
    static int getProximoId();
    virtual ~Caravana();
    Tipo getTipo() const;
    virtual string getDesignacaoTipo()const=0;//
    int getId() const;
    pair<int, int> getPosicao() const;
    pair<int, int> getPosicaoAnterior() const;
    void setPosicao(int novaLinha, int novaColuna);
    int getTripulantes() const;
    int getCarga() const;
    int getAgua() const;
    void adicionarTripulantes(int quantidade);
    void removerTripulantes(int quantidade);
    void adicionarCarga(int quantidade);
    void removerCarga(int quantidade);
    void reabastecerAgua();
    void consumirAgua();
    virtual void aplicarEfeitoItem(int tipoItem);
    bool estaDestruida() const;
    void perderTripulantes(int quantidade);
    void adicionarAgua(int quantidade);
    virtual string exibirDetalhes() const;
    bool estaEmCidade() const;
    void setEmCidade(bool estado);
    int getCapacidadeCarga() const;
    void setAutoGestao(bool estado);
    void setId(int newId);
    bool estaAdjacente(const Caravana& outra) const;
    void transferirAgua(Caravana& vencedora);
    void combater(Caravana& outra);




protected:

    int agua;
    int capacidadeAgua;
    int linha, coluna;
    Tipo tipo;
    int id;
    int linhaAnterior, colunaAnterior;
    int carga;
    int capacidadeCarga;
    int consumoAgua;
    vector<string> mercadorias;
    bool emCidade;
    bool autoGestao;
private:
    static  int proximoId; // Variável estática para gerar IDs único


};

#endif //POO_2024_25_TP_CARAVANA_H