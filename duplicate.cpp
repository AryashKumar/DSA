#include <stdio.h>  
 
int main ()  
{  
      
    int arr[20],i,j,k,n;     
    printf ("Enter the number of elements in an array:");  
    scanf (" %d", &n);    
    for (i=0;i<n;i++)  
    {  
        scanf("%d",&arr[i]);  
    }         
    for (i=0; i<n;i ++)  
    {  
        for (j=i+1;j<n;j++)  
        {   
            if ( arr[i] == arr[j])  
            {  
                for (k=j;k<n-1;k++)  
                {  
                    arr[k]=arr[k+1];  
                }  
                // decrease the size of array after removing duplicate element  
                n--;                   
            // if the position of the elements is changes, don't increase the index j  
                j--;      
            }  
        }  
    }    
    printf ("\nArray elements after deletion of the duplicate elements: ");    
    for (i=0;i<n;i++)  
    {  
        printf("%d ",arr[i]);  
    }  
    return 0;  
}  