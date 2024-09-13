/**
 * Палиндромы
 *
 * Дана строка из строчных латинских букв и пробелов. Проверьте, является ли она палиндромом без учета
 * пробелов.
 *
 * Формат ввода
 * На вход подается одна строка. В строке могут быть пробелы. Подряд может идти произвольное число
 * пробелов. Длина строки не превосходит 100.
 *
 * Формат вывода
 * Представьте, что из строки удалили все пробелы. Необходимо вывести YES, если полученная
 * строка — палиндром, и NO в противном случае.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum class Direction : int
{
    toFront = 1,
    toBack = -1
};

void moveAndSkipSpace(std::string &line, size_t &ptrLeft, size_t &prtRight, Direction dir)
{
    size_t *pointer;

    pointer = (dir == Direction::toFront ? &ptrLeft : &prtRight);

    *pointer += (int)dir;

    while (ptrLeft < prtRight && line[*pointer] == ' ')
    {
        *pointer += (int)dir;
    }
}

int main()
{
    std::string line;
    size_t ptrLeft, prtRight;
    bool isPalindrom = true;

    std::getline(std::cin, line);

    ptrLeft = -1;
    prtRight = line.length();

    moveAndSkipSpace(line, ptrLeft, prtRight, Direction::toFront);
    moveAndSkipSpace(line, ptrLeft, prtRight, Direction::toBack);

    while (ptrLeft < prtRight)
    {
        if (line[ptrLeft] != line[prtRight])
        {
            isPalindrom = false;
            break;
        }

        moveAndSkipSpace(line, ptrLeft, prtRight, Direction::toFront);
        moveAndSkipSpace(line, ptrLeft, prtRight, Direction::toBack);
    }

    std::cout
        << (isPalindrom ? "YES" : "NO") << std::endl;
}
