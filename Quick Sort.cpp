#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int n;
vector<int> origin;
vector<int> sorted;
int main() {
	scanf("%d", &n);
	origin.resize(n);
	sorted.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &origin[i]);
		sorted[i] = origin[i];
	}
	sort(sorted.begin(), sorted.end());
	vector<int> out;
	int count = 0, max = 0;
	for (int i = 0; i < n; i++) {
		if (origin[i] == sorted[i] && origin[i] > max) {
			count++; 
			out.push_back(origin[i]);
		}
		if(origin[i] > max) max = origin[i];
	}
	printf("%d\n", count);
	sort(out.begin(), out.end());
	for (int i = 0; i < out.size(); i++) {
		if(i!=0) printf(" %d", out[i]);
		else printf("%d", out[i]);
	}
  // 有一个测试点是 0 个pivot，但是估计测试服务器规定了格式要
  // 有两行，但是题目没作说明，有点坑（都是看大佬的答案才知道的。。）
	printf("\n");
}