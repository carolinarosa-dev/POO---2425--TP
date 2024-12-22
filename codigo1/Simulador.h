#include "Buffer.h"
#include "Comandos.h"

//#include "Caravana.h"
class Caravana;
class Deserto;
class Cidade;
class CaravanaBarbara;
class Jogador;

class Simulador {
public:
    void provocarTempestade(int linhaCentro, int colunaCentro, int raio);
    void verificarCombate();
    std::shared_ptr<Jogador> getJogador();
   // Jogador& getJogador();
    // Funções principais
    void executarComando(const std::string& comando); // Executa um comando

    std::shared_ptr<Caravana> getCaravana(int id);
    // Funções auxiliares
    void imprimirEstado() const;

private:
    int instantes;                  // Número de instantes decorridos

    Deserto *deserto;               // Mapa do deserto - aloca o mapa e o local da referencia na memoria
    vector<shared_ptr<Cidade>> cidades;//DONO
    vector<shared_ptr<CaravanaBarbara>> caravanasBarbaras;
    Buffer *buffer;                  // Buffer para output
    //Jogador jogador;
    std::shared_ptr<Jogador> jogador;
    vector<std::shared_ptr<Caravana>> caravanas; // Declaração da variável caravanas
    //Comandos comandos;
};
#endif //POO_2024_25_TP_SIMULADOR_H

//
// Created by Carolina Rosa on 09/11/2024.
//

#include "Simulador.h"
#include "Caravana.h"
#include "CaravanaBarbara.h"
#include "Cidade.h"
#include "Jogador.h"
#include "Deserto.h"

/*
void Simulador::listarCaravanas(char cidadeLetra) const {
    auto it = std::find_if(cidades.begin(), cidades.end(), cidadeLetra {
            return cidade->getNome() == cidadeLetra;
    });

    if (it != cidades.end()) {
        std::cout << (*it)->listarCaravanas();
    } else {
        std::cout << "Cidade " << cidadeLetra << " não encontrada." << std::endl;
    }
}
*/

void Simulador::provocarTempestade(int linhaCentro, int colunaCentro, int raio) {
    deserto->provocarTempestade(linhaCentro, colunaCentro, raio);
}

void Simulador::verificarCombate() {
    // Implementar lógica de verificação e resolução de combates
}

std::shared_ptr<Jogador> Simulador::getJogador() {
    return jogador;
}

std::shared_ptr<Caravana> Simulador::getCaravana(int id){
    for (const auto& caravana : jogador->getCaravanas()) {
        if (caravana->getId() == id){
            return caravana;
        }
    }
    return nullptr;
}

void Simulador::mostrarDescricaoCaravana(int idCaravana) const {
    for (const auto& caravana : jogador->getCaravanas()) {
        if (caravana->getId() == idCaravana) {
            cout << caravana->exibirDetalhes() << endl;
            return;
        }
    }
    cout << "Caravana com ID " << idCaravana << " nao encontrada." << endl;
}

const vector<shared_ptr<Cidade>> &Simulador::getCidades() const {
    return cidades;
}

bool Simulador::posicaoValida(int linha, int coluna, char** mapa) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas && mapa[linha][coluna] != '+';
}
