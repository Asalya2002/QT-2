#ifndef JAVACLASSFACTORY_H
#define JAVACLASSFACTORY_H
#include "abstractclassfactory.h"
#include <QWidget>
#include "classunit.h"
#include "javaclassunit.h"
// JavaClassFactory
class JavaClassFactory : public AbstractClassFactory {
public:
    // Реализация чисто виртуального метода createClassUnit() из интерфейса AbstractClassFactory
    // Он создает и возвращает объект типа JavaClassUnit с использованием переданного имени
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) override {
        return std::make_shared<JavaClassUnit>(name);
    }
};

#endif // JAVACLASSFACTORY_H
