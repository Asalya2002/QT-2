#ifndef METHODUNIT_H
#define METHODUNIT_H

#include "Unit.h"
#include <string>
#include <vector>
#include <memory>
#include "unit.h"
// Класс MethodUnit, производный от Unit
class MethodUnit : public Unit {
public:
    // Перечисление, определяющее модификаторы для методов
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

public:
    // Конструктор, принимающий имя метода, тип возвращаемого значения и флаги
    MethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
        m_name(name), m_returnType(returnType), m_flags(flags) {}

    // Метод, добавляющий Unit-объект в тело метода
    void add(const std::shared_ptr<Unit>& unit, Flags /* flags */ = 0) {
        m_body.push_back(unit);
    }

    // Метод, генерирующий код метода
    std::string compile(unsigned int level = 0) const {
        std::string result = generateShift(level); // Формируем отступ
        // Добавляем модификаторы доступа в зависимости от флагов
        if (m_flags & STATIC) {
            result += "static ";
        } else if (m_flags & VIRTUAL) {
            result += "virtual ";
        }
        result += m_returnType + " "; // Добавляем тип возвращаемого значения
        result += m_name + "()"; // Добавляем имя метода и параметры
        if (m_flags & CONST) {
            result += " const"; // Добавляем модификатор const, если он установлен
        }
        result += " {\n"; // Начинаем тело метода
        for (const auto& b : m_body) { // Проходим по всем элементам тела метода
            result += b->compile(level + 1); // Рекурсивно вызываем compile() для каждого элемента
        }
        result += generateShift(level) + "}\n"; // Завершаем тело метода
        return result;
    }

protected:
    std::string m_name; // Хранит имя метода
    std::string m_returnType; // Хранит тип возвращаемого значения
    Flags m_flags; // Хранит флаги модификаторов метода
    std::vector<std::shared_ptr<Unit>> m_body; // Хранит тело метода в виде вектора shared_ptr на Unit-объекты
};
#endif // METHODUNIT_H
