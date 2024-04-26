#ifndef JAVAMETHOD_H
#define JAVAMETHOD_H

#include "AbstractUnit.h"
#include <string>

class JavaMethod : public AbstractMethod {
public:
    JavaMethod(const std::string& name, const std::string& returnType, MethodUnit::Flags flags);
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::string m_returnType;
    MethodUnit::Flags m_flags;
    // Дополнительные члены-данные, необходимые для Java-метода
};

#endif // JAVAMETHOD_H
