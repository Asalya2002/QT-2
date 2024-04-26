#ifndef ABSTRACTUNITFACTORY_H
#define ABSTRACTUNITFACTORY_H

// Абстрактная фабрика
class AbstractUnitFactory {
public:
    virtual std::shared_ptr<AbstractClass> createClass(const std::string& name) = 0;
    virtual std::shared_ptr<AbstractMethod> createMethod(const std::string& name, const std::string& returnType, MethodUnit::Flags flags) = 0;
    virtual std::shared_ptr<AbstractPrintOperator> createPrintOperator(const std::string& text) = 0;
    virtual ~AbstractUnitFactory() = default;
};

#endif // ABSTRACTUNITFACTORY_H
