#include <iostream>
#include <cmath>

int real_string_hash(std::string& str, int& p, int& n)
{
    unsigned long long int hash{};
    for (int i = 0; i < str.length(); i++)
    {
        hash += static_cast<int>(str[i])*pow(p, i);
    }
    return hash%n;
}

int main()
{
    int p, n;
    std::string str;
    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;

    do
    {
        std::cout << "Введите строку: ";
        std::cin >> str;
        std::cout << "Хэш строки " << str << " = " << real_string_hash(str, p, n) << std::endl;
    } while (str != "exit");
    
    return 0;
}