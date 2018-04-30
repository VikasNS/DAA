#include <stdio.h>
int size=5;
int adj_mat[5][5]={{0,1,1,0,0},{1,0,0,1,0},{1,0,0,0,1},{0,1,0,0,1},{0,0,1,1,0}};
int dfs_visited[5]={0,0,0,0,0};
int bfs_visited[5]={0,0,0,0,0};

int queue[5];
int front=0;
int rear=0;

void dfs(int index)
{
    printf("%d ",index);
    dfs_visited[index]=1;
    int i=0;
    for(i;i<size;i++)
    {
        if(!dfs_visited[i] && adj_mat[index][i]) dfs (i);
    }
}

void enqueue(int value)
{
    queue[rear++]=value;
}

int dequeue()
{
    return (queue[front++]);
}

int isEmpty()
{
    return (front == rear);
}

void bfs(int index)
{
    enqueue(index);
    
    int ele;
    int i;
    bfs_visited[ele]=1;
    while(!isEmpty())
    {
        ele=dequeue();
        printf("%d ",ele);
        
        for(i=0;i<size;i++)
        {
            if(!bfs_visited[i] && adj_mat[ele][i]) 
            {
                enqueue(i);
                bfs_visited[i]=1; //*******Once you put it into queue mark it as visited******
                
            }
        }
    }
}

int main()
{
    
    dfs(0);
    printf("\n");
    bfs(0);
    return 0;
}
