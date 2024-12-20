//
// Created by Tinoco on 27/11/2024.
//
#ifndef POO_2024_25_TP_CARAVANABARBARA_H
#define POO_2024_25_TP_CARAVANABARBARA_H

#include "Caravana.h"
//#include "Cidade.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>



class CaravanaBarbara : public Caravana {
public:
    CaravanaBarbara(int id, int linha, int coluna);
    ~CaravanaBarbara() override;

    void moverAleatoriamente();
    void moverParaCaravana(int caravanaLinha, int caravanaColuna);
    bool verificarProximidade(int caravanaLinha, int caravanaColuna);
    void apanharItens(const std::string& item);
    void enfrentarTempestade();
    std::string turno(int caravanaLinha = -1, int caravanaColuna = -1);
    virtual string getDesignacaoTipo()const override{
        return "caravana barbara ";
    }
private:
    int turnosAteDesaparecer;


};


#endif //POO_2024_25_TP_CARAVANABARBARA_H