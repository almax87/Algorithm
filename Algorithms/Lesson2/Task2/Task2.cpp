#include <iostream>
class Fibo
{
    public:
        unsigned long int* mem_arr;
        int n;
    
    Fibo(int n) : n{n}
    {
        this->mem_arr = new unsigned long int[n];
    };

    void print_fibo(int n)
    {
        std::cout << "F(" << n << ") = " << mem_arr[n-1] << std::endl;
    }

    int fibo(int n)
    {
        if ((n >= 0) && (n <= 1))
            return mem_arr[n] = n;
        
        return mem_arr[n-1] = fibo(n-1) + fibo(n-2);
    }

    ~Fibo()
    {
        delete[] mem_arr;
        mem_arr = nullptr;
    }
};

int main()
{
    int n{};
    std::cout << "Введите n: ";
    std::cin >> n;
    Fibo* fibo = new Fibo(n);
    fibo->fibo(n);
    fibo->print_fibo(n);

    while (n != 0)
    {
        std::cout << "Введите n: ";
        std::cin >> n;
        if (n < fibo->n)
        {
            fibo->print_fibo(n);
        }
        else
        {
            delete fibo;
            Fibo* fibo = new Fibo(n);
            fibo->fibo(n);
            fibo->print_fibo(n);
        }
    };
    delete fibo;

    return 0;
}
