#include <stdio.h>

int heap[100];
int size;
int duplicate_size;

int has_left_child(int parent)
{
    return (2*parent+1)<size; 
}

int has_right_child(int parent)
{
    return (2*parent+2)<size;
}

int max_ele_index(int parent)
{
    //if there are no children
    if(!has_left_child(parent)) return -1; 
    //if there is only left child or if left child is greater than right child
    else if(!has_right_child(parent) || heap[2*parent+1]>heap[2*parent+2]) return (2*parent+1); 
    return (2*parent+2); //if none of the above,its obvious that right child is greater
}

void swap(int index,int child)
{
    int temp=heap[index];
    heap[index]=heap[child];
    heap[child]=temp;
}

void heapify(int index)
{
    int child;
    //heapify untill there are children and we are out of order
    while(((child=max_ele_index(index))!=-1) && (heap[index]<heap[child])) 
    {
        swap(index,child); //we swap with the max child to get the order back
        index=child; //we continue the same downwords
    }
}

void build_heap()
{
    int index=size/2-1; //index of last parent 
    //heapify all the parents starting from the last parent
    for(index;index>=0;index--) heapify(index); 
}

void heap_sort()
{
    while(size>=0)
    {
        swap(0,--size);
        heapify(0);
    }
}
 
int main()
{
    printf("How many elements do you want to sort.?\n");
    scanf("%d",&size);
    duplicate_size=size;
    
    int i=0;
    for(i;i<size;i++) scanf("%d",&heap[i]);
    
    build_heap();
    heap_sort();
    
    for(i=0;i<duplicate_size;i++) printf("%d ",heap[i]);
    

    return 0;
}
