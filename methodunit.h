#ifndef METHODUNIT_H
#define METHODUNIT_H
#include "unit.h"
#include <vector>
class MethodUnit : public Unit
{
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    MethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :m_name( name ), m_returnType( returnType ), m_flags( flags ){}
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ){
        m_body.push_back( unit );
    }
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
