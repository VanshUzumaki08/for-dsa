#include <stdio.h>
#include <stdlib.h>

// --- Node Structure ---------------------------------------
struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;         // points to first element
struct Node *rear  = NULL;         // points to last element

// --- Function Declarations --------------------------------
void insertion(int n);
void deletion();
void display();

// --- Main -------------------------------------------------
int main() {
    int choice, val;

    while (1) {
        printf("\n======= QUEUE MENU =======");
        printf("\n1. Insertion (Enqueue)");
        printf("\n2. Deletion  (Dequeue)");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                insertion(val);
                break;
            case 2: deletion(); break;
            case 3: display();  break;
            case 4: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

// --- Insertion (Enqueue) ----------------------------------
void insertion(int n) {
    struct Node *nl;

    nl = (struct Node *) malloc(sizeof(struct Node));

    if (nl == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    nl->data = n;
    nl->next = NULL;

    if (front == NULL) {           // queue is empty
        front = nl;
        rear  = nl;
        return;
    }

    rear->next = nl;               // link new node at end
    rear = nl;                     // update rear to new node

    printf("Inserted: %d\n", n);
}

// --- Deletion (Dequeue) -----------------------------------
void deletion() {
    struct Node *temp = front;

    if (front == NULL) {           // queue empty check
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", front->data);
    front = front->next;           // move front to next node
    free(temp);                    // free old front node

    if (front == NULL)             // queue became empty
        rear = NULL;               // reset rear too
}

// --- Display ----------------------------------------------
void display() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue (Front to Rear): ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
    printf("Front = %d\n", front->data);
    printf("Rear  = %d\n", rear->data);
}
