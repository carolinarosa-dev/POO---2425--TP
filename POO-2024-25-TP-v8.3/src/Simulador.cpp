#include "../include/Simulador.h"
#include "../include/Caravanas/CaravanaBarbara.h"
#include "../include/Mapa/Cidade.h"
#include "../include/Jogador.h"
#include <sstream>


Simulador::Simulador(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    jogador = std::make_shared<Jogador>();  // Inicializa o jogador
    bufferAtual = new Buffer(linhas, colunas);
    mapa = new char*[linhas];
    for(int i = 0; i<linhas; i++){
        mapa[i] = new char[colunas];
    }
}

void Simulador::setFase(int fase) {
    this->fase = fase;
}

int Simulador::getFase()const {
    return 0;
}

bool Simulador::posicaoValida(int linha, int coluna, char** mapa) const{
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas && mapa[linha][coluna] != '+';
}

char Simulador::getCaractere(int l, int c) const{
    return mapa[l][c];
}
int Simulador::getLinhas() const {
    return linhas;
}

int Simulador::getColunas() const {
    return colunas;
}

void Simulador::setLinhaMapa(int l, int c, char linha){
    mapa[l][c] = linha;
}
void Simulador::adicionaCaravanaJogador(std::unique_ptr<Caravana> caravana) {
     jogador->adicionarCaravana(std::move(caravana));
}

void Simulador::adicionaCaravanaBarbara(std::unique_ptr<CaravanaBarbara> caravana) {
    caravanasBarbaras.push_back(std::move(caravana));
}

void Simulador::jogadorCompraCaravana(char cidadeLetra, char tipoCaravana, int precoCaravana) const {

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

    int i;
    for (i = 0; i < cidades.size(); i++) {
        if (cidades.at(i)->getNome() == cidadeLetra) {
            break;
        }
    }
    if (i == cidades.size()) {
        std::cout << "Cidade nao encontrada!" << std::endl;
    }
    if (cidades.at(i)->possuiCaravana(tipo)) {
        auto novaCaravana = cidades.at(i)->removerCaravanaDaCidadeParaJogador(tipo);
        jogador->comprarCaravana(std::move(novaCaravana), precoCaravana);  // Transfere a posse
    } else {
        std::cout << "Cidade " << cidadeLetra << "nao  pode adiciona mais caravana deste tipo." << std::endl;
    }
    std::cout << "Caravana de tipo " << tipoCaravana
        << " comprada na cidade " << cidadeLetra
        << " por " << precoCaravana << " moedas.\n";
}

void Simulador::adicionarCidade(std::unique_ptr<Cidade> cidade){
    if (!cidade) { // Verifica se o ponteiro é nulo
        std::cerr << "Erro: Tentativa de adicionar uma cidade nula.\n";
        return;
    }
    // Verifica se a cidade já existe no simulador
    for (const auto& c : cidades) {
        if (c && c->getNome() == cidade->getNome()) {  // Verifica se a cidade já foi adicionada
            std::cerr << "Cidade '" << cidade->getNome() << "' ja existe no simulador.\n";
            return;
        }
    }
    // Adiciona a nova cidade
    cidades.push_back(std::move(cidade));
}

std::shared_ptr<Jogador> Simulador::getJogador() {
    return jogador;
}

char** Simulador::getMapa() const{
    return mapa;
}

std::unique_ptr<Cidade> Simulador::encontrarCidade(char letraCidade) { // Adicione "Simulador::"
//    for (auto& cidade : cidades) { // Agora o compilador reconhece "cidades"
//        if (cidade->getNome() == letraCidade) { // Corrija "getLetra" para "getNome", se necessário
//            return std::make_unique<Cidade>(*cidade);
//        }
//    }
    return nullptr;
}

void Simulador::imprimeMapa() const{
    for(int i =0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            std::cout << mapa[i][j];
        }
        std::cout << std::endl;
    }
}


void Simulador::comprarMercadoria(int idCaravana, int quantidadeMercadoria, int precoCompraMercadoria) {
        auto& caravanas = jogador->getCaravanas();
        std::unique_ptr<Caravana> *caravanaEncontrada = nullptr;
        for (auto& caravana : caravanas) {
            if (caravana->getId() == idCaravana) {
                caravanaEncontrada = &caravana;
                break;
            }
        }
        if (caravanaEncontrada == nullptr) {
            throw std::runtime_error("Caravana com ID nao encontrada.");
        }
        if (!(*caravanaEncontrada)->estaEmCidade()) {
            throw std::runtime_error("A caravana nao esta em uma cidade.");
        }

        int custoTotal = quantidadeMercadoria * precoCompraMercadoria;

        if (jogador->getMoedas() < custoTotal) {
            throw std::runtime_error("Moedas insuficientes para comprar mercadorias.");
        }

        if ((*caravanaEncontrada)->getCarga() + quantidadeMercadoria > (*caravanaEncontrada)->getCapacidadeCarga()) {
            throw std::runtime_error("Capacidade de carga da caravana excedida.");
        }

        jogador->adicionarMoedas(-custoTotal);
        (*caravanaEncontrada)->adicionarCarga(quantidadeMercadoria);

        std::cout << "Compradas " << quantidadeMercadoria << " toneladas de mercadorias para a caravana " << idCaravana << "." << std::endl;
}

void Simulador::venderMercadoria(int idCaravana, int precoVendaMercadoria) {
        auto& caravanas = jogador->getCaravanas();

        std::unique_ptr<Caravana>* caravanaEncontrada = nullptr;
        for (auto& caravana : caravanas) {
            if (caravana->getId() == idCaravana) {
                caravanaEncontrada = &caravana;
                break;
            }
        }
        if (caravanaEncontrada == nullptr) {
            throw std::runtime_error("Caravana com ID nao encontrada.");
        }
        if (!(*caravanaEncontrada)->estaEmCidade()) {
            throw std::runtime_error("A caravana nao esta em uma cidade.");
        }

        int quantidadeMercadoria = (*caravanaEncontrada)->getCarga();

        int valorVenda = quantidadeMercadoria * precoVendaMercadoria;

        jogador->adicionarMoedas(valorVenda);

        (*caravanaEncontrada)->removerCarga(quantidadeMercadoria);

        std::cout << "Toda a mercadoria da caravana " << idCaravana << " foi vendida por " << valorVenda << " moedas." << std::endl;

}

void Simulador::moverCaravana(int idCaravana, const std::string &direcao, char** mapa) {
    auto& caravanas = jogador->getCaravanas();
    Caravana* caravanaEncontrada = nullptr;

    for (auto& caravana : caravanas) {
        if (caravana->getId() == idCaravana) {
            caravanaEncontrada = &(*caravana);
            break;
        }
    }

    if (caravanaEncontrada) {
        int linhaAtual, colunaAtual;
        // Atribuindo a posição atual da caravana
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
        else throw std::invalid_argument("Direção inválida.");

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
                throw std::invalid_argument("Direção inválida.");
        }

        // Verificar se a nova posição é válida
        if (posicaoValida(novaLinha, novaColuna, mapa)) {
            // Atualizar a posição da caravana
            caravanaEncontrada->setPosicao(novaLinha, novaColuna);
        } else {
            throw std::runtime_error("Movimento inválido! A posição está ocupada ou fora dos limites.");
        }
    } else {
        throw std::runtime_error("Caravana com ID não encontrada.");
    }
}

Simulador::~Simulador() {
    for (int i = 0; i < linhas; i++) {
        delete[] mapa[i];
    }
    delete[] mapa;
}


/*
void Simulador::atualizaMapa() {
    int linha, coluna, linhaAnt, colunaAnt;
     for(auto &c : simulador->getJogador()->getCaravanas()){
         std::tie(linha, coluna) = c->getPosicao();
         std::tie(linhaAnt, colunaAnt) = c->getPosicaoAnterior();
         if(mapa[linha][coluna]+'0' != c->getId()){
             mapa[linhaAnt][colunaAnt] = '.';
             mapa[linha][coluna] = static_cast<char>(c->getId()+'0');
         }
     }
}
*/
