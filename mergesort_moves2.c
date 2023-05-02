#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int value;
    struct node* next;
} node;

void push(node** stack, int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

int pop(node** stack) {
    int value = (*stack)->value;
    node* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return value;
}

void swap(node** stack1, node** stack2) {
    int temp = pop(stack1);
    push(stack1, pop(stack1));
    push(stack1, temp);
    printf("swap A\n");
    temp = pop(stack2);
    push(stack2, pop(stack2));
    push(stack2, temp);
    printf("swap B\n");
}

void push_to(node** from_stack, node** to_stack) {
    int value = pop(from_stack);
    push(to_stack, value);
    if (to_stack == &stack_a) {
        printf("push A\n");
    } else {
        printf("push B\n");
    }
}

void rotate(node** stack) {
    int first_value = pop(stack);
    int second_value = pop(stack);
    push(stack, first_value);
    push(stack, second_value);
    printf("rotate A\n");
}

void reverse_rotate(node** stack) {
    node* current = *stack;
    while (current->next != NULL) {
        current = current->next;
    }
    int last_value = current->value;
    while (current != *stack) {
        current->value = current->prev->value;
        current = current->prev;
    }
    (*stack)->value = last_value;
    printf("reverse rotate A\n");
}

void sort(node** stack1, node** stack2, int size) {
    if (size < 2) {
        return;
    }
    int middle = size / 2;
    for (int i = 0; i < middle; i++) {
        push_to(stack1, stack2);
    }
    sort(stack2, stack1, middle);
    sort(stack2, stack1, size - middle);
    while (*stack1 != NULL && *stack2 != NULL) {
        if ((*stack1)->value < (*stack2)->value) {
            push_to(stack1, stack2);
        } else {
            push_to(stack2, stack1);
        }
    }
    while (*stack1 != NULL) {
        push_to(stack2, stack1);
    }
    while (*stack2 != NULL) {
        push_to(stack1, stack2);
    }
}

int main() {
    node* stack_a = NULL;
    node* stack_b = NULL;

    srand(time(NULL));
    int values[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        values[i] = rand() % 1000;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        push(&stack_a, values[i]);
    }

    sort(&stack_a, &stack_b, MAX_SIZE);

    return 0;
}
