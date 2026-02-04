#include <stdio.h>
#include <math.h>

void main(){
    float a, b;
    char op;
    printf("Erste Zahl (float): ");
    scanf("%f", &a);
    //printf("%.2f", a);
    printf("Zweite Zahl (float): ");
    scanf("%f", &b);
    printf("Gewuenschter Operator(+, -, *, /): ");
    scanf(" %c", &op);
    switch (op)
    {
    case '+':
        printf("%.2f %c %.2f = %.2f", a, op, b, a + b);
        break;
    case '-':
        printf("%.2f %c %.2f = %.2f", a, op, b, a - b);
        break;
    case '*':
        printf("%.2f %c %.2f = %.2f", a, op, b, a * b);
        break;
    case '/':
        if(b == 0){
            printf("Fehler: Division durch Null");
            return;
        }
        printf("%.2f %c %.2f = %.2f", a, op, b, a / b);
        break;
    default:
        printf("Ungueltiger Operator");
        break;
    }

}