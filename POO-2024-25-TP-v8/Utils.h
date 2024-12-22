//
// Created by Tinoco on 20/12/2024.
//

#ifndef POO_2024_25_TP_UTILS_H
#define POO_2024_25_TP_UTILS_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>


//#include "Jogador.h"
//
//#include "Simulador.h"
//#include "CaravanaComercio.h"
//#include "CaravanaMilitar.h"
//#include "CaravanaSecreta.h"

class Comandos;

class Utils {

public:
    Utils();


    void limparDados();

    //Validacoes
    bool validarArgumentos(const std::string &comando, std::string& mensagem) const;
    bool posicaoValida(int linha, int coluna, char** mapa) const;



    bool executarComando(const std::string &comando, std::string &mensagem) const; // Método para execução de comandos

    void limparMapa();
    std::string processaMapa() const;
    void atualizaMapa();
    std::string mostrarMapa() const;

    std::string mostrarConfig() const;


    int calcularPontuacao() const;

    void setAtributosConfiguraveis(std::map<std::string, int>& atributos, const std::string& chave, int novoValor);
    int getAtributoConfiguraveis(const std::map<std::string, int>& atributos, const std::string& chave);




////    int instantesEntreNovosItens;
////    int duracaoItem;
////    int maxItens;
//    int getPrecoVendaMercadoria() const;
//    int getPrecoCompraMercadoria() const;
////    int precoCaravana;
////    int instantesEntreNovosBarbaros;
////    int duracaoBarbaros;
//
//    void setInstantesEntreNovosItens(int instantesEntreNovosIntens);
//    void setDuracaoItem(int duracaoItem);
//    void setMaxItens(int maxItens);
//    void setPrecoVendaMercadoria(int PrecoVendaMercadoria);
//    void setPrecoCompraMercadoria(int PrecoCompraMercadoria);
//    void setPrecoCaravana(int PrecoCaravana);
//    void setInstantesEntreNovosBarbaros(int instantesEntreNovosBarbaros);
//    void setDuracaoBarbaros(int duracaoBarbaros);

    ~Utils();
private:
    Comandos* comandos;
//    Jogador jogador;
//    Simulador simulador;

    int linha, coluna;

    //configuraveis
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
    std::map<std::string, int> atributosConfiguraveis;


};


#endif //POO_2024_25_TP_UTILS_H
