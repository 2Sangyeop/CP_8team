#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

#define DISCOUNT_YEARS 12

const int discount_percent[DISCOUNT_YEARS] = {
    0, 100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50
};

void get_user_input(int* cc, int* yrs);
long calculate_total_tax(int cc, int years);
void display_result(int cc, int years, long total_tax);


int main(void) {
    int displacement_cc;
    int years;
    long total_tax;

    get_user_input(&displacement_cc, &years);

    total_tax = calculate_total_tax(displacement_cc, years);

    display_result(displacement_cc, years, total_tax);

    return 0;
}


void get_user_input(int* cc, int* yrs) {
    printf("승용차 세금 계산 program\n");

    // 1. 배기량 입력 
    printf("승용차의 배기량(cc)을 입력하고 Enter>");
    if (scanf("%d", cc) != 1 || *cc <= 0) {
        printf("오류: 배기량은 0보다 큰 정수여야 합니다.\n");
        exit(1);
    }

    // 2. 경과 연수 입력 
    printf("구입 후 경과년수를 입력하고 Enter>");
    if (scanf("%d", yrs) != 1 || *yrs < 0) {
        printf("오류: 경과 연수는 0 이상의 정수여야 합니다.\n");
        exit(1);
    }
}


long calculate_total_tax(int cc, int years) {
    int tax_rate;
    int year_index;
    int discount_pct;
    double discount_ratio;

    // 세율 결정
    if (cc <= 800) {
        tax_rate = 104;
    }
    else if (cc <= 1000) {
        tax_rate = 130;
    }
    else if (cc <= 1600) {
        tax_rate = 182;
    }
    else if (cc <= 2000) {
        tax_rate = 260;
    }
    else if (cc <= 2500) {
        tax_rate = 286;
    }
    else {
        tax_rate = 286;
    }

    // 할인율 
    if (years < 3) {
        year_index = 1;
    }
    else if (years >= 12) {
        year_index = 11;
    }
    else {
        year_index = years + 1;
    }

    discount_pct = discount_percent[year_index];

    // 세금 적용 비율 계산
    discount_ratio = (double)discount_pct / 100.0;

    // 최종 세금 계산
    return (long)(cc * tax_rate * discount_ratio);
}


void display_result(int cc, int years, long total_tax) {
    printf("\n배기량 : %d cc\n", cc);
    printf("경과 연수 : %d 년\n", years);
    printf("세금 총액 : %ld 원\n", total_tax);
}