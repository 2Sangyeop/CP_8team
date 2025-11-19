// 8팀 - program23.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 200

void print_prompt();
void start_calc();
void input_expr(char* expr);
int find_operator(const char* expr);
void extract_numbers(const char* expr, int op_pos, double* num1, double* num2, char* op);
double calc(double a, double b, char op);
void print_result(double result, const char* expr);

int main() {
    print_prompt();
    start_calc();

    return 0;
}

void print_prompt() {
    printf("사칙연산 계산기 프로그램\n\n");
    printf("연산식을 공백없이 입력후 Enter\n");
    printf("예: 234.5*34.7Enter\n");
    printf("공백 입력후 Enter하면 종료\n\n");
}

void start_calc() {
    char expr[SIZE];

    while (1) {
        printf("연산식 입력:");
        input_expr(expr);

        if (strlen(expr) == 0)
            return;

        int op_pos = find_operator(expr);

        if (op_pos == -1) {
            printf("올바른 식이 아닙니다.\n");
            continue;
        }

        double num1, num2;
        char op;

        extract_numbers(expr, op_pos, &num1, &num2, &op);

        double result = calc(num1, num2, op);

        printf("\n입력된 연산식 : %s\n", expr);
        printf("연산결과 : %.6f\n\n", result);
    }
}

void input_expr(char* expr) {
    fgets(expr, SIZE, stdin);
    expr[strcspn(expr, "\n")] = '\0';  // 개행 제거
}

int find_operator(const char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
            return i;
    }
    return -1;
}

void extract_numbers(const char* expr, int op_pos, double* num1, double* num2, char* op) {
    char left[SIZE], right[SIZE];
    strncpy(left, expr, op_pos);
    left[op_pos] = '\0';
    strcpy(right, expr + op_pos + 1);
    *num1 = atof(left);
    *num2 = atof(right);
    *op = expr[op_pos];
}

double calc(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b != 0 ? a / b : 0;
    default: return 0;
    }
}
