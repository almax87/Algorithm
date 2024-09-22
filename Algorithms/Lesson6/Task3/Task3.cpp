#include <iostream>

unsigned long long int hash(std::string& str_link, int len, int i)
{
    unsigned long int hash{};
    for (int j = i; j < i + len; j++)
    {
        hash += static_cast<int>(str_link[j]);
    }

    return hash;
}

int find_substring_light_rabin_karp(std::string& str, std::string& substr)
{  
    int substr_len = substr.length();  
    unsigned long long int substr_hash = hash(substr, substr_len, 0);
    unsigned long long int str_hash{};

    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0)
        {
            str_hash = hash(str, substr_len, i);
        }
        else
        { 
            str_hash = str_hash - static_cast<int>(str[i-1]) + static_cast<int>(str[i + substr_len - 1]);
        }

        if (str_hash != substr_hash)
        {
            continue;
        }
        else 
        {
            for (int j = 0; j < substr_len; j++)
            {
                if (str[i+j] != substr[j])
                    break;
                else if (j == substr_len-1)
                    return i;
            }
        }
    }

    return -1;
}


int main()
{
    std::string str{}, substr{};
    int str_index{};
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> str;
    do
    {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> substr;
        str_index = find_substring_light_rabin_karp(str, substr);
        if (str_index < 0)
            {
                std::cout << "Подстрока " << substr << " не найдена" << std::endl;
                continue;
            }
        std::cout << "Подстрока " << substr << " найдена по индексу " << str_index << std::endl;
    } while (substr != "exit");
    
    return 0;
}