#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

typedef struct node* NODE;

/* =========================================================
   BASIC OPERATIONS (LAB PROGRAM)
   ========================================================= */

NODE createNode(int x) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory not allocated\n");
        return NULL;
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

NODE insertFront(NODE head, int x) {
    NODE temp = createNode(x);
    temp->next = head;
    return temp;
}

NODE insertEnd(NODE head, int x) {
    NODE temp = createNode(x);
    if (head == NULL)
        return temp;

    NODE cur = head;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;
    return head;
}

NODE deleteFront(NODE head) {
    if (head == NULL) {
        printf("List Empty\n");
        return NULL;
    }
    NODE temp = head;
    head = head->next;
    free(temp);
    return head;
}

void display(NODE head) {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }
    NODE cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

/* =========================================================
   INSERT AT SPECIFIC POSITION
   ========================================================= */

NODE insertAtPos(NODE head, int x, int pos) {
    if (pos == 1)
        return insertFront(head, x);

    NODE cur = head;
    for (int i = 1; i < pos - 1 && cur != NULL; i++)
        cur = cur->next;

    if (cur == NULL) {
        printf("Invalid Position\n");
        return head;
    }

    NODE temp = createNode(x);
    temp->next = cur->next;
    cur->next = temp;
    return head;
}

/* =========================================================
   DELETE AT SPECIFIC POSITION
   ========================================================= */

NODE deleteAtPos(NODE head, int pos) {
    if (head == NULL) return NULL;

    if (pos == 1)
        return deleteFront(head);

    NODE cur = head;
    for (int i = 1; i < pos - 1 && cur->next != NULL; i++)
        cur = cur->next;

    if (cur->next == NULL) {
        printf("Invalid Position\n");
        return head;
    }

    NODE temp = cur->next;
    cur->next = temp->next;
    free(temp);
    return head;
}

/* =========================================================
   QUESTION 3:
   Delete items Sugar and Milk from linked list
   (Delete by key)
   ========================================================= */

NODE deleteByKey(NODE head, int key) {
    NODE cur = head, prev = NULL;

    if (cur != NULL && cur->data == key) {
        head = cur->next;
        free(cur);
        return head;
    }

    while (cur != NULL && cur->data != key) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL)
        return head;

    prev->next = cur->next;
    free(cur);
    return head;
}

/* =========================================================
   QUESTION 5:
   Music playlists (A, B, C) played in circular manner
   → Circular Singly Linked List
   ========================================================= */

NODE insertCircular(NODE head, int x) {
    NODE temp = createNode(x);
    if (head == NULL) {
        temp->next = temp;
        return temp;
    }

    NODE cur = head;
    while (cur->next != head)
        cur = cur->next;

    cur->next = temp;
    temp->next = head;
    return head;
}

NODE deleteCircular(NODE head, int key) {
    if (head == NULL) return NULL;

    NODE cur = head, prev = NULL;

    if (head->next == head && head->data == key) {
        free(head);
        return NULL;
    }

    do {
        if (cur->data == key) {
            if (prev != NULL) {
                prev->next = cur->next;
            } else {
                NODE last = head;
                while (last->next != head)
                    last = last->next;
                head = cur->next;
                last->next = head;
            }
            free(cur);
            return head;
        }
        prev = cur;
        cur = cur->next;
    } while (cur != head);

    return head;
}

/* =========================================================
   QUESTION 6:
   Browser navigation – find webpage after X clicks
   ========================================================= */

int pageAfterX(NODE head, int x) {
    NODE cur = head;
    for (int i = 0; i < x && cur != NULL; i++)
        cur = cur->next;

    if (cur == NULL)
        return -1;

    return cur->data;
}

/* =========================================================
   QUESTION 7:
   Polynomial Addition using Linked List
   ========================================================= */

struct poly {
    int coeff;
    int power;
    struct poly *next;
};

typedef struct poly* POLY;

POLY createTerm(int c, int p) {
    POLY t = (POLY)malloc(sizeof(struct poly));
    t->coeff = c;
    t->power = p;
    t->next = NULL;
    return t;
}

POLY addPoly(POLY p1, POLY p2) {
    POLY result = NULL, tail = NULL;

    while (p1 && p2) {
        POLY temp;
        if (p1->power == p2->power) {
            temp = createTerm(p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->power > p2->power) {
            temp = createTerm(p1->coeff, p1->power);
            p1 = p1->next;
        } else {
            temp = createTerm(p2->coeff, p2->power);
            p2 = p2->next;
        }

        if (result == NULL)
            result = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    } 

    while (p1 != NULL) {
        POLY temp = createTerm(p1->coeff, p1->power);
        if (result == NULL) result = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        p1 = p1->next;
    }

    while (p2 != NULL) {
        POLY temp = createTerm(p2->coeff, p2->power);
        if (result == NULL) result = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        p2 = p2->next;
    }

    return result;
}

/* =========================================================
   QUESTION 11:
   Remove duplicates from sorted linked list
   ========================================================= */

NODE removeDuplicates(NODE head) {
    NODE cur = head;

    while (cur != NULL && cur->next != NULL) {
        if (cur->data == cur->next->data) {
            NODE temp = cur->next;
            cur->next = temp->next;
            free(temp);
        } else {
            cur = cur->next;
        }
    }
    return head;
}

/* =========================================================
   MAIN FUNCTION (UNCOMMENT AS PER QUESTION)
   ========================================================= */

int main() {

    NODE head = NULL;

    /* ---------- Q3: DELETE SUGAR & MILK ---------- */
    /*
    head = insertEnd(head, 1); // Sugar
    head = insertEnd(head, 2); // Salt
    head = insertEnd(head, 3); // Milk
    head = deleteByKey(head, 1);
    head = deleteByKey(head, 3);
    display(head);
    */

    /* ---------- Q5: CIRCULAR PLAYLIST ---------- */
    /*
    head = insertCircular(head, 10);
    head = insertCircular(head, 20);
    head = insertCircular(head, 30);
    head = deleteCircular(head, 20);
    */

    /* ---------- Q6: BROWSER CLICKS ---------- */
    /*
    head = insertEnd(head, 101);
    head = insertEnd(head, 102);
    head = insertEnd(head, 103);
    printf("%d\n", pageAfterX(head, 2));
    */

    /* ---------- Q11: REMOVE DUPLICATES ---------- */
    /*
    head = insertEnd(head, 10);
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = removeDuplicates(head);
    display(head);
    */

    return 0;
}

