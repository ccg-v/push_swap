#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* merge(struct Node* left, struct Node* right) {
    struct Node* result = NULL;
    if(left == NULL) {
        return right;
    }
    if(right == NULL) {
        return left;
    }
    if(left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

struct Node* getMiddle(struct Node* head) {
    if(head == NULL) {
        return head;
    }
    struct Node* slow = head;
    struct Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node* mergeSort(struct Node* head_ref) {
    if(head_ref == NULL || head_ref->next == NULL) {
        return head_ref;
    }
    struct Node* middle = getMiddle(head_ref);
    struct Node* next_middle = middle->next;
    middle->next = NULL;
    struct Node* left = mergeSort(head_ref);
    struct Node* right = mergeSort(next_middle);
    struct Node* sorted_list = merge(left, right);
    return sorted_list;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while(node) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 5);
    push(&head, 9);
    push(&head, 2);
    push(&head, 1);
    push(&head, 7);
    push(&head, 6);
    push(&head, 3);
    push(&head, 8);
    push(&head, 10);
    push(&head, 4);

    printf("Original list: ");
    printList(head);

    head = mergeSort(head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}
