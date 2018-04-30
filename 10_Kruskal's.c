#include<stdio.h>

#define size 6
int adj_mat[size][size]={{0,3,1,6,0,0},
                         {3,0,5,0,3,0},
                         {1,5,0,5,6,4},
                         {6,0,5,0,0,2},
                         {0,3,6,0,0,6},
                         {0,0,4,2,6,0}
                        };
int im_linked_to[size]={-1,-1,-1,-1,-1,-1};



int whos_my_parent(int vertex)
{
  //Importance of while loop is seen when we connect 2 separate graph (with atleast 2 vertices in each)
  //Its helps us to find the parent in the above case
  while(im_linked_to[vertex]!=-1) vertex=im_linked_to[vertex];
  //printf("vertex im returning %d \n",vertex);
  return vertex;
}

int forms_cycle(int vertex1,int vertex2)
{
    //printf("vertex1 : %d vertex2 %d \n",vertex1,vertex2);
    if(vertex1==vertex2) return 1;
    im_linked_to[vertex2]=vertex1;
    return 0;
}

void krushkal()
{
    int i=1,s,t,min,min_v1,min_v2,t_v1,t_v2,total_cost=0,current_edge_cost=0;
    while(i<size)
    {
        min=999;
        for(s=0;s<size;s++)
        {
            for(t=0;t<size;t++)
            {
                if(min>adj_mat[s][t] && adj_mat[s][t]) //**check the path existance
                {
                    min=adj_mat[s][t];
                    
                    t_v1=min_v1=s;
                    t_v2=min_v2=t;
                    
                    total_cost+=min;
                    current_edge_cost=min;
                    
                }
            }
        }
        
        t_v1=whos_my_parent(t_v1);
        t_v2=whos_my_parent(t_v2);
        
       if(!forms_cycle(t_v1,t_v2)) printf("%d edge between %d --> %d : %d \n",i,min_v1+1,min_v2+1,current_edge_cost);

        
        adj_mat[min_v1][min_v2]=adj_mat[min_v2][min_v1]=999;
        i++;
    }
}


void  main()
{
    krushkal();
}
