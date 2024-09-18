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

int* remove_dynamic_array_head(int* &arr, int& logical_size, int& actual_size)
{
    char answer{};
    while(true)
    {
        std::cout << "\nУдалить элемент? y/n:  ";
        std::cin >> answer;
        if (answer == 'n')
            break;
        logical_size--;
        if (logical_size <= actual_size/3)
        {
            actual_size /= 3;
            int* new_arr = new int[actual_size];
            for(int i = 0; i < actual_size; i++)
            {
                if (i < logical_size)
                    new_arr[i] = arr[i+1];
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
                for (int i = 0; i < logical_size; i++)
                {
                    arr[i] = arr[i+1];
                }
                arr[logical_size] = static_cast<int>('_');
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

    remove_dynamic_array_head(arr, logical_size, actual_size);

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