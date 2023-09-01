#include <stdio.h> 
int main()
{
    int i,n1,n2,j,k;
    printf("Enter the size of the first array: ");
    scanf("%d",&n1);
    int arr1[n1];
    printf("Enter the elements of the first array: \n");
    for (i=0;i<n1;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter the size of the second array: ");
    scanf("%d",&n2);
    int arr2[n2];
    printf("Enter the elements of the second array: \n");
    for (j=0;j<n2;j++)
    {
        scanf("%d",&arr2[j]);
    }
    int arr3[n1+n2];
    i=j=0;
    int k;
    for (k=0;k<n1+n2;k++)
    {
        if (i<n1 && j<n2)
        {
            if (arr1[i]<arr2[j])
            {
                arr3[k]=arr1[i];
                i++;
            }
            else
            {
                arr3[k]=arr2[j];
                j++;
            }
        }
        else if (i<n1)
        {
            arr3[k]=arr1[i];
            i++;
        }
        else
        {
            arr3[k]=arr2[j];
            j++;
        }
    }
    printf("The merged array is: \n");
    for (k=0;k<n1+n2;k++)
    {
        printf("%d ",arr3[k]);
    }
   
    return 0;
}