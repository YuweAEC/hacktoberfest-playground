#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createCLL(){
    struct Node* node, *start;
    char ch;
    node = (struct Node*) malloc(sizeof(struct Node));
    start = node;
    printf("Enter Data: ");
    scanf("%d", &node->data);
    printf("Do you want to continue with more nodes? (Y/N): ");
    scanf(" %c", &ch);
    while (ch != 'n' && ch != 'N') {
        node->next = (struct Node*) malloc(sizeof(struct Node));
        node = node->next;
        printf("Enter Data: ");
        scanf("%d", &node->data);
        printf("Do you want to continue with more nodes? (Y/N): ");
        scanf(" %c", &ch);
    }
    node->next = start;
    return start;
}
void print_CLL(struct Node* start) {
    struct Node* temp = start;
    if(start == NULL) printf("\nThe list is empty.");
    printf("The Circular Linked List is:\n");
    do {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("%d\n", start->data);
}
struct Node* insert_begin(struct Node* start){
    struct Node* ptr = start, *newNode;
    if(start == NULL){
        printf("\nThe list is empty.");
        return start;
    }
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Data:\n");
    scanf("%d", &newNode->data);
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = start;
    start = newNode;
    return start;
}
struct Node* insert_end(struct Node* start){
    struct Node* ptr = start, *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Data:\n");
    scanf("%d", &newNode->data);
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = start;
    return start;
}
struct Node* insert_sloc(struct Node* start, int loc){
    struct Node *newNode, *temp;
    int i;
    newNode = (struct Node*) malloc (sizeof(struct Node));
    printf("Enter the element to be inserted: ");
    scanf("%d", &newNode->data);
    temp = start;
    for(i=0; i<loc-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("POSITION NOT FOUND\n");
        return start;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return start;
}
void insert_after_item(struct Node *start, int item){
    struct Node *node = start, *newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    while(node != NULL && node->data != item){
        node = node->next;
    }
    if(node == NULL){
        printf("ITEM NOT FOUND\n");
        free(newNode);
        return;
    }
    //insert new node after found node
    newNode->next = node->next;
    node->next = newNode;
}
struct Node* delete_begin(struct Node* start){
    struct Node* ptr = start;
    if(start == NULL){
        printf("List is Empty.");
        return start;
    }
    if (start->next == start) {
        printf("Deleted element is %d\n", start->data);
        free(start);
        return NULL;
    }
    // Traverse to the last node
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = start->next; // last node is pointing to 2nd node
    struct Node* temp = start;
    start = start->next; // point start to new first node
    printf("Deleted element is %d", temp->data);
    free(temp);
    return start;
}
struct Node* delete_end(struct Node* start){
    struct Node* ptr = start, *temp;
    if(start == NULL){
        printf("List is Empty.");
        return start;
    }
    while(ptr->next != start){
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = start;
    printf("Deleted element is %d", ptr->data);
    free(ptr);
    return start;
}
struct Node* delete_sloc(struct Node* start, int loc){
    struct Node* ptr, *temp;
    int i;
    if(start == NULL){
        printf("The List is Empty");
        return start;
    }
    printf("Enter the position:");
    scanf("%d", &loc);
    for(i=0; i<loc; i++){
        temp = ptr;
        ptr = ptr->next;
    }
    if(temp == NULL){
        printf("POSITION NOT EXIST");
        return start;
    }
    temp->next = ptr->next;
    printf("The deleted element is %d", ptr->data);
    free(ptr);
    return start;
}
struct Node* del_item(struct Node* start, int item){
    struct Node* ptr = start, *temp;
    if(start == NULL){
        printf("The List is Empty.");
        return start;
    }
    while(ptr != NULL && ptr->data != item){
        temp = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("ITEM NOT EXIST");
        return start; 
    }
    temp->next = ptr->next;
    printf("The deleted element is %d", ptr->data);
    free(ptr);
    return start;
}
int main(){
    struct Node* start = NULL;
    int choice, loc, item, SubChoice;
    printf("Enter the elements of Circular Linked List:\n");
    start = createCLL();
    print_CLL(start);
    printf("Hey User!! What do you want to enter? Enter 10 for Insertion and 20 for Deletion\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch(choice){
        case 10:
            printf("1. Insert at Beginning\n");
            printf("2. Insert at End\n");
            printf("3. Insert at Specific Position\n");
            printf("4. Insert After Specific Item\n");
            printf("5. Exit\n");
            printf("Enter your subchoice: ");
            scanf("%d", &SubChoice);
            switch(SubChoice){
                case 1:
                    start = insert_begin(start);
                    print_CLL(start);
                    break;
                case 2:
                    start = insert_end(start);
                    print_CLL(start);
                    break;
                case 3:
                    printf("Enter the position to insert the element: ");
                    scanf("%d", &loc);
                    start = insert_sloc(start, loc);
                    print_CLL(start);
                    break;
                case 4:
                    printf("Enter the item after which the new node should be inserted: ");
                    scanf("%d", &item);
                    insert_after_item(start, item);
                    print_CLL(start);
                    break;
                case 5:
                    exit(0);
                default:
                    printf("\nOops! Wrong choice...Please try again!\n");
            }
            break;
        case 20:
            printf("1. Delete from Beginning\n");
            printf("2. Delete from End\n");
            printf("3. Delete from any Position\n");
            printf("4. Delete After Specific Item\n");
            printf("5. Exit\n");
            printf("Enter your subchoice: ");
            scanf("%d", &SubChoice);
            switch(SubChoice){
                case 1:
                    start = delete_begin(start);
                    break;
                case 2:
                    start = delete_end(start);
                    break;
                case 3:
                    printf("Enter the item after which the new node should be inserted: ");
                    scanf("%d", &item);
                    delete_sloc(start, loc);
                    printf("\n");
                    print_CLL(start);
                    break;
                case 4:
                    printf("Enter the item after which the new node should be deleted: ");
                    scanf("%d", &item);
                    del_item(start, item);
                    printf("\n");
                    print_CLL(start);
                    break;
                case 5:
                    exit(0);
                default:
                    printf("\nOops! Wrong choice...Please try again!\n");
            }
            break;
        default:
            printf("Invalid Choice!\n");
    }
    return 0;
}
