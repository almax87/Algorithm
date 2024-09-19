#include <iostream>
#include <cmath>

void print_pyramid(int* arr, const int SIZE)
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

int main()
{
    const int SIZE = 10;
    int* arr = new int[SIZE]{16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    print_pyramid(arr, SIZE);

    delete[] arr;
    arr = nullptr;
    return 0;
}