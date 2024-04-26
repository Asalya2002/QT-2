#ifndef UNIT_H
#define UNIT_H

#include <QMainWindow>

class Unit {
public:
    // Используем Flags как псевдоним для unsigned int
    using Flags = unsigned int;

public:
    // Виртуальный деструктор по умолчанию
    virtual ~Unit() = default;

    // Виртуальный метод add, который бросает исключение, если не поддерживается
    virtual void add(const std::shared_ptr<Unit>&, Flags) {
        throw std::runtime_error("Not supported");
    }

    // Чисто виртуальный метод compile, который должен быть реализован в производных классах
    virtual std::string compile(unsigned int level = 0) const = 0;

protected:
    // Виртуальный метод generateShift, который генерирует отступ для вывода кода
    virtual std::string generateShift(unsigned int level) const {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for (unsigned int i = 0; i < level; ++i) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

#endif // UNIT_H
