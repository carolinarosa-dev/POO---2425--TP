



#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <iostream>
#include <string>

#include <vector>
#include <memory>

#include "Utils.h"
#include "Buffer.h"
#include "Montanha.h"
#include "Jogador.h"
#include "Cidade.h"
#include "CaravanaBarbara.h"

class Simulador {

public:
    bool terminarSimulacao() const;
//    Deserto
    void adicionarMontanha(double latitude, double longitude);
//    cidade
    std::string adicionarCidade(std::shared_ptr<Cidade> cidade)const;
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
    Utils utils;
    Jogador jogador;
    int contadorInstantes;
    std::vector<Montanha> montanhas;

};

#endif //POO_2024_25_TP_SIMULADOR