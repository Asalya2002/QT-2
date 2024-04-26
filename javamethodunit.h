#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H
#include "methodunit.h"
#include <QWidget>

// Пример обновления MethodUnit для Java
class JavaMethodUnit : public MethodUnit {
public:
// Конструктор, принимающий имя метода, тип возвращаемого значения и флаги
// и передающий их в конструктор базового класса MethodUnit
JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags) : MethodUnit(name, returnType, flags) {}

// Переопределение виртуального метода compile() из базового класса
std::string compile(unsigned int level = 0) const override {
    std::string result = generateShift(level); // Формируем отступ
    // Добавляем модификаторы доступа в зависимости от флагов
    if (m_flags & STATIC) {
        result += "static ";
    } else if (m_flags & VIRTUAL) {
        result += "abstract ";
    }
    if (m_flags & CONST) {
        result += "final ";
    }
    result += m_returnType + " " + m_name + "() {\n"; // Добавляем тип возвращаемого значения, имя метода и параметры
    for (const auto& b : m_body) { // Проходим по всем элементам тела метода
        result += b->compile(level + 1); // Рекурсивно вызываем compile() для каждого элемента
    }
    result += generateShift(level) + "}\n"; // Завершаем тело метода
    return result;
}
};

#endif // JAVAMETHODUNIT_H
