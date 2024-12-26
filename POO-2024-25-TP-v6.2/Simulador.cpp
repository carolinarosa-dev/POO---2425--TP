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
    : linhas(linhas), colunas(colunas), jogador(std::make_shared<Jogador>(0)), buffer(buffer) {
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
            throw std::invalid_argument("Tipo invalido de caravana!");
    }
    std::shared_ptr<Cidade> cidadeEscolhida = nullptr;
    for (const auto &cidade: cidades) {
        if (cidade->getNome() == cidadeLetra) {
            cidadeEscolhida = cidade;
            break;
        }
    }
    if (!cidadeEscolhida) {
        throw std::invalid_argument("Cidade nao encontrada!");
    }
    if (cidadeEscolhida->possuiCaravana(tipo)) {
        auto novaCaravana = cidadeEscolhida->removerCaravana(tipo);
        jogador->comprarCaravana(novaCaravana, precoCaravana);
        //cidadeEscolhida->adicionarCaravana(novaCaravana);
        novaCaravana->setEmCidade(true);
        std::cout << "Caravana de tipo " << tipoCaravana << " e ID: " << novaCaravana->getId() << " comprada na cidade "
                  << cidadeLetra << "." << std::endl;
    } else {
        std::cout << "Cidade " << cidadeLetra << "nao  pode adiciona mais caravana deste tipo." << std::endl;
    }
}

void Simulador::adicionaCaravanaJogador(std::shared_ptr<Caravana> caravana) {
    if (jogador->getCaravanas().size() >= 9) {
        throw std::runtime_error("Numero maximo de caravanas atingido.");
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
    //lógica de verificação e resolução de combates
        for (auto& caravana : caravanasJogador) {
            for (auto& caravanaBarbara : caravanasBarbaras) {
                if (caravana->estaAdjacente(*caravanaBarbara)) {
                    caravana->combater(*caravanaBarbara);

                    if (caravana->tripulantes <= 0) {
                        // Lidar com a destruição da caravana do jogador
                        caravanaBarbara->transferirAgua(*caravana);
                        // Remove a destruiçao da caravana do jogador da lista
                        caravanasJogador.erase(std::remove(caravanasJogador.begin(), caravanasJogador.end(), caravana), caravanasJogador.end());
                        break; // Exit the loop as the caravan is destroyed
                    }

                    if (caravanaBarbara->tripulantes <= 0) {
                        // Lidar com a destruição da caravana bárbara
                        caravana->transferirAgua(*caravanaBarbara);
                        // Remove a destruiçao da caravana barbara da lista
                        caravanasBarbaras.erase(std::remove(caravanasBarbaras.begin(), caravanasBarbaras.end(), caravanaBarbara), caravanasBarbaras.end());
                    }
                }
            }
        }
    }


bool Simulador::terminarSimulacao() const {
    return jogador->getMoedas() <= 0 && !jogador->temCaravanas();
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

void Simulador::criarCaravanaBarbara(int linha, int coluna) {
    int id = caravanasBarbaras.size() + 1; // Gerar um ID único para a caravana
    auto novaCaravana = std::make_shared<CaravanaBarbara>(id,linha, coluna);
    caravanasBarbaras.push_back(novaCaravana);
    std::cout << "Caravana barbara criada nas coordenadas (" << linha << ", " << coluna << ")." << std::endl;
}

const vector<shared_ptr<Cidade>> &Simulador::getCidades() const {
    return cidades;
}

void Simulador::comprarMercadoria(int idCaravana, int quantidadeMercadoria, int precoCompraMercadoria){

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

void Simulador::venderMercadoria(int idCaravana, int precoVendaMercadoria) {

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

bool Simulador::posicaoValida(int linha, int coluna, char** mapa) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas && mapa[linha][coluna] != '+';
}

void Simulador::moverCaravana(int idCaravana, const std::string &direcao, char** mapa) {
    auto caravanas = jogador->getCaravanas();
    std::shared_ptr<Caravana> caravanaEncontrada = nullptr;

    for (const auto& caravana : caravanas) {
        if (caravana->getId() == idCaravana) {
            caravanaEncontrada = caravana;
            break;
        }
    }
    if (caravanaEncontrada) {
    int linhaAtual, colunaAtual;
    std::tie(linhaAtual, colunaAtual) = caravanaEncontrada->getPosicao();
    int novaLinha = linhaAtual, novaColuna = colunaAtual;
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

        switch (direcaoNumerica) {
            case 0: novaLinha = (linhaAtual - 1 + linhas) % linhas; break; // Cima
            case 1: novaLinha = (linhaAtual + 1) % linhas; break; // Baixo
            case 2: novaColuna = (colunaAtual - 1 + colunas) % colunas; break; // Esquerda
            case 3: novaColuna = (colunaAtual + 1) % colunas; break; // Direita
            case 4: // Diagonal Cima-Esquerda
                novaLinha = (linhaAtual - 1 + linhas) % linhas;
                novaColuna = (colunaAtual - 1 + colunas) % colunas;
                break;
            case 5: // Diagonal Cima-Direita
                novaLinha = (linhaAtual - 1 + linhas) % linhas;
                novaColuna = (colunaAtual + 1) % colunas;
                break;
            case 6: // Diagonal Baixo-Esquerda
                novaLinha = (linhaAtual + 1) % linhas;
                novaColuna = (colunaAtual - 1 + colunas) % colunas;
                break;
            case 7: // Diagonal Baixo-Direita
                novaLinha = (linhaAtual + 1) % linhas;
                novaColuna = (colunaAtual + 1) % colunas;
                break;
            default:
                throw invalid_argument("Direcao invalida.");
        }
        // Verificar se a nova posição é válida
        if (posicaoValida(novaLinha, novaColuna, mapa)) {
            // Atualizar a posição da caravana
            caravanaEncontrada->setPosicao(novaLinha, novaColuna);
        } else {
            throw runtime_error("Movimento invalido! A posicao esta ocupada ou fora dos limites.");
        }
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