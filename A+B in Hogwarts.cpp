// 恕我直言，这是一道大水题，还以为要用进制转换，结果都不用
#include <iostream>
using namespace std;
int AG, AS, AK, BG, BS, BK;
int main() {
	scanf("%d.%d.%d %d.%d.%d", &AG, &AS, &AK, &BG, &BS, &BK);
	int newG, newS, newK;
	newK = AK + BK;
	if (newK >= 29) {
		newK %= 29;
		BS += 1;
	}
	newS = AS + BS;
	if (newS >= 17) {
		newS %= 17;
		BG += 1;
	}
	newG = AG + BG;
	printf("%d.%d.%d", newG, newS, newK);
}