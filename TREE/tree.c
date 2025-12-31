#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node* NODE;

/* =========================================================
   BASIC OPERATIONS (CREATE & INSERT)
   ========================================================= */

NODE createNode(int x) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NODE insertBST(NODE root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insertBST(root->left, x);
    else if (x > root->data)
        root->right = insertBST(root->right, x);
    
    return root;
}

/* =========================================================
                  TRAVERSALS
   ========================================================= */

void preorder(NODE root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* =========================================================
    MIN & MAX VALUES
   ========================================================= */

int findMin(NODE root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return -1;
    }
    NODE cur = root;
    while (cur->left != NULL) {
        cur = cur->left;
    }
    return cur->data;
}

int findMax(NODE root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return -1;
    }
    NODE cur = root;
    while (cur->right != NULL) {
        cur = cur->right;
    }
    return cur->data;
}

/* =========================================================
   MAIN FUNCTION
   ========================================================= */

int main() {
    NODE root = NULL;

    /* ----------  (BST) ---------- */
    /*
    // Constructing the Tree (Example Input)
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 70);
    root = insertBST(root, 60);
    root = insertBST(root, 80);

    printf("Pre-order Traversal:  ");
    preorder(root);
    printf("\n");

    printf("In-order Traversal:   ");
    inorder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    printf("Minimum Value: %d\n", findMin(root));
    printf("Maximum Value: %d\n", findMax(root));
    */

    return 0;
}