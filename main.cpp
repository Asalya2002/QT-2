#include "unit.h"
#include "methodunit.h"
#include "classunit.h"
#include <QApplication>
#include <iostream>
#include <string>
#include "abstractclassfactory.h"
#include "abstractmethodfactory.h"
#include <memory>
#include "csharpclassfactory.h"
#include "csharpmethodfactory.h"
#include "javaclassfactory.h"
#include "javamethodfactory.h"
#include "printoperatorunit.h"

// Использование фабрик для создания программ на C# и Java
void generateCSharpProgram() {
    // Создание фабрик для C#
    std::shared_ptr<AbstractClassFactory> csharpClassFactory = std::make_shared<CSharpClassFactory>();
    std::shared_ptr<AbstractMethodFactory> csharpMethodFactory = std::make_shared<CSharpMethodFactory>();

    // Создание классов и методов для C#
    auto myClass = csharpClassFactory->createClassUnit("MyClass");
    myClass->add(csharpMethodFactory->createMethodUnit("testFunc1", "void", 0), ClassUnit::PUBLIC);
    myClass->add(csharpMethodFactory->createMethodUnit("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);
    myClass->add(csharpMethodFactory->createMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);
    auto method = csharpMethodFactory->createMethodUnit("testFunc4", "void", MethodUnit::STATIC);
    method->add(std::make_shared<PrintOperatorUnit>("Hello, world!"));
    myClass->add(method, ClassUnit::PROTECTED);

    // Вывод C# программы
    std::cout << "C# Program:\n" << myClass->compile() << std::endl;
}

void generateJavaProgram() {
    // Создание фабрик для Java
    std::shared_ptr<AbstractClassFactory> javaClassFactory = std::make_shared<JavaClassFactory>();
    std::shared_ptr<AbstractMethodFactory> javaMethodFactory = std::make_shared<JavaMethodFactory>();

    // Создание классов и методов для Java
    auto myClass = javaClassFactory->createClassUnit("MyClass");
    myClass->add(javaMethodFactory->createMethodUnit("testFunc1", "void", 0), ClassUnit::PUBLIC);
    myClass->add(javaMethodFactory->createMethodUnit("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);
    myClass->add(javaMethodFactory->createMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);
    auto method = javaMethodFactory->createMethodUnit("testFunc4", "void", MethodUnit::STATIC);
    method->add(std::make_shared<PrintOperatorUnit>("Hello, world!"));
    myClass->add(method, ClassUnit::PROTECTED);

    // Вывод Java программы
    std::cout << "Java Program:\n" << myClass->compile() << std::endl;
}

int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
    generateCSharpProgram();
    generateJavaProgram();
    return app.exec();
}
