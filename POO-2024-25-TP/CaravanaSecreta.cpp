//
// Created by Carolina Rosa on 10/11/2024.
//

#include "CaravanaSecreta.h"


CaravanaSecreta::CaravanaSecreta(int id, int linha, int coluna)
        : Caravana(SECRETA, id, linha, coluna) {
    // Definir características da caravana secreta
}

void CaravanaSecreta::mover(char direcao) {
    // Implementar lógica de movimentação específica para caravana secreta
}

void CaravanaSecreta::aplicarEfeitoItem(int tipoItem) {
    // Implementar lógica específica de aplicação de efeito de item
}
