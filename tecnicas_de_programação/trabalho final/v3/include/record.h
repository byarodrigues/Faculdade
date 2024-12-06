#ifndef RECORD_H
#define RECORD_H

#include <string>
#include "serializable.h"
#include <type_traits>  // for std::is_base_of
#include <iostream>     // for std::ostream, std::istream

template <class T>
class record : public serializable {
    static_assert(std::is_base_of<serializable, T>::value, "T must be serializable");

public:
    record();
    record(T data);
    record(const record<T> &other);
    ~record();

    record<T> operator=(const record<T> &other);
    bool operator==(const record<T> &other) const;

    T getData() const;
    void setData(T data);

    unsigned long long int getNext() const;
    void setNext(unsigned long long int next);

    bool isDeleted() const;
    void del();
    void undel();

    unsigned long long int size() const override;

    // Métodos adicionados para a escrita e leitura de registros em arquivo
    void writeToFile(std::ostream &out) const override;
    void readFromFile(std::istream &in) override;

private:
    T data;
    unsigned long long int next;
    bool deleted;
};

template <class T>
record<T>::record() : serializable() {
    next = 0;
    deleted = false;
}

template <class T>
record<T>::record(T data) : serializable(), data(data) {
    next = 0;
    deleted = false;
}

template <class T>
record<T>::record(const record<T> &other) {
    data = other.data;
    next = other.next;
    deleted = other.deleted;
}

template <class T>
record<T>::~record() {}

template <class T>
record<T> record<T>::operator=(const record<T> &other) {
    if (this != &other) {
        data = other.data;
        next = other.next;
        deleted = other.deleted;
    }
    return *this;
}

template <class T>
bool record<T>::operator==(const record<T> &other) const {
    return (data == other.data && next == other.next && deleted == other.deleted);
}

template <class T>
T record<T>::getData() const {
    return data;
}

template <class T>
void record<T>::setData(T data) {
    this->data = data;
}

template <class T>
unsigned long long int record<T>::getNext() const {
    return next;
}

template <class T>
void record<T>::setNext(unsigned long long int next) {
    this->next = next;
}

template <class T>
bool record<T>::isDeleted() const {
    return deleted;
}

template <class T>
void record<T>::del() {
    deleted = true;
}

template <class T>
void record<T>::undel() {
    deleted = false;
}

template <class T>
unsigned long long int record<T>::size() const {
    return sizeof(data) + sizeof(next) + sizeof(deleted);
}

template <class T>
void record<T>::writeToFile(std::ostream &out) const {
    // Use os métodos de serialização da classe base
    serializable::serialize(out);

    // Escreva dados adicionais do registro no arquivo
    out.write(reinterpret_cast<const char*>(&next), sizeof(next));
    out.write(reinterpret_cast<const char*>(&deleted), sizeof(deleted));
}

template <class T>
void record<T>::readFromFile(std::istream &in) {
    // Use os métodos de desserialização da classe base
    deserialize(in);

    // Leia dados adicionais do registro do arquivo
    in.read(reinterpret_cast<char*>(&next), sizeof(next));
    in.read(reinterpret_cast<char*>(&deleted), sizeof(deleted));
}

#endif // RECORD_H

