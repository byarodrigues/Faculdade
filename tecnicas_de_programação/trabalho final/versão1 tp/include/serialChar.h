#ifndef SERIALCHAR_H
#define SERIALCHAR_H

#include "serializable.h"

class serialChar : public serializable {
public:
    serialChar();
    serialChar(char c);
    serialChar(const serialChar& other);
    virtual ~serialChar();
    serialChar operator=(const serialChar& other);
    bool operator==(const serialChar& other) const;
    bool operator<(const serialChar& other) const;
    bool operator<=(const serialChar& other) const;
    bool operator>(const serialChar& other) const;
    bool operator>=(const serialChar& other) const;
    bool operator!=(const serialChar& other) const;
    serialChar operator+(const serialChar& other) const;
    serialChar operator-(const serialChar& other) const;
    serialChar operator*(const serialChar& other) const;
    serialChar operator/(const serialChar& other) const;
    serialChar operator++();
    serialChar operator--();
    void setValue(char c);
    char getValue() const;
    virtual std::string toString() override;
    virtual void fromString(std::string repr) override;
    virtual std::string toXML() override;
    virtual void fromXML(std::string repr) override;
    virtual std::string toCSV() override;
    virtual void fromCSV(std::string repr) override;
    virtual std::string toJSON() override;
    virtual void fromJSON(std::string repr) override;
    virtual unsigned long long int size() const override;

protected:
    char value;
};

#endif // SERIALCHAR_H
