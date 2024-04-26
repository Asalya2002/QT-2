#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include "AbstractFactory.h"

class CppFactory : public AbstractFactory {
public:
    std::shared_ptr<Unit> createClassUnit(const std::string& name) override;
    std::shared_ptr<Unit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override;
    std::shared_ptr<Unit> createPrintOperatorUnit(const std::string& text) override;
};

#endif // CPPFACTORY_H

