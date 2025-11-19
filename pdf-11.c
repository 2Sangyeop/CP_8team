/* 파일명: pdf-11.c
   문제: pdf11번) 사원 봉급 계산
   작성자: 오태석
   날짜: 2025.11.19
   버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int hobong, spouse, family;
    int base_deduct, bonus;
    int tax_standard;
    int tax = 0;
    int rate = 0, deduct = 0;
    int pay;

    while (1) {
        printf("자료입력후 Enter>");
        scanf("%d", &hobong);

        if (hobong == 0) {
            printf("프로그램을 종료합니다.");
            break;
        }

        scanf("%d %d", &spouse, &family);


        bonus = 800000 + (hobong - 1) * 42000;


        base_deduct = 1000000 + 20000 * spouse + 10000 * family;


        tax_standard = bonus - base_deduct;

        if (tax_standard <= 0) {
            tax = 0;
        }
        else {

            if (tax_standard < 100000) {
                rate = 5; deduct = 0;
            }
            else if (tax_standard < 200000) {
                rate = 10; deduct = 3000;
            }
            else if (tax_standard < 300000) {
                rate = 20; deduct = 13000;
            }
            else {
                rate = 30; deduct = 28000;
            }

            tax = tax_standard * rate / 100 - deduct;
            if (tax < 0) tax = 0;
        }

        pay = bonus - tax;

        printf("분봉 : %d\n", bonus);
        printf("기초 공제액 : %d\n", base_deduct);
        printf("과세표준액 : %d\n", tax_standard);
        printf("세금 : %d\n", tax);
        printf("지급액 : %d\n\n", pay);
    }

    return 0;
}