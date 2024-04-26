#ifndef JAVACLASS_H
#define JAVACLASS_H
#include <string>

class JavaClass  {
public:
    explicit JavaClass(const std::string& name);
    std::string compile(unsigned int level = 0) const;

private:
    std::string m_name;
    // Дополнительные члены-данные, необходимые для Java-класса
};

#endif // JAVACLASS_H
