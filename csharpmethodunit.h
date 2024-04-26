#ifndef CSHARPMETHODUNIT_H
#define CSHARPMETHODUNIT_H

#include "methodunit.h"
#include <string>

// Класс CSharpMethodUnit, производный от MethodUnit
class CSharpMethodUnit : public MethodUnit {
public:
    // Конструктор, принимающий имя метода, тип возвращаемого значения и флаги
    // и передающий их в конструктор базового класса MethodUnit
    CSharpMethodUnit(const std::string& name, const std::string& returnType, Flags flags)
        : MethodUnit(name, returnType, flags) {}

    // Переопределение виртуального метода compile() из базового класса
    std::string compile(unsigned int level = 0) const override {
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
};

#endif // CSHARPMETHODUNIT_H

