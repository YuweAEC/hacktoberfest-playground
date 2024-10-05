#include<stdio.h>
#include<stdlib.h>

//Insertion and Deletion functions for a doubly linked list 

struct Node{
    int data;
    struct Node *next;
    struct Node *back;
};
/////////////////////////////////////////////////////////////////////////////////////
struct Node *insertion(struct Node *head)
{
    printf("Enter location and value : ");
    int val , k;
    scanf("%d %d",&k , &val);
    //EDGE CASE 1 ----- NO Head present-----
    if(head == NULL){
        if(k==1){
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = val;
            newNode->back = NULL;
            newNode->next = NULL;
        }
        else return NULL;
    }
    //EDGE CASE 2 ----- Insert at head -----
    if(k==1){
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = head;
        head->back = newNode;
        newNode->back = NULL;
        return newNode;
    }
    //Main insertion code :::::::
    struct Node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        if(count == k) break;
        temp = temp->next;
    }
    struct Node *prev = temp->back;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp;
    newNode->back = prev;
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
/////////////////////////////////////////////////////////////////////////////////////
struct Node *deletion(struct Node *head)
{
    printf("Enter location to delete : ");
    int k;
    scanf("%d",&k);
    //EDGE CASE 1 ----- NO Head present-----
    if(head == NULL) return NULL;
    int count = 0;
    struct Node *temp = head;
    while( temp!= NULL){
        count++;
        if(count == k) break;
        temp = temp -> next;
    }
    struct Node *prev = temp->back;
    struct Node *front = temp->next;
    prev->next = front;
    front->back = prev;
    temp->next = NULL;
    temp->back = NULL;
    free(temp);
    return head;

}
/////////////////////////////////////////////////////////////////////////////////////
void traversal(struct Node *head)
{
    if(head == NULL)
        printf("Empty List.\n");
    struct Node *p = head;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
/////////////////////////////////////////////////////////////////////////////////////
void main()
{
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter number of elements you want to enter : ");
    int n;
    scanf("%d",&n);
    
    printf("Enter head value : ");
    scanf("%d",&(head->data));
    head->next = NULL;

    printf("Now enter the remaining %d element(s) : ",(n-1));
    struct Node *p = head;
    for(int k = 1 ; k < n ; k++){
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&(temp->data));
        temp->next=NULL;
        p->next = temp;
        temp->back = p;
        p = p->next;
    }
    int choice;
    while(1)
    {
        printf("________MENU________\n");
        printf("1. Insert node at a specific position.\n");
        printf("2. Delete node at a specific position.\n");
        printf("3. Traverse the nodes\n");
        printf("0. Exit.\n");
        printf("Enter choice : ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                      head = insertion(head);
            }
            break;
            case 2:{
                      head = deletion(head);
            }
            break;
            case 3:{
                      traversal(head);
            }
            break;
            case 0:{
                    printf("Exiting the code...");
                      exit(0);
            }
            break;
            default : printf("Wrong choice. Please try again.\n");
        }
    }
}