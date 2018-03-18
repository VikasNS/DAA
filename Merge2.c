/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, Perl, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/


#include <stdio.h>

void merge(int arr[],int left_start,int left_end,int right_start,int right_end)
{
    int temp[right_end];
    int l=left_start;
    int r=right_start;
    int k=0;
    
    while(l<=left_end && r<=right_end)
    {
        if(arr[l]<arr[r]) temp[k++]=arr[l++];
        else temp[k++]=arr[r++];
    }
    
    
    while(l<=left_end) temp[k++]=arr[l++];
    while(r<=right_end) temp[k++]=arr[r++];
       k=0;
    //printf("%d %d",left_start,right_end);
    for(l=left_start;l<=right_end;l++) arr[l]=temp[k++];
}


void merge_sort(int arr[],int start,int end)
{
    
    if(start<end)
    {
       
       int mid=(start+end)/2;
       merge_sort(arr,start,mid);
       merge_sort(arr,mid+1,end);
       merge(arr,start,mid,mid+1,end);
    }
}



void main()
{
    int arr[10]={9,8,7,6,5,4,3,2,1,0};
    merge_sort(arr,0,9);
    int i=0;
    for(i;i<10;i++) printf(" %d ",arr[i]);

    
}
