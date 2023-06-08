#ifndef SHARPMETHODUNIT_H
#define SHARPMETHODUNIT_H

#include "methodunit.h"

class SharpMethodUnit: public MethodUnit
{
public:
    SharpMethodUnit(const std::string& name, const std::string& returnType, Flags flags):MethodUnit(name,returnType,flags){}
    std::string compile( unsigned int level = 0) const{
        std::string result = generateShift(level);
        if(GetFlags() & STATIC)
            result += "static ";
        else if(GetFlags() & VIRTUAL)
            result += "virtual ";
        result += GetType() + " ";
        result += GetName() + "()";
        result += " {\n";
        for(const auto& b : GetBody() )
            result += b->compile(level + 1);
        result += generateShift(level) + "}\n";
        return result;
    }
};
#endif // SHARPMETHODUNIT_H
//С# не поддерживает CONST
