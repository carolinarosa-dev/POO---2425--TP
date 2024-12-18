//
// Created by Carolina Rosa on 09/11/2024.
//

#include "Simulador.h"
#include "Caravana.h"
#include "CaravanaBarbara.h"
#include "Cidade.h"
#include "Jogador.h"
#include "Deserto.h"

Simulador::Simulador(int linhas, int colunas, Buffer *buffer)
   /*     : jogador(0), buffer(buffer) {
    this->deserto = new Deserto(linhas, colunas);*/
    : jogador(std::make_shared<Jogador>(100)), buffer(buffer) {
        this->deserto = new Deserto(linhas, colunas);
    }
 // Inicializa o jogador com 100 moedas

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
    for (const auto &cidade: cidades) {
        if (cidade->getNome() == cidadeLetra) {
            cidadeEscolhida = cidade;
            break;
        }
    }
    if (!cidadeEscolhida) {
        throw std::invalid_argument("Cidade não encontrada!");
    }
    if (cidadeEscolhida->possuiCaravana(tipo)) {
        auto novaCaravana = cidadeEscolhida->removerCaravana(tipo);
        jogador->comprarCaravana(novaCaravana, precoCaravana);
        //cidadeEscolhida->adicionarCaravana(novaCaravana);

        std::cout << "Caravana de tipo " << tipoCaravana << "e ID: " << novaCaravana->getId() << " comprada na cidade "
                  << cidadeLetra << "." << std::endl;
    } else {
        std::cout << "Cidade " << cidadeLetra << "não mais possui caravana deste tipo." << std::endl;
    }
}

void Simulador::adicionaCaravanaJogador(std::shared_ptr<Caravana> caravana) {
    if (jogador->getCaravanas().size() >= 9) {
        throw std::runtime_error("Número máximo de caravanas atingido.");
    }
    jogador->adicionarCaravana(caravana);

}
void Simulador::adicionaCaravanaBarbara(std::shared_ptr<CaravanaBarbara> caravana) {
    caravanasBarbaras.push_back(caravana);
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
            cerr << "Cidade '" << cidade->getNome() << "' ja existe no simulador.\n";
            return;
        }
    }
    // Adiciona a nova cidade
    cidades.push_back(cidade);
}

void Simulador::provocarTempestade(int linhaCentro, int colunaCentro, int raio) {
    deserto->provocarTempestade(linhaCentro, colunaCentro, raio);
}

void Simulador::moverCaravana(int idCaravana, int direcao) {
    // Implementar lógica de movimentação de caravanas
}

void Simulador::verificarCombate() {
    // Implementar lógica de verificação e resolução de combates
}

bool Simulador::terminarSimulacao() const {
    return jogador->getMoedas() <= 0 && !jogador->temCaravanas();
}

/*Jogador& Simulador::getJogador(){
    return jogador;
}*/

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

void Simulador::criarCaravanaBarbara(int linha, int coluna) {
    int id = caravanasBarbaras.size() + 1; // Gerar um ID único para a caravana
    auto novaCaravana = std::make_shared<CaravanaBarbara>(id,linha, coluna);
    caravanasBarbaras.push_back(novaCaravana);
    std::cout << "Caravana barbara criada nas coordenadas (" << linha << ", " << coluna << ")." << std::endl;
}

const vector<shared_ptr<Cidade>> &Simulador::getCidades() const {
    return cidades;
}

void Simulador::comprarMercadoria(int idCaravana, int quantidadeMercadoria) {
    auto caravanas = jogador->getCaravanas();
    std::shared_ptr<Caravana> caravanaEncontrada = nullptr;

    for (const auto& caravana : caravanas) {
        if (caravana->getId() == idCaravana) {
            caravanaEncontrada = caravana;
            break;
        }
    }

    if (caravanaEncontrada) {
        if (caravanaEncontrada->estaEmCidade()) {
            int custoTotal = quantidadeMercadoria * precoCompraMercadoria;
            if (jogador->getMoedas() >= custoTotal) {
                if (caravanaEncontrada->getCarga() + quantidadeMercadoria <= caravanaEncontrada->getCapacidadeCarga()) {
                    jogador->adicionarMoedas(-custoTotal);
                    caravanaEncontrada->adicionarCarga(quantidadeMercadoria);
                    std::cout << "Compradas " << quantidadeMercadoria << " toneladas de mercadorias para a caravana " << idCaravana << "." << std::endl;
                } else {
                    throw std::runtime_error("Capacidade de carga da caravana excedida.");
                }
            } else {
                throw std::runtime_error("Moedas insuficientes para comprar mercadorias.");
            }
        } else {
            throw std::runtime_error("A caravana nao esta em uma cidade.");
        }
    } else {
        throw std::runtime_error("Caravana com ID nao encontrada.");
    }
}

void Simulador::venderMercadoria(int idCaravana) {
    auto caravanas = jogador->getCaravanas();
    std::shared_ptr<Caravana> caravanaEncontrada = nullptr;

    for (const auto& caravana : caravanas) {
        if (caravana->getId() == idCaravana) {
            caravanaEncontrada = caravana;
            break;
        }
    }

    if (caravanaEncontrada) {
        if (caravanaEncontrada->estaEmCidade()) {
            int quantidadeMercadoria = caravanaEncontrada->getCarga();
            int valorVenda = quantidadeMercadoria * precoVendaMercadoria;
            jogador->adicionarMoedas(valorVenda);
            caravanaEncontrada->removerCarga(quantidadeMercadoria);
            std::cout << "Vendida toda a mercadoria da caravana " << idCaravana << " por " << valorVenda << " moedas." << std::endl;
        } else {
            throw std::runtime_error("A caravana nao esta em uma cidade.");
        }
    } else {
        throw std::runtime_error("Caravana com ID nao encontrada.");
    }
}

void Simulador::moverCaravana(int idCaravana, const std::string &direcao) {
    auto caravanas = jogador->getCaravanas();
    std::shared_ptr<Caravana> caravanaEncontrada = nullptr;

    for (const auto& caravana : caravanas) {
        if (caravana->getId() == idCaravana) {
            caravanaEncontrada = caravana;
            break;
        }
    }
    if (caravanaEncontrada) {
        int direcaoNumerica;
        if (direcao == "D") direcaoNumerica = 3;
        else if (direcao == "E") direcaoNumerica = 2;
        else if (direcao == "C") direcaoNumerica = 0;
        else if (direcao == "B") direcaoNumerica = 1;
        else if (direcao == "CE") direcaoNumerica = 4;
        else if (direcao == "CD") direcaoNumerica = 5;
        else if (direcao == "BE") direcaoNumerica = 6;
        else if (direcao == "BD") direcaoNumerica = 7;
        else throw std::invalid_argument("Direçao invalida.");

        deserto->moverCaravana(caravanaEncontrada, direcaoNumerica);
    } else {
        throw std::runtime_error("Caravana com ID nao encontrada.");
    }
}
void Simulador::ativarAutoGestao(int idCaravana) {
    auto caravanas = jogador->getCaravanas();
    std::shared_ptr<Caravana> caravanaEncontrada = nullptr;

    for (const auto& caravana : caravanas) {
        if (caravana->getId() == idCaravana) {
            caravanaEncontrada = caravana;
            break;
        }
    }
    if (caravanaEncontrada) {
        caravanaEncontrada->setAutoGestao(true);
    } else {
        throw std::runtime_error("Caravana com ID nao encontrada.");
    }
}

void Simulador::desativarAutoGestao(int idCaravana) {
    auto caravanas = jogador->getCaravanas();
    std::shared_ptr<Caravana> caravanaEncontrada = nullptr;

    for (const auto& caravana : caravanas) {
        if (caravana->getId() == idCaravana) {
            caravanaEncontrada = caravana;
            break;
        }
    }
    if (caravanaEncontrada) {
        caravanaEncontrada->setAutoGestao(false);
    } else {
        throw std::runtime_error("Caravana com ID nao encontrada.");
    }
}

Simulador::~Simulador(){}