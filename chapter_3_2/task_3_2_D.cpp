/**
 * Предметный указатель
 *
 * Профессор написал научную книгу и составил для неё предметный указатель. Это
 * список ключевых слов, для каждого из которых указана страница, на которой это
 * слово встречается. Теперь профессор хочет для каждой страницы выписать в
 * алфавитном порядке все ключевые слова, которые на эту страницу попали (если
 * такие вообще есть). Помогите профессору решить эту задачу.
 *
 * Формат ввода
 * Сначала задано натуральное число n, не превосходящее 1000 — количество слов,
 * которое требуется обработать. Далее идут n строк. В каждой строке сначала
 * записано ключевое слово. Затем идёт натуральное число, также не превосходящее
 * 1000, — номер страницы. Ключевые слова состоят из латинских букв, не бывают
 * пустыми и по длине не превосходят 16 символов. Слова в списке, конечно, могут
 * повторяться.
 *
 * Формат вывода
 * Выпишите в порядке возрастания все страницы, на которых присутствуют ключевые
 * слова. После каждого номера страницы через пробел выпишите в алфавитном
 * порядке сами эти слова. Если на какой-то странице слово встретилось несколько
 * раз, то повторять его не нужно. Завершающего пробела в конце строк быть не
 * должно.
 */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

std::string
Join(const std::vector<std::string>& tokens, char delimiter);

int
main()
{
    size_t count;
    int page;
    std::string word;
    std::map<int, std::set<std::string>> pages;

    std::cin >> count;
    for (size_t i = 0; i < count; ++i) {
        std::cin >> word >> page;

        pages[page].insert(word);
    }

    std::vector<std::pair<int, std::set<std::string>>> pageNums(pages.begin(),
                                                                pages.end());
    for (const auto& [p, tokinSet] : pageNums) {
        std::vector<std::string> tokens(tokinSet.begin(), tokinSet.end());

        std::cout << p << " " << Join(tokens, ' ') << std::endl;
    }
}

std::string
Join(const std::vector<std::string>& tokens, char delimiter)
{
    size_t count = tokens.size();
    std::string result = "";

    if (count == 0) {
        return result;
    }

    for (size_t i = 0; i < count - 1; ++i) {
        result += tokens[i] + delimiter;
    }
    result += tokens[count - 1];

    return result;
}