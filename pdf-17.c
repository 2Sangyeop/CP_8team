/* 파일명: pdf-17.c
   문제: pdf17번) 사원 봉급 계산
   작성자: 오태석
   날짜: 2025.11.19
   버전: v1.0
*/

#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

int main() {
    int angle;
    double s, c;
    int pos_s, pos_c;

    for (angle = 0; angle <= 360; angle += 15) {

        double rad = angle * PI / 180.0;
        s = sin(rad);
        c = cos(rad);

        pos_s = (int)(s * 25 + 25);
        pos_c = (int)(c * 25 + 25);

        printf("각도 %3d :", angle);

        if (fabs(s - c) <= 0.1) {
            int mid = (pos_s + pos_c) / 2;
            for (int i = 0; i < mid; i++)
                printf(" ");
            printf("*\n");
        }
        else if (pos_s < pos_c) {

            for (int i = 0; i < pos_s; i++)
                printf(" ");
            printf("S");
            for (int i = 0; i < pos_c - pos_s - 1; i++)
                printf(" ");
            printf("C\n");
        }
        else {

            for (int i = 0; i < pos_c; i++)
                printf(" ");
            printf("C");
            for (int i = 0; i < pos_s - pos_c - 1; i++)
                printf(" ");
            printf("S\n");
        }
    }

    return 0;
}