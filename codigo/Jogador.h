//
// Created by Carolina Rosa on 10/11/2024.
//

#ifndef JOGADOR_H
#define JOGADOR_H
#include <memory>
#include <vector>


#include"Simulador.h"

class Caravana;

using namespace std;

    int combatesVencidos;           // Número de combates vencidos
    vector<shared_ptr<Caravana>> caravanas; // DONO

public:
    void comprarCaravana(std::shared_ptr<Caravana>, int precoCaravana);

    bool temCaravanas() const;
    void listarCaravanas() const;
    const vector<shared_ptr<Caravana>>& getCaravanas() const;
//fazer um metodo para procura a caravana  e devolve o weak_ptr
//    for (const auto& caravana : caravanas) {
//        if (caravana->getId() == idCaravana) {
//            caravanaEncontrada = caravana;
//            break;
//        }
//    }
    void adicionarCaravana(std::shared_ptr<Caravana> caravana);
};

#endif //POO_2024_25_TP_JOGADOR_H
