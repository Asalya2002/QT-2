#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include "Unit.h"
#include <string>
#include <vector>
#include <memory>
// Класс ClassUnit, производный от Unit
class ClassUnit : public Unit
{public:
    // Перечисление, определяющее модификаторы доступа
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE};
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    // Конструктор, принимающий имя класса
    explicit ClassUnit( const std::string& name ) : m_name( name ) {
        // Инициализируем вектор m_fields размером, равным количеству модификаторов доступа
        m_fields.resize( ACCESS_MODIFIERS.size() );}
    // Метод, добавляющий Unit-объект с заданными флагами
    void add(const std::shared_ptr<Unit>& unit, Flags flags) {
        int accessModifier = PRIVATE; // Инициализируем модификатор доступа значением PRIVATE
        if (flags < ACCESS_MODIFIERS.size()) { // Если флаги соответствуют допустимым модификаторам
            accessModifier = flags; // Устанавливаем modifierAccess равным флагам
        }
        m_fields[accessModifier].push_back(unit); // Добавляем Unit-объект в соответствующий вектор
    }
    // Метод, генерирующий код класса
    std::string compile(unsigned int level = 0) const {
        std::string result = generateShift(level) + "class " + m_name + " {\n"; // Начинаем генерацию кода класса
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
        result += generateShift(level) + "};\n"; // Завершаем генерацию кода класса
        return result;
    }

protected:
    std::string m_name; // Хранит имя класса
    // Вектор векторов shared_ptr на Unit-объекты, разделенных по модификаторам доступа
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

#endif // CLASSUNIT_H
