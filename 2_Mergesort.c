/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


 #include <stdio.h>
        void merge(int arr[],int start,int mid,int end)
        {
            int l_s=start;
            int l_e=mid;
            int r_s=mid+1;
            int r_e=end;
            int i,j,k=l_s;
            
            
            int left[l_e+1];
            int right[r_e+1];
            
            for(i=l_s;i<=l_e;i++) left[i]=arr[i];
            for(j=r_s;j<=r_e;j++) right[j]=arr[j];
                
            
            
            
            
            
            while(l_s<=l_e && r_s<=r_e)
            {
                if(left[l_s]<=right[r_s]) arr[k++]=left[l_s++];
                else arr[k++]=right[r_s++];
            }
            
            while(l_s<=l_e) arr[k++]=left[l_s++];
            while(r_s<=r_e) arr[k++]=right[r_s++];
            
        }
        
        void merge_sort(int arr[],int start,int end)
        { 
            
            if(start!=end)
            {
                int mid=(start+end)/2;
                merge_sort(arr,start,mid);
                merge_sort(arr,mid+1,end);
                merge(arr,start,mid,end);
               
            }
        }
        
        
        int main()
        {
            int arr[]={10,1,5,20,86,3,0,46};
            merge_sort(arr,0,7);
            int i=0;
            for(i;i<=7;i++) printf("%d ",arr[i]);
            
        }



