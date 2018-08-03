#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int n, m, kn;
vector<vector<int> > G;
vector<int> hashT; // 哈希表记录每个节点的入度
// 这里第二个参数一定不能传入引用，否则哈希表改变了就不好弄回去了
bool isTopo(vector<int> & t, vector<int> Hash) {
	for (int i = 0; i < t.size(); i++) {
		if (Hash[t[i]] != 0) return false;
		for (int j = 0; j < G[t[i]].size(); j++)
			Hash[G[t[i]][j]]--;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	G.resize(n + 1);
	hashT.resize(n + 1, 0);
	int v1, v2;
	for (int i = 1; i <= m; i++) {
		cin >> v1 >> v2;
		G[v1].push_back(v2);
		hashT[v2]++;
	}
	cin >> kn;
	vector<int> topo(n);
	vector<int> ans;
	for (int i = 0; i < kn; i++) {
		for (int j = 0; j < n; j++)
			cin >> topo[j];
		if (!isTopo(topo, hashT))
			ans.push_back(i);
	}
	for (int i = 0; i < ans.size(); i++) {
	  if(i==0) cout << ans[i];
		else cout << " " << ans[i];
	}
}