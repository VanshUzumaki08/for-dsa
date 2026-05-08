#include <stdio.h>
#include <stdlib.h>

// --- Node Structure ---------------------------------------
struct Node {
    int data;
    int priority;
    struct Node *next;
};

struct Node *front = NULL;

// --- Function Declarations --------------------------------
void insertion(int n, int priority);
void deletion();
void display();

// --- Main -------------------------------------------------
int main() {
    int choice, val, pri;

    while (1) {
        printf("\n====== PRIORITY QUEUE MENU ======");
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                printf("Enter priority: ");
                scanf("%d", &pri);
                insertion(val, pri);
                break;
            case 2: deletion(); break;
            case 3: display();  break;
            case 4: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

// --- Insertion --------------------------------------------
void insertion(int n, int priority) {
    struct Node *nl, *temp = front;

    nl = (struct Node *) malloc(sizeof(struct Node));

    if (nl == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    nl->data     = n;
    nl->priority = priority;
    nl->next     = NULL;

    // Queue empty OR new node has highest priority
    if (front == NULL || priority < front->priority) {
        nl->next = front;
        front    = nl;
    } else {
        // Find correct position based on priority
        while (temp->next != NULL && temp->next->priority <= priority)
            temp = temp->next;

        nl->next   = temp->next;
        temp->next = nl;
    }

    printf("Inserted: %d (Priority: %d)\n", n, priority);
}

// --- Deletion ---------------------------------------------
void deletion() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty! Underflow.\n");
        return;
    }

    printf("Deleted element: %d (Priority: %d)\n",
            front->data, front->priority);

    front = front->next;           // move front forward
    free(temp);                    // free deleted node
}

// --- Display ----------------------------------------------
void display() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("\n%-10s %-10s\n", "Data", "Priority");
    printf("---------------------\n");
    while (temp != NULL) {
        printf("%-10d %-10d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}
