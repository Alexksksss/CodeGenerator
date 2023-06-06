#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H
#include "classunit.h"
class JavaClassUnit:public ClassUnit
{
public:
    JavaClassUnit(const std::string& name):ClassUnit(name){}
    std::string compile( unsigned int level = 0 ) const{
        std::string result = generateShift( level ) + "class " + m_name + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( m_fields[i].empty() ) {
                continue;
            }

            for( const auto& f :m_fields[i] ) {
                result += generateShift( level+1)+ACCESS_MODIFIERS[ i ] + " ";
                result += f->compile( level );
            }
            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    }
};

#endif // JAVACLASSUNIT_H
