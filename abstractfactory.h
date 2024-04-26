#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <memory>
#include <string>

class Unit;

class AbstractFactory {
public:
    virtual std::shared_ptr<Unit> createClassUnit(const std::string& name) = 0;
    virtual std::shared_ptr<Unit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;
    virtual std::shared_ptr<Unit> createPrintOperatorUnit(const std::string& text) = 0;
    virtual ~AbstractFactory() = default;
};

#endif // ABSTRACTFACTORY_H

