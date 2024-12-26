
#include "../include/Simulador.h"

#include "Mapa/Cidade.h"
#include "Jogador.h"
#include <sstream>


Simulador::Simulador() {
    jogador = std::make_shared<Jogador>();  // Inicializa o jogador
}

void Simulador::setFase(int fase) {
    this->fase = fase;
}

int Simulador::getFase()const {
    return 0;
}

std::string Simulador::jogadorCompraCaravana(char cidadeLetra, char tipoCaravana, int precoCaravana) const {
    std::ostringstream oss;
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

    Cidade* cidadeEscolhida = nullptr;
    int i;
    for (i = 0; i < cidades.size(); i++) {
        if (cidades.at(i)->getNome() == cidadeLetra) {
            break;
        }
    }
    std::cout << cidades.at(i)->getNome();
    if (i == cidades.size()) {
        throw std::invalid_argument("Cidade nao encontrada!");
    }
    if (cidades.at(i)->possuiCaravana(tipo)) {
        auto novaCaravana = cidades.at(i)->removerCaravanaDaCidadeParaJogador(tipo);
        jogador->comprarCaravana(std::move(novaCaravana), precoCaravana);  // Transfere a posse
    } else {
        oss << "Cidade " << cidadeLetra << "nao  pode adiciona mais caravana deste tipo." << std::endl;
    }
    oss << "Caravana de tipo " << tipoCaravana
        << " comprada na cidade " << cidadeLetra
        << " por " << precoCaravana << " moedas.\n";
    return oss.str();
}








//std::vector<std::unique_ptr<Cidade>> Simulador::getCidade() const {
//    return std::vector<std::unique_ptr<Cidade>>();
//}


/*
void Simulador::limpaDados() {
//    linha = coluna =0;
    setMoedas(1000);
    setInstantesEntreNovosItens(10);
    setDuracaoItem(20);
    setMaxItens(5);
    setPrecoVendaMercadoria(2);
    setPrecoCompraMercadoria(1);
    setPrecoCaravana(100);
    setInstantesEntreNovosBarbaros(40);
    setDuracaoBarbaros(60);
//    limparMapa();
}
void Simulador::atualizaMapa() {
    int linha, coluna, linhaAnt, colunaAnt;
//     for(auto &c : simulador->getJogador()->getCaravanas()){
//         std::tie(linha, coluna) = c->getPosicao();
//         std::tie(linhaAnt, colunaAnt) = c->getPosicaoAnterior();
//         if(mapa[linha][coluna]+'0' != c->getId()){
//             mapa[linhaAnt][colunaAnt] = '.';
//             mapa[linha][coluna] = static_cast<char>(c->getId()+'0');
//         }
//     }
}

void Simulador::setMoedas(int valor) {
    atributosConfiguraveis["moedas"] = valor;
}
void Simulador::setInstantesEntreNovosItens(int valor) {
    atributosConfiguraveis["instantes_entre_novos_itens"] = valor;
}
void Simulador::setDuracaoItem(int valor) {
    atributosConfiguraveis["duracao_item"] = valor;
}

void Simulador::setMaxItens(int valor) {
    atributosConfiguraveis["max_itens"] = valor;
}

void Simulador::setPrecoVendaMercadoria(int valor) {
    atributosConfiguraveis["preco_venda_mercadoria"] = valor;
}

void Simulador::setPrecoCompraMercadoria(int valor) {
    atributosConfiguraveis["preco_compra_mercadoria"] = valor;
}

void Simulador::setPrecoCaravana(int valor) {
    atributosConfiguraveis["preco_caravana"] = valor;
}

void Simulador::setInstantesEntreNovosBarbaros(int valor) {
    atributosConfiguraveis["instantes_entre_novos_barbaros"] = valor;
}
void Simulador::setDuracaoBarbaros(int valor) {
    atributosConfiguraveis["duracao_barbaros"] = valor;
}

void Simulador :: setAtributosConfiguraveis(const std::string chave, int valor) {
*/
/*
    if (chave == "moedas") {
        setMoedas(valor);
    }if (chave == "instantes_entre_novos_itens") {
        setInstantesEntreNovosItens(valor);
    } else if (chave == "duracao_item") {
        setDuracaoItem(valor);
    } else if (chave == "max_itens") {
        setMaxItens(valor);
    } else if (chave == "preco_venda_mercadoria") {
        setPrecoVendaMercadoria(valor);
    } else if (chave == "preco_compra_mercadoria") {
        setPrecoCompraMercadoria(valor);
    } else if (chave == "preco_caravana") {
        setPrecoCaravana(valor);
    } else if (chave == "instantes_entre_novos_barbaros") {
        setInstantesEntreNovosBarbaros(valor);
    } else if (chave == "duracao_barbaros") {
        setDuracaoBarbaros(valor);
    } else {
        std::cout << "Chave nao reconhecida: " << chave << std::endl;
    }
    *//*

    static const std::map<std::string, std::function<void(int)>> configuracoes = {
            {"moedas", [this](int v) { setMoedas(v); }},
            {"instantes_entre_novos_itens", [this](int v) { setInstantesEntreNovosItens(v); }},
            {"duracao_item", [this](int v) { setDuracaoItem(v); }},
            {"max_itens", [this](int v) { setMaxItens(v); }},
            {"preco_venda_mercadoria", [this](int v) { setPrecoVendaMercadoria(v); }},
            {"preco_compra_mercadoria", [this](int v) { setPrecoCompraMercadoria(v); }},
            {"preco_caravana", [this](int v) { setPrecoCaravana(v); }},
            {"instantes_entre_novos_barbaros", [this](int v) { setInstantesEntreNovosBarbaros(v); }},
            {"duracao_barbaros", [this](int v) { setDuracaoBarbaros(v); }},
    };

    auto it = configuracoes.find(chave);
    if (it != configuracoes.end()) {
        it->second(valor);  // Executa a função correspondente
        std::cout << "Configuracao aplicada: " << chave << " = " << valor << std::endl;
    } else {
        std::cout << "Chave nao reconhecida: " << chave << std::endl;
    }
}*/

/*
void Simulador::imprimirAtributosConfiguraveis() const {
    std::cout << "Atributos configuráveis:" << std::endl;
    for (const auto& [chave, valor] : getAtributosConfiguraveis()) {
        std::cout << chave << ": " << valor << std::endl;
    }
}
*/



//
//const std::pair<int, int> &Simulador::getPosCaravana() const {
//    return posCaravana;
//}
//
//void Simulador::setPosCaravana(const std::pair<int, int> &posCaravana) {
//    this->posCaravana = posCaravana;
//}
//
//const std::pair<int, int> &Simulador::getPosItem() const {
//    return posItem;
//}
//
//void Simulador::setPosItem(const std::pair<int, int> &posItem) {
//    this->posItem = posItem;
//}
//
//const std::pair<int, int> &Simulador::getPosCidade() const {
//    return posCidade;
//}
//
//void Simulador::setPosCidade(const std::pair<int, int> &posCidade) {
//    this->posCidade = posCidade;
//}
//
//const std::pair<int, int> &Simulador::getPosMontanha() const {
//    return posMontanha;
//}
//
//void Simulador::setPosMontanha(const std::pair<int, int> &posMontanha) {
//    this->posMontanha = posMontanha;
//}
//
//const std::pair<int, int> &Simulador::getPosDeserto() const {
//    return posDeserto;
//}
//
//void Simulador::setPosDeserto(const std::pair<int, int> &posDeserto) {
//    this->posDeserto = posDeserto;
//}
