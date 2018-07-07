/*
PAT 1019 Solution
*/
#include<iostream>
using namespace std;
int NbaseB[100];
int len = 0;
int N, b;
// 转化数字进制
void N2Bbase(int N, int b) {
	while(N!=0) {
		NbaseB[len++] = N % b;
		N /= b;
	}
}
// 查看是否符合回文的特征
bool checkPalindromic(int NbaseB[], int len) {
	int i=0, j=len-1;
	while(i<=j) {
		if(NbaseB[i++] != NbaseB[j--]) return false;
	}
	return true;
}
int main() {
	scanf("%d%d", &N, &b);
	N2Bbase(N, b);
	if(checkPalindromic(NbaseB, len))
		printf("Yes\n");
	else
		printf("No\n");
	
	if(len == 0) printf("0"); // 针对 0 的特殊情况
	for(int i=len-1;i>=0;i--)
		if(i != 0)
			printf("%d ", NbaseB[i]);
		else
			printf("%d", NbaseB[i]);
}
