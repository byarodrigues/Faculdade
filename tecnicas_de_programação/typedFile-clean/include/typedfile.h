#ifndef TYPEDFILE_H
#define TYPEDFILE_H

#include <fstream>
#include <type_traits>
#include "header.h"
#include "record.h"
using namespace std;

const ios::openmode mode = ios::in | ios::out | ios::binary;

template <class T>
class typedFile : private fstream {
   static_assert(is_base_of<serializable, T>::value, "T must be serializable");
   public:
      typedFile();
      typedFile(const string name, const string type, const unsigned int version, ios::openmode openmode = mode);
      virtual ~typedFile();
      bool open(const string name, const string type, const unsigned int version, ios::openmode openmode = mode);
      bool isOpen();
      bool close();
      bool clear();
      bool readRecord(record<T> &r, unsigned long long int i);
      bool writeRecord(record<T> &r, unsigned long long int i);
      bool insertRecord(record<T> &r);
      bool deleteRecord(unsigned long long int i);
      unsigned long long int getFirstValid();
      unsigned long long int getFirstDeleted();
      unsigned long long int search(T data);
   protected:
      header head;
      bool readHeader(header &h);
      bool writeHeader(header &h);
      unsigned long long int index2pos(unsigned long long int i);
      unsigned long long int pos2index(unsigned long long int p);
};

template <class T>
typedFile<T>::typedFile() : fstream() {
    // Inicializa��o adicional, se necess�rio
    // Exemplo: Defina alguns valores padr�o ou realize outras opera��es de inicializa��o

    // Se necess�rio, adicione inicializa��es ou l�gica espec�fica do construtor aqui
}

template <class T>
typedFile<T>::typedFile(const string name, const string type, const unsigned int ver, ios::openmode openmode)
    : fstream(name.c_str(), openmode) {
    if (!is_open()) {
        cerr << "Error opening file: " << name << endl;

        if (bad()) {
            cerr << "Error flags are set: badbit" << endl;
        }
        if (fail()) {
            cerr << "Error flags are set: failbit" << endl;
        }
        if (eof()) {
            cerr << "Error flags are set: eofbit" << endl;
        }

        // Limpar os flags de erro e reabrir o arquivo
        clear(); // Limpar os flags de erro

        cerr << "Retrying to open file: " << name << endl;

        // Tentar reabrir o arquivo
        open(name.c_str(), openmode);

        if (!is_open()) {
            cerr << "Failed to open file even after retry." << endl;
            // Adicione mais informa��es sobre o erro, se poss�vel
        } else {
            cout << "File opened successfully after retry: " << name << endl;
        }
    } else {
        cout << "File opened successfully: " << name << endl;
    }

    // Restante do c�digo do construtor
}


template <class T>
typedFile<T>::~typedFile() {
    close();
}

template <class T>
bool typedFile<T>::open(const string name, const string type, const unsigned int version, ios::openmode openmode) {
    if (is_open()) {
        close();
    }

    clear();

    open(name.c_str(), openmode);
    if (!is_open()) {
        return false; // Falha ao abrir o arquivo.
    }

    head.setType(type);
    head.setVersion(version);

    // Realize qualquer outra configura��o necess�ria ao abrir o arquivo.

    return true;
}

template <class T>
bool typedFile<T>::isOpen() {
    return is_open();
}

template <class T>
bool typedFile<T>::close() {
    if (is_open()) {
        flush();
        fstream::close();
        return !is_open();
    }
    return true;
}

template <class T>
bool typedFile<T>::clear() {
    if (!this->is_open()) {  // Corrigindo aqui para usar this->is_open()
        return false;
    }

    // Limpe o conte�do do arquivo ou realize qualquer opera��o de limpeza necess�ria.
    // Esta implementa��o depende do formato de armazenamento de seus dados.

    return true;
}

template <class T>
bool typedFile<T>::readRecord(record<T> &r, unsigned long long int i) {
    if (!is_open()) {
        cerr << "Error: File is not open." << endl;
        return false;
    }

    // Verificar se o �ndice est� dentro dos limites do arquivo
    if (i >= getFirstValid()) {
        cerr << "Error: Index out of bounds." << endl;
        return false;
    }

    // Calcular a posi��o do arquivo com base no �ndice
    unsigned long long int pos = index2pos(i);

    // Posicionar o ponteiro do arquivo na posi��o correta
    seekg(pos);

    // Verificar se a leitura foi bem-sucedida
    if (!read(reinterpret_cast<char*>(&r), sizeof(record<T>))) {
        cerr << "Error reading record at index " << i << "." << endl;
        return false;
    }

    return true;
}

template <class T>
bool typedFile<T>::writeRecord(record<T> &r, unsigned long long int i) {
    if (!is_open()) {
        cerr << "Error: File is not open." << endl;
        return false;
    }

    // Verificar se o �ndice est� dentro dos limites do arquivo
    if (i >= getFirstValid()) {
        cerr << "Error: Index out of bounds." << endl;
        return false;
    }

    // Calcular a posi��o do arquivo com base no �ndice
    unsigned long long int pos = index2pos(i);

    // Posicionar o ponteiro do arquivo na posi��o correta
    seekp(pos);

    // Verificar se a escrita foi bem-sucedida
    if (!write(reinterpret_cast<char*>(&r), sizeof(record<T>))) {
        cerr << "Error writing record at index " << i << "." << endl;
        return false;
    }

    return true;
}

template <class T>
bool typedFile<T>::insertRecord(record<T> &r) {
    if (!is_open()) {
        cerr << "Error: File is not open." << endl;
        return false;
    }

    // Encontrar um espa�o vago (um registro deletado) ou adicionar ao final
    unsigned long long int pos;
    if (getFirstDeleted() != 0) {
        // Se houver registros deletados, reutilize o primeiro
        pos = index2pos(getFirstDeleted());
        // Atualize o �ndice do pr�ximo registro deletado
        record<T> temp;
        seekg(pos);
        read(reinterpret_cast<char*>(&temp), sizeof(record<T>));
        head.firstDeleted = temp.getNext();
        writeHeader(head);
    } else {
        // Caso contr�rio, adicione ao final
        pos = index2pos(head.lastValid + 1);
        head.lastValid++;
        writeHeader(head);
    }

    // Posicionar o ponteiro do arquivo na posi��o correta
    seekp(pos);

    // Verificar se a escrita foi bem-sucedida
    if (!write(reinterpret_cast<char*>(&r), sizeof(record<T>))) {
        cerr << "Error inserting record." << endl;
        return false;
    }

    return true;
}

template <class T>
bool typedFile<T>::deleteRecord(unsigned long long int i) {
    if (!is_open()) {
        cerr << "Error: File is not open." << endl;
        return false;
    }

    // Verificar se o �ndice est� dentro dos limites v�lidos
    if (i < 1 || i > head.lastValid) {
        cerr << "Error: Invalid index." << endl;
        return false;
    }

    // Calcular a posi��o do registro no arquivo
    unsigned long long int pos = index2pos(i);

    // Posicionar o ponteiro do arquivo na posi��o correta
    seekg(pos);

    // Ler o registro para verificar se est� marcado como exclu�do
    record<T> temp;
    read(reinterpret_cast<char*>(&temp), sizeof(record<T>));

    // Verificar se o registro j� est� exclu�do
    if (temp.isDeleted()) {
        cerr << "Error: Record is already deleted." << endl;
        return false;
    }

    // Marcar o registro como exclu�do
    temp.del();

    // Posicionar o ponteiro do arquivo novamente e escrever o registro modificado
    seekp(pos);
    if (!write(reinterpret_cast<char*>(&temp), sizeof(record<T>))) {
        cerr << "Error deleting record." << endl;
        return false;
    }

    return true;
}

template <class T>
unsigned long long int typedFile<T>::getFirstValid() {
    if (!is_open()) {
        cerr << "Error: File is not open." << endl;
        return 0;  // Retorna 0 para indicar erro
    }

    unsigned long long int index = 1;  // Inicializa o �ndice

    // Itera pelos registros at� encontrar o primeiro v�lido
    while (index <= head.lastValid) {
        // Calcula a posi��o do registro no arquivo
        unsigned long long int pos = index2pos(index);

        // Posiciona o ponteiro do arquivo na posi��o correta
        seekg(pos);

        // L� o registro
        record<T> temp;
        read(reinterpret_cast<char*>(&temp), sizeof(record<T>));

        // Verifica se o registro n�o est� marcado como exclu�do
        if (!temp.isDeleted()) {
            return index;  // Retorna o �ndice do primeiro registro v�lido
        }

        // Incrementa o �ndice para verificar o pr�ximo registro
        index++;
    }

    cerr << "Error: No valid records found." << endl;
    return 0;  // Retorna 0 se nenhum registro v�lido for encontrado
}

template <class T>
unsigned long long int typedFile<T>::getFirstDeleted() {
    if (!is_open()) {
        cerr << "Error: File is not open." << endl;
        return 0;  // Retorna 0 para indicar erro
    }

    unsigned long long int index = 1;  // Inicializa o �ndice

    // Itera pelos registros at� encontrar o primeiro exclu�do
    while (index <= head.lastValid) {
        // Calcula a posi��o do registro no arquivo
        unsigned long long int pos = index2pos(index);

        // Posiciona o ponteiro do arquivo na posi��o correta
        seekg(pos);

        // L� o registro
        record<T> temp;
        read(reinterpret_cast<char*>(&temp), sizeof(record<T>));

        // Verifica se o registro est� marcado como exclu�do
        if (temp.isDeleted()) {
            return index;  // Retorna o �ndice do primeiro registro exclu�do
        }

        // Incrementa o �ndice para verificar o pr�ximo registro
        index++;
    }

    cerr << "Error: No deleted records found." << endl;
    return 0;  // Retorna 0 se nenhum registro exclu�do for encontrado
}

template <class T>
unsigned long long int typedFile<T>::search(T data) {
    if (!is_open()) {
        cerr << "Error: File is not open." << endl;
        return 0;  // Retorna 0 para indicar erro
    }

    unsigned long long int index = 1;  // Inicializa o �ndice

    // Itera pelos registros at� encontrar um com os dados espec�ficos
    while (index <= head.lastValid) {
        // Calcula a posi��o do registro no arquivo
        unsigned long long int pos = index2pos(index);

        // Posiciona o ponteiro do arquivo na posi��o correta
        seekg(pos);

        // L� o registro
        record<T> temp;
        read(reinterpret_cast<char*>(&temp), sizeof(record<T>));

        // Verifica se os dados do registro correspondem aos dados fornecidos
        if (temp.getData() == data && !temp.isDeleted()) {
            return index;  // Retorna o �ndice do registro encontrado
        }

        // Incrementa o �ndice para verificar o pr�ximo registro
        index++;
    }

    cerr << "Error: Record not found." << endl;
    return 0;  // Retorna 0 se o registro n�o for encontrado
}

template <class T>
bool typedFile<T>::readHeader(header &h) {
    if (!is_open()) {
        cerr << "Error: File is not open." << endl;
        return false;  // Retorna falso para indicar erro
    }

    // Posiciona o ponteiro do arquivo no in�cio do arquivo
    seekg(0);

    // L� o cabe�alho
    read(reinterpret_cast<char*>(&h), sizeof(header));

    if (good()) {
        return true;  // Retorna verdadeiro se a leitura for bem-sucedida
    } else {
        cerr << "Error: Failed to read header." << endl;
        return false;  // Retorna falso se a leitura falhar
    }
}

template <class T>
bool typedFile<T>::writeHeader(header &h) {
    if (!is_open()) {
        cerr << "Error: File is not open." << endl;
        return false;  // Retorna falso para indicar erro
    }

    // Posiciona o ponteiro do arquivo no in�cio do arquivo
    seekp(0);

    // Escreve o cabe�alho
    write(reinterpret_cast<char*>(&h), sizeof(header));

    if (good()) {
        return true;  // Retorna verdadeiro se a escrita for bem-sucedida
    } else {
        cerr << "Error: Failed to write header." << endl;
        return false;  // Retorna falso se a escrita falhar
    }
}

template <class T>
unsigned long long int typedFile<T>::index2pos(unsigned long long int i) {
    // Calcula a posi��o multiplicando o �ndice pelo tamanho do registro
    return sizeof(header) + i * sizeof(record<T>);
}

template <class T>
unsigned long long int typedFile<T>::pos2index(unsigned long long int p) {
    // Calcula o �ndice dividindo a posi��o pelo tamanho do registro
    return (p - sizeof(header)) / sizeof(record<T>);
}

#endif // TYPEDFILE_H
