#include <iostream>
using namespace std;
int n;
// c++11 标准保证 long long整型数据至少是 64 位的
long long a, b, c;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		long long sum = a + b;
    // 只有两个加数符号相同时才可能产生溢出，需要特别的判断一下
		if (a > 0 && b > 0 && sum < 0)
			printf("Case #%d: true\n", i);
		else if (a < 0 && b < 0 && sum >= 0)
			printf("Case #%d: false\n", i);
		else
			printf("Case #%d: %s\n", i, sum > c ? "true" : "false");
	}
}