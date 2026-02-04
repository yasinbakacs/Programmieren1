#include <stdio.h>
#include <math.h>

void add(float a, float b, char op);
void subtract(float a, float b, char op);
void multiply(float a, float b, char op);
void divide(float a, float b, char op);


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
        add(a, b, op);
        break;
    case '-':
        subtract(a, b, op);
        break;
    case '*':
        multiply(a, b, op);
        break;
    case '/':
        divide(a, b, op);
        break;
    default:
        printf("Ungueltiger Operator");
        break;
    }

}
void add(float a, float b, char op){
    printf("%.2f %c %.2f = %.2f", a, op, b, a + b);
}
void subtract(float a, float b, char op){
    printf("%.2f %c %.2f = %.2f", a, op, b, a - b);
}
void multiply(float a, float b, char op){
    printf("%.2f %c %.2f = %.2f", a, op, b, a * b);
}
void divide(float a, float b, char op){
    if(b == 0){
        printf("Fehler: Division durch Null");
        return;
    }
    printf("%.2f %c %.2f = %.2f", a, op, b, a / b);
}
