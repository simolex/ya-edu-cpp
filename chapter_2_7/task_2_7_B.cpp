/**
 * Общий префикс
 *
 * Напишите функцию для вычисления наибольшего общего префикса строк, переданных в векторе words:
 * std::string CommonPrefix(const std::vector<std::string>& words);
 * Например, для пустого вектора функция должна вернуть пустую строку, а для вектора из
 * строк "apple", "apricot" и "application" — строку "ap".
 *
 * Примечание
 * В решении не должно быть функции main: она будет в нашей тестирующей программе.
 * Подключите необходимые библиотеки и напишите код функции CommonPrefix.
 */

#include <iostream>
#include <vector>
#include <string>

std::string CommonPrefix(const std::vector<std::string> &words);

std::ostream &operator<<(std::ostream &stream, const std::pair<size_t, size_t> &pos)
{
    stream << pos.first << " " << pos.second;
    return stream;
}

int main()
{
    std::vector<std::string> words({"", "apricot", "application"});

    std::cout << CommonPrefix(words) << std::endl;
}

std::string CommonPrefix(const std::vector<std::string> &words)
{
    std::string result;
    size_t minSize = std::string::npos;
    std::string segment;
    bool canFinding = true;

    size_t count = words.size();

    if (count == 0)
    {
        return "";
    }

    for (size_t i = 0; i < count; ++i)
    {
        if (minSize > words[i].length())
        {
            minSize = words[i].length();
        }
    }

    for (size_t i = 0; i < minSize && canFinding; ++i)
    {
        segment = words[0].substr(i, 1);
        for (size_t j = 1; j < count && canFinding; ++j)
        {
            if (segment != words[j].substr(i, 1))
            {
                canFinding = false;
                continue;
            }
        }

        if (canFinding)
        {
            result += segment;
        }
    }

    return result;
}