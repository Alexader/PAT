/*
PAT 1024 Solution
*/
#include<iostream>
// 最大的数组如果可以取大一些，以为单纯的加法不会产生很大的数，坑了好久才知道
const int maxLen = 100;
int NInt[maxLen];
int K, len = 0;

// 题目不难，主要是要注意整数 N可能超过正整数的最大表示范围
bool isPalindromic(int NInt[], int len) {
	int i=0, j=len-1;
	while(i<=j) {
		if(NInt[i++] != NInt[j--]) return false;
	}
	return true;
}
void getReversePlus(int NInt[], int &len) {
	int temp[maxLen] = {0};
	int carry = 0;
	for(int i=0;i<len;i++) {
		temp[i] = NInt[i] + NInt[len-i-1] + carry;
		carry = temp[i] / 10;
		temp[i] %= 10;
	}
	if(carry)
		temp[len++] = carry;
	for(int i=0;i<len;i++)
		NInt[i] = temp[len-i-1];
}
int main() {
	char buff[11];
	scanf("%s %d", buff, &K);

	while(buff[len] != '\0') {
		NInt[len] = buff[len] - '0';
		len++;
	}
	int time = 0;
	for(int i=0;i<K;i++) {
		if(isPalindromic(NInt, len))
			break;
		getReversePlus(NInt, len);
		time++;
	}
	for(int i=0;i<len;i++)
		printf("%d", NInt[i]);
	printf("\n");
	printf("%d", time);
}
