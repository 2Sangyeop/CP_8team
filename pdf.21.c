#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

// --- 함수 선언 (Function Prototypes) ---
char* right(const char* st, int len);
char* left(const char* st, int len);
char* mid(const char* st, int start_pos, int len);


int main(void) {
    const char* original_st = "program";

    char* res_right = NULL;
    char* res_left = NULL;
    char* res_mid = NULL;

    printf("영문 문자열 처리 program\n"); // 출력 제목 수정

    // 1. right 함수 호출 및 결과 출력
    res_right = right(original_st, 3);
    printf("right: %s\n", res_right);

    // 2. left 함수 호출 및 결과 출력
    res_left = left(original_st, 4);
    printf("left : %s\n", res_left);

    // 3. mid 함수 호출 및 결과 출력
    res_mid = mid(original_st, 2, 3);
    printf("mid  : %s\n", res_mid);

    // 4. 원본 문자열 출력
    printf("원본 : %s\n", original_st);

    // 메모리 해제
    if (res_right) free(res_right);
    if (res_left) free(res_left);
    if (res_mid) free(res_mid);

  
    return 0;
}


// --- 함수 정의 (Function Definitions) ---

char* right(const char* st, int len) {
    size_t st_len = strlen(st);
    int start_index;

    if (len > st_len) {
        len = st_len;
    }

    start_index = st_len - len;

    char* result = (char*)malloc(len + 1);
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    strncpy(result, st + start_index, len);

    result[len] = '\0';

    return result;
}

char* left(const char* st, int len) {
    size_t st_len = strlen(st);

    if (len > st_len) {
        len = st_len;
    }

    char* result = (char*)malloc(len + 1);
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    strncpy(result, st, len);

    result[len] = '\0';

    return result;
}

char* mid(const char* st, int start_pos, int len) {
    size_t st_len = strlen(st);
    int start_index = start_pos - 1;

    if (start_index < 0 || start_index >= st_len || len <= 0) {
        char* result = (char*)malloc(1);
        if (result != NULL) result[0] = '\0';
        return result;
    }

    int remaining_len = st_len - start_index;

    if (len > remaining_len) {
        len = remaining_len;
    }

    char* result = (char*)malloc(len + 1);
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    strncpy(result, st + start_index, len);

    result[len] = '\0';

    return result;
}