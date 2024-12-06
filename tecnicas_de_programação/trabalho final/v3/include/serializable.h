/********************************************************
 * serializable.h - Trabalho - Árvore B                 *
 *                                                      *
 * Alunos: Beatriz Rodrigues de Oliveira Paiva          *
 *         RA: 0040300                                  *
 *                                                      *
 ********************************************************/

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iostream>
#include <string>
using namespace std;

class serializable {
public:
    serializable() {}
    virtual ~serializable() {}

    virtual void serialize(ostream &out) const = 0;
    virtual void deserialize(istream &in) = 0;
    virtual unsigned long long int size() const = 0;
};

#endif // SERIALIZABLE_H

