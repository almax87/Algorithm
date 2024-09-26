#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>

void tryInput(int& start, const int& ver)
{
    std::cout << "Введите номер вершины, с которой начнется обход: ";
    std::cin >> start;
    if ((start < 0) || (start > ver))
        throw std::runtime_error("Нет такой вершины!");
    else 
        return;
}

void add(int* visited, int v, const int ver)
{
    for (int i = 0; i < ver; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = v+1;
            return;
        }
    }    
}

bool checkVisited(int* visited, const int ver, int j)
{
    for (int i = 0; i < ver; i++)
    {
        if (visited[i] == j+1)
            return true;
    }
    return false;
}


void bfs(int** arr, const int& ver, int* visited, int start)
{
    int* queue = new int[ver]{};
    int head{}, count{};
    queue[count++] = start;
    add(visited, start, ver);
    while (head < count)
    {
        start = queue[head++];
        
        for (int i = 0; i < ver; i++)
        {
            if (arr[start][i] && !checkVisited(visited, ver, i))
            {
                queue[count++] = i;
                add(visited, i, ver);
            }
        }
    }
    delete[] queue;
    queue = nullptr;
}


int main()
{
    int ver{}, start{}; 
    std::ifstream input ("in.txt");
    if (input.is_open())
    {
        input >> ver;
        int** arr = new int*[ver];
        for (int i = 0; i < ver; i++)
        {
            arr[i] = new int[ver];
        }
        int* visited = new int[ver];
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
        while (true)
        {   
            try
            {
                tryInput(start, ver);
                break;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        start--;
        bfs(arr, ver, visited, start);
        std::cout << "Порядок обхода вершин: ";
        for (int i = 0; i < ver; i++)
        {
            std::cout << visited[i] << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < ver; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        arr = nullptr;
        delete[] visited;
        visited = nullptr;
    }
    else 
        std::cout << "Error!" << std::endl;
    input.close();
    
    return 0;
}