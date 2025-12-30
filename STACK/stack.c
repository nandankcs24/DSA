#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

/* =========================================================
   BASIC STACK (ARRAY)
   LAB PROGRAM: Stack Push, Pop, Display
   ========================================================= */

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
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
        printf("Stack Empty\n");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

/* =========================================================
   SAMPLE 1: SMALLEST ELEMENTS AT BOTTOM OF STACK
   ========================================================= */

int temp[MAX];
int ttop = -1;

void sortStack() {
    int x;
    while (top != -1) {
        x = pop();
        while (ttop != -1 && temp[ttop] > x)
            push(temp[ttop--]);
        temp[++ttop] = x;
    }
    while (ttop != -1)
        push(temp[ttop--]);
}

/* =========================================================
   LAB PROGRAM: INFIX TO POSTFIX
   ========================================================= */

char opStack[MAX];
int optop = -1;

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {

        if (isalnum(ch))
            postfix[k++] = ch;

        else if (ch == '(')
            opStack[++optop] = ch;

        else if (ch == ')') {
            while (opStack[optop] != '(')
                postfix[k++] = opStack[optop--];
            optop--;
        }

        else {
            while (optop != -1 &&
                   precedence(opStack[optop]) >= precedence(ch))
                postfix[k++] = opStack[optop--];
            opStack[++optop] = ch;
        }
    }

    while (optop != -1)
        postfix[k++] = opStack[optop--];

    postfix[k] = '\0';
}

/* =========================================================
   LAB PROGRAM: POSTFIX EXPRESSION EVALUATION
   ========================================================= */

int evalStack[MAX];
int etop = -1;

void epush(int x) { evalStack[++etop] = x; }
int epop() { return evalStack[etop--]; }

int evaluatePostfix(char postfix[]) {
    int i = 0, op1, op2;
    char ch;

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
   SAMPLE: BALANCED BRACKETS
   ========================================================= */

int isBalanced(char expr[]) {
    top = -1;
    for (int i = 0; expr[i]; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);
        else {
            if (top == -1) return 0;
            char open = pop();
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '['))
                return 0;
        }
    }
    return top == -1;
}

/* =========================================================
   SAMPLE: TWO STACKS USING ONE ARRAY
   ========================================================= */

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int x) {
    if (top1 + 1 == top2) return;
    arr[++top1] = x;
}

void push2(int x) {
    if (top2 - 1 == top1) return;
    arr[--top2] = x;
}

/* =========================================================
   SAMPLE: EQUAL STACK HEIGHTS
   ========================================================= */

int equalHeight(int s1[], int s2[], int s3[],
                int n1, int n2, int n3) {

    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < n1; i++) sum1 += s1[i];
    for (int i = 0; i < n2; i++) sum2 += s2[i];
    for (int i = 0; i < n3; i++) sum3 += s3[i];

    int i = 0, j = 0, k = 0;

    while (!(sum1 == sum2 && sum2 == sum3)) {
        if (sum1 >= sum2 && sum1 >= sum3)
            sum1 -= s1[i++];
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= s2[j++];
        else
            sum3 -= s3[k++];
    }
    return sum1;
}

/* =========================================================
   MAIN FUNCTION (USE AS PER QUESTION)
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

    /* ---------- SMALLEST ELEMENT AT BOTTOM ---------- */
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
    printf("Result: %d\n", evaluatePostfix(postfix));
    */

    /* ---------- BALANCED BRACKETS ---------- */
    /*
    char expr[MAX];
    scanf("%s", expr);
    if (isBalanced(expr))
        printf("YES\n");
    else
        printf("NO\n");
    */

    /* ---------- TWO STACKS ONE ARRAY ---------- */
    /*
    push1(10);
    push2(20);
    push1(30);
    push2(40);
    */

    /* ---------- EQUAL STACK HEIGHT ---------- */
    /*
    int s1[] = {3,2,1,1,1};
    int s2[] = {4,3,2};
    int s3[] = {1,1,4,1};
    printf("%d\n", equalHeight(s1,s2,s3,5,3,4));
    */

    return 0;
}

