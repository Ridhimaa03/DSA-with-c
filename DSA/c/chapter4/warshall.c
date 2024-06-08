#include<stdio.h>
#define V 4
#define INF 99999

void printSolution(int dist[][V]);
void floydWarshall (int graph[][V])
{
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];


	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
		    for (j = 0; j < V; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution(dist);
}


void printSolution(int dist[][V])
{
	int i,j;
	printf ("shortest distances between every pair of vertices \n");
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				printf("%s ", "INF");
			else
				printf ("%d ", dist[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	
	int graph[V][V] = { {0, 2, 1, 6},
						{2, 0, 5, 3},
						{1, 5, 0, 1},
						{6, 3, 1, 0}
					};

	floydWarshall(graph);
	return 0;
}


