#ifndef CPPUNITFACTORY_H
#define CPPUNITFACTORY_H


class CppUnitFactory : public AbstractUnitFactory {
public:
    std::shared_ptr<AbstractClass> createClass(const std::string& name) override {
        return std::make_shared<CppClass>(name);
    }
    std::shared_ptr<AbstractMethod> createMethod(const std::string& name, const std::string& returnType, MethodUnit::Flags flags) override {
        return std::make_shared<CppMethod>(name, returnType, flags);
    }
    std::shared_ptr<AbstractPrintOperator> createPrintOperator(const std::string& text) override {
        return std::make_shared<CppPrintOperator>(text);
    }
};

#endif // CPPUNITFACTORY_H
