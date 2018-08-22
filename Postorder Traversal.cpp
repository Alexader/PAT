#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
vector<int> pre;
vector<int> in;
bool flag = false;// flag 保存是否已经输出过东西，这样不用得到整棵树就可以输出完毕
void createTree(int preL, int preR, int inL, int inR) {
	if (preL > preR)
    return;
	int root = preL;
	int index = -1;
  // 在中序中找到根节点的下标
	for (int i = inL; i <= inR; i++)
		if (pre[root] == in[i]) {
			index = i; break;
		}
	if (index == -1) return;
	int leftNum = index - inL;
  // 确定左右子树进行递归
	createTree(preL + 1, preL + leftNum, inL, index - 1);
	createTree(preL+leftNum+1, preR, index+1, inR);
	if (!flag) {
		cout << pre[root];
		flag = true;
	}
}
int main() {
	cin >> n;
	in.resize(n);
	pre.resize(n);
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	for (int i = 0; i < n; i++)
		cin >> in[i];
	createTree(0, n - 1, 0, n - 1);
}