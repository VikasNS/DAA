#include<stdio.h>

int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int knapsack(int capacity,int weight[],int value[],int n)
{
    
    int k[n+1][capacity+1];
    int item,remainig_weight;
    
    for(item=0;item<=n;item++)
    {
        for(remainig_weight=0;remainig_weight<=capacity;remainig_weight++)
        {
            if(item==0 || remainig_weight == 0) k[item][remainig_weight]=0;
            else if(weight[item]>remainig_weight) k[item][remainig_weight]=k[item-1][remainig_weight];
            else  k[item][remainig_weight]=max( value[item]+k[item-1][remainig_weight-weight[item]] , k[item-1][remainig_weight]);
        }
    }
    
    int t;
    remainig_weight=capacity;
    
    printf("Items are ");
    for(item=n;item>0;item--)
    {
        
           if(k[item][remainig_weight]!=k[item-1][remainig_weight])
           {
               printf("%d ",item);
               remainig_weight-=weight[item];
           }
    }
    printf("\n");
    return k[n][capacity];
}

void main()
{
    int value[4]={0,60, 100, 120};
    int weight[4]={0,10, 20, 30};
    int i,capacity=50,n=3;
    printf("The total profit %d ",knapsack(capacity,weight,value,n));
}
