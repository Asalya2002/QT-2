#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include "classunit.h"
#include <string>

// Класс JavaClassUnit, производный от ClassUnit
class JavaClassUnit : public ClassUnit {
public:
    // Конструктор, принимающий имя класса и передающий его в конструктор базового класса
    JavaClassUnit(const std::string& name) : ClassUnit(name) {}

    // Переопределение виртуального метода compile() из базового класса
    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level) + "public class " + m_name + " {\n"; // Начало генерации кода класса
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) { // Проходим по всем модификаторам доступа
            if (m_fields[i].empty()) { // Если вектор с данным модификатором пуст
                continue; // Переходим к следующему модификатору
            }
            result += ACCESS_MODIFIERS[i] + ":\n"; // Добавляем в результат строку с модификатором доступа
            for (const auto& f : m_fields[i]) { // Проходим по всем Unit-объектам в векторе
                result += f->compile(level + 1); // Рекурсивно вызываем compile() для каждого Unit-объекта
            }
            result += "\n"; // Добавляем пустую строку для разделения блоков
        }
        result += generateShift(level) + "}\n"; // Завершаем генерацию кода класса
        return result;
    }
};

#endif // JAVACLASSUNIT_H

