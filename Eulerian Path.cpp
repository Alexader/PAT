#include <iostream>
#include <vector>

using namespace std;
const int maxn = 501;
int n, m;
vector<int> degree;
int G[maxn][maxn];
vector<bool> vis;
// 一开始没有判断连通性的时候，有一个 5分的测试点过不了，想想这么简单的
// 的代码逻辑应该不会错，应该是边界条件漏掉了，仔细想想也就应该是连通性了。
// 用 dfs 果然就通过了。
void dfs(int root) {
	vis[root] = true;
	for (int i = 1; i <= n; i++) {
		if (G[root][i] != 0 && !vis[i]) dfs(i);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	degree.resize(n + 1, 0);
	vis.resize(n + 1, false);
	int v1, v2;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &v1, &v2);
		degree[v1]++; degree[v2]++;
		G[v1][v2] = G[v2][v1] = 1;
	}
	int oddCnt = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if(i==1) printf("%d", degree[i]);
		else printf(" %d", degree[i]);
		if (degree[i] % 2) oddCnt++;
		if (!vis[i]) {
			dfs(i); cnt++;
		}
	}
	printf("\n");
	if (cnt == 1) {
		if (oddCnt == 0) printf("Eulerian");
		else if(oddCnt == 2) printf("Semi-Eulerian");
		else printf("Non-Eulerian");
	} else
		printf("Non-Eulerian");
}