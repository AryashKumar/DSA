#include<stdio.h>  
#include<stdlib.h>  
struct node  
{ 
    int data;
    struct node *prev;  
    struct node *next;  
    
};  
struct node *head;  
void insertion_beginning();  
void insertion_last();  
void insertion_specified();  
void deletion_beginning();  
void deletion_last();  
void deletion_specified();  
void display();  
void search();  
int main ()  
{  
int choice =0;  
    while(choice != 9)  
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insertion_beginning();  
            break;  
            case 2:  
            insertion_last();  
            break;  
            case 3:  
            insertion_specified();  
            break;  
            case 4:  
            deletion_beginning();  
            break;  
            case 5:  
            deletion_last();  
            break;  
            case 6:  
            deletion_specified();  
            break;  
            case 7:  
            search();  
            break;  
            case 8:  
            display();  
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    } 
    return 0;

}  
void insertion_beginning()  
{  
   struct node *nextnode;   
   int item;  
   nextnode = (struct node *)malloc(sizeof(struct node));  
   if(nextnode == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value");  
    scanf("%d",&item);  
      
   if(head==NULL)  
   {  
       nextnode->next = NULL;  
       nextnode->prev=NULL;  
       nextnode->data=item;  
       head=nextnode;  
   }  
   else   
   {  
       nextnode->data=item;  
       nextnode->prev=NULL;  
       nextnode->next = head;  
       head->prev=nextnode;  
       head=nextnode;  
   }  
   printf("\nNode inserted\n");  
}  
     
}  
void insertion_last()  
{  
   struct node *nextnode,*temp;  
   int item;  
   nextnode = (struct node *) malloc(sizeof(struct node));  
   if(nextnode == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value");  
       scanf("%d",&item);  
        nextnode->data=item;  
       if(head == NULL)  
       {  
           nextnode->next = NULL;  
           nextnode->prev = NULL;  
           head = nextnode;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = nextnode;  
          nextnode ->prev=temp;  
          nextnode->next = NULL;  
          }  
             
       }  
     printf("\nnode inserted\n");  
    }  
void insertion_specified()  
{  
   struct node *nextnode,*temp;  
   int item,loc,i;  
   nextnode = (struct node *)malloc(sizeof(struct node));  
   if(nextnode == NULL)  
   {  
       printf("\n OVERFLOW");  
   }  
   else  
   {  
       temp=head;  
       printf("Enter the location");  
       scanf("%d",&loc);  
       for(i=0;i<loc;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("\n There are less than %d elements", loc);  
               return;  
           }  
       }  
       printf("Enter value");  
       scanf("%d",&item);  
       nextnode->data = item;  
       nextnode->next = temp->next;  
       nextnode -> prev = temp;  
       temp->next = nextnode;  
       temp->next->prev=nextnode;  
       printf("\nnode inserted\n");  
   }  
}  
void deletion_beginning()  
{  
    struct node *nextnode;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        nextnode = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(nextnode);  
        printf("\nnode deleted\n");  
    }  
  
}  
void deletion_last()  
{  
    struct node *nextnode;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        nextnode = head;   
        if(nextnode->next != NULL)  
        {  
            nextnode = nextnode -> next;   
        }  
        nextnode -> prev -> next = NULL;   
        free(nextnode);  
        printf("\nnode deleted\n");  
    }  
}  
void deletion_specified()  
{  
    struct node *nextnode, *temp;  
    int val;  
    printf("\n Enter the data after which the node is to be deleted : ");  
    scanf("%d", &val);  
    nextnode = head;  
    while(nextnode -> data != val)  
    nextnode = nextnode -> next;  
    if(nextnode -> next == NULL)  
    {  
        printf("\nCan't delete\n");  
    }  
    else if(nextnode -> next -> next == NULL)  
    {  
        nextnode ->next = NULL;  
    }  
    else  
    {   
        temp = nextnode -> next;  
        nextnode -> next = temp -> next;  
        temp -> next -> prev = nextnode;  
        free(temp);  
        printf("\nnode deleted\n");  
    }     
}  
void display()  
{  
    struct node *nextnode;  
    printf("\n printing values...\n");  
    nextnode = head;  
    while(nextnode != NULL)  
    {  
        printf("%d\n",nextnode->data);  
        nextnode=nextnode->next;  
    }  
}   
void search()  
{  
    struct node *nextnode;  
    int item,i=0,flag;  
    nextnode = head;   
    if(nextnode == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (nextnode!=NULL)  
        {  
            if(nextnode->data == item)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            nextnode = nextnode -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}  