//
// Created by Carolina Rosa on 09/11/2024.
//

#include "Buffer.h"
#include <iostream>
#include <iomanip>
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
    } else {
        // Opcional: Adicionar mensagem para indicar erro.
        std::cerr << "Erro: Coordenadas fora dos limites do buffer." << std::endl;
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


/*void Buffer::imprimir(int num) {
    std::ostringstream oss;
    oss << num;
    imprimir(oss.str());
}*/


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



void Buffer::imprimir(int num) {
    // Caso especial para 0
    if (num == 0) {
        imprimir('0');
        return;
    }

    char temp[12]; // Array temporário para armazenar o número (int suporta até 10 dígitos, mais sinal)
    int i = 0;
    bool negativo = false;

    // Gerir números negativos
    if (num < 0) {
        negativo = true;
        num = -num; // Tornar positivo para processar os dígitos
    }

    // Extrair dígitos em ordem inversa
    while (num > 0) {
        temp[i++] = '0' + (num % 10); // Converter o último dígito para char
        num /= 10;
    }

    // Adicionar o sinal de negativo, se aplicável
    if (negativo) {
        temp[i++] = '-';
    }

    // Imprimir os caracteres na ordem correta
    while (i > 0) {
        imprimir(temp[--i]);
    }
}



// Para imprimir diretamente no buffer
Buffer& operator<<(Buffer& buf, char c) {
    buf.imprimir(c);
    return buf;
}

Buffer& operator<<(Buffer& buf, const std::string& str) {
    for (char c : str) {
        buf.imprimir(c);
    }
    return buf;
}

Buffer& operator<<(Buffer& buf, int num) {
    buf.imprimir(num);
    return buf;
}






