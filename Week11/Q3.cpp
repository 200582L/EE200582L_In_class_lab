#include <iostream>
#include <climits>
using namespace std;

#define V 6 // Number of vertices in the graph

int minKey(int key[], bool mstSet[])
{
    int min_Val = INT_MAX, min_Index;

    for (int v = 0; v < V; v++)
    {
        if (!mstSet[v] && key[v] < min_Val)
        {
            min_Val = key[v];
            min_Index = v;
        }
    }

    return min_Index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int k = 1; k < V; k++)
    {
        cout << parent[k] << " - " << k << "\t" << graph[k][parent[k]] << endl;
    }
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}};

    primMST(graph);

    return 0;
}
