/**
 * Сортировка точек
 * Вам даны координаты точек на плоскости. Выведите эти точки в порядке возрастания расстояний до
 * начала координат.
 *
 * Формат вводаСначала задано количество точек n. Затем идет последовательность из n строк, каждая
 * из которых содержит два целых числа — координаты точки. Величина n не превосходит 100. Координаты
 * точек по модулю не превосходят 1000.
 *
 * Формат вывода
 * Выведите через пробел кординаты точек в порядке возрастания расстояний до начала координат.
 * После каждой пары координат печатайте перевод строки.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Coord
{
    int i = 0;
    int j = 0;
};

std::istream &operator>>(std::istream &stream, Coord &pos)
{
    stream >> pos.i >> pos.j;
    return stream;
}

std::ostream &operator<<(std::ostream &stream, Coord &pos)
{
    stream << pos.i << " " << pos.j;
    return stream;
}

int main()
{
    size_t n;
    std::vector<Coord> list;
    Coord point;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> point;
        list.push_back(point);
    }

    std::sort(list.begin(), list.end(), [](Coord &a, Coord &b)
              { return a.i * a.i + a.j * a.j < b.i * b.i + b.j * b.j; });

    for (size_t i = 0; i < n; ++i)
    {
        std::cout << list[i] << std::endl;
    }
}
