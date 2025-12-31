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

int main() {
    NODE root = NULL;
    int choice, val;

    while (1) {
        printf("\n--- BST OPERATIONS MENU ---\n");
        printf("1. Insert Node (Construct Tree)\n");
        printf("2. Display Traversals (In/Pre/Post)\n");
        printf("3. Find Minimum Value\n");
        printf("4. Find Maximum Value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insertBST(root, val);
                break;
            case 2:
                printf("\nPre-order:  "); preorder(root);
                printf("\nIn-order:   "); inorder(root);
                printf("\nPost-order: "); postorder(root);
                printf("\n");
                break;
            case 3:
                val = findMin(root);
                if (val != -1) printf("Minimum Value: %d\n", val);
                break;
            case 4:
                val = findMax(root);
                if (val != -1) printf("Maximum Value: %d\n", val);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
