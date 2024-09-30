#include <iostream>
#include <fstream>

int main()
{
    int ver{};   
    std::ifstream input ("in.txt");
    if (input.is_open())
    {
        input >> ver;
        int** arr = new int*[ver];
        for (int i = 0; i < ver; i++)
        {
            arr[i] = new int[ver];
        }
        while (!(input.eof()))
        {
            for (int i = 0; i < ver; i++)
            {
                for (int j = 0; j < ver; j++)
                {
                    input >> arr[i][j];
                }
            }     
        }
        int count{};
        for (int i = 0; i < ver; i++)
        {
            count = 0;
            std::cout << i + 1 << ": ";
            for (int j = 0; j < ver; j++)
            {
                if (arr[i][j])
                {
                    std::cout << j + 1 << " ";
                    ++count;
                }
            }
            if (count == 0)
                std::cout << "нет";
            std::cout << std::endl;
        }
        for (int i = 0; i < ver; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        arr = nullptr;
    }
    else 
        std::cout << "Error!" << std::endl;
    input.close();
    
    return 0;
}