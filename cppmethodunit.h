#ifndef CPPMETHODUNIT_H
#define CPPMETHODUNIT_H

#include "methodunit.h"

class CppMethodUnit: public MethodUnit
{
public:
    CppMethodUnit(const std::string& name, const std::string& returnType, Flags flags):MethodUnit(name,returnType,flags){}
    std::string compile( unsigned int level = 0 ) const{
        std::string result = generateShift(level);
        if(GetFlags() & STATIC)
            result += "static ";
        else if(GetFlags() & VIRTUAL)
            result += "virtual ";
        result += GetType() + " ";
        result += GetName() + "()";
        if(GetFlags() & CONST)
            result += " const";
        result += " {\n";
        for(const auto& b : GetBody() )
            result += b->compile(level + 1);
        result += generateShift(level) + "}\n";
        return result;
    }
};

#endif // CPPMETHODUNIT_H
