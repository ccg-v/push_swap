#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a node at the beginning of the linked list
void push(Node** headRef, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to merge two sorted linked lists into one sorted linked list
Node* merge(Node* listA, Node* listB) {
    if (listA == NULL) {
        return listB;
    }
    if (listB == NULL) {
        return listA;
    }

    Node* mergedList = NULL;
    if (listA->data <= listB->data) {
        mergedList = listA;
        mergedList->next = merge(listA->next, listB);
    }
    else {
        mergedList = listB;
        mergedList->next = merge(listA, listB->next);
    }

    return mergedList;
}

// Function to split the linked list into two halves
void splitList(Node* source, Node** listARef, Node** listBRef) {
    Node* slowPtr = source;
    Node* fastPtr = source->next;

    while (fastPtr != NULL) {
        fastPtr = fastPtr->next;
        if (fastPtr != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
    }

    *listARef = source;
    *listBRef = slowPtr->next;
    slowPtr->next = NULL;
}

// Function to sort the linked list using merge sort
void mergeSort(Node** headRef) {
    Node* head = *headRef;
    Node* listA;
    Node* listB;

    if (head == NULL || head->next == NULL) {
        return;
    }

    splitList(head, &listA, &listB);

    mergeSort(&listA);
    mergeSort(&listB);

    *headRef = merge(listA, listB);
}

int main() {
    srand(time(NULL));

    // Generate a list of 100 random integers
    Node* head = NULL;
    for (int i = 0; i < 100; i++) {
        push(&head, rand() % 1000);
    }

    // Print the unsorted list
    printf("Unsorted list: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Sort the list using merge sort
    mergeSort(&head);

    // Print the list of movements employed during the sorting process
    printf("List of movements:\n");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}

