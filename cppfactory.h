#ifndef CPPFACTORY_H
#define CPPFACTORY_H
#include"abstractfactory.h"
#include "cppclassunit.h"
#include "cppmethodunit.h"
#include "cppprintoperatorunit.h"
class CppFactory: public AbstractFactory
{
public:
    std::shared_ptr<ClassUnit> CreateClass(const std::string& name)
    {
        return std::shared_ptr<ClassUnit>(new CppClassUnit(name));
    }
    std::shared_ptr<MethodUnit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags)
    {
        return std::shared_ptr<MethodUnit>(new CppMethodUnit(name,returnType, flags));
    }
    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string& text)
    {
        return std::shared_ptr<PrintOperatorUnit>(new CppPrintOperatorUnit(text));
    }
};
#endif // CPPFACTORY_H
