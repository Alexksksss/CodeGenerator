#include "unit.h"
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "abstractfactory.h"
#include "cppfactory.h"

std::string generateProgram(std::shared_ptr<AbstractFactory> factory)
{
    auto myClass = factory->CreateClass("MyClass");
    myClass->add(factory->CreateMethod( "testFunc1", "void", 0 ),ClassUnit::PUBLIC);
    myClass->add(factory->CreateMethod( "testFunc2", "void", MethodUnit::STATIC ),ClassUnit::PRIVATE);
    myClass->add(factory->CreateMethod(  "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),ClassUnit::PUBLIC);

    std::shared_ptr< MethodUnit > method = factory->CreateMethod( "testFunc4", "void", MethodUnit::STATIC );
    method->add( factory->CreatePrintOperator( R"(Hello, world!\n)" ) );
    myClass->add(method, ClassUnit::PROTECTED);

    return myClass->compile();
}

int main()
{
    std::cout << generateProgram(std::make_shared<CppFactory>()) << std::endl;
    return 0;
}
