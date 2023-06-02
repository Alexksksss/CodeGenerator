#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "unit.h"
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
class AbstractFactory
{
public:
    // Создание класса с заданным именем
    virtual std::shared_ptr<ClassUnit> CreateClass(const std::string& name) = 0;
    // Создание метода с заданным именем, типом возвращаемого значения и флагами
    virtual std::shared_ptr<MethodUnit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags) = 0;
    // Создание оператора вывода с заданным текстом
    virtual std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string& text) = 0;
    // Виртуальный деструктор
    virtual~AbstractFactory()=default;
};
#endif // ABSTRACTFACTORY_H
