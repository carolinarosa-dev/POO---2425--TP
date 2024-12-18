//
// Created by Carolina Rosa on 10/11/2024.
//

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

#include "CaravanaSecreta.h"

/*
CaravanaSecreta::CaravanaSecreta(int id, int linha, int coluna)
        : Caravana(id,SECRETA, linha, coluna) {

    tripulantes = 10;
    capacidadeAgua = 100;
    consumoAgua = 1;

}*/

CaravanaSecreta::CaravanaSecreta(int id,int linha, int coluna)
        : Caravana(id,Tipo::SECRETA, linha, coluna) {
    tripulantes = 10;
    capacidadeAgua = 100;
    consumoAgua = 1;
}

CaravanaSecreta::~CaravanaSecreta() {}


void CaravanaSecreta::mover(char direcao) {
    // Implementar lógica de movimentação específica para Caravana Secreta
    std::cout << "Movendo Caravana Secreta na direcao " << direcao << std::endl;
}

void CaravanaSecreta::aplicarEfeitoItem(int tipoItem) {
    // Implementar lógica de aplicação de efeito de item específica para Caravana Secreta
    std::cout << "Aplicando efeito do item " << tipoItem << " na Caravana Secreta" << std::endl;
}
void CaravanaSecreta::esconder() {
    // Implementar lógica para esconder a caravana
    std::cout << "Caravana Secreta esta se escondendo." << std::endl;
}
//string CaravanaSecreta::exibirDetalhes() const {
//    ostringstream oss;
//    oss << "Caravana Secreta ID: " << id << ", Tripulantes: " << tripulantes << "\n";
//    return oss.str();
//}