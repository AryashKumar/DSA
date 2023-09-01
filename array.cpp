#include<stdio.h>
#define size 20
main()
{
    int arr[size];
    int n,a,b,c,i,x,y,z,pos,mid,beg,end;    
    printf("Enter The Number Of Elements In Array:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    while(1)
    {
    printf("\nEnter Your Choice:\n1.Insertion\n2.Deletion\n3.Display\n4.Search\n5.Quit\n");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        if(n==size)
        {
            printf("The Array Is Full");
        }
        else
        {
        printf("Enter the element to be inserted: ");
        scanf("%d", &x);

        printf("Enter the position where the element is to be inserted: ");
        scanf("%d", &pos);
        for (i = n - 1; i >= pos; i--) 
        {
           arr[i + 1] = arr[i];
        }
        arr[pos] = x;
        n++;  // indicates no of elements

        printf("The array after inserting the new element is: ");
        for (i = 0; i <n; i++)  
        {
          printf("%d ", arr[i]);
        }
        }
        break;
    case 2:
          
         printf("Enter the location of the element to be deleted: ");
         scanf("%d", &y);
         if (y< 0 || y>= n) 
         {
           printf("Array Is Empty or Out of Range\n");
           return 1;
         }
        for (i = y; i < n - 1; i++) 
        {
          arr[i] = arr[i + 1];
        }
        n--;
        printf("The array after deleting the element is: ");
        for (i = 0; i < n; i++) 
        {
         printf("%d ", arr[i]);
        }
        break;   
    case 3:
    printf("The Elements Of The Array Are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    break;
    case 4:
    printf("Enter Your Choice:\n1.Linear Search\n2.Binary Search\n");
    scanf("%d",&b);
    switch (b)
    {
    case 1:
        printf("Enter the element to search: ");
        scanf("%d", &z); 
        for (i = 0; i <n; i++) 
        {
          if (arr[i] == z) 
          {
            printf("The element %d is found at index %d\n", z, i);
            break;
          }
        }
         if (i == n)
         {
          printf("The element %d is not found\n", z);
         }

        break;
    case 2:
        printf("Enter the element to search: ");
        scanf("%d", &c);
        beg=0;
        end=n-1;
        while (beg<=end) 
        {
         mid= (beg+end)/2;
        if (arr[mid] == c) 
        {
           printf("The Element %d is found at index %d\n",c,mid);
           break;
        } 
        else if (arr[mid] < c)
        {
          beg=mid+1;
        } 
        else  
        {
          end=mid-1;
        } 
        }//while
        if (beg>end) 
        {
          printf("Element not found\n");
        }
    break; 

    default:
        break;
    }
    break;
    
    default:
        break;
    }
    if(a==5)
    break;
    }


 //printf("\n Press any key to exit now");
 

}