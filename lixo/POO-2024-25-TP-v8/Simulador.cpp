
#include "Simulador.h"

bool Simulador::terminarSimulacao() const {
    //return jogador->getMoedas() <= 0 && !jogador->temCaravanas();
//    return jogador.getMoedas() <= 0 && !jogador.temCaravanas();
    return false;
}
std::vector<std::string>& Simulador::getMapaFicheiro(){
    return mapaFicheiro;
}

std::map<std::string, int>& Simulador :: getAtributosConfiguraveis() {
    return atributosConfiguraveis;
}
void Simulador::setInstantesEntreNovosItens(int instantesEntreNovosItens) {
    this->instantesEntreNovosItens = instantesEntreNovosItens;
}

void Simulador::setDuracaoItem(int duracaoItem) {
    this->duracaoItem = duracaoItem;
}

void Simulador::setMaxItens(int maxItens) {
    this->maxItens = maxItens;
}

void Simulador::setPrecoVendaMercadoria(int precoVendaMercadoria) {
    this->precoVendaMercadoria = precoVendaMercadoria;
}

void Simulador::setPrecoCompraMercadoria(int precoCompraMercadoria) {
    this->precoCompraMercadoria = precoCompraMercadoria;
}

void Simulador::setPrecoCaravana(int precoCaravana) {
    this->precoCaravana = precoCaravana;
}

void Simulador::setInstantesEntreNovosBarbaros(int instantesEntreNovosBarbaros) {
    this->instantesEntreNovosBarbaros = instantesEntreNovosBarbaros;
}

void Simulador::setDuracaoBarbaros(int duracaoBarbaros) {
    this->duracaoBarbaros = duracaoBarbaros;
}


//int Simulador::getInstantesEntreNovosItens() const {
//    return instantesEntreNovosItens;
//}
//
//int Simulador::getDuracaoItem() const {
//    return duracaoItem;
//}
//
//int Simulador::getMaxItens() const {
//    return maxItens;
//}
//
//int Simulador::getPrecoVendaMercadoria() const {
//    return precoVendaMercadoria;
//}
//
//int Simulador::getPrecoCompraMercadoria() const {
//    return precoCompraMercadoria;
//}
//
//int Simulador::getPrecoCaravana() const {
//    return precoCaravana;
//}
//
//int Simulador::getInstantesEntreNovosBarbaros() const {
//    return instantesEntreNovosBarbaros;
//}
//
//int Simulador::getDuracaoBarbaros() const {
//    return duracaoBarbaros;
//}
//deserto
void Simulador::adicionarMontanha(double latitude, double longitude)  {
//    montanhas.push_back(Montanha(latitude, longitude));
}

//cidade
std::string Simulador::adicionarCidade(std::shared_ptr <Cidade> cidade) const{
    std::ostringstream oss;
//    if (!cidade) { // Verifica se o ponteiro é nulo
//        oss << "Erro: Tentativa de adicionar uma cidade nula.\n";
       return oss.str();
//    }
//    // Verifica se a cidade já existe no simulador
//    for (const auto& c : cidades) {
//        if (c && c->getNome() == cidade->getNome()) {  // Verifica se a cidade já foi adicionada
//            oss << "Cidade '" << cidade->getNome() << "' ja existe no simulador.\n";
//            return oss.str();
//        }
//    }
//    // Adiciona a nova cidade
//    cidades.push_back(cidade);
}

//const std::vector <Cidade><std::shared_ptr> &Simulador::getCidades() const {
//    //return <initializer>;
//}

void Simulador::listarCaravanasNaCidade(char cidadeLetra) const {

}

//Caravanas
std::string Simulador::criarCaravanaBarbara(int linha, int coluna) const{
    std::ostringstream oss;
//    int id = caravanasBarbaras.size() + 1; // Gerar um ID único para a caravana
//    auto novaCaravana = std::make_shared<CaravanaBarbara>(id,linha, coluna);
//    caravanasBarbaras.push_back(novaCaravana);
//    oss << "Caravana barbara criada nas coordenadas (" << linha << ", " << coluna << ")." << std::endl;
    return oss.str();
}
//adiciona as caravanas que sao carragedas no ficheiro ao jogador
void Simulador::adicionaCaravanaJogador(std::shared_ptr<Caravana> caravana) {
    //if (jogador->getCaravanas().size() >= 9) {
//    if (jogador.getCaravanas().size() >= 9) {
//        throw std::runtime_error("Numero maximo de caravanas atingido.");
//    }
    //jogador->adicionarCaravanaJogador(caravana);
//    jogador.adicionarCaravanaJogador(std::move(caravana));
}

int Simulador::getPrecoComprac() const {
    return precoComprac;
}

void Simulador::setPrecoComprac(int precoComprac) {
   this->precoComprac = precoComprac;
}

std::string Simulador::jogadorCompraCaravana(char cidadeLetra, char tipoCaravana, int precoCaravana) const{
    Caravana::Tipo tipo;
    std::ostringstream oss;
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
//    for (const auto &cidade: cidades) {
//        if (cidade->getNome() == cidadeLetra) {
//            cidadeEscolhida = cidade;
//            break;
//        }
//    }
    if (!cidadeEscolhida) {
        throw std::invalid_argument("Cidade nao encontrada!");
    }
//    if (cidadeEscolhida->possuiCaravana(tipo)) {
//        auto novaCaravana = cidadeEscolhida->removerCaravana(tipo);
//        jogador->comprarCaravana(novaCaravana, precoCaravana);
//        //cidadeEscolhida->adicionarCaravana(novaCaravana);
//        novaCaravana->setEmCidade(true);
//        oss << "Jogador comprou uma caravana na cidade: \n"
//            << "Letra: " <<cidadeLetra
//            << "ID: " << novaCaravana->getId()
//            << "Tipo de caravarna: " << tipoCaravana
//            << std::endl;
//    }else {
//        oss << "Cidade " << cidadeLetra << "nao  pode adiciona mais nenhuma caravana deste tipo." << std::endl;
//    }
    return oss.str();
}

void Simulador::adicionaCaravanaBarbara(std::shared_ptr<CaravanaBarbara> caravana) {
//    caravanasBarbaras.push_back(caravana);
}

void Simulador::mostrarDescricaoCaravana(int idCaravana) const {

}

void Simulador::moverCaravana(int idCaravana, const std::string &direcao, char **mapa) {
    //auto caravanas = jogador->getCaravanas();
//    auto caravanas = jogador.getCaravanas();
    std::shared_ptr<Caravana> caravanaEncontrada = nullptr;

//    for (const auto& caravana : caravanas) {
//        if (caravana->getId() == idCaravana) {
//            caravanaEncontrada = caravana;
//            break;
//        }
//    }
    if (caravanaEncontrada) {
        int linhaAtual, colunaAtual;
//        std::tie(linhaAtual, colunaAtual) = caravanaEncontrada->getPosicao();
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

//        switch (direcaoNumerica) {
//            case 0: novaLinha = (linhaAtual - 1 + utils.posCaravana.first) %  utils.posCaravana.first; break; // Cima
//            case 1: novaLinha = (linhaAtual + 1) %  utils.posCaravana.first; break; // Baixo
//            case 2: novaColuna = (colunaAtual - 1 + utils.posCaravana.second) % utils.posCaravana.second; break; // Esquerda
//            case 3: novaColuna = (colunaAtual + 1) % utils.posCaravana.second; break; // Direita
//            case 4: // Diagonal Cima-Esquerda
//                novaLinha = (linhaAtual - 1 +  utils.posCaravana.first) %  utils.posCaravana.first;
//                novaColuna = (colunaAtual - 1 + utils.posCaravana.second) % utils.posCaravana.second;
//                break;
//            case 5: // Diagonal Cima-Direita
//                novaLinha = (linhaAtual - 1 +  utils.posCaravana.first) %  utils.posCaravana.first;
//                novaColuna = (colunaAtual + 1) % utils.posCaravana.second;
//                break;
//            case 6: // Diagonal Baixo-Esquerda
//                novaLinha = (linhaAtual + 1) % utils.posCaravana.first;
//                novaColuna = (colunaAtual - 1 + utils.posCaravana.second) % utils.posCaravana.second;
//                break;
//            case 7: // Diagonal Baixo-Direita
//                novaLinha = (linhaAtual + 1) % utils.posCaravana.first;
//                novaColuna = (colunaAtual + 1) % utils.posCaravana.second;
//                break;
//            default:
//                throw std::invalid_argument("Direcao invalida.");
//        }
//        // Verificar se a nova posição é válida
//        if (utils.posicaoValida(novaLinha, novaColuna, mapa)) {
//            // Atualizar a posição da caravana
//            caravanaEncontrada->setPosicao(novaLinha, novaColuna);
//        } else {
//            throw std::runtime_error("Movimento invalido! A posicao esta ocupada ou fora dos limites.");
//        }
//    } else {
//        throw std::runtime_error("Caravana com ID nao encontrada.");
   }
}

void Simulador::ativarAutoGestao(int idCaravana) {
//    auto caravanas = jogador->getCaravanas();
//    auto caravanas = jogador.getCaravanas();
    std::shared_ptr<Caravana> caravanaEncontrada = nullptr;

//    for (const auto& caravana : caravanas) {
//        if (caravana->getId() == idCaravana) {
//            caravanaEncontrada = caravana;
//            break;
//        }
//    }
    if (caravanaEncontrada) {
//        caravanaEncontrada->setAutoGestao(true);
    } else {
        throw std::runtime_error("Caravana com ID nao encontrada.");
    }
}

void Simulador::desativarAutoGestao(int idCaravana) {
//    auto caravanas = jogador->getCaravanas();
//    auto caravanas = jogador.getCaravanas();
    std::shared_ptr<Caravana> caravanaEncontrada = nullptr;

//    for (const auto& caravana : caravanas) {
//        if (caravana->getId() == idCaravana) {
//            caravanaEncontrada = caravana;
//            break;
//        }
//    }
    if (caravanaEncontrada) {
//        caravanaEncontrada->setAutoGestao(false);
    } else {
        throw std::runtime_error("Caravana com ID nao encontrada.");
    }
}

//compra e venda de mercadorias
void Simulador::comprarMercadoria(int idCaravana, int quantidadeMercadoria, int precoCompraMercadoria) {
//    auto caravanas = jogador->getCaravanas();
//    auto caravanas = jogador.getCaravanas();
    std::shared_ptr<Caravana> caravanaEncontrada = nullptr;
//    for (const auto& caravana : caravanas) {
//        if (caravana->getId() == idCaravana) {
//            caravanaEncontrada = caravana;
//            break;
//        }
//    }
    if (caravanaEncontrada) {
//        if (caravanaEncontrada->estaEmCidade()) {
//            int custoTotal = quantidadeMercadoria * precoCompraMercadoria;
//            //if (jogador->getMoedas() >= custoTotal) {
//            if (jogador.getMoedas() >= custoTotal) {
//                if (caravanaEncontrada->getCarga() + quantidadeMercadoria <= caravanaEncontrada->getCapacidadeCarga()) {
////                    jogador->adicionarMoedas(-custoTotal);
//                    jogador.adicionarMoedas(-custoTotal);
//                    caravanaEncontrada->adicionarCarga(quantidadeMercadoria);
//                    std::cout << "Compradas " << quantidadeMercadoria << " toneladas de mercadorias para a caravana " << idCaravana << "." << std::endl;
//                } else {
//                    throw std::runtime_error("Capacidade de carga da caravana excedida.");
//                }
//            } else {
//                throw std::runtime_error("Moedas insuficientes para comprar mercadorias.");
//            }
//        } else {
//            throw std::runtime_error("A caravana nao esta em uma cidade.");
//        }
    } else {
        throw std::runtime_error("Caravana com ID nao encontrada.");
    }
}


void Simulador::venderMercadoria(int idCaravana, int precoVendaMercadoria) {
//    auto caravanas = jogador->getCaravanas();
//    auto caravanas = jogador.getCaravanas();
    std::shared_ptr<Caravana> caravanaEncontrada = nullptr;

//    for (const auto& caravana : caravanas) {
//        if (caravana->getId() == idCaravana) {
//            caravanaEncontrada = caravana;
//            break;
//        }
//    }
    if (caravanaEncontrada) {
//        if (caravanaEncontrada->estaEmCidade()) {
//            int quantidadeMercadoria = caravanaEncontrada->getCarga();
//            int valorVenda = quantidadeMercadoria * precoVendaMercadoria;
//            //jogador->adicionarMoedas(valorVenda);
//            jogador.adicionarMoedas(valorVenda);
//
//            caravanaEncontrada->removerCarga(quantidadeMercadoria);
//            std::cout << "Vendida toda a mercadoria da caravana " << idCaravana << " por " << valorVenda << " moedas." << std::endl;
//        } else {
//            throw std::runtime_error("A caravana nao esta em uma cidade.");
//        }
    } else {
        throw std::runtime_error("Caravana com ID nao encontrada.");
    }
}








