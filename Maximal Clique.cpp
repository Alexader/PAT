#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
const int maxn = 210;
int n, m, kn;
int G[maxn][maxn] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int v1, v2;
	for (int i = 1; i <= m; i++) {
		cin >> v1 >> v2;
		G[v1][v2] = G[v2][v1] = 1;
	}
	cin >> kn;
	vector<int> maxCliq;
	vector<bool> hash;
	hash.resize(n+1, false);// n nodes to hash
	int nodeNum;
	for (int i = 0; i < kn; i++) {
		cin >> nodeNum;
		maxCliq.resize(nodeNum);
		fill(hash.begin(), hash.end(), false);
		for (int j = 0; j < nodeNum; j++) {
			cin >> maxCliq[j];
			hash[maxCliq[j]] = true;
		}
    // 这道题目竟然是暴力枚举，惊了
		// check if a clique first
		bool isClique = true;
		for (int j = 0; j < maxCliq.size() && isClique; j++) {
			for (int l = j+1; l < maxCliq.size() && isClique;l++)
				if (G[maxCliq[j]][maxCliq[l]] == 0)
					isClique = false;
		}
		if (!isClique) cout << "Not a Clique" << endl;
		else {
			// check if other node can be added
			bool isMax = true;
			for (int j = 1; j <= n; j++) {
				if (!hash[j]) {
					bool canAdd = true;
					for (int l = 0; l < maxCliq.size() && canAdd; l++)
						if (G[j][maxCliq[l]] == 0) canAdd = false;
					if (canAdd) {
						isMax = false; break;
					}
				}
			}
			if (isMax) cout << "Yes" << endl;
			else cout << "Not Maximal" << endl;
		}
	}
}