#include<stdio.h>
#include<stdlib.h>

struct Node
    {
        int data;
        struct Node *next;
    };

void insertNode(struct Node **head, int data)
{
    struct Node  *newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode->data = data;
    newNode->next= *head;

    *head = newNode;
}    

int main()
{
    

    struct Node *head = NULL; 

    int data;
    int choice;
    do
    {
        printf("\n1--------Insert Node");
        printf("\n2--------Print List");
        printf("\n0--------------Exit");
        printf("\nEnter Choice:");scanf("%d",&choice);

        if(choice==1)
        {
            printf("\nEnter Node Data:"); scanf("%d",&data); insertNode(&head, data);
        } else if(choice==2)
        {
            printf("\nStored Nodes in sll\n");
            struct Node *nodes = head;
            while(nodes!=NULL)
            {
                printf ("%d\n", nodes->data);
                nodes = nodes->next;

            }   
            printf("\n....Press any key to continue");
            getchar(); 
        }else if(choice!=0)
        
        
        {
            printf("\nInvalid Choice....");
            printf("\n....Press any key to continue");
            getchar();
        }

    } while (choice!=0);
    

     

    
    return 0;
}