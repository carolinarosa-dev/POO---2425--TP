//
// Created by Carolina Rosa on 10/11/2024.
//

#include "Comandos.h"


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









