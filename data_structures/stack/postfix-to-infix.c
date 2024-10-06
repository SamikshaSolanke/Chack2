#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void postfixToInfix(char postfix[], char infix[]) {
    char stack[MAX_SIZE];
    int top = -1;
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (!isOperator(postfix[i])) {
            top++;
            stack[top] = postfix[i];
        }
        else {
            char operand2 = stack[top];
            top--;
            char operand1 = stack[top];
            top--;
            
            infix[++top] = operand1;
            infix[++top] = postfix[i];
            infix[++top] = operand2;
        }
    }
}

int main() {
    char postfix[MAX_SIZE];
    char infix[MAX_SIZE];

    //Enter a postfix expression to test
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    
    postfixToInfix(postfix, infix);
    
    printf("Infix expression: %s\n", infix);
    return 0;
}
