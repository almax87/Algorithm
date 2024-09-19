#include <iostream>
#include <cmath>
#include <exception>
#include <stdexcept>

enum class Direction {left, right, up, exit};
const int SIZE = 10;

void print_pyramid (int*);
void input(int&);
void getIndex(int*, int&);



void print_pyramid(int* arr)
{
    std::cout << "Пирамида: " << std::endl;
    int lev{};
    for (int i = 0, j = 0; i < SIZE; i++, j++)
    {
        if (i == 0)
        {
            std::cout << lev << " root " << arr[i] << std::endl;
            lev++;
            continue;
        }

        if (j > pow(2,lev))
        {
            j = 1;
            lev++;
        }

        std::cout << lev; 
        if (i%2 != 0)
            std::cout << " left(";
        else
            std::cout << " right(";
        std::cout << arr[(i-1)/2] << ") " << arr[i] << std::endl;
    }
}

void input(int& i)
{
    Direction direction;
    std::string input;
    std::string variant[4]{"left", "right", "up", "exit"};
    std::cout << "Введите команду: ";
    std::cin >> input;
    int it{};
    while (input != variant[it])
    {
        it++;
        if (it > 4)
            {
                throw std::runtime_error ("Введен неверный вариант");
                break;
            }
    }

    direction = static_cast<Direction>(it);

    if ((i==0)&&(direction == Direction::up))
        throw std::runtime_error("Ошибка! Отсутствует родитель!");

    if ((direction == Direction::left)&&(2*i+1 >= SIZE))
    {
        throw std::runtime_error("Ошибка! Отсутствует левый потомок!");
    }
    if ((direction == Direction::right)&&(2*i + 2 >= SIZE))
    {
        throw std::runtime_error("Ошибка! Отсутствует правый потомок!");
    }

    switch (direction)
    {
        case Direction::left : i = (2*i + 1) ; break;
        case Direction::right : i = (2*i + 2) ; break;
        case Direction::up : i = ((i-1)/2); break;
        case Direction::exit : i = -1 ; break;
    }
}

void getIndex(int* arr, int& i)
{
    std::cout << "Вы находитесь здесь: ";
    int lev{}, count{};
    if (i == 0)
    {
        std::cout << lev << " root " << arr[i] << std::endl;
    }
    else
    {
        while(i > count)
        {
            lev++;
            count += pow(2,lev);
        }
        std::cout << lev;
        if (i%2 != 0)
            std::cout << " left(";
        else
            std::cout << " right(";
        std::cout << arr[(i-1)/2] << ") " << arr[i] << std::endl;
    }
}

int main()
{
    int* arr = new int[SIZE]{16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    print_pyramid(arr);
    int i{};
    getIndex(arr, i);
    while(true)
    {
        try
        {
            input(i);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
        if (i < 0)
            break;
        std::cout << "Ок" << std::endl;
        getIndex(arr, i);
    }
    
    
    delete[] arr;
    arr = nullptr;
    return 0;
}