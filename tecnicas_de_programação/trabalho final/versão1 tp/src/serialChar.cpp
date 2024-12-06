#include "serialChar.h"

serialChar::serialChar() : serializable() {
    this->value = '\0';
}

serialChar::serialChar(char c) : serializable() {
    this->value = c;
}

serialChar::serialChar(const serialChar& other) {
    this->value = other.value;
}

serialChar::~serialChar() {
}

serialChar serialChar::operator=(const serialChar& other) {
    this->value = other.value;
    return *this;
}

bool serialChar::operator==(const serialChar& other) const {
    return this->value == other.value;
}

bool serialChar::operator<(const serialChar& other) const {
    return this->value < other.value;
}

bool serialChar::operator<=(const serialChar& other) const {
    return this->value <= other.value;
}

bool serialChar::operator>(const serialChar& other) const {
    return this->value > other.value;
}

bool serialChar::operator>=(const serialChar& other) const {
    return this->value >= other.value;
}

bool serialChar::operator!=(const serialChar& other) const {
    return this->value != other.value;
}

serialChar serialChar::operator+(const serialChar& other) const {
    return serialChar(this->value + other.value);
}

serialChar serialChar::operator-(const serialChar& other) const {
    return serialChar(this->value - other.value);
}

serialChar serialChar::operator*(const serialChar& other) const {
    return serialChar(this->value * other.value);
}

serialChar serialChar::operator/(const serialChar& other) const {
    return serialChar(this->value / other.value);
}

serialChar serialChar::operator++() {
    this->value++;
    return *this;
}

serialChar serialChar::operator--() {
    this->value--;
    return *this;
}

void serialChar::setValue(char c) {
    this->value = c;
}

char serialChar::getValue() const {
    return this->value;
}

std::string serialChar::toString() {
    return std::string(1, this->value);
}

void serialChar::fromString(std::string repr) {
    if (!repr.empty()) {
        this->value = repr[0];
    }
}

std::string serialChar::toXML() {
    return "<char>" + std::string(1, this->value) + "</char>";
}

void serialChar::fromXML(std::string repr) {
    if (repr.length() >= 7) {
        this->value = repr[6];
    }
}

std::string serialChar::toCSV() {
    return std::string(1, this->value) + ",";
}

void serialChar::fromCSV(std::string repr) {
    if (!repr.empty()) {
        this->value = repr[0];
    }
}

std::string serialChar::toJSON() {
    return "{\"value\":\"" + std::string(1, this->value) + "\"}";
}

void serialChar::fromJSON(std::string repr) {
    if (repr.length() >= 15) {
        this->value = repr[10];
    }
}

unsigned long long int serialChar::size() const {
    return sizeof(char);
}
