#include <stdio.h>
#include <stdlib.h>

// --- Node Structure ---------------------------------------
struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// --- Function Declarations --------------------------------
void append();
void display();
void insertAtPosBefore();
void insertAtPosAfter();
void deleteAtPosBefore();
void deleteAtPosAfter();

// --- Main -------------------------------------------------
int main() {
    int choice;
    do {
        printf("\n===== DOUBLY LINKED LIST MENU =====");
        printf("\n1. Append");
        printf("\n2. Display");
        printf("\n3. Insert Before Position");
        printf("\n4. Insert After Position");
        printf("\n5. Delete Before Position");
        printf("\n6. Delete After Position");
        printf("\n7. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: append();             break;
            case 2: display();            break;
            case 3: insertAtPosBefore();  break;
            case 4: insertAtPosAfter();   break;
            case 5: deleteAtPosBefore();  break;
            case 6: deleteAtPosAfter();   break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}

// --- 1. Append --------------------------------------------
void append() {
    struct Node *nl, *temp = head;

    nl = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter element: ");
    scanf("%d", &nl->data);

    nl->next = NULL;
    nl->prev = NULL;

    if (head == NULL) {
        head = nl;
    } else {
        while (temp->next != NULL)
            temp = temp->next;

        nl->prev = temp;
        temp->next = nl;
    }
}

// --- 2. Display -------------------------------------------
void display() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// --- 3. Insert Before Position ----------------------------
void insertAtPosBefore() {
    struct Node *nl, *temp = head, *n2;
    int pos, i, found = 0;

    printf("Enter position: ");
    scanf("%d", &pos);

    nl = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter element: ");
    scanf("%d", &nl->data);
    nl->next = NULL;
    nl->prev = NULL;

    if (pos == 1) {
        nl->next = head;
        if (head != NULL)
            head->prev = nl;
        head = nl;
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        free(nl);
        return;
    }

    n2 = temp->next;
    nl->next = n2;
    nl->prev = temp;
    temp->next = nl;
    if (n2 != NULL)
        n2->prev = nl;
}

// --- 4. Insert After Position -----------------------------
void insertAtPosAfter() {
    struct Node *nl, *temp = head, *n2;
    int pos, i, found = 0;

    printf("Enter position: ");
    scanf("%d", &pos);

    nl = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter element: ");
    scanf("%d", &nl->data);
    nl->next = NULL;
    nl->prev = NULL;

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(nl);
        return;
    }

    n2 = temp->next;
    nl->next = n2;
    nl->prev = temp;
    temp->next = nl;
    if (n2 != NULL)
        n2->prev = nl;
}

// --- 5. Delete Before Position ----------------------------
void deleteAtPosBefore() {
    struct Node *temp = head, *n2, *n3;
    int pos, i, found = 0;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 1) {
        printf("No node before position %d!\n", pos);
        return;
    }

    if (pos == 2) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    for (i = 1; i < pos - 2 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    n2 = temp->next;   // node to delete
    n3 = n2->next;
    temp->next = n3;
    if (n3 != NULL)
        n3->prev = temp;
    free(n2);
}

// --- 6. Delete After Position -----------------------------
void deleteAtPosAfter() {
    struct Node *temp = head, *n2, *n3;
    int pos, i, found = 0;

    printf("Enter position: ");
    scanf("%d", &pos);

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    n2 = temp->next;   // node to delete
    n3 = n2->next;
    temp->next = n3;
    if (n3 != NULL)
        n3->prev = temp;
    free(n2);
}
