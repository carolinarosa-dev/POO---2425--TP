
#include "Comandos.h"

#include <fstream> //ficheiro

void Comandos::cmd_config(const std::string &nomeFicheiro){
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

std::string Comandos::cmd_sair() const {
    std::ostringstream oss;
    oss << "Implementar - Saindo do programa...\n";
    return oss.str();
}

std::string Comandos::cmd_exec(std::istringstream &iss) const {
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
    std::string linha;
    while (getline(ficheiro, linha)) {
        executarComando(linha);
    }
    ficheiro.close();
    oss << "Comandos do ficheiro " << nomeFicheiro << " executados com sucesso!" << std::endl;

    return oss.str();
}

std::string Comandos::cmd_prox(std::istringstream &iss) const {
    std::ostringstream oss;
    int n = 1; // Valor padrão
    iss >> n;
    if (n <= 0) {
        oss << "Numero de instantes deve ser maior que 0!\n";
        return oss.str();
    }
    for (int i = 0; i < n; ++i) {
        // adicionar a lógica para atualizar o estado da simulação a cada instante
        oss << "Avancando instante " << (i + 1) << " de " << n << std::endl;
        oss << "\n\n\n\n\nAtualizar o estado da simulação chamando Simulacao::atualizarEstado\n\n\n\";
        // simulador.atualizarEstado(); // 'simulacao' é uma instância da classe Simulacao
        // Exibir o mapa e outras informações relevantes
        mostrarConfig();
    }
    return oss.str();
}

void Comandos::cmd_comprac(std::istringstream &iss, int precoCaravana) {
    char cidadeNome;
    char tipoCaravana;
    //char tipoCaravanaChar;

    // Lê a cidade, o número da caravana e o tipo da caravana
    iss >> cidadeNome >> tipoCaravana;
    // Chama a função do simulador para adicionar a caravana
    simulador->adicionaCaravanaJogador(cidadeNome, tipoCaravana, precoCaravana);

}

std::string Comandos::cmd_precos() const {
    std::ostringstream oss;
    oss << "Precos das mercadorias:"
        << "\nPreco de venda: " << atributosConfiguraveis.at("precoVendaMercadoria") << " moedas"
        << "\nPreco de compra: " << atributosConfiguraveis.at("precoCompraMercadoria") << " moedas" << std::endl;
    return oss.str();
}

std::string Comandos::cmd_cidade(std::istringstream &iss) const {
    std::ostringstream oss;
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
    oss << detalhesCaravanas;
    return oss.str();
}

std::string Comandos::cmd_caravana(std::istringstream &iss) const {
    std::ostringstream oss;
    int numCaravana;
    iss >> numCaravana;
    auto caravana = simulador->getCaravana(numCaravana);
    if (caravana){
        oss << caravana->exibirDetalhes();
    }else{
        oss << "Caravana nao encontrada"<< std::endl;
    }
    return oss.str();
}

std::string Comandos::cmd_compra(std::istringstream &iss) const {
    std::ostringstream oss;
    int idCaravana, quantidadeMercadoria;
    iss >> idCaravana >> quantidadeMercadoria;

    try {
        simulador->comprarMercadoria(idCaravana, quantidadeMercadoria, atributosConfiguraveis.at("precoCompraMercadoria"));
    } catch (const std::exception &e) {
        oss << "Erro ao comprar mercadorias: " << e.what() << std::endl;
    }
    return oss.str();
}

std::string Comandos::cmd_vende(std::istringstream &iss) const {
    std::ostringstream oss;
    int idCaravana;
    iss >> idCaravana;

    try {
        simulador->venderMercadoria(idCaravana, precoVendaMercadoria);
        oss<< "Vendida toda a mercadoria da caravana " << idCaravana << "." << std::endl;
    } catch (const std::exception &e) {
        oss << "Erro ao vender mercadorias: " << e.what() << std::endl;
    }
    return oss.str();
}

std::string Comandos::cmd_move(std::istringstream &iss) const {
    std::ostringstream oss;
    int idCaravana;
    std::string direcao;
    iss >> idCaravana >> direcao;

    try {
        simulador->moverCaravana(idCaravana, direcao, mapa);
        oss << "Caravana " << idCaravana << " movida na direcao " << direcao << "." << std::endl;
    } catch (const std::exception &e) {
        oss << "Erro ao mover a caravana: " << e.what() << std::endl;
    }
    atualizaMapa();
    return oss.str();
}

std::string Comandos::cmd_auto(std::istringstream &iss) const {
    std::ostringstream oss;
    int idCaravana;
    iss >> idCaravana;

    try {
        simulador->ativarAutoGestao(idCaravana);
        oss << "Caravana " << idCaravana << " colocada em auto-gestao." << std::endl;
    } catch (const std::exception &e) {
        oss << "Erro ao ativar auto-gestao: " << e.what() << std::endl;
    }
    return oss.str();
}

std::string Comandos::cmd_stop(std::istringstream &iss) const {
    std::ostringstream oss;
    int idCaravana;
    iss >> idCaravana;

    try {
        simulador->desativarAutoGestao(idCaravana);
        oss << "Caravana " << idCaravana << " parou o comportamento automatico." << std::endl;
    } catch (const std::exception &e) {
        oss << "Erro ao parar o comportamento automatico: " << e.what() << std::endl;
    }
    return oss.str();
}
std::string Comandos::cmd_barbaro(std::istringstream &iss) const {
    std::ostringstream oss;
    int linha, coluna;
    iss >> linha >> coluna;
    try {
        simulador->criarCaravanaBarbara(linha, coluna);
        //std::cout << "Caravana barbara criada nas coordenadas (" << linha << ", " << coluna << ")." << std::endl;
    } catch (const std::exception &e) {
        oss << "Erro ao criar caravana barbara: " << e.what() << std::endl;
    }
    return oss.str();
}

std::string Comandos::cmd_areia(std::istringstream &iss) const {
    std::ostringstream oss;
    int linha, coluna, raio;
    iss >> linha >> coluna >> raio;

    try {
        simulador->provocarTempestade(linha, coluna, raio);
        oss << "Tempestade de areia criada na posicao (" << linha << ", " << coluna << ") com raio " << raio << "." << std::endl;
    } catch (const std::exception &e) {
        oss << "Erro ao criar tempestade de areia: " << e.what() << std::endl;
    }
    return oss.str();
}

std::string Comandos::cmd_moedas(std::istringstream &iss) const {
    std::ostringstream oss;
    int n;
    iss >> n;
    jogador.moedas += n;
    oss << "Moedas atualizadas: " << jogador.moedas << std::endl;
    return oss.str();
}

std::string Comandos::cmd_tripul(std::istringstream &iss) const {
    std::ostringstream oss;
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
                oss << "Adicionados " << quantidadeTripulantes << " tripulantes a caravana " << idCaravana << "." << std::endl;
            } else {
                throw std::runtime_error("A caravana nao esta em uma cidade.");
            }
        } else {
            throw std::runtime_error("Caravana com ID nao encontrada.");
        }
    } catch (const std::exception &e) {
        oss << "Erro: " << e.what() << std::endl;
    }
    return oss.str();
}
std::string Comandos::cmd_saves(std::istringstream &iss) const {
    std::ostringstream oss;
    std::string nome;
    iss >> nome;
    if (nome.empty()) {
        oss << "Nome nao especificado!" << std::endl;
        return oss.str();
    }

    buffersSalvos[nome] = new Buffer(*bufferAtual);
    oss << "Estado do buffer salvo com o nome: " << nome << std::endl;

    return oss.str();
}

std::string Comandos::cmd_loads(std::istringstream &iss) const {
    std::ostringstream oss;
    std::string nome;
    iss >> nome;
    if (nome.empty()) {
        oss << "Nome nao especificado!" << std::endl;
        return oss.str();
    }
    auto it = buffersSalvos.find(nome);
    if (it != buffersSalvos.end()) {
        oss << "Carregando estado do buffer com o nome: " << nome << std::endl << *(it->second);
    } else {
        oss << "Nenhum buffer salvo com o nome: " << nome << std::endl;
    }
    return oss.str();
}
std::string Comandos::cmd_lists() const {
    std::ostringstream oss;
    if (buffersSalvos.empty()) {
        oss << "Nenhum buffer salvo." << std::endl;
    } else {
        oss << "Buffers salvos:" << std::endl;
        for (const auto& pair : buffersSalvos) {
            std::cout << pair.first << std::endl;
        }
    }
    return oss.str();
}

std::string Comandos::cmd_dels(std::istringstream &iss) const {
    std::ostringstream oss;
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
        oss << "Buffer com o nome " << nome << " apagado." << std::endl;
    } else {
        oss << "Nenhum buffer salvo com o nome: " << nome << std::endl;
    }
    return oss.str();
}

std::string Comandos::cmd_terminar() const {
    std::ostringstream oss;
    // Calcular e exibir a pontuação
    int pontuacao = calcularPontuacao();
    oss << "Simulacao terminada!\n"
        << "Pontuacao final: " << pontuacao << std::endl;

    simualdor.fase = 1;
    utils.limparDados();
    oss << "Esta de volta a fase 1. Pode iniciar uma nova simulacao ou sair do programa." << std::endl;
    return oss.str();
}
