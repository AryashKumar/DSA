#include<stdio.h>
#include<string.h>
#define size 20

int main()
{
    struct student
    {
     int rollno;
     char name[10];
     float perc;
    }stu[size];
    int i,n,a,m,b,c,d,e,r,newr,rd;
    float p,newp,pd;
    char arr[20],na[20],newn[20],nd[20];
    printf("Enter The Number Of Records To Be Entered:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Roll Number:");
        scanf("%d",&stu[i].rollno);
        printf("Enter Name:");
        scanf("%s",&stu[i].name);
        printf("Enter Percentage:");
        scanf("%f",&stu[i].perc);
    }
    while (1)
    {
    printf("\n....Student Record Keeping....\nChoices Are:\n1.Add Record\n2.Display All Record\n3.Search a Record\n4.Modify Record\n5.Delete Record\n6.Quit\n");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
    printf("Enter The Number Of Records To Be Added:");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("Enter Roll Number:");
        scanf("%d",&stu[i].rollno);
        printf("Enter Name:");
        scanf("%s",&stu[i].name);
        printf("Enter Percentage:");
        scanf("%.2f",&stu[i].perc);
    }
    n=n+m;

        break;
    case 2:
    for(i=0;i<n;i++)
    {
        printf("\nRoll Number:%d",stu[i].rollno);
        printf("\nName:%s",stu[i].name);
        printf("\nPercentage:%f",stu[i].perc);
    }
    break;
    case 3:
    printf("Search:\n1.Name\n2.Roll Number\n");
    scanf("%d",&b);
    switch (b)
    {
    case 1:
    printf("Enter Name:");
    scanf("%s",&arr); 
    for(i=0;i<n;i++)
    {
    if(strcmp(stu[i].name,arr)==0)
    {
        printf("Record Found");
    }
    }
        break;
    case 2:
    printf("Enter Roll Number:");
    scanf("%d",&c);
    for(i=0;i<n;i++)
    {
    if(stu[i].rollno==c)
    {
        printf("Record Found");
    }
    }
        break;

    break;
    default:
        break;
    }
    case 4:
    printf("\nEnter The Item To Be Updated:\n1.Roll Number\n2.Name\n3.Percentage\n");
    scanf("%d",&d);
    switch (d)
    {
    case 1:
        printf("Enter The Roll Number To Be Updated:");
        scanf("%d",&r);
        printf("Enter New Roll Number:");
        scanf("%d",&newr);
        for(i=0;i<n;i++)
    {
    if(stu[i].rollno==r)
    {
       stu[i].rollno=newr;
    }
    else
    printf("\nRecord Not Found....\n");
    }
    break;
    case 2:
    printf("Enter The Name To Be Updated:");
    scanf("%s",&na);
    printf("Enter New Name:");
    scanf("%s",&newn);
    for(i=0;i<n;i++)
    {
    if(strcmp(stu[i].name,na)==0)
    {
       strcpy(stu[i].name,newn);
    }
    else
    printf("\nRecord Not Found....\n");
    }

    
    break;

    case 3:
    printf("Enter The Percentage To Be Updated:");
    scanf("%f",&p);
    printf("Enter New Roll Number:");
    scanf("%f",&newp);
    for(i=0;i<n;i++)
    {
    if(stu[i].perc==p)
    {
       stu[i].perc=newp;
    }
    else
    printf("\nRecord Not Found....\n");
    }
        break;
    
    default:
        break;
    }
    case 5:
    printf("\nEnter The Item To Be Deleted:\n1.Roll Number\n2.Name\n3.Percentage\n");
    scanf("%d",&e);
    switch (e)
    {
    case 1:
    printf("Enter The Roll Number To Be Deleted:");
    scanf("%d",&rd);
        
    for(i=0;i<n;i++)
    {
    if(stu[i].rollno==rd)
    {
       stu[i].rollno=stu[i+1].rollno;
    }
    else
    printf("\nRecord Not Found....\n");
    }
    break;
    case 2:
    printf("Enter The Name To Be Deleted:");
    scanf("%s",&nd);
    for(i=0;i<n;i++)
    {
    if(strcmp(stu[i].name,nd)==0)
    {
       strcpy(stu[i].name,stu[i+1].name);
    }
    else
    printf("\nRecord Not Found....\n");
    }

    
    break;

    case 3:
    printf("Enter The Percentage To Be Deleted:");
    scanf("%f",&pd);
    
    for(i=0;i<n;i++)
    {
    if(stu[i].perc==p)
    {
       stu[i].perc=stu[i+1].perc;
    }
    else
    printf("\nRecord Not Found....\n");
    }
        break;
    
    default:
        break;
    }    
    default:
        break;
    }
    if (a==6)
    break;
    
    }

    
    return 0;
}