/*
Solution for PAT 1015
*/
#include<stdio.h>
#include<cmath>
using namespace std;

bool isPrime(int N) {
	// 一般要求下的判断质数，这个函数都是满足要求的
	if(N<=1) return false;
	// 如果不把 limit 提前算出来，会超时，注意
	int limit = (int)sqrt(N);
	for(int i=2;i<=limit;i++) // 等于号很重要，有一个测试点就是卡这里
		if(N % i == 0) return false;
	return true;
}
int D2Decimal(int N, int D) {
	// 转化数字进制的技巧
	int len = 0, arr[100];
	do
	{
		arr[len++] = N % D;
		N = N / D;
	} while (N != 0);
	N = 0;
	for (int i = 0; i < len; i++)
		N = N * D + arr[i];
	return N;
}
int main() {
	int N, D;
	while(scanf("%d", &N) != EOF && N > 0) {
		scanf("%d", &D);
		if(isPrime(N) == false) {
			printf("No\n");
			continue;
		}
		int dec = D2Decimal(N, D);
		if(isPrime(dec) == false)
			printf("No\n");
		else
			printf("Yes\n");
	}
}
