#ifndef POO_2024_25_TP_CIDADE_H
#define POO_2024_25_TP_CIDADE_H

#include <iostream>
#include <memory>

class Cidade {
public:
    Cidade(char nome, int linha, int coluna);

    void adicionarCaravana(std::shared_ptr<Caravana> caravana);//conhece do dono jogador

};
#endif //POO_2024_25_TP_CIDADE_H