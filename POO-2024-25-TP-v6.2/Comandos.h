
    //
    // Created by Carolina Rosa on 10/11/2024.
    //

    #ifndef POO_2024_25_TP_COMANDOS_H
    #define POO_2024_25_TP_COMANDOS_H
    #include <string>
    #include <sstream>
    #include <iostream>
    #include <vector>
    #include<fstream>
    #include <map>
    #include <stdexcept>
    #include<iterator>

    #include "Simulador.h"
    #include "Caravana.h"

#include "Deserto.h"
    class Cidade;
    class Simulador;
    class Montanha;
    using namespace std;

    class Comandos {

    private:

        Buffer* bufferAtual;
        map<string, Buffer*> buffersSalvos;
        char** mapa; //DESTRUIR
        vector<shared_ptr<Cidade>> cidades;
        shared_ptr<Montanha>montanha;
        shared_ptr<Simulador> simulador;
        std::map<std::string, int> atributosConfiguraveis;

        int linhas=10, colunas=20;
        int moedas, instantesEntreNovosItens, duracaoItem, maxItens;
        int precoCaravana, precoCompraMercadoria, precoVendaMercadoria;
        int instantesEntreNovosBarbaros, duracaoBarbaros;
        int fase; // 1 para Fase 1, 2 para Fase 2

    public:

        Comandos(int linhas, int colunas);
        ~Comandos();
        Comandos(); // Construtor
        void limparDados();

        void processaMapa();
        bool validarArgumentos(const string &cmd);
        void executarComando(const string &comando); // Método para execução de comandos
        void mostrarConfig() const;

        int calcularPontuacao() const;
        void barbaro(istringstream &iss);

    //Acho que é no simulador
    // Métodos para adicionar cidades e caravanas
    /*void adicionarCidade(Cidade cidade);
    void adicionarCaravana(Caravana* caravana);*/

        // Comandos da Fase 1
        void lerConfiguracao(const string &nomeFicheiro);
        void sair();

        // Comandos da Fase 2
        void exec(istringstream &iss);
        void prox(istringstream &iss);
        void comprac(std::istringstream& iss, int precoCaravana);// implementar a "logica" no simulador
        void terminar();
        void saves(istringstream& iss);
        void loads(istringstream& iss);
        void lists();
        void dels(istringstream& iss);
        void adicionaMoedas(istringstream& iss);
        void limparMapa();
        void mostrarMapa() const;
        void atualizaMapa();
        string listarPrecos();
        void mostrarDetalhesCaravana(istringstream& iss);
        void listarCaravanasCidade(std::istringstream &iss);
        void tripul(istringstream& iss);
        void areia(istringstream &iss);
        void compra(istringstream &iss);
        void vende(istringstream &iss);
        void move(istringstream &iss);
        void autoGestao(istringstream &iss);
        void stop(istringstream &iss);



    };
#endif //POO_2024_25_TP_COMANDOS_H

