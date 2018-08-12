#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
// 突然发现 c++没有提供直接比较浮点数相等的函数，只能自己设置一下了
const double epsilon = 1e-9;
vector<vector<int> > tree;
int n;
double p, r;
int maxd = 0, cnt = 0;
void dfs(int root, int depth) {
	if (tree[root].empty()) {
		if (depth > maxd) {
			maxd = depth;
			cnt = 1;
		}
		else if (depth == maxd) cnt++;
		return;
	}
	for (int i = 0; i < tree[root].size(); i++)
		dfs(tree[root][i], depth+1);
}
int main() {
	scanf("%d%lf%lf", &n, &p, &r);
	tree.resize(n + 1);
	int temp, root;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (temp == -1) tree[n].push_back(i);
		else tree[temp].push_back(i);
	}
	dfs(n, 0);
	printf("%0.2lf %d", p*pow(1 + 0.01*r, maxd-1), cnt);
}