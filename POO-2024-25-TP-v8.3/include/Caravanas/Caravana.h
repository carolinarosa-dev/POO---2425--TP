#ifndef POO_2024_25_TP_CARAVANA_H
#define POO_2024_25_TP_CARAVANA_H

#include <iostream>
#include <string>
#include <vector>

#include "Simulador.h"

class Comandos;

class Caravana{
public:
    enum Tipo {
        COMERCIO, MILITAR, SECRETA, BARBARA
    };

    // Caravana();
    Caravana(Tipo tipo,  int linha, int coluna);


    Tipo getTipo() const;

    int getId() const;

    std::pair<int, int> getPosicaoCaravana() const;
    std::pair<int, int> getPosicaoAnteriorCaravana() const;

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

    bool estaEmCidade() const;

    void setEmCidade(bool estado);
    int getCapacidadeCarga() const;
    void setAutoGestao(bool estado);

    virtual std::string getDesignacaoTipo()const=0;//
    virtual std::string exibirDetalhes() const;
    virtual ~Caravana();
protected:

    //Comandos comandos;

    Tipo tipo;
    int linha, coluna;
    int linhaAnterior, colunaAnterior;
    int tripulantes;
    int carga;
    int agua;
    int capacidadeCarga;
    int capacidadeAgua;
    int consumoAgua;
    std::vector<std::string> mercadorias;
    bool emCidade;
    bool autoGestao;
private:
    static int id; // Variável estática para gerar IDs único
};
#endif //POO_2024_25_TP_CARAVANA_H