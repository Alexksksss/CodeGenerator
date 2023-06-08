#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H
#include "printoperatorunit.h"

class JavaPrintOperatorUnit: public PrintOperatorUnit
{
public:
    JavaPrintOperatorUnit( const std::string& text ):PrintOperatorUnit(text){}
    std::string compile(unsigned int level = 0) const{
            return generateShift(level) + "System.out.println(\"" + GetText() + "\");\n";
    }
};
#endif // JAVAPRINTOPERATORUNIT_H
