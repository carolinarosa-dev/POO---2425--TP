//
// Created by Tinoco on 20/12/2024.
//

#include "Utils.h"
#include "Comandos.h"

Utils::Utils() {}

void Utils::limparDados() {
    linha = coluna =0;
//    jogador.moedas = 0;
//    simulador->instantesEntreNovosItens = duracaoItem = maxItens = 0;
//    simulador->precoCaravana = 0;
//    simulador->instantesEntreNovosBarbaros = duracaoBarbaros = 0;
    limparMapa();
}

bool Utils::validarArgumentos(const std::string &comando, std::string  &mensagem) const{
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
            mensagem =  "Erro: O comando '" + cmd + "' nao aceita argumentos.\n";
            return false;
        }
    } else if (cmd == "config" || cmd == "exec" ||cmd == "prox" || cmd == "cidade" || cmd == "caravana" || cmd == "vende" ||
               cmd == "auto" || cmd == "stop" || cmd == "moedas" || cmd == "saves" || cmd == "loads" || cmd == "dels") {
        if (argumentos.size() != 1) {
            mensagem = "Erro: O comando '" + cmd + "' requer exatamente 1 argumento.\n";
            return false;
        }
    } else if (cmd == "comprac" || cmd == "compra" || cmd == "move" || cmd == "barbaro" || cmd == "tripul") {
        if (argumentos.size() != 2) {
            mensagem = "Erro: O comando '" + cmd + "' requer exatamente 2 argumentos.\n";
            return false;
        }
    } else if (cmd == "areia") {
        if (argumentos.size() != 3) {
            mensagem = "Erro: O comando 'areia' requer exatamente 3 argumentos.\n";
            return false;
        }
    } else {
        mensagem = "Erro: Comando desconhecido '" + cmd + "'.\n";
        return false;
    }
    return true;
}

bool Utils::posicaoValida(int linha, int coluna, char **mapa) const {
    //return linha >= 0 && linha < linha && coluna >= 0 && coluna < coluna && mapa[linha][coluna] != '+';
//
//// Verifica se a linha e a coluna estão dentro dos limites
//    if (linha < 0 || linha >= numLinhas || coluna < 0 || coluna >= numColunas) {
//        return false; // Posição fora dos limites do mapa
//    }
//
//    // Verifica se a posição é uma montanha ('+')
//    if (mapa[linha][coluna] == '+') {
//        return false; // Montanha é um obstáculo, não podemos passar
//    }
//
//    // Se não for montanha, a posição é válida
    return true;
}

bool Utils::verificarFicheiro(const std::string &nomeFicheiro) {
    if (!std::filesystem::exists(nomeFicheiro)) {
        std::cerr << "O ficheiro \"" << nomeFicheiro << "\" nao existe. Verifique o nome e tente novamente." << std::endl;
        return false;
    }

    std::ifstream ficheiro(nomeFicheiro);
    if (!ficheiro.is_open()) {
        std::cerr << "Erro ao abrir o ficheiro: " << nomeFicheiro << std::endl;
        return false;
    }

    return true;
}
//le as linhas, as colunas e o mapa
void Utils::lerFicheiro(std::ifstream& ficheiro, int& linhas, int& colunas, std::vector<std::string>& mapa) {
    std::string palavra;

    // Ler as dimensões (linhas e colunas)
    ficheiro >> palavra >> linhas;
    ficheiro >> palavra >> colunas;
    ficheiro.ignore();

    // Ler o mapa do deserto
    std::string linha;
    for (int i = 0; i < linhas; ++i) {
        std::getline(ficheiro, linha);  // Ler linha do mapa
        if (linha.length() != colunas) {
            throw std::runtime_error("Erro no mapa: número de colunas incorreto");
        }
        mapa.push_back(linha);
    }

    std::cout << "Mapa do deserto:" << std::endl;
    for (const auto &row: mapa) {
        std::cout << row << std::endl;
    }

}

void Utils::processarFicheiro(std::map<std::string, int>& atributosConfiguraveis) {
   /* for (const auto& [chave, valor] : atributosConfiguraveis) {
        if (chave == "moedas") {
            jogador->setMoedas(valor);
        } else if (chave == "instantes_entre_novos_itens") {
            simulador->setInstantesEntreNovosBarbaros(valor);
        } else if (chave == "duracao_item") {
            simulador->setDuracaoItem(valor);
        } else if (chave == "max_itens") {
            simulador->setMaxItens(valor);
        } else if (chave == "preco_venda_mercadoria") {
            simulador->setPrecoVendaMercadoria(valor);
        } else if (chave == "preco_compra_mercadoria") {
            simulador->setPrecoCompraMercadoria(valor);
        } else if (chave == "preco_caravana") {
            simulador->setPrecoCaravana(valor);
        } else if (chave == "instantes_entre_novos_barbaros") {
            simulador->setInstantesEntreNovosBarbaros(valor);
        } else if (chave == "duracao_barbaros") {
            simulador->setDuracaoBarbaros(valor);
        }
    }*/
    if (atributosConfiguraveis.find("moedas") != atributosConfiguraveis.end()) {
//        jogador->setMoedas(atributosConfiguraveis["moedas"]);
    }
    if (atributosConfiguraveis.find("instantes_entre_novos_itens") != atributosConfiguraveis.end()) {
        simulador->setInstantesEntreNovosItens(atributosConfiguraveis["instantes_entre_novos_itens"]);
    }
    if (atributosConfiguraveis.find("duração_item") != atributosConfiguraveis.end()) {
        simulador->setDuracaoItem(atributosConfiguraveis["duração_item"]);
    }
    if (atributosConfiguraveis.find("max_itens") != atributosConfiguraveis.end()) {
        simulador->setMaxItens(atributosConfiguraveis["max_itens"]);
    }
    if (atributosConfiguraveis.find("preço_venda_mercadoria") != atributosConfiguraveis.end()) {
        simulador->setPrecoVendaMercadoria(atributosConfiguraveis["preço_venda_mercadoria"]);
    }
    if (atributosConfiguraveis.find("preço_compra_mercadoria") != atributosConfiguraveis.end()) {
        simulador->setPrecoCompraMercadoria(atributosConfiguraveis["preço_compra_mercadoria"]);
    }
    if (atributosConfiguraveis.find("preço_caravana") != atributosConfiguraveis.end()) {
        simulador->setPrecoCaravana(atributosConfiguraveis["preço_caravana"]);
    }
    if (atributosConfiguraveis.find("instantes_entre_novos_barbaros") != atributosConfiguraveis.end()) {
        simulador->setInstantesEntreNovosBarbaros(atributosConfiguraveis["instantes_entre_novos_barbaros"]);
    }
    if (atributosConfiguraveis.find("duracao_barbaros") != atributosConfiguraveis.end()) {
        simulador->setDuracaoBarbaros(atributosConfiguraveis["duracao_barbaros"]);
    }
}

bool Utils::executarComando(const std::string &comando, std::string &mensagem)const {
    std::istringstream iss(comando);
    std::string cmd;
    iss >> cmd;
    try {
        if (!validarArgumentos(comando, mensagem)) {
            std::cout << mensagem;
            return false;
        }
        if (cmd == "config") {
            std::string nomeFicheiro;
            iss >> nomeFicheiro;
            // Verifica se o nome do ficheiro foi fornecido
            if (nomeFicheiro.empty()) {
                mensagem = "Erro: O comando 'config' requer o nome de um ficheiro como parametro.\n";
                //return false;
            }
            bool sucesso = false;
            while (!sucesso) {
                try {
                    comandos->cmd_config(nomeFicheiro, linha, coluna);
                    sucesso = true;
                } catch (const std::runtime_error &e) {
                    // Caso o ficheiro não seja encontrado ou outro erro ocorra
                    mensagem = std::string(e.what()) + "Ficheiro nao encontrado\nDigite novamente apenas o nome do ficheiro:\n";
                    std::getline(std::cin, nomeFicheiro);
                }
            }
        } else if (cmd == "sair") {
            comandos->cmd_sair();
        } else if (cmd == "exec") {
            comandos->cmd_exec(iss);
        } else if (cmd == "prox") {
            comandos->cmd_prox(iss);
        } else if (cmd == "comprac") {
           // comandos->cmd_comprac(iss, simulador->setPrecoComprac(iss));
           comandos->cmd_comprac(iss, precoComprac);
        } else if (cmd == "precos") {
            std::string precos = comandos->cmd_precos();
            std::cout << precos;
        } else if (cmd == "cidade") {
            comandos->cmd_cidade(iss);
        } else if (cmd == "caravana") {
            comandos->cmd_caravana(iss);
        } else if (cmd == "compra") {
            comandos->cmd_compra(iss);
        } else if (cmd == "vende") {
            comandos->cmd_vende(iss);
        } else if (cmd == "move") {
            comandos->cmd_move(iss);
        } else if (cmd == "auto") {
            comandos->cmd_auto(iss);
        } else if (cmd == "stop") {
            comandos->cmd_stop(iss);
        } else if (cmd == "barbaro") {
            comandos->cmd_barbaro(iss);
        } else if (cmd == "moedas") {
            comandos->cmd_moedas(iss);
        } else if (cmd == "areia") {
            comandos->cmd_areia(iss);
        } else if (cmd == "tripul") {
            comandos->cmd_tripul(iss);
        } else if (cmd == "saves") {
            comandos->cmd_saves(iss);
        } else if (cmd == "loads") {
            comandos->cmd_loads(iss);
        } else if (cmd == "lists") {
            comandos->cmd_lists();
        } else if (cmd == "dels") {
            comandos->cmd_dels(iss);
        } else if (cmd == "terminar") {
            comandos->cmd_terminar();
        } else {
            mensagem = "Comando desconhecido: ";
        }
    }
        // Trata outros tipos de exceções
    catch (const std::exception &e) {
        mensagem = e.what();
        return false;
    }
    return true;
}

void Utils::limparMapa() {
/*    for(int i = 0; i < linha; i++){
        for(int j = 0; i < coluna; i++){
            mapa[i][j] = '.';
        }
    }
*/}

std::string Utils::processaMapa() const{
    std::ostringstream oss;
/*    for (int linha = 0; linha < linha; ++linha) {
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
 */
    return oss.str();
}

void Utils::atualizaMapa() {
    /* int linha, coluna, linhaAnt, colunaAnt;
     for(auto &c : simulador->getJogador()->getCaravanas()){
         std::tie(linha, coluna) = c->getPosicao();
         std::tie(linhaAnt, colunaAnt) = c->getPosicaoAnterior();
         if(mapa[linha][coluna]+'0' != c->getId()){
             mapa[linhaAnt][colunaAnt] = '.';
             mapa[linha][coluna] = static_cast<char>(c->getId()+'0');
         }
     }*/
}

std::string Utils::mostrarMapa() const {
    std::ostringstream oss;
    /*  for(int i = 0; i < linha; i++){
          for(int j = 0; j < coluna; j++){
              oss << mapa[i][j];
          }
          oss << std::endl;
      }
  */    return oss.str();
}

std::string Utils::mostrarConfig() const {
    std::ostringstream oss;
    oss << "Linhas: " << linha << std::endl
        << "Colunas: " << coluna << std::endl;
//        << "Moedas: " << jogador->getMoedas();
    oss <<"\n\n\n------REMOVER ESTA LINHA MOSTRACONFIG---colocar o output para o buffer------\n\n\n";mostrarMapa();

    // Acesse o mapa de atributos configuráveis através do simulador
    const std::map<std::string, int>& atributosConfiguraveis = simulador->getAtributosConfiguraveis();

    oss << "Instantes entre novos itens: " << atributosConfiguraveis.at("duracaoItem") << std::endl
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
//    int pontuacao = jogador.getMoedas();
//    return pontuacao;
    return 0;
}

Utils::~Utils() {
    delete comandos;
}









