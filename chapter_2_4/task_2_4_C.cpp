/**
 * Обратная перестановка
 *
 * На мероприятие приглашены n гостей. Им предлагают занять места с номерами от 1 до n в зале.
 * Гости занимают эти места в произвольном порядке. Известно, на каком месте сел очередной гость.
 *
 * Выпишите для каждого очередного места номер гостя, который на него сел.
 *
 * Формат ввода
 * Дано число n, а затем n различных чисел 𝑎1,𝑎2,...,𝑎𝑛  от 1 до n.
 * Число  a[k] ​— это номер места, на которое сел 𝑘 k-й гость. Число n не превосходит 20000.
 *
 * Формат вывода
 * Выведите n чисел b1​, b2​,..., bn​  от 1 до n. Число bk​  должно обозначать номер гостя, который сел на k-е место.
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    size_t n;
    int place;
    std::vector<std::pair<int, int>> places_guests;

    std::cin >> n;

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> place;
        places_guests.push_back({place, i + 1});
    }

    std::sort(places_guests.begin(), places_guests.end(), [](auto a, auto b)
              { return a.first < b.first; });

    for (size_t i = 0; i < n - 1; ++i)
    {
        std::cout << places_guests[i].second << " ";
    }
    std::cout << places_guests[n - 1].second << std::endl;
}
