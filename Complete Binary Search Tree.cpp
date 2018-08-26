#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> ans;
vector<int> tree;
int ptr;
// 根据完全二叉树和BST可以知道现需遍历是有序的，所以可以利用先序遍历填入数据
void preOrder(int root) {
	if (root >= n) return;
	preOrder(2 * root + 1);
	ans[root] = tree[ptr++];
	preOrder(2 * root + 2);
}
int main() {
	scanf("%d", &n);
	ans.resize(n);
	tree.resize(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &tree[i]);
	sort(tree.begin(), tree.end());
	preOrder(0);
	// 完全二叉树的层序遍历就是按照顺序输出
	for (int i = 0; i < ans.size(); i++) {
		if(i==0) printf("%d", ans[i]);
		else printf(" %d", ans[i]);
	}
}