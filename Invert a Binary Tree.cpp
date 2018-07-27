#include <cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int maxn = 31;
int N;

struct node
{
	int indice;
	int left;
	int right;
}tree[maxn];
map<int, bool>mp;
void level(int root) {
	queue<int> q;
	//q.push(root);
	int index = root;
	if (tree[index].right != -1) q.push(tree[index].right);
	if (tree[index].left != -1) q.push(tree[index].left);
	printf("%d", index);
	while (!q.empty())
	{
		index = q.front();
		printf(" %d", index);
		q.pop();
		if (tree[index].right != -1) q.push(tree[index].right);
		if (tree[index].left != -1) q.push(tree[index].left);
	}
}
void inOrder(int root, vector<int> &in) {
	if (root == -1) return;
	inOrder(tree[root].right, in);
	in.push_back(root);
	inOrder(tree[root].left, in);
}
int main() {
	scanf("%d", &N); getchar();
	char l, r;
	for (int i = 0; i < N; i++) {
		scanf("%c %c", &l, &r); getchar();
		if (l == '-') tree[i].left = -1;
		else {
			tree[i].left = (int)l - '0';
			mp[tree[i].left] = true;// 记录该节点成为过孩子
		}
		if (r == '-') tree[i].right = -1;
		else {
			tree[i].right = r - '0';
			mp[tree[i].right] = true;// 记录该节点成为过孩子
		}
	}
	int root = -1;// 记录根节点的位置
	for (int i = 0; i < N; i++)
		if (!mp[i]) {
			root = i; break;
		}
	level(root);
	printf("\n");
	vector<int> in;
	inOrder(root, in);
	for (int i = 0; i < N; i++) {
		if (i != N - 1) printf("%d ", in[i]);
		else printf("%d", in[i]);
	}
}