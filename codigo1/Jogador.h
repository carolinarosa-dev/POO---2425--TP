#include"Simulador.h"

class Caravana;

public:
    void comprarCaravana(std::shared_ptr<Caravana>, int precoCaravana);

    void listarCaravanas() const;
    const vector<shared_ptr<Caravana>>& getCaravanas() const;
//fazer um metodo para procura a caravana  e devolve o weak_ptr
//    for (const auto& caravana : caravanas) {
//        if (caravana->getId() == idCaravana) {
//            caravanaEncontrada = caravana;
//            break;
//        }
//    }

};

#endif //POO_2024_25_TP_JOGADOR_H
//#include"Caravana.h"

#include "Jogador.h"
#include "CaravanaComercio.h"
#include "CaravanaMilitar.h"
#include "CaravanaSecreta.h"
#include <iostream>

class Caravana;



void Jogador::comprarCaravana(std::shared_ptr<Caravana> caravana, int precoCaravana) {
    if (moedas >= precoCaravana) {
        caravana->setId(caravanas.size()+1);
        caravanas.push_back(caravana);
        cout << "moedas antes " << moedas << endl;
        moedas -= precoCaravana;
        cout << "moedas depois" << moedas << endl;
    } else {
        throw runtime_error("Moedas insuficientes para comprar uma caravana!");
    }
}

const vector<shared_ptr<Caravana>>& Jogador::getCaravanas() const {
    return caravanas;
}
