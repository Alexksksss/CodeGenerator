#ifndef METHODUNIT_H
#define METHODUNIT_H
#include "unit.h"
#include <vector>
class MethodUnit : public Unit
{
public:
    enum Modifier {
        STATIC,
        CONST,
        VIRTUAL
    };
public:
    MethodUnit(const std::string& name, const std::string& returnType, Flags flags) :m_name(name), m_returnType(returnType), m_flags(flags){}
    void add(const std::shared_ptr< Unit >& unit, Flags  = 0){
        m_body.push_back(unit);
    }

    // геттеры
    std::string GetName()const{return m_name;}
    std::string GetType()const{return m_returnType;}
    Flags GetFlags()const{return m_flags;}
    std::vector< std::shared_ptr<Unit>> GetBody()const{return m_body;}
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr<Unit>> m_body;
};
#endif // METHODUNIT_H
