#ifndef CSHARPUNITFACTORY_H
#define CSHARPUNITFACTORY_H
#include "AbstractUnitFactory.h"
#include "CSharpClass.h"
#include "CSharpMethod.h"
#include "CSharpPrintOperator.h"

class CSharpUnitFactory : public AbstractUnitFactory {
public:
    std::shared_ptr<AbstractClass> createClass(const std::string& name) override {
        return std::make_shared<CSharpClass>(name);
    }

    std::shared_ptr<AbstractMethod> createMethod(const std::string& name, const std::string& returnType, MethodUnit::Flags flags) override {
        return std::make_shared<CSharpMethod>(name, returnType, flags);
    }

    std::shared_ptr<AbstractPrintOperator> createPrintOperator(const std::string& text) override {
        return std::make_shared<CSharpPrintOperator>(text);
    }
};

#endif // CSHARPUNITFACTORY_H
