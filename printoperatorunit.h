#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include "Unit.h"
class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit(const std::string& text) : m_text(text){}
    std::string GetText()const{return m_text;}
private:
    std::string m_text;
};
#endif // PRINTOPERATORUNIT_H
