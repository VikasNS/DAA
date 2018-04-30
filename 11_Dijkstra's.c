#include <stdio.h>
#define V 9

int till_now_min[V];
int tree[V];
int adjacent_matrix[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };


int find_minimum(){
	int min_vertex;
	int min_value=999;
	for (int i = 0; i < V; ++i)
	{
		if(!tree[i] && till_now_min[i]<min_value)
		{
			min_vertex = i;
			min_value = till_now_min[i];
		}

	}

	return min_vertex;
}

void dijkstra(){
	int i = 1;
	int vertex;
	while(i < V){
		vertex = find_minimum();
		tree[vertex]=1;

		for(int j=0;j<V;j++)
		{
			if(!tree[j])
			{
				if(adjacent_matrix[vertex][j]) //check if path exits
				{
					if(till_now_min[j]>(till_now_min[vertex]+adjacent_matrix[vertex][j]))
				{
					till_now_min[j]=till_now_min[vertex]+adjacent_matrix[vertex][j];
				}
				}
			}
		}

		i++;
	}

}

int main(){
	till_now_min[0] = 0;
	for(int i = 1; i < V; i++)
		till_now_min[i] = 999;

	for(int i = 0; i < V; i++)
		tree[i] = 0;

	dijkstra();

	printf("Vertex\tDistance from Source\n");

	for (int i = 0; i < V; i++)
	{
		printf("%d\t%d\n",i,till_now_min[i]);
	}
	return 0;
}
