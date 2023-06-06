#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H
#include "classunit.h"
class JavaClassUnit:public ClassUnit
{
public:
    JavaClassUnit(const std::string& name):ClassUnit(name){}
    std::string compile( unsigned int level = 0 ) const{
        std::string result = generateShift(level) + "class " + GetName() + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size()-3; ++i ) {
            if(GetFields(i).empty())
                continue;
            result += ACCESS_MODIFIERS[i];
            for(const auto& f :GetFields(i)){
                result += f->compile(leve);
                result += "\n";//пустая строка между методами
            }
        }
        result += generateShift(level) + "};\n";
        return result;
    }
};


#endif // JAVACLASSUNIT_H
