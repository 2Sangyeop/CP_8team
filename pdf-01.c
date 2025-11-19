/* 파일명: pdf-01.c
   문제: pdf1번) 등차수열
   작성자: 오태석
   날짜: 2025.11.19
   버전: v1.0
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_recursive(int n) {
	int a = 1;
	for (int i = 1; i <= n; i++) {
		printf("%d ", a);
		a += 2;
	}
}

void print_formula(int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d ", 2*i - 1);
	}
}

int main() {
	int n;

	printf("출력할 항의 개수 입력 : ");
	scanf("%d", &n);

	printf("점화식: ");
	print_recursive(n);

	printf("\n일반항: ");
	print_formula(n);

	return 0;
}