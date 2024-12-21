



#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <iostream>
#include <string>

#include <vector>
#include <memory>

#include "Buffer.h"
#include "Jogador.h"
#include "Cidade.h"
#include "CaravanaBarbara.h"

class Simulador {

public:
//    simulador
    Simulador();
    //Simulador(int linhas, int colunas, int moedasIniciais);
    Simulador(int linhas, int colunas, Buffer *buffer);

    bool terminarSimulacao() const;
//    cidade
    std::string adicionarCidade(std::shared_ptr<Cidade> cidade);
    const std::vector<std::shared_ptr<Cidade>> &getCidades() const;
    void listarCaravanasNaCidade(char cidadeLetra) const;

    //    Itens
//    caravanas

    std::string criarCaravanaBarbara(int linha, int coluna) const;
    void adicionaCaravanaJogador(std::shared_ptr<Caravana> caravana);//processaMapa
    std::string jogadorCompraCaravana(char cidadeLetra, char tipoCaravana, int precoCaravana) const;//comprac
    void adicionaCaravanaBarbara(std::shared_ptr<CaravanaBarbara> caravana);

    void mostrarDescricaoCaravana(int idCaravana) const;

    void moverCaravana(int idCaravana, const std::string &direcao, char** mapa);
    void ativarAutoGestao(int idCaravana);
    void desativarAutoGestao(int idCaravana);


//    compras e vendas
    void comprarMercadoria(int idCaravana, int quantidadeMercadoria, int precoCompraMercadoria);
    void venderMercadoria(int idCaravana, int precoVendaMercadoria);

//    combates

private:
    Jogador jogador;

};

#endif //POO_2024_25_TP_SIMULADOR