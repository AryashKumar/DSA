#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
  
void beginsert ();   
void lastinsert ();  
void randominsert();  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
void search();  
int main ()  
{  
    int choice =0;  
    while(choice != 9)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            beginsert();      
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            randominsert();       
            break;  
            case 4:  
            begin_delete();       
            break;  
            case 5:  
            last_delete();        
            break;  
            case 6:  
            random_delete();          
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
void beginsert()  
{  
    struct node *nextnode;  
    int item;  
    nextnode = (struct node *) malloc(sizeof(struct node *));  
    if(nextnode == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter value\n");    
        scanf("%d",&item);    
        nextnode->data = item;  
        nextnode->next = head;  
        head = nextnode;  
        printf("\nNode inserted");  
    }  
      
}  
void lastinsert()  
{  
    struct node *nextnode,*temp;  
    int item;     
    nextnode = (struct node*)malloc(sizeof(struct node));      
    if(nextnode == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        nextnode->data = item;  
        if(head == NULL)  
        {  
            nextnode-> next = NULL;  
            head = nextnode;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = nextnode;  
            nextnode->next = NULL;  
            printf("\nNode inserted");  
          
        }  
    }  
}  
void randominsert()  
{  
    int i,loc,item;   
    struct node *nextnode, *temp;  
    nextnode = (struct node *) malloc (sizeof(struct node));  
    if(nextnode == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value");  
        scanf("%d",&item);  
        nextnode->data = item;  
        printf("\nEnter the location after which you want to insert ");  
        scanf("\n%d",&loc);  
        temp=head;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
          
        }  
        nextnode ->next = temp ->next;   
        temp ->next = nextnode;   
        printf("\nNode inserted");  
    }  
}  
void begin_delete()  
{  
    struct node *temp;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else  
    {  
        temp = head;  
        head = temp->next;  

        free(temp);  
        printf("\nNode deleted from the begining ...\n");  
    }  
}  
void last_delete()  
{  
    struct node *nextnode,*current;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted ...\n");  
    }  
          
    else  
    {  
        nextnode = head;   
        while(nextnode->next != NULL)  
        {  
            current= nextnode;  
            nextnode = nextnode ->next;  
        }  
        current->next = NULL;  
        free(nextnode);  
        printf("\nDeleted Node from the last ...\n");  
    }     
}  
void random_delete()  
{  
    struct node *nextnode,*current;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc);  
    nextnode=head;  
    for(i=0;i<loc;i++)  
    {  
        current = nextnode;       
        nextnode = nextnode->next;  
              
        if(nextnode == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    current ->next = nextnode ->next;  
    free(nextnode);  
    printf("\nDeleted node %d ",loc+1);  
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
                printf("item found at location %d ",i+1);  
                flag=0;  
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
            printf("Item not found\n");  
        }  
    }     
          
}  
  
void display()  
{  
    struct node *nextnode;  
    nextnode = head;   
    if(nextnode == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (nextnode!=NULL)  
        {  
            printf("\n%d",nextnode->data);  
            nextnode = nextnode -> next;  
        }  
    }  
}     