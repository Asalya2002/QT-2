#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

class PrintOperatorUnit : public Unit {
public:
    // Конструктор, который принимает текст, который будет выводиться
    // Этот текст сохраняется в приватном поле m_text
    explicit PrintOperatorUnit(const std::string& text) : m_text(text) { }

    // Метод, который генерирует код для вывода текста на консоль
    std::string compile(unsigned int level = 0) const {
        // Использует вспомогательную функцию generateShift, чтобы сделать отступы
        // в соответствии с уровнем вложенности
        return generateShift(level) + "printf(\"" + m_text + "\");\n";
    }

private:
    // Приватное поле, хранящее текст, который будет выводиться
    std::string m_text;
};


#endif // PRINTOPERATORUNIT_H
