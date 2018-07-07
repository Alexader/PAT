/*
PAT 1023 Solution
*/
#include<iostream>

using namespace std;
const int maxn = 21;
int originalDigits[maxn];
int afterDigits[maxn];
int n, len = 0;

void DoubleInt(int Integer[], int result[], int len) {
	int carry = 0;
	
	for(int i=len-1;i>=0;i--) {
		result[i+1] = Integer[i] * 2 + carry;
		carry = result[i+1] / 10;
		result[i+1] %= 10;
	}
	result[0] = carry;
}

bool checkPermutation(int original[], int Doubled[], int len) {
	if(Doubled[0] != 0) return false; // 产生了进位的话，位数都不符合了肯定不是保持相同的排列
	int Index[10] = {0};
	for(int i=0;i<len;i++) {
		Index[original[i]]++;
		Index[Doubled[i+1]]--;
	}
	for(int i=0;i<10;i++)
		if(Index[i] != 0) return false;
	return true;
}
int main() {
	char buff[maxn];
	scanf("%s", buff);
	int ptr = 0;
	while(buff[ptr] != '\0') {
		originalDigits[ptr] = buff[ptr] - '0';
		ptr++;
	}
	// 实现大整数的乘法运算
	DoubleInt(originalDigits, afterDigits, ptr);

	if(checkPermutation(originalDigits, afterDigits, ptr))
		printf("Yes\n");
	else
		printf("No\n");
	
	if(afterDigits[0] != 0)
		printf("%d", afterDigits[0]);
	for(int i=1;i<=ptr;i++)
		printf("%d", afterDigits[i]);
}
