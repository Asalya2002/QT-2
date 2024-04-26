#ifndef ABSTRACTMETHODFACTORY_H
#define ABSTRACTMETHODFACTORY_H
#include "methodunit.h"
#include <QWidget>

// Интерфейс AbstractMethodFactory
class AbstractMethodFactory {
public:
    // Чисто виртуальный метод, который должен быть реализован в конкретной реализации фабрики
    // Он возвращает объект типа std::shared_ptr<MethodUnit>, созданный с использованием имени, типа возвращаемого значения и флагов, переданных в качестве аргументов
    virtual std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, MethodUnit::Flags flags) = 0;
};

#endif // ABSTRACTMETHODFACTORY_H
