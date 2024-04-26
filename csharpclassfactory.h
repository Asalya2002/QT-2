#ifndef CSHARPCLASSFACTORY_H
#define CSHARPCLASSFACTORY_H
#include "classunit.h"
#include "abstractclassfactory.h"
#include "csharpclassunit.h"

// Класс CSharpClassFactory, реализующий интерфейс AbstractClassFactory
class CSharpClassFactory : public AbstractClassFactory {
public:
    // Реализация чисто виртуального метода createClassUnit() из интерфейса AbstractClassFactory
    // Он создает и возвращает объект типа CSharpClassUnit с использованием переданного имени
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) override {
        return std::make_shared<CSharpClassUnit>(name);
    }
};

#endif // CSHARPCLASSFACTORY_H
