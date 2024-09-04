#include <iostream>

int fibo(int n)
{
    if (n == 0)
        return 0;
    if ((n == 1)||(n == 2))
        return 1;
    return fibo(n-1) + fibo(n-2);

}

int main()
{
    int n{};
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cout << "F(" << n << ") = " << fibo(n) << std::endl;

    return 0;
}