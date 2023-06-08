#ifndef SHARPPRINTOPERATORUNIT_H
#define SHARPPRINTOPERATORUNIT_H
#include "printoperatorunit.h"

class SharpPrintOperatorUnit: public PrintOperatorUnit
{
public:
    SharpPrintOperatorUnit( const std::string& text ):PrintOperatorUnit(text){}
    std::string compile(unsigned int level = 0) const{
            return generateShift(level) + "Console.WriteLine(\"" + GetText() + "\");\n";
    }
};
#endif // SHARPPRINTOPERATORUNIT_H
