#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
const int maxn = 500;
const int INF = 1e5;
int n, m, s, d;
struct node
{
  // 我这里把边权矩阵和边长的矩阵合在一起了，也可以像晴神笔记一样分开写
	int dis;
	int cost;
	node(int d = INF, int c=-1) : dis(d), cost(c) {};
};
node G[maxn][maxn];
bool vis[maxn] = { false };
int dis[maxn] = { INF };
int co[maxn] = { INF };
void dijkstra(int s, vector<int> &path) {
	fill(dis, dis + n, INF);
	dis[s] = 0; co[0] = 0;
	for (int j = 0; j < n; j++) {
		int u = -1, min = INF;// nearest node
		for (int i = 0; i < n; i++) {
			if (vis[i] == false && dis[i] < min) {
				u = i; min = dis[i];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int i = 0; i < n; i++) {
			if (vis[i] == false && G[u][i].dis != INF) {
				if (dis[i] > dis[u] + G[u][i].dis) {
					dis[i] = dis[u] + G[u][i].dis;
					co[i] = co[u] + G[u][i].cost;
					path[i] = u; // 记录了每一个节点前面一个节点的序号
				}
				else if (dis[i] == dis[u] + G[u][i].dis && co[i] > co[u]+G[u][i].cost) {
          // 碰到相同边长的公路，比较两条路径的费用如何
					co[i] = co[u] + G[u][i].cost;
					path[i] = u;
				}
			}
		}
	}
}
void dfs(vector<int> pre, int v, int s) {
  // 从目的地往前推节点，推到了出发的节点就开始输出
	if (v == s) {
		printf("%d ", s);
		return;
	}
	dfs(pre, pre[v], s);
	printf("%d ", v);
}
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &d);
	int v1, v2, di, c;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d", &v1, &v2, &di, &c);
		G[v1][v2] = { di, c };
		G[v2][v1] = { di, c };
	}
	vector<int> pre(n);
	dijkstra(s, pre);
	dfs(pre, d, s);
	cout << dis[d] <<" "<<co[d];
}