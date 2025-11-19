// 8팀 - program30.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>  // Windows 전용, getch() 사용

// 함수 선언
void input_num(char num[14]);
void parse_num(const char num[14], int* year, int* month, int* day, char* gender);
const char* get_zodiac(int year);
int calculate_age(int year, int month, int day);
void print_result(int year, int month, int day, char gender, const char* zodiac, int age);

int main() {
    char num[14];
    int year, month, day, age;
    char gender;
    const char* zodiac;

    // 1. 주민등록번호 입력
    input_num(num);
    // 2. 생년월일 및 성별 계산
    parse_num(num, &year, &month, &day, &gender);
    // 3. 띠 계산
    zodiac = get_zodiac(year);
    // 4. 만 나이 계산
    age = calculate_age(year, month, day);
    // 5. 출력
    print_result(year, month, day, gender, zodiac, age);

    return 0;
}

// 주민등록번호 입력 함수
void input_num(char num[14]) {
    int i;
    char ch;

    printf("주민등록번호 13자리를 '-' 없이 입력하고 Enter\n주민번호> ");

    for (i = 0; i < 13; ) {
        ch = _getch();

        if (ch >= '0' && ch <= '9') {
            num[i] = ch;
            if (i == 5) {
                printf("%c-", ch);  // 6자리 뒤에 -
            }
            else if (i >= 6) {
                printf("*");        // 뒤 7자리 *로 표시
            }
            else {
                printf("%c", ch);   
            }
            i++;
        }
    }
    num[13] = '\0';
    printf("\n");
}

// 생년월일, 성별 판단
void parse_num(const char num[14], int* year, int* month, int* day, char* gender) {
    int yy, mm, dd;
    char g = num[6];

    sscanf(num, "%2d%2d%2d", &yy, &mm, &dd);

    // 성별 판단 및 연도 계산
    if (g == '1' || g == '2') {
        *year = 1900 + yy;
        *gender = (g == '1') ? 'M' : 'F';
    }
    else if (g == '3' || g == '4') {
        *year = 2000 + yy;
        *gender = (g == '3') ? 'M' : 'F';
    }

    *month = mm;
    *day = dd;
}

// 띠 계산 
const char* get_zodiac(int year) {
    const char* zodiacs[] = {
        "쥐", "소", "호랑이", "토끼",
        "용", "뱀", "말", "양",
        "원숭이", "닭", "개", "돼지"
    };
    int index = (year - 1900) % 12;
    if (index < 0) index += 12;
    return zodiacs[index];
}

// 만 나이 계산
int calculate_age(int year, int month, int day) {
    time_t t = time(NULL);
    struct tm today = *localtime(&t);

    int age = today.tm_year + 1900 - year;

    if (today.tm_mon + 1 < month || (today.tm_mon + 1 == month && today.tm_mday < day)) {
        age--;
    }
    return age;
}

// 결과 출력 함수
void print_result(int year, int month, int day, char gender, const char* zodiac, int age) {
    printf("생년 월일: %04d년 %02d월 %02d일\n", year, month, day);
    printf("성별: %s\n", gender == 'M' ? "남자" : "여자");
    printf("띠 계산: %s\n", zodiac);
    printf("만 나이: %d\n", age);
}


