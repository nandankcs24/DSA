#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10


int stack[MAX_SIZE];

int top = -1;


void push(int value);
int pop(); 
void display();

void push(int value) {
    
    if (top == MAX_SIZE - 1) {
        printf("\nStack is Full!!! Insertion is not possible!!!\n");
    } else {
        top++;
        stack[top] = value;
        printf("\nInsertion success!!!\n");
    }
}


int pop() {
    int deleted_value = -9999; 
    if (top == -1) {
        printf("\nStack is Empty!!! Deletion is not possible!!!\n");
        
        return deleted_value; 
    } else {
        deleted_value = stack[top]; 
        printf("\nDeleted: %d\n", deleted_value);
        top--; 
        return deleted_value; 
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is Empty!!!\n");
    } else {
        printf("\nStack elements are (Top to Bottom):\n");
        
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int value, choice;

    
    while (1) {
        printf("\n\n***** MENU *****\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Clearing buffer...\n");
            
            while (getchar() != '\n');
            continue; 
        }

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                
                if (scanf("%d", &value) != 1) {
                    printf("\nInvalid input. Clearing buffer...\n");
                    
                    while (getchar() != '\n');
                    break; 
                }
                push(value);
                break;
            case 2:
                
                pop(); 
                break;
            case 3:
                display();
                break;
            case 4:
                
                printf("\nExiting program.\n");
                exit(0); 
            default:
                printf("\nWrong selection!!! Try again!!!\n");
                break;
        }
    }
    
    
    return 0; 
}