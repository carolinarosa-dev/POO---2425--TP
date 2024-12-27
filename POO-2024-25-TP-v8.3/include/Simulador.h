#ifndef POO_2024_25_TP_SIMULADOR_H
#define POO_2024_25_TP_SIMULADOR_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "memory"
//#include "Mapa/Cidade.h"

#include "Buffer.h"
class Caravana;
class CaravanaBarbara;
class Cidade;
class Jogador;

class Simulador {

public:
    Simulador(int linhas, int colunas);
    void setFase(int fase);


    int getFase()const;
    bool terminarSimulacao() const;


//    Deserto
    void adicionarMontanha(double latitude, double longitude);
//    cidade
    void adicionarCidade(std::unique_ptr<Cidade> cidade);
    void listarCaravanasNaCidade(char cidadeLetra) const;
    char getCaractere(int l, int c) const;
    int getLinhas() const;
    int getColunas() const;
    char** getMapa() const;
    std::unique_ptr<Cidade> encontrarCidade(char letraCidade);
    void imprimeMapa() const;
//    Itens

//    caravanas
    void adicionaCaravanaJogador(std::unique_ptr<Caravana> caravana);//processaMapa
    void jogadorCompraCaravana(char cidadeLetra, char tipoCaravana, int precoCaravana) const;//comprac
    void adicionaCaravanaBarbara(std::unique_ptr<CaravanaBarbara> caravana);
    void setLinhaMapa(int l, int c, char linha);

//    void moverCaravana(int idCaravana, const std::string &direcao, char** mapa);
//    void ativarAutoGestao(int idCaravana);
//    void desativarAutoGestao(int idCaravana);
//
//    compras e vendas
    void comprarMercadoria(int idCaravana, int quantidadeMercadoria, int precoCompraMercadoria);
    void venderMercadoria(int idCaravana, int precoVendaMercadoria);
//
////    combates
//     jogador
    std::shared_ptr<Jogador>getJogador();

private:
    Buffer* bufferAtual;
    //std::map<std::string, Buffer*> buffersSalvos;
    int fase;
    char** mapa;
    int linhas, colunas;
    std::vector<std::unique_ptr<Cidade>> cidades;
    std::shared_ptr<Jogador> jogador;
    std::vector<std::unique_ptr<CaravanaBarbara>> caravanasBarbaras;
    int contadorInstantes;

//recebe o preco no comando comprac
    int precoComprac;


};
#endif //POO_2024_25_TP_SIMULADOR_H