#include<stdio.h>
#include<math.h>
 
int board[20],count;
 
int main()
{
 int n,i,j;
 void queen(int row,int n);
 
 printf(" - N Queens Problem Using Backtracking -");
 printf("\n\nEnter number of Queens:");
 scanf("%d",&n);
 queen(1,n);
 return 0;
}
 
//function for printing the solution
void print(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);
 
 for(i=1;i<=n;i++)
  printf("\t%d",i);
 
 for(i=1;i<=n;++i)
 {
  printf("\n\n%d",i);
  for(j=1;j<=n;++j) //for nxn board
  {
   if(board[i]==j)
    printf("\tQ"); //queen at i,j position
   else
    printf("\t-"); //empty slot
  }
 }
}
 
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
 int i;
 //We have a pair of row and column given as parameter to our function
 //We need to check if any conflicts exits or not
 //only ask permission for rows above it so its row-1
 //We iterate through all the rows,i represents a row and board[i] represents the column in that ith row where queen is placed
 for(i=1;i<=row-1;++i)
 {
  //checking column and digonal conflicts
  if(board[i]==column) //As we iterate ,board[i] gives all the columns in which we have queens and if a queen is allready placed in the new column in which we are trying to place the next queen,we return 0
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row)) //For diagonal conflict
    return 0;
 }
 
 return 1; //no conflicts
}
 
//function to check for proper positioning of queen
void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column))
  {
   board[row]=column; //no conflicts so place queen
   if(row==n) //dead end , we have completed placing all queens , so we print it.
      print(n); //printing the board configuration
   else //try queen with next position 
      queen(row+1,n);  //ie we continue placing new queen in next row
  }
 }
}
