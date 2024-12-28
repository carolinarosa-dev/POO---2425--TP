/*
Capacidade de Tripulantes: Máximo de 10 tripulantes.
Velocidade: Muito rápida, pode se deslocar até 4 vezes por turno.
Capacidade de Carga: Pequena, não transporta carga.
Capacidade de Água: 100 litros de água.
Consumo de Água: Gasta 1 litro de água por instante, 0.5 litros se tiver menos de metade dos tripulantes, 0 se não tiver nenhum tripulante.
Movimento Autônomo: Se move de forma furtiva, evitando outras caravanas e bárbaros. Se houver um item a uma distância de 3 linhas e/ou colunas, desloca-se para apanhá-lo.
Tempestade de Areia: Tem 20% de chance de ser destruída em uma tempestade de areia. Se sobreviver, não sofre perdas adicionais.
Desaparecimento: Se ficar sem tripulantes, move-se de forma aleatória e desaparece após 3 instantes.
Habilidade Especial: Pode se esconder por um turno, tornando-se invisível para outras caravanas e bárbaros.
*/

#ifndef POO_2024_25_TP_CARAVANASECRETA_H
#define POO_2024_25_TP_CARAVANASECRETA_H

#include "../include/Caravanas/Caravana.h"

class CaravanaSecreta : public Caravana {

public:
//    CaravanaSecreta(int id, int linha, int coluna);
    CaravanaSecreta(int id,  int linha, int coluna, Tipo tipo);

    virtual std::string getDesignacaoTipo()const override;

    ~CaravanaSecreta() override;
};

#endif //POO_2024_25_TP_CARAVANASECRETA_H