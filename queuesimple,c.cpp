#include <stdio.h>
#include <stdlib.h>

// --- Queue Setup ------------------------------------------
#define SIZE 5

int arr[SIZE];
int front = -1, rear = -1;

// --- Function Declarations --------------------------------
void insertion(int val);
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
void insertion(int val) {
    if (rear == SIZE - 1) {                // queue full check
        printf("Queue Overflow! Queue is full.\n");
        return;
    }

    if (front == -1)                       // first element
        front = 0;

    arr[++rear] = val;                     // increment rear, insert
    printf("Inserted: %d\n", val);
}

// --- Deletion (Dequeue) -----------------------------------
void deletion() {
    if (front == -1 || front > rear) {     // queue empty check
        printf("Queue Underflow! Queue is empty.\n");
        front = rear = -1;                 // reset
        return;
    }

    printf("Deleted element: %d\n", arr[front]);
    front++;                               // move front forward

    if (front > rear)                      // queue became empty
        front = rear = -1;
}

// --- Display ----------------------------------------------
void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue (Front to Rear): ");
    for (i = front; i <= rear; i++)
        printf("%d  ", arr[i]);
    printf("\n");
    printf("Front = arr[%d] = %d\n", front, arr[front]);
    printf("Rear  = arr[%d] = %d\n", rear,  arr[rear]);
}
