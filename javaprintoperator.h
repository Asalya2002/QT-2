#ifndef JAVAPRINTOPERATOR_H
#define JAVAPRINTOPERATOR_H

#include "AbstractUnit.h"
#include <string>

class JavaPrintOperator : public AbstractPrintOperator {
public:
    explicit JavaPrintOperator(const std::string& text);
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};

#endif // JAVAPRINTOPERATOR_H
