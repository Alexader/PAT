#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int n;
// 看清楚题目要求，这个的范围超过了一般的整形
// 最后一个测试点就是考这个
long long p;
vector<int> v;
int main() {
	scanf("%d%lld", &n, &p);
	v.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	int left = 0, right = 0, max = 0, index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + max; j < n; j++) {
			if (v[j] <= v[i] * p) {
				index = j - i + 1;
				if (max < index) max = index;
			}
			else {
				break;
			}
		}
	}
	printf("%d", max);
}