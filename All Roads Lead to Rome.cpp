#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
const int maxn = 201;
const int inf = 1e9;
int G[maxn][maxn];
int n, k;
vector<bool> vis;
map<string, int> happy;
// 储存图的时候使用城市对应的下标（按照输入的顺序标号），但是输出的时候需要输出城市名称
// 所以使用了连个 map 进行转化。
map<string, int> city2num;
vector<string> num2city;
vector<int> dis;
vector<int> num; // 保存可能的最短路径的条数
vector<int> pre[maxn]; // 保存每个结点可能的前驱，通过 dfs 可以比较所有的最短路径的第二特征
string st;
void dijkstra(int s) {
	for (int i = 0; i<n; i++)
		vis[i] = false;
	dis[0] = 0; num[0] = 1;
	for (int i = 0; i<n; i++) {
		int u = -1, mini = inf;
		for (int j = 0; j<n; j++)
			if (vis[j] == false && mini > dis[j]) {
				mini = dis[j];
				u = j;
			}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v<n; v++) {
			if (vis[v] == false && G[u][v] != 0) {
				if (dis[v] > dis[u] + G[u][v]) {
					dis[v] = dis[u] + G[u][v];
					num[v] = num[u];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dis[v] == dis[u] + G[u][v]) {
					pre[v].push_back(u);
					num[v] += num[u];
				}
			}
		}
	}
}
int totalHap, Ahap;
vector<int> path, tempPath;
void dfs(int v) {
	if (v == 0) {
		int tmp = 0;
		tempPath.push_back(0);
		for (int i = 0; i<tempPath.size(); i++) {
			tmp += happy[num2city[tempPath[i]]];
		}
    // 按照题目的规则，先比较总 happiness，在比较平均值
		if (tmp > totalHap) {
			totalHap = tmp;
			path = tempPath;
			Ahap = tmp / (tempPath.size()-1);
		}
		else if (tmp == totalHap) {
			if (tmp / (tempPath.size() - 1) > Ahap) {
				Ahap = tmp / (tempPath.size() - 1);
				path = tempPath;
			}
		}
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
		tempPath.pop_back(); // 把当前的 i 节点弹出，为下一次分叉做好准备
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k >> st;
	num2city.resize(n);
	vis.resize(n);
	num.resize(n);
	dis.resize(n, inf);
	string city;
	int hap;
	num2city[0] = st;
	city2num[st] = 0;
	for (int i = 1; i < n; i++) {
		cin >> city >> hap;
		city2num[city] = i;
		num2city[i] = city;
		happy[city] = hap;
	}
	string s, e;
	int w;
	for (int i = 0; i<k; i++) {
		cin >> s >> e >> w;
		G[city2num[s]][city2num[e]] = w;
		G[city2num[e]][city2num[s]] = w;
	}
	dijkstra(0);
	int dest = city2num["ROM"];
	dfs(dest);
	cout << num[dest] << " " << dis[dest] << " " << totalHap << " " << Ahap << endl;
	for (int i = path.size() - 1; i >= 0; i--) {
		if (i != 0) cout << num2city[path[i]] << "->";
		else cout << num2city[path[i]];
	}
}