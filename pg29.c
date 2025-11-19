// 8팀 - program29.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 선언
void input_date(int* year, int* month, int* day);
int is_leap_year(int year);
int get_day_of_week(int year, int month, int day);
void print_weekday(int day_of_week);

int main() {
    int year, month, day;

    // 입력 함수 호출
    input_date(&year, &month, &day);

    // 요일 계산 함수 호출
    int day_of_week = get_day_of_week(year, month, day);

    // 출력 함수 호출
    print_weekday(day_of_week);

    return 0;
}

void input_date(int* year, int* month, int* day) {
    printf("특정일의 요일을 구하는 프로그램 \n\n");
    printf("년도와 월 일을 입력합니다.\n");
    printf("입력될 숫자는 space bar로 분리합니다.\n");
    printf("예: 2005 5 1\n");
    printf("년월일 입력: ");
    scanf("%d %d %d", year, month, day);
}

int is_leap_year(int year) {
    if ((year % 400) == 0)
        return 1;
    else if ((year % 100) == 0)
        return 0;
    else if ((year % 4) == 0)
        return 1;
    else
        return 0;
}

int get_day_of_week(int year, int month, int day) {
    int total_days = 0;

    for (int y = 1; y < year; y++) {
        total_days += is_leap_year(y) ? 366 : 365;
    }

    int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    for (int m = 1; m < month; m++) {
        if (m == 2 && is_leap_year(year))
            total_days += 29;
        else
            total_days += days_in_month[m - 1];
    }

    total_days += day;

    int day_of_week = total_days % 7;

    return day_of_week;
}

void print_weekday(int day_of_week) {
    const char* weekdays[] = { "일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일" };
    printf("%s입니다.\n", weekdays[day_of_week]);
}

