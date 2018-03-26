/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int weight[10];
int value[10];
int item_weight_matrix[10][10];


int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

int knapsack(int n,int w)
{
    if(item_weight_matrix[n][w]==-1)
    {
        if(weight[n]>w) item_weight_matrix[n][w]=knapsack(n-1,w);
        else  item_weight_matrix[n][w]=max(knapsack(n-1,w),(value[n]+knapsack(n-1,w-weight[n])));
    }
    return item_weight_matrix[n][w];
}

void print_chosen(int n,int w)
{
    int i=n,j=w,k;
    while(i>0 && j>0)
    {
        if(item_weight_matrix[i][j]!=item_weight_matrix[i-1][j]) 
        {
            printf("item %d \n",i);
            j=j-weight[i];
        }
        i--;
    }
    
}

int main()
{
    int n,i,j,w;
    
    printf("Enter the number of items");
    scanf("%d",&n);
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0) item_weight_matrix[i][j]=0;
            else item_weight_matrix[i][j]=-1;
        }
    }
    
    for(i=1;i<=n;i++)
    {
        printf("Enter the weight %d element");
        scanf("%d",&weight[i]);
        printf("Enter the value %d element");
        scanf("%d",&value[i]);
    }
    
    knapsack(4,5);
    print_chosen(4,5);
    return 0;
}
