#include "Simulador.h"
#include "Caravana.h"
class Cidade;
class Simulador;
class Montanha;
using namespace std;

class Comandos {

private:
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

//CPP
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

    Comandos::~Comandos() {
        delete bufferAtual;
        for (auto& pair : buffersSalvos) {
            delete pair.second;
        }
    }
