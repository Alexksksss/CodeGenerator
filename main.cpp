#include "unit.h"
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "abstractfactory.h"
#include "cppfactory.h"
#include "sharpfactory.h"
#include "javafactory.h"

std::string generateProgram(std::shared_ptr<AbstractFactory> factory)
{
    auto myClass = factory->CreateClass("MyClass");
    myClass->add(factory->CreateMethod("testFunc1", "void", 0 ),ClassUnit::PUBLIC);
    myClass->add(factory->CreateMethod("testFunc2", "void", MethodUnit::STATIC ),ClassUnit::PRIVATE);
    myClass->add(factory->CreateMethod("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),ClassUnit::PUBLIC);
    myClass->add(factory->CreateMethod("testFunc5", "void", MethodUnit::VIRTUAL),ClassUnit::INTERNAL); // должен только для шарпа
    myClass->add(factory->CreateMethod("testFunc6", "void", MethodUnit::ABSTRACT),ClassUnit::PROTECTED); // должен только для java

    std::shared_ptr< MethodUnit > method = factory->CreateMethod( "testFunc4", "void", MethodUnit::STATIC );
    method->add(factory->CreatePrintOperator( R"(Hello, world!\n)" ) );
    myClass->add(method, ClassUnit::PROTECTED);

    return myClass->compile();
}

int main()
{
    std::cout << generateProgram(std::make_shared<CppFactory>()) << std::endl;
    std::cout << "------------------------------------------------\n" << std::endl;
    std::cout << generateProgram(std::make_shared<SharpFactory>()) << std::endl;
    std::cout << "------------------------------------------------\n" << std::endl;
    std::cout << generateProgram(std::make_shared<JavaFactory>()) << std::endl;
    return 0;
}
