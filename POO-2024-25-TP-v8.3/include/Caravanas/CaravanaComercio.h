#ifndef POO_2024_25_TP_CARAVANACOMERCIO_H
#define POO_2024_25_TP_CARAVANACOMERCIO_H

#include "Caravana.h"

class CaravanaComercio : public Caravana {
public:
    CaravanaComercio();

    CaravanaComercio(Tipo tipo, int linha, int coluna);

    virtual std::string getDesignacaoTipo()const override;

    ~CaravanaComercio() override;

};
#endif //POO_2024_25_TP_CARAVANACOMERCIO_H