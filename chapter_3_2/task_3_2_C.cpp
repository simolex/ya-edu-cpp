/**
 * Файловая система
 * Дан список всех файлов в некоторой файловой системе. Необходимо вывести все
 * непустые директории этой файловой системы в лексикографическом порядке.
 * Гарантируется, что все пути начинаются от корня файловой системы. Все пути
 * состоят из слешей (/), латинских символов, цифр и точек. Два слеша никогда не
 * стоят подряд.
 *
 * Формат ввода
 * На вход подаются строки, описывающие пути ко всем файлам в системе. Каждый
 * путь содержится в отдельной строке. Число строк не превосходит 10000.
 *
 * Формат вывода
 * Выведите все непустые директории в этой файловой системе в лексикографическом
 * порядке. Каждый путь должен начинаться со слеша и заканчиваться слешом.
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Node {
    // std::string name;
    std::map<std::string, Node> childs;
};

std::vector<std::string> Split(const std::string& str, char delimiter);

int main() {
    std::string path;

    while (std::getline(std::cin, path)) {
    }

    // for (auto& letter : lettersResult) {
    //     std::cout << letter;
    // }
    // std::cout << std::endl;
}

std::vector<std::string> Split(const std::string& str, char delimiter) {
    size_t pointer = 0;
    size_t count = str.length();
    std::vector<std::string> result;

    for (size_t i = 0; i < count; ++i) {
        if (str[i] == delimiter) {
            result.push_back(str.substr(pointer, i - pointer));
            pointer = i + 1;
        }
    }
    result.push_back(str.substr(pointer, count - pointer));

    return result;
}