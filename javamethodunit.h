#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H
#include "methodunit.h"

class JavaMethodUnit: public MethodUnit
{
public:
    JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags):MethodUnit(name,returnType,flags){}
    std::string compile( unsigned int level = 0) const{
        std::string result = generateShift(level);
        if(GetFlags() & ABSTRACT)
            result += "abstract ";
        else if(GetFlags() & STATIC)
            result += "static ";
        result += GetType() + " ";
        result += GetName() + "()";
        if(GetFlags() & FINAL)
            result += " final";
        result += " {\n";
        for(const auto& b : GetBody() )
            result += b->compile(level + 1);
        result += generateShift(level) + "}\n";
        return result;
    }
};
#endif // JAVAMETHODUNIT_H
