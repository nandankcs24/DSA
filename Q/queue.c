#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* =========================================================
   QUEUE USING ARRAY
   LAB PROGRAM: Insert, Delete, Display
   ========================================================= */

int queue[MAX];
int front = -1, rear = -1;

void insertQ(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int deleteQ() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void displayQ() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

/* =========================================================
   CIRCULAR QUEUE USING ARRAY
   LAB PROGRAM: Insert, Delete, Display
   ========================================================= */

int cqueue[MAX];
int cfront = -1, crear = -1;

void cInsert(int x) {
    if ((crear + 1) % MAX == cfront) {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (cfront == -1)
        cfront = 0;
    crear = (crear + 1) % MAX;
    cqueue[crear] = x;
}

int cDelete() {
    int x;
    if (cfront == -1) {
        printf("Circular Queue Underflow\n");
        return -1;
    }
    x = cqueue[cfront];
    if (cfront == crear)
        cfront = crear = -1;
    else
        cfront = (cfront + 1) % MAX;
    return x;
}

void cDisplay() {
    if (cfront == -1) {
        printf("Circular Queue Empty\n");
        return;
    }
    int i = cfront;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == crear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

/* =========================================================
   PRIORITY QUEUE USING ARRAY
   SAMPLE PROGRAM (Question 10)
   Higher value = higher priority
   ========================================================= */

int pqueue[MAX];
int pcount = 0;

void pqInsert(int x) {
    int i;
    if (pcount == MAX) {
        printf("Priority Queue Overflow\n");
        return;
    }

    for (i = pcount - 1; i >= 0 && pqueue[i] < x; i--)
        pqueue[i + 1] = pqueue[i];

    pqueue[i + 1] = x;
    pcount++;
}

int pqDelete() {
    if (pcount == 0) {
        printf("Priority Queue Underflow\n");
        return -1;
    }
    return pqueue[--pcount];
}

void pqDisplay() {
    if (pcount == 0) {
        printf("Priority Queue Empty\n");
        return;
    }
    for (int i = 0; i < pcount; i++)
        printf("%d ", pqueue[i]);
    printf("\n");
}

/* =========================================================
   DEQUE (DOUBLE ENDED QUEUE) USING ARRAY
   SYLLABUS TOPIC
   ========================================================= */

int deque[MAX];
int dfront = -1, drear = -1;

void insertFront(int x) {
    if (dfront == 0) {
        printf("Deque Overflow\n");
        return;
    }
    if (dfront == -1)
        dfront = drear = 0;
    else
        dfront--;
    deque[dfront] = x;
}

void insertRear(int x) {
    if (drear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }
    if (dfront == -1)
        dfront = drear = 0;
    else
        drear++;
    deque[drear] = x;
}

int deleteFront() {
    if (dfront == -1) {
        printf("Deque Underflow\n");
        return -1;
    }
    int x = deque[dfront];
    if (dfront == drear)
        dfront = drear = -1;
    else
        dfront++;
    return x;
}

int deleteRear() {
    if (dfront == -1) {
        printf("Deque Underflow\n");
        return -1;
    }
    int x = deque[drear];
    if (dfront == drear)
        dfront = drear = -1;
    else
        drear--;
    return x;
}

/* =========================================================
   MAIN FUNCTION (UNCOMMENT AS PER QUESTION)
   ========================================================= */

int main() {

    /* ---------- SIMPLE QUEUE ---------- */
    /*
    insertQ(10);
    insertQ(20);
    insertQ(30);
    displayQ();
    deleteQ();
    displayQ();
    */

    /* ---------- CIRCULAR QUEUE ---------- */
    /*
    cInsert(5);
    cInsert(10);
    cInsert(15);
    cDisplay();
    cDelete();
    cDisplay();
    */

    /* ---------- PRIORITY QUEUE ---------- */
    /*
    pqInsert(30);
    pqInsert(10);
    pqInsert(50);
    pqInsert(20);
    pqDisplay();
    pqDelete();
    pqDisplay();
    */

    /* ---------- DEQUE ---------- */
    /*
    insertRear(10);
    insertRear(20);
    insertFront(5);
    printf("%d\n", deleteRear());
    printf("%d\n", deleteFront());
    */

    return 0;
}
