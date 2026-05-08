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
void insertion(int n);              // insert at rear only
void insertionAtFront(int n);       // insert at front
void insertionAtRear(int n);        // insert at rear
void deletionAtFront();             // delete from front
void deletionAtRear();              // delete from rear
void display();

void inputRestrictedQueue();        // insertion at rear only
void outputRestrictedQueue();       // deletion from front only

// --- Main -------------------------------------------------
int main() {
    int choice;

    while (1) {
        printf("\n========= DEQUE MAIN MENU =========");
        printf("\n1. Input Restricted Deque");
        printf("\n2. Output Restricted Deque");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: inputRestrictedQueue();  break;
            case 2: outputRestrictedQueue(); break;
            case 3: display();               break;
            case 4: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

// --- Input Restricted Deque Menu --------------------------
// Insertion only at REAR, Deletion from BOTH ends
void inputRestrictedQueue() {
    int choice, val;

    printf("\n--- Input Restricted Deque ---");
    printf("\n1. Insertion (Rear only)");
    printf("\n2. Deletion from Front");
    printf("\n3. Deletion from Rear");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &val);
            insertion(val);
            break;
        case 2: deletionAtFront(); break;
        case 3: deletionAtRear();  break;
        default: printf("Invalid choice!\n");
    }
}

// --- Output Restricted Deque Menu -------------------------
// Insertion from BOTH ends, Deletion only at FRONT
void outputRestrictedQueue() {
    int choice, val;

    printf("\n--- Output Restricted Deque ---");
    printf("\n1. Insertion at Front");
    printf("\n2. Insertion at Rear");
    printf("\n3. Deletion (Front only)");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &val);
            insertionAtFront(val);
            break;
        case 2:
            printf("Enter element: ");
            scanf("%d", &val);
            insertionAtRear(val);
            break;
        case 3: deletionAtFront(); break;
        default: printf("Invalid choice!\n");
    }
}

// --- Insertion at Rear (default) --------------------------
void insertion(int n) {
    struct Node *nl;

    nl = (struct Node *) malloc(sizeof(struct Node));
    if (nl == NULL) { printf("Memory error!\n"); return; }

    nl->data = n;
    nl->next = NULL;

    if (front == NULL) {
        front = rear = nl;
    } else {
        rear->next = nl;
        rear = nl;
    }

    printf("Inserted at Rear: %d\n", n);
}

// --- Insertion at Front -----------------------------------
void insertionAtFront(int n) {
    struct Node *nl;

    nl = (struct Node *) malloc(sizeof(struct Node));
    if (nl == NULL) { printf("Memory error!\n"); return; }

    nl->data = n;
    nl->next = NULL;

    if (front == NULL) {
        front = rear = nl;
    } else {
        nl->next = front;          // new node points to old front
        front = nl;                // update front
    }

    printf("Inserted at Front: %d\n", n);
}

// --- Insertion at Rear ------------------------------------
void insertionAtRear(int n) {
    insertion(n);                  // same as default insertion
}

// --- Deletion at Front ------------------------------------
void deletionAtFront() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty! Underflow.\n");
        return;
    }

    printf("Deleted from Front: %d\n", front->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;               // queue became empty

    free(temp);
}

// --- Deletion at Rear -------------------------------------
void deletionAtRear() {
    struct Node *temp = front, *prev = NULL;

    if (front == NULL) {
        printf("Queue is empty! Underflow.\n");
        return;
    }

    if (front == rear) {           // only one node
        printf("Deleted from Rear: %d\n", front->data);
        free(front);
        front = rear = NULL;
        return;
    }

    // Traverse to second last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted from Rear: %d\n", temp->data);
    prev->next = NULL;             // second last becomes last
    rear = prev;                   // update rear
    free(temp);
}

// --- Display ----------------------------------------------
void display() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Deque (Front to Rear): ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
    printf("Front = %d\n", front->data);
    printf("Rear  = %d\n", rear->data);
}
