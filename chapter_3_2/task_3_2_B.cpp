/**
 * Общие буквы
 *
 * Вам даны слова. Выведите в алфавитном порядке список общих букв всех слов.
 *
 * Формат ввода
 * На вход поступают слова (по одному в строке), состоящие из маленьких
 * латинских букв алфавита. Длина слов не превосходит 100 символов, а количество
 * слов не превосходит 1000.
 *
 * Формат вывода
 * Выведите в алфавитном порядке без пробелов список букв, которые присутствуют
 * в каждом слове.
 */

#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    std::set<char> lettersResult;
    std::string word;

    std::cin >> word;
    for (char ch : word) {
        lettersResult.insert(ch);
    }

    while (std::cin >> word) {
        std::set<char> letters(word.begin(), word.end());

        std::vector<char> sortedByLetters(lettersResult.begin(),
                                          lettersResult.end());
        for (char letter : sortedByLetters) {
            if (letters.find(letter) == letters.end()) {
                lettersResult.erase(letter);
            }
        }
    }
    for (auto& letter : lettersResult) {
        std::cout << letter;
    }
    std::cout << std::endl;
}