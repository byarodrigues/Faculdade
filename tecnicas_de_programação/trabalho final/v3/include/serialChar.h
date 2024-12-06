/********************************************************
 * serialChar.h - Trabalho - Árvore B                   *
 *                                                      *
 * Alunos: Beatriz Rodrigues de Oliveira Paiva          *
 *         RA: 0040300                                  *
 *                                                      *
 ********************************************************/

#ifndef SERIALCHAR_H
#define SERIALCHAR_H

#include "serializable.h"
#include <iostream>

class serialChar : public serializable {
public:
    serialChar();
    serialChar(char i);
    ~serialChar();
    serialChar& operator=(const serialChar& other);
    bool operator==(const serialChar &other) const;
    bool operator<(const serialChar &other) const;
    bool operator<=(const serialChar &other) const;
    bool operator>(const serialChar &other) const;
    bool operator>=(const serialChar &other) const;
    bool operator!=(const serialChar &other) const;
    serialChar operator+(const serialChar& other) const;
    serialChar operator-(const serialChar& other) const;
    serialChar operator*(const serialChar& other) const;
    serialChar operator/(const serialChar& other) const;
    serialChar operator++();
    serialChar operator--();
    void setValue(char v);
    char getValue() const;
    virtual unsigned long long int size() const;
    void serialize(std::ostream& out) const;
    void deserialize(std::istream& in) override;

private:
    char data;
};

#endif // SERIALCHAR_H
