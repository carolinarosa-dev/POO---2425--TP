//
// Created by Tinoco on 20/12/2024.
//

#include "Utils.h"

void Utils::limparDados() {
    linhas = colunas = moedas = 0;
    instantesEntreNovosItens = duracaoItem = maxItens = 0;
    precoCaravana = 0;
    instantesEntreNovosBarbaros = duracaoBarbaros = 0;
    limparMapa();
}

bool Utils::validarArgumentos(const std::string &cmd) {
    std::vector<std::string> argumentos;
    std::istringstream iss(comando);
    std::string cmd, arg;
    iss >> cmd;

    while (iss >> arg) {
        argumentos.push_back(arg);
    }

    // Validar o número de argumentos com base no comando
    if (cmd == "sair" || cmd == "precos" || cmd == "lists" || cmd == "terminar") {
        if (!argumentos.empty()) {
            std::cerr << "Erro: O comando '" << cmd << "' nao aceita argumentos." << std::endl;
            return false;
        }
    } else if (cmd == "config" || cmd == "exec" ||cmd == "prox" || cmd == "cidade" || cmd == "caravana" || cmd == "vende" ||
               cmd == "auto" || cmd == "stop" || cmd == "moedas" || cmd == "saves" || cmd == "loads" || cmd == "dels") {
        if (argumentos.size() != 1) {
            std::cerr << "Erro: O comando '" << cmd << "' requer exatamente 1 argumento." << std::endl;
            return false;
        }
    } else if (cmd == "comprac" || cmd == "compra" || cmd == "move" || cmd == "barbaro" || cmd == "tripul") {
        if (argumentos.size() != 2) {
            std::cerr << "Erro: O comando '" << cmd << "' requer exatamente 2 argumentos." << std::endl;
            return false;
        }
    } else if (cmd == "areia") {
        if (argumentos.size() != 3) {
            std::cerr << "Erro: O comando 'areia' requer exatamente 3 argumentos." << std::endl;
            return false;
        }
    } else {
        // Comando desconhecido
        std::cerr << "Erro: Comando desconhecido '" << cmd << "'." << std::endl;
        return false;
    }

    return true; // Se nenhuma validação falhar, retorna verdadeiro
}
bool Utils::posicaoValida(int linha, int coluna, char **mapa) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas && mapa[linha][coluna] != '+';
}

void Utils::executarComando(const std::string &comando) {
    std::istringstream iss(comando);
    std::string cmd;
    iss >> cmd;
    try {
        if (!validarArgumentos(comando)) {
            return; // Termina a execução caso os parâmetros sejam inválidos
        }
        if (cmd == "config") {
            std::string nomeFicheiro;
            iss >> nomeFicheiro;
            // Verifica se o nome do ficheiro foi fornecido
            if (nomeFicheiro.empty()) {
                std::cerr << "Erro: O comando 'config' requer o nome de um ficheiro como parametro." << std::endl;
                return;
            }
            bool sucesso = false;
            while (!sucesso) {
                try {
                    comandos.config(nomeFicheiro);
                    sucesso = true;
                } catch (const std::runtime_error &e) {
                    // Caso o ficheiro não seja encontrado ou outro erro ocorra
                    std::cerr << e.what() << std::endl;
                    std::cout << "Ficheiro nao encontrado\n";
                    std::cout << "Digite novamente apenas o nome do ficheiro:";
                    std::getline(std::cin, nomeFicheiro);
                }
            }
        } else if (cmd == "sair") {
            sair();
        } else if (cmd == "exec") {
            exec(iss);
        } else if (cmd == "prox") {
            prox(iss);
        } else if (cmd == "comprac") {
            comprac(iss, precoCaravana);
        } else if (cmd == "precos") {
            std::string precos = listarPrecos();
            std::cout << precos;
        } else if (cmd == "cidade") {
            listarCaravanasCidade(iss);
        } else if (cmd == "caravana") {
            mostrarDetalhesCaravana(iss);
        } else if (cmd == "compra") {
            compra(iss);
        } else if (cmd == "vende") {
            vende(iss);
        } else if (cmd == "move") {
            move(iss);
        } else if (cmd == "auto") {
            autoGestao(iss);
        } else if (cmd == "stop") {
            stop(iss);
        } else if (cmd == "barbaro") {
            barbaro(iss);
        } else if (cmd == "moedas") {
            adicionaMoedas(iss);
        } else if (cmd == "areia") {
            areia(iss);
        } else if (cmd == "tripul") {
            tripul(iss);
        } else if (cmd == "saves") {
            saves(iss);
        } else if (cmd == "loads") {
            loads(iss);
        } else if (cmd == "lists") {
            lists();
        } else if (cmd == "dels") {
            dels(iss);
        } else if (cmd == "terminar") {
            terminar();
        } else if (cmd == "showMoedas"){
            cout << simulador->getJogador()->getMoedas() <<endl;
        }
        else {
            std::cout << "Comando desconhecido: " << cmd << std::endl;
        }
    }
        // Trata outros tipos de exceções
    catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}

void Utils::limparMapa() {
    for(int i = 0; i < linhas; i++){
        for(int j = 0; i < colunas; i++){
            mapa[i][j] = '.';
        }
    }
}

std::string Utils::processaMapa() const{
    std::ostringstream oss;
    for (int linha = 0; linha < linhas; ++linha) {
        for (int coluna = 0; coluna < colunas; ++coluna) {
            char caractere = mapa[linha][coluna];

            if (isalpha(caractere)) { // Se for uma letra (cidade)
                auto novaCidade = std::make_shared<Cidade>(caractere, linha, coluna);
                if (!novaCidade) {
                    oss << "Erro ao criar a cidade '" << caractere << "'.\n";
                    continue;  // Avançar para o próximo caractere
                }
                novaCidade->adicionarCaravana(make_shared<CaravanaComercio>(Caravana::getProximoId()+10,linha,coluna));
                novaCidade->adicionarCaravana(make_shared<CaravanaMilitar>(Caravana::getProximoId()+10,linha,coluna));
                novaCidade->adicionarCaravana(make_shared<CaravanaSecreta>(Caravana::getProximoId()+10,linha,coluna));
                simulador->adicionarCidade(novaCidade);

            } else if (isdigit(caractere) && caractere != '0') { // Se for um número (caravana)
                int id = caractere - '0'; //converte o caractere para o inteiro correspondente
                simulador->adicionaCaravanaJogador(make_shared<CaravanaMilitar>(id,linha, coluna)); //por enquanto adiciona apenas militares aquelas já presentes no mapa, mas podemos fazer um random
            } else if (caractere == '+'){ // Se for uma montanha
                //montanha->adicionaMontanha();
            } else if (caractere == '.') { // uma posição vazia
                //cout << "Posição vazia (" << linha << ", " << coluna << ")\n";
            } else if (caractere == '!') { // caravana barbara
                simulador->adicionaCaravanaBarbara(make_shared<CaravanaBarbara>(Caravana::getProximoId(), linha, coluna));
            }else {
                oss << "Caractere desconhecido '" << caractere << "' na posição ("
                     << linha << ", " << coluna << ")\n";
            }
        }
    }
    return oss.str();
}

void Utils::atualizaMapa() {
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

std::string Utils::mostrarMapa() const {
    std::ostringstream oss;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << mapa[i][j];
        }
        cout << endl;
    }
    return oss.str();
}

std::string Utils::mostrarConfig() const {
    std::ostringstream oss;
    oss << "Linhas: " << linhas << std::endl
        << "Colunas: " << colunas << std::endl
        << "Mapa do deserto:" << std::endl;
        oss <<"\n\n\n------REMOVER ESTA LINHA MOSTRACONFIG---colocar o output para o buffer------\n\n\n"    mostrarMapa();
        oss << "Moedas: " << atributosConfiguraveis.at("moedas") << std::endl
        << "Instantes entre novos itens: " << atributosConfiguraveis.at("instantesEntreNovosItens") << std::endl
        << "Duracao do item: " << atributosConfiguraveis.at("duracaoItem") << std::endl
        << "Maximo de itens: " << atributosConfiguraveis.at("maxItens") << std::endl
        << "Preco de venda de mercadoria: " << atributosConfiguraveis.at("precoVendaMercadoria") << std::endl
        << "Preco de compra de mercadoria: " << atributosConfiguraveis.at("precoCompraMercadoria") << std::endl
        << "Preco da caravana: " << atributosConfiguraveis.at("precoCaravana") << std::endl
        << "Instantes entre novos barbaros: " << atributosConfiguraveis.at("instantesEntreNovosBarbaros") << std::endl
        << "Duracao dos barbaros: " << atributosConfiguraveis.at("duracaoBarbaros") << std::endl;
    return oss.str();

}

int Utils::calcularPontuacao() const {
    // Exemplo de cálculo de pontuação (ajuste conforme necessário)
    int pontuacao = moedas;
    return pontuacao;
}




