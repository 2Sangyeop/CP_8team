#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 3 //행렬의 크기 define

void print_matrix(const int matrix[SIZE][SIZE], const char* name);
void add_matrices(const int A[SIZE][SIZE], const int B[SIZE][SIZE], int C[SIZE][SIZE]);
void subtract_matrices(const int A[SIZE][SIZE], const int B[SIZE][SIZE], int C[SIZE][SIZE]);
void multiply_matrices(const int A[SIZE][SIZE], const int B[SIZE][SIZE], int C[SIZE][SIZE]);

int main(void) {
    // 1. 행렬 A, B 초기화
    int matrix_A[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matrix_B[SIZE][SIZE] = {
        {3, 6, 9},
        {2, 5, 8},
        {1, 4, 7}
    };

    // 2. 결과 행렬 선언
    int matrix_Sum[SIZE][SIZE];
    int matrix_Diff[SIZE][SIZE];
    int matrix_Prod[SIZE][SIZE];

    // 행렬 A, B 출력
    print_matrix(matrix_A, "A");
    print_matrix(matrix_B, "B");

    // 3. 행렬 합 계산 및 출력 (A + B)
    add_matrices(matrix_A, matrix_B, matrix_Sum);
    printf("\nmatrix A + matrix B:");
    print_matrix(matrix_Sum, "");

    // 4. 행렬 차 계산 및 출력 (A - B)
    subtract_matrices(matrix_A, matrix_B, matrix_Diff);
    printf("\nmatrix A - matrix B:");
    print_matrix(matrix_Diff, "");

    // 5. 행렬 곱 계산 및 출력 (A * B)
    multiply_matrices(matrix_A, matrix_B, matrix_Prod);
    printf("\nmatrix A * matrix B:");
    print_matrix(matrix_Prod, "");

    return 0;
}


// 1. 행렬을 출력하는 함수
void print_matrix(const int matrix[SIZE][SIZE], const char* name) {
    printf("\nMatrix %s:\n", name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

// 2. 행렬의 합(A + B)을 계산하는 함수
void add_matrices(const int A[SIZE][SIZE], const int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// 3. 행렬의 차(A - B)를 계산하는 함수
void subtract_matrices(const int A[SIZE][SIZE], const int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// 4. 행렬의 곱(A * B)을 계산하는 함수
void multiply_matrices(const int A[SIZE][SIZE], const int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) { 
            C[i][j] = 0; 
            for (int k = 0; k < SIZE; k++) { 
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}