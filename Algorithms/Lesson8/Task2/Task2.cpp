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

void addOrder(int* order, int v, const int ver)
{
    int* temp = new int[ver]{};
    for (int i = 0; i < ver; i++)
    {
        temp[i] = order[i];
    }
    order[0] = v+1;
    for (int i = 1; i < ver; i++)
    {
        order[i] = temp[i-1];
    }
    delete[] temp;
    temp = nullptr;
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

void dfs(int** arr, const int& ver, int* visited, int* order, int v)
{
    for (int j = 0; j < ver; j++)
    {
        if (arr[v][j] == 1)
            {
                if (!checkVisited(visited, ver, j))
                {
                    addVisited(visited, j, ver);
                    dfs(arr, ver, visited, order, j);
                }        
            }
    }
    addOrder(order, v, ver);
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
        int* visited = new int[ver]{};
        int* order = new int[ver];
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
        for (int i = 0; i < ver; i++)
        {
            if (!visited[i])
            {
                addVisited(visited, i, ver);
                dfs(arr, ver, visited, order, i);
            }
                
        }
        
        std::cout << "Порядок обхода вершин: ";
        for (int i = 0; i < ver; i++)
        {
            std::cout << order[i] << " ";
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