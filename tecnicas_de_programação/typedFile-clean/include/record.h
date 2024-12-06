#ifndef RECORD_H
#define RECORD_H

#include <string>
#include "serializable.h"
#include <type_traits>  // for static_assert

using namespace std;

template <class T>
class record : public serializable {
    static_assert(is_base_of<serializable, T>::value, "T must be serializable");
public:
    record();
    record(T d);
    record(const record<T> &other);
    virtual ~record();
    record<T> operator=(const record<T> &other);
    bool operator==(const record<T> &other);
    T getData() const;
    void setData(T d);
    unsigned long long int getNext() const;
    void setNext(unsigned long long int n);
    bool isDeleted() const;
    void del();
    void undel();
    virtual string toString();
    virtual void fromString(string repr);
    virtual string toCSV();
    virtual void fromCSV(string repr);
    virtual string toJSON();
    virtual void fromJSON(string repr);
    virtual string toXML();
    virtual void fromXML(string repr);
    virtual unsigned long long int size() const;

protected:
    T data;
    bool deleted;
    unsigned long long int next;
};

template <class T>
record<T>::record() : serializable() {
    // Initialize the data members as needed
    data = T();
    deleted = false;
    next = 0;
}

template <class T>
record<T>::record(T d) : serializable() {
    data = d;
    deleted = false;
    next = 0;
}

template <class T>
record<T>::record(const record<T> &other) {
    data = other.data;
    deleted = other.deleted;
    next = other.next;
}

template <class T>
record<T>::~record() {
    // Destructor implementation as needed
}

template <class T>
record<T> record<T>::operator=(const record<T> &other) {
    if (this == &other) {
        return *this;
    }
    data = other.data;
    deleted = other.deleted;
    next = other.next;
    return *this;
}

template <class T>
bool record<T>::operator==(const record<T> &other) {
    return data == other.data && deleted == other.deleted && next == other.next;
}

template <class T>
T record<T>::getData() const {
    return data;
}

template <class T>
void record<T>::setData(T d) {
    data = d;
}

template <class T>
unsigned long long int record<T>::getNext() const {
    return next;
}

template <class T>
void record<T>::setNext(unsigned long long int n) {
    next = n;
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
string record<T>::toString() {
    // Serialization logic as needed
    return data.toString(); // Assuming that T has a toString method
}

template <class T>
void record<T>::fromString(string repr) {
    // Deserialization logic as needed
    data.fromString(repr); // Assuming that T has a fromString method
}

template <class T>
string record<T>::toCSV() {
    // CSV serialization logic as needed
    return data.toCSV(); // Assuming that T has a toCSV method
}

template <class T>
void record<T>::fromCSV(string repr) {
    // CSV deserialization logic as needed
    data.fromCSV(repr); // Assuming that T has a fromCSV method
}

template <class T>
string record<T>::toJSON() {
    // JSON serialization logic as needed
    return data.toJSON(); // Assuming that T has a toJSON method
}

template <class T>
void record<T>::fromJSON(string repr) {
    // JSON deserialization logic as needed
    data.fromJSON(repr); // Assuming that T has a fromJSON method
}

template <class T>
string record<T>::toXML() {
    // XML serialization logic as needed
    return data.toXML(); // Assuming that T has a toXML method
}

template <class T>
void record<T>::fromXML(string repr) {
    // XML deserialization logic as needed
    data.fromXML(repr); // Assuming that T has a fromXML method
}

template <class T>
unsigned long long int record<T>::size() const {
    // Size calculation logic as needed
    return data.size(); // Assuming that T has a size method
}

#endif // RECORD_H
