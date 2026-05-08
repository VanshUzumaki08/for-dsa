#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// --- Append -----------------------------------------------
void append() {
    struct Node *nl, *temp = head;

    nl = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter element: ");
    scanf("%d", &nl->data);

    if (head == NULL) {
        nl->next = nl;
        nl->prev = nl;
        head = nl;
        return;
    }

    struct Node *last = head->prev; // last node (prev of head)
    last->next = nl;
    nl->prev = last;
    nl->next = head;
    head->prev = nl;
}

// --- Display ----------------------------------------------
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head: %d)\n", head->data);
}

// --- Insert at First --------------------------------------
void insertFirst() {
    struct Node *nl;

    nl = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter element: ");
    scanf("%d", &nl->data);

    if (head == NULL) {
        nl->next = nl;
        nl->prev = nl;
        head = nl;
        return;
    }

    struct Node *last = head->prev;
    nl->next = head;
    nl->prev = last;
    last->next = nl;
    head->prev = nl;
    head = nl;                     // update head
}

// --- Insert at Last (same as append) ---------------------
void insertLast() {
    append();
}

// --- Delete First -----------------------------------------
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head) {      // only one node
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    struct Node *last = head->prev;

    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);
}

// --- Delete Last ------------------------------------------
void deleteLast() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head) {      // only one node
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head->prev;
    struct Node *second_last = last->prev;

    second_last->next = head;
    head->prev = second_last;
    free(last);
}

// --- Main -------------------------------------------------
int main() {
    int choice;
    do {
        printf("\n=== Circular Doubly Linked List ===");
        printf("\n1. Append");
        printf("\n2. Display");
        printf("\n3. Insert First");
        printf("\n4. Insert Last");
        printf("\n5. Delete First");
        printf("\n6. Delete Last");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: append();      break;
            case 2: display();     break;
            case 3: insertFirst(); break;
            case 4: insertLast();  break;
            case 5: deleteFirst(); break;
            case 6: deleteLast();  break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}
