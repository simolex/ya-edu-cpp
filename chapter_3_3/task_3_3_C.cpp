/**
 * Алгоритм set_difference
 *
 * Напишите свою реализацию стандартного алгоритма set_difference.
 * Заголовок функции должен быть таким:
 * template <typename InIter1, typename InIter2, typename OutIter>
 * OutIter SetDifference(InIter1 first1, InIter1 last1,
 *                       InIter2 first2, InIter2 last2,
 *                       OutIter out);
 * Функция должна сформировать элементы разности диапазонов [first1, last1) и
 * [first2, last2) и записать их в последовательность, начинающуюся с out.
 * Исходные диапазоны предполагаются отсортированными. Каждый элемент считается
 * со своей кратностью. Функция должна вернуть итератор, который указывает
 * за последний записанный элемент.
 *
 * Примечание
 * В вашем решении должен быть только код этой шаблонной функции и не должно
 * быть функции main. Программа должна использовать константную память и быть
 *  линейной по сложности. Допускается сравнивать итераторы с помощью
 *  == и !=, а также сравнивать элементы с помощью <. Использовать вызов
 *  std::set_difference нельзя.
 */

#include <iostream>
#include <iterator>
#include <vector>

template<typename InIter1, typename InIter2, typename OutIter>
OutIter
SetDifference(InIter1 first1,
              InIter1 last1,
              InIter2 first2,
              InIter2 last2,
              OutIter out)
{
    while (first1 != last1) {
        while (first2 != last2 && *first1 > *first2) {
            ++first2;
        }
        if (first2 == last2 || *first1 < *first2) {
            *out = *first1;
            ++out;
        } else if (first2 != last2) {
            ++first2;
        }
        ++first1;
    }
    return out;
}

int
main()
{
    std::vector<int> v1({ 1, 2, 3, 4, 6 });
    std::vector<int> v2({ 2, 3 });
    std::vector<int> o;
    SetDifference(
      v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(o));
    for (int& e : o) {
        std::cout << ' ' << e;
    }
}
