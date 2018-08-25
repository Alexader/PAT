#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n;
struct node
{
	int l;
	int r;
	int val;
};
vector<node> tree;
vector<int> arr;
int ptr = 0;
void in(int root) {
	if (root == -1) return;
	in(tree[root].l);
	tree[root].val = arr[ptr++];
	in(tree[root].r);
}
void level(int root) {
	queue<int> q;
	q.push(root);
	int tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		if (tmp == root) printf("%d", tree[tmp].val);
		else printf(" %d", tree[tmp].val);
		if (tree[tmp].l != -1) q.push(tree[tmp].l);
		if (tree[tmp].r != -1) q.push(tree[tmp].r);
	}
}
int main() {
	scanf("%d", &n);
	tree.resize(n);
	arr.resize(n);
	// 先在数组中填好二叉树的分叉的信息
	for (int i = 0; i < n; i++)
		scanf("%d%d", &tree[i].l, &tree[i].r);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());
	// BST 的性质时中序遍历的结果是升序的，利用之填入数据，在层序遍历即可
	in(0);
	level(0);
}