#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#define SIZE 100

int top = -1;
int k = 0; 

char stack[SIZE]; 
char infix[SIZE];
char postfix[SIZE];


char peek();
void push(char element);
char pop();
int precedence(char operand);
int infix_to_postfix();

int main(){
    printf("Infix Expression: ");
   
    if (scanf("%99s", infix) != 1) {
        
        return 1;
    } 

    infix_to_postfix();
    
    
    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
    
    return 0;
}


char peek() {
    if (top == -1) return '\0'; 
    return stack[top]; 
}


char pop() {
    if (top == -1) return '\0'; 
    return stack[top--]; 
}


void push(char element) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = element; 
}

int precedence(char operand) {
    if (operand == '^'){
        return 3;
    }
    if (operand == '*' || operand == '/') {
        return 2;
    }
    if (operand == '+' || operand == '-') {
        return 1;
    }
    return 0; 
}

int infix_to_postfix(){
    for(int i = 0; i < strlen(infix); i++){
        char c = infix[i];

        if(isalnum(c)){
            postfix[k++] = c;
        }
        else if (c == '(' || c == '{' || c == '['){
            push(c);
        }
        else if (c == ')' || c == '}' || c == ']'){
    
            char matching_open = (c == ')') ? '(' : (c == '}') ? '{' : '[';

            while (top != -1 && peek() != matching_open){
                postfix[k++] = pop();
            }
            
            if (top != -1 && peek() == matching_open){
                pop();
            } else {
            
                printf("\nError: Unmatched closing parenthesis/bracket!\n");
                return 0;
            }
        }
        else{
           
            int current_prec = precedence(c);
            char top_op;

            
            while (top != -1) {
                top_op = peek();
                
                if (precedence(top_op) == 0) break;
                
                int top_prec = precedence(top_op);
                
                
                if (top_prec > current_prec || 
                    (top_prec == current_prec && c != '^')) {
                    postfix[k++] = pop();
                } else {
                    break; 
                }
            }
            push(c);
        }
    }

   
    while (top != -1){
        if (peek() == '(' || peek() == '{' || peek() == '[') {
            printf("\nError: Unmatched opening parenthesis/bracket!\n");
            return 0;
        }
        postfix[k++] = pop();
    }
    
    return 1;
}
