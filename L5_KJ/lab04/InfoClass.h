#pragma once
#include <string>

class InfoClass
{
public:
    InfoClass(const std::string &);
    virtual ~InfoClass();
    virtual std::string info() const;
    void info(const std::string &);

protected:
    std::string m_info;
};


class InfoSuperClass : public InfoClass
{
public:
    InfoSuperClass(const std::string& , int);
    ~InfoSuperClass();
    std::string info() const;

private:
    int m_number;
};