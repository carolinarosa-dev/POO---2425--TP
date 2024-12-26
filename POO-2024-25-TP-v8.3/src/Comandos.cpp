
#include "../include/Comandos.h"

#include <iostream>
#include <filesystem>
#include <fstream>

Comandos::Comandos(): simulador(nullptr){}

void Comandos::cmd_config(const std::string &nomeFicheiro, int linhas, int colunas){
    std::ifstream ficheiro(nomeFicheiro);

       // Ler as configurações do ficheiro para o mapa
    lerFicheiro(ficheiro, linhas, colunas);
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
    moedas = atributosConfiguraveis.at("moedas");
    preco_caravana = atributosConfiguraveis.at("preco_carvana");

    std::cout << "moedas" << moedas;
    std::cout << "preco_caravana" << preco_caravana;

    if (moedas >= preco_caravana) {
        simulador->jogadorCompraCaravana(cidadeNome, tipoCaravana, preco_caravana);
    }
//    else {
//        throw runtime_error("Moedas insuficientes para comprar uma caravana!");
//    }
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
/*    char letraCidade;
    iss >> letraCidade;
    std::shared_ptr<Cidade> cidadeEscolhida = nullptr;
    for (const auto& cidade : simulador->getCidade()) {
        if (cidade->getNome() == letraCidade) {
            cidadeEscolhida = cidade;
            break;
        }
    }
    if (!cidadeEscolhida) {
        throw std::invalid_argument("Erro: Cidade '" + std::string(1, letraCidade) + "' nao encontrada!");
    }
    std::string detalhesCaravanas = cidadeEscolhida->listarCaravanas();
    std::cout << detalhesCaravanas;char letraCidade;
    iss >> letraCidade;
    std::shared_ptr<Cidade> cidadeEscolhida = nullptr;
    for (const auto& cidade : simulador->getCidade()) {
        if (cidade->getNome() == letraCidade) {
            cidadeEscolhida = cidade;
            break;
        }
    }
    if (!cidadeEscolhida) {
        throw std::invalid_argument("Erro: Cidade '" + std::string(1, letraCidade) + "' nao encontrada!");
    }
    std::string detalhesCaravanas = cidadeEscolhida->listarCaravanas();
    std::cout << detalhesCaravanas;*/


/*  char letraCidade;
    iss >> letraCidade;

// Ponteiro único para a cidade escolhida
    std::unique_ptr<Cidade> cidadeEscolhida = nullptr;

// Itera pelas cidades do simulador
    for (const auto& cidade : simulador->getCidade()) {
        if (cidade->getNome() == letraCidade) {
            // Cria um novo std::unique_ptr apontando para a cidade correspondente
            cidadeEscolhida = std::make_unique<Cidade>(*cidade); // Copia a cidade
            break;
        }
    }

// Verifica se a cidade foi encontrada
    if (!cidadeEscolhida) {
        throw std::invalid_argument("Erro: Cidade '" + std::string(1, letraCidade) + "' nao encontrada!");
    }

// Usa o ponteiro único para acessar os detalhes da cidade
    std::string detalhesCaravanas = cidadeEscolhida->listarCaravanas();
    std::cout << detalhesCaravanas;
*/
    std::ostringstream oss;
    return oss.str();
}

std::string Comandos::cmd_caravana(std::istringstream &iss){
    std::ostringstream oss;
    int numCaravana;
    iss >> numCaravana;
//    auto caravana = simulador->getCaravana(numCaravana);
//    if (caravana){
//        oss << caravana->exibirDetalhes();
//    }else{
//        oss << "Caravana nao encontrada"<< std::endl;
//    }
    return oss.str();
}

std::string Comandos::cmd_compra(std::istringstream &iss){
    std::ostringstream oss;
    int idCaravana, quantidadeMercadoria;
    iss >> idCaravana >> quantidadeMercadoria;

    try {
//        simulador->comprarMercadoria(idCaravana, quantidadeMercadoria, utils.atributosConfiguraveis.at("precoCompraMercadoria"));
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
//        simulador->venderMercadoria(idCaravana, utils.precoVendaMercadoria);
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

void Comandos::setMapaFicheiro(const std::string &linha)  {
    mapaFicheiro.push_back(linha);
}
std::vector<std::string>& Comandos::getMapaFicheiro(){
    return mapaFicheiro;
}
void Comandos::imprimirMapa(){
    std::cout << "Mapa do deserto:" << std::endl;
    for (auto& linha : getMapaFicheiro()) {
        std::cout << linha << std::endl;
    }
}

void Comandos::lerFicheiro(std::ifstream &ficheiro, int &linhas, int &colunas){
    if (!ficheiro.is_open()) {
        throw std::runtime_error("Erro: Não foi possível abrir o ficheiro.");
    }

    std::string palavra;
    ficheiro >> palavra >> linhas;
    ficheiro >> palavra >> colunas;
    ficheiro.ignore();

    // Verifica se as dimensões são válidas
    if (linhas <= 0 || colunas <= 0) {
        throw std::runtime_error("Dimensões inválidas no ficheiro (linhas ou colunas <= 0).");
    }

    // Ler o mapa do deserto
    std::string linha;
    for (int i = 0; i < linhas; ++i) {
        if (!std::getline(ficheiro, linha)) {
            throw std::runtime_error("Erro: não foi possível ler a linha do ficheiro");
        }
        if (linha.length() != colunas) {
            throw std::runtime_error("Erro no mapa: número de colunas incorreto");
        }

        setMapaFicheiro(linha);
    }
    imprimirMapa();

    // Le as configurações
    std::string linha_config;
    while (std::getline(ficheiro, linha_config)) {
        std::istringstream iss(linha_config);
        std::string chave;
        int valor;
        // Ler chave e valor de cada linha
        if (iss >> chave >> valor) {
            setAtributosConfiguraveis(chave,valor);
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
                    cmd_config(nomeFicheiro, linha, coluna);
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
            moedas = atributosConfiguraveis.at("moedas");
            preco_caravana = atributosConfiguraveis.at("preco_carvana");
            std::cout << "moedas" << moedas;
            std::cout << "preco_caravana" << preco_caravana;
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

void Comandos::setMoedas(int valor) {
    atributosConfiguraveis["moedas"] = valor;
}
void Comandos::setInstantesEntreNovosItens(int valor) {
    atributosConfiguraveis["instantes_entre_novos_itens"] = valor;
}
void Comandos::setDuracaoItem(int valor) {
    atributosConfiguraveis["duracao_item"] = valor;
}

void Comandos::setMaxItens(int valor) {
    atributosConfiguraveis["max_itens"] = valor;
}

void Comandos::setPrecoVendaMercadoria(int valor) {
    atributosConfiguraveis["preco_venda_mercadoria"] = valor;
}

void Comandos::setPrecoCompraMercadoria(int valor) {
    atributosConfiguraveis["preco_compra_mercadoria"] = valor;
}

void Comandos::setPrecoCaravana(int valor) {
    atributosConfiguraveis["preco_caravana"] = valor;
}

void Comandos::setInstantesEntreNovosBarbaros(int valor) {
    atributosConfiguraveis["instantes_entre_novos_barbaros"] = valor;
}
void Comandos::setDuracaoBarbaros(int valor) {
    atributosConfiguraveis["duracao_barbaros"] = valor;
}

void Comandos :: setAtributosConfiguraveis(const std::string chave, int valor) {
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
    */
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
    } else {
        std::cout << "Chave nao reconhecida: " << chave << std::endl;
    }
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



