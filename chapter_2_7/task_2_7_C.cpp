/**
 * Функция Split
 * Вам требуется написать функцию со следующим заголовком:
 * std::vector<std::string> Split(const std::string& str, char delimiter);
 * Функция должна вернуть вектор строк, полученный разбиением строки str на части по указанному
 * символу-разделителю delimiter. Если разделитель встретился в начале или в конце строки str,
 * то в начале (соответственно, в конце) вектора с результатом должна быть пустая строка.
 * Если два разделителя встретились рядом, то пустая строка между ними тоже должна попасть в ответ.
 * Для пустой строки надо вернуть вектор, содержащий одну пустую строку.
 *
 * Например, Split("What_is_your_name?", '_') должна вернуть вектор из строк What, is, your и name?.
 */

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> Split(const std::string &str, char delimiter);

std::ostream &operator<<(std::ostream &stream, const std::vector<std::string> &list)
{
    for (auto line : list)
    {
        stream << "~" << line << std::endl;
    }
    return stream;
}

int main()
{
    std::cout << Split("What_is_your_name?", '_') << std::endl;
}

std::vector<std::string> Split(const std::string &str, char delimiter)
{
    size_t pointer = 0;
    size_t count = str.length();
    std::vector<std::string> result;

    for (size_t i = 0; i < count; ++i)
    {
        if (str[i] == delimiter)
        {
            result.push_back(str.substr(pointer, i - pointer));
            pointer = i + 1;
        }
    }
    result.push_back(str.substr(pointer, count - pointer));

    return result;
}