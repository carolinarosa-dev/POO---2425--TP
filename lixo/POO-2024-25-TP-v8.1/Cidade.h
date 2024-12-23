#ifndef POO_2024_25_TP_CIDADE_H
#define POO_2024_25_TP_CIDADE_H

#include <iostream>
#include <vector>
#include <memory>
#include "sstream"
#include "Utils.h"

class Cidade {
public:
    Cidade(char nome, int linha, int coluna);
    char getNome() const;
    int getTripulantes() const;
    bool possuiCaravana(Caravana::Tipo tipo);
    void adicionaCaravanaCidade(std::unique_ptr<Caravana> caravana);//conhece do dono jogador
    std::shared_ptr<Caravana> cidadeVendeCaravana(int id);

    std::string listarCaravanas() const;

private:
    //Utils posCidade;
    char nome;
    int linha, coluna;
    int tripulantes;

    std::vector<std::unique_ptr<Caravana>> caravanasNaCidade;
    std::vector<std::string> mercadorias;


};
#endif //POO_2024_25_TP_CIDADE_H