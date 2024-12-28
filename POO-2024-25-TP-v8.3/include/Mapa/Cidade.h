#ifndef POO_2024_25_TP_CIDADE_H
#define POO_2024_25_TP_CIDADE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Caravanas/Caravana.h"
class Comandos;
class Simulador;

class Cidade {
public:
    Cidade(char nome, int linha, int coluna);
    char getNome() const;
    std::pair<int, int>getPosicaoCidade() const;

    int getTripulantes() const;
    bool possuiCaravana(Caravana::Tipo tipo);
    std::unique_ptr<Caravana>removerCaravanaDaCidadeParaJogador(Caravana::Tipo tipo);

    void adicionaCaravanasCidade(std::unique_ptr<Caravana> caravana);
    std::string listarCaravanas() const;

private:

    char nome;
    int linha, coluna;
    int tripulantes;

    std::vector<std::unique_ptr<Caravana>> caravanasCidade;
    std::vector<std::string> mercadorias;


};
#endif //POO_2024_25_TP_CIDADE_H