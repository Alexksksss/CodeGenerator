#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H
#include "printoperatorunit.h"

class CppPrintOperatorUnit: public PrintOperatorUnit
{
public:
    CppPrintOperatorUnit( const std::string& text ):PrintOperatorUnit(text){}
    std::string compile(unsigned int level = 0) const{
            return generateShift(level) + "printf(\"" + GetText() + "\");\n";
    }
};
#endif // CPPPRINTOPERATORUNIT_H
