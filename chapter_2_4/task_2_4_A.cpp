/**
 * Пароли
 *
 * Пароль от некоторого сервиса должен удовлетворять таким ограничениям:
 *  состоять из символов таблицы ASCII с кодами от 33 до 126;
 *  быть не короче 8 символов и не длиннее 14;
 *  из 4 классов символов — большие буквы, маленькие буквы, цифры, прочие символы — в пароле должны присутствовать не менее трёх любых.
 * Напишите программу, которая проверит, что введённый пароль подходит под эти ограничения.
 *
 * Формат ввода
 * На входе дана одна строка с паролем.
 *
 * Формат вывода
 * Выведите YES, если пароль удовлетворяет требованиям, и NO в противном случае.
 */

#include <iostream>
#include <string>
#include <array>

enum CharClass
{
    numbers,
    lower,
    upper,
    other
};

size_t getIndexClass(char letter)
{
    if (letter >= '0' && letter <= '9')
        return CharClass::numbers;

    if (letter >= 'a' && letter <= 'z')
        return CharClass::lower;

    if (letter >= 'A' && letter <= 'Z')
        return CharClass::upper;

    return CharClass::other;
}

int main()
{
    size_t length;
    std::string password;
    std::array<bool, 4> char_class = {false, false, false, false}; // 0 - number, 1-lowerCase, 2-upperCase, 3-other

    bool isValid = true;

    std::cin >> password;

    length = password.length();
    if (length >= 8 && length <= 14)
    {
        for (char letter : password)
        {
            if (letter < 33 || letter > 126)
            {
                isValid = false;
                break;
            }
            char_class[getIndexClass(letter)] = true;
        }
    }
    else
    {
        isValid = false;
    }

    int count = 0;

    for (bool existClass : char_class)
    {
        if (existClass)
            count++;
    }

    if (count < 3)
        isValid = false;

    std::cout
        << (isValid ? "YES" : "NO") << std::endl;
}
