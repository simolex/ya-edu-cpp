/**
 * Функция Join
 *
 * Вам требуется написать функцию Join со следующим заголовком:
 *
 * std::string Join(const std::vector<std::string>& tokens, char delimiter);
 * Функция должна вернуть строку, полученную склейкой элементов вектора через указанный разделитель.
 * Например, Join({"What", "is", "your", "name?"}, '_') должна вернуть строку "What_is_your_name?".
 *
 * Примечание
 * Если вектор tokens пустой, то функция должна вернуть пустую строку. Если в векторе tokens ровно
 * один элемент, то он и должен вернуться в ответе.
 * Подключите необходимые заголовочные файлы и напишите только код функции Join.
 * Мы скомпилируем решение с нашей функцией main.
 */

#include <iostream>
#include <vector>
#include <string>

std::string Join(const std::vector<std::string> &tokens, char delimiter);

int main()
{
    std::cout << Join({"What", "is", "your", "name?"}, '_') << std::endl;
}

std::string Join(const std::vector<std::string> &tokens, char delimiter)
{
    size_t count = tokens.size();
    std::string result = "";

    if (count == 0)
    {
        return result;
    }

    for (size_t i = 0; i < count - 1; ++i)
    {
        result += tokens[i] + delimiter;
    }
    result += tokens[count - 1];

    return result;
}