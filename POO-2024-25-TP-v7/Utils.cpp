//
// Created by Tinoco on 20/12/2024.
//

#include "Utils.h"

void Utils::limparDados() {
    linha = coluna = jogador.moedas = 0;
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
    return linha >= 0 && linha < linha && coluna >= 0 && coluna < coluna && mapa[linha][coluna] != '+';
}

std::string Utils::executarComando(const std::string &comando)const {
    std::ostringstream oss;
    std::istringstream iss(comando);
    std::string cmd;
    iss >> cmd;
    try {
        if (!validarArgumentos(comando)) {
            oss << "Parametros invalidos\n";
            return oss.str(); // Termina a execução caso os parâmetros sejam inválidos
        }
        if (cmd == "config") {
            std::string nomeFicheiro;
            iss >> nomeFicheiro;
            // Verifica se o nome do ficheiro foi fornecido
            if (nomeFicheiro.empty()) {
               oss << "Erro: O comando 'config' requer o nome de um ficheiro como parametro." << std::endl;
                return oss.str();
            }
            bool sucesso = false;
            while (!sucesso) {
                try {
                    comandos.cmd_config(nomeFicheiro);
                    sucesso = true;
                } catch (const std::runtime_error &e) {
                    // Caso o ficheiro não seja encontrado ou outro erro ocorra
                    oss << e.what()
                        << "Ficheiro nao encontrado\n"
                        << "Digite novamente apenas o nome do ficheiro:";
                    std::getline(std::cin, nomeFicheiro);
                }
            }
        } else if (cmd == "sair") {
            comandos.cmd_sair();
        } else if (cmd == "exec") {
            comandos.cmd_exec(iss);
        } else if (cmd == "prox") {
            comandos.cmd_prox(iss);
        } else if (cmd == "comprac") {
            comandos.cmd_comprac(iss, precoCaravana);
        } else if (cmd == "precos") {
            std::string precos = comandos.cmd_precos();
            std::cout << precos;
        } else if (cmd == "cidade") {
            comandos.cmd_cidade(iss);
        } else if (cmd == "caravana") {
            comandos.cmd_caravana(iss);
        } else if (cmd == "compra") {
            comandos.cmd_compra(iss);
        } else if (cmd == "vende") {
            comandos.cmd_vende(iss);
        } else if (cmd == "move") {
            comandos.cmd_move(iss);
        } else if (cmd == "auto") {
            comandos.cmd_auto(iss);
        } else if (cmd == "stop") {
            comandos.cmd_stop(iss);
        } else if (cmd == "barbaro") {
            comandos.cmd_barbaro(iss);
        } else if (cmd == "moedas") {
            comandos.cmd_moedas(iss);
        } else if (cmd == "areia") {
            comandos.cmd_areia(iss);
        } else if (cmd == "tripul") {
            comandos.cmd_tripul(iss);
        } else if (cmd == "saves") {
            comandos.cmd_saves(iss);
        } else if (cmd == "loads") {
            comandos.cmd_loads(iss);
        } else if (cmd == "lists") {
            comandos.cmd_lists();
        } else if (cmd == "dels") {
            comandos.cmd_dels(iss);
        } else if (cmd == "terminar") {
            comandos.cmd_terminar();
        } else if (cmd == "showMoedas"){
            oss<< simulador->getJogador()->getMoedas() << std::endl;
        }
        else {
            oss << "Comando desconhecido: " << cmd << std::endl;
        }
    }
        // Trata outros tipos de exceções
    catch (const std::exception &e) {
        oss << "Erro: " << e.what() << std::endl;
        return oss.str();
    }
    return oss.str();
}

void Utils::limparMapa() {
    for(int i = 0; i < linha; i++){
        for(int j = 0; i < coluna; i++){
            mapa[i][j] = '.';
        }
    }
}

std::string Utils::processaMapa() const{
    std::ostringstream oss;
    for (int linha = 0; linha < linha; ++linha) {
        for (int coluna = 0; coluna < coluna; ++coluna) {
            char caractere = mapa[linha][coluna];

            if (isalpha(caractere)) { // Se for uma letra (cidade)
                auto novaCidade = std::make_shared<Cidade>(caractere, linha, coluna);
                if (!novaCidade) {
                    oss << "Erro ao criar a cidade '" << caractere << "'.\n";
                    continue;  // Avançar para o próximo caractere
                }
                novaCidade->adicionarCaravana(std::make_shared<CaravanaComercio>(Caravana::getId(),linha,coluna));
                novaCidade->adicionarCaravana(std::make_shared<CaravanaMilitar>(Caravana::getId(),linha,coluna));
                novaCidade->adicionarCaravana(std::make_shared<CaravanaSecreta>(Caravana::getId(),linha,coluna));
                simulador->adicionarCidade(novaCidade);

            } else if (isdigit(caractere) && caractere != '0') { // Se for um número (caravana)
                int id = caractere - '0'; //converte o caractere para o inteiro correspondente
                simulador->adicionaCaravanaJogador(std::make_shared<CaravanaMilitar>(id,linha, coluna)); //adiciona apenas militares aquelas já presentes no mapa, no enunciado nao especifica
            } else if (caractere == '+'){ // Se for uma montanha
                //montanha->adicionaMontanha();
            } else if (caractere == '.') { // uma posição vazia
                //cout << "Posição vazia (" << linha << ", " << coluna << ")\n";
            } else if (caractere == '!') { // caravana barbara
                simulador->adicionaCaravanaBarbara(std::make_shared<CaravanaBarbara>(Caravana::getId(), linha, coluna));
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
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            oss << mapa[i][j];
        }
        oss << std::endl;
    }
    return oss.str();
}

std::string Utils::mostrarConfig() const {
    std::ostringstream oss;
    oss << "Linhas: " << linha << std::endl
        << "Colunas: " << coluna << std::endl
        << "Mapa do deserto:" << std::endl;
        oss <<"\n\n\n------REMOVER ESTA LINHA MOSTRACONFIG---colocar o output para o buffer------\n\n\n";mostrarMapa();
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
    //int pontuacao = moedas;
    int pontuacao = jogador.getMoedas();
    return pontuacao;
}




