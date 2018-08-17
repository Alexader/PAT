#include<iostream>
#include<vector>
using namespace std;
const int maxn = 100;
int n, m, dep;
vector<vector<int> > fam(maxn);
int nochild[maxn]; // 保存各个层的叶子节点数目
// 本来想层次遍历，但是层次遍历好像不太好判断结点所在的层数
void dfs(int root, int depth) {
	for(int i=0;i<fam[root].size();i++)
		dfs(fam[root][i], depth+1);
	if(fam[root].empty()) nochild[depth]++;
	if(depth > dep) dep = depth;
}
int main() {
	scanf("%d%d", &n, &m);
	int f, child, num;
	for(int i=0;i<m;i++) {
		scanf("%d %d", &f, &num);
		for(int j=0;j<num;j++) {
			scanf("%d", &child);
			fam[f].push_back(child);
		}
	}
	dep = 0;
	dfs(1, 1);
	for(int i=1;i<=dep;i++){
		if(i==1) printf("%d", nochild[i]);
		else printf(" %d", nochild[i]);
	}
}