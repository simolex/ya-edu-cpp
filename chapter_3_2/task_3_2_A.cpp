/**
 * Встречалось ли число раньше?
 *
 * На вход подаётся последовательность целых чисел. Для каждого числа выведите в
 * отдельной строке слово YES, если это число ранее встречалось в
 * последовательности, и NO, если не встречалось.
 *
 * Формат ввода
 * Вводится список чисел. Все числа списка находятся на одной строке и разделены
 * пробелом. Каждое число представимо типом int.
 *
 * Формат вывода
 * Выведите ответ на задачу.

 */

#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> nums;
    int num;
    while (std::cin >> num) {
        auto iter = nums.find(num);
        if (iter == nums.end()) {
            std::cout << "NO" << std::endl;
            nums.insert(num);
            continue;
        }

        std::cout << "YES" << std::endl;
    }
}
