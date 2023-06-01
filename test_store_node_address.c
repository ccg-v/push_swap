#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    // Create a sample linked list
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    // Store the address of a node in a variable
    struct Node* nodeAddress = second;

    // Printing the stored address
    printf("Address of the second node: %p\n", (void*)nodeAddress);

    // Accessing the data of the second node using the stored address
    printf("Data of the second node: %d\n", nodeAddress->data);

    // Freeing the memory
    free(head);
    free(second);
    free(third);

    return 0;
}