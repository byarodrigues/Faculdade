/********************************************************
 * serialChar.cpp - Trabalho - Árvore B                 *
 *                                                      *
 * Alunos: Beatriz Rodrigues de Oliveira Paiva          *
 *         RA: 0040300                                  *
 *                                                      *
 ********************************************************/

#include "serialChar.h"

serialChar::serialChar() : serializable() {
    this->data = 0;
}

serialChar::serialChar(char i) : serializable() {
    this->data = i;
}

serialChar::~serialChar() {
}

serialChar& serialChar::operator=(const serialChar& other) {
    if (this != &other) {  // Evita autoatribuição
        this->data = other.data;
    }
    return *this;
}

bool serialChar::operator==(const serialChar &other) const {
    return this->data == other.data;
}

bool serialChar::operator<(const serialChar &other) const {
    return this->data < other.data;
}

bool serialChar::operator<=(const serialChar &other) const {    // Verifica se this é menor que other ou se são iguais
    return this->data < other.data || this->data == other.data;
}

bool serialChar::operator>(const serialChar &other) const {    // Inverte a lógica do operador <
    return this->data > other.data;
}

bool serialChar::operator>=(const serialChar &other) const {    // Verifica se this é maior que other ou se são iguais
    return this->data > other.data || this->data == other.data;
}

bool serialChar::operator!=(const serialChar &other) const {    // Inverte a lógica do operador de igualdade
    return !(this->data == other.data);
}

serialChar serialChar::operator+(const serialChar& other) const {    // Cria uma nova instância concatenando os membros
    char result = this->data + other.data;

    // Retorna a nova instância
    return serialChar(result);
}

serialChar serialChar::operator-(const serialChar& other) const {    // Cria uma nova instância subtraindo os membros
    char result = this->data - other.data;

    // Retorna a nova instância
    return serialChar(result);
}

serialChar serialChar::operator*(const serialChar& other) const {    // Cria uma nova instância multiplicando os valores ASCII dos membros
    char result = this->data * other.data;

    // Retorna a nova instância
    return serialChar(result);
}

serialChar serialChar::operator/(const serialChar& other) const {    // Verifica se o divisor é zero para evitar uma possível divisão por zero
    if (other.data != 0) {
        // Cria uma nova instância dividindo os valores ASCII dos membros
        char result = this->data / other.data;

        // Retorna a nova instância
        return serialChar(result);
    } else {
        // Trate a divisão por zero conforme necessário
        // Aqui, poderia lançar uma exceção, retornar um valor padrão, etc.
        // Estou usando um caractere nulo ('\0') como exemplo.
        return serialChar('\0');
    }
}

serialChar serialChar::operator++() {    // Incrementa o valor ASCII do caractere
    ++this->data;

    // Retorna a instância após o incremento
    return *this;
}

serialChar serialChar::operator--() {    // Decrementa o valor ASCII do caractere
    --this->data;

    // Retorna a instância após o decremento
    return *this;
}

void serialChar::setValue(char v) {    // Atribui o valor a data
    this->data = v;
}

char serialChar::getValue() const {    // Retorna o valor do caractere
    return this->data;
}

unsigned long long int serialChar::size() const {    // Retorna o tamanho da instância em bytes
    return sizeof(this->data);
}

void serialChar::serialize(ostream &out) const {
    out.write(reinterpret_cast<const char*>(&data), sizeof(data));
}

void serialChar::deserialize(istream &in) {
    in.read(reinterpret_cast<char*>(&data), sizeof(data));
}

