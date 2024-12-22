#ifndef CARAVANA_H
#define CARAVANA_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> // Para std::max
#include <vector>

#include "Utils.h"

class Caravana{
public:
    enum Tipo {
        COMERCIO, MILITAR, SECRETA, BARBARA
    };

    Caravana(int linha, int coluna);


    Caravana(int id,Tipo tipo,  int linha, int coluna);

    void setId(int newId);
    Tipo getTipo() const;
    int getId() const;

    //para imprimir o tipo de caravana correspondente
    virtual std::string getDesignacaoTipo()const=0;//
    virtual std::string exibirDetalhes() const;

//    triulantes
    int getTripulantes() const;
    void adicionarTripulantes(int quantidade);
    void perderTripulantes(int quantidade);
    void removerTripulantes(int quantidade);

//    deslocamento / movimento
    std::pair<int, int> getPosicao() const;
    std::pair<int, int> getPosicaoAnterior() const;
    void setPosicao(int novaLinha, int novaColuna);
    void setAutoGestao(bool estado);


//    mercadoria / carga
    int getCapacidadeCarga() const;

//    agua
    void adicionarAgua(int quantidade);
    int getAgua() const;
    void consumirAgua();
    void reabastecerAgua();


    int getCarga() const;
    void adicionarCarga(int quantidade);
    void removerCarga(int quantidade);

    virtual void aplicarEfeitoItem(int tipoItem);

    bool estaEmCidade() const;
    void setEmCidade(bool estado);

    bool estaDestruida() const;
    virtual ~Caravana();

protected:

    Tipo tipo;
    static int id;
    //Utils posCaravana;
    int linha, coluna;
    int linhaAnterior, colunaAnterior;
    int tripulantes;
    int carga;
    int agua;
    int capacidadeCarga;
    int capacidadeAgua;
    int consumoAgua;

    bool emCidade;
    bool autoGestao;

    std::vector<std::string> mercadorias;

};
#endif //POO_2024_25_TP_CARAVANA_H