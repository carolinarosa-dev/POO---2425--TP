
#include <iostream>
#include <string>
#include <sstream>

#include "Caravana.h"

class Jogador {
private:
    int moedas;
    int combatesVencidos;           // Número de combates vencidos

public:
    Jogador(int moedasIniciais);

    int getMoedas() const;
    void adicionarMoedas(int quantidade);

    bool temCaravanas() const;
    std::string listarCaravanas() const;

//    void comprarCaravana(std::shared_ptr<Caravana>, int precoCaravana);

//    const vector<shared_ptr<Caravana>>& getCaravanas() const;
//    void adicionarCaravana(std::shared_ptr<Caravana> caravana);
};
