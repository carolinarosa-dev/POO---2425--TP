//
// Created by Carolina Rosa on 09/11/2024.
//

#include "Simulador.h"
#include "CaravanaBarbara.h"

/*
Simulador::Simulador(int linhas, int colunas, int moedasIniciais)
        : jogador(moedasIniciais), instantes(0), combatesVencidos(0) {}*/

//Simulador::Simulador(int linhas, int colunas, Buffer buffer) : deserto(linhas, colunas), jogador(100), buffer(buffer) {} // Inicializa o jogador com 100 moedas

/*

void Simulador::adicionaCaravanaJogador(char cidadeLetra, int tipoCaravanaNum, char tipoCaravanaChar) {
    Caravana::Tipo tipoCaravana;
    switch (tipoCaravanaChar) {
        case 'C':
            tipoCaravana = Caravana::COMERCIO;
            break;
        case 'M':
            tipoCaravana = Caravana::MILITAR;
            break;
        case 'S':
            tipoCaravana = Caravana::SECRETA;
            break;
        default:
            throw std::invalid_argument("Tipo de caravana inválido!");
    }

    auto it = std::find_if(cidades.begin(), cidades.end(), cidadeLetra {
            return cidade->getNome() == cidadeLetra;
    });

    if (it == cidades.end()) {
        throw std::invalid_argument("Cidade não encontrada!");
    }

   jogador.comprarCaravana(tipoCaravanaNum, tipoCaravana, 0, 0);
    (*it)->adicionarCaravana(jogador.getCaravanas().back());

    std::cout << "Caravana de número " << tipoCaravanaNum << " comprada na cidade " << cidadeLetra << "." << std::endl;
}
*/

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


void Simulador::adicionarCidade(std::shared_ptr<Cidade> cidade) {
    cidades.push_back(cidade);
}

void Simulador::provocarTempestade(int linhaCentro, int colunaCentro, int raio) {
    // Implementar lógica de tempestade de areia
}

void Simulador::moverCaravana(int idCaravana, int direcao) {
    // Implementar lógica de movimentação de caravanas
}

void Simulador::verificarCombate() {
    // Implementar lógica de verificação e resolução de combates
}

bool Simulador::terminarSimulacao() const {
    return jogador.getMoedas() <= 0 && !jogador.temCaravanas();
}




void Simulador::mostrarDescricaoCaravana(int idCaravana) const {
    for (const auto& caravana : jogador.getCaravanas()) {
        if (caravana->getId() == idCaravana) {
            cout << caravana->exibirDetalhes() << endl;
            return;
        }
    }
    cout << "Caravana com ID " << idCaravana << " não encontrada." << endl;
}



void Simulador::criarCaravanaBarbara(int linha, int coluna) {
    int id = caravanasBarbaras.size() + 1; // Gerar um ID único para a caravana
    auto novaCaravana = std::make_shared<CaravanaBarbara>(id, linha, coluna);
    caravanasBarbaras.push_back(novaCaravana);
    std::cout << "Caravana bárbara criada nas coordenadas (" << linha << ", " << coluna << ")." << std::endl;
}