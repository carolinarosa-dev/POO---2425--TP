//
// Created by Carolina Rosa on 09/11/2024.
//

#include "Buffer.h"
#include <iostream>

#include "sstream"

Buffer::Buffer(int linhas, int colunas) : linhas(linhas), colunas(colunas), cursorLinha(0), cursorColuna(0) {
    // Alocação dinâmica de memória
    buffer = new char*[linhas];
    for (int i = 0; i < linhas; ++i) {
        buffer[i] = new char[colunas];
    }
    esvaziar();
}


Buffer::~Buffer() {
    // Libertar memória alocada
    for (int i = 0; i < linhas; ++i) {
        delete[] buffer[i];
    }
    delete[] buffer;
}

void Buffer::esvaziar() {
    // Preencher o buffer com espaços
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            buffer[i][j] = '-';
        }
    }
    cursorLinha = 0;
    cursorColuna = 0;
}



void Buffer::transcreverParaConsola() {
    // Imprimir o conteúdo do buffer na consola
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            std::cout << buffer[i][j];
        }
        std::cout << std::endl;
    }
}


void Buffer::moverCursor(int linha, int coluna) {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
        cursorLinha = linha;
        cursorColuna = coluna;
    }
}



void Buffer::imprimir(char c) {
    if (cursorLinha >= 0 && cursorLinha < linhas && cursorColuna >= 0 && cursorColuna < colunas) {
        buffer[cursorLinha][cursorColuna] = c;
        cursorColuna++;
        if (cursorColuna >= colunas) {
            cursorColuna = 0;
            cursorLinha++;
        }
    }
}


void Buffer::imprimir(const std::string& str) {
    for (char c : str) {
        imprimir(c);
    }
}


void Buffer::imprimir(int num) {
    std::ostringstream oss;
    oss << num;
    imprimir(oss.str());
}


// Implementação da sobrecarga do operador <<
std::ostream& operator<<(std::ostream& os, const Buffer& buf) { //funçao global
    for (int i = 0; i < buf.linhas; ++i) {
        for (int j = 0; j < buf.colunas; ++j) {
            os << buf.buffer[i][j];
        }
        os << '\n';  // Nova linha após cada linha do buffer
    }
    return os;

}

int Buffer::getLinhas() const {
    return linhas;
}

void Buffer::setLinhas(int linhas) {
    this->linhas = linhas;
}

int Buffer::getColunas() const {
    return colunas;
}

void Buffer::setColunas(int colunas) {
    this->colunas = colunas;
}

char Buffer::getPosicao(int linha, int coluna)const{
    return buffer[linha][coluna];
}



