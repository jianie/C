#include <stdio.h>
#include <string.h>
#include <time.h>

static int freq[11];
long fibo(int n) {
	freq[n]++;
	if (n <= 1) return n;
	return fibo(n - 1) + fibo(n - 2);
}
static void initFreq() {
	int i;
	for (i = 0; i <= 10; i++)
		freq[i] = 0;
}
static void printFreq() {
	int i;
	for (i = 10; i >= 0; i--)
		printf("Fibo(%2d) = %2d번\n", i, freq[i]);
}
long fiboIter(int n) {
	long f0 = 0, f1 = 1, f;
	int i;
	if (n == 0) return f0;
	if (n == 1) return f1;
	for (i = 2; i <= n; i++) {
		f = f0 + f1;
		f0 = f1;
		f1 = f;
	}
	return f;
}

void reverse(char* str, int left, int right) {
	char tmp;
	if (left < right) {
		tmp = str[right];
		str[right] = str[left];
		str[left] = tmp;
		reverse(str, left + 1, right - 1);
	}
}



void main()
{
	int		i,j;
	long	maxfibo;
	char	str[80] = "Soongsil University!";

	printf("\n(7.1) 피보나치 함수 호출 횟수: fibo(10)\n");
	initFreq();
	fibo(10);
	printFreq();


	printf("\n(7.3) 문자열을 반대로 바꾸는 함수\n");
	printf(" 문자열: %s\n", str);
	reverse(str, 0, strlen(str)-1);
	printf(" 열자문: %s\n", str);


}