#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
const int maxn = 1010;
int n, m, k;
vector<bool> visited;
int G[maxn][maxn] = { 0 };
void dfs(int node) {
	visited[node] = true;
	for (int i = 1; i <= n; i++)
		if (G[node][i] > 0 && visited[i] == false)
			dfs(i);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	int c1, c2;
	visited.resize(n+1, false);
	for (int i = 0; i < m; i++) {
		cin >> c1 >> c2;
		G[c1][c2] = G[c2][c1] = 1;
	}
	int query;
	for (int i = 0; i < k; i++) {
		cin >> query;
		fill(visited.begin(), visited.end(), false);
		int count = 0;
		visited[query] = true;
    // 利用深度搜索求图的连通分量
		for (int j = 1; j <= n; j++) {
			if (visited[j] == false) {
				dfs(j);
				count++;
			}
		}
		cout << count-1 << endl;
	}
}