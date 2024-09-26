#include <iostream>
#include <fstream>
void addVisited(int* visited, int v, const int ver)
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

bool goRound(int** arr, const int& ver, int* visited, int start)
{
    for (int j = 0; j < ver; j++)
    {
        if (arr[start][j] == 1)
        {
            if (checkVisited(visited, ver, j))  
                return true;
            else
            {
                addVisited(visited, j, ver);
                goRound(arr, ver, visited, j);
                if (start == ver - 1)
                    return false;
            }        
        }
    }
}

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
        int start{1};
        addVisited(visited, start-1, ver);
        if (goRound(arr, ver, visited, start-1))
            std::cout << "Есть цикл!";
        else
            std::cout << "Нет цикла!";
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