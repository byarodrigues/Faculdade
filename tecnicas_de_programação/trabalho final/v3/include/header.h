/********************************************************
 * header.h - Trabalho - Árvore B                     *
 *                                                      *
 * Alunos: Beatriz Rodrigues de Oliveira Paiva          *
 *         RA: 0040300                                  *
 *                                                      *
 ********************************************************/

#ifndef HEADER_H
#define HEADER_H

#include "serializable.h"
#include <string>

using namespace std;

class header : public serializable {
public:
    header();
    header(const string t, unsigned int v);
    header(const header &h);
    ~header();

    header& operator=(const header &h);
    bool operator==(const header &h) const;

    unsigned long long int getFirstDeleted() const;
    void setFirstDeleted(unsigned long long int r);

    unsigned long long int getFirstValid() const;
    void setFirstValid(unsigned long long int r);

    string getType() const;
    void setType(string t);

    unsigned int getVersion() const;
    void setVersion(unsigned int v);

    string toString() const; // Certifique-se de que a declaração tem 'const'
    void fromString(string repr);

    unsigned long long int size() const;

private:
    unsigned long long int firstDeleted;
    unsigned long long int firstValid;
    string type;
    unsigned int version;
};

#endif // HEADER_H

