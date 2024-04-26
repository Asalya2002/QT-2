#ifndef CSHARPMETHODFACTORY_H
#define CSHARPMETHODFACTORY_H

#include "abstractmethodfactory.h"
#include "csharpmethodunit.h"

// Класс CSharpMethodFactory, реализующий интерфейс AbstractMethodFactory
class CSharpMethodFactory : public AbstractMethodFactory {
public:
    // Реализация чисто виртуального метода createMethodUnit() из интерфейса AbstractMethodFactory
    // Он создает и возвращает объект типа CSharpMethodUnit с использованием переданных имени, типа возвращаемого значения и флагов
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, MethodUnit::Flags flags) override {
        return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
    }
};

#endif // CSHARPMETHODFACTORY_H

