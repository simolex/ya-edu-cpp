/**
 * Количество дней в месяце
 *
 * Напишите программу, выводящую количество дней в месяце по заданному номеру месяца и году.
 *
 * Формат ввода
 * На вход программе подается два целых положительных числа: номер месяца (от 1 до 12)
 * и четырёхзначный год.
 *
 * Формат вывода
 * Необходимо вывести одно число — количество дней в заданном месяце.
 */

#include <iostream>
#include <array>

int addDayIntercalary(int month, int year)
{
    return month == 2 && ((year % 4 == 0 && year % 100 > 0) || (year % 100 == 0 && year % 400 == 0)) ? 1 : 0;
}

int main()
{
    int month, year;
    std::array<int, 12> day_count = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::cin >> month >> year;

    std::cout << day_count[month - 1] + addDayIntercalary(month, year);
}