#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createLL() {
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
    node->next = NULL;
    return start;
}
void print_LL(struct Node* start) {
    struct Node* temp = start;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct Node* reverseLL(struct Node* start){
    struct Node* prev = NULL;
    struct Node* ptr = start;
    struct Node* nextNode = NULL;
    if(ptr->next == NULL){
        return start;
    }
    while(ptr != NULL){
        nextNode = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = nextNode;
    }
    start = prev;
    return start;
}
bool isPalindrome(struct Node* start){
    if(start == NULL || start->next == NULL){
        return 1;
    }
    struct Node* slow = start;
    struct Node* fast = start;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node* newHead = reverseLL(slow->next);
    struct Node* first = start;
    struct Node* second = newHead;
    while(second != NULL){
        if(first->data != second->data){
            reverseLL(start);
            return 0;
        }
        else{
            first = first->next;
            second = second->next;
        }
    }
    reverseLL(start);
    return 1;
}
int main(){
    struct Node* start = NULL;
    start = createLL();
    print_LL(start);
    if(isPalindrome(start)){
        printf("Yes it is a Palindrome Linked List.");
    }
    else{
        printf("Oops! It's not a Palindrome Linked List.");
    }
    return 0;
}