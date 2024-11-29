//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Comandos.h"

Comandos::Comandos(int linhas, int colunas) {
    bufferAtual = new Buffer(linhas, colunas);
}

// Construtor
Comandos::Comandos() : linhas(0), colunas(0), moedas(0),
                       instantesEntreNovosItens(0), duracaoItem(0),
                       maxItens(0), precoVendaMercadoria(0),
                       precoCompraMercadoria(0), precoCaravana(0),
                       instantesEntreNovosBarbaros(0), duracaoBarbaros(0) {}

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

    // Ler parâmetros configuráveis
    while (ficheiro >> linha) {
        if (linha == "moedas")
            ficheiro >> moedas;
        else if (linha == "instantes_entre_novos_itens")
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


void Comandos::executarComando(const string &comando) {
    istringstream iss(comando);
    string cmd;
    iss >> cmd;

    if (cmd == "config") {
        config(iss);
    } else if (cmd == "sair") {
        sair();
    } else if (cmd == "exec") {
        exec(iss);
    } else if (cmd == "prox") {
        prox(iss);
    } else if (cmd == "comprac") {
        // comprac(iss);
    } else if (cmd == "precos") {
        listarPrecos();
    }else if (cmd == "cidade") {
//            listarCaravanasCidade(iss);
        } else if (cmd == "caravana") {
//            mostrarDetalhesCaravana(iss);
    } else if (cmd == "moedas") {
        adicionaMoedas(iss);
    } else if (cmd == "tripul") {
        // tripul(iss);
    }else if (cmd == "saves") {
        saves(iss);
    } else if (cmd == "loads") {
        loads(iss);
    } else if (cmd == "lists") {
        lists();
    } else if (cmd == "dels") {
        dels(iss);
    }else if (cmd == "terminar") {
        terminar();
    } else {
        cout << "Comando desconhecido: " << cmd << endl;
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


void Comandos::listarPrecos() {
    cout << "Preços das mercadorias:" << endl;
    cout << "Preço de venda: " << precoVendaMercadoria << " moedas" << endl;
    cout << "Preço de compra: " << precoCompraMercadoria << " moedas" << endl;
}


// Adiciona uma cidade ao vetor de cidades
/*
void Comandos::adicionarCidade(Cidade cidade) {
    cidades.push_back(cidade);
}

// Adiciona uma caravana ao vetor de caravanas
void Comandos::adicionarCaravana(Caravana* caravana) {
    caravanas.push_back(caravana);
}
*/

// Lista as caravanas presentes numa cidade
/*void Comandos::listarCaravanasCidade(std::istringstream &iss) {
    char cidadeNome;
    iss >> cidadeNome;*/

    // Procura pela cidade no vetor
/*    bool cidadeEncontrada = false;
    for (const auto& cidade : cidades) {
        if (cidade.getNome() == cidadeNome) {
            cidadeEncontrada = true;
            cidade.listarCaravanas();  // Chama a função para listar caravanas na cidade
            break;
        }
    }*/
/*
    if (!cidadeEncontrada) {
        std::cout << "Cidade não encontrada!" << std::endl;
    }
}*/

// Exibe detalhes de uma caravana
/*
void Comandos::mostrarDetalhesCaravana(std::istringstream &iss) {
    int idCaravana;
    iss >> idCaravana;

    // Procura pela caravana no vetor
    bool caravanaEncontrada = false;
    for (const auto& caravana : caravanas) {
        if (caravana->getId() == idCaravana) {
            caravanaEncontrada = true;
            caravana->exibirDetalhes();  // Chama a função para exibir detalhes da caravana
            break;
        }
    }

    if (!caravanaEncontrada) {
        std::cout << "Caravana não encontrada!" << std::endl;
    }
}
*/





/*
void Comandos::tripul(std::istringstream& iss) {
    int n, t;
    iss >> n >> t;
    if (iss.fail() || n <= 0 || t <= 0) {
        std::cerr << "Erro: valores inválidos para caravana ou tripulantes." << std::endl;
        return;
    }

    for (auto& caravana : caravanas) {
        if (caravana.getId() == n) {
            if (caravana.estaEmCidade()) {
                caravana.adicionarTripulantes(t);
                std::cout << "Adicionados " << t << " tripulantes à caravana " << n << "." << std::endl;
            } else {
                std::cerr << "Erro: a caravana " << n << " não está em uma cidade." << std::endl;
            }
            return;
        }
    }
    std::cerr << "Erro: caravana " << n << " não encontrada." << std::endl;
}

*/

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
   /* for (auto& cidadeAtual : cidades) { // Supondo que 'cidades' é um vetor de cidades
        if(auto obj = cidadeAtual.lock())
        if (obj->getNome() == cidadeNome) {
            cidade = cidadeAtual;
            break;
        }
    }*/

    if (!cidade.lock()) {
        //gerar execções
        //cout << "Cidade " << cidadeNome << " não encontrada!" << endl;
        return; // Se a cidade não for encontrada
    }

    //chamar o simudador
}
