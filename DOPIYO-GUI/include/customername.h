#ifndef CUSTOMERNAME_H
#define CUSTOMERNAME_H

#include <QString>

class CustomerName
{
public:
    static CustomerName& instance(){
        static CustomerName instance;
        return instance;
    }
    void setName(const std::string& n) {name = n;}
    std::string getName() const { return name; }

private:
    CustomerName(){}
    std::string name;
};

#endif // CUSTOMERNAME_H
