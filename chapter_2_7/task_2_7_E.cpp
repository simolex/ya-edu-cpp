/**
 * Транспонировать матрицу
 * Дана прямоугольная матрица A из m строк и n столбцов. Транспонированной матрицей A^T  называется
 * матрица из n строк и m столбцов, в которой строки и столбцы поменялись ролями: элементA[ij]^T​
 * равен элементу A[ji].
 *
 * Напишите функцию, которая возвращает транспонированную матрицу:
 * std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix);
 *
 * Примечание
 * Гарантируется, что вектор matrix непуст и все его элементы имеют равную ненулевую длину.
 * Подключите необходимые заголовочные файлы и напишите только код функции Transpose.
 * Мы скомпилируем решение с нашей функцией main.
 */

#include <iostream>
#include <vector>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>> &matrix);

int main()
{
    // std::cout << Join({"What", "is", "your", "name?"}, '_') << std::endl;
    std::vector<std::vector<int>> print = Transpose({{1, 2}, {3, 4}, {5, 6}});

    for (size_t i = 0; i < 2; ++i)
    {
        for (size_t j = 0; j < 3; ++j)
        {
            std::cout << print[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>> &matrix)
{
    size_t n = matrix.size();
    size_t m = matrix[0].size();

    std::vector<std::vector<int>> result(m, std::vector<int>(n));

    for (size_t i = 0; i < m; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}