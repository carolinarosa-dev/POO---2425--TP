//
// Created by Carolina Rosa on 09/11/2024.
//

#ifndef POO_2024_25_TP_BUFFER_H
#define POO_2024_25_TP_BUFFER_H

#include <iostream>


class Buffer {


public:
    Buffer(int linhas, int colunas);
    ~Buffer();

    void esvaziar();
    void transcreverParaConsola();
    void moverCursor(int linha, int coluna);
    void imprimir(char c);
    void imprimir(const std::string& str);
    void imprimir(int num);

    // Declaração da função friend para a sobrecarga
    friend std::ostream& operator<<(std::ostream& os, const Buffer& buf);

    int linhas;
    int colunas;
    char** buffer;
    int cursorLinha, cursorColuna;
};

#endif //POO_2024_25_TP_BUFFER_H






