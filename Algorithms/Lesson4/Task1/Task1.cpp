#include <iostream>
#include <exception>
#include <stdexcept>

int try_input(int& logical_size, int& actual_size)
{
    std::cout << "Введите фактический размер массива: ";
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;
    if (logical_size > actual_size)
        throw std::runtime_error("Ошибка! Логический массив не может превышать фактический!");
    else 
        return 1;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    std::cout << "Динамический массив: ";
    for (int i = 0; i < logical_size; i++)
    {
        std::cout << arr[i] << " ";
    }
    for (int i = logical_size; i < actual_size; i++)
    {
        std::cout << static_cast<char>(arr[i]) << " ";
    }
}

int main()
{
    int actual_size{}, logical_size{};
    while (true)
    {
        try
        {
            try_input(logical_size, actual_size);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    int *arr = new int[actual_size];
    
    for (int i = 0; i < logical_size; i++)
    {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    for (int i = logical_size; i < actual_size; i++)
    {
        arr[i] = static_cast<int>('_');   
    }
    
    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;

    arr = nullptr;

    return 0;
}