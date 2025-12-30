#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

/* =========================================================
   BASIC STACK (ARRAY)
   ========================================================= */

int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top-bottom):\n");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

/* =========================================================
   STACK COMPARISON (EQUAL / NOT EQUAL)
   ========================================================= */

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) { stack1[++top1] = x; }
void push2(int x) { stack2[++top2] = x; }

void compareStacks() {
    if (top1 != top2) {
        printf("NOT EQUAL\n");
        return;
    }
    for (int i = 0; i <= top1; i++) {
        if (stack1[i] != stack2[i]) {
            printf("NOT EQUAL\n");
            return;
        }
    }
    printf("EQUAL\n");
}

/* =========================================================
   MERGE TWO STACKS
   ========================================================= */

int s3[2 * MAX];
int top3 = -1;

void push3(int x) { s3[++top3] = x; }

void mergeStacks() {
    while (top1 != -1 || top2 != -1) {
        if (top1 != -1)
            push3(stack1[top1--]);
        if (top2 != -1)
            push3(stack2[top2--]);
    }
}

/* =========================================================
   SORT STACK (SMALLEST AT BOTTOM)
   ========================================================= */

int temp[MAX];
int ttop = -1;

void pushTemp(int x) { temp[++ttop] = x; }
int popTemp() { return temp[ttop--]; }

void sortStack() {
    int x;
    while (top != -1) {
        x = pop();
        while (ttop != -1 && temp[ttop] > x)
            push(popTemp());
        pushTemp(x);
    }
    while (ttop != -1)
        push(popTemp());
}

/* =========================================================
   INFIX TO POSTFIX
   ========================================================= */

char cstack[MAX];
int ctop = -1;

void cpush(char ch) { cstack[++ctop] = ch; }
char cpop() { return cstack[ctop--]; }

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch))
            postfix[k++] = ch;

        else if (ch == '(')
            cpush(ch);

        else if (ch == ')') {
            while (cstack[ctop] != '(')
                postfix[k++] = cpop();
            cpop();
        }

        else {
            while (ctop != -1 &&
                   precedence(cstack[ctop]) >= precedence(ch))
                postfix[k++] = cpop();
            cpush(ch);
        }
    }

    while (ctop != -1)
        postfix[k++] = cpop();

    postfix[k] = '\0';
}

/* =========================================================
   POSTFIX EVALUATION
   ========================================================= */

int evalStack[MAX];
int etop = -1;

void epush(int x) { evalStack[++etop] = x; }
int epop() { return evalStack[etop--]; }

int evaluatePostfix(char postfix[]) {
    int i = 0;
    char ch;
    int op1, op2;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch))
            epush(ch - '0');
        else {
            op2 = epop();
            op1 = epop();
            switch (ch) {
                case '+': epush(op1 + op2); break;
                case '-': epush(op1 - op2); break;
                case '*': epush(op1 * op2); break;
                case '/': epush(op1 / op2); break;
            }
        }
    }
    return epop();
}

/* =========================================================
   MAIN — UNCOMMENT WHAT YOU NEED IN EXAM
   ========================================================= */

int main() {

    /* ---------- BASIC STACK ---------- */
    /*
    push(5);
    push(10);
    push(3);
    display();
    pop();
    display();
    */

    /* ---------- STACK COMPARISON ---------- */
    /*
    push1(10); push1(4); push1(2);
    push2(10); push2(4); push2(2);
    compareStacks();
    */

    /* ---------- MERGE STACKS ---------- */
    /*
    push1(1); push1(2); push1(3);
    push2(4); push2(5); push2(6);
    mergeStacks();
    for (int i = top3; i >= 0; i--)
        printf("%d ", s3[i]);
    */

    /* ---------- SORT STACK ---------- */
    /*
    push(5); push(66); push(5); push(8); push(7);
    sortStack();
    display();
    */

    /* ---------- INFIX TO POSTFIX ---------- */
    /*
    char infix[MAX], postfix[MAX];
    printf("Enter infix: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    */

    /* ---------- POSTFIX EVALUATION ---------- */
    /*
    char postfix[MAX];
    printf("Enter postfix: ");
    scanf("%s", postfix);
    printf("Result = %d\n", evaluatePostfix(postfix));
    */

    return 0;
}
