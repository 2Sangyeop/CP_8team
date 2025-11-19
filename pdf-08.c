/* 파일명: pdf-08.c
   문제: pdf8번) 비만도의 측정과 판정
   작성자: 오태석
   날짜: 2025.11.19
   버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

char* calc_bmi(float bmi_raw);

int main()
{
    float height = 0.0, weight = 0.0;
    float standard = 0.0, bmi = 0.0, fat = 0.0;
    char* bmi_result = NULL;
    char* fat_result = NULL;

    printf("신장(cm)을 입력하고 Enter>: ");
    scanf("%f", &height);

    printf("체중(kg)을 입력하고 Enter>: ");
    scanf("%f", &weight);

    printf("\n판정 결과\n\n");

    standard = (height - 100) * 0.9f;

    float bmi_raw = weight / ((height / 100.0f) * (height / 100.0f));
    bmi = floor(bmi_raw * 10) / 10;  

    bmi_result = calc_bmi(bmi);

    fat = ((weight - standard) / standard) * 100;
    fat = floor(fat * 10) / 10;

    if (fat <= 10)
        fat_result = "정상 체중";
    else if (fat <= 19)
        fat_result = "과체중";
    else
        fat_result = "비만";

  

    printf("표준체중(kg) : %.1f\n", standard);
    printf("신체질량지수 : %.1f\n", bmi);
    printf("지수에 대한 비만 판정 : %s\n", bmi_result);
    printf("비만도(%%) : %.1f\n", fat);
    printf("비만도에 대한 판정 : %s\n", fat_result);

    return 0;
}

char* calc_bmi(float bmi_raw)
{
    if (bmi_raw < 20)
        return "저체중";
    else if (bmi_raw <= 24)
        return "정상 체중";
    else if (bmi_raw <= 30)
        return "과체중";
    else
        return "병적 비만";
}