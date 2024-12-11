//
// Created by Carolina Rosa on 09/11/2024.
//

#include "Simulador.h"
#include "Caravana.h"
#include "CaravanaBarbara.h"
#include "Cidade.h"
#include "Jogador.h"
#include "Deserto.h"



//Simulador::Simulador(int linhas, int colunas, int moedasIniciais)
//        : jogador(moedasIniciais), instantes(0), combatesVencidos(0) {
//    cidades = make_shared<Cidade>();
//
//}

Simulador::Simulador(int linhas, int colunas, Buffer *buffer)
    : jogador(0), buffer(buffer) {
    this->deserto = new Deserto(linhas, colunas);

} // Inicializa o jogador com 100 moedas



void Simulador::adicionaCaravanaJogador(char cidadeLetra, char tipoCaravana, int precoCaravana) {
    Caravana::Tipo tipo;
    switch (tipoCaravana) {
        case 'C':
            tipo = Caravana::COMERCIO;
            break;
        case 'M':
            tipo = Caravana::MILITAR;
            break;
        case 'S':
            tipo = Caravana::SECRETA;
            break;
        default:
            throw std::invalid_argument("Tipo inválido de caravana!");
    }

    std::shared_ptr<Cidade> cidadeEscolhida = nullptr;
    for (const auto& cidade : cidades) {
        if (cidade->getNome() == cidadeLetra) {
            cidadeEscolhida = cidade;
            break;
        }
    }

    if (!cidadeEscolhida) {
        throw std::invalid_argument("Cidade não encontrada!");
    }

   auto novaCaravana = jogador.comprarCaravana(tipoCaravana, tipo, 0, 0, precoCaravana);
   cidadeEscolhida->adicionarCaravana(novaCaravana);

    std::cout << "Caravana de número " << tipoCaravana << " comprada na cidade " << cidadeLetra << "." << std::endl;
}
void Simulador::adicionaCaravanaBarbara(char caractere, int linha, int coluna) {
    cout << "adicionaCaravanaBarbara";
}

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
    if (!cidade) { // Verifica se o ponteiro é nulo
        cerr << "Erro: Tentativa de adicionar uma cidade nula.\n";
        return;
    }

    // Verifica se a cidade já existe no simulador

    for (const auto& c : cidades) {
        if (c && c->getNome() == cidade->getNome()) {  // Verifica se a cidade já foi adicionada
            cerr << "Cidade '" << cidade->getNome() << "' já existe no simulador.\n";
            return;
        }
    }


    // Adiciona a nova cidade
    cidades.push_back(cidade);
    cout << "REMOVER      Cidade '" << cidade->getNome() << "' adicionada na posição ("
              << cidade->getLinha() << ", " << cidade->getColuna() << ").\n";

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

Jogador& Simulador::getJogador(){
    return jogador;
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

const vector<shared_ptr<Cidade>> &Simulador::getCidades() const {
    return cidades;
}
