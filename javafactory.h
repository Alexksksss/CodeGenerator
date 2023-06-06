#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H
#include"abstractfactory.h"
#include "javaclassunit.h"
#include "javamethodunit.h"
#include "javaprintoperatorunit.h"
class JavaFactory: public AbstractFactory
{
public:
    std::shared_ptr<ClassUnit> CreateClass(const std::string& name)
    {
        return std::shared_ptr<ClassUnit>(new JavaClassUnit(name));
    }
    std::shared_ptr<MethodUnit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags)
    {
        return std::shared_ptr<MethodUnit>(new JavaMethodUnit(name,returnType, flags));
    }
    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string& text)
    {
        return std::shared_ptr<PrintOperatorUnit>(new JavaPrintOperatorUnit(text));
    }
};
#endif // JAVAFACTORY_H
