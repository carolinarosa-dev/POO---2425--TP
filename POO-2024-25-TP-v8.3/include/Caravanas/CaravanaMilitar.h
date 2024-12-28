
#ifndef POO_2024_25_TP_CARAVANAMILITAR_H
#define POO_2024_25_TP_CARAVANAMILITAR_H

#include "../include/Caravanas/Caravana.h"

class CaravanaMilitar : public Caravana {

public:
    CaravanaMilitar(int id, int linha, int coluna, Tipo tipo);

    virtual std::string getDesignacaoTipo()const override;

    ~CaravanaMilitar() override;
};
#endif //POO_2024_25_TP_CARAVANAMILITAR_H