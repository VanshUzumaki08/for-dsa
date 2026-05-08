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
struct Node *createNode(int n);
void inorder(struct Node *root);
void preorder(struct Node *root);
void postorder(struct Node *root);

// --- Main -------------------------------------------------
int main() {

    // -- Build the Tree ------------------------------------
    root              = createNode(10);
    root->left        = createNode(20);
    root->right       = createNode(30);
    root->left->left  = createNode(40);
    root->left->right = createNode(50);
    root->left->right->left  = createNode(60);
    root->left->right->right = createNode(70);

    /*
              10
             /  \
           20    30
          /  \
        40    50
             /  \
           60    70
    */

    printf("Inorder   (Left, Root, Right): ");
    inorder(root);
    printf("\n");

    printf("Preorder  (Root, Left, Right): ");
    preorder(root);
    printf("\n");

    printf("Postorder (Left, Right, Root): ");
    postorder(root);
    printf("\n");

    return 0;
}

// --- Create Node ------------------------------------------
struct Node *createNode(int n) {
    struct Node *nl;

    nl = (struct Node *) malloc(sizeof(struct Node));

    if (nl == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    nl->left  = NULL;
    nl->right = NULL;
    nl->data  = n;

    return nl;
}

// --- Inorder Traversal (Left ? Root ? Right) -------------
void inorder(struct Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);           // visit left subtree
    printf("%d ", root->data);     // visit root
    inorder(root->right);          // visit right subtree
}

// --- Preorder Traversal (Root ? Left ? Right) ------------
void preorder(struct Node *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);     // visit root
    preorder(root->left);          // visit left subtree
    preorder(root->right);         // visit right subtree
}

// --- Postorder Traversal (Left ? Right ? Root) -----------
void postorder(struct Node *root) {
    if (root == NULL)
        return;

    postorder(root->left);         // visit left subtree
    postorder(root->right);        // visit right subtree
    printf("%d ", root->data);     // visit root
}
