

#include <stdio.h>
#define max 100
#define vertex_len 5
int explored[vertex_len];
int min_distance[vertex_len];
int my_tree[vertex_len];
int dis_mat[vertex_len][vertex_len];

int next_vertex()
{
    int min_index=0;
    int min=100;
    int i;
    
    for(i=0;i<vertex_len;i++)
    {
      if(explored[i]==0 && min_distance[i]<min)
      {
        min_index=i;
        min=min_distance[i];
      }
    }
    
    return min_index;
}

void update_keys(int new_added_vertex)
{
  int i=0;
  for(i;i<vertex_len;i++)
  {
    if(dis_mat[new_added_vertex][i] && explored[i]==0 && dis_mat[new_added_vertex][i]<min_distance[i])
    {
        min_distance[i]=dis_mat[new_added_vertex][i];
        my_tree[i]=new_added_vertex;
    }
   }
}

void prins_algo()
{
    int next,i=0;
    for(i;i<vertex_len;i++) 
    {
      min_distance[i]=max;
      explored[i]=0;
    }
    min_distance[0]=0;
    
    my_tree[0]=-1;
    
    
    for(i=0;i<vertex_len;i++)
    {
      
      next=next_vertex();
      explored[next]=1;
      update_keys(next);
      
    }
}

void print_tree()
{
  int i=1;
    printf("Edge  Weight\n");
    for(i;i<vertex_len;i++)
    {
      printf("%d-%d     %d\n",my_tree[i],i,dis_mat[i][my_tree[i]]);
    }
}

int main()
{
    int l_dis_mat[vertex_len][vertex_len]={
                      {0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
    int i=0,j=0;
    for(i;i<vertex_len;i++)
    {
      for(j=0;j<vertex_len;j++)
      {
        dis_mat[i][j]=l_dis_mat[i][j];
      }
     
    }
    prins_algo();
    print_tree();
    
    

    return 0;
}
