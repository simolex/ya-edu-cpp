/**
 * Soundex
 * Известный алгоритм Soundex определяет, похожи ли два английских слова по звучанию. На вход он принимает слово и заменяет
 * его на некоторый четырёхсимвольный код. Если коды двух слов совпадают, то слова, как правило, звучат похоже.
 *
 * Вам требуется реализовать этот алгоритм. Он работает так:
 * Первая буква слова сохраняется.
 * В остальной части слова буквы a, e, h, i, o, u, w и y удаляются;
 * Оставшиеся буквы заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
 * b, f, p, v: 1
 * c, g, j, k, q, s, x, z: 2
 * d, t: 3
 * l: 4
 * m, n: 5
 * r: 6
 *
 * Любая последовательность идущих подряд одинаковых цифр сокращается до одной такой цифры.
 * Итоговая строка обрезается до первых четырёх символов.
 * Если длина строки получилась меньше четырёх символов, в конце добавляются нули.
 * Примеры:
 * ammonium → ammnm → a5555 → a5 → a500.
 * implementation → implmnttn → i51455335 → i514535 → i514.
 *
 * Формат ввода
 * На вход подаётся одно непустое слово из строчных латинских букв. Длина слова не превосходит 20 символов.
 *
 * Формат вывода
 * Напечатайте четырёхбуквенный код, соответствующий слову.
 */

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iomanip>

int main()
{
    size_t prevGroup;
    size_t maxSize;
    std::string word;
    std::array<std::string, 6> groups = {
        "bfpv",
        "cgjkqsxz",
        "dt",
        "l",
        "mn",
        "r"};
    std::string replacedWord = "";

    std::cin >> word;

    prevGroup = 7;
    maxSize = 4;
    replacedWord.push_back(word[0]);
    for (size_t i = 1; i < word.length(); ++i)
    {
        for (size_t k = 0; k < 6; ++k)
        {
            if (groups[k].find(word[i]) != std::string::npos && prevGroup != k)
            {
                replacedWord.push_back('1' + k);
                prevGroup = k;
                break;
            }
        }

        if (replacedWord.length() >= maxSize)
            break;
    }

    std::cout << std::setfill('0') << std::left << std::setw(4) << replacedWord << std::endl;
}
