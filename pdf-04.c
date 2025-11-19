/* 파일명: pdf-04.c
   문제: pdf4번) 최대공약수와 최소공배수
   작성자: 오태석
   날짜: 2025.11.19
   버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>

int gcd(int x, int y) {
	int r;
	while (y != 0) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int lcm(int x, int y) {
	return (x * y) / gcd(x, y);
}

int main() {
	int a, b;

	printf("첫 번째 숫자를 입력하고 Enter>:");
	scanf("%d", &a);

	printf("두 번째 숫자를 입력하고 Enter>: ");	
	scanf("%d", &b);

	int g = gcd(a, b);	
	int l = lcm(a, b);

	printf("\n최대공약수  %d\n", g);
	printf("최소공배수  %d\n", l);

	return 0;
}