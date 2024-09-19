/**
 *
 * Символьные n-граммы
 *
 * Будем называть символьной n-граммой последовательность из n последовательно
 * идущих символов в одном слове в тексте. Для данного числа n подсчитайте
 * суммарное количество каждой n-граммы в тексте.
 *
 * Формат ввода
 * В первой строке заданы два числа: m — число слов в тексте (от 1 до 100000) и
 * n — длина 𝑛 n-граммы (от 1 до 5). Далее идет 𝑚 m слов. Можно считать, что
 * слова отделены пробелами или переносами строк. Обработку пунктуации и
 * регистра реализовывать не нужно. Читайте слова просто через std::cin >> word.
 *
 * Формат вывода
 * Выведите все n-граммы, отсортированные по убыванию частоты, а в случае равных
 * частот — лексикографически (по алфавиту). Для каждой 𝑛 n-граммы напечатайте
 * также её частоту (смотрите формат в примере).
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
int
main()
{
    size_t count, size;
    std::unordered_map<std::string, int> subwords;
    std::cin >> count >> size;
    for (size_t i = 0; i != count; ++i) {
        std::string word;
        std::cin >> word;
        for (size_t i = 0; word.size() >= size && i <= (word.size() - size);
             ++i) {
            subwords[word.substr(i, size)]++;
        }
    }
    std::vector<std::pair<std::string, int>> sortedByFreq(subwords.begin(),
                                                          subwords.end());
    std::sort(sortedByFreq.begin(),
              sortedByFreq.end(),
              [](const auto& p1, const auto& p2) {
                  return std::tie(p2.second, p1.first) <
                         std::tie(p1.second, p2.first);
              });
    for (const auto& [token, cnt] : sortedByFreq) {
        std::cout << token << " - " << cnt << std::endl;
    }
}
