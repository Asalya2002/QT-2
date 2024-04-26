#ifndef JAVAMETHODFACTORY_H
#define JAVAMETHODFACTORY_H
#include "abstractmethodfactory.h"
#include <QWidget>
#include "methodunit.h"
#include "javamethodunit.h"
// JavaMethodFactory
class JavaMethodFactory : public AbstractMethodFactory {
public:
    // Реализация чисто виртуального метода createMethodUnit() из интерфейса AbstractMethodFactory
    // Он создает и возвращает объект типа JavaMethodUnit с использованием переданных имени, типа возвращаемого значения и флагов
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, MethodUnit::Flags flags) override {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }
};
#endif // JAVAMETHODFACTORY_H
