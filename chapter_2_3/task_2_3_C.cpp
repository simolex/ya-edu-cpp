/**
 * Високосный год
 *
 * Определите, является ли год високосным по григорианскому календарю.
 *
 * Напоминание:
 * год, номер которого кратен 400, — високосный;
 * остальные годы, номер которых кратен 100, — невисокосные (например, годы 1700, 1800, 1900, 2100, 2200, 2300);
 * остальные годы, номер которых кратен 4, — високосные.
 * все остальные годы — невисокосные.
 *
 * Формат ввода
 * Вводится целое положительное четырёхзначное число — номер года.
 *
 * Формат вывода
 * Программа выводит YES если год високосный и NO в противном случае.
 */

#include <iostream>

int main()
{
    int year;
    std::cin >> year;

    if ((year % 4 == 0 && year % 100 > 0) || (year % 100 == 0 && year % 400 == 0))
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
}