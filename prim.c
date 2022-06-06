#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 10

int minKey(int key[], bool mstSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

int printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{

    int parent[V];

    int key[V];

    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {

        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main()
{

    int graph[V][V] = {{0, 15, 0, 0, 0, 30, 2, 0, 0, 0},
                       {15, 0, 4, 0, 0, 0, 10, 0, 0, 0},
                       {0, 4, 0, 10, 9, 0, 7, 13, 0, 0},
                       {0, 0, 10, 0, 6, 0, 0, 6, 15, 2},
                       {0, 0, 9, 6, 0, 0, 0, 0, 0, 9},
                       {30, 0, 0, 0, 0, 0, 20, 13, 0, 0},
                       {2, 10, 7, 0, 0, 20, 0, 8, 0, 0},
                       {0, 0, 13, 6, 0, 13, 8, 0, 8, 0},
                       {0, 0, 0, 15, 0, 0, 0, 8, 0, 1},
                       {0, 0, 0, 2, 9, 0, 0, 0, 1, 0}

    };

    primMST(graph);

    return 0;
}