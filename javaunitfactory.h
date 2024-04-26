#ifndef JAVAUNITFACTORY_H
#define JAVAUNITFACTORY_H
#include "AbstractUnitFactory.h"
#include "javaclass.h"
#include "JavaMethod.h"
#include "JavaPrintOperator.h"

class JavaUnitFactory : public AbstractUnitFactory {
public:
    std::shared_ptr<AbstractClass> createClass(const std::string& name) override {
        return std::make_shared<JavaClass>(name);
    }

    std::shared_ptr<AbstractMethod> createMethod(const std::string& name, const std::string& returnType, MethodUnit::Flags flags) override {
        return std::make_shared<JavaMethod>(name, returnType, flags);
    }

    std::shared_ptr<AbstractPrintOperator> createPrintOperator(const std::string& text) override {
        return std::make_shared<JavaPrintOperator>(text);
    }
};

#endif // JAVAUNITFACTORY_H
