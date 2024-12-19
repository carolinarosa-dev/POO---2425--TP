//
// Created by Carolina Rosa on 10/11/2024.
//
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <filesystem>

#include "Comandos.h"
#include "Cidade.h"
#include "Caravana.h"
#include "CaravanaComercio.h"
#include "CaravanaMilitar.h"
#include "CaravanaSecreta.h"
#include "CaravanaBarbara.h"
#include "Montanha.h"

Comandos::Comandos(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    bufferAtual = new Buffer(linhas, colunas);
    mapa = new char*[linhas];
    for(int i = 0; i<linhas; i++){
        mapa[i] = new char[colunas];
    }
    simulador = std::make_shared<Simulador>(linhas, colunas, bufferAtual);

}

Comandos::Comandos() : linhas(0), colunas(0), moedas(0),
                       instantesEntreNovosItens(0), duracaoItem(0),
                       maxItens(0), precoCaravana(0),
                       instantesEntreNovosBarbaros(0), duracaoBarbaros(0) {
    simulador = nullptr;
}

void Comandos::limparDados() {
    linhas = colunas = moedas = 0;
    instantesEntreNovosItens = duracaoItem = maxItens = 0;
    precoCaravana = 0;
    instantesEntreNovosBarbaros = duracaoBarbaros = 0;
    limparMapa();
}
void Comandos::limparMapa(){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; i < colunas; i++){
            mapa[i][j] = '.';
        }
    }
}

void Comandos::mostrarMapa() const{
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << mapa[i][j];
        }
        cout << endl;
    }
}
void Comandos::lerConfiguracao(const std::string &nomeFicheiro) {
    if (!std::filesystem::exists(nomeFicheiro)) {
        throw std::runtime_error("O ficheiro \"" + nomeFicheiro + "\" nao existe. Verifique o nome e tente novamente.");
    }
    std::ifstream ficheiro(nomeFicheiro);
    if (!ficheiro.is_open()) {
        throw std::runtime_error("Erro ao abrir o ficheiro: " + nomeFicheiro);
    }
    limparDados();
    std::string linha;
    try {
        // Ler dimensões
        ficheiro >> linha >> linhas;
        ficheiro >> linha >> colunas;
        ficheiro.ignore(); // Ignorar o newline após a leitura das dimensões
        // Ler o mapa do deserto
        bufferAtual = new Buffer(linhas, colunas);
        mapa = new char*[linhas];
        for(int i = 0; i<linhas; i++){
            mapa[i] = new char[colunas];
        }
        simulador = std::make_shared<Simulador>(linhas, colunas, bufferAtual);
        for (int i = 0; i < linhas; ++i) {
            std::getline(ficheiro, linha);
            if (linha.length() != colunas) {
                throw std::runtime_error("Erro: o tamanho da linha do mapa nao corresponde ao numero de colunas.");
            }
            for (int j = 0; j< linha.length(); j++){
                mapa[i][j] = linha[j];
            }
        }
        processaMapa();
        // Ler parâmetros configuráveis
        while (ficheiro >> linha) {
            if (linha == "moedas") {
                ficheiro >> moedas;
                atributosConfiguraveis["moedas"] = moedas;
                simulador->getJogador()->adicionarMoedas(moedas);
            } else if (linha == "instantes_entre_novos_itens") {
                ficheiro >> instantesEntreNovosItens;
                atributosConfiguraveis["instantesEntreNovosItens"] = instantesEntreNovosItens;
            }else if (linha == "duração_item") {
                ficheiro >> duracaoItem;
                atributosConfiguraveis["duracaoItem"] = duracaoItem;
            }else if (linha == "max_itens") {
                ficheiro >> maxItens;
                atributosConfiguraveis["maxItens"] = maxItens;
            }else if (linha == "preço_venda_mercadoria") {
                ficheiro >> precoVendaMercadoria;
                atributosConfiguraveis["precoVendaMercadoria"] = precoVendaMercadoria;
            }else if (linha == "preço_compra_mercadoria") {
                ficheiro >> precoCompraMercadoria;
                atributosConfiguraveis["precoCompraMercadoria"] = precoCompraMercadoria;
            }else if (linha == "preço_caravana") {
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
        ficheiro.close();
        std::cout << "Configuracao lida com sucesso!" << std::endl;
        mostrarConfig();
    } catch (const std::exception &e) {
        throw std::runtime_error("Erro ao processar o ficheiro: " + std::string(e.what()));
    }
}

void Comandos::processaMapa() {
    for (int linha = 0; linha < linhas; ++linha) {
        for (int coluna = 0; coluna < colunas; ++coluna) {
            char caractere = mapa[linha][coluna];

            if (isalpha(caractere)) { // Se for uma letra (cidade)
                auto novaCidade = std::make_shared<Cidade>(caractere, linha, coluna);
                if (!novaCidade) {
                    cerr << "Erro ao criar a cidade '" << caractere << "'.\n";
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
                cerr << "Caractere desconhecido '" << caractere << "' na posição ("
                     << linha << ", " << coluna << ")\n";
            }
        }
    }
}
bool Comandos::validarArgumentos(const string &cmd, istringstream &iss) {
    std::vector<std::string> argumentos;
    std::string arg;
    while (iss >> arg) {
        argumentos.push_back(arg);
    }

    // Validar o número de argumentos com base no comando
    if (cmd == "sair" || cmd == "precos" || cmd == "lists" || cmd == "terminar") {
        if (!argumentos.empty()) {
            std::cerr << "Erro: O comando '" << cmd << "' nao aceita argumentos." << std::endl;
            return false;
        }
    } else if (cmd == "config" || cmd == "prox" || cmd == "cidade" || cmd == "caravana" || cmd == "vende" ||
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
void Comandos::executarComando(const string &comando) {
    istringstream iss(comando);
    string cmd;
    iss >> cmd;
    try {
        if (!validarArgumentos(cmd, iss)) {
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
                    lerConfiguracao(nomeFicheiro);
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

void Comandos::sair() {
    cout << "Saindo do programa..." << endl;
}

void Comandos::mostrarConfig() const {
    cout << "Linhas: " << linhas << endl;
    cout << "Colunas: " << colunas << endl;
    cout << "Mapa do deserto:" << endl;
    mostrarMapa();
    cout << "Moedas: " << atributosConfiguraveis.at("moedas") << endl;
    cout << "Instantes entre novos itens: " << atributosConfiguraveis.at("instantesEntreNovosItens") << endl;
    cout << "Duracao do item: " << atributosConfiguraveis.at("duracaoItem") << endl;
    cout << "Maximo de itens: " << atributosConfiguraveis.at("maxItens") << endl;
    cout << "Preco de venda de mercadoria: " << atributosConfiguraveis.at("precoVendaMercadoria") << endl;
    cout << "Preco de compra de mercadoria: " << atributosConfiguraveis.at("precoCompraMercadoria") << endl;
    cout << "Preco da caravana: " << atributosConfiguraveis.at("precoCaravana") << endl;
    cout << "Instantes entre novos barbaros: " << atributosConfiguraveis.at("instantesEntreNovosBarbaros") << endl;
    cout << "Duracao dos barbaros: " << atributosConfiguraveis.at("duracaoBarbaros") << endl;
}

void Comandos::exec(istringstream &iss) {
    string nomeFicheiro;
    iss >> nomeFicheiro;
    if (nomeFicheiro.empty()) {
        cerr << "Nome de ficheiro não especificado!" << endl;
        return;
    }
    ifstream ficheiro(nomeFicheiro);
    if (!ficheiro.is_open()) {
        cerr << "Erro ao abrir o ficheiro: " << nomeFicheiro << endl;
        return;
    }
    string linha;
    while (getline(ficheiro, linha)) {
        executarComando(linha);
    }
    ficheiro.close();
    cout << "Comandos do ficheiro " << nomeFicheiro << " executados com sucesso!" << endl;
}

void Comandos::prox(istringstream &iss) {
    int n = 1; // Valor padrão
    iss >> n;
    if (n <= 0) {
        cerr << "Numero de instantes deve ser maior que 0!" << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        // adicionar a lógica para atualizar o estado da simulação a cada instante
        cout << "Avancando instante " << (i + 1) << " de " << n << endl;
        // Atualizar o estado da simulação chamando Simulacao::atualizarEstado
        // simulador.atualizarEstado(); // 'simulacao' é uma instância da classe Simulacao
        // Exibir o mapa e outras informações relevantes
        mostrarConfig();
    }
}

void Comandos::terminar() {
    // Calcular e exibir a pontuação
    int pontuacao = calcularPontuacao();
    cout << "Simulacao terminada!" << endl;
    cout << "Pontuacao final: " << pontuacao << endl;

    fase = 1;
    limparDados();
    cout << "Esta de volta a fase 1. Pode iniciar uma nova simulacao ou sair do programa." << endl;
}

int Comandos::calcularPontuacao() const {
    // Exemplo de cálculo de pontuação (ajuste conforme necessário)
    int pontuacao = moedas;
    return pontuacao;
}

Comandos::~Comandos() {
    delete bufferAtual;
    for (auto& pair : buffersSalvos) {
        delete pair.second;
    }
}

void Comandos::saves(std::istringstream& iss) {
    std::string nome;
    iss >> nome;
    if (nome.empty()) {
        std::cerr << "Nome nao especificado!" << std::endl;
        return;
    }

    buffersSalvos[nome] = new Buffer(*bufferAtual);
    std::cout << "Estado do buffer salvo com o nome: " << nome << std::endl;
}

void Comandos::loads(std::istringstream& iss) {
    std::string nome;
    iss >> nome;
    if (nome.empty()) {
        std::cerr << "Nome nao especificado!" << std::endl;
        return;
    }
    auto it = buffersSalvos.find(nome);
    if (it != buffersSalvos.end()) {
        std::cout << "Carregando estado do buffer com o nome: " << nome << std::endl;
        std::cout << *(it->second);
    } else {
        std::cerr << "Nenhum buffer salvo com o nome: " << nome << std::endl;
    }
}

void Comandos::lists() {
    if (buffersSalvos.empty()) {
        std::cout << "Nenhum buffer salvo." << std::endl;
    } else {
        std::cout << "Buffers salvos:" << std::endl;
        for (const auto& pair : buffersSalvos) {
            std::cout << pair.first << std::endl;
        }
    }
}

void Comandos::dels(std::istringstream& iss) {
    std::string nome;
    iss >> nome;
    if (nome.empty()) {
        std::cerr << "Nome nao especificado!" << std::endl;
        return;
    }
    auto it = buffersSalvos.find(nome);
    if (it != buffersSalvos.end()) {
        delete it->second;
        buffersSalvos.erase(it);
        std::cout << "Buffer com o nome " << nome << " apagado." << std::endl;
    } else {
        std::cerr << "Nenhum buffer salvo com o nome: " << nome << std::endl;
    }
}

void Comandos::adicionaMoedas(istringstream& iss) {
    int n;
    iss >> n;
    moedas += n;
    std::cout << "Moedas atualizadas: " << moedas << std::endl;
}

string Comandos::listarPrecos() {
    ostringstream oss;
        oss << "Precos das mercadorias:"
            << "\nPreco de venda: " << atributosConfiguraveis.at("precoVendaMercadoria") << " moedas"
            << "\nPreco de compra: " <<atributosConfiguraveis.at("precoCompraMercadoria") << " moedas" << std::endl;
    return oss.str();
}

void Comandos::listarCaravanasCidade(std::istringstream &iss) {
    char letraCidade;
    iss >> letraCidade;
    std::shared_ptr<Cidade> cidadeEscolhida = nullptr;
    for (const auto& cidade : simulador->getCidades()) {
        if (cidade->getNome() == letraCidade) {
            cidadeEscolhida = cidade;
            break;
        }
    }
    if (!cidadeEscolhida) {
        throw std::invalid_argument("Erro: Cidade '" + std::string(1, letraCidade) + "' nao encontrada!");
    }
    std::string detalhesCaravanas = cidadeEscolhida->listarCaravanas();
    std::cout << detalhesCaravanas;
}

void Comandos::barbaro(istringstream &iss) {
    int linha, coluna;
    iss >> linha >> coluna;
    try {
        simulador->criarCaravanaBarbara(linha, coluna);
        //std::cout << "Caravana barbara criada nas coordenadas (" << linha << ", " << coluna << ")." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Erro ao criar caravana barbara: " << e.what() << std::endl;
    }
}

void Comandos::comprac(std::istringstream& iss, int precoCaravana) {
    char cidadeNome;
    char tipoCaravana;
    //char tipoCaravanaChar;

    // Lê a cidade, o número da caravana e o tipo da caravana
    iss >> cidadeNome >> tipoCaravana;
    // Chama a função do simulador para adicionar a caravana
    simulador->adicionaCaravanaJogador(cidadeNome, tipoCaravana, precoCaravana);
}

void Comandos::mostrarDetalhesCaravana(istringstream &iss) {
    int numCaravana;
    iss >> numCaravana;
    auto caravana = simulador->getCaravana(numCaravana);
    if (caravana){
        cout << caravana->exibirDetalhes();
    }else{
        cout << "Caravana nao encontrada"<<endl;
    }
}

void Comandos::tripul(istringstream &iss) {
    int idCaravana, quantidadeTripulantes;
    iss >> idCaravana >> quantidadeTripulantes;
    try {
        // Encontrar a caravana com o ID fornecido
        auto caravanas = simulador->getJogador()->getCaravanas();
        //auto caravanas = simulador->getCaravana(idCaravana);
        std::shared_ptr<Caravana> caravanaEncontrada = nullptr;

        for (const auto& caravana : caravanas) {
            //std::cout << "Verificando caravana com ID: " << caravana->getId() << std::endl; // Depuração
            if (caravana->getId() == idCaravana) {
                caravanaEncontrada = caravana;
                break;
            }
        }
        if (caravanaEncontrada) {
            if (caravanaEncontrada->estaEmCidade()) {
                caravanaEncontrada->adicionarTripulantes(quantidadeTripulantes);
                std::cout << "Adicionados " << quantidadeTripulantes << " tripulantes a caravana " << idCaravana << "." << std::endl;
            } else {
                throw std::runtime_error("A caravana nao esta em uma cidade.");
            }
        } else {
            throw std::runtime_error("Caravana com ID nao encontrada.");
        }
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}
/*
void Comandos::tripul(istringstream &iss) {
    int idCaravana, quantidadeTripulantes;
    iss >> idCaravana >> quantidadeTripulantes;

    // Verificar se a quantidade de tripulantes é válida
    if (quantidadeTripulantes <= 0) {
        std::cerr << "Erro: A quantidade de tripulantes deve ser maior que zero." << std::endl;
        return;
    }

    try {
        // Procurar pela caravana com o ID fornecido
        auto caravanaEncontrada = simulador->getCaravana(idCaravana); // Supõe que retorna um shared_ptr<Caravana>

        if (!caravanaEncontrada) {
            throw std::runtime_error("Caravana com ID " + std::to_string(idCaravana) + " nao encontrada.");
        }

        // Verificar se a caravana está em uma cidade
        if (!caravanaEncontrada->estaEmCidade()) {
            throw std::runtime_error("A caravana com ID " + std::to_string(idCaravana) + " nao esta em uma cidade.");
        }

        // Adicionar os tripulantes
        caravanaEncontrada->adicionarTripulantes(quantidadeTripulantes);
        std::cout << "Adicionados " << quantidadeTripulantes << " tripulantes a caravana " << idCaravana << "." << std::endl;

    } catch (const std::exception &e) {
        // Captura qualquer erro e exibe uma mensagem apropriada
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}
 */

void Comandos::areia(istringstream &iss) {
    int linha, coluna, raio;
    iss >> linha >> coluna >> raio;

    try {
        simulador->provocarTempestade(linha, coluna, raio);
        std::cout << "Tempestade de areia criada na posicao (" << linha << ", " << coluna << ") com raio " << raio << "." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Erro ao criar tempestade de areia: " << e.what() << std::endl;
    }
}

void Comandos::compra(istringstream &iss) {
    int idCaravana, quantidadeMercadoria;
    iss >> idCaravana >> quantidadeMercadoria;

    try {
        simulador->comprarMercadoria(idCaravana, quantidadeMercadoria, atributosConfiguraveis.at("precoCompraMercadoria"));
    } catch (const std::exception &e) {
        std::cerr << "Erro ao comprar mercadorias: " << e.what() << std::endl;
    }
}

void Comandos::vende(istringstream &iss) {
    int idCaravana;
    iss >> idCaravana;

    try {
        simulador->venderMercadoria(idCaravana, precoVendaMercadoria);
        std::cout << "Vendida toda a mercadoria da caravana " << idCaravana << "." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Erro ao vender mercadorias: " << e.what() << std::endl;
    }
}

void Comandos::move(istringstream &iss) {
    int idCaravana;
    std::string direcao;
    iss >> idCaravana >> direcao;

    try {
        simulador->moverCaravana(idCaravana, direcao, mapa);
        std::cout << "Caravana " << idCaravana << " movida na direcao " << direcao << "." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Erro ao mover a caravana: " << e.what() << std::endl;
    }
    atualizaMapa();
}

void Comandos::atualizaMapa(){
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

void Comandos::autoGestao(istringstream &iss) {
    int idCaravana;
    iss >> idCaravana;

    try {
        simulador->ativarAutoGestao(idCaravana);
        std::cout << "Caravana " << idCaravana << " colocada em auto-gestao." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Erro ao ativar auto-gestao: " << e.what() << std::endl;
    }
}

void Comandos::stop(istringstream &iss) {
    int idCaravana;
    iss >> idCaravana;

    try {
        simulador->desativarAutoGestao(idCaravana);
        std::cout << "Caravana " << idCaravana << " parou o comportamento automatico." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Erro ao parar o comportamento automatico: " << e.what() << std::endl;
    }
}