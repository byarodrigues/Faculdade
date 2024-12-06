#ifndef RECORD_H
#define RECORD_H

#include <string>
#include "serializable.h"
#include <type_traits>  // for static_assert

using namespace std;

template <class T, const unsigned int MIN_DEGREE>
class record : public serializable {
    static_assert(is_base_of<serializable, T>::value, "T must be serializable");
public:
    record();
    record(T d);
    record(const record<T, MIN_DEGREE> &other);
    virtual ~record();
    record<T, MIN_DEGREE>& operator=(const record<T, MIN_DEGREE> &other);
    bool operator==(const record<T, MIN_DEGREE> &other) const;
    T getData() const;
    void setData(T d);
    unsigned long long int getNext() const;
    void setNext(unsigned long long int n);
    bool isDeleted() const;
    void del();
    void undel();
    virtual string toString() const;
    virtual void fromString(string repr);
    virtual string toCSV() const;
    virtual void fromCSV(string repr);
    virtual string toJSON() const;
    virtual void fromJSON(string repr);
    virtual string toXML() const;
    virtual void fromXML(string repr);
    virtual unsigned long long int size() const;

protected:
    T data;
    bool deleted;
    unsigned long long int next;
};

template <class T, const unsigned int MIN_DEGREE>
record<T, MIN_DEGREE>::record() : serializable() {
    data = T();
    deleted = false;
    next = 0;
}

template <class T, const unsigned int MIN_DEGREE>
record<T, MIN_DEGREE>::record(T d) : serializable() {
    data = d;
    deleted = false;
    next = 0;
}

template <class T, const unsigned int MIN_DEGREE>
record<T, MIN_DEGREE>::record(const record<T, MIN_DEGREE> &other) {
    data = other.data;
    deleted = other.deleted;
    next = other.next;
}

template <class T, const unsigned int MIN_DEGREE>
record<T, MIN_DEGREE>::~record() {
    // Destructor implementation as needed
}

template <class T, const unsigned int MIN_DEGREE>
record<T, MIN_DEGREE> &record<T, MIN_DEGREE>::operator=(const record<T, MIN_DEGREE> &other) {
    if (this == &other) {
        return *this;
    }
    data = other.data;
    deleted = other.deleted;
    next = other.next;
    return *this;
}

template <class T, const unsigned int MIN_DEGREE>
bool record<T, MIN_DEGREE>::operator==(const record<T, MIN_DEGREE> &other) const {
    return data == other.data && deleted == other.deleted && next == other.next;
}

template <class T, const unsigned int MIN_DEGREE>
T record<T, MIN_DEGREE>::getData() const {
    return data;
}

template <class T, const unsigned int MIN_DEGREE>
void record<T, MIN_DEGREE>::setData(T d) {
    data = d;
}

template <class T, const unsigned int MIN_DEGREE>
unsigned long long int record<T, MIN_DEGREE>::getNext() const {
    return next;
}

template <class T, const unsigned int MIN_DEGREE>
void record<T, MIN_DEGREE>::setNext(unsigned long long int n) {
    next = n;
}

template <class T, const unsigned int MIN_DEGREE>
bool record<T, MIN_DEGREE>::isDeleted() const {
    return deleted;
}

template <class T, const unsigned int MIN_DEGREE>
void record<T, MIN_DEGREE>::del() {
    deleted = true;
}

template <class T, const unsigned int MIN_DEGREE>
void record<T, MIN_DEGREE>::undel() {
    deleted = false;
}

template <class T, const unsigned int MIN_DEGREE>
string record<T, MIN_DEGREE>::toString() const {
    return data.toString();
}

template <class T, const unsigned int MIN_DEGREE>
void record<T, MIN_DEGREE>::fromString(string repr) {
    data.fromString(repr);
}

template <class T, const unsigned int MIN_DEGREE>
string record<T, MIN_DEGREE>::toCSV() const {
    return data.toCSV();
}

template <class T, const unsigned int MIN_DEGREE>
void record<T, MIN_DEGREE>::fromCSV(string repr) {
    data.fromCSV(repr);
}

template <class T, const unsigned int MIN_DEGREE>
string record<T, MIN_DEGREE>::toJSON() const {
    return data.toJSON();
}

template <class T, const unsigned int MIN_DEGREE>
void record<T, MIN_DEGREE>::fromJSON(string repr) {
    data.fromJSON(repr);
}

template <class T, const unsigned int MIN_DEGREE>
string record<T, MIN_DEGREE>::toXML() const {
    return data.toXML();
}

template <class T, const unsigned int MIN_DEGREE>
void record<T, MIN_DEGREE>::fromXML(string repr) {
    data.fromXML(repr);
}

template <class T, const unsigned int MIN_DEGREE>
unsigned long long int record<T, MIN_DEGREE>::size() const {
    return data.size();
}

#endif // RECORD_H
