#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<vector<int> > fam(100);
int level[100] = {0};
// 采用深度或者广度优先都可以计数相同深度的结点数目
void dfs(int root, int depth) {
	level[depth]++;
	for(int i=0;i<fam[root].size();i++)
		dfs(fam[root][i], depth+1);
}
int main() {
	scanf("%d%d", &n, &m);
	int num, child, id;
	for(int i=0;i<m;i++) {
		scanf("%d%d", &id, &num);
		for(int i=0;i<num;i++) {
			scanf("%d", &child);
			fam[id].push_back(child);
		}
	}
	dfs(1, 1);
	int max = 0, lev;
	for(int i=1;i<100;i++)
		if(level[i] > max) {
			max = level[i];
			lev = i;
		}
	printf("%d %d", max, lev);
}