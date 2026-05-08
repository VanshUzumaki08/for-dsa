#include <stdio.h>
#include <stdlib.h>

// --- Node Structure ---------------------------------------
struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear  = NULL;

// --- Function Declarations --------------------------------
void enqueue(int n);
void dequeue();
void display();

// --- Main -------------------------------------------------
int main() {
    int choice, val;

    while (1) {
        printf("\n====== CIRCULAR QUEUE MENU ======");
        printf("\n1. Enqueue (Insert)");
        printf("\n2. Dequeue (Delete)");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

// --- Enqueue (Insert) -------------------------------------
void enqueue(int n) {
    struct Node *nl;

    nl = (struct Node *) malloc(sizeof(struct Node));

    if (nl == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    nl->data = n;
    nl->next = NULL;

    if (front == NULL) {           // queue is empty
        front      = nl;
        rear       = nl;
        rear->next = front;        // circular: rear points back to front
    } else {
        nl->next   = rear->next;   // new node points to front
        rear->next = nl;           // old rear points to new node
        rear       = nl;           // update rear to new node
    }

    printf("Enqueued: %d\n", n);
}

// --- Dequeue (Delete) -------------------------------------
void dequeue() {
    struct Node *temp = front;

    if (front == NULL) {           // queue empty check
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("Dequeued element: %d\n", front->data);

    if (temp == rear) {            // only one node left
        free(temp);
        front = NULL;
        rear  = NULL;
    } else {
        front      = front->next;  // move front forward
        rear->next = front;        // maintain circular link
        free(temp);
    }
}

// --- Display ----------------------------------------------
void display() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Circular Queue (Front to Rear): ");
    do {
        printf("%d", temp->data);
        if (temp->next != front)
            printf(" -> ");
        temp = temp->next;
    } while (temp != front);

    printf(" -> (back to front: %d)\n", front->data);
    printf("Front = %d\n", front->data);
    printf("Rear  = %d\n", rear->data);
}
