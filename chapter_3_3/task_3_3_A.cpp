/**
 * Удвоить вектор
 *
 * Требуется написать шаблонную функцию Duplicate, которая получает на вход
 * вектор и дублирует все его элементы в конце вектора. Например, из вектора с
 * элементами 1, 2, 3 должен получиться вектор с элементами 1, 2, 3, 1, 2, 3.
 * Вася написал вот такую реализацию, которая почему-то не работает:
 *
 * #include <vector>
 *    template <typename T>
 *    void Duplicate(std::vector<T>& v) {
 *        for (auto it = v.begin(); it != v.end(); ++it) {
 *            v.push_back(*it);
 *        }
 *    }
 *
 * Вам надо исправить код Васи.
 *
 * Примечание
 * Сдайте в систему только исправленный код функции Duplicate без функции
 * main. Подключите все необходимые для вашей реализации библиотеки. Заголовок
 * функции Вася написал правильно, в этом можете не сомневаться.

 */

#include <iostream>
#include <vector>

template<typename T>
void
Duplicate(std::vector<T>& v)
{
    size_t len = v.size();
    v.resize(len * 2);

    auto end = v.begin() + len;
    for (auto it = v.begin(); it != end; ++it) {
        v[len++] = *it;
    }
}

int
main()
{
    std::vector<int> v({ 1, 2, 3 });
    Duplicate(v);
    for (int& e : v) {
        std::cout << ' ' << e;
    }
}
