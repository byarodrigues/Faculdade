/********************************************************
 * header.cpp - Trabalho - Árvore B                     *
 *                                                      *
 * Alunos: Beatriz Rodrigues de Oliveira Paiva          *
 *         RA: 0040300                                  *
 *                                                      *
 ********************************************************/

#include "header.h"
#include <sstream>

header::header() : serializable() {
    // Inicialize os membros conforme necessário
    firstDeleted = 0; // ou o valor padrão desejado
    firstValid = 0;   // ou o valor padrão desejado
    type = "";        // ou o valor padrão desejado
    version = 1;      // ou a versão inicial desejada
}

header::header(const string t, unsigned int v) : serializable() {
    // Inicialize os membros conforme necessário
    firstDeleted = 0; // ou o valor padrão desejado
    firstValid = 0;   // ou o valor padrão desejado
    type = t;
    version = v;
}

header::header(const header &h) {
    // Copie os membros conforme necessário
    firstDeleted = h.firstDeleted;
    firstValid = h.firstValid;
    type = h.type;
    version = h.version;
}

header::~header() {
   //dtor
}

header& header::operator=(const header &h) {
    // Atribua os membros conforme necessário
    firstDeleted = h.firstDeleted;
    firstValid = h.firstValid;
    type = h.type;
    version = h.version;

    return *this;
}

bool header::operator==(const header &h) const {
    // Compare os membros e retorne true se forem iguais, caso contrário, false
    return (firstDeleted == h.firstDeleted &&
            firstValid == h.firstValid &&
            type == h.type &&
            version == h.version);
}

unsigned long long int header::getFirstDeleted() const {
    return firstDeleted;
}

void header::setFirstDeleted(unsigned long long int r) {
    firstDeleted = r;
}

unsigned long long int header::getFirstValid() const {
    return firstValid;
}

void header::setFirstValid(unsigned long long int r) {
    firstValid = r;
}

string header::getType() const {
    return type;
}

void header::setType(string t) {
    type = t;
}

unsigned int header::getVersion() const {
    return version;
}

void header::setVersion(unsigned int v) {
    version = v;
}

string header::toString() const {
    return to_string(firstDeleted) + "," + to_string(firstValid) + "," + type + "," + to_string(version);
}

void header::fromString(string repr) {
    stringstream ss(repr);
    string token;

    getline(ss, token, ',');
    firstDeleted = stoull(token);

    getline(ss, token, ',');
    firstValid = stoull(token);

    getline(ss, type, ',');

    getline(ss, token, ',');
    version = stoi(token);
}

unsigned long long int header::size() const {
    // Retorne o tamanho total da instância em bytes
    return sizeof(firstDeleted) + sizeof(firstValid) + type.size() + sizeof(version);
}

