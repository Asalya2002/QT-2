#ifndef ABSTRACTCLASSFACTORY_H
#define ABSTRACTCLASSFACTORY_H
#include "classunit.h"
#include <QWidget>

// Интерфейс AbstractClassFactory
class AbstractClassFactory {
public:
    // Чисто виртуальный метод, который должен быть реализован в конкретной реализации фабрики
    // Он возвращает объект типа std::shared_ptr<ClassUnit>, созданный с использованием имени, переданного в качестве аргумента
    virtual std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) = 0;
};

#endif // ABSTRACTCLASSFACTORY_H
