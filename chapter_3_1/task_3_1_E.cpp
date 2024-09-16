/**
 * Ctrl+X, Ctrl+V - 2
 *
 * Эта задача — продолжение предыдущей задачи Ctrl+X, Ctrl+V. В качестве основы
 * вы можете взять код оттуда. Петя продолжает разработку своего текстового
 * редактора. На этот раз добавилось еще одна операция:
 * - зажать клавишу Shift (Shift).
 * Операции Up и Down при зажатой клавише Shift выделяют строки в текстовом
 * редакторе. Если курсор находится на строке n, то после операций Shift, Down,
 * Down выделенными окажутся строки n и n+1. Операция Ctrl+X вырезает
 * выделенные строки из файла в буфер. Операция Ctrl+V копирует строки из
 * буфера, заменяя выделенные строки в файле. Операции Ctrl+X и Ctrl+V
 * сбрасывают выделение после исполнения и отпускают клавишу Shift. Если при
 * исполнении этих операций в файле не выделена ни одна строка, поведение
 * должно соответствовать предыдущей задаче Ctrl+X, Ctrl+V.
 *
 * Формат ввода
 * Программе на вход подаётся набор строк, разделённых переносом строки. Длина
 * каждой строки не превышает 3000 символов. Последняя строка в файле является
 * пустой. Она означает завершение ввода файла. Других пустых строк в файле
 * быть не может. После этого и до окончания ввода программе подаются команды
 * Down, Up, Ctrl+X, Ctrl+V, Shift.
 *
 * Формат вывода
 * Выведите получившийся файл построчно.
 */

#include <iostream>
#include <list>
#include <string>

int
main()
{
    std::list<std::string> text;
    std::list<std::string> clipboard;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.length() == 0) {
            break;
        }
        text.push_back(line);
    }

    std::string command;
    auto current = text.begin();
    auto offsetCurrent = text.begin();
    bool isShift = false;

    while (std::getline(std::cin, command)) {
        if (command == "Up") {
            if (isShift) {
                if (offsetCurrent != text.begin()) {
                    offsetCurrent--;
                }
            } else {
                if (current != text.begin()) {
                    current--;
                }
            }
        } else if (command == "Down") {
            if (isShift) {
                if (offsetCurrent != text.end()) {
                    offsetCurrent++;
                }
            } else {
                if (current != text.end()) {
                    current++;
                }
            }
        } else if (command == "Ctrl+X") {
            if (current != text.end()) {
                clipboard.clear();
                if ((isShift && offsetCurrent == current) || !isShift) {
                    auto toSplice = current;
                    current = std::next(current);
                    clipboard.splice(clipboard.begin(), text, toSplice);
                } else if (isShift && offsetCurrent > 0) {
                } else if (isShift && offsetCurrent < 0) {
                }
            }
            isShift = false;
        } else if (command == "Ctrl+V") {
            text.insert(current, clipboard.begin(), clipboard.end());
            isShift = false;
        } else if (command == "Shift") {
            isShift = true;
            offsetCurrent = current;
        }
    }

    for (const auto& item : text) {
        std::cout << item << std::endl;
    }
}
