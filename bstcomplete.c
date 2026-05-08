#include <stdio.h>
#include <stdlib.h>

// --- Node Structure ---------------------------------------
struct Node {
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *root = NULL;

// --- Function Declarations --------------------------------
struct Node *createNode();
void insertNode();
void inorder(struct Node *x);
void preorder(struct Node *x);
void postorder(struct Node *x);
void search();
void deleteNode(struct Node *x, struct Node *p, int n, int isLeft);
void deleteNodeWithTwoChild(struct Node *x);

// --- Main -------------------------------------------------
int main() {
    int choice;

    while (1) {
        printf("\n========= BST MENU =========");
        printf("\n1. Insert Node");
        printf("\n2. Pre-order Traversal");
        printf("\n3. In-order Traversal");
        printf("\n4. Post-order Traversal");
        printf("\n5. Delete Node");
        printf("\n6. Search");
        printf("\n7. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertNode();       break;
            case 2: printf("Pre-order:  "); preorder(root);  printf("\n"); break;
            case 3: printf("In-order:   "); inorder(root);   printf("\n"); break;
            case 4: printf("Post-order: "); postorder(root); printf("\n"); break;
            case 5: deleteNode(root, NULL, 0, 0); break;
            case 6: search();           break;
            case 7: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

// --- Create Node ------------------------------------------
struct Node *createNode() {
    struct Node *nl;

    nl = (struct Node *) malloc(sizeof(struct Node));

    if (nl == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    nl->left  = NULL;
    nl->right = NULL;

    printf("Enter element: ");
    scanf("%d", &nl->data);

    return nl;
}

// --- Insert Node ------------------------------------------
void insertNode() {
    struct Node *temp = root, *nl, *n2;

    if (root == NULL) {
        root = createNode();       // first node becomes root
        return;
    }

    nl = createNode();             // create new node

    // Find correct position
    while (temp != NULL) {
        n2 = temp;
        if (nl->data < temp->data)
            temp = temp->left;     // go left if smaller
        else
            temp = temp->right;    // go right if larger
    }

    // Attach new node
    if (nl->data < n2->data)
        n2->left  = nl;
    else
        n2->right = nl;
}

// --- Inorder Traversal (Left ? Root ? Right) -------------
void inorder(struct Node *x) {
    if (x == NULL)
        return;

    inorder(x->left);
    printf("%d ", x->data);
    inorder(x->right);
}

// --- Preorder Traversal (Root ? Left ? Right) ------------
void preorder(struct Node *x) {
    if (x == NULL)
        return;

    printf("%d ", x->data);
    preorder(x->left);
    preorder(x->right);
}

// --- Postorder Traversal (Left ? Right ? Root) -----------
void postorder(struct Node *x) {
    if (x == NULL)
        return;

    postorder(x->left);
    postorder(x->right);
    printf("%d ", x->data);
}

// --- Search -----------------------------------------------
void search() {
    struct Node *temp = root;
    int n;

    printf("Enter element to search: ");
    scanf("%d", &n);

    while (temp != NULL) {
        if (n == temp->data) {
            printf("Element %d FOUND in BST!\n", n);
            return;
        } else if (n < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    printf("Element %d NOT found in BST.\n", n);
}

// --- Delete Node With Two Children ------------------------
void deleteNodeWithTwoChild(struct Node *x) {
    struct Node *parent = x;
    struct Node *temp   = x->right;   // find inorder successor

    // Go to leftmost node of right subtree
    while (temp->left != NULL) {
        parent = temp;
        temp   = temp->left;
    }

    x->data = temp->data;             // copy successor data to x

    // Delete the successor node
    if (x == parent)
        parent->right = temp->right;
    else
        parent->left  = temp->right;

    free(temp);
}

// --- Delete Node ------------------------------------------
void deleteNode(struct Node *x, struct Node *p, int n, int isLeft) {
    int val;

    // Get value to delete only on first call
    if (p == NULL && x == root) {
        printf("Enter element to delete: ");
        scanf("%d", &val);
        n = val;
    }

    if (x == NULL) {
        printf("Element %d not found!\n", n);
        return;
    }

    // Traverse to find node
    if (n < x->data)
        deleteNode(x->left,  x, n, 1);   // go left
    else if (n > x->data)
        deleteNode(x->right, x, n, 0);   // go right
    else {
        // -- Case 1: Leaf node (no children) ---------------
        if (x->left == NULL && x->right == NULL) {
            if (p == NULL)
                root = NULL;
            else if (isLeft)
                p->left  = NULL;
            else
                p->right = NULL;
            free(x);
            printf("Element deleted successfully.\n");
        }
        // -- Case 2: One child -----------------------------
        else if (x->left == NULL || x->right == NULL) {
            struct Node *child;

            if (x->left != NULL)
                child = x->left;
            else
                child = x->right;

            if (p == NULL)
                root = child;
            else if (isLeft)
                p->left  = child;
            else
                p->right = child;

            free(x);
            printf("Element deleted successfully.\n");
        }
        // -- Case 3: Two children --------------------------
        else {
            deleteNodeWithTwoChild(x);
            printf("Element deleted successfully.\n");
        }
    }
}
