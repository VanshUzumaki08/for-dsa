#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int arr[SIZE];
int top = -1;

// --- Function Declarations --------------------------------
void push();
void pop();
void peek();
void display();

// --- Main -------------------------------------------------
int main() {
    int choice;

    while (1) {
        printf("\n======= STACK MENU =======");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push();    break;
            case 2: pop();     break;
            case 3: peek();    break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

// --- Push -------------------------------------------------
void push() {
    if (top == SIZE - 1) {              // Stack full check
        printf("Stack Overflow!\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &arr[++top]);           // increment top, then insert
    printf("Element pushed successfully.\n");
}

// --- Pop --------------------------------------------------
void pop() {
    if (top == -1) {                    // Stack empty check
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped element: %d\n", arr[top--]); // print then decrement
}

// --- Peek (Top Element) -----------------------------------
void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", arr[top]);
}

// --- Display ----------------------------------------------
void display() {
	int i;
	
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    for (i = top; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");
}
