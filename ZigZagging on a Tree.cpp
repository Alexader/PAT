#include <cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 50;
int N;
struct node {
	int val;
	int height;
	node *left;
	node *right;
	node(int v, int h = 0) :val(v), height(h), left(nullptr), right(nullptr) {};
};
node* tree = nullptr;
int post[maxn];
int in[maxn];

// 从中序遍历和后序遍历中恢复二叉树
node* createTree(int postL, int postR, int inL, int inR, int h) {
	if (postL > postR) return nullptr;
	node* root = new node(post[postR], h);
	int index;
	for (index = inL; index <= inR; index++)
		if (in[index] == post[postR]) break;
	int leftNum = index - inL;
	root->left = createTree(postL, postL + leftNum - 1, inL, index - 1, h + 1);
	root->right = createTree(postL + leftNum, postR - 1, index + 1, inR, h + 1);
	return root;
}
// 层序遍历进行打表记录，然后按照层数的奇偶性进行输出的方向选择
void level(node* root, vector<vector<int> >& result) {
	if (root == nullptr) return;
	queue<node*> q;
	q.push(root);
	int level;
	node * temp;
	while (!q.empty()) {
		temp = q.front();
		level = temp->height;
		result[level].push_back(temp->val);
		q.pop();
		if (temp->left != nullptr) q.push(temp->left);
		if (temp->right != nullptr) q.push(temp->right);
	}
}
void zigzagTraversal(vector<vector<int> >& result) {
    // 这里有一个最后的空格不能输出的技巧，就是先输出第一个元素，然后后面进行循环输出，空格在前
	printf("%d", result[0][0]);
	for (int i = 1; i<result.size(); i++) {
		// vector<int>::iterator it;
		if (i % 2) {
			// 奇数的层就是从左往右遍历
			auto it = result[i].begin();
			for (; it != result[i].end(); it++) {
				printf(" %d", *it);
			}
		}
		else {
			auto it = result[i].rbegin();
			for (; it != result[i].rend(); it++) {
				printf(" %d", *it);
			}
		}

	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i<N; i++) scanf("%d", &in[i]);
	for (int i = 0; i<N; i++) scanf("%d", &post[i]);

	tree = createTree(0, N - 1, 0, N - 1, 0);
	vector<vector<int> > result;
	result.resize(N + 1);// resize() 很重要，不然函数中用到的vector会报错
	level(tree, result);
	zigzagTraversal(result);
}