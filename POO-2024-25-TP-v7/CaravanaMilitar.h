
#ifndef POO_2024_25_TP_CARAVANAMILITAR_H
#define POO_2024_25_TP_CARAVANAMILITAR_H

#include "Caravana.h"

class CaravanaMilitar : public Caravana {
public:
    CaravanaMilitar(int id, int linha, int coluna);


    void aplicarEfeitoItem(int tipoItem) ;

    virtual std::string getDesignacaoTipo()const override;
    ~CaravanaMilitar() override;
};



#endif //POO_2024_25_TP_CARAVANAMILITAR_H