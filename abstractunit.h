#ifndef ABSTRACTUNIT_H
#define ABSTRACTUNIT_H

#include <string>
#include <memory>

class AbstractUnit {
public:
    virtual std::string compile(unsigned int level = 0) const = 0;
    virtual ~AbstractUnit() = default;
};

#endif // ABSTRACTUNIT_H
