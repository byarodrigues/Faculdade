/********************************************************
 * typedfile.h - Trabalho - �rvore B                    *
 *                                                      *
 * Alunos: Beatriz Rodrigues de Oliveira Paiva          *
 *         RA: 0040300                                  *
 *                                                      *
 ********************************************************/

#ifndef TYPEDFILE_H
#define TYPEDFILE_H

#include "header.h"
#include "record.h"
#include "serializable.h"
#include <string>
#include <fstream>
#include <type_traits>
#include "btree_node.h"

template <class T, unsigned int MIN_DEGREE = 0>
class typedFile : public std::fstream {
 //   static_assert(std::is_base_of<serializable, T>::value, "T must be serializable");
    template <class U> friend class record;  // Alterei para 'record'

public:
    typedFile();
    typedFile(const std::string& name, const std::string& type, const unsigned int version, std::ios::openmode openmode);
    ~typedFile();

    bool open(const std::string& name, const std::string& type, const unsigned int version, std::ios::openmode openmode);
    bool isOpen();
    bool close();
    bool clear();
    bool readRecord(record<T>& r, unsigned long long int i);  // Alterei para 'record'
    bool writeRecord(const record<T>& r, unsigned long long int i);  // Alterei para 'record'
    bool insertRecord(const record<T>& r);  // Alterei para 'record'
    bool deleteRecord(unsigned long long int i);
    unsigned long long int getFirstValid();
    unsigned long long int getFirstDeleted();
    unsigned long long int search(T data);
    bool readHeader(header& h);
    bool writeHeader(const header& h);
    void write(const serializable& obj);
    unsigned long long int index2pos(unsigned long long int i);
    unsigned long long int pos2index(unsigned long long int p);

private:
    std::string type;
    unsigned int version;
    bool fileIsValid(const std::string& type, const unsigned int version);
    unsigned long long int getRealFileSize();

};

template <class U>
class Record;

template <class T, unsigned int MIN_DEGREE>
typedFile<T, MIN_DEGREE>::typedFile() : std::fstream() {
//    static_assert(std::is_base_of<serializable, T>::value, "T must be serializable");
}

template <class T, unsigned int MIN_DEGREE>
typedFile<T, MIN_DEGREE>::typedFile(const std::string& name, const std::string& type, const unsigned int version, std::ios::openmode openmode)
    : std::fstream(name.c_str(), openmode), type(type), version(version) {
    if (this->is_open()) {
        std::cout << "O arquivo est� aberto" << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        close();
    }
}

template <class T, unsigned int MIN_DEGREE>
typedFile<T, MIN_DEGREE>::~typedFile() {
    if (this->is_open()) {
        this->close();
    }
}

template <class T, unsigned int MIN_DEGREE>
bool typedFile<T, MIN_DEGREE>::open(const std::string& name, const std::string& type, const unsigned int version, std::ios::openmode openmode) {
    if (this->is_open()) {
        std::cerr << "Erro: O arquivo j� est� aberto." << std::endl;
        return false;
    }

    std::fstream::open(name.c_str(), openmode);

    if (!this->is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return false;
    }

    // L�gica para verificar se o arquivo j� existe e possui o tipo e a vers�o corretos
    if (fileIsValid(type, version)) {
        std::cout << "O arquivo existe e possui o tipo e a vers�o corretos." << std::endl;
        // Realize opera��es adicionais, se necess�rio
    } else {
        std::cerr << "Erro: O arquivo n�o possui o tipo ou a vers�o corretos." << std::endl;
        this->close();
        return false;
    }

    return true;
}

template <class T, unsigned int MIN_DEGREE>
bool typedFile<T, MIN_DEGREE>::isOpen() {
    return this->is_open();
}

template <class T, unsigned int MIN_DEGREE>
bool typedFile<T, MIN_DEGREE>::close() {
    if (fstream::is_open()) {
        fstream::close();
        return true;
    }
    return false;
}

template <class T, unsigned int MIN_DEGREE>
bool typedFile<T, MIN_DEGREE>::readRecord(record<T>& r, unsigned long long int i) {
    if (!this->is_open()) {
        cerr << "Erro: O arquivo n�o est� aberto." << endl;
        return false;
    }

    // Calcular a posi��o f�sica do registro no arquivo
    unsigned long long int position = index2pos(i);

    // Mover o ponteiro de leitura para a posi��o calculada
    this->seekg(position, ios::beg);

    // Ler os dados brutos do registro do arquivo
    string rawData;
    getline(*this, rawData);

    // Desserializar os dados brutos para o registro
    r.deserialize(rawData);

    return true;
}


template <class T, unsigned int MIN_DEGREE>
bool typedFile<T, MIN_DEGREE>::writeRecord(const record<T>& r, unsigned long long int i) {
    if (!this->is_open()) {
        cerr << "Erro: O arquivo n�o est� aberto." << endl;
        return false;
    }

    // Calcular a posi��o f�sica do registro no arquivo
    unsigned long long int position = index2pos(i);

    // Mover o ponteiro de escrita para a posi��o calculada
    this->seekp(position, ios::beg);

    // Serializar o registro e escrever os dados brutos no arquivo
    string rawData = r.serialize();
    *this << rawData << endl;

    return true;
}

template <class T, unsigned int MIN_DEGREE>
bool typedFile<T, MIN_DEGREE>::insertRecord(const record<T>& r) {
    if (!this->is_open()) {
        cerr << "Erro: O arquivo n�o est� aberto." << endl;
        return false;
    }

    // Mover o ponteiro de escrita para o final do arquivo
    this->seekp(0, ios::end);

    // Serializar o registro e escrever os dados brutos no arquivo
    string rawData = r.serialize();
    *this << rawData << endl;

    return true;
}

template <class T, unsigned int MIN_DEGREE>
bool typedFile<T, MIN_DEGREE>::deleteRecord(unsigned long long int i) {
    if (!this->is_open()) {
        cerr << "Erro: O arquivo n�o est� aberto." << endl;
        return false;
    }

    // Calcular a posi��o f�sica do registro no arquivo
    unsigned long long int position = index2pos(i);

    // Mover o ponteiro de escrita para a posi��o do registro
    this->seekp(position, ios::beg);

    // Sobrescrever o registro com uma marca de exclus�o
    // (aqui estou usando um exemplo de marca, voc� pode ajustar conforme necess�rio)
    *this << "Registro Exclu�do" << endl;

    return true;
}

template <class T, unsigned int MIN_DEGREE>
unsigned long long int typedFile<T, MIN_DEGREE>::getFirstValid() {
    if (!this->is_open()) {
        cerr << "Erro: O arquivo n�o est� aberto." << endl;
        return 0; // ou outro valor de erro, dependendo dos requisitos do seu programa
    }

    header h;
    if (!readHeader(h)) {
        cerr << "Erro ao ler o cabe�alho." << endl;
        return 0; // ou outro valor de erro, dependendo dos requisitos do seu programa
    }

    return h.getFirstValid(); // supondo que o cabe�alho tenha um m�todo para obter a posi��o do primeiro registro v�lido
}

template <class T, unsigned int MIN_DEGREE>
unsigned long long int typedFile<T, MIN_DEGREE>::getFirstDeleted() {
    if (!this->is_open()) {
        cerr << "Erro: O arquivo n�o est� aberto." << endl;
        return 0; // ou outro valor de erro, dependendo dos requisitos do seu programa
    }

    header h;
    if (!readHeader(h)) {
        cerr << "Erro ao ler o cabe�alho." << endl;
        return 0; // ou outro valor de erro, dependendo dos requisitos do seu programa
    }

    return h.getFirstDeleted(); // supondo que o cabe�alho tenha um m�todo para obter a posi��o do primeiro registro deletado
}

template <class T, unsigned int MIN_DEGREE>
unsigned long long int typedFile<T, MIN_DEGREE>::search(T data) {
    if (!this->is_open()) {
        cerr << "Erro: O arquivo n�o est� aberto." << endl;
        return 0; // ou outro valor de erro, dependendo dos requisitos do seu programa
    }

    unsigned long long int currentIndex = 0;
    Record<T> currentRecord;

    // Iterar sobre os registros no arquivo
    while (readRecord(currentRecord, currentIndex)) {
        // Comparar os dados do registro com os dados fornecidos
        if (currentRecord.getData() == data) {
            // Se encontrar um registro com os dados correspondentes, retorna o �ndice
            return currentIndex;
        }

        currentIndex++;
    }

    // Se n�o encontrar o registro, retorna 0 ou outro valor de erro
    return 0; // ou outro valor de exemplo, substitua conforme necess�rio
}

template <class T, unsigned int MIN_DEGREE>
bool typedFile<T, MIN_DEGREE>::readHeader(header &h) {
    if (!this->is_open()) {
        cerr << "Erro: O arquivo n�o est� aberto." << endl;
        return false;
    }

    // Mover o ponteiro de leitura para o in�cio do arquivo
    this->seekg(0, ios::beg);

    // Ler os dados brutos do cabe�alho do arquivo
    string rawData;
    getline(*this, rawData);

    // Desserializar os dados brutos para o objeto Header
    h.fromString(rawData);

    return true;
}

template <class T, unsigned int MIN_DEGREE>
bool typedFile<T, MIN_DEGREE>::writeHeader(const header &h) {
    if (!this->is_open()) {
        cerr << "Erro: O arquivo n�o est� aberto." << endl;
        return false;
    }

    // Mover o ponteiro de escrita para o in�cio do arquivo
    this->seekp(0, ios::beg);

    // Obter a representa��o de string do cabe�alho
    string headerString = h.toString();

    // Escrever os dados brutos do cabe�alho no arquivo
    *this << headerString << endl;

    return true;
}

template <class T, unsigned int MIN_DEGREE>
bool typedFile<T, MIN_DEGREE>::fileIsValid(const std::string& type, const unsigned int version) {
    if (!this->is_open()) {
        std::cerr << "Erro: O arquivo n�o est� aberto." << std::endl;
        return false;
    }

    // Verificar se o arquivo possui um cabe�alho v�lido
    header h;
    if (!readHeader(h)) {
        std::cerr << "Erro ao ler o cabe�alho." << std::endl;
        return false;
    }

    // Comparar o tipo e a vers�o no cabe�alho com os valores esperados
    if (h.getType() == type && h.getVersion() == version) {
        std::cout << "Arquivo v�lido. Tipo e vers�o corretos." << std::endl;
        return true;
    } else {
        std::cerr << "Erro: O arquivo n�o possui o tipo ou a vers�o corretos." << std::endl;
        return false;
    }
}

// voltar aqui
/*************************************/

template <class T, unsigned int MIN_DEGREE>
unsigned long long int typedFile<T, MIN_DEGREE>::index2pos(unsigned long long int i) {
    if (!this->is_open()) {
        std::cerr << "Erro: O arquivo n�o est� aberto." << std::endl;
        return 0;
    }

    // Salva o estado atual do cursor no arquivo
    std::streampos currentPosition = this->tellg();

    // Move o cursor para o final do arquivo para obter o tamanho real
    this->seekg(0, std::ios::end);
    unsigned long long int fileSize = this->tellg();

    // Restaura o cursor para a posi��o original
    this->seekg(currentPosition);

    return fileSize;
}

template <class T, unsigned int MIN_DEGREE>
unsigned long long int typedFile<T, MIN_DEGREE>::pos2index(unsigned long long int p) {
    if (!this->is_open()) {
        std::cerr << "Erro: O arquivo n�o est� aberto." << std::endl;
        return 0; // Ou algum valor que indique erro
    }

    size_t nodeSize = sizeof(BTreeNode<T, MIN_DEGREE>);  // Use a defini��o correta

    // Verificar se a posi��o fornecida ultrapassa o tamanho real do arquivo
    unsigned long long int fileSize = getRealFileSize(); // Substitua pela fun��o real
    if (p >= fileSize) {
        std::cerr << "Erro: Posi��o fornecida ultrapassa o tamanho real do arquivo." << std::endl;
        return 0; // Ou algum valor que indique erro
    }

    // Ajuste da posi��o se necess�rio (por exemplo, se houver um cabe�alho no in�cio do arquivo)
    // unsigned long long int adjustedPosition = p + headerSize; // Ajuste conforme necess�rio

    // Calcular o �ndice dividindo a posi��o f�sica pelo tamanho do n�
    unsigned long long int index = p / nodeSize;

    // Considerar a estrutura espec�fica da �rvore B
    // Se necess�rio, ajuste o c�lculo do �ndice com base na estrutura da �rvore

    return index;
}

#endif // TYPEDFILE_H
