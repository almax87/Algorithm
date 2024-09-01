#include <iostream>
#include <locale>

int count_max (const int* arr, const int &init_point, const int &arr_size)
{
    int count = arr_size/2;
    for (int i = 0; i < arr_size; i++)
    {  
        if (init_point < arr[arr_size/2])
        {
            if (arr[arr_size/2 - i] == init_point)
                return arr_size/2 + i;
        }
        else
        {
            if (init_point == arr[arr_size - 1 - i])
            {
                return i;                
            }
                
        } 
    }
    return count;
}

int main()
{
    setlocale(LC_ALL,"russian");
    int init_point{};
    const int arr[] {1, 23, 44, 56, 77, 77, 89, 100, 100, 101, 101, 105, 105};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Введите точку отсчета: ";
    std::cin >> init_point;
    std::cout << "Количество элементов в массиве больших чем " << init_point << ": " << count_max(arr, init_point, arr_size) << std::endl;

    std::cin.get();
    std::cin.get();

    return 0;
}