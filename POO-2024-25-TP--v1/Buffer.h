//
// Created by Carolina Rosa on 09/11/2024.
//

#ifndef POO_2024_25_TP_BUFFER_H
#define POO_2024_25_TP_BUFFER_H

#include <iostream>



    class Buffer {
    public:
        // Construtor e destrutor
        Buffer(int linhas, int colunas);  // Inicializa o buffer com o número de linhas e colunas fornecido
        ~Buffer();                       // Libera memória alocada dinamicamente

        // Métodos principais
        void esvaziar();                 // Limpa o buffer, preenchendo com espaços
        void transcreverParaConsola();   // Imprime o conteúdo do buffer na consola
        void moverCursor(int linha, int coluna); // Move o cursor para uma posição específica (linha, coluna)
        void imprimir(char c);           // Imprime um único caractere na posição do cursor
        void imprimir(const std::string& str); // Imprime uma string a partir da posição do cursor
        void imprimir(int num);          // Imprime um número inteiro a partir da posição do cursor

        // Operador de saída para facilitar a transcrição do buffer
        // Declaração da função friend para a sobrecarg
        friend std::ostream& operator<<(std::ostream& os, const Buffer& buf);

    private:
        int linhas;                      // Número de linhas do buffer
        int colunas;                     // Número de colunas do buffer
        char** buffer;                   // Matriz bidimensional que armazena o conteúdo do buffer
        int cursorLinha;                 // Linha atual do cursor
        int cursorColuna;                // Coluna atual do cursor
    };


#endif //POO_2024_25_TP_BUFFER_H






