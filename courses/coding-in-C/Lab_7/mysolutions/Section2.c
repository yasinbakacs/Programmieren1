#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    double value;
    struct Node *next;
} Node;


Node *create_Node(double value);
Node *insert_at_3(Node *head, double value);
void print_list(Node *head, int n);

int main(){
srand(time(NULL));
Node *head = NULL;
Node *tmp;
for(int i = 0; i < 50; i++){
    tmp = create_Node(rand() % 100 * 1.5);
    tmp->next = head;
    head = tmp;
    }
   
print_list(head, 10);



int arr[51];
for(int i = 0; i < 50; i++){
    arr[i] = rand() % 100;
}

insert_at_3(head, 42.0);
printf("Node new");
print_list(head, 10);
}






/*
 * @Creates a new node with the given value.
 *
 * @param [in] double value: The value to be stored in the node.
 * @return Returns a pointer to the newly created node.
 */

Node *create_Node(double value){
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); 
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

/*
 * @Inserts a new node with the given value at the 3rd position in the linked list.
 *
 * @param [in] Node *head: A pointer to the head of the linked list.
 * @param [in] double value: The value to be stored in the new node.
 * @return Returns a pointer to the head of the modified linked list.
 */

Node* insert_at_3(Node *head, double value){
    Node *newNode = create_Node(value);
    Node *current = head;
    for(int i = 1 ; i < 2 && current != NULL; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}


void print_list(Node *head, int n){
    Node *current = head;
    for(int i = 1; i < n; i++){
        printf("Node value: %f\n", current->value);
        current = current->next;
    }
    
}
 


