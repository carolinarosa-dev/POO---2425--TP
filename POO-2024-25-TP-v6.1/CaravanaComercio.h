//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef POO_2024_25_TP_CARAVANACOMERCIO_H
#define POO_2024_25_TP_CARAVANACOMERCIO_H

#include "Caravana.h"

class CaravanaComercio : public Caravana {
public:
    CaravanaComercio();
    CaravanaComercio(int id, int linha, int coluna);
    ~CaravanaComercio() override;
    //void mover(char direcao) override;
    void aplicarEfeitoItem(int tipoItem) override;
    void esconder();
    //string exibirDetalhes() const;
    virtual string getDesignacaoTipo()const override{
        return "caravana comercio ";
    }

};



#endif //POO_2024_25_TP_CARAVANACOMERCIO_H