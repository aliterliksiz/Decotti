#include <stdio.h>
#include <stdbool.h>

#define INF 9999999

#define V 10

int G[V][V] = {
    {0, 15, 0, 0, 0, 30, 2, 0, 0, 0},
    {0, 0, 4, 0, 0, 0, 10, 0, 0, 0},
    {0, 4, 0, 10, 9, 0, 7, 13, 0, 0},
    {0, 0, 10, 0, 6, 0, 0, 6, 15, 2},
    {0, 0, 9, 6, 0, 0, 0, 0, 0, 9},
    {30, 0, 0, 0, 0, 0, 20, 13, 0, 0},
    {2, 10, 7, 0, 0, 20, 0, 8, 0, 0},
    {0, 0, 13, 6, 0, 13, 8, 0, 8, 0},
    {0, 0, 0, 15, 0, 0, 0, 8, 0, 1},
    {0, 0, 0, 2, 9, 0, 0, 0, 1, 0}};

int main()
{
    int no_edge;
    int total_w = 0;

    int selected[V];

    memset(selected, false, sizeof(selected));

    no_edge = 0;

    selected[2] = true;

    int x;
    int y;

    
    printf("Edge : Weight\n");

    while (no_edge < V - 1)
    {

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    { // not in selected and there is an edge
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        total_w += G[x][y];
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edge++;
    }
    printf("Selected 2\n");
    printf("Total Weight = %d", total_w);
    return 0;
}