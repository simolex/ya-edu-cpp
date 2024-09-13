/**
 * Сапёр
 * Вам необходимо построить поле для игры «Сапёр» по его конфигурации — высоте, ширине и координатам
 * расставленных на нем мин.
 *
 * Вкратце напомним правила построения поля для игры «Сапёр»:
 * поле состоит из клеток с минами и пустых клеток;
 * клетки с миной обозначаются символом *;
 * пустые клетки содержат число от 0 до 8 — количество мин на соседних клетках.
 *
 * Формат ввода
 * В первой строке содержатся три числа:
 * число m от 1 до 100 — количество строк на поле;
 * число n от 1 до 100 — количество столбцов на поле;
 * число k от 0 до mn — количество мин на поле.
 * В следующих k строках содержатся пары чисел с координатами мин (номерами строки и столбца).
 * Нумерация ведётся с единицы.
 *
 * Формат вывода
 * Выведите построенное поле, разделяя строки поля символом \n, а столбцы — пробелом.
 */

#include <iostream>
#include <vector>

struct Position
{
    int i = 0;
    int j = 0;
};

std::istream &operator>>(std::istream &stream, Position &pos)
{
    stream >> pos.i >> pos.j;
    return stream;
}

struct Cell
{
    bool isMine = false;
    short neigMine = 0;
};

const std::vector<Position> Delta = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
};

void outCell(Cell &cell)
{
    if (cell.isMine)
    {
        std::cout << "*";
    }
    else
    {
        std::cout << (char)('0' + cell.neigMine);
    }
}

int main()
{
    size_t m, n, k;
    Position position;
    Cell *cell;

    std::cin >> m >> n >> k;
    std::vector<std::vector<Cell>> field(m + 2, std::vector<Cell>(n + 2));

    for (size_t i = 0; i < k; ++i)
    {
        std::cin >> position;
        field[position.i][position.j].isMine = true;

        for (size_t t = 0; t < Delta.size(); ++t)
        {
            cell = &field[position.i + Delta[t].i][position.j + Delta[t].j];

            if (!cell->isMine)
            {
                cell->neigMine++;
            }
        }
    }

    for (size_t i = 1; i <= m; ++i)
    {
        for (size_t j = 1; j < n; ++j)
        {
            outCell(field[i][j]);
            std::cout << " ";
        }
        outCell(field[i][n]);
        std::cout << std::endl;
    }
}
