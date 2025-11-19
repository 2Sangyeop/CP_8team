#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 

void print_term(int current_n, int max_n, int prev_term);
void recursive_geo(int n);
void iterative_geo(int n);

int main(void) {
    int n;

    printf("출력할 항의 개수 입력 후 Enter> ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("잘못된 입력입니다. 1 이상의 정수를 입력해주세요.\n");
        return 1;
    }

    recursive_geo(n);
    iterative_geo(n);

    return 0;
}

//  등비수열 항 재귀 출력
void print_term(int current_n, int max_n, int prev_term) {
    if (current_n > max_n) {
        return;
    }

    int current_term;
    if (current_n == 1) {
        current_term = 1;
    }
    else {
        current_term = 2 * prev_term;
    }

    printf("%d ", current_term);

    print_term(current_n + 1, max_n, current_term);
}

// 1. 재귀 호출 등비수열 출력
void recursive_geo(int n) {
    printf("점화식:\n");
    print_term(1, n, 0);
    printf("\n");
}

// 2. 반복문 등비수열 출력
void iterative_geo(int n) {
    printf("일반항:\n");

    for (int i = 1; i <= n; i++) {
        int term = 1;
        for (int k = 1; k < i; k++) {
            term *= 2;
        }
        printf("%d ", term);
    }
    printf("\n");
}