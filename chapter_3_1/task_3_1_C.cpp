/**
 * Вагоны
 * Вы — машинист. Вам поручено реализовать функцию void MakeTrain(), чтобы сформировать поезд
 * из набора вагонов. У каждого вагона есть номер (помещается в int). Номера вагонов внутри состава
 * могут повторяться. Изначально путь, на котором формируется состав, пустой. Вы должны уметь выполнять
 * следующие команды, которые поступают в отдельных строках на входе:
 * +left W — добавить вагон с номером W слева
 * +right W — добавить вагон с номером W справа
 * -left N — отцепить и убрать N вагонов слева
 * -right N — отцепить и убрать N вагонов справа
 * В последних двух командах
 * N может быть больше текущей длины состава — в этом случае надо убрать весь состав целиком.
 * Отцеплять вагоны по одному может быть долго: постарайтесь сразу отцеплять по N штук.
 * Напечатайте через пробел номера вагонов получившегося состава, если смотреть на них слева направо.
 * В самом конце напечатайте перевод строки.
 * На вход подаются строки с командами в указанном формате. Всего будет не более 1 млн команд.
 * Оформите ваше решение в функции void MakeTrain(). Эта функция должна читать данные со стандартного
 * потока ввода и печатать их в стандартный поток вывода. Подключите все необходимые библиотеки.
 * В вашем решении не должно быть функции main.
 */

#include <iostream>
#include <list>
#include <string>

#include <iterator>

void MakeTrain();

int main()
{
    MakeTrain();
}

template <typename List>
void Print(const List &data, const std::string delimiter)
{
    bool visitedFirst = false;
    for (const auto &item : data)
    {
        if (visitedFirst)
        {
            std::cout << delimiter;
        }
        else
        {
            visitedFirst = true;
        }
        std::cout << item;
    }

    std::cout << std::endl;
}

void MakeTrain()
{
    std::list<int> train;
    std::string command;
    int param;
    auto front = train.begin();
    auto back = train.end();

    while (std::cin >> command >> param)
    {
        front = train.begin();
        back = train.end();

        if (command == "+left")
        {
            train.push_front(param);
        }
        else if (command == "+right")
        {

            train.push_back(param);
        }
        else if (command == "-left")
        {

            if (param >= train.size())
            {
                train.clear();
            }
            std::advance(front, param - 1);
            train.erase(train.begin(), front);
        }
        else if (command == "-right")
        {
            if (param >= train.size())
            {
                train.clear();
            }
            std::advance(back, -1 * param);
            train.erase(back, train.end());
        }
    }

    Print(train, " ");
}
