
#include "../include/Comandos.h"
#include "Mapa/Cidade.h"
#include "Caravanas/CaravanaComercio.h"
#include "Caravanas/CaravanaMilitar.h"
#include "Caravanas/CaravanaSecreta.h"
#include "Caravanas/CaravanaBarbara.h"
#include "Jogador.h"
#include <iostream>
#include <filesystem>
#include <fstream>

Comandos::Comandos(): simulador(nullptr){}

void Comandos::cmd_config(const std::string &nomeFicheiro){
    std::ifstream ficheiro(nomeFicheiro);

       // Ler as configurações do ficheiro para o mapa
    lerFicheiro(ficheiro);
    std::cout << "Configuracao carregada com sucesso!" << std::endl;
}

std::string Comandos::cmd_sair(){
    std::ostringstream oss;
    oss << "Implementar - Saindo do programa...\n";
    return oss.str();
}

std::string Comandos::cmd_exec(std::istringstream &iss){
    std::ostringstream oss;
    std::string nomeFicheiro;
    iss >> nomeFicheiro;
    if (nomeFicheiro.empty()) {
        oss << "Nome de ficheiro não especificado!\n";
        return oss.str();
    }
    std::ifstream ficheiro(nomeFicheiro);
    if (!ficheiro.is_open()) {
        oss << "Erro ao abrir o ficheiro: " << nomeFicheiro << std::endl;
        return oss.str();
    }
    std::string linha, mensagem;
    while (std::getline(ficheiro, linha)) {
        try {
            executarComando(linha, mensagem);
            if (!mensagem.empty()) {
                oss << "Resultado do comando: " << mensagem << std::endl;
            }
        } catch (const std::exception &e) {
            oss << "Erro ao executar comando '" << linha << "': " << e.what() << std::endl;
        }
    }
    ficheiro.close();
    oss << "Comandos do ficheiro " << nomeFicheiro << " executados com sucesso!" << std::endl;
    return oss.str();
}

std::string Comandos::cmd_prox(std::istringstream &iss){
    std::ostringstream oss;
    int n = 1; // Valor padrão
    iss >> n;
    if (n <= 0) {
        oss << "Numero de instantes deve ser maior que 0!\n";
        return oss.str();
    }
    for (int i = 0; i < n; ++i) {
        // adicionar a lógica para atualizar o estado da simulação a cada instante
        oss << "Avancando instante " << (i + 1) << " de " << n;

         //"Atualizar o estado da simulação chamando Simulacao::atualizarEstado\n\n\n\";
        // simulador.atualizarEstado(); // 'simulacao' é uma instância da classe Simulacao
        // Exibir o mapa e outras informações relevantes

        //mostrarConfig();
    }
    return oss.str();
}

//void Comandos::cmd_comprac(std::istringstream &iss, int precoCaravana) {
void Comandos::cmd_comprac(std::istringstream &iss){

    char cidadeNome;
    char tipoCaravana;
    // Lê a cidade e o tipo da caravana
    iss >> cidadeNome >> tipoCaravana;

    if (moedas >= precoCaravana) {
        simulador->jogadorCompraCaravana(cidadeNome, tipoCaravana, precoCaravana);
    } else {
        std::cout << "Moedas insuficientes para comprar uma caravana!";
    }

}

std::string Comandos::cmd_precos(){
    std::ostringstream oss;
    auto atributos = getAtributosConfiguraveis();
    oss << "Precos das mercadorias:"
        << "\nPreco de venda: " << atributos.at("preco_venda_mercadoria") << " moedas"
        << "\nPreco de compra: " << atributos.at("preco_compra_mercadoria") << " moedas" << std::endl;

    return oss.str();
}

std::string Comandos::cmd_cidade(std::istringstream &iss){
    char letraCidade;
    iss >> letraCidade;


    //std::unique_ptr<Cidade> cidadeEscolhida = simulador->encontrarCidade(letraCidade);

//    if (!cidadeEscolhida) {
//        throw std::invalid_argument("Erro: Cidade '" + std::string(1, letraCidade) + "' nao encontrada!");
//    }
//
//    // Agora que encontramos a cidade, listamos as caravanas que estão lá
    std::string detalhesCaravanas;// = cidadeEscolhida->listarCaravanas();  // Supondo que o metodo `listarCaravanas` exista
//    std::cout << detalhesCaravanas << std::endl;  // Exibe as caravanas da cidade

    // Armazena a resposta no stringstream
    std::ostringstream oss;
    oss << detalhesCaravanas;
    return oss.str();  // Retorna as caravanas da cidade como uma string
}

void Comandos::cmd_caravana(std::istringstream &iss){
    //std::ostringstream oss;
    int numCaravana;
    iss >> numCaravana;
    auto caravana = simulador->getJogador()->exibirDetalheCaravana(numCaravana);

    std::cout << caravana;
}

std::string Comandos::cmd_compra(std::istringstream &iss){
    std::ostringstream oss;
    int idCaravana, quantidadeMercadoria;
    iss >> idCaravana >> quantidadeMercadoria;

    try {
        simulador->comprarMercadoria(idCaravana, quantidadeMercadoria, atributosConfiguraveis.at("preco_compra_mercadoria"));
    } catch (const std::exception &e) {
        oss << "Erro ao comprar mercadorias: " << e.what() << std::endl;
    }
    return oss.str();
}

std::string Comandos::cmd_vende(std::istringstream &iss){
    std::ostringstream oss;
    int idCaravana;
    iss >> idCaravana;

    try {
       simulador->venderMercadoria(idCaravana, atributosConfiguraveis.at("preco_venda_mercadoria"));
        oss<< "Vendida toda a mercadoria da caravana " << idCaravana << "." << std::endl;
    } catch (const std::exception &e) {
        oss << "Erro ao vender mercadorias: " << e.what() << std::endl;
    }
    return oss.str();
}

std::string Comandos::cmd_move(std::istringstream &iss){
    std::ostringstream oss;
    int idCaravana;
    std::string direcao;
    iss >> idCaravana >> direcao;

    try {
//        simulador->moverCaravana(idCaravana, direcao, mapa);
        oss << "Caravana " << idCaravana << " movida na direcao " << direcao << "." << std::endl;
    } catch (const std::exception &e) {
        oss << "Erro ao mover a caravana: " << e.what() << std::endl;
    }
    atualizaMapa();
    return oss.str();
}

std::string Comandos::cmd_auto(std::istringstream &iss){
    std::ostringstream oss;
    int idCaravana;
    iss >> idCaravana;

    try {
//        simulador->ativarAutoGestao(idCaravana);
        oss << "Caravana " << idCaravana << " colocada em auto-gestao." << std::endl;
    } catch (const std::exception &e) {
        oss << "Erro ao ativar auto-gestao: " << e.what() << std::endl;
    }
    return oss.str();
}

std::string Comandos::cmd_stop(std::istringstream &iss){
    std::ostringstream oss;
    int idCaravana;
    iss >> idCaravana;

    try {
//        simulador->desativarAutoGestao(idCaravana);
        oss << "Caravana " << idCaravana << " parou o comportamento automatico." << std::endl;
    } catch (const std::exception &e) {
        oss << "Erro ao parar o comportamento automatico: " << e.what() << std::endl;
    }
    return oss.str();
}
std::string Comandos::cmd_barbaro(std::istringstream &iss){
    std::ostringstream oss;
    int linha, coluna;
    iss >> linha >> coluna;
    try {
//        simulador->criarCaravanaBarbara(linha, coluna);
        //std::cout << "Caravana barbara criada nas coordenadas (" << linha << ", " << coluna << ")." << std::endl;
    } catch (const std::exception &e) {
        oss << "Erro ao criar caravana barbara: " << e.what() << std::endl;
    }
    return oss.str();
}

std::string Comandos::cmd_areia(std::istringstream &iss){
    std::ostringstream oss;
    int linha, coluna, raio;
    iss >> linha >> coluna >> raio;

    try {
//        simulador->provocarTempestade(linha, coluna, raio);
        oss << "Tempestade de areia criada na posicao (" << linha << ", " << coluna << ") com raio " << raio << "." << std::endl;
    } catch (const std::exception &e) {
        oss << "Erro ao criar tempestade de areia: " << e.what() << std::endl;
    }
    return oss.str();
}

std::string Comandos::cmd_moedas(std::istringstream &iss){
    std::ostringstream oss;
    int n;
    iss >> n;
//    jogador.moedas += n;
//    oss << "Moedas atualizadas: " << jogador.getMoedas() << std::endl;
    return oss.str();
}

std::string Comandos::cmd_tripul(std::istringstream &iss){
    std::ostringstream oss;
    int idCaravana, quantidadeTripulantes;
    iss >> idCaravana >> quantidadeTripulantes;
//    try {
        // Encontrar a caravana com o ID fornecido
//        auto caravanas = simulador->getJogador()->getCaravanas();
        //auto caravanas = simulador->getCaravana(idCaravana);
//        std::shared_ptr<Caravana> caravanaEncontrada = nullptr;

//        for (const auto& caravana : caravanas) {
//            //std::cout << "Verificando caravana com ID: " << caravana->getId() << std::endl; // Depuração
//            if (caravana->getId() == idCaravana) {
//                caravanaEncontrada = caravana;
//                break;
//            }
//        }
//        if (caravanaEncontrada) {
//            if (caravanaEncontrada->estaEmCidade()) {
//                caravanaEncontrada->adicionarTripulantes(quantidadeTripulantes);
//                oss << "Adicionados " << quantidadeTripulantes << " tripulantes a caravana " << idCaravana << "." << std::endl;
//            } else {
//                throw std::runtime_error("A caravana nao esta em uma cidade.");
//            }
//        } else {
//            throw std::runtime_error("Caravana com ID nao encontrada.");
//        }
//    } catch (const std::exception &e) {
//        oss << "Erro: " << e.what() << std::endl;
//    }
    return oss.str();
}
std::string Comandos::cmd_saves(std::istringstream &iss){
    std::ostringstream oss;
    std::string nome;
    iss >> nome;
    if (nome.empty()) {
        oss << "Nome nao especificado!" << std::endl;
        return oss.str();
    }

    //buffersSalvos[nome] = new Buffer(*bufferAtual);
    oss << "Estado do buffer salvo com o nome: " << nome << std::endl;

    return oss.str();
}

std::string Comandos::cmd_loads(std::istringstream &iss){
    std::ostringstream oss;
    std::string nome;
    iss >> nome;
    if (nome.empty()) {
        oss << "Nome nao especificado!" << std::endl;
        return oss.str();
    }
//    auto it = buffersSalvos.find(nome);
//    if (it != buffersSalvos.end()) {
//        oss << "Carregando estado do buffer com o nome: " << nome << std::endl << *(it->second);
//    } else {
//        oss << "Nenhum buffer salvo com o nome: " << nome << std::endl;
//    }
    return oss.str();
}
std::string Comandos::cmd_lists(){
    std::ostringstream oss;
    /*if (buffersSalvos.empty()) {
        oss << "Nenhum buffer salvo." << std::endl;
    } else {
        oss << "Buffers salvos:" << std::endl;
        for (const auto& pair : buffersSalvos) {
            std::cout << pair.first << std::endl;
        }
    }
    */return oss.str();
}

std::string Comandos::cmd_dels(std::istringstream &iss){
    std::ostringstream oss;
    std::string nome;
    iss >> nome;
//    if (nome.empty()) {
//        oss << "Nome nao especificado!" << std::endl;
//        return oss.str();
//    }
//    auto it = buffersSalvos.find(nome);
//    if (it != buffersSalvos.end()) {
//        delete it->second;
//        buffersSalvos->erase(it);
//        oss << "Buffer com o nome " << nome << " apagado." << std::endl;
//    } else {
//        oss << "Nenhum buffer salvo com o nome: " << nome << std::endl;
//    }
    return oss.str();
}

std::string Comandos::cmd_terminar(){
    std::ostringstream oss;
    // Calcular e exibir a pontuação
    int pontuacao = calcularPontuacao();
    oss << "Simulacao terminada!\n"
        << "Pontuacao final: " << pontuacao << std::endl;

    simulador->setFase(1);
    limpaDados();
    oss << "Esta de volta a fase 1. Pode iniciar uma nova simulacao ou sair do programa." << std::endl;
    return oss.str();
}



void Comandos::processaMapa() {
    for (int linha = 0; linha < simulador->getLinhas(); ++linha) {
        for (int coluna = 0; coluna < simulador->getColunas(); ++coluna) {
            char caractere = simulador->getCaractere(linha,coluna);

            if (isalpha(caractere)) { // Se for uma letra (cidade)
                auto novaCidade = std::make_unique<Cidade>(caractere, linha, coluna);
                if (!novaCidade) {
                    std::cerr << "Erro ao criar a cidade '" << caractere << "'.\n";
                    continue;  // Avançar para o próximo caractere
                }
                novaCidade->adicionaCaravanasCidade(std::make_unique<CaravanaComercio>(Caravana::getContador(),linha,coluna,Caravana::COMERCIO));
                novaCidade->adicionaCaravanasCidade(std::make_unique<CaravanaMilitar>(Caravana::getContador(),linha,coluna,Caravana::MILITAR));
                novaCidade->adicionaCaravanasCidade(std::make_unique<CaravanaSecreta>(Caravana::getContador(),linha,coluna,Caravana::SECRETA));

                simulador->adicionarCidade(std::move(novaCidade));

            } else if (isdigit(caractere) && caractere != '0') { // Se for um número (caravana)
                int id = caractere - '0'; //converte o caractere para o inteiro correspondente
                simulador->adicionaCaravanaJogador(std::make_unique<CaravanaMilitar>(id,linha, coluna,Caravana::MILITAR)); //por enquanto adiciona apenas militares aquelas já presentes no mapa, mas podemos fazer um random
            } else if (caractere == '+'){ // Se for uma montanha
                //montanha->adicionaMontanha();
            } else if (caractere == '.') { // uma posição vazia
                //cout << "Posição vazia (" << linha << ", " << coluna << ")\n";
            } else if (caractere == '!') { // caravana barbara
                simulador->adicionaCaravanaBarbara(std::make_unique<CaravanaBarbara>(linha, coluna));
            }else {
                std::cerr << "Caractere desconhecido '" << caractere << "' na posição ("
                     << linha << ", " << coluna << ")\n";
            }
        }
    }
}
void Comandos::lerFicheiro(std::ifstream &ficheiro){
    if (!ficheiro.is_open()) {
        throw std::runtime_error("Erro: Não foi possível abrir o ficheiro.");
    }

    std::string palavra;
    int linhas, colunas;
    ficheiro >> palavra >> linhas;
    ficheiro >> palavra >> colunas;
    ficheiro.ignore();

    // Verifica se as dimensões são válidas
    if (linhas  <= 0 || colunas <= 0) {
        throw std::runtime_error("Dimensões inválidas no ficheiro (linhas ou colunas <= 0).");
    }

    // Ler o mapa do deserto
    std::string linha;

    simulador = new Simulador(linhas, colunas);
    for (int i = 0; i < simulador->getLinhas(); ++i) {
        std::getline(ficheiro, linha);
        if (linha.length() != simulador->getColunas()) {
            throw std::runtime_error("Erro: o tamanho da linha do mapa nao corresponde ao numero de colunas.");
        }
        for (int j = 0; j< linha.length(); j++){
            simulador->setLinhaMapa(i,j,linha[j]);
        }
    }

    processaMapa();
    simulador->imprimeMapa();

    // Le as configurações
    std::string linha_config;
    while (ficheiro >> linha) {
        if (linha == "moedas") {
            ficheiro >> moedas;
            atributosConfiguraveis["moedas"] = moedas;
            simulador->getJogador()->adicionarMoedas(moedas);
        } else if (linha == "instantes_entre_novos_itens") {
            ficheiro >> instantesEntreNovosItens;
            atributosConfiguraveis["instantesEntreNovosItens"] = instantesEntreNovosItens;
        }else if (linha == "duracao_item") {
            ficheiro >> duracaoItem;
            atributosConfiguraveis["duracaoItem"] = duracaoItem;
        }else if (linha == "max_itens") {
            ficheiro >> maxItens;
            atributosConfiguraveis["maxItens"] = maxItens;
        }else if (linha == "preco_venda_mercadoria") {
            ficheiro >> precoVendaMercadoria;
            atributosConfiguraveis["precoVendaMercadoria"] = precoVendaMercadoria;
        }else if (linha == "preco_compra_mercadoria") {
            ficheiro >> precoCompraMercadoria;
            atributosConfiguraveis["precoCompraMercadoria"] = precoCompraMercadoria;
        }else if (linha == "preco_caravana") {
            ficheiro >> precoCaravana;
            atributosConfiguraveis["precoCaravana"] = precoCaravana;
        }else if (linha == "instantes_entre_novos_barbaros") {
            ficheiro >> instantesEntreNovosBarbaros;
            atributosConfiguraveis["instantesEntreNovosBarbaros"] = instantesEntreNovosBarbaros;
        }else if (linha == "duracao_barbaros") {
            ficheiro >> duracaoBarbaros;
            atributosConfiguraveis["duracaoBarbaros"] = duracaoBarbaros;
        }
    }
    imprimirAtributosConfiguraveis();
    ficheiro.close();
}
bool Comandos::validarArgumentos(const std::string &comando, std::string  &mensagem){
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
bool Comandos::executarComando(const std::string &comando, std::string &mensagem){
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
                return false;
            }
            bool sucesso = false;
            while (!sucesso) {
                try {
                    cmd_config(nomeFicheiro);
                    sucesso = true;
                } catch (const std::runtime_error &e) {
                    // Caso o ficheiro não seja encontrado ou outro erro ocorra
                    mensagem = std::string(e.what()) + "Ficheiro nao encontrado\nDigite novamente apenas o nome do ficheiro:\n";
                    std::getline(std::cin, nomeFicheiro);
                }
            }
        } else if (cmd == "sair") {
            cmd_sair();
        } else if (cmd == "exec") {
            cmd_exec(iss);
        } else if (cmd == "prox") {
            cmd_prox(iss);
        } else if (cmd == "comprac") {
              cmd_comprac(iss);
        } else if (cmd == "precos") {
            std::string precos = cmd_precos();
            std::cout << precos;
        } else if (cmd == "cidade") {
            cmd_cidade(iss);
        } else if (cmd == "caravana") {
            cmd_caravana(iss);
        } else if (cmd == "compra") {
            cmd_compra(iss);
        } else if (cmd == "vende") {
            cmd_vende(iss);
        } else if (cmd == "move") {
            cmd_move(iss);
        } else if (cmd == "auto") {
           cmd_auto(iss);
        } else if (cmd == "stop") {
            cmd_stop(iss);
        } else if (cmd == "barbaro") {
           cmd_barbaro(iss);
        } else if (cmd == "moedas") {
            cmd_moedas(iss);
        } else if (cmd == "areia") {
            cmd_areia(iss);
        } else if (cmd == "tripul") {
            cmd_tripul(iss);
        } else if (cmd == "saves") {
            cmd_saves(iss);
        } else if (cmd == "loads") {
            cmd_loads(iss);
        } else if (cmd == "lists") {
            cmd_lists();
        } else if (cmd == "dels") {
            cmd_dels(iss);
        } else if (cmd == "terminar") {
            cmd_terminar();
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
void Comandos::limparMapa() {
/*    for(int i = 0; i < linha; i++){
        for(int j = 0; i < coluna; i++){
            mapa[i][j] = '.';
        }
    }
*/}
void Comandos::limpaDados() {
    moedas = 0;
    instantesEntreNovosItens = duracaoItem = maxItens = 0;
    precoCaravana = 0;
    instantesEntreNovosBarbaros = duracaoBarbaros = 0;
    limparMapa();
}
void Comandos::atualizaMapa() {
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

int Comandos::calcularPontuacao(){
    std::map<std::string, int> atributos = getAtributosConfiguraveis();
    int pontuacao = atributos["moedas"];
    return pontuacao;
}


std::map<std::string, int> Comandos::getAtributosConfiguraveis()const{
    return atributosConfiguraveis;
}

void Comandos::imprimirAtributosConfiguraveis() const {
    std::cout << "Atributos configuraveis:" << std::endl;
    for (const auto& [chave, valor] : getAtributosConfiguraveis()) {
        std::cout << chave << ": " << valor << std::endl;
    }
}

Comandos::~Comandos(){

}



