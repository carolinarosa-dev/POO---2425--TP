#ifndef POO_2024_25_TP_SIMULADOR_H
#define POO_2024_25_TP_SIMULADOR_H


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
    std::vector<std::string>& getMapaFicheiro();
    std::map<std::string, int>& getAtributosConfiguraveis();
    void setInstantesEntreNovosItens (int instantesEntreNovosItens);
    void setDuracaoItem (int duracaoItem);
    void setMaxItens (int maxItens);
    void setPrecoVendaMercadoria (int precoVendaMercadoria);
    void setPrecoCompraMercadoria (int precoCompraMercadoria);
    void setPrecoCaravana (int precoCaravana);
    void setInstantesEntreNovosBarbaros (int instantesEntreNovosBarbaros);
    void setDuracaoBarbaros (int duracaoBarbaros);

//    int getInstantesEntreNovosItens() const;
//    int getDuracaoItem() const;
//    int getMaxItens() const;
//    int getPrecoVendaMercadoria() const;
//    int getPrecoCompraMercadoria() const;
//    int getPrecoCaravana() const;
//    int getInstantesEntreNovosBarbaros() const;
//    int getDuracaoBarbaros() const;

//    Deserto
    void adicionarMontanha(double latitude, double longitude);
//    cidade
    std::string adicionarCidade(std::shared_ptr<Cidade> cidade)const;
//    const std::vector<std::shared_ptr<Cidade>> &getCidades() const;
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
    //recebe o preco no comando comprac
    int precoComprac;
public:
    int getPrecoComprac() const;

    void setPrecoComprac(int precoComprac);

private:
    //Utils utils;
    Jogador jogador;
    int contadorInstantes;

    std::vector<std::string> mapaFicheiro;
    std::vector<Montanha> montanhas;

    //configuraveis
    std::map<std::string, int> atributosConfiguraveis;
    int instantesEntreNovosItens;
    int duracaoItem;
    int maxItens;
    int precoVendaMercadoria;
    int precoCompraMercadoria;
    int precoCaravana;
    int instantesEntreNovosBarbaros;
    int duracaoBarbaros;

    // Criar entidades com suas coordenadas
    std::pair<int, int> posDeserto;   // Coordenadas da Deserto
    std::pair<int, int> posMontanha;   // Coordenadas da Montanha
    std::pair<int, int> posCidade;     // Coordenadas da Cidade
    std::pair<int, int> posItem ;       // Coordenadas de um Item
    std::pair<int, int> posCaravana;   // Coordenadas da Caravana


};

#endif //POO_2024_25_TP_SIMULADOR_H