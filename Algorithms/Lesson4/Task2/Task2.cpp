#include <iostream>
#include <exception>
#include <stdexcept>

void try_input(int& logical_size, int& actual_size)
{
    std::cout << "Введите фактический размер массива: ";
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;
    if (logical_size > actual_size)
        throw std::runtime_error("Ошибка! Логический массив не может превышать фактический!");
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

int* append_to_dynamic_array(int* &arr, int& logical_size, int& actual_size)
{
    int element{};
    while(true)
    {
        std::cout << "\nВведите элемент для добавления: ";
        std::cin >> element;
        if (element == 0)
            break;
        if (logical_size == actual_size)
        {
            actual_size *= 2;
            logical_size++;
            int* new_arr = new int[actual_size];
            for(int i = 0; i < actual_size; i++)
            {
                if (i < logical_size-1)
                    new_arr[i] = arr[i];
                else if (i == logical_size-1)
                {
                    new_arr[i] = element;
                }
                else
                {
                    new_arr[i] = static_cast<int>('_');
                }
            }
            delete[] arr;
            arr = new_arr;
            new_arr = nullptr;
        }
        else
            {
                logical_size++;
                arr[logical_size-1] = element;
            }
        print_dynamic_array(arr, logical_size, actual_size);
    }
    return arr; 
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

    append_to_dynamic_array(arr, logical_size, actual_size);

    std::cout << "Спасибо! Ваш массив: ";
    for (int i = 0; i < logical_size; i++)
    {
        std::cout << arr[i] << " ";
    }
    for (int i = logical_size; i < actual_size; i++)
    {
        std::cout << static_cast<char>(arr[i]) << " ";
    }
    std::cout << std::endl;
    delete[] arr;
    arr = nullptr;

    return 0;
}