#include <iostream>
#include <vector>
using namespace std;
const int maxn = 500;
const int inf = 1e9;
int n, m, s, e;
int G[maxn][maxn];
vector<int> help;
vector<bool> vis;
vector<int> dis;
vector<int> hp;
vector<int> num; // num[i] 存储从 s 城市到 i 城市的可能路径
void dijkstra(int s) {
	for (int i = 0; i < n; i++)
		dis[i] = inf;
	// hp[s] = help[s] 因题目而异，有的题目出发结点不算入结点权值就设置为 0
	dis[s] = 0; hp[s] = help[s]; num[s] = 1;
	// 老是忘记外层的循环，提醒一下自己
	for (int i = 0; i < n; i++) {
		int u = -1, mini = inf;
		for (int j = 0; j < n;j++)
			if (!vis[j] && mini > dis[j]) {
				mini = dis[j];
				u = j;
			}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (!vis[v] && G[u][v] != 0) {
				if (dis[v] > dis[u] + G[u][v]) {
					dis[v] = dis[u] + G[u][v];
					hp[v] = hp[u] + help[v];
					// 如果只有一条路从 u 到 v，那么可能的路径就继承 u 的
					num[v] = num[u];
				}
				else if (dis[v] == dis[u] + G[u][v]) {
					// 注意这里是要求所有一样长的路径个数，并不要求这些一样长的路径
					// 还有一样的 help 值。一开始这里理解有误，两个测试点过不去
					if(hp[v] < hp[u] + help[v]) hp[v] = hp[u] + help[v];
					num[v] += num[u]; // 除了已经找到的路径数目，又可以从 u 结点增加 num[u] 条路径
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &e);
	help.resize(n);
	vis.resize(n, false);
	dis.resize(n, inf);
	hp.resize(n, 0);
	num.resize(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &help[i]);
	int v1, v2, w;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &v1, &v2, &w);
		G[v1][v2] = G[v2][v1] = w;
	}
	dijkstra(s);
	printf("%d %d", num[e], hp[e]);
}