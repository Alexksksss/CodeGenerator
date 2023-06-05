#ifndef SHARPFACTORY_H
#define SHARPFACTORY_H
#include"abstractfactory.h"
#include "sharpclassunit.h"
#include "sharpmethodunit.h"
#include "sharpprintoperatorunit.h"
class SharpFactory: public AbstractFactory
{
public:
    std::shared_ptr<ClassUnit> CreateClass(const std::string& name)
    {
        return std::shared_ptr<ClassUnit>(new SharpClassUnit(name));
    }
    std::shared_ptr<MethodUnit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags)
    {
        return std::shared_ptr<MethodUnit>(new SharpMethodUnit(name,returnType, flags));
    }
    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string& text)
    {
        return std::shared_ptr<PrintOperatorUnit>(new SharpPrintOperatorUnit(text));
    }
};
#endif // SHARPFACTORY_H
