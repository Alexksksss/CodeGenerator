#ifndef SHARPCLASSUNIT_H
#define SHARPCLASSUNIT_H
#include "classunit.h"

class SharpClassUnit: public ClassUnit
{
public:
    SharpClassUnit(const std::string& name):ClassUnit(name){}
    std::string compile(unsigned int level = 0) const{
        std::string result = generateShift(level) + "class " + GetName() + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if(GetFields(i).empty())
                continue;
            result += ACCESS_MODIFIERS[i] + ":\n";
            for(const auto& f :GetFields(i)){
                result += f->compile(level + 1);
                result += "\n";//пустая строка между методами
            }
        }
        result += generateShift(level) + "};\n";
        return result;
    }
};

#endif // SHARPCLASSUNIT_H
