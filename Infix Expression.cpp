// 其实这个语法树就是要进行中序遍历，一开始还被吓到了，编译原理我去
#include <iostream>
#include<vector>
#include<string>
using namespace std;
int n;
struct node
{
	string data;
	int left;
	int right;
};
int R;
vector<node> tree;
vector<bool> Notroot = { false };
void in(int root) {
  // 遍历的时候需要注意最外层的括号是不要的，也就要判断一下是不是根节点再打括号
	if (root == -1) return;
	if ((tree[root].left != -1 || tree[root].right != -1) && root!= R) cout << "(";
	in(tree[root].left);
	cout << tree[root].data;
	in(tree[root].right);
	if ((tree[root].left != -1 || tree[root].right != -1) && root != R) cout << ")";
}
int main() {
	cin >> n;
	tree.resize(n+1);
	Notroot.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> tree[i].data >> tree[i].left >> tree[i].right;
		if (tree[i].left != -1) Notroot[tree[i].left] = true;
		if (tree[i].right != -1) Notroot[tree[i].right] = true;
	}

	for (int i = 1; i <= n;i++)
		if (Notroot[i] == false) {
			R = i;
			break;
		}
	in(R);
}