/**
 * Прямоугольный треугольник
 *
 * Напишите программу, которая проверяет является ли треугольник прямоугольным.
 *
 * Формат ввода
 * На стандартный поток ввода подаётся три целых положительных числа — стороны треугольника.
 * Числа не превосходят 30000.
 *
 * Формат вывода
 * Если полученный треугольник является прямоугольным, напечатайте YES. Если треугольник
 * не является прямоугольным, напечатайте NO. Если с заданными сторонами невозможно построить
 * треугольник, напечатайте UNDEFINED.
 */
#include <iostream>
#include <algorithm>
#include <array>

int main()
{
    std::array<double, 3> edges;

    std::for_each(
        std::begin(edges), std::end(edges),
        [](auto &edge)
        { std::cin >> edge; });

    std::sort(edges.begin(), edges.end());

    if (edges[0] + edges[1] > edges[2] && edges[1] + edges[2] > edges[0] && edges[0] + edges[2] > edges[1])
    {
        if (edges[0] * edges[0] + edges[1] * edges[1] == edges[2] * edges[2])
        {
            std::cout << "YES";
        }
        else
        {
            std::cout << "NO";
        }
    }
    else
    {
        std::cout << "UNDEFINED";
    }
}