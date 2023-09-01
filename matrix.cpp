#include<stdio.h>
void TriangularMatrix(int row, int col)
{
       int a[row][col];
       printf("\nEnter the Elements \n");
       for(int i = 0; i<row; i++)
       {
         for(int j = 0; j<col; j++)
         {
       		scanf("%d", &a[i][j]);
         }
       }      
       printf("\n\nUpper Triangular Matrix : "); 
 	   for(int i = 0; i<row; i++)
       {
         printf("\n");
         for(int j = 0; j<col; j++)
         {
     		 if(j >= i)
    		 printf(" %d ", a[i][j]);
    		 else
    		 printf(" 0 ");
          }
       }
       printf("\n\nLower Triangular Matrix : "); 
 	   for(int i = 0; i<row; i++)
       {
         printf("\n");
         for(int j = 0; j<col; j++)
         {
     		 if(j <= i)
    		 printf(" %d ", a[i][j]);
    		 else
    		 printf(" 0 ");
          }
       }
}
int identity(int num)
{
    int row, col;
    printf("\nIdentity Matrix :");    
    for (row = 0; row < num; row++)
    {
        for (col = 0; col < num; col++)
        {
            if (row == col)
                printf("%d ", 1);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
    return 0;
}


int main()
{
  int row, col,size; 
  printf("\nEnter Number of rows : ");
  scanf("%d", &row); 
  printf("\nEnter Number of columns : ");
  scanf("%d", &col);
  TriangularMatrix(row,col);
  printf("\nEnter The Size Of Identity Matrix:");
  scanf("%d",size);
  identity(size);
  return 0;
}