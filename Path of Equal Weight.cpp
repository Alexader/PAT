#include <cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// 这道题需要采用深度搜索的策略，难度比较大
int n, m, s;// 分别是总的节点数，非叶子的节点数，路径权重和
struct node
{
	int nodeNum;
	int val;
	vector<int> children;
};
vector<node> tree;

bool cmp(int  a, int b) {
	return tree[a].val > tree[b].val;
}
vector<int> path;
void dfs(int depth, int nodeNum, int curSum) {
	if (curSum > s) return;
	if (curSum < s) {
		path[depth] = tree[nodeNum].val;
		curSum += tree[nodeNum].val;
		if (curSum == s && tree[nodeNum].children.empty()) {
			for (int i = 0; i <= depth; i++) {
				if(i != depth)
					printf("%d ", path[i]);
				else
					printf("%d\n", path[i]);
			}
			return;
		}
		else if (curSum == s) return;
		else 
			for (auto i = tree[nodeNum].children.begin(); i != tree[nodeNum].children.end(); i++)
				dfs(depth+1, tree[*i].nodeNum, curSum);
	}

}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	tree.resize(n);
	path.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tree[i].val);
		tree[i].nodeNum = i;
	}
	int index, num, childIndex;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &index, &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &childIndex);
			tree[index].children.push_back(childIndex);
		}
		sort(tree[index].children.begin(), tree[index].children.end(), cmp);
	}
	dfs(0, 0, 0);
}
