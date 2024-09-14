/**
 * Шаблонный Print
 *
 * Вам надо написать функцию Print, которая умеет печатать в поток std::cout элементы переданного
 * контейнера через указанную строку-разделитель. Первый аргумент функции — контейнер. Гарантируется,
 * что по этому контейнеру можно проитерироваться с помощью стандартного цикла range-based for, и что
 * элементы контейнера можно напечатать в поток std::cout с помощью стандартного оператора <<.
 * Второй аргумент функции — строка-разделитель, которую надо печатать между элементами. В конце
 * необходимо напечатать перевод строки \n.
 *
 * Пример вызова:
 * int main() {
 *     std::vector<int> data = {1, 2, 3, 4};
 *     Print(data, ", ");  // 1, 2, 3, 4
 * }
 *
 * Примечание
 * В вашем решении должен быть только код функции Print без функции main. Подключите все необходимые
 * для реализации библиотеки. Используйте константные ссылки для получения параметров и при итерации
 * в цикле, чтобы избежать лишних копирований: если этого не сделать, то программа не скомпилируется.
 */

#include <iostream>
#include <vector>
#include <string>

template <typename List>
void Print(const List &data, const std::string delimiter);

int main()
{
    std::vector<int> data = {1, 2, 3, 4};
    Print(data, ", "); // 1, 2, 3, 4
}

template <typename List>
void Print(const List &data, const std::string delimiter)
{
    bool visitedFirst = false;
    for (const auto &item : data)
    {
        if (visitedFirst)
        {
            std::cout << delimiter;
        }
        else
        {
            visitedFirst = true;
        }
        std::cout << item;
    }

    std::cout << std::endl;
}