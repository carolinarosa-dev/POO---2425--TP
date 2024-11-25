
#include <iostream>

//#include "Interface.h"
#include "CaravanaComercio.h"
#include "CaravanaMilitar.h"
#include "CaravanaSecreta.h"
#include "Simulador.h"

using namespace std;


int main() {
    // Defina os valores para os parâmetros do construtor
    int moedasJogador = 1000;
    int instantes = 10;
    int duracaoIntem = 5;
    int maxItem = 50;
    double precoVendaMercadorias = 10.0;
    double precoCompraMercadorias = 5.0;
    double precoCaravanas = 100.0;
    int instantesBarbaros = 5;
    int duracaoBarbaros = 3;
    Buffer buffer(10, 10);  // Passando as dimensões do buffer (10x10)

    // Agora crie o simulador passando os parâmetros
    Simulador simulador(moedasJogador, instantes, duracaoIntem, maxItem,
                        precoVendaMercadorias, precoCompraMercadorias,
                        precoCaravanas, instantesBarbaros, duracaoBarbaros, buffer);
    Caravana* caravana1 = new CaravanaComercio(1,1,1);
    Caravana* caravana2 = new CaravanaMilitar(1,1,1);
    Caravana* caravana3 = new CaravanaSecreta(1,1,1);

    simulador.adicionaCaravana(caravana1);
    simulador.adicionaCaravana(caravana2);
    simulador.adicionaCaravana(caravana3);

// Imprimindo os detalhes de todas as caravanas
    simulador.imprimirCaravanas();

    caravana1->exibirDetalhes();
    caravana2->exibirDetalhes();
    caravana3->exibirDetalhes();


    return 0;

    return 0;  // Fim do programa
}










