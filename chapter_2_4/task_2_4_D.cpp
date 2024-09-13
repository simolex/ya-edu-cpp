/**
 * Сортировка по убыванию
 *
 * Вам даны строки текстового файла. Отсортируйте набор этих строк по убыванию.
 *
 * Формат ввода
 * Количество строк не превосходит 1000. Каждая строка состоит из символов ASCII с кодами от 32 до 126,
 * длина строки не превосходит 100.
 *
 * Формат вывода
 * Напечатайте строки в отсортированном по убыванию порядке. Для сравнения строк друг с другом достаточно использовать
 * стандартные операторы сравнения, определённые для std::string.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string line;
    std::vector<std::string> list;

    while (std::getline(std::cin, line))
    {
        list.push_back(line);
    }

    std::sort(list.begin(), list.end(), [](auto a, auto b)
              { return a > b; });

    for (auto line : list)
    {
        std::cout << line << std::endl;
    }
}
