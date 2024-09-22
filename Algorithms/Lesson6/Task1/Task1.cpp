#include <iostream>

int simple_string_hash(std::string& str)
{
    int hash{};
    for (int i = 0; i < str.length();i++ )
    {
        hash += static_cast<int>(str[i]);
    }
    return hash;
}

int main()
{
    std::string str{};
    do
    {
        std::cout << "Введите строку: ";
        std::cin >> str;
        std::cout << "Наивный хэш строки " << str << " = " << simple_string_hash(str) << std::endl;
    } while (str != "exit");

    return 0;
}