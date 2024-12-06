#include "headers.h"

header::header() : serializable() {
    type = "***";
    firstDeleted = 0;
    firstValid = 0;
    version = 0;
}

header::header(const std::string t, unsigned int v) : serializable() {
    type = t.substr(0, 3);
    firstDeleted = 0;
    firstValid = 0;
    version = v;
}

header::header(const header &h) {
    type = h.getType();
    firstDeleted = h.getFirstDeleted();
    firstValid = h.getFirstValid();
    version = h.getVersion();
}

header::~header() {
}

header header::operator=(const header &h) {
    header aux(h);
    if (this == &h)
        return *this;

    type = h.getType();
    firstDeleted = h.getFirstDeleted();
    firstValid = h.getFirstValid();
    version = h.getVersion();

    return aux;
}

bool header::operator==(const header &h) {
    return type == h.getType() && version == h.getVersion() &&
           firstDeleted == h.getFirstDeleted() &&
           firstValid == h.getFirstValid();
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

std::string header::getType() const {
    return type;
}

void header::setType(std::string t) {
    type = t.substr(0, 3);
}

unsigned int header::getVersion() const {
    return version;
}

void header::setVersion(unsigned int v) {
    version = v;
}

std::string header::toString() {
    std::string aux = "";
    aux += type;
    aux += std::string(reinterpret_cast<char*>(&version), sizeof(version));
    aux += std::string(reinterpret_cast<char*>(&firstValid), sizeof(firstValid));
    aux += std::string(reinterpret_cast<char*>(&firstDeleted), sizeof(firstDeleted));
    return aux;
}

void header::fromString(std::string repr) {
    int pos = 0;
    type = repr.substr(pos, 3);
    pos += type.length();
    repr.copy(reinterpret_cast<char*>(&version), sizeof(version), pos);
    pos += sizeof(version);
    repr.copy(reinterpret_cast<char*>(&firstValid), sizeof(firstValid), pos);
    pos += sizeof(firstValid);
    repr.copy(reinterpret_cast<char*>(&firstDeleted), sizeof(firstDeleted), pos);
}

unsigned long long int header::size() const {
    return type.length() + sizeof(version) + sizeof(firstValid) + sizeof(firstDeleted);
}
