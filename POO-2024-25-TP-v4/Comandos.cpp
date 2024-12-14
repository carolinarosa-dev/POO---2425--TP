//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Comandos.h"
#include "Cidade.h"
#include "Caravana.h"
#include "CaravanaComercio.h"
#include "CaravanaMilitar.h"
#include "CaravanaSecreta.h"

Comandos::Comandos(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    bufferAtual = new Buffer(linhas, colunas);
    simulador = std::make_shared<Simulador>(linhas, colunas, bufferAtual);

}



// Construtor
Comandos::Comandos() : linhas(0), colunas(0), moedas(0),
                       instantesEntreNovosItens(0), duracaoItem(0),
                       maxItens(0), precoVendaMercadoria(0),
                       precoCompraMercadoria(0), precoCaravana(0),
                       instantesEntreNovosBarbaros(0), duracaoBarbaros(0) {
    simulador = nullptr;
}

void Comandos::limparDados() {
    linhas = colunas = moedas = 0;
    instantesEntreNovosItens = duracaoItem = maxItens = 0;
    precoVendaMercadoria = precoCompraMercadoria = precoCaravana = 0;
    instantesEntreNovosBarbaros = duracaoBarbaros = 0;
    mapa.clear();
}

void Comandos::lerConfiguracao(const string &nomeFicheiro) {
    ifstream ficheiro(nomeFicheiro);
    if (!ficheiro.is_open()) {
        cerr << "Erro ao abrir o ficheiro: " << nomeFicheiro << endl;
        return;
    }

    limparDados();
    string linha;

    // Ler dimensões
    ficheiro >> linha >> linhas;
    ficheiro >> linha >> colunas;
    ficheiro.ignore(); // Ignorar o newline após a leitura das dimensões

    // Ler o mapa do deserto
    for (int i = 0; i < linhas; ++i) {
        getline(ficheiro, linha);
        if (linha.length() != colunas) {
            cerr << "Erro: o tamanho da linha do mapa não corresponde ao número de colunas." << endl;
            return;
        }
        mapa.push_back(linha);
    }
    processaMapa();
    // Ler parâmetros configuráveis
    while (ficheiro >> linha) {
        if (linha == "moedas") {
            ficheiro >> moedas;
            simulador->getJogador()->adicionarMoedas(moedas);
        }else if (linha == "instantes_entre_novos_itens")
            ficheiro >> instantesEntreNovosItens;
        else if (linha == "duração_item")
            ficheiro >> duracaoItem;
        else if (linha == "max_itens")
            ficheiro >> maxItens;
        else if (linha == "preço_venda_mercadoria")
            ficheiro >> precoVendaMercadoria;
        else if (linha == "preço_compra_mercadoria")
            ficheiro >> precoCompraMercadoria;
        else if (linha == "preço_caravana")
            ficheiro >> precoCaravana;
        else if (linha == "instantes_entre_novos_barbaros")
            ficheiro >> instantesEntreNovosBarbaros;
        else if (linha == "duração_barbaros")
            ficheiro >> duracaoBarbaros;
    }

    ficheiro.close();
    cout << "Configuração lida com sucesso!" << endl;

}
void Comandos::processaMapa() {
    for (int linha = 0; linha < mapa.size(); ++linha) {
        for (int coluna = 0; coluna < mapa[linha].size(); ++coluna) {
            char caractere = mapa[linha][coluna];

            if (isalpha(caractere)) { // Se for uma letra (cidade)
                auto novaCidade = std::make_shared<Cidade>(caractere, linha, coluna);
                if (!novaCidade) {
                    cerr << "Erro ao criar a cidade '" << caractere << "'.\n";
                    continue;  // Avançar para o próximo caractere
                }
                simulador->adicionarCidade(novaCidade);

            } else if (isdigit(caractere) && caractere != '0') { // Se for um número (caravana)
                cout << "na posição (" << linha << ", " << coluna << ")\n";

                //simulador->adicionaCaravanaJogador(make_shared<Caravana>(caractere, linha, coluna));
            } else if (caractere == '+'){ // Se for uma montanha
                //cout << "Montanha na posição (" << linha << ", " << coluna << ")\n";
            } else if (caractere == '.') { // uma posição vazia
                //cout << "Posição vazia (" << linha << ", " << coluna << ")\n";
            } else if (caractere == '!') { // caravana barbara
                //simulador->adicionaCaravanaBarbara(make_shared<CaravanaBarbara>(caractere, linha, coluna));
            }else {
                cerr << "Caractere desconhecido '" << caractere << "' na posição ("
                     << linha << ", " << coluna << ")\n";
            }
        }
    }
}

void Comandos::executarComando(const string &comando) {
    istringstream iss(comando);
    string cmd;
    iss >> cmd;
    try {
        if (cmd == "config") {
            config(iss);
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
        } else if (cmd == "barbaro") {
            criarCaravanaBarbara(iss);
        } else if (cmd == "moedas") {
            adicionaMoedas(iss);
        } else if (cmd == "tripul") {
            // tripul(iss);
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
        } else {
            std::cout << "Comando desconhecido: " << cmd << std::endl;
        }
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
}


void Comandos::config(istringstream &iss) {
    string nomeFicheiro;
    iss >> nomeFicheiro;
    if (nomeFicheiro.empty()) {
        cerr << "Nome de ficheiro não especificado!" << endl;
        return;
    }
    lerConfiguracao(nomeFicheiro);
    mostrarConfig();
}

void Comandos::sair() {
    cout << "Saindo do programa..." << endl;
}

void Comandos::mostrarConfig() const {
    cout << "Linhas: " << linhas << endl;
    cout << "Colunas: " << colunas << endl;
    cout << "Mapa do deserto:" << endl;
    for (const auto &linha: mapa) {
        cout << linha << endl;
    }
    cout << "Moedas: " << moedas << endl;
    cout << "Instantes entre novos itens: " << instantesEntreNovosItens << endl;
    cout << "Duração do item: " << duracaoItem << endl;
    cout << "Máximo de itens: " << maxItens << endl;
    cout << "Preço de venda de mercadoria: " << precoVendaMercadoria << endl;
    cout << "Preço de compra de mercadoria: " << precoCompraMercadoria << endl;
    cout << "Preço da caravana: " << precoCaravana << endl;
    cout << "Instantes entre novos bárbaros: " << instantesEntreNovosBarbaros << endl;
    cout << "Duração dos bárbaros: " << duracaoBarbaros << endl;
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
        cerr << "Número de instantes deve ser maior que 0!" << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        // adicionar a lógica para atualizar o estado da simulação a cada instante
        cout << "Avançando instante " << (i + 1) << " de " << n << endl;

        // Atualizar o estado da simulação chamando Simulacao::atualizarEstado
        // simulador.atualizarEstado(); // 'simulacao' é uma instância da classe Simulacao
        // Exibir o mapa e outras informações relevantes
        mostrarConfig();
    }
}




void Comandos::terminar() {
    // Calcular e exibir a pontuação
    int pontuacao = calcularPontuacao();
    cout << "Simulação terminada!" << endl;
    cout << "Pontuação final: " << pontuacao << endl;

    fase = 1;
    limparDados();
    cout << "Está de volta à fase 1. Pode iniciar uma nova simulação ou sair do programa." << endl;
}

int Comandos::calcularPontuacao() const {
    // Exemplo de cálculo de pontuação (ajuste conforme necessário)
    int pontuacao = moedas;
    return pontuacao;
}


Comandos::~Comandos() {
    delete bufferAtual;
//    delete simulador;
    for (auto& pair : buffersSalvos) {
        delete pair.second;
    }
}

void Comandos::saves(std::istringstream& iss) {
    std::string nome;
    iss >> nome;
    if (nome.empty()) {
        std::cerr << "Nome não especificado!" << std::endl;
        return;
    }

    buffersSalvos[nome] = new Buffer(*bufferAtual);
    std::cout << "Estado do buffer salvo com o nome: " << nome << std::endl;
}

void Comandos::loads(std::istringstream& iss) {
    std::string nome;
    iss >> nome;
    if (nome.empty()) {
        std::cerr << "Nome não especificado!" << std::endl;
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
        std::cerr << "Nome não especificado!" << std::endl;
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


/*void Comandos::listarPrecos() {
    cout << "Preços das mercadorias:" << endl;
    cout << "Preço de venda: " << precoVendaMercadoria << " moedas" << endl;
    cout << "Preço de compra: " << precoCompraMercadoria << " moedas" << endl;
}*/

string Comandos::listarPrecos() {
    ostringstream oss;
    oss << "Preços das mercadorias:" << std::endl;
    oss << "Preço de venda: " << precoVendaMercadoria << " moedas" << std::endl;
    oss << "Preço de compra: " << precoCompraMercadoria << " moedas" << std::endl;
    return oss.str();
}

/*void Comandos::listarCaravanasCidade(std::istringstream &iss){
    char letraCidade;
    iss >> letraCidade;
    shared_ptr<Cidade> cidadeEscolhida = nullptr;
    for (const auto& cidade : simulador->getCidades()) {
        if (cidade->getNome() == letraCidade) {
            cidadeEscolhida = cidade;
            break;
        }
    }

    if (!cidadeEscolhida) {
        throw std::invalid_argument("Cidade não encontrada!");
    }

    cidadeEscolhida->listarCaravanas();

}*/

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
        throw std::invalid_argument("Erro: Cidade '" + std::string(1, letraCidade) + "' não encontrada!");
    }

    std::string detalhesCaravanas = cidadeEscolhida->listarCaravanas();
    std::cout << detalhesCaravanas;
}

void Comandos::criarCaravanaBarbara(std::istringstream &iss) {
    int linha, coluna;
    iss >> linha >> coluna;
    simulador->criarCaravanaBarbara(linha, coluna);
}


/*


void Comandos::comprac(istringstream& iss) {
    char cidadeNome;
    int tipoCaravanaNum;  // Tipo da caravana (número de 0 a 9)

    // Lê a cidade e o número da caravana
    iss >> cidadeNome >> tipoCaravanaNum;

    // Verifica se o número da caravana está dentro do intervalo esperado (1 a 9)
    if (tipoCaravanaNum < 0 || tipoCaravanaNum > 9) {
        //gerar execções
        cout << "Número de caravana inválido! Deve ser de 0 a 9." << endl;
        return;
    }

    // Encontra a cidade correspondente
    weak_ptr<Cidade> cidade;
 for (auto& cidadeAtual : cidades) { // Supondo que 'cidades' é um vetor de cidades
        if(auto obj = cidadeAtual.lock())
        if (obj->getNome() == cidadeNome) {
            cidade = cidadeAtual;
            break;
        }
    }

    if (!cidade.lock()) {
        //gerar execções
        //cout << "Cidade " << cidadeNome << " não encontrada!" << endl;
        return; // Se a cidade não for encontrada
    }
    //simulador.adicionaCaravanaJogador();
    //chamar o simudador
}
*/


void Comandos::comprac(std::istringstream& iss, int precoCaravana) {
    char cidadeNome;
    char tipoCaravana;
    //char tipoCaravanaChar;

    // Lê a cidade, o número da caravana e o tipo da caravana
    iss >> cidadeNome >> tipoCaravana;

    // Verifica se o número da caravana está dentro do intervalo esperado (0 a 9)
    // if (tipoCaravanaNum < 0 || tipoCaravanaNum > 9) {
    //     throw std::invalid_argument("Número de caravana inválido! Deve ser de 0 a 9.");
    // } Isto não estava a fazer sentido neste ponto, uma vez que o comando é (por exemplo): comprac a T, indicando a caravana por tipo e não por número

    // Chama a função do simulador para adicionar a caravana
    simulador->adicionaCaravanaJogador(cidadeNome, tipoCaravana, precoCaravana);
}

/*
void Comandos::comprac(std::istringstream& iss, int precoCaravana) {
    char cidadeNome;
    char tipoCaravana;

    // Lê a cidade e o tipo da caravana
    iss >> cidadeNome >> tipoCaravana;

    try {
        if (Caravana::getProximoId() > 9) {
            throw std::runtime_error("Número máximo de caravanas atingido.");
        }

        std::shared_ptr<Caravana> novaCaravana;
        if (tipoCaravana == 'C') {

            novaCaravana = std::make_shared<CaravanaComercio>(cidadeNome, precoCaravana);
        } else if (tipoCaravana == 'M') {
            novaCaravana = std::make_shared<CaravanaMilitar>(cidadeNome, precoCaravana);
        } else if (tipoCaravana == 'S') {
            novaCaravana = std::make_shared<CaravanaSecreta>(cidadeNome, precoCaravana);
        } else {
            throw std::invalid_argument("Tipo de caravana desconhecido.");
        }

        simulador->adicionaCaravanaJogador(novaCaravana);
        std::cout << "Caravana do tipo " << tipoCaravana << " comprada na cidade " << cidadeNome << "." << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Erro ao comprar caravana: " << e.what() << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}
*/

void Comandos::mostrarDetalhesCaravana(istringstream &iss) {
    char tipoCaravana;
    iss >> tipoCaravana;

    Caravana::Tipo tipo;
    Caravana* caravana;
    switch (tipoCaravana) {
        case 'C':
           // caravana = new CaravanaComercio();
            cout << caravana->exibirDetalhes();
            break;
        case 'M':
            tipo = Caravana::MILITAR;
            break;
        case 'S':
            tipo = Caravana::SECRETA;
            break;
        default:
            throw std::invalid_argument("Tipo inválido de caravana!");
    }


}