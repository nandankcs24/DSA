#include <stdio.h>
#include <stdlib.h>

/* =========================================================
   DOUBLY LINKED LIST NODE DEFINITION
   ========================================================= */

struct dnode {
    int data;
    struct dnode *prev;
    struct dnode *next;
};

typedef struct dnode* DNODE;

/* =========================================================
   CREATE NODE
   ========================================================= */

DNODE createNode(int x) {
    DNODE newNode = (DNODE)malloc(sizeof(struct dnode));
    if (newNode == NULL) {
        printf("Memory not allocated\n");
        return NULL;
    }
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* =========================================================
   INSERT AT LEFT (BEGINNING)
   LAB PROGRAM
   ========================================================= */

DNODE insertLeft(DNODE head, int x) {
    DNODE temp = createNode(x);
    if (head == NULL)
        return temp;

    temp->next = head;
    head->prev = temp;
    return temp;
}

/* =========================================================
   INSERT AT RIGHT (END)
   LAB PROGRAM
   ========================================================= */

DNODE insertRight(DNODE head, int x) {
    DNODE temp = createNode(x);
    if (head == NULL)
        return temp;

    DNODE cur = head;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;
    temp->prev = cur;
    return head;
}

/* =========================================================
   DELETE NODE BY VALUE
   LAB / SAMPLE PROGRAM
   ========================================================= */

DNODE deleteByValue(DNODE head, int key) {
    if (head == NULL) {
        printf("List Empty\n");
        return NULL;
    }

    DNODE cur = head;

    while (cur != NULL && cur->data != key)
        cur = cur->next;

    if (cur == NULL) {
        printf("Element not found\n");
        return head;
    }

    if (cur->prev != NULL)
        cur->prev->next = cur->next;
    else
        head = cur->next;

    if (cur->next != NULL)
        cur->next->prev = cur->prev;

    free(cur);
    return head;
}

/* =========================================================
   DISPLAY FORWARD
   ========================================================= */

void displayForward(DNODE head) {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    DNODE cur = head;
    while (cur != NULL) {
        printf("%d <-> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

/* =========================================================
   DISPLAY BACKWARD
   ========================================================= */

void displayBackward(DNODE head) {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    DNODE cur = head;
    while (cur->next != NULL)
        cur = cur->next;

    while (cur != NULL) {
        printf("%d <-> ", cur->data);
        cur = cur->prev;
    }
    printf("NULL\n");
}

/* =========================================================
   MAIN FUNCTION (UNCOMMENT AS PER QUESTION)
   ========================================================= */

int main() {

    DNODE head = NULL;

    /* ---------- INSERT LEFT ---------- */
    /*
    head = insertLeft(head, 10);
    head = insertLeft(head, 20);
    displayForward(head);
    */

    /* ---------- INSERT RIGHT ---------- */
    /*
    head = insertRight(head, 30);
    head = insertRight(head, 40);
    displayForward(head);
    */

    /* ---------- DELETE BY VALUE ---------- */
    /*
    head = deleteByValue(head, 20);
    displayForward(head);
    */

    /* ---------- DISPLAY BACKWARD ---------- */
    /*
    displayBackward(head);
    */

    return 0;
}

