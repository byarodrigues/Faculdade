#include "intserial.h"

intSerial::intSerial() : serializable() {
  this->value = 0;
}

intSerial::intSerial(int i) : serializable() {
  this->value = i;
}

intSerial::intSerial(const intSerial& other) {
  this->value = other.value;
}

intSerial::~intSerial() {
}

intSerial intSerial::operator=(const intSerial& other) {
  this->value = other.value;
  return *this;
}

bool intSerial::operator==(const intSerial &other) const {
  return this->value == other.value;
}

bool intSerial::operator<(const intSerial &other) const {
  return this->value < other.value;
}

bool intSerial::operator<=(const intSerial &other) const {
  return this->value <= other.value;
}

bool intSerial::operator>(const intSerial &other) const {
  return this->value > other.value;
}

bool intSerial::operator>=(const intSerial &other) const {
  return this->value >= other.value;
}

bool intSerial::operator!=(const intSerial &other) const {
  return this->value != other.value;
}

intSerial intSerial::operator+(const intSerial& other) const {
  return intSerial(this->value + other.value);
}

intSerial intSerial::operator-(const intSerial& other) const {
  return intSerial(this->value - other.value);
}

intSerial intSerial::operator*(const intSerial& other) const {
  return intSerial(this->value * other.value);
}

intSerial intSerial::operator/(const intSerial& other) const {
  return intSerial(this->value / other.value);
}

intSerial intSerial::operator++() {
  this->value++;
  return *this;
}

intSerial intSerial::operator--() {
  this->value--;
  return *this;
}

void intSerial::setValue(int v) {
  this->value = v;
}

int intSerial::getValue() const {
  return this->value;
}

string intSerial::toString() {
  return to_string(this->value);
}

void intSerial::fromString(string repr) {
  this->value = stoi(repr);
}

string intSerial::toXML() {
  return "<int>" + to_string(this->value) + "</int>";
}

void intSerial::fromXML(string repr) {
  this->value = stoi(repr.substr(5, repr.length() - 6));
}

string intSerial::toCSV() {
  return to_string(this->value) + ",";
}

void intSerial::fromCSV(string repr) {
  this->value = stoi(repr.substr(0, repr.length() - 1));
}

string intSerial::toJSON() {
  return "{" + string("\"value\":").append(to_string(this->value)) + "}";
}

void intSerial::fromJSON(string repr) {
  this->value = stoi(repr.substr(7, repr.length() - 8));
}

unsigned long long int intSerial::size() const {
  return sizeof(int);
}
