#ifndef POO_2024_25_TP_SIMULADOR_H
#define POO_2024_25_TP_SIMULADOR_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "memory"
//#include "Mapa/Cidade.h"

#include "Caravanas/Caravana.h"

class Cidade;
class Jogador;

class Simulador {

public:
    Simulador();
    void setFase(int fase);


    int getFase()const;
    bool terminarSimulacao() const;


//    Deserto
    void adicionarMontanha(double latitude, double longitude);
//    cidade
//    std::vector<std::unique_ptr<Cidade>> getCidade()const;
//    std::string adicionarCidade(std::shared_ptr<Cidade> cidade)const;
//    const std::vector<std::shared_ptr<Cidade>> &getCidades() const;
    void listarCaravanasNaCidade(char cidadeLetra) const;

    //    Itens
//    caravanas
//    std::string criarCaravanaBarbara(int linha, int coluna) const;
//   void adicionaCaravanaJogador(std::shared_ptr<Caravana> caravana);//processaMapa
    std::string jogadorCompraCaravana(char cidadeLetra, char tipoCaravana, int precoCaravana) const;//comprac
//    void adicionaCaravanaBarbara(std::shared_ptr<CaravanaBarbara> caravana);
//
//    void mostrarDescricaoCaravana(int idCaravana) const;
//
//    void moverCaravana(int idCaravana, const std::string &direcao, char** mapa);
//    void ativarAutoGestao(int idCaravana);
//    void desativarAutoGestao(int idCaravana);
//
////    compras e vendas
//    void comprarMercadoria(int idCaravana, int quantidadeMercadoria, int precoCompraMercadoria);
//    void venderMercadoria(int idCaravana, int precoVendaMercadoria);
//
////    combates


private:
    int fase;

    std::vector<std::unique_ptr<Cidade>> cidades;
    std::shared_ptr<Jogador> jogador;
    int contadorInstantes;

//recebe o preco no comando comprac
    int precoComprac;


};


#endif //POO_2024_25_TP_SIMULADOR_H