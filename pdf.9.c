#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

#define CITIES 6

const char* city_names[CITIES] = {
    "서울(0)", "수원(1)", "천안(2)", "대전(3)", "대구(4)", "부산(5)"
};

const int toll_fee[CITIES][CITIES] = {
    {0,      1700,    4200,    7500,   15200,  19300},
    {1700,   0,       3400,    6700,   13600,  17800},
    {4200,   3400,    0,       4200,   11000,  15000},
    {7500,   6700,    4200,    0,       7800,  12100},
    {15200,  13600,   11000,   7800,    0,      4500},
    {19300,  17800,   15000,   12100,   4500,   0}
};

void get_city_codes(int* start_code, int* end_code);
int calculate_fee(int start_code, int end_code);
void display_result(int start_code, int end_code, int fee);


int main(void) {
    int start_code;
    int end_code;
    int fee;

    get_city_codes(&start_code, &end_code);

    fee = calculate_fee(start_code, end_code);

    display_result(start_code, end_code, fee);

    return 0;
}


void get_city_codes(int* start_code, int* end_code) {
    printf("고속도로 통행료 계산 program\n");
    printf("각 도시별 번호\n");
    for (int i = 0; i < CITIES; i++) {
        printf("%s ", city_names[i]);
    }
    printf("\n");

    printf("출발지 도시번호 입력하고 Enter>");
    if (scanf("%d", start_code) != 1) {
        printf("입력 오류: 정수만 입력하세요.\n");
        exit(1);
    }

    printf("도착지 도시번호 입력하고 Enter>");
    if (scanf("%d", end_code) != 1) {
        printf("입력 오류: 정수만 입력하세요.\n");
        exit(1);
    }

    if (*start_code < 0 || *start_code >= CITIES || *end_code < 0 || *end_code >= CITIES) {
        printf("오류: 도시 번호는 0에서 %d 사이여야 합니다.\n", CITIES - 1);
        exit(1);
    }
}


int calculate_fee(int start_code, int end_code) {
    if (start_code == end_code) {
        return 0;
    }
    return toll_fee[start_code][end_code];
}


void display_result(int start_code, int end_code, int fee) {
    if (start_code == end_code) {
        printf("%s에서 %s까지의 요금: 0 원 (같은 도시)\n",
            city_names[start_code], city_names[end_code]);
    }
    else {
        printf("%s에서 %s까지 요금 : %d 원\n",
            city_names[start_code],
            city_names[end_code],
            fee);
    }
}