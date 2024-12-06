#ifndef HEADERS_H
#define HEADERS_H

#include "serializable.h"

class header : public serializable {
public:
    header();
    header(const std::string t, unsigned int v);
    header(const header &h);
    virtual ~header();
    header operator=(const header &h);
    bool operator==(const header &h);
    unsigned long long int getFirstDeleted() const;
    void setFirstDeleted(unsigned long long int r);
    unsigned long long int getFirstValid() const;
    void setFirstValid(unsigned long long int r);
    std::string getType() const;
    void setType(std::string t);
    unsigned int getVersion() const;
    void setVersion(unsigned int v);
    virtual std::string toString() override;
    virtual void fromString(std::string repr) override;
    virtual unsigned long long int size() const override;

protected:
    std::string type;
    unsigned int version;
    unsigned long long int firstDeleted;
    unsigned long long int firstValid;
};

#endif // HEADERS_H
