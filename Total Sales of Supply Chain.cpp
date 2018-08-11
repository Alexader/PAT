// 感觉这个还是比较好写的 dfs,只用对叶子节点进行计算，就是
// 传入的参数的处理上需要注意一下，r 给的是百分比数字
#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
struct node {
	int storage;
	vector<int> children;
};
vector<node> tree;
int n;
double p, r;
double total = 0.0;
void dfs(node &root, double p) {
	if (root.children.empty()) {
		total += p*root.storage;
		return;
	}
	for (int i = 0; i < root.children.size(); i++) {
		dfs(tree[root.children[i]], p*(1+0.01*r));
	}
}
int main() {
	scanf("%d %lf %lf", &n, &p, &r);
	tree.resize(n);
	int temp, num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num == 0) {
			scanf("%d", &temp);
			tree[i].storage = temp;
		}
		else
			for (int j = 0; j < num; j++) {
				scanf("%d", &temp);
				tree[i].children.push_back(temp);
			}
	}
	dfs(tree[0], p);
	printf("%0.1lf", total);
}