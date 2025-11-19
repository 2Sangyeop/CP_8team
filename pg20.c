// 8팀 - program20.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 100

void start_game();
void print_prompt();
void input_word(char* word);
int check_word(const char* prev, const char* next);
void print_reenter();

int main() {
    start_game();   
    return 0;
}

// 전체 게임을 처리하는 함수
void start_game() {
    char prev[SIZE];
    char next[SIZE];

    print_prompt();
    input_word(prev);

    while (1) {
        print_prompt();
        input_word(next);

        // 종료 조건
        if (next[0] == '0')
            return;

		// 끝말잇기 검사
        while (!check_word(prev, next)) {
            print_reenter();    // “다시 입력하세요”
            print_prompt();
            input_word(next);

            if (next[0] == '0')
                return;
        }

        // prev 갱신
        strcpy(prev, next);
    }
}


// "단어를 입력하고 Enter>" 출력
void print_prompt() {
    printf("단어를 입력하고 Enter>");
}

// 단어 입력
void input_word(char* word) {
    scanf("%s", word);
}

// 끝말 검사
int check_word(const char* prev, const char* next) {
    char last = prev[strlen(prev) - 1];
    char first = next[0];
    return last == first;
}

// "다시 입력하세요"
void print_reenter() {
    printf("다시 입력하세요\n");
}


