#include <stdio.h>
#include <stdlib.h>

// --- Node Structure ---------------------------------------
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;           // top of stack (acts as head)

// --- Function Declarations --------------------------------
void push();
void pop();
void display();

// --- Main -------------------------------------------------
int main() {
    int choice;

    while (1) {
        printf("\n======= STACK MENU =======");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push();    break;
            case 2: pop();     break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

// --- Push -------------------------------------------------
void push() {
    struct Node *nl;

    nl = (struct Node *) malloc(sizeof(struct Node));

    if (nl == NULL) {
        printf("Heap Overflow! Cannot allocate memory.\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &nl->data);

    nl->next = NULL;

    if (top == NULL) {             // stack is empty
        top = nl;
        return;
    }

    nl->next = top;                // new node points to old top
    top = nl;                      // update top to new node
}

// --- Pop --------------------------------------------------
void pop() {
    struct Node *temp = top;

    if (top == NULL) {             // stack empty check
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    printf("Popped element: %d\n", top->data);
    top = top->next;               // move top to next node
    free(temp);                    // free old top
}

// --- Display ----------------------------------------------
void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack (Top to Bottom):\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
