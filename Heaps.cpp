#include <iostream>
#include <vector>
using namespace std;
int m, n;
// 完全二叉树是一颗除了最后一层所有的层都是满的二叉树
// 所以直接用数组表示，父子关系用下标就可以表示
// 运用 flag 很重要啊，之前想用递归判断，好像边界条件太复杂了。。
int istree(vector<int> &t) {
	int flag = t[0] < t[1] ? 1 : -1;
	for (int i = 0; i < n / 2; i++) {
		if (flag == 1 &&( (2 * i + 1 < n &&t[2 * i + 1] < t[i]) || (2 * i + 2 < n && t[2 * i + 2] < t[i]))) flag = 0;
		if (flag == -1 &&( (2 * i + 1 < n &&t[2 * i + 1] > t[i]) || (2 * i + 2 < n && t[2 * i + 2] > t[i]))) flag = 0;
	}
	return flag;
}
void postOrder(vector<int> &t, int root) {
	if (root >= n) return;
	postOrder(t, 2 * root + 1);
	postOrder(t, 2 * root + 2);
  // 因为每行的末尾不能多空格，正好后续遍历最后一个元素就是根节点，正好进行控制空格的有无
	if(root == 0)
		printf("%d", t[root]);
	else printf("%d ", t[root]);
}
int main() {
	scanf("%d%d", &m, &n);
	vector<int> tree(n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &tree[j]);
		int kind = istree(tree);
		if (kind == -1)
			printf("Max Heap\n");
		else if(kind == 0)
			printf("Not Heap\n");
		else
			printf("Min Heap\n");
		postOrder(tree, 0);
		if(i!=m-1) printf("\n");
	}
}