/**
 * ArgMax в матрице
 *
 * Вам требуется написать на C++ функцию со следующим заголовком:
 * std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix);
 *
 * Функция должна вернуть пару из индексов максимального элемента в матрице. Если максимальных
 * элементов несколько, то нужно вернуть наименьшую такую пару.
 *
 * Формат ввода
 * В первой строке двумя числами n и k задан размер матрицы. В последующих𝑛n строках вводится
 * числовая матрица в k столбцов.
 *
 * Формат вывода
 * Индекс строки и столбца максимального элемента в матрице.
 */

#include <iostream>
#include <vector>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>> &matrix);

std::ostream &operator<<(std::ostream &stream, const std::pair<size_t, size_t> &pos)
{
    stream << pos.first << " " << pos.second;
    return stream;
}

int main()
{
    size_t n, k;
    size_t maxI, maxJ;

    std::cin >> n >> k;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(k));

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < k; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << MatrixArgMax(matrix) << std::endl;
}

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>> &matrix)
{
    std::pair<size_t, size_t> maxPosition(0, 0);
    size_t n = matrix.size();
    size_t k = matrix[0].size();
    int max = matrix[0][0];

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < k; ++j)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
                maxPosition = {i, j};
            };
        }
    }
    return maxPosition;
}