#include <stdio.h>
#include <ctype.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char x) {
    if (top == SIZE - 1) { printf("Overflow\n"); return; }
    stack[++top] = x;
}

char pop() {
    if (top == -1) { printf("Underflow\n"); return -1; }
    return stack[top--];
}

int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')') {
            while (stack[top] != '(') postfix[j++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
        i++;
    }
    while (top != -1) postfix[j++] = pop();
    postfix[j] = '\0';
}

int evalPostfix(char exp[]) {
    int stack[SIZE], top = -1;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i]))
            stack[++top] = exp[i] - '0';
        else {
            int b = stack[top--];
            int a = stack[top--];
            switch (exp[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }
    return stack[top];
}

int main() {
    char infix[SIZE], postfix[SIZE];
    printf("Enter infix: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Evaluation: %d\n", evalPostfix(postfix));
    return 0;
}