
// 8팀 - Program16.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846 

// 함수 선언
void input_values(double* A, double* B, double* c);
double line_length(double A, double B, double c);
void print_result(double a);

// 메인 함수
int main() {
    double A, B, c;
    double a;

    // 입력 함수 호출
    input_values(&A, &B, &c);

    // 계산 함수 호출
    a = line_length(A, B, c);

    // 출력 함수 호출
    print_result(a);

    return 0;
}

// 입력 담당 함수
void input_values(double* A, double* B, double* c) {
    printf("a의 각도를 입력하고 Enter>");
    scanf("%lf", A);

    printf("b의 각도를 입력하고 Enter>");
    scanf("%lf", B);

    printf("선분 ab의 길이를 입력하고 Enter>");
    scanf("%lf", c);
}

// 계산 담당 함수 (사인 법칙 사용)
double line_length(double A, double B, double c) {
    double radA = A * PI / 180.0;
    double radC = (180.0 - (A + B)) * PI / 180.0;

    double a = (sin(radA) / sin(radC)) * c;

    return a;
}

// 출력 담당 함수
void print_result(double a) {
    printf("선분 a(BC)의 길이 = %f\n", a);
}




