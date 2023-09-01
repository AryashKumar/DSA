#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;
    int exp;
    struct Node* next;
}Node;

void insert(Node** poly, int coef, int exp) 
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
    
    if (*poly == NULL)
    {
        *poly = temp;
        return;
    }
    
    Node* current = *poly;
    
    while (current->next != NULL) 
    {
        current = current->next;
    }
    
    current->next = temp;
}

void print(Node* poly)
{
    if (poly == NULL) 
    {
        printf("0\n");
        return;
    }
    
    Node* current = poly;
    
    while (current != NULL)
    {
        printf("%dx^%d", current->coef, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    
    printf("\n");
}

Node* add(Node* poly1, Node* poly2) 
{
    Node* result = NULL;
    
    while (poly1 != NULL && poly2 != NULL) 
    {
        if (poly1->exp == poly2->exp) 
        {
            insert(&result, poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) 
        {
            insert(&result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else 
        {
            insert(&result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
    }
    
    while (poly1 != NULL) 
    {
        insert(&result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }
    
    while (poly2 != NULL) 
    {
        insert(&result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }
    
    return result;
}

int main() 
{
    int choice=0,n1,n2,n3,n4;
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    printf("Enter First Polynomial:\n");
    while (choice!=1)
    {
    
    printf("Enter Coefficient:");
    scanf("%d",&n1);
    printf("Enter Exponent:");
    scanf("%d",&n2);    
    insert(&poly1, n1, n2);
    printf("Enter 1 to Stop:");
    scanf("%d",&choice);
    }
    printf("Enter Second Polynomial:\n");

    while (choice!=2)
    {
    printf("Enter Coefficient:");
    scanf("%d",&n3);
    printf("Enter Exponent:");
    scanf("%d",&n4); 
    insert(&poly2,n3,n4);
    printf("Enter 2 to Stop:");
    scanf("%d",&choice);
    }
    

    printf("First polynomial: ");
    print(poly1);

    printf("Second polynomial: ");
    print(poly2);

    Node* result = add(poly1, poly2);
    printf("Result: ");
    print(result);

    return 0;
}